Imports System
Imports System.Collections.Generic
Imports System.IO.Ports
Imports System.Text
Imports System.Threading

Namespace Clases
    ''' <summary>
    ''' Administrador multihilo de comunicaciones serie para la Máquina Principal (NS-GH) y múltiples tolvas DV-1000.
    ''' </summary>
    Public Class GestorComunicaciones
        Public Shared Instancia As New GestorComunicaciones()

        Public ReadOnly Property MaquinaPrincipal As New ModeloMaquinaPrincipal()
        Public ReadOnly Property ListaTolvas As New List(Of ModeloTolva)()

        Private _puertoPrincipal As SerialPort
        Private ReadOnly _puertosTolvas As New Dictionary(Of Integer, SerialPort)()
        Private ReadOnly _mapeoPuertosId As New Dictionary(Of SerialPort, Integer)()
        Private ReadOnly _candado As New Object()

        ' Eventos para notificación a la interfaz gráfica
        Public Event DatosTolvaActualizados(tolva As ModeloTolva)
        Public Event DatosMaquinaActualizados(maquina As ModeloMaquinaPrincipal)
        Public Event EstadoConexionCambiado(nombreDispositivo As String, conectado As Boolean)
        Public Event ErrorComunicacion(dispositivo As String, mensajeError As String)

        Public Sub New()
            ListaTolvas.Add(New ModeloTolva() With {.IdTolva = 1, .Nombre = "Tolva 1", .PuertoCOM = "COM3"})
            ListaTolvas.Add(New ModeloTolva() With {.IdTolva = 2, .Nombre = "Tolva 2", .PuertoCOM = "COM4"})
        End Sub

        ''' <summary>
        ''' Escanea los puertos USB COM del sistema enviando el comando PING para identificar dispositivos.
        ''' </summary>
        Public Function EscanearYAutoDetectarPuertos() As Dictionary(Of String, String)
            Dim resultados As New Dictionary(Of String, String)()
            Dim puertosDisponibles As String() = SerialPort.GetPortNames()

            For Each puerto In puertosDisponibles
                Try
                    Using sp As New SerialPort(puerto, 9600, Parity.None, 8, StopBits.One)
                        sp.ReadTimeout = 600
                        sp.WriteTimeout = 600
                        sp.Open()
                        sp.DiscardInBuffer()

                        sp.WriteLine("PING")
                        Thread.Sleep(100)

                        Dim respuesta As String = sp.ReadLine().Trim()
                        If respuesta.Contains("PONG:ID=MAIN") Then
                            resultados(puerto) = "Máquina Principal (NS-GH)"
                            MaquinaPrincipal.PuertoCOM = puerto
                        ElseIf respuesta.Contains("PONG:ID=") Then
                            Dim idStr As String = respuesta.Split(":"c)(1).Replace("ID=", "")
                            resultados(puerto) = "Tolva Balanza DV-1000 (ID " & idStr & ")"
                            Dim id As Integer
                            If Integer.TryParse(idStr, id) Then
                                Dim tolva = ListaTolvas.Find(Function(t) t.IdTolva = id)
                                If tolva IsNot Nothing Then
                                    tolva.PuertoCOM = puerto
                                End If
                            End If
                        Else
                            resultados(puerto) = "Dispositivo desconocido"
                        End If
                    End Using
                Catch ex As Exception
                    resultados(puerto) = "Sin respuesta / En uso"
                End Try
            Next

            Return resultados
        End Function

        ''' <summary>
        ''' Establece la conexión serie con la máquina principal NS-GH.
        ''' </summary>
        Public Sub ConectarMaquinaPrincipal(puerto As String)
            SyncLock _candado
                Try
                    If _puertoPrincipal IsNot Nothing AndAlso _puertoPrincipal.IsOpen Then
                        _puertoPrincipal.Close()
                    End If

                    _puertoPrincipal = New SerialPort(puerto, 9600, Parity.None, 8, StopBits.One)
                    AddHandler _puertoPrincipal.DataReceived, AddressOf PuertoPrincipal_DataReceived
                    _puertoPrincipal.Open()

                    MaquinaPrincipal.PuertoCOM = puerto
                    MaquinaPrincipal.Conectado = True
                    MaquinaPrincipal.EstadoActual = "ESPERA"

                    RaiseEvent EstadoConexionCambiado("Máquina Principal (NS-GH)", True)
                    _puertoPrincipal.WriteLine("PING")
                    _puertoPrincipal.WriteLine("ESTADO")
                Catch ex As Exception
                    MaquinaPrincipal.Conectado = False
                    MaquinaPrincipal.EstadoActual = "ERROR"
                    RaiseEvent ErrorComunicacion("Máquina Principal", ex.Message)
                End Try
            End SyncLock
        End Sub

        ''' <summary>
        ''' Establece la conexión serie con una Tolva Balanza DV-1000 específica.
        ''' </summary>
        Public Sub ConectarTolva(idTolva As Integer, puerto As String)
            SyncLock _candado
                Try
                    Dim tolva = ListaTolvas.Find(Function(t) t.IdTolva = idTolva)
                    If tolva Is Nothing Then Return

                    If _puertosTolvas.ContainsKey(idTolva) Then
                        Dim spAntiguo = _puertosTolvas(idTolva)
                        If spAntiguo.IsOpen Then spAntiguo.Close()
                        _puertosTolvas.Remove(idTolva)
                        _mapeoPuertosId.Remove(spAntiguo)
                    End If

                    Dim sp As New SerialPort(puerto, 9600, Parity.None, 8, StopBits.One)
                    _mapeoPuertosId(sp) = idTolva
                    AddHandler sp.DataReceived, AddressOf PuertoTolva_DataReceived
                    sp.Open()

                    _puertosTolvas(idTolva) = sp
                    tolva.PuertoCOM = puerto
                    tolva.Conectado = True
                    tolva.EstadoActual = "ESPERA"

                    RaiseEvent EstadoConexionCambiado(tolva.Nombre, True)
                    sp.WriteLine("PING")
                    sp.WriteLine("ESTADO")
                Catch ex As Exception
                    Dim tolva = ListaTolvas.Find(Function(t) t.IdTolva = idTolva)
                    If tolva IsNot Nothing Then
                        tolva.Conectado = False
                        tolva.EstadoActual = "ERROR"
                    End If
                    RaiseEvent ErrorComunicacion("Tolva " & idTolva, ex.Message)
                End Try
            End SyncLock
        End Sub

        ''' <summary>
        ''' Envía un comando a la Máquina Principal NS-GH.
        ''' </summary>
        Public Sub EnviarComandoMaquina(comando As String)
            SyncLock _candado
                Try
                    If _puertoPrincipal IsNot Nothing AndAlso _puertoPrincipal.IsOpen Then
                        _puertoPrincipal.WriteLine(comando)
                    End If
                Catch ex As Exception
                    RaiseEvent ErrorComunicacion("Máquina Principal", ex.Message)
                End Try
            End SyncLock
        End Sub

        ''' <summary>
        ''' Envía un comando a una Tolva Balanza DV-1000 específica.
        ''' </summary>
        Public Sub EnviarComandoTolva(idTolva As Integer, comando As String)
            SyncLock _candado
                Try
                    If _puertosTolvas.ContainsKey(idTolva) AndAlso _puertosTolvas(idTolva).IsOpen Then
                        _puertosTolvas(idTolva).WriteLine(comando)
                    End If
                Catch ex As Exception
                    RaiseEvent ErrorComunicacion("Tolva " & idTolva, ex.Message)
                End Try
            End SyncLock
        End Sub

        ''' <summary>
        ''' Envía un comando en simultáneo a todas las tolvas conectadas.
        ''' </summary>
        Public Sub EnviarComandoATodasLasTolvas(comando As String)
            For Each kvp In _puertosTolvas
                Try
                    If kvp.Value.IsOpen Then kvp.Value.WriteLine(comando)
                Catch
                End Try
            Next
        End Sub

        Private Sub PuertoPrincipal_DataReceived(sender As Object, e As SerialDataReceivedEventArgs)
            Try
                Dim sp = DirectCast(sender, SerialPort)
                While sp.IsOpen AndAlso sp.BytesToRead > 0
                    Dim linea As String = sp.ReadLine().Trim()
                    ProcesarTramaMaquina(linea)
                End While
            Catch
            End Try
        End Sub

        Private Sub PuertoTolva_DataReceived(sender As Object, e As SerialDataReceivedEventArgs)
            Try
                Dim sp = DirectCast(sender, SerialPort)
                Dim idTolva As Integer = 0
                SyncLock _candado
                    If Not _mapeoPuertosId.TryGetValue(sp, idTolva) Then Return
                End SyncLock

                While sp.IsOpen AndAlso sp.BytesToRead > 0
                    Dim linea As String = sp.ReadLine().Trim()
                    ProcesarTramaTolva(idTolva, linea)
                End While
            Catch
            End Try
        End Sub

        Private Sub ProcesarTramaMaquina(linea As String)
            If String.IsNullOrWhiteSpace(linea) Then Return

            ' Trama completa esperada:
            ' ESTADO:ENVASANDO;BOLSAS:124;BPM:32.5;T_SELL:1000;T_ARR:400;MOR_C:400;MOR_A:400;FC_MOR:0;TACA:1;SEC:0;TIPO:0;CLAVE:1234;T1:160;T2:158;T3:162;T4:160;SET_T1:150;SET_T2:150;SET_T3:150;SET_T4:150;CAL:1;TOLVAS_OK:1;ID:MAIN
            If linea.StartsWith("ESTADO:") Then
                Dim partes = linea.Split(";"c)
                For Each p In partes
                    Dim claveValor = p.Split(":"c)
                    If claveValor.Length >= 2 Then
                        Dim clave = claveValor(0).ToUpper()
                        Dim valor = claveValor(1)

                        Select Case clave
                            Case "ESTADO" : MaquinaPrincipal.EstadoActual = valor
                            Case "BOLSAS" : Long.TryParse(valor, MaquinaPrincipal.ContadorBolsas)
                            Case "BPM" : Double.TryParse(valor, MaquinaPrincipal.BolsasPorMinuto)
                            Case "T_SELL" : Integer.TryParse(valor, MaquinaPrincipal.TiempoSelladoMs)
                            Case "T_ARR" : Integer.TryParse(valor, MaquinaPrincipal.TiempoArrastreMs)
                            Case "MOR_C" : Integer.TryParse(valor, MaquinaPrincipal.TiempoMordazaCierraMs)
                            Case "MOR_A" : Integer.TryParse(valor, MaquinaPrincipal.TiempoMordazaAbreMs)
                            Case "FC_MOR" : MaquinaPrincipal.UsarFCMordaza = (valor = "1")
                            Case "TACA" : MaquinaPrincipal.UsarSensorTaca = (valor = "1")
                            Case "SEC" : Integer.TryParse(valor, MaquinaPrincipal.SecuenciaOperacion)
                            Case "TIPO" : Integer.TryParse(valor, MaquinaPrincipal.TipoMaquina)
                            Case "CLAVE" : Integer.TryParse(valor, MaquinaPrincipal.ClaveAccesoLocal)
                            Case "T1" : Integer.TryParse(valor, MaquinaPrincipal.TempActualSupIzq)
                            Case "T2" : Integer.TryParse(valor, MaquinaPrincipal.TempActualSupDer)
                            Case "T3" : Integer.TryParse(valor, MaquinaPrincipal.TempActualInfExt)
                            Case "T4" : Integer.TryParse(valor, MaquinaPrincipal.TempActualInfInt)
                            Case "SET_T1" : Integer.TryParse(valor, MaquinaPrincipal.TempConsignaSupIzq)
                            Case "SET_T2" : Integer.TryParse(valor, MaquinaPrincipal.TempConsignaSupDer)
                            Case "SET_T3" : Integer.TryParse(valor, MaquinaPrincipal.TempConsignaInfExt)
                            Case "SET_T4" : Integer.TryParse(valor, MaquinaPrincipal.TempConsignaInfInt)
                            Case "CAL" : MaquinaPrincipal.CalefaccionActiva = (valor = "1")
                            Case "TOLVAS_OK" : MaquinaPrincipal.TolvasListasFisico = (valor = "1")
                        End Select
                    End If
                Next
                MaquinaPrincipal.UltimaActualizacion = DateTime.Now
                RaiseEvent DatosMaquinaActualizados(MaquinaPrincipal)
            End If
        End Sub

        Private Sub ProcesarTramaTolva(idTolva As Integer, linea As String)
            If String.IsNullOrWhiteSpace(linea) Then Return

            Dim tolva = ListaTolvas.Find(Function(t) t.IdTolva = idTolva)
            If tolva Is Nothing Then Return

            If linea.StartsWith("ESTADO:") Then
                Dim partes = linea.Split(";"c)
                For Each p In partes
                    Dim claveValor = p.Split(":"c)
                    If claveValor.Length >= 2 Then
                        Dim clave = claveValor(0).ToUpper()
                        Dim valor = claveValor(1)

                        Select Case clave
                            Case "ESTADO" : tolva.EstadoActual = valor
                            Case "PESO" : Double.TryParse(valor, tolva.PesoActual)
                            Case "OBJETIVO" : Integer.TryParse(valor, tolva.PesoObjetivo)
                            Case "VFINA" : Integer.TryParse(valor, tolva.VibracionFina)
                            Case "INERCIA" : Integer.TryParse(valor, tolva.Inercia)
                            Case "TDESC" : Integer.TryParse(valor, tolva.TiempoDescargaMs)
                            Case "CONTADOR" : Long.TryParse(valor, tolva.ContadorDescargas)
                        End Select
                    End If
                Next
                tolva.UltimaActualizacion = DateTime.Now
                RaiseEvent DatosTolvaActualizados(tolva)
            End If
        End Sub

        Public Sub DesconectarTodo()
            SyncLock _candado
                Try
                    If _puertoPrincipal IsNot Nothing AndAlso _puertoPrincipal.IsOpen Then
                        _puertoPrincipal.Close()
                    End If
                    For Each kvp In _puertosTolvas
                        If kvp.Value.IsOpen Then kvp.Value.Close()
                    Next
                    _puertosTolvas.Clear()
                    _mapeoPuertosId.Clear()
                Catch
                End Try
            End SyncLock
        End Sub
    End Class
End Namespace
