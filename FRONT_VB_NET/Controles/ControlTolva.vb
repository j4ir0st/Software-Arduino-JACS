Imports System
Imports System.Drawing
Imports System.Windows.Forms
Imports Clases

Namespace Controles
    ''' <summary>
    ''' Componente visual reutilizable para supervisar y operar una Tolva Balanza DV-1000.
    ''' </summary>
    Public Class ControlTolva
        Private _tolva As ModeloTolva
        Private _modoAdminActivo As Boolean = False

        Public Property Tolva As ModeloTolva
            Get
                Return _tolva
            End Get
            Set(value As ModeloTolva)
                _tolva = value
                If _tolva IsNot Nothing Then
                    lblTitulo.Text = _tolva.Nombre & " [" & _tolva.PuertoCOM & "]"
                    numPesoObjetivo.Value = CDec(_tolva.PesoObjetivo)
                    numVibracionFina.Value = CDec(_tolva.VibracionFina)
                    numTiempoDescarga.Value = CDec(_tolva.TiempoDescargaMs)
                    ActualizarVisualizacion()
                End If
            End Set
        End Property

        Public Sub EstablecerModoAdministrador(activo As Boolean)
            _modoAdminActivo = activo
            numPesoObjetivo.Enabled = activo
            numVibracionFina.Enabled = activo
            numTiempoDescarga.Enabled = activo
            btnEnviarParametros.Enabled = activo
            btnTara.Enabled = activo
        End Sub

        ''' <summary>
        ''' Refresca todos los elementos visuales del control según el estado de la tolva.
        ''' </summary>
        Public Sub ActualizarVisualizacion()
            If _tolva Is Nothing Then Return

            If InvokeRequired Then
                Invoke(New Action(AddressOf ActualizarVisualizacion))
                Return
            End If

            ' 1. Peso en pantalla digital
            lblPesoActual.Text = Math.Round(_tolva.PesoActual, 0).ToString() & " gr"

            ' 2. Barra de progreso y porcentaje
            Dim porcentaje = CInt(Math.Min(100.0, Math.Max(0.0, _tolva.PorcentajeAvance)))
            pbarProgreso.Value = porcentaje
            lblProgresoTexto.Text = _tolva.PorcentajeAvance.ToString("F1") & "% (Obj: " & _tolva.PesoObjetivo & " gr)"

            ' 3. Estado visual con colores intuitivos
            Select Case _tolva.EstadoActual.ToUpper()
                Case "DOSIF_GRUESA"
                    lblEstado.Text = "CARGA GRUESA"
                    lblEstado.BackColor = Color.DodgerBlue
                Case "DOSIF_FINA"
                    lblEstado.Text = "AJUSTE FINO"
                    lblEstado.BackColor = Color.Gold
                    lblEstado.ForeColor = Color.Black
                Case "PESO_LISTO"
                    lblEstado.Text = "PESO LISTO"
                    lblEstado.BackColor = Color.ForestGreen
                    lblEstado.ForeColor = Color.White
                Case "DESCARGANDO"
                    lblEstado.Text = "DESCARGANDO"
                    lblEstado.BackColor = Color.DarkOrange
                    lblEstado.ForeColor = Color.White
                Case "DETENIDO"
                    lblEstado.Text = "DETENIDO"
                    lblEstado.BackColor = Color.Firebrick
                    lblEstado.ForeColor = Color.White
                Case "ESPERA"
                    lblEstado.Text = "EN ESPERA"
                    lblEstado.BackColor = Color.DimGray
                    lblEstado.ForeColor = Color.White
                Case Else
                    lblEstado.Text = "DESCONECTADO"
                    lblEstado.BackColor = Color.Gray
                    lblEstado.ForeColor = Color.White
            End Select

            ' 4. Contador de descargas
            lblContadorDescargas.Text = "Descargas Realizadas: " & _tolva.ContadorDescargas
        End Sub

        Private Sub btnIniciar_Click(sender As Object, e As EventArgs) Handles btnIniciar.Click
            If _tolva IsNot Nothing Then
                GestorComunicaciones.Instancia.EnviarComandoTolva(_tolva.IdTolva, "START")
            End If
        End Sub

        Private Sub btnDetener_Click(sender As Object, e As EventArgs) Handles btnDetener.Click
            If _tolva IsNot Nothing Then
                GestorComunicaciones.Instancia.EnviarComandoTolva(_tolva.IdTolva, "STOP")
            End If
        End Sub

        Private Sub btnDescargar_Click(sender As Object, e As EventArgs) Handles btnDescargar.Click
            If _tolva IsNot Nothing Then
                GestorComunicaciones.Instancia.EnviarComandoTolva(_tolva.IdTolva, "DESC")
            End If
        End Sub

        Private Sub btnTara_Click(sender As Object, e As EventArgs) Handles btnTara.Click
            If _tolva IsNot Nothing Then
                GestorComunicaciones.Instancia.EnviarComandoTolva(_tolva.IdTolva, "TARA")
            End If
        End Sub

        Private Sub btnEnviarParametros_Click(sender As Object, e As EventArgs) Handles btnEnviarParametros.Click
            If _tolva IsNot Nothing Then
                Dim nuevoPeso As Integer = CInt(numPesoObjetivo.Value)
                Dim nuevaVf As Integer = CInt(numVibracionFina.Value)
                Dim nuevoTDesc As Integer = CInt(numTiempoDescarga.Value)
                GestorComunicaciones.Instancia.EnviarComandoTolva(_tolva.IdTolva, "PESO:" & nuevoPeso)
                GestorComunicaciones.Instancia.EnviarComandoTolva(_tolva.IdTolva, "VFINA:" & nuevaVf)
                GestorComunicaciones.Instancia.EnviarComandoTolva(_tolva.IdTolva, "TDESC:" & nuevoTDesc)
                _tolva.PesoObjetivo = nuevoPeso
                _tolva.VibracionFina = nuevaVf
                _tolva.TiempoDescargaMs = nuevoTDesc
                MessageBox.Show("Parámetros enviados a " & _tolva.Nombre & " correctamente.", "Configuración Tolva", MessageBoxButtons.OK, MessageBoxIcon.Information)
            End If
        End Sub
    End Class
End Namespace
