Namespace Formularios
    <Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
    Partial Class FormConfiguracionPuertos
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

        Friend WithEvents grpDeteccion As System.Windows.Forms.GroupBox
        Friend WithEvents btnEscanear As System.Windows.Forms.Button
        Friend WithEvents lstResultadosEscaneo As System.Windows.Forms.ListBox
        Friend WithEvents grpAsignacion As System.Windows.Forms.GroupBox
        Friend WithEvents lblMaquinaPrincipal As System.Windows.Forms.Label
        Friend WithEvents cboPuertoMaquina As System.Windows.Forms.ComboBox
        Friend WithEvents dgvTolvas As System.Windows.Forms.DataGridView
        Friend WithEvents colId As System.Windows.Forms.DataGridViewTextBoxColumn
        Friend WithEvents colNombre As System.Windows.Forms.DataGridViewTextBoxColumn
        Friend WithEvents colPuerto As System.Windows.Forms.DataGridViewComboBoxColumn
        Friend WithEvents btnAgregarTolva As System.Windows.Forms.Button
        Friend WithEvents btnEliminarTolva As System.Windows.Forms.Button
        Friend WithEvents btnGuardarConectar As System.Windows.Forms.Button
        Friend WithEvents btnCerrar As System.Windows.Forms.Button

        <System.Diagnostics.DebuggerStepThrough()>
        Private Sub InitializeComponent()
            Me.grpDeteccion = New System.Windows.Forms.GroupBox()
            Me.btnEscanear = New System.Windows.Forms.Button()
            Me.lstResultadosEscaneo = New System.Windows.Forms.ListBox()
            Me.grpAsignacion = New System.Windows.Forms.GroupBox()
            Me.lblMaquinaPrincipal = New System.Windows.Forms.Label()
            Me.cboPuertoMaquina = New System.Windows.Forms.ComboBox()
            Me.dgvTolvas = New System.Windows.Forms.DataGridView()
            Me.colId = New System.Windows.Forms.DataGridViewTextBoxColumn()
            Me.colNombre = New System.Windows.Forms.DataGridViewTextBoxColumn()
            Me.colPuerto = New System.Windows.Forms.DataGridViewComboBoxColumn()
            Me.btnAgregarTolva = New System.Windows.Forms.Button()
            Me.btnEliminarTolva = New System.Windows.Forms.Button()
            Me.btnGuardarConectar = New System.Windows.Forms.Button()
            Me.btnCerrar = New System.Windows.Forms.Button()
            Me.grpDeteccion.SuspendLayout()
            Me.grpAsignacion.SuspendLayout()
            CType(Me.dgvTolvas, System.ComponentModel.ISupportInitialize).BeginInit()
            Me.SuspendLayout()
            '
            'grpDeteccion
            '
            Me.grpDeteccion.Controls.Add(Me.lstResultadosEscaneo)
            Me.grpDeteccion.Controls.Add(Me.btnEscanear)
            Me.grpDeteccion.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.grpDeteccion.Location = New System.Drawing.Point(12, 12)
            Me.grpDeteccion.Name = "grpDeteccion"
            Me.grpDeteccion.Size = New System.Drawing.Size(460, 160)
            Me.grpDeteccion.TabIndex = 0
            Me.grpDeteccion.TabStop = False
            Me.grpDeteccion.Text = "Auto-Detección de Arduinos en Puertos USB"
            '
            'btnEscanear
            '
            Me.btnEscanear.BackColor = System.Drawing.Color.DodgerBlue
            Me.btnEscanear.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnEscanear.ForeColor = System.Drawing.Color.White
            Me.btnEscanear.Location = New System.Drawing.Point(15, 25)
            Me.btnEscanear.Name = "btnEscanear"
            Me.btnEscanear.Size = New System.Drawing.Size(180, 32)
            Me.btnEscanear.TabIndex = 0
            Me.btnEscanear.Text = "Escanear Puertos USB"
            Me.btnEscanear.UseVisualStyleBackColor = False
            '
            'lstResultadosEscaneo
            '
            Me.lstResultadosEscaneo.Font = New System.Drawing.Font("Segoe UI", 9.0!)
            Me.lstResultadosEscaneo.FormattingEnabled = True
            Me.lstResultadosEscaneo.ItemHeight = 15
            Me.lstResultadosEscaneo.Location = New System.Drawing.Point(15, 65)
            Me.lstResultadosEscaneo.Name = "lstResultadosEscaneo"
            Me.lstResultadosEscaneo.Size = New System.Drawing.Size(430, 79)
            Me.lstResultadosEscaneo.TabIndex = 1
            '
            'grpAsignacion
            '
            Me.grpAsignacion.Controls.Add(Me.btnEliminarTolva)
            Me.grpAsignacion.Controls.Add(Me.btnAgregarTolva)
            Me.grpAsignacion.Controls.Add(Me.dgvTolvas)
            Me.grpAsignacion.Controls.Add(Me.cboPuertoMaquina)
            Me.grpAsignacion.Controls.Add(Me.lblMaquinaPrincipal)
            Me.grpAsignacion.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.grpAsignacion.Location = New System.Drawing.Point(12, 185)
            Me.grpAsignacion.Name = "grpAsignacion"
            Me.grpAsignacion.Size = New System.Drawing.Size(460, 240)
            Me.grpAsignacion.TabIndex = 1
            Me.grpAsignacion.TabStop = False
            Me.grpAsignacion.Text = "Asignación de Puertos y Gestión de Tolvas"
            '
            'lblMaquinaPrincipal
            '
            Me.lblMaquinaPrincipal.AutoSize = True
            Me.lblMaquinaPrincipal.Font = New System.Drawing.Font("Segoe UI", 9.0!)
            Me.lblMaquinaPrincipal.Location = New System.Drawing.Point(15, 28)
            Me.lblMaquinaPrincipal.Name = "lblMaquinaPrincipal"
            Me.lblMaquinaPrincipal.Size = New System.Drawing.Size(193, 15)
            Me.lblMaquinaPrincipal.TabIndex = 0
            Me.lblMaquinaPrincipal.Text = "Máquina Principal (NS-GH Selladora):"
            '
            'cboPuertoMaquina
            '
            Me.cboPuertoMaquina.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
            Me.cboPuertoMaquina.Font = New System.Drawing.Font("Segoe UI", 9.0!)
            Me.cboPuertoMaquina.FormattingEnabled = True
            Me.cboPuertoMaquina.Location = New System.Drawing.Point(220, 25)
            Me.cboPuertoMaquina.Name = "cboPuertoMaquina"
            Me.cboPuertoMaquina.Size = New System.Drawing.Size(120, 23)
            Me.cboPuertoMaquina.TabIndex = 1
            '
            'dgvTolvas
            '
            Me.dgvTolvas.AllowUserToAddRows = False
            Me.dgvTolvas.AllowUserToDeleteRows = False
            Me.dgvTolvas.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize
            Me.dgvTolvas.Columns.AddRange(New System.Windows.Forms.DataGridViewColumn() {Me.colId, Me.colNombre, Me.colPuerto})
            Me.dgvTolvas.Location = New System.Drawing.Point(15, 60)
            Me.dgvTolvas.Name = "dgvTolvas"
            Me.dgvTolvas.Size = New System.Drawing.Size(430, 130)
            Me.dgvTolvas.TabIndex = 2
            '
            'colId
            '
            Me.colId.HeaderText = "ID"
            Me.colId.Name = "colId"
            Me.colId.ReadOnly = True
            Me.colId.Width = 50
            '
            'colNombre
            '
            Me.colNombre.HeaderText = "Nombre Tolva"
            Me.colNombre.Name = "colNombre"
            Me.colNombre.Width = 180
            '
            'colPuerto
            '
            Me.colPuerto.HeaderText = "Puerto COM"
            Me.colPuerto.Name = "colPuerto"
            Me.colPuerto.Width = 130
            '
            'btnAgregarTolva
            '
            Me.btnAgregarTolva.BackColor = System.Drawing.Color.MediumSeaGreen
            Me.btnAgregarTolva.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnAgregarTolva.ForeColor = System.Drawing.Color.White
            Me.btnAgregarTolva.Location = New System.Drawing.Point(15, 200)
            Me.btnAgregarTolva.Name = "btnAgregarTolva"
            Me.btnAgregarTolva.Size = New System.Drawing.Size(130, 28)
            Me.btnAgregarTolva.TabIndex = 3
            Me.btnAgregarTolva.Text = "+ Agregar Tolva"
            Me.btnAgregarTolva.UseVisualStyleBackColor = False
            '
            'btnEliminarTolva
            '
            Me.btnEliminarTolva.BackColor = System.Drawing.Color.IndianRed
            Me.btnEliminarTolva.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnEliminarTolva.ForeColor = System.Drawing.Color.White
            Me.btnEliminarTolva.Location = New System.Drawing.Point(160, 200)
            Me.btnEliminarTolva.Name = "btnEliminarTolva"
            Me.btnEliminarTolva.Size = New System.Drawing.Size(130, 28)
            Me.btnEliminarTolva.TabIndex = 4
            Me.btnEliminarTolva.Text = "- Eliminar Tolva"
            Me.btnEliminarTolva.UseVisualStyleBackColor = False
            '
            'btnGuardarConectar
            '
            Me.btnGuardarConectar.BackColor = System.Drawing.Color.ForestGreen
            Me.btnGuardarConectar.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnGuardarConectar.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.btnGuardarConectar.ForeColor = System.Drawing.Color.White
            Me.btnGuardarConectar.Location = New System.Drawing.Point(210, 440)
            Me.btnGuardarConectar.Name = "btnGuardarConectar"
            Me.btnGuardarConectar.Size = New System.Drawing.Size(150, 34)
            Me.btnGuardarConectar.TabIndex = 2
            Me.btnGuardarConectar.Text = "Guardar y Conectar"
            Me.btnGuardarConectar.UseVisualStyleBackColor = False
            '
            'btnCerrar
            '
            Me.btnCerrar.BackColor = System.Drawing.Color.DimGray
            Me.btnCerrar.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnCerrar.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.btnCerrar.ForeColor = System.Drawing.Color.White
            Me.btnCerrar.Location = New System.Drawing.Point(370, 440)
            Me.btnCerrar.Name = "btnCerrar"
            Me.btnCerrar.Size = New System.Drawing.Size(100, 34)
            Me.btnCerrar.TabIndex = 3
            Me.btnCerrar.Text = "Cerrar"
            Me.btnCerrar.UseVisualStyleBackColor = False
            '
            'FormConfiguracionPuertos
            '
            Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
            Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
            Me.ClientSize = New System.Drawing.Size(484, 486)
            Me.Controls.Add(Me.btnCerrar)
            Me.Controls.Add(Me.btnGuardarConectar)
            Me.Controls.Add(Me.grpAsignacion)
            Me.Controls.Add(Me.grpDeteccion)
            Me.Font = New System.Drawing.Font("Segoe UI", 8.25!)
            Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog
            Me.MaximizeBox = False
            Me.MinimizeBox = False
            Me.Name = "FormConfiguracionPuertos"
            Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent
            Me.Text = "Configuración de Puertos USB y Tolvas"
            Me.grpDeteccion.ResumeLayout(False)
            Me.grpAsignacion.ResumeLayout(False)
            Me.grpAsignacion.PerformLayout()
            CType(Me.dgvTolvas, System.ComponentModel.ISupportInitialize).EndInit()
            Me.ResumeLayout(False)

        End Sub
    End Class
End Namespace
