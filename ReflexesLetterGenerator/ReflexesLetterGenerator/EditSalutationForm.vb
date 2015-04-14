Public Class EditSalutationForm
    Dim EditSalutationList As List(Of ReflexesForm.Salutation) = Nothing
    Dim index As Integer

    Sub New(ByRef SalutationList As List(Of ReflexesForm.Salutation), ByVal tempIndex As Integer)
        InitializeComponent()
        EditSalutationList = SalutationList
        index = tempIndex

        EditSalNameTextBox.Text = EditSalutationList(index).SalutationName
        EditSalBodyTextBox.Text = EditSalutationList(index).SalutationInfo
    End Sub

    Private Sub CancelButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CancelButton.Click
        Me.Close()
    End Sub

    
    Private Sub SaveButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles SaveButton.Click
        'Check that both text boxes have stuff in them before making changes to the Salutation

        If Not (EditSalNameTextBox.Text = "") Then
            If Not (EditSalBodyTextBox.Text = "") Then

                Dim tempSal As New ReflexesForm.Salutation
                tempSal.SalutationName = EditSalNameTextBox.Text
                tempSal.SalutationInfo = EditSalBodyTextBox.Text

                EditSalutationList.RemoveAt(index)
                EditSalutationList.Add(tempSal)

                Me.Close()
            Else
                MsgBox("Please enter a Salutation Body")
            End If
        Else
            MsgBox("Please enter a Salutation Name")
        End If

    End Sub
End Class