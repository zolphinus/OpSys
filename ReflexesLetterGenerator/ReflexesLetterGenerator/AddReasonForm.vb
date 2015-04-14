Public Class AddReasonForm
    Dim tempReasonList As List(Of ReflexesForm.Reason) = Nothing
    Dim ReasonTitle As Boolean = False
    Dim Rev As Boolean = False


    Sub New(ByRef ReasonList As List(Of ReflexesForm.Reason))

        InitializeComponent()
        tempReasonList = ReasonList

    End Sub



    Private Sub OKButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles OKButton.Click
        If (ReasonTitleTextBox.Text = "") Then
            ReasonTitle = False
        Else
            ReasonTitle = True
        End If


        If (ReasonTitle = True) Then

            'create a salutation
            Dim tempRev As New ReflexesForm.Reason
            tempRev.ReasonName = ReasonTitleTextBox.Text
            tempRev.ReasonBody = New List(Of String)

            For Each Item In ReasonTextBox.Lines
                tempRev.ReasonBody.Add(Item)
            Next

            'add to list
            tempReasonList.Add(tempRev)



            Me.Close()



        Else
            MsgBox("Please enter a Reason Name")
        End If

    End Sub

    Private Sub CancelAddButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CancelAddButton.Click
        Me.Close()
    End Sub

End Class