Public Class SchedulerForm

    'Skill levels for students
    Public Enum Skill
        LOW
        HIGH
    End Enum

    'Checks for changes, will prompt user before saving/closing
    Public wasModified As Boolean = False

    Dim studentList As New List(Of Student)


    Public Class Student
        Public studentName As String
        Public skillLevel As Skill
        Public timeList As New List(Of String)

        'Needs to maintain a list of times in string form

        Public Sub New(ByVal newName As String, ByVal newSkill As Skill)
            Me.studentName = newName
            Me.skillLevel = newSkill
        End Sub


    End Class


    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'Need to add file loading/parsing to fill the student list from saved data
    End Sub

    

    

    Private Sub NextStudent_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles NextStudent.Click
        'Test to verify that students can be created and populated into list

        Dim newSkill As Skill
        newSkill = Skill.HIGH
        Dim newStudent As New Student("TestJ", newSkill)
        newStudent.timeList.Add("Time1")
        NameTextBox.Text = newStudent.studentName
        studentList.Add(newStudent)
        Dim newStudent2 As New Student("TestK", newSkill)
        newStudent2.timeList.Add("Time2")
        studentList.Add(newStudent2)
    End Sub

    Private Sub TestButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TestButton.Click
        'Test to verify students could be populated in the ListBox
        StudentListBox.Items.Clear()
        For Each Student In studentList
            StudentListBox.Items.Add(Student.studentName)
        Next (Student)
    End Sub

    Private Sub StudentListBox_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles StudentListBox.SelectedIndexChanged
        'Automatically pulls student data from the list as different students are selected in the listBox
        Dim TempStudent As Student
        If (Not (studentList.Count = 0)) Then
            If (StudentListBox.SelectedItems.Count > 0) Then
                TempStudent = studentList(StudentListBox.SelectedIndex)
                NameTextBox.Text = TempStudent.studentName
                TimesListBox.Items.Clear()

                For Each sItem As String In TempStudent.timeList
                    TimesListBox.Items.Add(sItem)
                Next (sItem)

                If TempStudent.skillLevel = Skill.HIGH Then
                    HighSkillRadio.Checked = True
                    LowSkillRadio.Checked = False
                Else
                    HighSkillRadio.Checked = False
                    LowSkillRadio.Checked = True
                End If
            End If
        End If

    End Sub


    Private Sub UpdateStudentButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles UpdateStudentButton.Click
        If (Not (studentList.Count = 0)) Then

            Dim TempStudent As Student
            TempStudent = studentList(StudentListBox.SelectedIndex)
            TempStudent.studentName = NameTextBox.Text
            If (HighSkillRadio.Checked = True) Then
                TempStudent.skillLevel = Skill.HIGH
            ElseIf (LowSkillRadio.Checked = True) Then
                TempStudent.skillLevel = Skill.LOW
            End If

        End If
    End Sub


    Private Sub ClearTimeButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ClearTimeButton.Click
        Dim TempStudent As Student
        If (Not (studentList.Count = 0)) Then
            If (Not (TimesListBox.SelectedItems.Count = 0)) Then

                TempStudent = studentList(StudentListBox.SelectedIndex)
                TempStudent.timeList.Remove(TempStudent.timeList(TimesListBox.SelectedIndex))
                TimesListBox.Items.Clear()
                For Each sItem As String In TempStudent.timeList
                    TimesListBox.Items.Add(sItem)
                Next (sItem)
            End If


        End If



    End Sub

    Private Sub AddTimeButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles AddTimeButton.Click
        Dim TempStudent As Student
        If (Not (studentList.Count = 0)) Then
            If (StudentListBox.SelectedItems.Count = 1) Then
                If (Not (StartTimeTextBox.Text = "")) Then
                    If (Not (EndTimeTextBox.Text = "")) Then
                        TempStudent = studentList(StudentListBox.SelectedIndex)
                        TempStudent.timeList.Add(StartTimeTextBox.Text + "  " + EndTimeTextBox.Text)


                        TimesListBox.Items.Clear()
                        For Each sItem As String In TempStudent.timeList
                            TimesListBox.Items.Add(sItem)
                        Next (sItem)
                    End If
                End If
            End If
        End If
    End Sub

End Class
