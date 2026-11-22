Namespace Formularios
    <Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
    Partial Class FormPrincipal
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

        Friend WithEvents pnlHeader As System.Windows.Forms.Panel
        Friend WithEvents lblTitulo As System.Windows.Forms.Label
        Friend WithEvents lblSubtitulo As System.Windows.Forms.Label
        Friend WithEvents lblModoUsuario As System.Windows.Forms.Label
        Friend WithEvents btnModoAdmin As System.Windows.Forms.Button
        Friend WithEvents btnCambiarClaveAdmin As System.Windows.Forms.Button
        Friend WithEvents btnConfigPuertos As System.Windows.Forms.Button
        Friend WithEvents btnParadaGeneral As System.Windows.Forms.Button
        Friend WithEvents splitPrincipal As System.Windows.Forms.SplitContainer
        Friend WithEvents grpMaquinaPrincipal As System.Windows.Forms.GroupBox
        Friend WithEvents lblEstadoMaquina As System.Windows.Forms.Label
        Friend WithEvents lblDisplayBolsas As System.Windows.Forms.Label
        Friend WithEvents btnResetContador As System.Windows.Forms.Button
        Friend WithEvents lblDisplayBPM As System.Windows.Forms.Label
        Friend WithEvents btnIniciarEnvasado As System.Windows.Forms.Button
        Friend WithEvents btnDetenerEnvasado As System.Windows.Forms.Button
        Friend WithEvents btnJogArrastre As System.Windows.Forms.Button
        Friend WithEvents btnCicloMordazas As System.Windows.Forms.Button
        Friend WithEvents btnProbarCorte As System.Windows.Forms.Button
        Friend WithEvents grpParametrosCiclo As System.Windows.Forms.GroupBox
        Friend WithEvents lblSelladoMs As System.Windows.Forms.Label
        Friend WithEvents numTiempoSellado As System.Windows.Forms.NumericUpDown
        Friend WithEvents lblArrastreMs As System.Windows.Forms.Label
        Friend WithEvents numTiempoArrastre As System.Windows.Forms.NumericUpDown
        Friend WithEvents chkUsarTaca As System.Windows.Forms.CheckBox
        Friend WithEvents btnAplicarParametrosMaquina As System.Windows.Forms.Button
        Friend WithEvents btnAjustesAvanzados As System.Windows.Forms.Button
        Friend WithEvents grpTemperaturas As System.Windows.Forms.GroupBox
        Friend WithEvents lblT1 As System.Windows.Forms.Label
        Friend WithEvents lblT2 As System.Windows.Forms.Label
        Friend WithEvents lblT3 As System.Windows.Forms.Label
        Friend WithEvents lblT4 As System.Windows.Forms.Label
        Friend WithEvents btnToggleCalefaccion As System.Windows.Forms.Button
        Friend WithEvents pnlTolvasHeader As System.Windows.Forms.Panel
        Friend WithEvents lblTituloTolvas As System.Windows.Forms.Label
        Friend WithEvents btnIniciarTodasTolvas As System.Windows.Forms.Button
        Friend WithEvents btnDetenerTodasTolvas As System.Windows.Forms.Button
        Friend WithEvents btnDescargarTodasTolvas As System.Windows.Forms.Button
        Friend WithEvents flpContenedorTolvas As System.Windows.Forms.FlowLayoutPanel
        Friend WithEvents statusStripPrincipal As System.Windows.Forms.StatusStrip
        Friend WithEvents statusLabelMensaje As System.Windows.Forms.ToolStripStatusLabel
        Friend WithEvents tmrRefrescoUI As System.Windows.Forms.Timer

        <System.Diagnostics.DebuggerStepThrough()>
        Private Sub InitializeComponent()
            Me.components = New System.ComponentModel.Container()
            Me.pnlHeader = New System.Windows.Forms.Panel()
            Me.lblTitulo = New System.Windows.Forms.Label()
            Me.lblSubtitulo = New System.Windows.Forms.Label()
            Me.lblModoUsuario = New System.Windows.Forms.Label()
            Me.btnModoAdmin = New System.Windows.Forms.Button()
            Me.btnCambiarClaveAdmin = New System.Windows.Forms.Button()
            Me.btnConfigPuertos = New System.Windows.Forms.Button()
            Me.btnParadaGeneral = New System.Windows.Forms.Button()
            Me.splitPrincipal = New System.Windows.Forms.SplitContainer()
            Me.grpMaquinaPrincipal = New System.Windows.Forms.GroupBox()
            Me.lblEstadoMaquina = New System.Windows.Forms.Label()
            Me.lblDisplayBolsas = New System.Windows.Forms.Label()
            Me.btnResetContador = New System.Windows.Forms.Button()
            Me.lblDisplayBPM = New System.Windows.Forms.Label()
            Me.btnIniciarEnvasado = New System.Windows.Forms.Button()
            Me.btnDetenerEnvasado = New System.Windows.Forms.Button()
            Me.btnJogArrastre = New System.Windows.Forms.Button()
            Me.btnCicloMordazas = New System.Windows.Forms.Button()
            Me.btnProbarCorte = New System.Windows.Forms.Button()
            Me.grpParametrosCiclo = New System.Windows.Forms.GroupBox()
            Me.lblSelladoMs = New System.Windows.Forms.Label()
            Me.numTiempoSellado = New System.Windows.Forms.NumericUpDown()
            Me.lblArrastreMs = New System.Windows.Forms.Label()
            Me.numTiempoArrastre = New System.Windows.Forms.NumericUpDown()
            Me.chkUsarTaca = New System.Windows.Forms.CheckBox()
            Me.btnAplicarParametrosMaquina = New System.Windows.Forms.Button()
            Me.btnAjustesAvanzados = New System.Windows.Forms.Button()
            Me.grpTemperaturas = New System.Windows.Forms.GroupBox()
            Me.lblT1 = New System.Windows.Forms.Label()
            Me.lblT2 = New System.Windows.Forms.Label()
            Me.lblT3 = New System.Windows.Forms.Label()
            Me.lblT4 = New System.Windows.Forms.Label()
            Me.btnToggleCalefaccion = New System.Windows.Forms.Button()
            Me.pnlTolvasHeader = New System.Windows.Forms.Panel()
            Me.lblTituloTolvas = New System.Windows.Forms.Label()
            Me.btnIniciarTodasTolvas = New System.Windows.Forms.Button()
            Me.btnDetenerTodasTolvas = New System.Windows.Forms.Button()
            Me.btnDescargarTodasTolvas = New System.Windows.Forms.Button()
            Me.flpContenedorTolvas = New System.Windows.Forms.FlowLayoutPanel()
            Me.statusStripPrincipal = New System.Windows.Forms.StatusStrip()
            Me.statusLabelMensaje = New System.Windows.Forms.ToolStripStatusLabel()
            Me.tmrRefrescoUI = New System.Windows.Forms.Timer(Me.components)
            Me.pnlHeader.SuspendLayout()
            CType(Me.splitPrincipal, System.ComponentModel.ISupportInitialize).BeginInit()
            Me.splitPrincipal.Panel1.SuspendLayout()
            Me.splitPrincipal.Panel2.SuspendLayout()
            Me.splitPrincipal.SuspendLayout()
            Me.grpMaquinaPrincipal.SuspendLayout()
            Me.grpParametrosCiclo.SuspendLayout()
            CType(Me.numTiempoSellado, System.ComponentModel.ISupportInitialize).BeginInit()
            CType(Me.numTiempoArrastre, System.ComponentModel.ISupportInitialize).BeginInit()
            Me.grpTemperaturas.SuspendLayout()
            Me.pnlTolvasHeader.SuspendLayout()
            Me.statusStripPrincipal.SuspendLayout()
            Me.SuspendLayout()
            '
            'pnlHeader
            '
            Me.pnlHeader.BackColor = System.Drawing.Color.FromArgb(CType(CType(24, Byte), Integer), CType(CType(32, Byte), Integer), CType(CType(44, Byte), Integer))
            Me.pnlHeader.Controls.Add(Me.btnParadaGeneral)
            Me.pnlHeader.Controls.Add(Me.btnConfigPuertos)
            Me.pnlHeader.Controls.Add(Me.btnCambiarClaveAdmin)
            Me.pnlHeader.Controls.Add(Me.btnModoAdmin)
            Me.pnlHeader.Controls.Add(Me.lblModoUsuario)
            Me.pnlHeader.Controls.Add(Me.lblSubtitulo)
            Me.pnlHeader.Controls.Add(Me.lblTitulo)
            Me.pnlHeader.Dock = System.Windows.Forms.DockStyle.Top
            Me.pnlHeader.Location = New System.Drawing.Point(0, 0)
            Me.pnlHeader.Name = "pnlHeader"
            Me.pnlHeader.Size = New System.Drawing.Size(1200, 70)
            Me.pnlHeader.TabIndex = 0
            '
            'lblTitulo
            '
            Me.lblTitulo.AutoSize = True
            Me.lblTitulo.Font = New System.Drawing.Font("Segoe UI", 13.0!, System.Drawing.FontStyle.Bold)
            Me.lblTitulo.ForeColor = System.Drawing.Color.White
            Me.lblTitulo.Location = New System.Drawing.Point(12, 10)
            Me.lblTitulo.Name = "lblTitulo"
            Me.lblTitulo.Size = New System.Drawing.Size(515, 25)
            Me.lblTitulo.TabIndex = 0
            Me.lblTitulo.Text = "SISTEMA INTEGRAL DE ENVASADO Y MULTI-DOSIFICACIÓN"
            '
            'lblSubtitulo
            '
            Me.lblSubtitulo.AutoSize = True
            Me.lblSubtitulo.Font = New System.Drawing.Font("Segoe UI", 9.0!)
            Me.lblSubtitulo.ForeColor = System.Drawing.Color.LightGray
            Me.lblSubtitulo.Location = New System.Drawing.Point(14, 38)
            Me.lblSubtitulo.Name = "lblSubtitulo"
            Me.lblSubtitulo.Size = New System.Drawing.Size(378, 15)
            Me.lblSubtitulo.TabIndex = 1
            Me.lblSubtitulo.Text = "Controlador Central NS-GH + Tolvas Balanza DV-1000 con Carga y Tara"
            '
            'lblModoUsuario
            '
            Me.lblModoUsuario.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
            Me.lblModoUsuario.BackColor = System.Drawing.Color.SteelBlue
            Me.lblModoUsuario.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.lblModoUsuario.ForeColor = System.Drawing.Color.White
            Me.lblModoUsuario.Location = New System.Drawing.Point(540, 18)
            Me.lblModoUsuario.Name = "lblModoUsuario"
            Me.lblModoUsuario.Size = New System.Drawing.Size(130, 34)
            Me.lblModoUsuario.TabIndex = 2
            Me.lblModoUsuario.Text = "MODO: OPERADOR"
            Me.lblModoUsuario.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
            '
            'btnModoAdmin
            '
            Me.btnModoAdmin.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
            Me.btnModoAdmin.BackColor = System.Drawing.Color.Orange
            Me.btnModoAdmin.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnModoAdmin.Font = New System.Drawing.Font("Segoe UI", 8.5!, System.Drawing.FontStyle.Bold)
            Me.btnModoAdmin.ForeColor = System.Drawing.Color.Black
            Me.btnModoAdmin.Location = New System.Drawing.Point(678, 18)
            Me.btnModoAdmin.Name = "btnModoAdmin"
            Me.btnModoAdmin.Size = New System.Drawing.Size(110, 34)
            Me.btnModoAdmin.TabIndex = 3
            Me.btnModoAdmin.Text = "Modo Admin"
            Me.btnModoAdmin.UseVisualStyleBackColor = False
            '
            'btnCambiarClaveAdmin
            '
            Me.btnCambiarClaveAdmin.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
            Me.btnCambiarClaveAdmin.BackColor = System.Drawing.Color.Goldenrod
            Me.btnCambiarClaveAdmin.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnCambiarClaveAdmin.Font = New System.Drawing.Font("Segoe UI", 8.0!, System.Drawing.FontStyle.Bold)
            Me.btnCambiarClaveAdmin.ForeColor = System.Drawing.Color.White
            Me.btnCambiarClaveAdmin.Location = New System.Drawing.Point(796, 18)
            Me.btnCambiarClaveAdmin.Name = "btnCambiarClaveAdmin"
            Me.btnCambiarClaveAdmin.Size = New System.Drawing.Size(110, 34)
            Me.btnCambiarClaveAdmin.TabIndex = 4
            Me.btnCambiarClaveAdmin.Text = "Cambiar Clave"
            Me.btnCambiarClaveAdmin.UseVisualStyleBackColor = False
            Me.btnCambiarClaveAdmin.Visible = False
            '
            'btnConfigPuertos
            '
            Me.btnConfigPuertos.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
            Me.btnConfigPuertos.BackColor = System.Drawing.Color.Teal
            Me.btnConfigPuertos.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnConfigPuertos.Font = New System.Drawing.Font("Segoe UI", 8.5!, System.Drawing.FontStyle.Bold)
            Me.btnConfigPuertos.ForeColor = System.Drawing.Color.White
            Me.btnConfigPuertos.Location = New System.Drawing.Point(914, 18)
            Me.btnConfigPuertos.Name = "btnConfigPuertos"
            Me.btnConfigPuertos.Size = New System.Drawing.Size(110, 34)
            Me.btnConfigPuertos.TabIndex = 5
            Me.btnConfigPuertos.Text = "Puertos USB"
            Me.btnConfigPuertos.UseVisualStyleBackColor = False
            '
            'btnParadaGeneral
            '
            Me.btnParadaGeneral.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
            Me.btnParadaGeneral.BackColor = System.Drawing.Color.Crimson
            Me.btnParadaGeneral.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnParadaGeneral.Font = New System.Drawing.Font("Segoe UI", 10.0!, System.Drawing.FontStyle.Bold)
            Me.btnParadaGeneral.ForeColor = System.Drawing.Color.White
            Me.btnParadaGeneral.Location = New System.Drawing.Point(1032, 12)
            Me.btnParadaGeneral.Name = "btnParadaGeneral"
            Me.btnParadaGeneral.Size = New System.Drawing.Size(156, 46)
            Me.btnParadaGeneral.TabIndex = 6
            Me.btnParadaGeneral.Text = "PARADA GENERAL"
            Me.btnParadaGeneral.UseVisualStyleBackColor = False
            '
            'splitPrincipal
            '
            Me.splitPrincipal.Dock = System.Windows.Forms.DockStyle.Fill
            Me.splitPrincipal.FixedPanel = System.Windows.Forms.FixedPanel.Panel1
            Me.splitPrincipal.Location = New System.Drawing.Point(0, 70)
            Me.splitPrincipal.Name = "splitPrincipal"
            '
            'splitPrincipal.Panel1
            '
            Me.splitPrincipal.Panel1.AutoScroll = True
            Me.splitPrincipal.Panel1.Controls.Add(Me.grpTemperaturas)
            Me.splitPrincipal.Panel1.Controls.Add(Me.grpParametrosCiclo)
            Me.splitPrincipal.Panel1.Controls.Add(Me.grpMaquinaPrincipal)
            Me.splitPrincipal.Panel1.Padding = New System.Windows.Forms.Padding(10)
            '
            'splitPrincipal.Panel2
            '
            Me.splitPrincipal.Panel2.Controls.Add(Me.flpContenedorTolvas)
            Me.splitPrincipal.Panel2.Controls.Add(Me.pnlTolvasHeader)
            Me.splitPrincipal.Panel2.Padding = New System.Windows.Forms.Padding(10)
            Me.splitPrincipal.Size = New System.Drawing.Size(1200, 622)
            Me.splitPrincipal.SplitterDistance = 460
            Me.splitPrincipal.TabIndex = 1
            '
            'grpMaquinaPrincipal
            '
            Me.grpMaquinaPrincipal.Controls.Add(Me.btnResetContador)
            Me.grpMaquinaPrincipal.Controls.Add(Me.btnProbarCorte)
            Me.grpMaquinaPrincipal.Controls.Add(Me.btnCicloMordazas)
            Me.grpMaquinaPrincipal.Controls.Add(Me.btnJogArrastre)
            Me.grpMaquinaPrincipal.Controls.Add(Me.btnDetenerEnvasado)
            Me.grpMaquinaPrincipal.Controls.Add(Me.btnIniciarEnvasado)
            Me.grpMaquinaPrincipal.Controls.Add(Me.lblDisplayBPM)
            Me.grpMaquinaPrincipal.Controls.Add(Me.lblDisplayBolsas)
            Me.grpMaquinaPrincipal.Controls.Add(Me.lblEstadoMaquina)
            Me.grpMaquinaPrincipal.Dock = System.Windows.Forms.DockStyle.Top
            Me.grpMaquinaPrincipal.Font = New System.Drawing.Font("Segoe UI", 9.5!, System.Drawing.FontStyle.Bold)
            Me.grpMaquinaPrincipal.Location = New System.Drawing.Point(10, 10)
            Me.grpMaquinaPrincipal.Name = "grpMaquinaPrincipal"
            Me.grpMaquinaPrincipal.Size = New System.Drawing.Size(440, 240)
            Me.grpMaquinaPrincipal.TabIndex = 0
            Me.grpMaquinaPrincipal.TabStop = False
            Me.grpMaquinaPrincipal.Text = "Control Máquina Principal (NS-GH)"
            '
            'lblEstadoMaquina
            '
            Me.lblEstadoMaquina.BackColor = System.Drawing.Color.DimGray
            Me.lblEstadoMaquina.Font = New System.Drawing.Font("Segoe UI", 10.0!, System.Drawing.FontStyle.Bold)
            Me.lblEstadoMaquina.ForeColor = System.Drawing.Color.White
            Me.lblEstadoMaquina.Location = New System.Drawing.Point(15, 25)
            Me.lblEstadoMaquina.Name = "lblEstadoMaquina"
            Me.lblEstadoMaquina.Size = New System.Drawing.Size(410, 28)
            Me.lblEstadoMaquina.TabIndex = 0
            Me.lblEstadoMaquina.Text = "ESTADO: EN ESPERA"
            Me.lblEstadoMaquina.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
            '
            'lblDisplayBolsas
            '
            Me.lblDisplayBolsas.BackColor = System.Drawing.Color.Black
            Me.lblDisplayBolsas.Font = New System.Drawing.Font("Consolas", 17.0!, System.Drawing.FontStyle.Bold)
            Me.lblDisplayBolsas.ForeColor = System.Drawing.Color.Cyan
            Me.lblDisplayBolsas.Location = New System.Drawing.Point(15, 60)
            Me.lblDisplayBolsas.Name = "lblDisplayBolsas"
            Me.lblDisplayBolsas.Size = New System.Drawing.Size(140, 42)
            Me.lblDisplayBolsas.TabIndex = 1
            Me.lblDisplayBolsas.Text = "Bolsas: 0"
            Me.lblDisplayBolsas.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
            '
            'btnResetContador
            '
            Me.btnResetContador.BackColor = System.Drawing.Color.DimGray
            Me.btnResetContador.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnResetContador.Font = New System.Drawing.Font("Segoe UI", 7.5!, System.Drawing.FontStyle.Bold)
            Me.btnResetContador.ForeColor = System.Drawing.Color.White
            Me.btnResetContador.Location = New System.Drawing.Point(160, 60)
            Me.btnResetContador.Name = "btnResetContador"
            Me.btnResetContador.Size = New System.Drawing.Size(50, 42)
            Me.btnResetContador.TabIndex = 2
            Me.btnResetContador.Text = "Reset"
            Me.btnResetContador.UseVisualStyleBackColor = False
            '
            'lblDisplayBPM
            '
            Me.lblDisplayBPM.BackColor = System.Drawing.Color.Black
            Me.lblDisplayBPM.Font = New System.Drawing.Font("Consolas", 17.0!, System.Drawing.FontStyle.Bold)
            Me.lblDisplayBPM.ForeColor = System.Drawing.Color.Yellow
            Me.lblDisplayBPM.Location = New System.Drawing.Point(220, 60)
            Me.lblDisplayBPM.Name = "lblDisplayBPM"
            Me.lblDisplayBPM.Size = New System.Drawing.Size(205, 42)
            Me.lblDisplayBPM.TabIndex = 3
            Me.lblDisplayBPM.Text = "0.0 BPM"
            Me.lblDisplayBPM.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
            '
            'btnIniciarEnvasado
            '
            Me.btnIniciarEnvasado.BackColor = System.Drawing.Color.ForestGreen
            Me.btnIniciarEnvasado.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnIniciarEnvasado.Font = New System.Drawing.Font("Segoe UI", 10.0!, System.Drawing.FontStyle.Bold)
            Me.btnIniciarEnvasado.ForeColor = System.Drawing.Color.White
            Me.btnIniciarEnvasado.Location = New System.Drawing.Point(15, 112)
            Me.btnIniciarEnvasado.Name = "btnIniciarEnvasado"
            Me.btnIniciarEnvasado.Size = New System.Drawing.Size(195, 40)
            Me.btnIniciarEnvasado.TabIndex = 4
            Me.btnIniciarEnvasado.Text = "INICIAR ENVASADO"
            Me.btnIniciarEnvasado.UseVisualStyleBackColor = False
            '
            'btnDetenerEnvasado
            '
            Me.btnDetenerEnvasado.BackColor = System.Drawing.Color.Firebrick
            Me.btnDetenerEnvasado.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnDetenerEnvasado.Font = New System.Drawing.Font("Segoe UI", 10.0!, System.Drawing.FontStyle.Bold)
            Me.btnDetenerEnvasado.ForeColor = System.Drawing.Color.White
            Me.btnDetenerEnvasado.Location = New System.Drawing.Point(230, 112)
            Me.btnDetenerEnvasado.Name = "btnDetenerEnvasado"
            Me.btnDetenerEnvasado.Size = New System.Drawing.Size(195, 40)
            Me.btnDetenerEnvasado.TabIndex = 5
            Me.btnDetenerEnvasado.Text = "DETENER ENVASADO"
            Me.btnDetenerEnvasado.UseVisualStyleBackColor = False
            '
            'btnJogArrastre
            '
            Me.btnJogArrastre.BackColor = System.Drawing.Color.SlateGray
            Me.btnJogArrastre.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnJogArrastre.Font = New System.Drawing.Font("Segoe UI", 8.5!, System.Drawing.FontStyle.Bold)
            Me.btnJogArrastre.ForeColor = System.Drawing.Color.White
            Me.btnJogArrastre.Location = New System.Drawing.Point(15, 162)
            Me.btnJogArrastre.Name = "btnJogArrastre"
            Me.btnJogArrastre.Size = New System.Drawing.Size(130, 34)
            Me.btnJogArrastre.TabIndex = 6
            Me.btnJogArrastre.Text = "Arrastre (JOG)"
            Me.btnJogArrastre.UseVisualStyleBackColor = False
            '
            'btnCicloMordazas
            '
            Me.btnCicloMordazas.BackColor = System.Drawing.Color.SlateGray
            Me.btnCicloMordazas.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnCicloMordazas.Font = New System.Drawing.Font("Segoe UI", 8.5!, System.Drawing.FontStyle.Bold)
            Me.btnCicloMordazas.ForeColor = System.Drawing.Color.White
            Me.btnCicloMordazas.Location = New System.Drawing.Point(155, 162)
            Me.btnCicloMordazas.Name = "btnCicloMordazas"
            Me.btnCicloMordazas.Size = New System.Drawing.Size(130, 34)
            Me.btnCicloMordazas.TabIndex = 7
            Me.btnCicloMordazas.Text = "Ciclo Mordazas"
            Me.btnCicloMordazas.UseVisualStyleBackColor = False
            '
            'btnProbarCorte
            '
            Me.btnProbarCorte.BackColor = System.Drawing.Color.SlateGray
            Me.btnProbarCorte.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnProbarCorte.Font = New System.Drawing.Font("Segoe UI", 8.5!, System.Drawing.FontStyle.Bold)
            Me.btnProbarCorte.ForeColor = System.Drawing.Color.White
            Me.btnProbarCorte.Location = New System.Drawing.Point(295, 162)
            Me.btnProbarCorte.Name = "btnProbarCorte"
            Me.btnProbarCorte.Size = New System.Drawing.Size(130, 34)
            Me.btnProbarCorte.TabIndex = 8
            Me.btnProbarCorte.Text = "Probar Corte"
            Me.btnProbarCorte.UseVisualStyleBackColor = False
            '
            'grpParametrosCiclo
            '
            Me.grpParametrosCiclo.Controls.Add(Me.btnAjustesAvanzados)
            Me.grpParametrosCiclo.Controls.Add(Me.btnAplicarParametrosMaquina)
            Me.grpParametrosCiclo.Controls.Add(Me.chkUsarTaca)
            Me.grpParametrosCiclo.Controls.Add(Me.numTiempoArrastre)
            Me.grpParametrosCiclo.Controls.Add(Me.lblArrastreMs)
            Me.grpParametrosCiclo.Controls.Add(Me.numTiempoSellado)
            Me.grpParametrosCiclo.Controls.Add(Me.lblSelladoMs)
            Me.grpParametrosCiclo.Dock = System.Windows.Forms.DockStyle.Top
            Me.grpParametrosCiclo.Font = New System.Drawing.Font("Segoe UI", 9.5!, System.Drawing.FontStyle.Bold)
            Me.grpParametrosCiclo.Location = New System.Drawing.Point(10, 250)
            Me.grpParametrosCiclo.Name = "grpParametrosCiclo"
            Me.grpParametrosCiclo.Size = New System.Drawing.Size(440, 140)
            Me.grpParametrosCiclo.TabIndex = 1
            Me.grpParametrosCiclo.TabStop = False
            Me.grpParametrosCiclo.Text = "Parámetros Rápidos de Ciclo"
            '
            'lblSelladoMs
            '
            Me.lblSelladoMs.AutoSize = True
            Me.lblSelladoMs.Font = New System.Drawing.Font("Segoe UI", 8.5!)
            Me.lblSelladoMs.Location = New System.Drawing.Point(15, 30)
            Me.lblSelladoMs.Name = "lblSelladoMs"
            Me.lblSelladoMs.Size = New System.Drawing.Size(122, 15)
            Me.lblSelladoMs.TabIndex = 0
            Me.lblSelladoMs.Text = "Tiempo Sellado (ms):"
            '
            'numTiempoSellado
            '
            Me.numTiempoSellado.Location = New System.Drawing.Point(145, 27)
            Me.numTiempoSellado.Maximum = New Decimal(New Integer() {9000, 0, 0, 0})
            Me.numTiempoSellado.Minimum = New Decimal(New Integer() {100, 0, 0, 0})
            Me.numTiempoSellado.Name = "numTiempoSellado"
            Me.numTiempoSellado.Size = New System.Drawing.Size(80, 24)
            Me.numTiempoSellado.TabIndex = 1
            Me.numTiempoSellado.Value = New Decimal(New Integer() {1000, 0, 0, 0})
            '
            'lblArrastreMs
            '
            Me.lblArrastreMs.AutoSize = True
            Me.lblArrastreMs.Font = New System.Drawing.Font("Segoe UI", 8.5!)
            Me.lblArrastreMs.Location = New System.Drawing.Point(15, 62)
            Me.lblArrastreMs.Name = "lblArrastreMs"
            Me.lblArrastreMs.Size = New System.Drawing.Size(125, 15)
            Me.lblArrastreMs.TabIndex = 2
            Me.lblArrastreMs.Text = "Tiempo Arrastre (ms):"
            '
            'numTiempoArrastre
            '
            Me.numTiempoArrastre.Location = New System.Drawing.Point(145, 59)
            Me.numTiempoArrastre.Maximum = New Decimal(New Integer() {9000, 0, 0, 0})
            Me.numTiempoArrastre.Minimum = New Decimal(New Integer() {50, 0, 0, 0})
            Me.numTiempoArrastre.Name = "numTiempoArrastre"
            Me.numTiempoArrastre.Size = New System.Drawing.Size(80, 24)
            Me.numTiempoArrastre.TabIndex = 3
            Me.numTiempoArrastre.Value = New Decimal(New Integer() {400, 0, 0, 0})
            '
            'chkUsarTaca
            '
            Me.chkUsarTaca.AutoSize = True
            Me.chkUsarTaca.Font = New System.Drawing.Font("Segoe UI", 8.5!)
            Me.chkUsarTaca.Location = New System.Drawing.Point(18, 98)
            Me.chkUsarTaca.Name = "chkUsarTaca"
            Me.chkUsarTaca.Size = New System.Drawing.Size(209, 19)
            Me.chkUsarTaca.TabIndex = 4
            Me.chkUsarTaca.Text = "Usar Sensor de Taca (Fotomarca)"
            Me.chkUsarTaca.UseVisualStyleBackColor = True
            '
            'btnAplicarParametrosMaquina
            '
            Me.btnAplicarParametrosMaquina.BackColor = System.Drawing.Color.LightSteelBlue
            Me.btnAplicarParametrosMaquina.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnAplicarParametrosMaquina.Font = New System.Drawing.Font("Segoe UI", 8.5!, System.Drawing.FontStyle.Bold)
            Me.btnAplicarParametrosMaquina.Location = New System.Drawing.Point(240, 25)
            Me.btnAplicarParametrosMaquina.Name = "btnAplicarParametrosMaquina"
            Me.btnAplicarParametrosMaquina.Size = New System.Drawing.Size(185, 35)
            Me.btnAplicarParametrosMaquina.TabIndex = 5
            Me.btnAplicarParametrosMaquina.Text = "Aplicar Rápidos"
            Me.btnAplicarParametrosMaquina.UseVisualStyleBackColor = False
            '
            'btnAjustesAvanzados
            '
            Me.btnAjustesAvanzados.BackColor = System.Drawing.Color.CadetBlue
            Me.btnAjustesAvanzados.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnAjustesAvanzados.Font = New System.Drawing.Font("Segoe UI", 8.5!, System.Drawing.FontStyle.Bold)
            Me.btnAjustesAvanzados.ForeColor = System.Drawing.Color.White
            Me.btnAjustesAvanzados.Location = New System.Drawing.Point(240, 68)
            Me.btnAjustesAvanzados.Name = "btnAjustesAvanzados"
            Me.btnAjustesAvanzados.Size = New System.Drawing.Size(185, 49)
            Me.btnAjustesAvanzados.TabIndex = 6
            Me.btnAjustesAvanzados.Text = "⚙ Ajustes Avanzados NS-GH (Tiempos / Modos / SetPoints)"
            Me.btnAjustesAvanzados.UseVisualStyleBackColor = False
            '
            'grpTemperaturas
            '
            Me.grpTemperaturas.Controls.Add(Me.btnToggleCalefaccion)
            Me.grpTemperaturas.Controls.Add(Me.lblT4)
            Me.grpTemperaturas.Controls.Add(Me.lblT3)
            Me.grpTemperaturas.Controls.Add(Me.lblT2)
            Me.grpTemperaturas.Controls.Add(Me.lblT1)
            Me.grpTemperaturas.Dock = System.Windows.Forms.DockStyle.Top
            Me.grpTemperaturas.Font = New System.Drawing.Font("Segoe UI", 9.5!, System.Drawing.FontStyle.Bold)
            Me.grpTemperaturas.Location = New System.Drawing.Point(10, 390)
            Me.grpTemperaturas.Name = "grpTemperaturas"
            Me.grpTemperaturas.Size = New System.Drawing.Size(440, 160)
            Me.grpTemperaturas.TabIndex = 2
            Me.grpTemperaturas.TabStop = False
            Me.grpTemperaturas.Text = "Pirómetros de Temperatura Modbus (°C)"
            '
            'lblT1
            '
            Me.lblT1.BackColor = System.Drawing.Color.FromArgb(CType(CType(240, Byte), Integer), CType(CType(240, Byte), Integer), CType(CType(240, Byte), Integer))
            Me.lblT1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
            Me.lblT1.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.lblT1.Location = New System.Drawing.Point(15, 28)
            Me.lblT1.Name = "lblT1"
            Me.lblT1.Size = New System.Drawing.Size(195, 30)
            Me.lblT1.TabIndex = 0
            Me.lblT1.Text = "Sup. Izq: 0 °C (Set: 150)"
            Me.lblT1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
            '
            'lblT2
            '
            Me.lblT2.BackColor = System.Drawing.Color.FromArgb(CType(CType(240, Byte), Integer), CType(CType(240, Byte), Integer), CType(CType(240, Byte), Integer))
            Me.lblT2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
            Me.lblT2.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.lblT2.Location = New System.Drawing.Point(225, 28)
            Me.lblT2.Name = "lblT2"
            Me.lblT2.Size = New System.Drawing.Size(200, 30)
            Me.lblT2.TabIndex = 1
            Me.lblT2.Text = "Sup. Der: 0 °C (Set: 150)"
            Me.lblT2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
            '
            'lblT3
            '
            Me.lblT3.BackColor = System.Drawing.Color.FromArgb(CType(CType(240, Byte), Integer), CType(CType(240, Byte), Integer), CType(CType(240, Byte), Integer))
            Me.lblT3.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
            Me.lblT3.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.lblT3.Location = New System.Drawing.Point(15, 68)
            Me.lblT3.Name = "lblT3"
            Me.lblT3.Size = New System.Drawing.Size(195, 30)
            Me.lblT3.TabIndex = 2
            Me.lblT3.Text = "Inf. Ext: 0 °C (Set: 150)"
            Me.lblT3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
            '
            'lblT4
            '
            Me.lblT4.BackColor = System.Drawing.Color.FromArgb(CType(CType(240, Byte), Integer), CType(CType(240, Byte), Integer), CType(CType(240, Byte), Integer))
            Me.lblT4.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
            Me.lblT4.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.lblT4.Location = New System.Drawing.Point(225, 68)
            Me.lblT4.Name = "lblT4"
            Me.lblT4.Size = New System.Drawing.Size(200, 30)
            Me.lblT4.TabIndex = 3
            Me.lblT4.Text = "Inf. Int: 0 °C (Set: 150)"
            Me.lblT4.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
            '
            'btnToggleCalefaccion
            '
            Me.btnToggleCalefaccion.BackColor = System.Drawing.Color.DarkOrange
            Me.btnToggleCalefaccion.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnToggleCalefaccion.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Bold)
            Me.btnToggleCalefaccion.ForeColor = System.Drawing.Color.White
            Me.btnToggleCalefaccion.Location = New System.Drawing.Point(15, 110)
            Me.btnToggleCalefaccion.Name = "btnToggleCalefaccion"
            Me.btnToggleCalefaccion.Size = New System.Drawing.Size(410, 34)
            Me.btnToggleCalefaccion.TabIndex = 4
            Me.btnToggleCalefaccion.Text = "ACTIVAR CALEFACCIÓN DE MORDAZAS"
            Me.btnToggleCalefaccion.UseVisualStyleBackColor = False
            '
            'pnlTolvasHeader
            '
            Me.pnlTolvasHeader.BackColor = System.Drawing.Color.WhiteSmoke
            Me.pnlTolvasHeader.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
            Me.pnlTolvasHeader.Controls.Add(Me.btnDescargarTodasTolvas)
            Me.pnlTolvasHeader.Controls.Add(Me.btnDetenerTodasTolvas)
            Me.pnlTolvasHeader.Controls.Add(Me.btnIniciarTodasTolvas)
            Me.pnlTolvasHeader.Controls.Add(Me.lblTituloTolvas)
            Me.pnlTolvasHeader.Dock = System.Windows.Forms.DockStyle.Top
            Me.pnlTolvasHeader.Location = New System.Drawing.Point(10, 10)
            Me.pnlTolvasHeader.Name = "pnlTolvasHeader"
            Me.pnlTolvasHeader.Size = New System.Drawing.Size(716, 48)
            Me.pnlTolvasHeader.TabIndex = 0
            '
            'lblTituloTolvas
            '
            Me.lblTituloTolvas.AutoSize = True
            Me.lblTituloTolvas.Font = New System.Drawing.Font("Segoe UI", 11.0!, System.Drawing.FontStyle.Bold)
            Me.lblTituloTolvas.Location = New System.Drawing.Point(10, 12)
            Me.lblTituloTolvas.Name = "lblTituloTolvas"
            Me.lblTituloTolvas.Size = New System.Drawing.Size(262, 20)
            Me.lblTituloTolvas.TabIndex = 0
            Me.lblTituloTolvas.Text = "TOLVAS DOSIFICADORAS (DV-1000)"
            '
            'btnIniciarTodasTolvas
            '
            Me.btnIniciarTodasTolvas.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
            Me.btnIniciarTodasTolvas.BackColor = System.Drawing.Color.ForestGreen
            Me.btnIniciarTodasTolvas.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnIniciarTodasTolvas.Font = New System.Drawing.Font("Segoe UI", 8.0!, System.Drawing.FontStyle.Bold)
            Me.btnIniciarTodasTolvas.ForeColor = System.Drawing.Color.White
            Me.btnIniciarTodasTolvas.Location = New System.Drawing.Point(346, 8)
            Me.btnIniciarTodasTolvas.Name = "btnIniciarTodasTolvas"
            Me.btnIniciarTodasTolvas.Size = New System.Drawing.Size(115, 30)
            Me.btnIniciarTodasTolvas.TabIndex = 1
            Me.btnIniciarTodasTolvas.Text = "Iniciar Todas"
            Me.btnIniciarTodasTolvas.UseVisualStyleBackColor = False
            '
            'btnDetenerTodasTolvas
            '
            Me.btnDetenerTodasTolvas.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
            Me.btnDetenerTodasTolvas.BackColor = System.Drawing.Color.Firebrick
            Me.btnDetenerTodasTolvas.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnDetenerTodasTolvas.Font = New System.Drawing.Font("Segoe UI", 8.0!, System.Drawing.FontStyle.Bold)
            Me.btnDetenerTodasTolvas.ForeColor = System.Drawing.Color.White
            Me.btnDetenerTodasTolvas.Location = New System.Drawing.Point(469, 8)
            Me.btnDetenerTodasTolvas.Name = "btnDetenerTodasTolvas"
            Me.btnDetenerTodasTolvas.Size = New System.Drawing.Size(115, 30)
            Me.btnDetenerTodasTolvas.TabIndex = 2
            Me.btnDetenerTodasTolvas.Text = "Detener Todas"
            Me.btnDetenerTodasTolvas.UseVisualStyleBackColor = False
            '
            'btnDescargarTodasTolvas
            '
            Me.btnDescargarTodasTolvas.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
            Me.btnDescargarTodasTolvas.BackColor = System.Drawing.Color.DarkOrange
            Me.btnDescargarTodasTolvas.FlatStyle = System.Windows.Forms.FlatStyle.Flat
            Me.btnDescargarTodasTolvas.Font = New System.Drawing.Font("Segoe UI", 8.0!, System.Drawing.FontStyle.Bold)
            Me.btnDescargarTodasTolvas.ForeColor = System.Drawing.Color.White
            Me.btnDescargarTodasTolvas.Location = New System.Drawing.Point(592, 8)
            Me.btnDescargarTodasTolvas.Name = "btnDescargarTodasTolvas"
            Me.btnDescargarTodasTolvas.Size = New System.Drawing.Size(115, 30)
            Me.btnDescargarTodasTolvas.TabIndex = 3
            Me.btnDescargarTodasTolvas.Text = "Descargar Todas"
            Me.btnDescargarTodasTolvas.UseVisualStyleBackColor = False
            '
            'flpContenedorTolvas
            '
            Me.flpContenedorTolvas.AutoScroll = True
            Me.flpContenedorTolvas.BackColor = System.Drawing.Color.FromArgb(CType(CType(245, Byte), Integer), CType(CType(247, Byte), Integer), CType(CType(250, Byte), Integer))
            Me.flpContenedorTolvas.Dock = System.Windows.Forms.DockStyle.Fill
            Me.flpContenedorTolvas.Location = New System.Drawing.Point(10, 58)
            Me.flpContenedorTolvas.Name = "flpContenedorTolvas"
            Me.flpContenedorTolvas.Padding = New System.Windows.Forms.Padding(5)
            Me.flpContenedorTolvas.Size = New System.Drawing.Size(716, 554)
            Me.flpContenedorTolvas.TabIndex = 1
            '
            'statusStripPrincipal
            '
            Me.statusStripPrincipal.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.statusLabelMensaje})
            Me.statusStripPrincipal.Location = New System.Drawing.Point(0, 692)
            Me.statusStripPrincipal.Name = "statusStripPrincipal"
            Me.statusStripPrincipal.Size = New System.Drawing.Size(1200, 22)
            Me.statusStripPrincipal.TabIndex = 2
            Me.statusStripPrincipal.Text = "StatusStrip"
            '
            'statusLabelMensaje
            '
            Me.statusLabelMensaje.Name = "statusLabelMensaje"
            Me.statusLabelMensaje.Size = New System.Drawing.Size(161, 17)
            Me.statusLabelMensaje.Text = "Sistema listo para producción."
            '
            'tmrRefrescoUI
            '
            Me.tmrRefrescoUI.Enabled = True
            Me.tmrRefrescoUI.Interval = 300
            '
            'FormPrincipal
            '
            Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
            Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
            Me.ClientSize = New System.Drawing.Size(1200, 714)
            Me.Controls.Add(Me.splitPrincipal)
            Me.Controls.Add(Me.pnlHeader)
            Me.Controls.Add(Me.statusStripPrincipal)
            Me.Font = New System.Drawing.Font("Segoe UI", 8.25!)
            Me.MinimumSize = New System.Drawing.Size(1000, 650)
            Me.Name = "FormPrincipal"
            Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
            Me.Text = "JACS MÁQUINAS - Control de Envasado y Multi-Dosificación"
            Me.pnlHeader.ResumeLayout(False)
            Me.pnlHeader.PerformLayout()
            Me.splitPrincipal.Panel1.ResumeLayout(False)
            Me.splitPrincipal.Panel2.ResumeLayout(False)
            CType(Me.splitPrincipal, System.ComponentModel.ISupportInitialize).EndInit()
            Me.splitPrincipal.ResumeLayout(False)
            Me.grpMaquinaPrincipal.ResumeLayout(False)
            Me.grpParametrosCiclo.ResumeLayout(False)
            Me.grpParametrosCiclo.PerformLayout()
            CType(Me.numTiempoSellado, System.ComponentModel.ISupportInitialize).EndInit()
            CType(Me.numTiempoArrastre, System.ComponentModel.ISupportInitialize).EndInit()
            Me.grpTemperaturas.ResumeLayout(False)
            Me.pnlTolvasHeader.ResumeLayout(False)
            Me.pnlTolvasHeader.PerformLayout()
            Me.statusStripPrincipal.ResumeLayout(False)
            Me.statusStripPrincipal.PerformLayout()
            Me.ResumeLayout(False)
            Me.PerformLayout()

        End Sub
    End Class
End Namespace
