Namespace Formularios
    <Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
    Partial Class FormCambiarClaveAdmin
        Inherits System.Windows.Forms.Form

        <System.Diagnostics.DebuggerNonUserCode()>
        Protected Overrides Sub Dispose(ByVal disposing As Boolean)
            Try
                If disposing AndAlso components IsNot Nothing Then
                    components.Dispose()
                End If
            Finally
                MyBase.Dispose(disposing)
            End Try
        End Sub

        Private components As System.ComponentModel.IContainer

        Friend WithEvents lblClaveActual As System.Windows.Forms.Label
        Friend WithEvents txtClaveActual As System.Windows.Forms.TextBox
        Friend WithEvents lblNuevaClave As System.Windows.Forms.Label
        Friend WithEvents txtNuevaClave As System.Windows.Forms.TextBox
        Friend WithEvents lblConfirmarClave As System.Windows.Forms.Label
        Friend WithEvents txtConfirmarClave As System.Windows.Forms.TextBox
        Friend WithEvents btnGuardar As System.Windows.Forms.Button
        Friend WithEvents btnCancelar As System.Windows.Forms.Button

        <System.Diagnostics.DebuggerStepThrough()>
        Private Sub InitializeComponent()
            Me.lblClaveActual = New System.Windows.Forms.Label()
            Me.txtClaveActual = New System.Windows.Forms.TextBox()
            Me.lblNuevaClave = New System.Windows.Forms.Label()
            Me.txtNuevaClave = New System.Windows.Forms.TextBox()
            Me.lblConfirmarClave = New System.Windows.Forms.Label()
            Me.txtConfirmarClave = New System.Windows.Forms.TextBox()
            Me.btnGuardar = New System.Windows.Forms.Button()
            Me.btnCancelar = New System.Windows.Forms.Button()
            Me.SuspendLayout()
            '
            'lblClaveActual
            '
            Me.lblClaveActual.AutoSize = True
            Me.lblClaveActual.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.lblClaveActual.Location = New System.Drawing.Point(20, 18)
            Me.lblClaveActual.Name = "lblClaveActual"
            Me.lblClaveActual.Size = New System.Drawing.Size(76, 15)
            Me.lblClaveActual.TabIndex = 0
            Me.lblClaveActual.Text = "Clave Actual:"
            '
            'txtClaveActual
            '
            Me.txtClaveActual.Font = New System.Drawing.Font("Segoe UI", 10.0!)
            Me.txtClaveActual.Location = New System.Drawing.Point(20, 38)
            Me.txtClaveActual.Name = "txtClaveActual"
            Me.txtClaveActual.PasswordChar = Global.Microsoft.VisualBasic.ChrW(8226)
            Me.txtClaveActual.Size = New System.Drawing.Size(260, 25)
            Me.txtClaveActual.TabIndex = 1
            '
            'lblNuevaClave
            '
            Me.lblNuevaClave.AutoSize = True
            Me.lblNuevaClave.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.lblNuevaClave.Location = New System.Drawing.Point(20, 75)
            Me.lblNuevaClave.Name = "lblNuevaClave"
            Me.lblNuevaClave.Size = New System.Drawing.Size(79, 15)
            Me.lblNuevaClave.TabIndex = 2
            Me.lblNuevaClave.Text = "Nueva Clave:"
            '
            'txtNuevaClave
            '
            Me.txtNuevaClave.Font = New System.Drawing.Font("Segoe UI", 10.0!)
            Me.txtNuevaClave.Location = New System.Drawing.Point(20, 95)
            Me.txtNuevaClave.Name = "txtNuevaClave"
            Me.txtNuevaClave.PasswordChar = Global.Microsoft.VisualBasic.ChrW(8226)
            Me.txtNuevaClave.Size = New System.Drawing.Size(260, 25)
            Me.txtNuevaClave.TabIndex = 3
            '
            'lblConfirmarClave
            '
            Me.lblConfirmarClave.AutoSize = True
            Me.lblConfirmarClave.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.lblConfirmarClave.Location = New System.Drawing.Point(20, 132)
            Me.lblConfirmarClave.Name = "lblConfirmarClave"
            Me.lblConfirmarClave.Size = New System.Drawing.Size(135, 15)
            Me.lblConfirmarClave.TabIndex = 4
            Me.lblConfirmarClave.Text = "Confirmar Nueva Clave:"
            '
            'txtConfirmarClave
            '
            Me.txtConfirmarClave.Font = New System.Drawing.Font("Segoe UI", 10.0!)
            Me.txtConfirmarClave.Location = New System.Drawing.Point(20, 152)
            Me.txtConfirmarClave.Name = "txtConfirmarClave"
            Me.txtConfirmarClave.PasswordChar = Global.Microsoft.VisualBasic.ChrW(8226)
            Me.txtConfirmarClave.Size = New System.Drawing.Size(260, 25)
            Me.txtConfirmarClave.TabIndex = 5
            '
            'btnGuardar
            '
            Me.btnGuardar.BackColor = System.Drawing.Color.ForestGreen
            Me.btnGuardar.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnGuardar.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.btnGuardar.ForeColor = System.Drawing.Color.White
            Me.btnGuardar.Location = New System.Drawing.Point(20, 195)
            Me.btnGuardar.Name = "btnGuardar"
            Me.btnGuardar.Size = New System.Drawing.Size(125, 34)
            Me.btnGuardar.TabIndex = 6
            Me.btnGuardar.Text = "Guardar Clave"
            Me.btnGuardar.UseVisualStyleBackColor = False
            '
            'btnCancelar
            '
            Me.btnCancelar.BackColor = System.Drawing.Color.DimGray
            Me.btnCancelar.DialogResult = System.Windows.Forms.DialogResult.Cancel
            Me.btnCancelar.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnCancelar.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.btnCancelar.ForeColor = System.Drawing.Color.White
            Me.btnCancelar.Location = New System.Drawing.Point(155, 195)
            Me.btnCancelar.Name = "btnCancelar"
            Me.btnCancelar.Size = New System.Drawing.Size(125, 34)
            Me.btnCancelar.TabIndex = 7
            Me.btnCancelar.Text = "Cancelar"
            Me.btnCancelar.UseVisualStyleBackColor = False
            '
            'FormCambiarClaveAdmin
            '
            Me.AcceptButton = Me.btnGuardar
            Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
            Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
            Me.CancelButton = Me.btnCancelar
            Me.ClientSize = New System.Drawing.Size(304, 246)
            Me.Controls.Add(Me.btnCancelar)
            Me.Controls.Add(Me.btnGuardar)
            Me.Controls.Add(Me.txtConfirmarClave)
            Me.Controls.Add(Me.lblConfirmarClave)
            Me.Controls.Add(Me.txtNuevaClave)
            Me.Controls.Add(Me.lblNuevaClave)
            Me.Controls.Add(Me.txtClaveActual)
            Me.Controls.Add(Me.lblClaveActual)
            Me.Font = New System.Drawing.Font("Segoe UI", 8.25!)
            Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog
            Me.MaximizeBox = False
            Me.MinimizeBox = False
            Me.Name = "FormCambiarClaveAdmin"
            Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent
            Me.Text = "Cambiar Clave de Administrador"
            Me.ResumeLayout(False)
            Me.PerformLayout()

        End Sub
    End Class
End Namespace
