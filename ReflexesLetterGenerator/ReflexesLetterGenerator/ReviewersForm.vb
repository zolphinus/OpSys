Public Class ReviewersForm


    Dim tempReviewerList As List(Of ReflexesForm.Reviewer) = Nothing

    Sub New(ByRef ReviewerList As List(Of ReflexesForm.Reviewer))
        'loads the list of Reviewers
        InitializeComponent()
        tempReviewerList = ReviewerList

    End Sub

    
    Private Sub AddReviewerButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles AddReviewerButton.Click
        Dim AddReviewerForm As New AddReviewerForm(tempReviewerList)
        AddReviewerForm.ShowDialog()

        ReviewerListBox.Items.Clear()
        For Each Item In tempReviewerList
            ReviewerListBox.Items.Add(Item.ReviewerName)
        Next Item

    End Sub

    Private Sub DeleteReviewerButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles DeleteReviewerButton.Click
        If (ReviewerListBox.Items.Count > 0) Then
            If (ReviewerListBox.SelectedIndex >= 0) Then
                'prompt user YES/NO to decide to delete or not
                tempReviewerList.RemoveAt(ReviewerListBox.SelectedIndex)
                ReviewerListBox.Items.Clear()
                For Each Item In tempReviewerList
                    ReviewerListBox.Items.Add(Item.ReviewerName)
                Next Item

            Else
                MsgBox("Please select a Reviewer to delete!")
            End If
        Else
            MsgBox("There are no Reviewers to delete!")
        End If
    End Sub

    Private Sub OKButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles OKButton.Click
        'save Reviewers to file
        Dim REVIEWERS_FILE As String = "reviewers.txt"
        Dim objWriter As New System.IO.StreamWriter(REVIEWERS_FILE)

        For Each Item In tempReviewerList
            objWriter.WriteLine(Item.ReviewerName)
        Next Item

        objWriter.Close()
        Me.Close()
    End Sub

    Private Sub ReviewersForm_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'Clear then Populate List Box so that it's current
        ReviewerListBox.Items.Clear()
        For Each Item In tempReviewerList
            ReviewerListBox.Items.Add(Item.ReviewerName)
        Next Item
    End Sub

    Private Sub EditReviewerButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles EditReviewerButton.Click


        ReviewerListBox.Items.Clear()
        For Each Item In tempReviewerList
            ReviewerListBox.Items.Add(Item.ReviewerName)
        Next Item
    End Sub
End Class