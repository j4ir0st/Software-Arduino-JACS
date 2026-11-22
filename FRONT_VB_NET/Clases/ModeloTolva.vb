Imports System

Namespace Clases
    ''' <summary>
    ''' Representa el estado y parámetros de una Tolva Dosificadora con Balanza DV-1000.
    ''' </summary>
    Public Class ModeloTolva
        Public Property IdTolva As Integer = 1
        Public Property Nombre As String = "Tolva 1"
        Public Property PuertoCOM As String = "COM3"
        Public Property Conectado As Boolean = False

        ' Estados posibles: "ESPERA", "DOSIF_GRUESA", "DOSIF_FINA", "PESO_LISTO", "DESCARGANDO", "DETENIDO", "DESCONECTADO"
        Public Property EstadoActual As String = "DESCONECTADO"

        Public Property PesoActual As Double = 0.0
        Public Property PesoObjetivo As Integer = 500
        Public Property VibracionFina As Integer = 30
        Public Property Inercia As Integer = 5
        Public Property TiempoDescargaMs As Integer = 2000
        Public Property ContadorDescargas As Long = 0
        Public Property UltimaActualizacion As DateTime = DateTime.MinValue

        ''' <summary>
        ''' Calcula el porcentaje de avance de llenado (0% a 100%).
        ''' </summary>
        Public ReadOnly Property PorcentajeAvance As Double
            Get
                If PesoObjetivo <= 0 Then Return 0.0
                Dim porcentaje As Double = (PesoActual / PesoObjetivo) * 100.0
                If porcentaje < 0.0 Then Return 0.0
                If porcentaje > 100.0 Then Return 100.0
                Return Math.Round(porcentaje, 1)
            End Get
        End Property

        ''' <summary>
        ''' Indica si la tolva ya alcanzó el peso programado y está lista para descargar.
        ''' </summary>
        Public ReadOnly Property EstaListoParaDescargar As Boolean
            Get
                Return EstadoActual.Equals("PESO_LISTO", StringComparison.OrdinalIgnoreCase) OrElse (PesoActual >= (PesoObjetivo - Inercia))
            End Get
        End Property
    End Class
End Namespace
