Public Class SalutationsForm


    Dim tempSalutationList As List(Of ReflexesForm.Salutation) = Nothing

    Sub New(ByRef SalutationList As List(Of ReflexesForm.Salutation))
        'loads the list of salutations
        InitializeComponent()
        tempSalutationList = SalutationList

    End Sub

    Private Sub EditSalutationsForm_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'Clear then Populate List Box so that it's current
        SalutationListBox.Items.Clear()
        For Each Item In tempSalutationList
            SalutationListBox.Items.Add(Item.SalutationName)
        Next Item
    End Sub

    Private Sub AddSalutationButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles AddSalutationButton.Click
        Dim AddSalutationForm As New AddSalutationForm(tempSalutationList)
        AddSalutationForm.ShowDialog()

        SalutationListBox.Items.Clear()
        For Each Item In tempSalutationList
            SalutationListBox.Items.Add(Item.SalutationName)
        Next Item

    End Sub

    Private Sub DeleteSalutationButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles DeleteSalutationButton.Click
        If (SalutationListBox.Items.Count > 0) Then
            If (SalutationListBox.SelectedIndex >= 0) Then
                'prompt user YES/NO to decide to delete or not
                tempSalutationList.RemoveAt(SalutationListBox.SelectedIndex)
                SalutationListBox.Items.Clear()
                For Each Item In tempSalutationList
                    SalutationListBox.Items.Add(Item.SalutationName)
                Next Item

            Else
                MsgBox("Please select a salutation to delete!")
            End If
        Else
            MsgBox("There are no salutations to delete!")
        End If
    End Sub

    Private Sub OKButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles OKButton.Click
        'save salutations to file
        Dim SALUTATIONS_FILE As String = "salutations.txt"
        Dim objWriter As New System.IO.StreamWriter(SALUTATIONS_FILE)

        For Each Item In tempSalutationList
            objWriter.WriteLine(Item.SalutationName)
            objWriter.WriteLine(Item.SalutationInfo)
        Next Item

        objWriter.Close()
        Me.Close()
    End Sub
End Class