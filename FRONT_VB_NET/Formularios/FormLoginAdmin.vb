Imports System
Imports System.Windows.Forms
Imports Clases

Namespace Formularios
    Public Class FormLoginAdmin
        Private Sub btnAceptar_Click(sender As Object, e As EventArgs) Handles btnAceptar.Click
            If txtPassword.Text.Trim() = ConfiguracionApp.Instancia.ClaveAdmin Then
                Me.DialogResult = DialogResult.OK
                Me.Close()
            Else
                MessageBox.Show("Clave incorrecta. Acceso denegado.", "Seguridad", MessageBoxButtons.OK, MessageBoxIcon.Warning)
                txtPassword.Clear()
                txtPassword.Focus()
            End If
        End Sub

        Private Sub btnCancelar_Click(sender As Object, e As EventArgs) Handles btnCancelar.Click
            Me.DialogResult = DialogResult.Cancel
            Me.Close()
        End Sub
    End Class
End Namespace
