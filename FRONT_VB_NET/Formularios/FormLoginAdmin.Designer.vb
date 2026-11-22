Namespace Formularios
    <Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
    Partial Class FormLoginAdmin
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

        Friend WithEvents lblInstruccion As System.Windows.Forms.Label
        Friend WithEvents txtPassword As System.Windows.Forms.TextBox
        Friend WithEvents btnAceptar As System.Windows.Forms.Button
        Friend WithEvents btnCancelar As System.Windows.Forms.Button

        <System.Diagnostics.DebuggerStepThrough()>
        Private Sub InitializeComponent()
            Me.lblInstruccion = New System.Windows.Forms.Label()
            Me.txtPassword = New System.Windows.Forms.TextBox()
            Me.btnAceptar = New System.Windows.Forms.Button()
            Me.btnCancelar = New System.Windows.Forms.Button()
            Me.SuspendLayout()
            '
            'lblInstruccion
            '
            Me.lblInstruccion.Font = New System.Drawing.Font("Segoe UI", 10.0!)
            Me.lblInstruccion.Location = New System.Drawing.Point(20, 20)
            Me.lblInstruccion.Name = "lblInstruccion"
            Me.lblInstruccion.Size = New System.Drawing.Size(260, 40)
            Me.lblInstruccion.TabIndex = 0
            Me.lblInstruccion.Text = "Ingrese la clave de administrador para acceder a configuraciones avanzadas:"
            '
            'txtPassword
            '
            Me.txtPassword.Font = New System.Drawing.Font("Segoe UI", 12.0!, System.Drawing.FontStyle.Bold)
            Me.txtPassword.Location = New System.Drawing.Point(24, 70)
            Me.txtPassword.Name = "txtPassword"
            Me.txtPassword.PasswordChar = Global.Microsoft.VisualBasic.ChrW(8226)
            Me.txtPassword.Size = New System.Drawing.Size(256, 29)
            Me.txtPassword.TabIndex = 1
            Me.txtPassword.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
            '
            'btnAceptar
            '
            Me.btnAceptar.BackColor = System.Drawing.Color.ForestGreen
            Me.btnAceptar.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnAceptar.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.btnAceptar.ForeColor = System.Drawing.Color.White
            Me.btnAceptar.Location = New System.Drawing.Point(24, 115)
            Me.btnAceptar.Name = "btnAceptar"
            Me.btnAceptar.Size = New System.Drawing.Size(120, 32)
            Me.btnAceptar.TabIndex = 2
            Me.btnAceptar.Text = "Aceptar"
            Me.btnAceptar.UseVisualStyleBackColor = False
            '
            'btnCancelar
            '
            Me.btnCancelar.BackColor = System.Drawing.Color.Firebrick
            Me.btnCancelar.DialogResult = System.Windows.Forms.DialogResult.Cancel
            Me.btnCancelar.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnCancelar.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.btnCancelar.ForeColor = System.Drawing.Color.White
            Me.btnCancelar.Location = New System.Drawing.Point(160, 115)
            Me.btnCancelar.Name = "btnCancelar"
            Me.btnCancelar.Size = New System.Drawing.Size(120, 32)
            Me.btnCancelar.TabIndex = 3
            Me.btnCancelar.Text = "Cancelar"
            Me.btnCancelar.UseVisualStyleBackColor = False
            '
            'FormLoginAdmin
            '
            Me.AcceptButton = Me.btnAceptar
            Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
            Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
            Me.CancelButton = Me.btnCancelar
            Me.ClientSize = New System.Drawing.Size(304, 166)
            Me.Controls.Add(Me.btnCancelar)
            Me.Controls.Add(Me.btnAceptar)
            Me.Controls.Add(Me.txtPassword)
            Me.Controls.Add(Me.lblInstruccion)
            Me.Font = New System.Drawing.Font("Segoe UI", 8.25!)
            Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog
            Me.MaximizeBox = False
            Me.MinimizeBox = False
            Me.Name = "FormLoginAdmin"
            Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent
            Me.Text = "Acceso Administrador"
            Me.ResumeLayout(False)
            Me.PerformLayout()

        End Sub
    End Class
End Namespace
