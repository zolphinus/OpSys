Public Class ReasonsForm


    Dim tempReasonsList As List(Of ReflexesForm.Reason) = Nothing
    Dim tempReason As ReflexesForm.Reason = Nothing


    Sub New(ByRef ReasonsList As List(Of ReflexesForm.Reason))
        'loads the list of Reasonss
        InitializeComponent()
        tempReasonsList = ReasonsList

    End Sub


    Private Sub AddReasonsButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles AddReasonsButton.Click
        Dim AddReasonsForm As New AddReasonForm(tempReasonsList)
        AddReasonsForm.ShowDialog()

        ReasonsListBox.Items.Clear()
        For Each Item In tempReasonsList
            ReasonsListBox.Items.Add(Item.ReasonName)
        Next Item

    End Sub

    Private Sub DeleteReasonsButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles DeleteReasonsButton.Click
        If (ReasonsListBox.Items.Count > 0) Then
            If (ReasonsListBox.SelectedIndex >= 0) Then
                'prompt user YES/NO to decide to delete or not
                tempReasonsList.RemoveAt(ReasonsListBox.SelectedIndex)
                ReasonsListBox.Items.Clear()
                ReasonTextBox.Clear()
                For Each Item In tempReasonsList
                    ReasonsListBox.Items.Add(Item.ReasonName)
                Next Item

            Else
                MsgBox("Please select a Reasons to delete!")
            End If
        Else
            MsgBox("There are no Reasonss to delete!")
        End If
    End Sub

    Private Sub OKButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles OKButton.Click
        'save Reasonss to file
        Dim ReasonsS_FILE As String = "reasons.txt"
        Dim objWriter As New System.IO.StreamWriter(ReasonsS_FILE)

        For Each ReasonItem In tempReasonsList
            objWriter.WriteLine(ReasonItem.ReasonName)
            For Each BodyItem In ReasonItem.ReasonBody
                objWriter.WriteLine(BodyItem)
            Next
            objWriter.WriteLine("*")
        Next ReasonItem

        objWriter.Close()
        Me.Close()
    End Sub

    Private Sub ReasonssForm_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'Clear then Populate List Box so that it's current
        ReasonsListBox.Items.Clear()
        For Each Item In tempReasonsList
            ReasonsListBox.Items.Add(Item.ReasonName)
        Next Item
    End Sub

    Private Sub EditReasonsButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles EditReasonsButton.Click
        If (ReasonsListBox.Items.Count > 0) Then
            If ReasonsListBox.SelectedIndex > -1 Then
                Dim EditSalForm As New EditReasonsForm(tempReasonsList, ReasonsListBox.SelectedIndex)
                EditSalForm.ShowDialog()


                ReasonsListBox.Items.Clear()
                For Each Item In tempReasonsList
                    ReasonsListBox.Items.Add(Item.ReasonName)
                Next Item

            Else
                MsgBox("Select a Reason to edit!")

            End If
        Else
            MsgBox("There are no Reasons to edit!")
        End If

        ReasonsListBox.Items.Clear()
        For Each Item In tempReasonsList
            ReasonsListBox.Items.Add(Item.ReasonName)
        Next Item
    End Sub

    Private Sub ReasonsListBox_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ReasonsListBox.SelectedIndexChanged

        ReasonTextBox.Clear()

        If (ReasonsListBox.SelectedIndex > -1) Then
            tempReason = tempReasonsList(ReasonsListBox.SelectedIndex)
            For Each Item In tempReason.ReasonBody
                ReasonTextBox.AppendText(Item & vbNewLine)
            Next
        End If

    End Sub
End Class