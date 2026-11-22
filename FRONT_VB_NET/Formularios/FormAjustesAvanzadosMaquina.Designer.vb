Namespace Formularios
    <Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
    Partial Class FormAjustesAvanzadosMaquina
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

        Friend WithEvents grpTiempos As System.Windows.Forms.GroupBox
        Friend WithEvents lblSellado As System.Windows.Forms.Label
        Friend WithEvents numSellado As System.Windows.Forms.NumericUpDown
        Friend WithEvents lblArrastre As System.Windows.Forms.Label
        Friend WithEvents numArrastre As System.Windows.Forms.NumericUpDown
        Friend WithEvents lblMorCierra As System.Windows.Forms.Label
        Friend WithEvents numMorCierra As System.Windows.Forms.NumericUpDown
        Friend WithEvents lblMorAbre As System.Windows.Forms.Label
        Friend WithEvents numMorAbre As System.Windows.Forms.NumericUpDown

        Friend WithEvents grpModos As System.Windows.Forms.GroupBox
        Friend WithEvents chkFcMordaza As System.Windows.Forms.CheckBox
        Friend WithEvents chkSensorTaca As System.Windows.Forms.CheckBox
        Friend WithEvents lblSecuencia As System.Windows.Forms.Label
        Friend WithEvents cboSecuencia As System.Windows.Forms.ComboBox
        Friend WithEvents lblTipoMaq As System.Windows.Forms.Label
        Friend WithEvents cboTipoMaq As System.Windows.Forms.ComboBox
        Friend WithEvents lblClaveLocal As System.Windows.Forms.Label
        Friend WithEvents numClaveLocal As System.Windows.Forms.NumericUpDown

        Friend WithEvents grpTemperaturasConsigna As System.Windows.Forms.GroupBox
        Friend WithEvents lblSetT1 As System.Windows.Forms.Label
        Friend WithEvents numSetT1 As System.Windows.Forms.NumericUpDown
        Friend WithEvents lblSetT2 As System.Windows.Forms.Label
        Friend WithEvents numSetT2 As System.Windows.Forms.NumericUpDown
        Friend WithEvents lblSetT3 As System.Windows.Forms.Label
        Friend WithEvents numSetT3 As System.Windows.Forms.NumericUpDown
        Friend WithEvents lblSetT4 As System.Windows.Forms.Label
        Friend WithEvents numSetT4 As System.Windows.Forms.NumericUpDown

        Friend WithEvents btnGuardarTodo As System.Windows.Forms.Button
        Friend WithEvents btnResetContador As System.Windows.Forms.Button
        Friend WithEvents btnRestaurarFabrica As System.Windows.Forms.Button
        Friend WithEvents btnCerrar As System.Windows.Forms.Button

        <System.Diagnostics.DebuggerStepThrough()>
        Private Sub InitializeComponent()
            Me.grpTiempos = New System.Windows.Forms.GroupBox()
            Me.lblSellado = New System.Windows.Forms.Label()
            Me.numSellado = New System.Windows.Forms.NumericUpDown()
            Me.lblArrastre = New System.Windows.Forms.Label()
            Me.numArrastre = New System.Windows.Forms.NumericUpDown()
            Me.lblMorCierra = New System.Windows.Forms.Label()
            Me.numMorCierra = New System.Windows.Forms.NumericUpDown()
            Me.lblMorAbre = New System.Windows.Forms.Label()
            Me.numMorAbre = New System.Windows.Forms.NumericUpDown()
            Me.grpModos = New System.Windows.Forms.GroupBox()
            Me.chkFcMordaza = New System.Windows.Forms.CheckBox()
            Me.chkSensorTaca = New System.Windows.Forms.CheckBox()
            Me.lblSecuencia = New System.Windows.Forms.Label()
            Me.cboSecuencia = New System.Windows.Forms.ComboBox()
            Me.lblTipoMaq = New System.Windows.Forms.Label()
            Me.cboTipoMaq = New System.Windows.Forms.ComboBox()
            Me.lblClaveLocal = New System.Windows.Forms.Label()
            Me.numClaveLocal = New System.Windows.Forms.NumericUpDown()
            Me.grpTemperaturasConsigna = New System.Windows.Forms.GroupBox()
            Me.lblSetT1 = New System.Windows.Forms.Label()
            Me.numSetT1 = New System.Windows.Forms.NumericUpDown()
            Me.lblSetT2 = New System.Windows.Forms.Label()
            Me.numSetT2 = New System.Windows.Forms.NumericUpDown()
            Me.lblSetT3 = New System.Windows.Forms.Label()
            Me.numSetT3 = New System.Windows.Forms.NumericUpDown()
            Me.lblSetT4 = New System.Windows.Forms.Label()
            Me.numSetT4 = New System.Windows.Forms.NumericUpDown()
            Me.btnGuardarTodo = New System.Windows.Forms.Button()
            Me.btnResetContador = New System.Windows.Forms.Button()
            Me.btnRestaurarFabrica = New System.Windows.Forms.Button()
            Me.btnCerrar = New System.Windows.Forms.Button()
            Me.grpTiempos.SuspendLayout()
            CType(Me.numSellado, System.ComponentModel.ISupportInitialize).BeginInit()
            CType(Me.numArrastre, System.ComponentModel.ISupportInitialize).BeginInit()
            CType(Me.numMorCierra, System.ComponentModel.ISupportInitialize).BeginInit()
            CType(Me.numMorAbre, System.ComponentModel.ISupportInitialize).BeginInit()
            Me.grpModos.SuspendLayout()
            CType(Me.numClaveLocal, System.ComponentModel.ISupportInitialize).BeginInit()
            Me.grpTemperaturasConsigna.SuspendLayout()
            CType(Me.numSetT1, System.ComponentModel.ISupportInitialize).BeginInit()
            CType(Me.numSetT2, System.ComponentModel.ISupportInitialize).BeginInit()
            CType(Me.numSetT3, System.ComponentModel.ISupportInitialize).BeginInit()
            CType(Me.numSetT4, System.ComponentModel.ISupportInitialize).BeginInit()
            Me.SuspendLayout()
            '
            'grpTiempos
            '
            Me.grpTiempos.Controls.Add(Me.numMorAbre)
            Me.grpTiempos.Controls.Add(Me.lblMorAbre)
            Me.grpTiempos.Controls.Add(Me.numMorCierra)
            Me.grpTiempos.Controls.Add(Me.lblMorCierra)
            Me.grpTiempos.Controls.Add(Me.numArrastre)
            Me.grpTiempos.Controls.Add(Me.lblArrastre)
            Me.grpTiempos.Controls.Add(Me.numSellado)
            Me.grpTiempos.Controls.Add(Me.lblSellado)
            Me.grpTiempos.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.grpTiempos.Location = New System.Drawing.Point(12, 12)
            Me.grpTiempos.Name = "grpTiempos"
            Me.grpTiempos.Size = New System.Drawing.Size(260, 160)
            Me.grpTiempos.TabIndex = 0
            Me.grpTiempos.TabStop = False
            Me.grpTiempos.Text = "Tiempos de Ciclo y Movimientos"
            '
            'lblSellado
            '
            Me.lblSellado.AutoSize = True
            Me.lblSellado.Font = New System.Drawing.Font("Segoe UI", 8.5!)
            Me.lblSellado.Location = New System.Drawing.Point(15, 28)
            Me.lblSellado.Name = "lblSellado"
            Me.lblSellado.Size = New System.Drawing.Size(122, 15)
            Me.lblSellado.TabIndex = 0
            Me.lblSellado.Text = "Tiempo Sellado (ms):"
            '
            'numSellado
            '
            Me.numSellado.Location = New System.Drawing.Point(165, 25)
            Me.numSellado.Maximum = New Decimal(New Integer() {9000, 0, 0, 0})
            Me.numSellado.Minimum = New Decimal(New Integer() {100, 0, 0, 0})
            Me.numSellado.Name = "numSellado"
            Me.numSellado.Size = New System.Drawing.Size(80, 23)
            Me.numSellado.TabIndex = 1
            Me.numSellado.Value = New Decimal(New Integer() {1000, 0, 0, 0})
            '
            'lblArrastre
            '
            Me.lblArrastre.AutoSize = True
            Me.lblArrastre.Font = New System.Drawing.Font("Segoe UI", 8.5!)
            Me.lblArrastre.Location = New System.Drawing.Point(15, 60)
            Me.lblArrastre.Name = "lblArrastre"
            Me.lblArrastre.Size = New System.Drawing.Size(125, 15)
            Me.lblArrastre.TabIndex = 2
            Me.lblArrastre.Text = "Tiempo Arrastre (ms):"
            '
            'numArrastre
            '
            Me.numArrastre.Location = New System.Drawing.Point(165, 57)
            Me.numArrastre.Maximum = New Decimal(New Integer() {9000, 0, 0, 0})
            Me.numArrastre.Minimum = New Decimal(New Integer() {50, 0, 0, 0})
            Me.numArrastre.Name = "numArrastre"
            Me.numArrastre.Size = New System.Drawing.Size(80, 23)
            Me.numArrastre.TabIndex = 3
            Me.numArrastre.Value = New Decimal(New Integer() {400, 0, 0, 0})
            '
            'lblMorCierra
            '
            Me.lblMorCierra.AutoSize = True
            Me.lblMorCierra.Font = New System.Drawing.Font("Segoe UI", 8.5!)
            Me.lblMorCierra.Location = New System.Drawing.Point(15, 92)
            Me.lblMorCierra.Name = "lblMorCierra"
            Me.lblMorCierra.Size = New System.Drawing.Size(134, 15)
            Me.lblMorCierra.TabIndex = 4
            Me.lblMorCierra.Text = "Cierre Mordazas (ms):"
            '
            'numMorCierra
            '
            Me.numMorCierra.Location = New System.Drawing.Point(165, 89)
            Me.numMorCierra.Maximum = New Decimal(New Integer() {5000, 0, 0, 0})
            Me.numMorCierra.Minimum = New Decimal(New Integer() {50, 0, 0, 0})
            Me.numMorCierra.Name = "numMorCierra"
            Me.numMorCierra.Size = New System.Drawing.Size(80, 23)
            Me.numMorCierra.TabIndex = 5
            Me.numMorCierra.Value = New Decimal(New Integer() {400, 0, 0, 0})
            '
            'lblMorAbre
            '
            Me.lblMorAbre.AutoSize = True
            Me.lblMorAbre.Font = New System.Drawing.Font("Segoe UI", 8.5!)
            Me.lblMorAbre.Location = New System.Drawing.Point(15, 124)
            Me.lblMorAbre.Name = "lblMorAbre"
            Me.lblMorAbre.Size = New System.Drawing.Size(148, 15)
            Me.lblMorAbre.TabIndex = 6
            Me.lblMorAbre.Text = "Apertura Mordazas (ms):"
            '
            'numMorAbre
            '
            Me.numMorAbre.Location = New System.Drawing.Point(165, 121)
            Me.numMorAbre.Maximum = New Decimal(New Integer() {5000, 0, 0, 0})
            Me.numMorAbre.Minimum = New Decimal(New Integer() {50, 0, 0, 0})
            Me.numMorAbre.Name = "numMorAbre"
            Me.numMorAbre.Size = New System.Drawing.Size(80, 23)
            Me.numMorAbre.TabIndex = 7
            Me.numMorAbre.Value = New Decimal(New Integer() {400, 0, 0, 0})
            '
            'grpModos
            '
            Me.grpModos.Controls.Add(Me.numClaveLocal)
            Me.grpModos.Controls.Add(Me.lblClaveLocal)
            Me.grpModos.Controls.Add(Me.cboTipoMaq)
            Me.grpModos.Controls.Add(Me.lblTipoMaq)
            Me.grpModos.Controls.Add(Me.cboSecuencia)
            Me.grpModos.Controls.Add(Me.lblSecuencia)
            Me.grpModos.Controls.Add(Me.chkSensorTaca)
            Me.grpModos.Controls.Add(Me.chkFcMordaza)
            Me.grpModos.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.grpModos.Location = New System.Drawing.Point(285, 12)
            Me.grpModos.Name = "grpModos"
            Me.grpModos.Size = New System.Drawing.Size(280, 160)
            Me.grpModos.TabIndex = 1
            Me.grpModos.TabStop = False
            Me.grpModos.Text = "Sensores, Secuencia y Modelo"
            '
            'chkFcMordaza
            '
            Me.chkFcMordaza.AutoSize = True
            Me.chkFcMordaza.Font = New System.Drawing.Font("Segoe UI", 8.5!)
            Me.chkFcMordaza.Location = New System.Drawing.Point(15, 25)
            Me.chkFcMordaza.Name = "chkFcMordaza"
            Me.chkFcMordaza.Size = New System.Drawing.Size(186, 19)
            Me.chkFcMordaza.TabIndex = 0
            Me.chkFcMordaza.Text = "Fin de Carrera de Mordazas"
            Me.chkFcMordaza.UseVisualStyleBackColor = True
            '
            'chkSensorTaca
            '
            Me.chkSensorTaca.AutoSize = True
            Me.chkSensorTaca.Font = New System.Drawing.Font("Segoe UI", 8.5!)
            Me.chkSensorTaca.Location = New System.Drawing.Point(15, 48)
            Me.chkSensorTaca.Name = "chkSensorTaca"
            Me.chkSensorTaca.Size = New System.Drawing.Size(209, 19)
            Me.chkSensorTaca.TabIndex = 1
            Me.chkSensorTaca.Text = "Sensor Óptico de Taca (Fotomarca)"
            Me.chkSensorTaca.UseVisualStyleBackColor = True
            '
            'lblSecuencia
            '
            Me.lblSecuencia.AutoSize = True
            Me.lblSecuencia.Font = New System.Drawing.Font("Segoe UI", 8.5!)
            Me.lblSecuencia.Location = New System.Drawing.Point(12, 75)
            Me.lblSecuencia.Name = "lblSecuencia"
            Me.lblSecuencia.Size = New System.Drawing.Size(65, 15)
            Me.lblSecuencia.TabIndex = 2
            Me.lblSecuencia.Text = "Secuencia:"
            '
            'cboSecuencia
            '
            Me.cboSecuencia.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
            Me.cboSecuencia.Font = New System.Drawing.Font("Segoe UI", 8.0!)
            Me.cboSecuencia.FormattingEnabled = True
            Me.cboSecuencia.Items.AddRange(New Object() {"0: Secuencial (Sella->Tolva->Arrastra)", "1: Paralelo (Sella y Tolva a la vez)"})
            Me.cboSecuencia.Location = New System.Drawing.Point(82, 72)
            Me.cboSecuencia.Name = "cboSecuencia"
            Me.cboSecuencia.Size = New System.Drawing.Size(185, 21)
            Me.cboSecuencia.TabIndex = 3
            '
            'lblTipoMaq
            '
            Me.lblTipoMaq.AutoSize = True
            Me.lblTipoMaq.Font = New System.Drawing.Font("Segoe UI", 8.5!)
            Me.lblTipoMaq.Location = New System.Drawing.Point(12, 102)
            Me.lblTipoMaq.Name = "lblTipoMaq"
            Me.lblTipoMaq.Size = New System.Drawing.Size(51, 15)
            Me.lblTipoMaq.TabIndex = 4
            Me.lblTipoMaq.Text = "Modelo:"
            '
            'cboTipoMaq
            '
            Me.cboTipoMaq.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
            Me.cboTipoMaq.Font = New System.Drawing.Font("Segoe UI", 8.0!)
            Me.cboTipoMaq.FormattingEnabled = True
            Me.cboTipoMaq.Items.AddRange(New Object() {"0: SLSC (Estándar 3 Zonas)", "1: SLSO (Especial 4 Zonas)"})
            Me.cboTipoMaq.Location = New System.Drawing.Point(82, 99)
            Me.cboTipoMaq.Name = "cboTipoMaq"
            Me.cboTipoMaq.Size = New System.Drawing.Size(185, 21)
            Me.cboTipoMaq.TabIndex = 5
            '
            'lblClaveLocal
            '
            Me.lblClaveLocal.AutoSize = True
            Me.lblClaveLocal.Font = New System.Drawing.Font("Segoe UI", 8.5!)
            Me.lblClaveLocal.Location = New System.Drawing.Point(12, 129)
            Me.lblClaveLocal.Name = "lblClaveLocal"
            Me.lblClaveLocal.Size = New System.Drawing.Size(117, 15)
            Me.lblClaveLocal.TabIndex = 6
            Me.lblClaveLocal.Text = "PIN Teclado Arduino:"
            '
            'numClaveLocal
            '
            Me.numClaveLocal.Location = New System.Drawing.Point(145, 126)
            Me.numClaveLocal.Maximum = New Decimal(New Integer() {999999, 0, 0, 0})
            Me.numClaveLocal.Name = "numClaveLocal"
            Me.numClaveLocal.Size = New System.Drawing.Size(122, 23)
            Me.numClaveLocal.TabIndex = 7
            Me.numClaveLocal.Value = New Decimal(New Integer() {1234, 0, 0, 0})
            '
            'grpTemperaturasConsigna
            '
            Me.grpTemperaturasConsigna.Controls.Add(Me.numSetT4)
            Me.grpTemperaturasConsigna.Controls.Add(Me.lblSetT4)
            Me.grpTemperaturasConsigna.Controls.Add(Me.numSetT3)
            Me.grpTemperaturasConsigna.Controls.Add(Me.lblSetT3)
            Me.grpTemperaturasConsigna.Controls.Add(Me.numSetT2)
            Me.grpTemperaturasConsigna.Controls.Add(Me.lblSetT2)
            Me.grpTemperaturasConsigna.Controls.Add(Me.numSetT1)
            Me.grpTemperaturasConsigna.Controls.Add(Me.lblSetT1)
            Me.grpTemperaturasConsigna.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.grpTemperaturasConsigna.Location = New System.Drawing.Point(12, 185)
            Me.grpTemperaturasConsigna.Name = "grpTemperaturasConsigna"
            Me.grpTemperaturasConsigna.Size = New System.Drawing.Size(553, 90)
            Me.grpTemperaturasConsigna.TabIndex = 2
            Me.grpTemperaturasConsigna.TabStop = False
            Me.grpTemperaturasConsigna.Text = "Consignas de Temperatura Modbus (SetPoints en °C)"
            '
            'lblSetT1
            '
            Me.lblSetT1.AutoSize = True
            Me.lblSetT1.Font = New System.Drawing.Font("Segoe UI", 8.5!)
            Me.lblSetT1.Location = New System.Drawing.Point(15, 28)
            Me.lblSetT1.Name = "lblSetT1"
            Me.lblSetT1.Size = New System.Drawing.Size(107, 15)
            Me.lblSetT1.TabIndex = 0
            Me.lblSetT1.Text = "Sup. Izquierda (°C):"
            '
            'numSetT1
            '
            Me.numSetT1.Location = New System.Drawing.Point(135, 25)
            Me.numSetT1.Maximum = New Decimal(New Integer() {250, 0, 0, 0})
            Me.numSetT1.Name = "numSetT1"
            Me.numSetT1.Size = New System.Drawing.Size(70, 23)
            Me.numSetT1.TabIndex = 1
            Me.numSetT1.Value = New Decimal(New Integer() {150, 0, 0, 0})
            '
            'lblSetT2
            '
            Me.lblSetT2.AutoSize = True
            Me.lblSetT2.Font = New System.Drawing.Font("Segoe UI", 8.5!)
            Me.lblSetT2.Location = New System.Drawing.Point(290, 28)
            Me.lblSetT2.Name = "lblSetT2"
            Me.lblSetT2.Size = New System.Drawing.Size(100, 15)
            Me.lblSetT2.TabIndex = 2
            Me.lblSetT2.Text = "Sup. Derecha (°C):"
            '
            'numSetT2
            '
            Me.numSetT2.Location = New System.Drawing.Point(410, 25)
            Me.numSetT2.Maximum = New Decimal(New Integer() {250, 0, 0, 0})
            Me.numSetT2.Name = "numSetT2"
            Me.numSetT2.Size = New System.Drawing.Size(70, 23)
            Me.numSetT2.TabIndex = 3
            Me.numSetT2.Value = New Decimal(New Integer() {150, 0, 0, 0})
            '
            'lblSetT3
            '
            Me.lblSetT3.AutoSize = True
            Me.lblSetT3.Font = New System.Drawing.Font("Segoe UI", 8.5!)
            Me.lblSetT3.Location = New System.Drawing.Point(15, 58)
            Me.lblSetT3.Name = "lblSetT3"
            Me.lblSetT3.Size = New System.Drawing.Size(95, 15)
            Me.lblSetT3.TabIndex = 4
            Me.lblSetT3.Text = "Inf. Exterior (°C):"
            '
            'numSetT3
            '
            Me.numSetT3.Location = New System.Drawing.Point(135, 55)
            Me.numSetT3.Maximum = New Decimal(New Integer() {250, 0, 0, 0})
            Me.numSetT3.Name = "numSetT3"
            Me.numSetT3.Size = New System.Drawing.Size(70, 23)
            Me.numSetT3.TabIndex = 5
            Me.numSetT3.Value = New Decimal(New Integer() {150, 0, 0, 0})
            '
            'lblSetT4
            '
            Me.lblSetT4.AutoSize = True
            Me.lblSetT4.Font = New System.Drawing.Font("Segoe UI", 8.5!)
            Me.lblSetT4.Location = New System.Drawing.Point(290, 58)
            Me.lblSetT4.Name = "lblSetT4"
            Me.lblSetT4.Size = New System.Drawing.Size(95, 15)
            Me.lblSetT4.TabIndex = 6
            Me.lblSetT4.Text = "Inf. Interior (°C):"
            '
            'numSetT4
            '
            Me.numSetT4.Location = New System.Drawing.Point(410, 55)
            Me.numSetT4.Maximum = New Decimal(New Integer() {250, 0, 0, 0})
            Me.numSetT4.Name = "numSetT4"
            Me.numSetT4.Size = New System.Drawing.Size(70, 23)
            Me.numSetT4.TabIndex = 7
            Me.numSetT4.Value = New Decimal(New Integer() {150, 0, 0, 0})
            '
            'btnGuardarTodo
            '
            Me.btnGuardarTodo.BackColor = System.Drawing.Color.ForestGreen
            Me.btnGuardarTodo.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnGuardarTodo.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.btnGuardarTodo.ForeColor = System.Drawing.Color.White
            Me.btnGuardarTodo.Location = New System.Drawing.Point(12, 290)
            Me.btnGuardarTodo.Name = "btnGuardarTodo"
            Me.btnGuardarTodo.Size = New System.Drawing.Size(180, 36)
            Me.btnGuardarTodo.TabIndex = 3
            Me.btnGuardarTodo.Text = "Guardar Todo en Arduino"
            Me.btnGuardarTodo.UseVisualStyleBackColor = False
            '
            'btnResetContador
            '
            Me.btnResetContador.BackColor = System.Drawing.Color.Teal
            Me.btnResetContador.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnResetContador.Font = New System.Drawing.Font("Segoe UI", 8.5!, System.Drawing.FontStyle.Bold)
            Me.btnResetContador.ForeColor = System.Drawing.Color.White
            Me.btnResetContador.Location = New System.Drawing.Point(205, 290)
            Me.btnResetContador.Name = "btnResetContador"
            Me.btnResetContador.Size = New System.Drawing.Size(140, 36)
            Me.btnResetContador.TabIndex = 4
            Me.btnResetContador.Text = "Reset Contador"
            Me.btnResetContador.UseVisualStyleBackColor = False
            '
            'btnRestaurarFabrica
            '
            Me.btnRestaurarFabrica.BackColor = System.Drawing.Color.DarkOrange
            Me.btnRestaurarFabrica.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnRestaurarFabrica.Font = New System.Drawing.Font("Segoe UI", 8.5!, System.Drawing.FontStyle.Bold)
            Me.btnRestaurarFabrica.ForeColor = System.Drawing.Color.White
            Me.btnRestaurarFabrica.Location = New System.Drawing.Point(355, 290)
            Me.btnRestaurarFabrica.Name = "btnRestaurarFabrica"
            Me.btnRestaurarFabrica.Size = New System.Drawing.Size(120, 36)
            Me.btnRestaurarFabrica.TabIndex = 5
            Me.btnRestaurarFabrica.Text = "Restaurar Fábrica"
            Me.btnRestaurarFabrica.UseVisualStyleBackColor = False
            '
            'btnCerrar
            '
            Me.btnCerrar.BackColor = System.Drawing.Color.DimGray
            Me.btnCerrar.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnCerrar.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.btnCerrar.ForeColor = System.Drawing.Color.White
            Me.btnCerrar.Location = New System.Drawing.Point(485, 290)
            Me.btnCerrar.Name = "btnCerrar"
            Me.btnCerrar.Size = New System.Drawing.Size(80, 36)
            Me.btnCerrar.TabIndex = 6
            Me.btnCerrar.Text = "Cerrar"
            Me.btnCerrar.UseVisualStyleBackColor = False
            '
            'FormAjustesAvanzadosMaquina
            '
            Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
            Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
            Me.ClientSize = New System.Drawing.Size(579, 340)
            Me.Controls.Add(Me.btnCerrar)
            Me.Controls.Add(Me.btnRestaurarFabrica)
            Me.Controls.Add(Me.btnResetContador)
            Me.Controls.Add(Me.btnGuardarTodo)
            Me.Controls.Add(Me.grpTemperaturasConsigna)
            Me.Controls.Add(Me.grpModos)
            Me.Controls.Add(Me.grpTiempos)
            Me.Font = New System.Drawing.Font("Segoe UI", 8.25!)
            Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog
            Me.MaximizeBox = False
            Me.MinimizeBox = False
            Me.Name = "FormAjustesAvanzadosMaquina"
            Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent
            Me.Text = "Ajustes Avanzados de la Envasadora (Arduino NS-GH)"
            Me.grpTiempos.ResumeLayout(False)
            Me.grpTiempos.PerformLayout()
            CType(Me.numSellado, System.ComponentModel.ISupportInitialize).EndInit()
            CType(Me.numArrastre, System.ComponentModel.ISupportInitialize).EndInit()
            CType(Me.numMorCierra, System.ComponentModel.ISupportInitialize).EndInit()
            CType(Me.numMorAbre, System.ComponentModel.ISupportInitialize).EndInit()
            Me.grpModos.ResumeLayout(False)
            Me.grpModos.PerformLayout()
            CType(Me.numClaveLocal, System.ComponentModel.ISupportInitialize).EndInit()
            Me.grpTemperaturasConsigna.ResumeLayout(False)
            Me.grpTemperaturasConsigna.PerformLayout()
            CType(Me.numSetT1, System.ComponentModel.ISupportInitialize).EndInit()
            CType(Me.numSetT2, System.ComponentModel.ISupportInitialize).EndInit()
            CType(Me.numSetT3, System.ComponentModel.ISupportInitialize).EndInit()
            CType(Me.numSetT4, System.ComponentModel.ISupportInitialize).EndInit()
            Me.ResumeLayout(False)

        End Sub
    End Class
End Namespace
