Imports System
Imports System.Windows.Forms
Imports Clases

Namespace Formularios
    Public Class FormAjustesAvanzadosMaquina
        Private Sub FormAjustesAvanzadosMaquina_Load(sender As Object, e As EventArgs) Handles MyBase.Load
            CargarValoresActuales()
        End Sub

        Private Sub CargarValoresActuales()
            Dim m = GestorComunicaciones.Instancia.MaquinaPrincipal

            numSellado.Value = CDec(Math.Max(100, Math.Min(9000, m.TiempoSelladoMs)))
            numArrastre.Value = CDec(Math.Max(50, Math.Min(9000, m.TiempoArrastreMs)))
            numMorCierra.Value = CDec(Math.Max(50, Math.Min(5000, m.TiempoMordazaCierraMs)))
            numMorAbre.Value = CDec(Math.Max(50, Math.Min(5000, m.TiempoMordazaAbreMs)))

            chkFcMordaza.Checked = m.UsarFCMordaza
            chkSensorTaca.Checked = m.UsarSensorTaca

            If m.SecuenciaOperacion >= 0 AndAlso m.SecuenciaOperacion < cboSecuencia.Items.Count Then
                cboSecuencia.SelectedIndex = m.SecuenciaOperacion
            Else
                cboSecuencia.SelectedIndex = 0
            End If

            If m.TipoMaquina >= 0 AndAlso m.TipoMaquina < cboTipoMaq.Items.Count Then
                cboTipoMaq.SelectedIndex = m.TipoMaquina
            Else
                cboTipoMaq.SelectedIndex = 0
            End If

            numClaveLocal.Value = CDec(Math.Max(0, m.ClaveAccesoLocal))

            numSetT1.Value = CDec(Math.Max(0, Math.Min(250, m.TempConsignaSupIzq)))
            numSetT2.Value = CDec(Math.Max(0, Math.Min(250, m.TempConsignaSupDer)))
            numSetT3.Value = CDec(Math.Max(0, Math.Min(250, m.TempConsignaInfExt)))
            numSetT4.Value = CDec(Math.Max(0, Math.Min(250, m.TempConsignaInfInt)))
        End Sub

        Private Sub btnGuardarTodo_Click(sender As Object, e As EventArgs) Handles btnGuardarTodo.Click
            Dim g = GestorComunicaciones.Instancia

            Dim tSellado = CInt(numSellado.Value)
            Dim tArrastre = CInt(numArrastre.Value)
            Dim tMorC = CInt(numMorCierra.Value)
            Dim tMorA = CInt(numMorAbre.Value)
            Dim fcMor = If(chkFcMordaza.Checked, 1, 0)
            Dim taca = If(chkSensorTaca.Checked, 1, 0)
            Dim sec = cboSecuencia.SelectedIndex
            Dim tipoMaq = cboTipoMaq.SelectedIndex
            Dim clave = CInt(numClaveLocal.Value)

            Dim setT1 = CInt(numSetT1.Value)
            Dim setT2 = CInt(numSetT2.Value)
            Dim setT3 = CInt(numSetT3.Value)
            Dim setT4 = CInt(numSetT4.Value)

            ' Enviar tramas de configuración al Arduino NS-GH
            g.EnviarComandoMaquina("SET_SELLADO:" & tSellado)
            g.EnviarComandoMaquina("SET_ARRASTRE:" & tArrastre)
            g.EnviarComandoMaquina("SET_MOR_CIERRA:" & tMorC)
            g.EnviarComandoMaquina("SET_MOR_ABRE:" & tMorA)
            g.EnviarComandoMaquina("SET_FC_MOR:" & fcMor)
            g.EnviarComandoMaquina("SET_TACA:" & taca)
            g.EnviarComandoMaquina("SET_SECUENCIA:" & sec)
            g.EnviarComandoMaquina("SET_TIPO_MAQ:" & tipoMaq)
            g.EnviarComandoMaquina("SET_CLAVE_LOCAL:" & clave)

            g.EnviarComandoMaquina("SET_TEMP:7:" & setT1)
            g.EnviarComandoMaquina("SET_TEMP:8:" & setT2)
            g.EnviarComandoMaquina("SET_TEMP:9:" & setT3)
            g.EnviarComandoMaquina("SET_TEMP:10:" & setT4)

            ' Actualizar modelo local
            g.MaquinaPrincipal.TiempoSelladoMs = tSellado
            g.MaquinaPrincipal.TiempoArrastreMs = tArrastre
            g.MaquinaPrincipal.TiempoMordazaCierraMs = tMorC
            g.MaquinaPrincipal.TiempoMordazaAbreMs = tMorA
            g.MaquinaPrincipal.UsarFCMordaza = (fcMor = 1)
            g.MaquinaPrincipal.UsarSensorTaca = (taca = 1)
            g.MaquinaPrincipal.SecuenciaOperacion = sec
            g.MaquinaPrincipal.TipoMaquina = tipoMaq
            g.MaquinaPrincipal.ClaveAccesoLocal = clave
            g.MaquinaPrincipal.TempConsignaSupIzq = setT1
            g.MaquinaPrincipal.TempConsignaSupDer = setT2
            g.MaquinaPrincipal.TempConsignaInfExt = setT3
            g.MaquinaPrincipal.TempConsignaInfInt = setT4

            MessageBox.Show("Todos los parámetros han sido transmitidos y grabados en el Arduino NS-GH.", "Configuración Envasadora", MessageBoxButtons.OK, MessageBoxIcon.Information)
            Me.DialogResult = DialogResult.OK
            Me.Close()
        End Sub

        Private Sub btnResetContador_Click(sender As Object, e As EventArgs) Handles btnResetContador.Click
            If MessageBox.Show("¿Está seguro de reiniciar el contador de bolsas a 0?", "Confirmar Reinicio", MessageBoxButtons.YesNo, MessageBoxIcon.Question) = DialogResult.Yes Then
                GestorComunicaciones.Instancia.EnviarComandoMaquina("RESET_CONT")
                GestorComunicaciones.Instancia.MaquinaPrincipal.ContadorBolsas = 0
                MessageBox.Show("Contador de bolsas reiniciado a 0.", "Contador", MessageBoxButtons.OK, MessageBoxIcon.Information)
            End If
        End Sub

        Private Sub btnRestaurarFabrica_Click(sender As Object, e As EventArgs) Handles btnRestaurarFabrica.Click
            If MessageBox.Show("¿Está seguro de restablecer los valores de fábrica de la envasadora?", "Restaurar Fábrica", MessageBoxButtons.YesNo, MessageBoxIcon.Warning) = DialogResult.Yes Then
                GestorComunicaciones.Instancia.EnviarComandoMaquina("RESET_VALORES")
                System.Threading.Thread.Sleep(300)
                GestorComunicaciones.Instancia.EnviarComandoMaquina("ESTADO")
                MessageBox.Show("Valores de fábrica restablecidos en el Arduino NS-GH.", "Restauración Completada", MessageBoxButtons.OK, MessageBoxIcon.Information)
                CargarValoresActuales()
            End If
        End Sub

        Private Sub btnCerrar_Click(sender As Object, e As EventArgs) Handles btnCerrar.Click
            Me.Close()
        End Sub
    End Class
End Namespace
