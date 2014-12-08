Imports System.IO

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

    Private Sub SchedulerForm_Load(ByVal sender As Object, _
    ByVal e As System.EventArgs) Handles MyBase.Load
        'Performs actions once the form has been loaded
        'Load file and populate lists here

        Const filepath As String = "c:\student_scheduler\students\"

        If (Not Directory.Exists(filepath)) Then
            Directory.CreateDirectory(filepath)
        End If

        If Not My.Computer.FileSystem.FileExists(filepath & "students.txt") Then
            'Uses the file system to create the students file if it does not exist
            Dim fs As FileStream = File.Create(filepath & "students.txt")
            fs.Close()

        End If


        Dim fileRead As New IO.StreamReader(filepath & "students.txt")
        Dim input As String
        Dim tempName As String
        Dim tempSkill As Skill

        'First line is either empty, or a * character which means a student's data is available

        input = fileRead.ReadLine()

        While Not (input Is Nothing)
            If (input Is Nothing) Then
                Exit While
            End If
            'reads the name first
            input = fileRead.ReadLine()
            tempName = input
            'reads the skill level string
            input = fileRead.ReadLine()
            If (input = "HIGH") Then
                'High skill students require proper string, while low skill students are default
                tempSkill = Skill.HIGH
            Else
                tempSkill = Skill.LOW
            End If
            Dim newStudent As New Student(tempName, tempSkill)

            While Not (input Is Nothing)
                input = fileRead.ReadLine()
                If (input = "*") Then
                    Exit While
                ElseIf (input Is Nothing) Then
                    Exit While
                End If

                newStudent.timeList.Add(input)

            End While



            'while for times



            'NameTextBox.Text = newStudent.studentName
            studentList.Add(newStudent)

        End While


        'read in students from file




        fileRead.Close()
        StudentListBox.Items.Clear()
        For Each Student In studentList
            StudentListBox.Items.Add(Student.studentName)
        Next (Student)



    End Sub

    'Implement the ability to save students to file
    Private Sub SchedulerForm_UnLoad(ByVal sender As Object, _
        ByVal e As System.EventArgs) Handles MyBase.Disposed
        Const filepath As String = "c:\student_scheduler\students\"

        If (Not Directory.Exists(filepath)) Then
            Directory.CreateDirectory(filepath)
        End If

        If Not My.Computer.FileSystem.FileExists(filepath & "students.txt") Then
            'Uses the file system to create the students file if it does not exist
            Dim fs As FileStream = File.Create(filepath & "students.txt")
            fs.Close()

        End If

        'Write to file without append. Change false to true for append.
        Dim fileSave As New IO.StreamWriter(filepath & "students.txt", False)
        
        For Each Student In studentList
            'Asterisk is used as a file marker
            fileSave.WriteLine("*")
            'Writes name
            fileSave.WriteLine(Student.studentName)
            'Writes skill level
            If (Student.skillLevel = Skill.HIGH) Then
                fileSave.WriteLine("HIGH")
            Else
                fileSave.WriteLine("LOW")
            End If
            'Writes student times
            For Each sItem As String In Student.timeList
                fileSave.WriteLine(sItem)
            Next (sItem)
        Next (Student)

        fileSave.Close()

    End Sub


    'Implement Scheduling Algorithm

End Class
