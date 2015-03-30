Public Class AddReviewerForm
    Dim tempReviewerList As List(Of ReflexesForm.Reviewer) = Nothing
    Dim RevName As Boolean = False
    Dim Rev As Boolean = False


    Sub New(ByRef ReviewerList As List(Of ReflexesForm.Reviewer))

        InitializeComponent()
        tempReviewerList = ReviewerList

    End Sub



    Private Sub OKButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles OKButton.Click
        If (RevNameTextBox.Text = "") Then
            RevName = False
        Else
            RevName = True
        End If


        If (RevName = True) Then

            'create a salutation
            Dim tempRev As New ReflexesForm.Reviewer
            tempRev.ReviewerName = RevNameTextBox.Text

            'add to list
            tempReviewerList.Add(tempRev)



            Me.Close()



        Else
        MsgBox("Please enter a Reviewer Name")
        End If

    End Sub

    Private Sub CancelAddButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CancelAddButton.Click
        Me.Close()
    End Sub

    
End Class