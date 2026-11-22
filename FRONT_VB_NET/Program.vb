Imports System
Imports System.Windows.Forms
Imports Formularios

Namespace FrontEnvasadora
    Friend Module Program
        ''' <summary>
        ''' Punto de entrada principal para la aplicación de control.
        ''' </summary>
        <STAThread()>
        Sub Main()
            Application.EnableVisualStyles()
            Application.SetCompatibleTextRenderingDefault(False)
            Application.Run(New FormPrincipal())
        End Sub
    End Module
End Namespace
