Public Class EditReviewersForm
    Dim EditReviewersList As List(Of ReflexesForm.Reviewer) = Nothing
    Dim index As Integer

    Sub New(ByRef ReviewersList As List(Of ReflexesForm.Reviewer), ByVal tempIndex As Integer)
        InitializeComponent()
        EditReviewersList = ReviewersList
        index = tempIndex

        EditRevNameTextBox.Text = EditReviewersList(index).ReviewerName
    End Sub

    Private Sub CancelButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CancelButton.Click
        Me.Close()
    End Sub


    Private Sub SaveButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles SaveButton.Click
        'Check that both text boxes have stuff in them before making changes to the Reviewers

        If Not (EditRevNameTextBox.Text = "") Then

                Dim tempRev As New ReflexesForm.Reviewer
                tempRev.ReviewerName = EditRevNameTextBox.Text

                EditReviewersList.RemoveAt(index)
                EditReviewersList.Add(tempRev)

                Me.Close()
        Else
            MsgBox("Please enter a Reviewers Name")
        End If

    End Sub
End Class