Imports System
Imports System.IO
Imports System.Windows.Forms

Namespace Clases
    ''' <summary>
    ''' Administra la configuración persistente en la PC para el Frontend (clave de admin, preferencias).
    ''' </summary>
    Public Class ConfiguracionApp
        Public Shared ReadOnly Instancia As New ConfiguracionApp()

        Public Property ClaveAdmin As String = "j4ir0st123"

        Private ReadOnly Property RutaArchivoConfig As String
            Get
                Dim carpeta = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), "JACS_MAQUINAS")
                If Not Directory.Exists(carpeta) Then
                    Directory.CreateDirectory(carpeta)
                End If
                Return Path.Combine(carpeta, "configuracion_admin.cfg")
            End Get
        End Property

        Private Sub New()
            Cargar()
        End Sub

        ''' <summary>
        ''' Carga la configuración desde el disco. Si no existe, guarda los valores por defecto.
        ''' </summary>
        Public Sub Cargar()
            Try
                If File.Exists(RutaArchivoConfig) Then
                    Dim lineas = File.ReadAllLines(RutaArchivoConfig)
                    For Each linea In lineas
                        Dim parte = linea.Trim()
                        If parte.StartsWith("CLAVE_ADMIN=") Then
                            Dim clave = parte.Substring("CLAVE_ADMIN=".Length).Trim()
                            If Not String.IsNullOrEmpty(clave) Then
                                ClaveAdmin = clave
                            End If
                        End If
                    Next
                Else
                    Guardar()
                End If
            Catch
            End Try
        End Sub

        ''' <summary>
        ''' Guarda de forma persistente la clave de administrador en la PC.
        ''' </summary>
        Public Sub Guardar()
            Try
                Dim contenido As String = "CLAVE_ADMIN=" & ClaveAdmin & Environment.NewLine
                File.WriteAllText(RutaArchivoConfig, contenido)
            Catch ex As Exception
                MessageBox.Show("No se pudo guardar la configuración: " & ex.Message, "Configuración", MessageBoxButtons.OK, MessageBoxIcon.Warning)
            End Try
        End Sub

        ''' <summary>
        ''' Valida y actualiza la clave de administrador.
        ''' </summary>
        Public Function CambiarClave(claveActual As String, nuevaClave As String) As Boolean
            If claveActual = ClaveAdmin Then
                ClaveAdmin = nuevaClave
                Guardar()
                Return True
            End If
            Return False
        End Function
    End Class
End Namespace
