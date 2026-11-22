Imports System
Imports System.Drawing
Imports System.Windows.Forms
Imports Clases
Imports Controles

Namespace Formularios
    ''' <summary>
    ''' Pantalla principal de control y supervisión para la Máquina Envasadora NS-GH y las Tolvas DV-1000.
    ''' </summary>
    Public Class FormPrincipal
        Private _modoAdminActivo As Boolean = False

        Private Sub FormPrincipal_Load(sender As Object, e As EventArgs) Handles MyBase.Load
            ' Cargar configuración local persistente (clave admin, etc.)
            ConfiguracionApp.Instancia.Cargar()

            ' Suscripción a eventos del gestor de comunicaciones
            AddHandler GestorComunicaciones.Instancia.DatosMaquinaActualizados, AddressOf Gestor_DatosMaquinaActualizados
            AddHandler GestorComunicaciones.Instancia.DatosTolvaActualizados, AddressOf Gestor_DatosTolvaActualizados
            AddHandler GestorComunicaciones.Instancia.EstadoConexionCambiado, AddressOf Gestor_EstadoConexionCambiado
            AddHandler GestorComunicaciones.Instancia.ErrorComunicacion, AddressOf Gestor_ErrorComunicacion

            ' Construir los paneles visuales de las tolvas
            ReconstruirControlesTolvas()
            ActualizarModoUsuario()

            ' Intentar auto-conectar con los puertos por defecto si están disponibles
            Try
                GestorComunicaciones.Instancia.ConectarMaquinaPrincipal(GestorComunicaciones.Instancia.MaquinaPrincipal.PuertoCOM)
                For Each t In GestorComunicaciones.Instancia.ListaTolvas
                    GestorComunicaciones.Instancia.ConectarTolva(t.IdTolva, t.PuertoCOM)
                Next
            Catch
            End Try
        End Sub

        Private Sub FormPrincipal_FormClosing(sender As Object, e As FormClosingEventArgs) Handles MyBase.FormClosing
            ' Cerrar puertos y liberar recursos al salir
            GestorComunicaciones.Instancia.DesconectarTodo()
        End Sub

        ''' <summary>
        ''' Genera dinámicamente las tarjetas gráficas para cada tolva conectada.
        ''' </summary>
        Private Sub ReconstruirControlesTolvas()
            flpContenedorTolvas.SuspendLayout()
            flpContenedorTolvas.Controls.Clear()

            For Each tolva In GestorComunicaciones.Instancia.ListaTolvas
                Dim ctl As New ControlTolva() With {
                    .Tolva = tolva,
                    .Margin = New Padding(8)
                }
                ctl.EstablecerModoAdministrador(_modoAdminActivo)
                flpContenedorTolvas.Controls.Add(ctl)
            Next

            flpContenedorTolvas.ResumeLayout()
            lblTituloTolvas.Text = "TOLVAS DOSIFICADORAS DV-1000 (" & GestorComunicaciones.Instancia.ListaTolvas.Count & " ACTIVAS)"
        End Sub

        ''' <summary>
        ''' Aplica restricciones visuales entre modo Operador y Administrador.
        ''' </summary>
        Private Sub ActualizarModoUsuario()
            If _modoAdminActivo Then
                lblModoUsuario.Text = "MODO: ADMINISTRADOR"
                lblModoUsuario.BackColor = Color.ForestGreen
                btnModoAdmin.Text = "Cerrar Modo Admin"
                btnModoAdmin.BackColor = Color.LightCoral
                btnCambiarClaveAdmin.Visible = True

                grpParametrosCiclo.Enabled = True
                btnToggleCalefaccion.Enabled = True
                btnResetContador.Enabled = True
            Else
                lblModoUsuario.Text = "MODO: OPERADOR"
                lblModoUsuario.BackColor = Color.SteelBlue
                btnModoAdmin.Text = "Acceso Admin"
                btnModoAdmin.BackColor = Color.Orange
                btnCambiarClaveAdmin.Visible = False

                grpParametrosCiclo.Enabled = False
                btnToggleCalefaccion.Enabled = False
                btnResetContador.Enabled = False
            End If

            For Each ctl In flpContenedorTolvas.Controls
                If TypeOf ctl Is ControlTolva Then
                    DirectCast(ctl, ControlTolva).EstablecerModoAdministrador(_modoAdminActivo)
                End If
            Next
        End Sub

        Private Sub btnModoAdmin_Click(sender As Object, e As EventArgs) Handles btnModoAdmin.Click
            If _modoAdminActivo Then
                _modoAdminActivo = False
                ActualizarModoUsuario()
                statusLabelMensaje.Text = "Modo Administrador finalizado. Modo Operador activo."
            Else
                Using login As New FormLoginAdmin()
                    If login.ShowDialog(Me) = DialogResult.OK Then
                        _modoAdminActivo = True
                        ActualizarModoUsuario()
                        statusLabelMensaje.Text = "Modo Administrador activado. Parámetros avanzados desbloqueados."
                    End If
                End Using
            End If
        End Sub

        Private Sub btnCambiarClaveAdmin_Click(sender As Object, e As EventArgs) Handles btnCambiarClaveAdmin.Click
            Using formClave As New FormCambiarClaveAdmin()
                formClave.ShowDialog(Me)
            End Using
        End Sub

        Private Sub btnConfigPuertos_Click(sender As Object, e As EventArgs) Handles btnConfigPuertos.Click
            ' Requiere modo admin para reconfigurar puertos
            If Not _modoAdminActivo Then
                Using login As New FormLoginAdmin()
                    If login.ShowDialog(Me) <> DialogResult.OK Then Return
                    _modoAdminActivo = True
                    ActualizarModoUsuario()
                End Using
            End If

            Using formConfig As New FormConfiguracionPuertos()
                If formConfig.ShowDialog(Me) = DialogResult.OK Then
                    ReconstruirControlesTolvas()
                End If
            End Using
        End Sub

        Private Sub btnAjustesAvanzados_Click(sender As Object, e As EventArgs) Handles btnAjustesAvanzados.Click
            Using formAjustes As New FormAjustesAvanzadosMaquina()
                If formAjustes.ShowDialog(Me) = DialogResult.OK Then
                    ' Refrescar parámetros en los controles rápidos
                    Dim m = GestorComunicaciones.Instancia.MaquinaPrincipal
                    numTiempoSellado.Value = CDec(Math.Max(100, Math.Min(9000, m.TiempoSelladoMs)))
                    numTiempoArrastre.Value = CDec(Math.Max(50, Math.Min(9000, m.TiempoArrastreMs)))
                    chkUsarTaca.Checked = m.UsarSensorTaca
                End If
            End Using
        End Sub

        Private Sub btnResetContador_Click(sender As Object, e As EventArgs) Handles btnResetContador.Click
            If MessageBox.Show("¿Desea reiniciar el contador de bolsas producidas a 0?", "Reset Contador", MessageBoxButtons.YesNo, MessageBoxIcon.Question) = DialogResult.Yes Then
                GestorComunicaciones.Instancia.EnviarComandoMaquina("RESET_CONT")
                GestorComunicaciones.Instancia.MaquinaPrincipal.ContadorBolsas = 0
                lblDisplayBolsas.Text = "Bolsas: 0"
                statusLabelMensaje.Text = "Contador de bolsas reiniciado a 0."
            End If
        End Sub

        Private Sub btnParadaGeneral_Click(sender As Object, e As EventArgs) Handles btnParadaGeneral.Click
            ' 1. Detener máquina principal NS-GH
            GestorComunicaciones.Instancia.EnviarComandoMaquina("STOP")

            ' 2. Detener todas las tolvas DV-1000
            GestorComunicaciones.Instancia.EnviarComandoATodasLasTolvas("STOP")

            statusLabelMensaje.Text = "¡PARADA GENERAL ACTIVADA! Todos los actuadores han sido apagados."
            MessageBox.Show("Parada General Ejecutada: La envasadora y todas las tolvas han sido detenidas.", "Parada de Emergencia", MessageBoxButtons.OK, MessageBoxIcon.Warning)
        End Sub

        Private Sub btnIniciarEnvasado_Click(sender As Object, e As EventArgs) Handles btnIniciarEnvasado.Click
            GestorComunicaciones.Instancia.EnviarComandoMaquina("START")
            statusLabelMensaje.Text = "Iniciando ciclo continuo de envasado..."
        End Sub

        Private Sub btnDetenerEnvasado_Click(sender As Object, e As EventArgs) Handles btnDetenerEnvasado.Click
            GestorComunicaciones.Instancia.EnviarComandoMaquina("STOP")
            statusLabelMensaje.Text = "Deteniendo ciclo de envasado..."
        End Sub

        Private Sub btnJogArrastre_Click(sender As Object, e As EventArgs) Handles btnJogArrastre.Click
            GestorComunicaciones.Instancia.EnviarComandoMaquina("JOG_ARR")
        End Sub

        Private Sub btnCicloMordazas_Click(sender As Object, e As EventArgs) Handles btnCicloMordazas.Click
            GestorComunicaciones.Instancia.EnviarComandoMaquina("MOR_CIERRA")
            System.Threading.Thread.Sleep(500)
            GestorComunicaciones.Instancia.EnviarComandoMaquina("MOR_ABRE")
        End Sub

        Private Sub btnProbarCorte_Click(sender As Object, e As EventArgs) Handles btnProbarCorte.Click
            GestorComunicaciones.Instancia.EnviarComandoMaquina("CORTE")
        End Sub

        Private Sub btnToggleCalefaccion_Click(sender As Object, e As EventArgs) Handles btnToggleCalefaccion.Click
            Dim maq = GestorComunicaciones.Instancia.MaquinaPrincipal
            If maq.CalefaccionActiva Then
                GestorComunicaciones.Instancia.EnviarComandoMaquina("CALENTAR:0")
            Else
                GestorComunicaciones.Instancia.EnviarComandoMaquina("CALENTAR:1")
            End If
        End Sub

        Private Sub btnAplicarParametrosMaquina_Click(sender As Object, e As EventArgs) Handles btnAplicarParametrosMaquina.Click
            Dim tSellado = CInt(numTiempoSellado.Value)
            Dim tArrastre = CInt(numTiempoArrastre.Value)
            Dim usarTaca = If(chkUsarTaca.Checked, 1, 0)

            GestorComunicaciones.Instancia.EnviarComandoMaquina("SET_SELLADO:" & tSellado)
            GestorComunicaciones.Instancia.EnviarComandoMaquina("SET_ARRASTRE:" & tArrastre)
            GestorComunicaciones.Instancia.EnviarComandoMaquina("SET_TACA:" & usarTaca)

            MessageBox.Show("Parámetros de sellado y arrastre actualizados en el Arduino Principal.", "Configuración Guardada", MessageBoxButtons.OK, MessageBoxIcon.Information)
        End Sub

        Private Sub btnIniciarTodasTolvas_Click(sender As Object, e As EventArgs) Handles btnIniciarTodasTolvas.Click
            GestorComunicaciones.Instancia.EnviarComandoATodasLasTolvas("START")
        End Sub

        Private Sub btnDetenerTodasTolvas_Click(sender As Object, e As EventArgs) Handles btnDetenerTodasTolvas.Click
            GestorComunicaciones.Instancia.EnviarComandoATodasLasTolvas("STOP")
        End Sub

        Private Sub btnDescargarTodasTolvas_Click(sender As Object, e As EventArgs) Handles btnDescargarTodasTolvas.Click
            GestorComunicaciones.Instancia.EnviarComandoATodasLasTolvas("DESC")
        End Sub

        Private Sub Gestor_DatosMaquinaActualizados(maquina As ModeloMaquinaPrincipal)
            If InvokeRequired Then
                Invoke(New Action(Of ModeloMaquinaPrincipal)(AddressOf Gestor_DatosMaquinaActualizados), maquina)
                Return
            End If

            lblDisplayBolsas.Text = "Bolsas: " & maquina.ContadorBolsas
            lblDisplayBPM.Text = maquina.BolsasPorMinuto.ToString("F1") & " BPM"

            Select Case maquina.EstadoActual.ToUpper()
                Case "ENVASANDO"
                    lblEstadoMaquina.Text = "ESTADO: ENVASANDO"
                    lblEstadoMaquina.BackColor = Color.ForestGreen
                Case "SELLANDO"
                    lblEstadoMaquina.Text = "ESTADO: SELLANDO MORDAZAS"
                    lblEstadoMaquina.BackColor = Color.DarkOrange
                Case "ARRASTRANDO"
                    lblEstadoMaquina.Text = "ESTADO: ARRASTRANDO FILM"
                    lblEstadoMaquina.BackColor = Color.DodgerBlue
                Case "ESPERA_TOLVAS"
                    lblEstadoMaquina.Text = "ESTADO: ESPERANDO DESCARGA TOLVAS"
                    lblEstadoMaquina.BackColor = Color.Gold
                    lblEstadoMaquina.ForeColor = Color.Black
                Case "DETENIDO"
                    lblEstadoMaquina.Text = "ESTADO: DETENIDO"
                    lblEstadoMaquina.BackColor = Color.Firebrick
                    lblEstadoMaquina.ForeColor = Color.White
                Case Else
                    lblEstadoMaquina.Text = "ESTADO: EN ESPERA"
                    lblEstadoMaquina.BackColor = Color.DimGray
                    lblEstadoMaquina.ForeColor = Color.White
            End Select

            ' Temperaturas actuales y consignas
            lblT1.Text = "Sup. Izq: " & maquina.TempActualSupIzq & " °C (Set: " & maquina.TempConsignaSupIzq & ")"
            lblT2.Text = "Sup. Der: " & maquina.TempActualSupDer & " °C (Set: " & maquina.TempConsignaSupDer & ")"
            lblT3.Text = "Inf. Ext: " & maquina.TempActualInfExt & " °C (Set: " & maquina.TempConsignaInfExt & ")"
            lblT4.Text = "Inf. Int: " & maquina.TempActualInfInt & " °C (Set: " & maquina.TempConsignaInfInt & ")"

            If maquina.CalefaccionActiva Then
                btnToggleCalefaccion.Text = "APAGAR CALEFACCIÓN DE MORDAZAS"
                btnToggleCalefaccion.BackColor = Color.Crimson
            Else
                btnToggleCalefaccion.Text = "ACTIVAR CALEFACCIÓN DE MORDAZAS"
                btnToggleCalefaccion.BackColor = Color.DarkOrange
            End If
        End Sub

        Private Sub Gestor_DatosTolvaActualizados(tolva As ModeloTolva)
            If InvokeRequired Then
                Invoke(New Action(Of ModeloTolva)(AddressOf Gestor_DatosTolvaActualizados), tolva)
                Return
            End If

            For Each ctl In flpContenedorTolvas.Controls
                If TypeOf ctl Is ControlTolva Then
                    Dim ctlTolva = DirectCast(ctl, ControlTolva)
                    If ctlTolva.Tolva IsNot Nothing AndAlso ctlTolva.Tolva.IdTolva = tolva.IdTolva Then
                        ctlTolva.ActualizarVisualizacion()
                        Exit For
                    End If
                End If
            Next
        End Sub

        Private Sub Gestor_EstadoConexionCambiado(nombreDispositivo As String, conectado As Boolean)
            If InvokeRequired Then
                Invoke(New Action(Of String, Boolean)(AddressOf Gestor_EstadoConexionCambiado), nombreDispositivo, conectado)
                Return
            End If

            statusLabelMensaje.Text = nombreDispositivo & If(conectado, " conectado exitosamente.", " desconectado.")
        End Sub

        Private Sub Gestor_ErrorComunicacion(dispositivo As String, mensajeError As String)
            If InvokeRequired Then
                Invoke(New Action(Of String, String)(AddressOf Gestor_ErrorComunicacion), dispositivo, mensajeError)
                Return
            End If

            statusLabelMensaje.Text = "Error en " & dispositivo & ": " & mensajeError
        End Sub
    End Class
End Namespace
