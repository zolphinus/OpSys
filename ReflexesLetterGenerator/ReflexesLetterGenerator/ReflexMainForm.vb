Imports System.IO

Public Class ReflexesForm

    Dim SalutationSelected As Boolean = False
    Dim ReasonSelected As Boolean = False
    Dim ReviewerSelected As Boolean = False
    Dim RecipientSelected As Boolean = False

    Dim ReasonList As New List(Of Reason)
    Dim ReviewerList As New List(Of Reviewer)
    Dim SalutationList As New List(Of Salutation)

    Dim CurrentSalutation As Salutation
    Dim CurrentReviewer As Reviewer
    Dim CurrentReason As Reason


    Public Structure Salutation
        Public SalutationName As String
        Public SalutationInfo As String
    End Structure


    Public Structure Reviewer
        Public ReviewerName As String
    End Structure

    Public Structure Reason
        Public ReasonName As String
        Public ReasonBody As List(Of String)


        'function to delete the body
        Public Sub deleteBody()
            ReasonBody.Clear()
        End Sub


    End Structure

    Private Sub EditSalutationsButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles EditSalutationsButton.Click
        Dim SalutationForm As New SalutationsForm(SalutationList)
        SalutationForm.ShowDialog()

        SalutationComboBox.Items.Clear()
        For Each Item In SalutationList
            SalutationComboBox.Items.Add(Item.SalutationName)
        Next Item

        SalutationSelected = False
    End Sub

    Private Sub EditReviewersButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles EditReviewersButton.Click
        Dim ReviewersForm As New ReviewersForm(ReviewerList)
        ReviewersForm.ShowDialog()

        ReviewerComboBox.Items.Clear()
        For Each Item In ReviewerList
            ReviewerComboBox.Items.Add(Item.ReviewerName)
        Next Item

        ReviewerSelected = False
    End Sub


    Private Sub ReflexesForm_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'Load Reasons from file to create reason list
        Dim REASONS_FILE_NAME As String = "reasons.txt"
        Dim REASONS_BACKUP_FILE As String = "reasons1.txt"
        Dim REVIEWERS_FILE_NAME As String = "reviewers.txt"
        Dim REVIEWERS_BACKUP_FILE As String = "reviewers1.txt"
        Dim SALUTATIONS_FILE_NAME As String = "salutations.txt"
        Dim SALUTATIONS_BACKUP_FILE As String = "salutations1.txt"



        If File.Exists(SALUTATIONS_FILE_NAME) = True Then
            'Creates a backup of the last known good Salutations file
            FileCopy(SALUTATIONS_FILE_NAME, SALUTATIONS_BACKUP_FILE)
            Dim objReader As New System.IO.StreamReader(SALUTATIONS_FILE_NAME)

            Dim line As String = ""

            While True
                line = objReader.ReadLine()
                'If the file reads in the EOF, line will be empty, and break the loop
                If line Is Nothing Then
                    Exit While
                End If

                Dim TempSalutation As New Salutation
                TempSalutation.SalutationName = line

                line = objReader.ReadLine()
                TempSalutation.SalutationInfo = line

                CurrentSalutation = TempSalutation
                SalutationList.Add(CurrentSalutation)
                SalutationComboBox.Items.Add(CurrentSalutation.SalutationName)
            End While
            objReader.Close()
        Else
            File.Create(SALUTATIONS_FILE_NAME)
            'If the primary file doesn't exist but the backup does, restore it
            'and then read the info in
            If File.Exists(SALUTATIONS_BACKUP_FILE) = True Then
                FileClose(SALUTATIONS_BACKUP_FILE, SALUTATIONS_FILE_NAME)
                Dim objReader As New System.IO.StreamReader(SALUTATIONS_FILE_NAME)

                Dim line As String = ""

                While True
                    line = objReader.ReadLine()
                    'If the file reads in the EOF, line will be empty, and break the loop
                    If line Is Nothing Then
                        Exit While
                    End If

                    Dim TempSalutation As New Salutation
                    TempSalutation.SalutationName = line

                    line = objReader.ReadLine()
                    TempSalutation.SalutationInfo = line

                    CurrentSalutation = TempSalutation
                    SalutationList.Add(CurrentSalutation)
                    SalutationComboBox.Items.Add(CurrentSalutation.SalutationName)
                End While
                objReader.Close()
            End If
        End If


        If File.Exists(REVIEWERS_FILE_NAME) = True Then
            'Creates a backup of the last known good Salutations file
            FileCopy(REVIEWERS_FILE_NAME, REVIEWERS_BACKUP_FILE)
            Dim objReader As New System.IO.StreamReader(REVIEWERS_FILE_NAME)

            Dim line As String = ""

            While True
                line = objReader.ReadLine()
                'If the file reads in the EOF, line will be empty, and break the loop
                If line Is Nothing Then
                    Exit While
                End If

                'creates reviewers list
                Dim TempReviewer As New Reviewer
                TempReviewer.ReviewerName = line

                CurrentReviewer = TempReviewer
                ReviewerList.Add(CurrentReviewer)
                'add reviewers to the combo box
                ReviewerComboBox.Items.Add(CurrentReviewer.ReviewerName)

            End While
            objReader.Close()
        Else
            File.Create(REVIEWERS_FILE_NAME)
            'If the primary file doesn't exist but the backup does, restore it
            'and then read the info in
            If File.Exists(REVIEWERS_BACKUP_FILE) = True Then
                FileClose(REVIEWERS_BACKUP_FILE, REVIEWERS_FILE_NAME)
                Dim objReader As New System.IO.StreamReader(REVIEWERS_FILE_NAME)

                Dim line As String = ""

                While True
                    line = objReader.ReadLine()
                    'If the file reads in the EOF, line will be empty, and break the loop
                    If line Is Nothing Then
                        Exit While
                    End If

                    'creates reviewers list
                    Dim TempReviewer As New Reviewer
                    TempReviewer.ReviewerName = line

                    CurrentReviewer = TempReviewer
                    ReviewerList.Add(CurrentReviewer)
                    'add reviewers to the combo box
                    ReviewerComboBox.Items.Add(CurrentReviewer.ReviewerName)
                End While
                objReader.Close()
            End If
        End If


        Dim readTitle As Boolean = True

        If File.Exists(REASONS_FILE_NAME) = True Then
            'Creates a backup of the last known good Salutations file
            FileCopy(REASONS_FILE_NAME, REASONS_BACKUP_FILE)
            Dim objReader As New System.IO.StreamReader(REASONS_FILE_NAME)

            Dim line As String = ""

            While True
                line = objReader.ReadLine()
                'If the file reads in the EOF, line will be empty, and break the loop
                If line Is Nothing Then
                    Exit While
                End If

                'creates reviewers list
                Dim TempReason As New Reason
                TempReason.ReasonName = line
                TempReason.ReasonBody = New List(Of String)

                While Not line.Equals("*")
                    line = objReader.ReadLine()
                    If line Is Nothing Then
                        Exit While
                    End If

                    If line = "*" Then
                        Exit While
                    End If


                    TempReason.ReasonBody.Add(line)
                End While

                CurrentReason = TempReason
                ReasonList.Add(CurrentReason)
                'add reviewers to the combo box
                ReasonComboBox.Items.Add(CurrentReason.ReasonName)

            End While
            objReader.Close()
        Else
            File.Create(REASONS_FILE_NAME)
            'If the primary file doesn't exist but the backup does, restore it
            'and then read the info in
            If File.Exists(REASONS_BACKUP_FILE) = True Then
                FileClose(REASONS_BACKUP_FILE, REASONS_FILE_NAME)
                Dim objReader As New System.IO.StreamReader(REASONS_FILE_NAME)

                Dim line As String = ""

                While True
                    line = objReader.ReadLine()
                    'If the file reads in the EOF, line will be empty, and break the loop
                    If line Is Nothing Then
                        Exit While
                    End If

                    'creates reviewers list
                    Dim TempReason As New Reason
                    TempReason.ReasonName = line
                    TempReason.ReasonBody = New List(Of String)

                    While True
                        If line.Equals("*") Then
                            Exit While
                        End If
                        line = objReader.ReadLine()
                        TempReason.ReasonBody.Add(line)
                    End While

                    CurrentReason = TempReason
                    ReasonList.Add(CurrentReason)
                    'add reviewers to the combo box
                    ReasonComboBox.Items.Add(CurrentReason.ReasonName)

                End While
                objReader.Close()
            End If
        End If
    End Sub

    'Saves the updated Reason/Reviewer/Salutations files on form close

    Private Sub ReasonComboBox_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ReasonComboBox.SelectedIndexChanged
        ReasonSelected = True
    End Sub

    Private Sub SalutationComboBox_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles SalutationComboBox.SelectedIndexChanged
        SalutationSelected = True
    End Sub

    Private Sub ReviewerComboBox_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles SalutationComboBox.SelectedIndexChanged
        ReviewerSelected = True
    End Sub

    Private Sub SaveLetterButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles SaveLetterButton.Click

        If (RecipientNameTextBox.Text = "") Then
            RecipientSelected = False
        Else
            RecipientSelected = True
        End If

        If (RecipientSelected = True) Then
            If (ReasonSelected = True) Then
                If (SalutationSelected = True) Then
                    If (ReviewerSelected = True) Then
                        'Prompt to Save the letter
                        'Save to a text file [RecipientName]Letter.txt

                        'Format the Letter

                        'Reflexes Header
                        'School Address
                        'City/State/Zip

                        'Spacing, then "Dear Recipient,"

                        'Spacing and then letter body

                        'Spacing and then Salutation


                        'Spacing and then Reviewer Name



                    Else
                        MsgBox("Please select a reviewer.")
                    End If
                Else
                    MsgBox("Please select a salutation.")
                End If
            Else
                MsgBox("Please select a reason.")
            End If
        Else
            MsgBox("Please select a recipient.")
        End If
    End Sub

    Private Sub EditReasonsButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles EditReasonsButton.Click
        Dim ReasonsForm As New ReasonsForm(ReasonList)
        ReasonsForm.ShowDialog()

        ReasonComboBox.Items.Clear()
        For Each Item In ReasonList
            ReasonComboBox.Items.Add(Item.ReasonName)
        Next Item

        ReasonSelected = False
    End Sub

End Class
