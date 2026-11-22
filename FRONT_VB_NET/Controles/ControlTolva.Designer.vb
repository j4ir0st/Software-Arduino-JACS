Namespace Controles
    <Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
    Partial Class ControlTolva
        Inherits System.Windows.Forms.UserControl

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

        Friend WithEvents pnlContenedor As System.Windows.Forms.Panel
        Friend WithEvents lblTitulo As System.Windows.Forms.Label
        Friend WithEvents lblEstado As System.Windows.Forms.Label
        Friend WithEvents lblPesoActual As System.Windows.Forms.Label
        Friend WithEvents pbarProgreso As System.Windows.Forms.ProgressBar
        Friend WithEvents lblProgresoTexto As System.Windows.Forms.Label
        Friend WithEvents numPesoObjetivo As System.Windows.Forms.NumericUpDown
        Friend WithEvents numVibracionFina As System.Windows.Forms.NumericUpDown
        Friend WithEvents numTiempoDescarga As System.Windows.Forms.NumericUpDown
        Friend WithEvents btnEnviarParametros As System.Windows.Forms.Button
        Friend WithEvents btnIniciar As System.Windows.Forms.Button
        Friend WithEvents btnDetener As System.Windows.Forms.Button
        Friend WithEvents btnDescargar As System.Windows.Forms.Button
        Friend WithEvents btnTara As System.Windows.Forms.Button
        Friend WithEvents lblContadorDescargas As System.Windows.Forms.Label
        Friend WithEvents lblLabelObj As System.Windows.Forms.Label
        Friend WithEvents lblLabelVF As System.Windows.Forms.Label
        Friend WithEvents lblLabelTDesc As System.Windows.Forms.Label

        <System.Diagnostics.DebuggerStepThrough()>
        Private Sub InitializeComponent()
            Me.pnlContenedor = New System.Windows.Forms.Panel()
            Me.lblTitulo = New System.Windows.Forms.Label()
            Me.lblEstado = New System.Windows.Forms.Label()
            Me.lblPesoActual = New System.Windows.Forms.Label()
            Me.pbarProgreso = New System.Windows.Forms.ProgressBar()
            Me.lblProgresoTexto = New System.Windows.Forms.Label()
            Me.numPesoObjetivo = New System.Windows.Forms.NumericUpDown()
            Me.numVibracionFina = New System.Windows.Forms.NumericUpDown()
            Me.numTiempoDescarga = New System.Windows.Forms.NumericUpDown()
            Me.btnEnviarParametros = New System.Windows.Forms.Button()
            Me.btnIniciar = New System.Windows.Forms.Button()
            Me.btnDetener = New System.Windows.Forms.Button()
            Me.btnDescargar = New System.Windows.Forms.Button()
            Me.btnTara = New System.Windows.Forms.Button()
            Me.lblContadorDescargas = New System.Windows.Forms.Label()
            Me.lblLabelObj = New System.Windows.Forms.Label()
            Me.lblLabelVF = New System.Windows.Forms.Label()
            Me.lblLabelTDesc = New System.Windows.Forms.Label()
            CType(Me.numPesoObjetivo, System.ComponentModel.ISupportInitialize).BeginInit()
            CType(Me.numVibracionFina, System.ComponentModel.ISupportInitialize).BeginInit()
            CType(Me.numTiempoDescarga, System.ComponentModel.ISupportInitialize).BeginInit()
            Me.pnlContenedor.SuspendLayout()
            Me.SuspendLayout()
            '
            'pnlContenedor
            '
            Me.pnlContenedor.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
            Me.pnlContenedor.Controls.Add(Me.lblTitulo)
            Me.pnlContenedor.Controls.Add(Me.lblEstado)
            Me.pnlContenedor.Controls.Add(Me.lblPesoActual)
            Me.pnlContenedor.Controls.Add(Me.pbarProgreso)
            Me.pnlContenedor.Controls.Add(Me.lblProgresoTexto)
            Me.pnlContenedor.Controls.Add(Me.lblLabelObj)
            Me.pnlContenedor.Controls.Add(Me.numPesoObjetivo)
            Me.pnlContenedor.Controls.Add(Me.lblLabelVF)
            Me.pnlContenedor.Controls.Add(Me.numVibracionFina)
            Me.pnlContenedor.Controls.Add(Me.lblLabelTDesc)
            Me.pnlContenedor.Controls.Add(Me.numTiempoDescarga)
            Me.pnlContenedor.Controls.Add(Me.btnEnviarParametros)
            Me.pnlContenedor.Controls.Add(Me.btnIniciar)
            Me.pnlContenedor.Controls.Add(Me.btnDetener)
            Me.pnlContenedor.Controls.Add(Me.btnDescargar)
            Me.pnlContenedor.Controls.Add(Me.btnTara)
            Me.pnlContenedor.Controls.Add(Me.lblContadorDescargas)
            Me.pnlContenedor.Dock = System.Windows.Forms.DockStyle.Fill
            Me.pnlContenedor.Location = New System.Drawing.Point(0, 0)
            Me.pnlContenedor.Name = "pnlContenedor"
            Me.pnlContenedor.Size = New System.Drawing.Size(260, 365)
            Me.pnlContenedor.TabIndex = 0
            '
            'lblTitulo
            '
            Me.lblTitulo.BackColor = System.Drawing.Color.FromArgb(CType(CType(33, Byte), Integer), CType(CType(43, Byte), Integer), CType(CType(54, Byte), Integer))
            Me.lblTitulo.Font = New System.Drawing.Font("Segoe UI", 11.0!, System.Drawing.FontStyle.Bold)
            Me.lblTitulo.ForeColor = System.Drawing.Color.White
            Me.lblTitulo.Location = New System.Drawing.Point(0, 0)
            Me.lblTitulo.Name = "lblTitulo"
            Me.lblTitulo.Size = New System.Drawing.Size(258, 30)
            Me.lblTitulo.TabIndex = 0
            Me.lblTitulo.Text = "TOLVA 1 [COM3]"
            Me.lblTitulo.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
            '
            'lblEstado
            '
            Me.lblEstado.BackColor = System.Drawing.Color.DimGray
            Me.lblEstado.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.lblEstado.ForeColor = System.Drawing.Color.White
            Me.lblEstado.Location = New System.Drawing.Point(10, 36)
            Me.lblEstado.Name = "lblEstado"
            Me.lblEstado.Size = New System.Drawing.Size(238, 22)
            Me.lblEstado.TabIndex = 1
            Me.lblEstado.Text = "EN ESPERA"
            Me.lblEstado.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
            '
            'lblPesoActual
            '
            Me.lblPesoActual.BackColor = System.Drawing.Color.Black
            Me.lblPesoActual.Font = New System.Drawing.Font("Consolas", 22.0!, System.Drawing.FontStyle.Bold)
            Me.lblPesoActual.ForeColor = System.Drawing.Color.Lime
            Me.lblPesoActual.Location = New System.Drawing.Point(10, 64)
            Me.lblPesoActual.Name = "lblPesoActual"
            Me.lblPesoActual.Size = New System.Drawing.Size(238, 48)
            Me.lblPesoActual.TabIndex = 2
            Me.lblPesoActual.Text = "0 gr"
            Me.lblPesoActual.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
            '
            'pbarProgreso
            '
            Me.pbarProgreso.Location = New System.Drawing.Point(10, 118)
            Me.pbarProgreso.Name = "pbarProgreso"
            Me.pbarProgreso.Size = New System.Drawing.Size(238, 16)
            Me.pbarProgreso.TabIndex = 3
            '
            'lblProgresoTexto
            '
            Me.lblProgresoTexto.Font = New System.Drawing.Font("Segoe UI", 8.5!, System.Drawing.FontStyle.Bold)
            Me.lblProgresoTexto.Location = New System.Drawing.Point(10, 137)
            Me.lblProgresoTexto.Name = "lblProgresoTexto"
            Me.lblProgresoTexto.Size = New System.Drawing.Size(238, 18)
            Me.lblProgresoTexto.TabIndex = 4
            Me.lblProgresoTexto.Text = "0.0% (Obj: 500 gr)"
            Me.lblProgresoTexto.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
            '
            'lblLabelObj
            '
            Me.lblLabelObj.AutoSize = True
            Me.lblLabelObj.Font = New System.Drawing.Font("Segoe UI", 8.0!)
            Me.lblLabelObj.Location = New System.Drawing.Point(10, 160)
            Me.lblLabelObj.Name = "lblLabelObj"
            Me.lblLabelObj.Size = New System.Drawing.Size(75, 13)
            Me.lblLabelObj.TabIndex = 5
            Me.lblLabelObj.Text = "Objetivo (gr):"
            '
            'numPesoObjetivo
            '
            Me.numPesoObjetivo.Location = New System.Drawing.Point(88, 156)
            Me.numPesoObjetivo.Maximum = New Decimal(New Integer() {50000, 0, 0, 0})
            Me.numPesoObjetivo.Name = "numPesoObjetivo"
            Me.numPesoObjetivo.Size = New System.Drawing.Size(65, 22)
            Me.numPesoObjetivo.TabIndex = 6
            Me.numPesoObjetivo.Value = New Decimal(New Integer() {500, 0, 0, 0})
            '
            'lblLabelVF
            '
            Me.lblLabelVF.AutoSize = True
            Me.lblLabelVF.Font = New System.Drawing.Font("Segoe UI", 8.0!)
            Me.lblLabelVF.Location = New System.Drawing.Point(10, 184)
            Me.lblLabelVF.Name = "lblLabelVF"
            Me.lblLabelVF.Size = New System.Drawing.Size(69, 13)
            Me.lblLabelVF.TabIndex = 7
            Me.lblLabelVF.Text = "V. Fina (gr):"
            '
            'numVibracionFina
            '
            Me.numVibracionFina.Location = New System.Drawing.Point(88, 180)
            Me.numVibracionFina.Maximum = New Decimal(New Integer() {5000, 0, 0, 0})
            Me.numVibracionFina.Name = "numVibracionFina"
            Me.numVibracionFina.Size = New System.Drawing.Size(65, 22)
            Me.numVibracionFina.TabIndex = 8
            Me.numVibracionFina.Value = New Decimal(New Integer() {30, 0, 0, 0})
            '
            'lblLabelTDesc
            '
            Me.lblLabelTDesc.AutoSize = True
            Me.lblLabelTDesc.Font = New System.Drawing.Font("Segoe UI", 8.0!)
            Me.lblLabelTDesc.Location = New System.Drawing.Point(10, 208)
            Me.lblLabelTDesc.Name = "lblLabelTDesc"
            Me.lblLabelTDesc.Size = New System.Drawing.Size(76, 13)
            Me.lblLabelTDesc.TabIndex = 9
            Me.lblLabelTDesc.Text = "T. Desc (ms):"
            '
            'numTiempoDescarga
            '
            Me.numTiempoDescarga.Location = New System.Drawing.Point(88, 204)
            Me.numTiempoDescarga.Maximum = New Decimal(New Integer() {30000, 0, 0, 0})
            Me.numTiempoDescarga.Minimum = New Decimal(New Integer() {100, 0, 0, 0})
            Me.numTiempoDescarga.Name = "numTiempoDescarga"
            Me.numTiempoDescarga.Size = New System.Drawing.Size(65, 22)
            Me.numTiempoDescarga.TabIndex = 10
            Me.numTiempoDescarga.Value = New Decimal(New Integer() {2000, 0, 0, 0})
            '
            'btnEnviarParametros
            '
            Me.btnEnviarParametros.BackColor = System.Drawing.Color.LightSteelBlue
            Me.btnEnviarParametros.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnEnviarParametros.Font = New System.Drawing.Font("Segoe UI", 8.0!, System.Drawing.FontStyle.Bold)
            Me.btnEnviarParametros.Location = New System.Drawing.Point(159, 156)
            Me.btnEnviarParametros.Name = "btnEnviarParametros"
            Me.btnEnviarParametros.Size = New System.Drawing.Size(89, 70)
            Me.btnEnviarParametros.TabIndex = 11
            Me.btnEnviarParametros.Text = "Aplicar Parám."
            Me.btnEnviarParametros.UseVisualStyleBackColor = False
            '
            'btnIniciar
            '
            Me.btnIniciar.BackColor = System.Drawing.Color.FromArgb(CType(CType(46, Byte), Integer), CType(CType(139, Byte), Integer), CType(CType(87, Byte), Integer))
            Me.btnIniciar.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnIniciar.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.btnIniciar.ForeColor = System.Drawing.Color.White
            Me.btnIniciar.Location = New System.Drawing.Point(10, 236)
            Me.btnIniciar.Name = "btnIniciar"
            Me.btnIniciar.Size = New System.Drawing.Size(115, 34)
            Me.btnIniciar.TabIndex = 12
            Me.btnIniciar.Text = "INICIAR"
            Me.btnIniciar.UseVisualStyleBackColor = False
            '
            'btnDetener
            '
            Me.btnDetener.BackColor = System.Drawing.Color.FromArgb(CType(CType(178, Byte), Integer), CType(CType(34, Byte), Integer), CType(CType(34, Byte), Integer))
            Me.btnDetener.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnDetener.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.btnDetener.ForeColor = System.Drawing.Color.White
            Me.btnDetener.Location = New System.Drawing.Point(133, 236)
            Me.btnDetener.Name = "btnDetener"
            Me.btnDetener.Size = New System.Drawing.Size(115, 34)
            Me.btnDetener.TabIndex = 13
            Me.btnDetener.Text = "DETENER"
            Me.btnDetener.UseVisualStyleBackColor = False
            '
            'btnDescargar
            '
            Me.btnDescargar.BackColor = System.Drawing.Color.DarkOrange
            Me.btnDescargar.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnDescargar.Font = New System.Drawing.Font("Segoe UI", 8.5!, System.Drawing.FontStyle.Bold)
            Me.btnDescargar.ForeColor = System.Drawing.Color.White
            Me.btnDescargar.Location = New System.Drawing.Point(10, 276)
            Me.btnDescargar.Name = "btnDescargar"
            Me.btnDescargar.Size = New System.Drawing.Size(115, 30)
            Me.btnDescargar.TabIndex = 14
            Me.btnDescargar.Text = "DESCARGAR"
            Me.btnDescargar.UseVisualStyleBackColor = False
            '
            'btnTara
            '
            Me.btnTara.BackColor = System.Drawing.Color.RoyalBlue
            Me.btnTara.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnTara.Font = New System.Drawing.Font("Segoe UI", 8.5!, System.Drawing.FontStyle.Bold)
            Me.btnTara.ForeColor = System.Drawing.Color.White
            Me.btnTara.Location = New System.Drawing.Point(133, 276)
            Me.btnTara.Name = "btnTara"
            Me.btnTara.Size = New System.Drawing.Size(115, 30)
            Me.btnTara.TabIndex = 15
            Me.btnTara.Text = "TARA"
            Me.btnTara.UseVisualStyleBackColor = False
            '
            'lblContadorDescargas
            '
            Me.lblContadorDescargas.BackColor = System.Drawing.Color.FromArgb(CType(CType(240, Byte), Integer), CType(CType(240, Byte), Integer), CType(CType(240, Byte), Integer))
            Me.lblContadorDescargas.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Regular)
            Me.lblContadorDescargas.Location = New System.Drawing.Point(10, 314)
            Me.lblContadorDescargas.Name = "lblContadorDescargas"
            Me.lblContadorDescargas.Size = New System.Drawing.Size(238, 22)
            Me.lblContadorDescargas.TabIndex = 16
            Me.lblContadorDescargas.Text = "Descargas Realizadas: 0"
            Me.lblContadorDescargas.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
            '
            'ControlTolva
            '
            Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
            Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
            Me.Controls.Add(Me.pnlContenedor)
            Me.Font = New System.Drawing.Font("Segoe UI", 8.25!)
            Me.Name = "ControlTolva"
            Me.Size = New System.Drawing.Size(260, 345)
            CType(Me.numPesoObjetivo, System.ComponentModel.ISupportInitialize).EndInit()
            CType(Me.numVibracionFina, System.ComponentModel.ISupportInitialize).EndInit()
            CType(Me.numTiempoDescarga, System.ComponentModel.ISupportInitialize).EndInit()
            Me.pnlContenedor.ResumeLayout(False)
            Me.pnlContenedor.PerformLayout()
            Me.ResumeLayout(False)

        End Sub
    End Class
End Namespace

        End Sub
    End Class
End Namespace
