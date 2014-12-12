Imports System.IO

Public Class SchedulerForm

    'Skill levels for students
    Public Enum Skill
        LOW
        AVERAGE
        HIGH
    End Enum

    'Checks for changes, will prompt user before saving/closing
    Public wasModified As Boolean = False

    Dim studentList As New List(Of Student)

    Dim Generator As System.Random = New System.Random()


    Public Class Student
        Public studentName As String
        Public skillLevel As Skill
        Public randomID As Integer


        Public timeList As New List(Of String)

        'Needs to maintain a list of times in string form

        Public Sub New(ByVal newName As String, ByVal newSkill As Skill, ByVal newID As Integer)
            Me.studentName = newName
            Me.skillLevel = newSkill
            randomID = newID
        End Sub
    End Class

    Public Class Team
        Public TeamNumber As Integer
        Public MembersList As New List(Of Student)

        Public Sub New(ByVal NewTeamNumber As Integer)
            Me.TeamNumber = NewTeamNumber
        End Sub
    End Class

    Public Class TimeNode
        Public timeInt As Integer
        Public timeString As String
        Public studentList As New List(Of Student)

        Public Sub New(ByVal timeInt As Integer)
            Me.timeInt = timeInt
            Me.timeString = Convert.ToString(timeInt)
        End Sub
    End Class



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
                ElseIf TempStudent.skillLevel = Skill.AVERAGE Then
                    AverageRadioButton.Checked = True
                Else
                    LowSkillRadio.Checked = True
                End If
            End If
        End If

        If (StudentListBox.SelectedItems.Count = 1) Then
            RemoveButton.Enabled = True
        End If


    End Sub


    Private Sub UpdateStudentButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles UpdateStudentButton.Click
        If (Not (studentList.Count = 0)) Then
            If Not (StudentListBox.SelectedItems.Count = 0) Then

                Dim TempStudent As Student
                TempStudent = studentList(StudentListBox.SelectedIndex)
                TempStudent.studentName = NameTextBox.Text
                If (HighSkillRadio.Checked = True) Then
                    TempStudent.skillLevel = Skill.HIGH
                ElseIf (AverageRadioButton.Checked = True) Then
                    TempStudent.skillLevel = Skill.AVERAGE
                Else
                    TempStudent.skillLevel = Skill.AVERAGE
                End If
                StudentListBox.Items.Clear()
                For Each Student In studentList
                    StudentListBox.Items.Add(Student.studentName)
                Next (Student)
                UpdateStudentButton.Enabled = False
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

        'Checks to see if the directory is present, and if not, creates it
        If (Not Directory.Exists(filepath)) Then
            Directory.CreateDirectory(filepath)
        End If

        If Not My.Computer.FileSystem.FileExists(filepath & "students.txt") Then
            'Uses the file system to create the students file if it does not exist
            Dim fs As FileStream = File.Create(filepath & "students.txt")
            fs.Close()

        End If

        'defaults the name text box to zero length, for GUI purposes
        NameTextBox.Text = ""
        NewStudentButton.Enabled = False
        RemoveButton.Enabled = False
        UpdateStudentButton.Enabled = False
        CalculateButton.Enabled = False
        CompetenceRadioButton.Checked = True
        FifteenRadioButton.Checked = True

        Dim fileRead As New IO.StreamReader(filepath & "students.txt")
        Dim input As String
        Dim tempName As String
        Dim tempSkill As Skill
        Dim tempRandom As Integer
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
            If (input = "High") Then
                'High skill students require proper string, while low skill students are default
                tempSkill = Skill.HIGH
            ElseIf (input = "Average") Then
                tempSkill = Skill.AVERAGE
            Else
                tempSkill = Skill.LOW
            End If
            tempRandom = Generator.Next(0, 1000)
            Dim newStudent As New Student(tempName, tempSkill, tempRandom)

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
                fileSave.WriteLine("High")
            ElseIf (Student.skillLevel = Skill.AVERAGE) Then
                fileSave.WriteLine("Average")
            Else
                fileSave.WriteLine("Low")
            End If
            'Writes student times
            For Each sItem As String In Student.timeList
                fileSave.WriteLine(sItem)
            Next (sItem)
        Next (Student)

        fileSave.Close()

    End Sub




    Private Sub NewStudentButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles NewStudentButton.Click
        Dim tempSkill As Skill

        If (HighSkillRadio.Checked = True) Then
            tempSkill = Skill.HIGH
        ElseIf (AverageRadioButton.Checked = True) Then
            tempSkill = Skill.AVERAGE
        Else
            tempSkill = Skill.LOW
        End If

        Dim tempRandom As Integer
        tempRandom = Generator.Next(0, 1000)
        Dim newStudent As New Student(NameTextBox.Text, tempSkill, tempRandom)
        studentList.Add(newStudent)
        StudentListBox.Items.Clear()
        For Each Student In studentList
            StudentListBox.Items.Add(Student.studentName)
        Next (Student)
    End Sub

    Private Sub RemoveButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles RemoveButton.Click
        If (StudentListBox.SelectedItems.Count = 1) Then
            'If a student is selected
            studentList.Remove(studentList(StudentListBox.SelectedIndex))
            StudentListBox.Items.Clear()
            For Each Student In studentList
                StudentListBox.Items.Add(Student.studentName)
            Next (Student)

            If (studentList.Count = 0) Then
                CalculateButton.Enabled = False
            End If

        End If
    End Sub

    Private Sub NameTextBox_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles NameTextBox.TextChanged
        If (NameTextBox.Text.Length = 0) Then
            NewStudentButton.Enabled = False
            UpdateStudentButton.Enabled = False
        Else
            NewStudentButton.Enabled = True
            UpdateStudentButton.Enabled = True
        End If
    End Sub

    Private Sub GroupSizeTextBox_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles GroupSizeTextBox.TextChanged
        If (studentList.Count > 0 And TeamsFileBox.Text.Length > 0) Then
            CalculateButton.Enabled = True
        Else
            CalculateButton.Enabled = False
        End If
    End Sub

    Private Sub TeamsFileBox_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TeamsFileBox.TextChanged
        If (studentList.Count > 0 And TeamsFileBox.Text.Length > 0) Then
            CalculateButton.Enabled = True
        Else
            CalculateButton.Enabled = False
        End If
    End Sub

    Private Sub CalculateButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CalculateButton.Click
        

        Dim teamSize As Integer
        teamSize = Convert.ToInt32(GroupSizeTextBox.Text)

        Dim numTeams As Integer = studentList.Count / teamSize
        If (numTeams < 1) Then
            numTeams = 1
        End If

        'Set to zero to allow for error checking later, if desired
        Dim timeInterval As Integer = 0
        Dim selectedMode As Integer = 0

        'Determines which calculation mode to use
        If (CompetenceRadioButton.Checked = True) Then
            selectedMode = 1
        ElseIf (RandomRadioButton.Checked = True) Then
            selectedMode = 2
        ElseIf (TimeMatchRadioButton.Checked = True) Then
            selectedMode = 3
        ElseIf (OverviewRadioButton.Checked = True) Then
            selectedMode = 4
        End If

        'Determines Time Intervals
        If (FifteenRadioButton.Checked = True) Then
            timeInterval = 15
        ElseIf (ThirtyRadioButton.Checked = True) Then
            timeInterval = 30
        ElseIf (FortyFiveRadioButton.Checked = True) Then
            timeInterval = 45
        ElseIf (SixtyRadioButton.Checked = True) Then
            timeInterval = 60
        End If

        If (teamSize < 1) Then
            teamSize = 1
        End If

        'Setup information lists
        Dim TeamList As New List(Of Team)
        Dim unmatchedStudents As New List(Of Student)
        Dim timeSlots As New List(Of TimeNode)

        'Creates the teams and populates the list of teams
        For value As Integer = 0 To numTeams - 1
            Dim newTeam As New Team(value)
            TeamList.Add(newTeam)
        Next

        Dim tempTeam As Team
        Dim tempSkill As String
        'clears the error label to test if selection worked
        ErrorLabel.Text = ""
        Select Case selectedMode
            Case 0
                ErrorLabel.Text = "ERROR"
            Case 1
                'Competence Results
                'Sorts list based on skill, high to low
                studentList.Sort(Function(x, y) y.skillLevel.CompareTo(x.skillLevel))
                Dim teamNumber As Integer = 0
                For Each Student In studentList
                    teamNumber = teamNumber Mod numTeams
                    tempTeam = TeamList(teamNumber)
                    tempTeam.MembersList.Add(Student)
                    teamNumber += 1
                Next (Student)

                'Output to the file
                Dim filepath As String = "c:\student_scheduler\students\Results\"

                If (Not Directory.Exists(filepath)) Then
                    Directory.CreateDirectory(filepath)
                End If

                filepath = filepath & TeamsFileBox.Text & ".txt"

                If Not My.Computer.FileSystem.FileExists(filepath) Then
                    'Uses the file system to create the students file if it does not exist
                    Dim fs As FileStream = File.Create(filepath)
                    fs.Close()

                End If


                'Write to file without append. Change false to true for append.
                Dim fileSave As New IO.StreamWriter(filepath, False)


                For Each Team In TeamList
                    fileSave.WriteLine("Team " & Convert.ToString(Team.TeamNumber))
                    For Each Student In Team.MembersList
                        If (Student.skillLevel = Skill.HIGH) Then
                            tempSkill = "High"
                        ElseIf (Student.skillLevel = Skill.AVERAGE) Then
                            tempSkill = "Average"
                        Else
                            tempSkill = "Low"
                        End If
                        fileSave.WriteLine(Student.studentName & " - " & tempSkill)
                    Next
                    fileSave.WriteLine("")
                Next

                fileSave.Close()

            Case 2
                'Random Results
                'Sorts list based on randomID, high to low. IDs are assigned at random
                studentList.Sort(Function(x, y) y.randomID.CompareTo(x.randomID))
                Dim teamNumber As Integer = 0
                For Each Student In studentList
                    teamNumber = teamNumber Mod numTeams
                    tempTeam = TeamList(teamNumber)
                    tempTeam.MembersList.Add(Student)
                    teamNumber += 1
                Next (Student)

                'Output to the file
                Dim filepath As String = "c:\student_scheduler\students\Results\"

                If (Not Directory.Exists(filepath)) Then
                    Directory.CreateDirectory(filepath)
                End If

                filepath = filepath & TeamsFileBox.Text & ".txt"

                If Not My.Computer.FileSystem.FileExists(filepath) Then
                    'Uses the file system to create the students file if it does not exist
                    Dim fs As FileStream = File.Create(filepath)
                    fs.Close()

                End If


                'Write to file without append. Change false to true for append.
                Dim fileSave As New IO.StreamWriter(filepath, False)

                For Each Team In TeamList
                    fileSave.WriteLine("Team " & Convert.ToString(Team.TeamNumber))
                    For Each Student In Team.MembersList
                        If (Student.skillLevel = Skill.HIGH) Then
                            tempSkill = "High"
                        ElseIf (Student.skillLevel = Skill.AVERAGE) Then
                            tempSkill = "Average"
                        Else
                            tempSkill = "Low"
                        End If
                        fileSave.WriteLine(Student.studentName)
                    Next
                    fileSave.WriteLine("")
                Next

                fileSave.Close()
            Case 3
                'Time Match Results
            Case 4
                'Overview Results

        End Select




        'Sort list of students by skill

        'Create list of time interval nodes for the day, based on the selected time interval

        'Calculate number of teams and Create list of teams

        'Create list of students not belonging to a time

        'Assign students to Time Interval Nodes

        'Sweep over list of Interval Nodes, deleting nodes with zero students

        'Algorithm to assign teams

        'Save teams to file

        'Save non-team students to file





    End Sub

    
End Class
