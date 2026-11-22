Imports System

Namespace Clases
    ''' <summary>
    ''' Representa el estado, temperaturas y todos los parámetros configurables de la Máquina Envasadora Principal NS-GH.
    ''' </summary>
    Public Class ModeloMaquinaPrincipal
        Public Property PuertoCOM As String = "COM1"
        Public Property Conectado As Boolean = False

        ' Estados: "ESPERA", "ENVASANDO", "SELLANDO", "ARRASTRANDO", "ESPERA_TOLVAS", "DETENIDO", "DESCONECTADO"
        Public Property EstadoActual As String = "DESCONECTADO"

        Public Property ContadorBolsas As Long = 0
        Public Property BolsasPorMinuto As Double = 0.0

        ' Parámetros de ciclo de máquina
        Public Property TiempoSelladoMs As Integer = 1000
        Public Property TiempoArrastreMs As Integer = 400
        Public Property TiempoMordazaCierraMs As Integer = 400
        Public Property TiempoMordazaAbreMs As Integer = 400
        Public Property UsarFCMordaza As Boolean = False
        Public Property UsarSensorTaca As Boolean = False
        Public Property SecuenciaOperacion As Integer = 0     ' 0 = Secuencial, 1 = Paralelo
        Public Property TipoMaquina As Integer = 0            ' 0 = SLSC (3 zonas), 1 = SLSO (4 zonas)
        Public Property ClaveAccesoLocal As Integer = 1234    ' Clave de acceso en el teclado físico

        ' Temperaturas en tiempo real (°C) de los 4 pirómetros Modbus
        Public Property TempActualSupIzq As Integer = 0
        Public Property TempActualSupDer As Integer = 0
        Public Property TempActualInfExt As Integer = 0
        Public Property TempActualInfInt As Integer = 0

        ' Temperaturas consigna (SetPoint en °C)
        Public Property TempConsignaSupIzq As Integer = 150
        Public Property TempConsignaSupDer As Integer = 150
        Public Property TempConsignaInfExt As Integer = 150
        Public Property TempConsignaInfInt As Integer = 150

        Public Property CalefaccionActiva As Boolean = False
        Public Property TolvasListasFisico As Boolean = False
        Public Property UltimaActualizacion As DateTime = DateTime.MinValue
    End Class
End Namespace
