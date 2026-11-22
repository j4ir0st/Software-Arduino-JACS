Imports System
Imports System.IO.Ports
Imports System.Windows.Forms
Imports Clases

Namespace Formularios
    Public Class FormConfiguracionPuertos
        Private Sub FormConfiguracionPuertos_Load(sender As Object, e As EventArgs) Handles MyBase.Load
            CargarPuertosDisponibles()
            CargarTolvasActuales()
        End Sub

        Private Sub CargarPuertosDisponibles()
            Dim puertos = SerialPort.GetPortNames()

            cboPuertoMaquina.Items.Clear()
            colPuerto.Items.Clear()

            For Each p In puertos
                cboPuertoMaquina.Items.Add(p)
                colPuerto.Items.Add(p)
            Next

            If cboPuertoMaquina.Items.Contains(GestorComunicaciones.Instancia.MaquinaPrincipal.PuertoCOM) Then
                cboPuertoMaquina.SelectedItem = GestorComunicaciones.Instancia.MaquinaPrincipal.PuertoCOM
            ElseIf cboPuertoMaquina.Items.Count > 0 Then
                cboPuertoMaquina.SelectedIndex = 0
            End If
        End Sub

        Private Sub CargarTolvasActuales()
            dgvTolvas.Rows.Clear()
            For Each tolva In GestorComunicaciones.Instancia.ListaTolvas
                Dim filaIdx = dgvTolvas.Rows.Add(tolva.IdTolva, tolva.Nombre, tolva.PuertoCOM)
            Next
        End Sub

        Private Sub btnEscanear_Click(sender As Object, e As EventArgs) Handles btnEscanear.Click
            lstResultadosEscaneo.Items.Clear()
            lstResultadosEscaneo.Items.Add("Escaneando puertos USB... por favor espere...")
            Application.DoEvents()

            Dim resultados = GestorComunicaciones.Instancia.EscanearYAutoDetectarPuertos()
            lstResultadosEscaneo.Items.Clear()

            CargarPuertosDisponibles()

            For Each kvp In resultados
                lstResultadosEscaneo.Items.Add(kvp.Key & " -> " & kvp.Value)
            Next

            If Not String.IsNullOrEmpty(GestorComunicaciones.Instancia.MaquinaPrincipal.PuertoCOM) Then
                If cboPuertoMaquina.Items.Contains(GestorComunicaciones.Instancia.MaquinaPrincipal.PuertoCOM) Then
                    cboPuertoMaquina.SelectedItem = GestorComunicaciones.Instancia.MaquinaPrincipal.PuertoCOM
                End If
            End If

            CargarTolvasActuales()
        End Sub

        Private Sub btnAgregarTolva_Click(sender As Object, e As EventArgs) Handles btnAgregarTolva.Click
            Dim nuevoId As Integer = 1
            If GestorComunicaciones.Instancia.ListaTolvas.Count > 0 Then
                nuevoId = GestorComunicaciones.Instancia.ListaTolvas(GestorComunicaciones.Instancia.ListaTolvas.Count - 1).IdTolva + 1
            End If

            Dim nuevaTolva As New ModeloTolva() With {
                .IdTolva = nuevoId,
                .Nombre = "Tolva " & nuevoId,
                .PuertoCOM = If(cboPuertoMaquina.Items.Count > 0, cboPuertoMaquina.Items(0).ToString(), "COM1")
            }
            GestorComunicaciones.Instancia.ListaTolvas.Add(nuevaTolva)
            CargarTolvasActuales()
        End Sub

        Private Sub btnEliminarTolva_Click(sender As Object, e As EventArgs) Handles btnEliminarTolva.Click
            If dgvTolvas.CurrentRow IsNot Nothing Then
                Dim id As Integer = CInt(dgvTolvas.CurrentRow.Cells(0).Value)
                Dim tolva = GestorComunicaciones.Instancia.ListaTolvas.Find(Function(t) t.IdTolva = id)
                If tolva IsNot Nothing Then
                    GestorComunicaciones.Instancia.ListaTolvas.Remove(tolva)
                    CargarTolvasActuales()
                End If
            End If
        End Sub

        Private Sub btnGuardarConectar_Click(sender As Object, e As EventArgs) Handles btnGuardarConectar.Click
            ' Guardar asignación de la máquina principal
            If cboPuertoMaquina.SelectedItem IsNot Nothing Then
                Dim puertoMain = cboPuertoMaquina.SelectedItem.ToString()
                GestorComunicaciones.Instancia.MaquinaPrincipal.PuertoCOM = puertoMain
                GestorComunicaciones.Instancia.ConectarMaquinaPrincipal(puertoMain)
            End If

            ' Guardar asignaciones de las tolvas
            For Each row As DataGridViewRow In dgvTolvas.Rows
                Dim id = CInt(row.Cells(0).Value)
                Dim nombre = row.Cells(1).Value.ToString()
                Dim puerto = If(row.Cells(2).Value IsNot Nothing, row.Cells(2).Value.ToString(), "")

                Dim tolva = GestorComunicaciones.Instancia.ListaTolvas.Find(Function(t) t.IdTolva = id)
                If tolva IsNot Nothing Then
                    tolva.Nombre = nombre
                    tolva.PuertoCOM = puerto
                    If Not String.IsNullOrEmpty(puerto) Then
                        GestorComunicaciones.Instancia.ConectarTolva(id, puerto)
                    End If
                End If
            Next

            MessageBox.Show("Configuración guardada y puertos conectados correctamente.", "Conexión USB", MessageBoxButtons.OK, MessageBoxIcon.Information)
            Me.DialogResult = DialogResult.OK
            Me.Close()
        End Sub

        Private Sub btnCerrar_Click(sender As Object, e As EventArgs) Handles btnCerrar.Click
            Me.Close()
        End Sub
    End Class
End Namespace
