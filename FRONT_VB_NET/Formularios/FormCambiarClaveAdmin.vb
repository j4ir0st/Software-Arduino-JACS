Imports System
Imports System.Windows.Forms
Imports Clases

Namespace Formularios
    Public Class FormCambiarClaveAdmin
        Private Sub btnGuardar_Click(sender As Object, e As EventArgs) Handles btnGuardar.Click
            Dim actual = txtClaveActual.Text.Trim()
            Dim nueva = txtNuevaClave.Text.Trim()
            Dim confirmacion = txtConfirmarClave.Text.Trim()

            If String.IsNullOrEmpty(nueva) Then
                MessageBox.Show("La nueva clave no puede estar vacía.", "Validación", MessageBoxButtons.OK, MessageBoxIcon.Warning)
                txtNuevaClave.Focus()
                Return
            End If

            If nueva <> confirmacion Then
                MessageBox.Show("La nueva clave y su confirmación no coinciden.", "Validación", MessageBoxButtons.OK, MessageBoxIcon.Warning)
                txtConfirmarClave.Clear()
                txtConfirmarClave.Focus()
                Return
            End If

            If ConfiguracionApp.Instancia.CambiarClave(actual, nueva) Then
                MessageBox.Show("Clave de Administrador actualizada y guardada con éxito en la PC.", "Seguridad", MessageBoxButtons.OK, MessageBoxIcon.Information)
                Me.DialogResult = DialogResult.OK
                Me.Close()
            Else
                MessageBox.Show("La clave actual ingresada es incorrecta.", "Error de Seguridad", MessageBoxButtons.OK, MessageBoxIcon.Error)
                txtClaveActual.Clear()
                txtClaveActual.Focus()
            End If
        End Sub

        Private Sub btnCancelar_Click(sender As Object, e As EventArgs) Handles btnCancelar.Click
            Me.DialogResult = DialogResult.Cancel
            Me.Close()
        End Sub
    End Class
End Namespace
