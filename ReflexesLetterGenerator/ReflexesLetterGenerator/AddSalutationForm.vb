Public Class AddSalutationForm
    Dim tempSalutationList As List(Of ReflexesForm.Salutation) = Nothing
    Dim SalName As Boolean = False
    Dim Sal As Boolean = False


    Sub New(ByRef SalutationList As List(Of ReflexesForm.Salutation))

        InitializeComponent()
        tempSalutationList = SalutationList

    End Sub



    Private Sub OKButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles OKButton.Click
        If (SalNameTextBox.Text = "") Then
            SalName = False
        Else
            SalName = True
        End If

        If (SalTextBox.Text = "") Then
            Sal = False
        Else
            Sal = True
        End If

        If (SalName = True) Then
            If (Sal = True) Then
                'create a salutation
                Dim tempSal As New ReflexesForm.Salutation
                tempSal.SalutationName = SalNameTextBox.Text
                tempSal.SalutationInfo = SalTextBox.Text

                'add to list
                tempSalutationList.Add(tempSal)



                Me.Close()
            Else
                MsgBox("Please enter a salutation")
            End If
        Else
            MsgBox("Please enter a Salutation Name")
        End If

    End Sub

    Private Sub CancelAddButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CancelAddButton.Click
        Me.Close()
    End Sub
End Class