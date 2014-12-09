<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class SchedulerForm
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.StudentListBox = New System.Windows.Forms.ListBox()
        Me.StudentNameLabel = New System.Windows.Forms.Label()
        Me.TimesListBox = New System.Windows.Forms.ListBox()
        Me.NameTextBox = New System.Windows.Forms.TextBox()
        Me.LowSkillRadio = New System.Windows.Forms.RadioButton()
        Me.HighSkillRadio = New System.Windows.Forms.RadioButton()
        Me.UpdateStudentButton = New System.Windows.Forms.Button()
        Me.NewStudentButton = New System.Windows.Forms.Button()
        Me.AddTimeButton = New System.Windows.Forms.Button()
        Me.ClearTimeButton = New System.Windows.Forms.Button()
        Me.StartTimeTextBox = New System.Windows.Forms.TextBox()
        Me.StartLabel = New System.Windows.Forms.Label()
        Me.EndTimeTextBox = New System.Windows.Forms.TextBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.RemoveButton = New System.Windows.Forms.Button()
        Me.CalculateButton = New System.Windows.Forms.Button()
        Me.GroupSizeLabel = New System.Windows.Forms.Label()
        Me.TimeIntervalLabel = New System.Windows.Forms.Label()
        Me.GroupSizeTextBox = New System.Windows.Forms.TextBox()
        Me.IntervalTextBox = New System.Windows.Forms.TextBox()
        Me.SaveFileLabel = New System.Windows.Forms.Label()
        Me.TeamsFileBox = New System.Windows.Forms.TextBox()
        Me.DotTXTLabel = New System.Windows.Forms.Label()
        Me.SkillGroupBox = New System.Windows.Forms.GroupBox()
        Me.AverageRadioButton = New System.Windows.Forms.RadioButton()
        Me.TimeControlsGroupBox = New System.Windows.Forms.GroupBox()
        Me.StudentControlsGroupBox = New System.Windows.Forms.GroupBox()
        Me.ModeGroupBox = New System.Windows.Forms.GroupBox()
        Me.TimeMatchRadioButton = New System.Windows.Forms.RadioButton()
        Me.RandomRadioButton = New System.Windows.Forms.RadioButton()
        Me.CompetenceRadioButton = New System.Windows.Forms.RadioButton()
        Me.OverviewRadioButton = New System.Windows.Forms.RadioButton()
        Me.ErrorLabel = New System.Windows.Forms.Label()
        Me.SkillGroupBox.SuspendLayout()
        Me.TimeControlsGroupBox.SuspendLayout()
        Me.StudentControlsGroupBox.SuspendLayout()
        Me.ModeGroupBox.SuspendLayout()
        Me.SuspendLayout()
        '
        'StudentListBox
        '
        Me.StudentListBox.FormattingEnabled = True
        Me.StudentListBox.Location = New System.Drawing.Point(209, 12)
        Me.StudentListBox.Name = "StudentListBox"
        Me.StudentListBox.Size = New System.Drawing.Size(200, 108)
        Me.StudentListBox.TabIndex = 1
        '
        'StudentNameLabel
        '
        Me.StudentNameLabel.AutoSize = True
        Me.StudentNameLabel.Location = New System.Drawing.Point(12, 12)
        Me.StudentNameLabel.Name = "StudentNameLabel"
        Me.StudentNameLabel.Size = New System.Drawing.Size(38, 13)
        Me.StudentNameLabel.TabIndex = 2
        Me.StudentNameLabel.Text = "Name "
        '
        'TimesListBox
        '
        Me.TimesListBox.FormattingEnabled = True
        Me.TimesListBox.Location = New System.Drawing.Point(15, 240)
        Me.TimesListBox.Name = "TimesListBox"
        Me.TimesListBox.Size = New System.Drawing.Size(170, 95)
        Me.TimesListBox.TabIndex = 4
        '
        'NameTextBox
        '
        Me.NameTextBox.Location = New System.Drawing.Point(56, 12)
        Me.NameTextBox.Name = "NameTextBox"
        Me.NameTextBox.Size = New System.Drawing.Size(129, 20)
        Me.NameTextBox.TabIndex = 5
        '
        'LowSkillRadio
        '
        Me.LowSkillRadio.AutoSize = True
        Me.LowSkillRadio.Location = New System.Drawing.Point(6, 66)
        Me.LowSkillRadio.Name = "LowSkillRadio"
        Me.LowSkillRadio.Size = New System.Drawing.Size(45, 17)
        Me.LowSkillRadio.TabIndex = 6
        Me.LowSkillRadio.TabStop = True
        Me.LowSkillRadio.Text = "Low"
        Me.LowSkillRadio.UseVisualStyleBackColor = True
        '
        'HighSkillRadio
        '
        Me.HighSkillRadio.AutoSize = True
        Me.HighSkillRadio.Location = New System.Drawing.Point(6, 19)
        Me.HighSkillRadio.Name = "HighSkillRadio"
        Me.HighSkillRadio.Size = New System.Drawing.Size(47, 17)
        Me.HighSkillRadio.TabIndex = 7
        Me.HighSkillRadio.TabStop = True
        Me.HighSkillRadio.Text = "High"
        Me.HighSkillRadio.UseVisualStyleBackColor = True
        '
        'UpdateStudentButton
        '
        Me.UpdateStudentButton.Location = New System.Drawing.Point(6, 19)
        Me.UpdateStudentButton.Name = "UpdateStudentButton"
        Me.UpdateStudentButton.Size = New System.Drawing.Size(150, 23)
        Me.UpdateStudentButton.TabIndex = 8
        Me.UpdateStudentButton.Text = "Update Student"
        Me.UpdateStudentButton.UseVisualStyleBackColor = True
        '
        'NewStudentButton
        '
        Me.NewStudentButton.Location = New System.Drawing.Point(6, 48)
        Me.NewStudentButton.Name = "NewStudentButton"
        Me.NewStudentButton.Size = New System.Drawing.Size(150, 23)
        Me.NewStudentButton.TabIndex = 10
        Me.NewStudentButton.Text = "&Add New Student"
        Me.NewStudentButton.UseVisualStyleBackColor = True
        '
        'AddTimeButton
        '
        Me.AddTimeButton.Location = New System.Drawing.Point(6, 19)
        Me.AddTimeButton.Name = "AddTimeButton"
        Me.AddTimeButton.Size = New System.Drawing.Size(157, 23)
        Me.AddTimeButton.TabIndex = 11
        Me.AddTimeButton.Text = "Add Time"
        Me.AddTimeButton.UseVisualStyleBackColor = True
        '
        'ClearTimeButton
        '
        Me.ClearTimeButton.Location = New System.Drawing.Point(6, 68)
        Me.ClearTimeButton.Name = "ClearTimeButton"
        Me.ClearTimeButton.Size = New System.Drawing.Size(157, 23)
        Me.ClearTimeButton.TabIndex = 12
        Me.ClearTimeButton.Text = "Clear Time"
        Me.ClearTimeButton.UseVisualStyleBackColor = True
        '
        'StartTimeTextBox
        '
        Me.StartTimeTextBox.Location = New System.Drawing.Point(38, 42)
        Me.StartTimeTextBox.Name = "StartTimeTextBox"
        Me.StartTimeTextBox.Size = New System.Drawing.Size(40, 20)
        Me.StartTimeTextBox.TabIndex = 13
        '
        'StartLabel
        '
        Me.StartLabel.AutoSize = True
        Me.StartLabel.Location = New System.Drawing.Point(3, 45)
        Me.StartLabel.Name = "StartLabel"
        Me.StartLabel.Size = New System.Drawing.Size(29, 13)
        Me.StartLabel.TabIndex = 14
        Me.StartLabel.Text = "Start"
        '
        'EndTimeTextBox
        '
        Me.EndTimeTextBox.Location = New System.Drawing.Point(116, 42)
        Me.EndTimeTextBox.Name = "EndTimeTextBox"
        Me.EndTimeTextBox.Size = New System.Drawing.Size(47, 20)
        Me.EndTimeTextBox.TabIndex = 15
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(84, 45)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(26, 13)
        Me.Label1.TabIndex = 16
        Me.Label1.Text = "End"
        '
        'RemoveButton
        '
        Me.RemoveButton.Location = New System.Drawing.Point(6, 77)
        Me.RemoveButton.Name = "RemoveButton"
        Me.RemoveButton.Size = New System.Drawing.Size(150, 23)
        Me.RemoveButton.TabIndex = 17
        Me.RemoveButton.Text = "&Remove Student"
        Me.RemoveButton.UseVisualStyleBackColor = True
        '
        'CalculateButton
        '
        Me.CalculateButton.Location = New System.Drawing.Point(209, 240)
        Me.CalculateButton.Name = "CalculateButton"
        Me.CalculateButton.Size = New System.Drawing.Size(200, 23)
        Me.CalculateButton.TabIndex = 18
        Me.CalculateButton.Text = "&Calculate Teams"
        Me.CalculateButton.UseVisualStyleBackColor = True
        '
        'GroupSizeLabel
        '
        Me.GroupSizeLabel.AutoSize = True
        Me.GroupSizeLabel.Location = New System.Drawing.Point(206, 272)
        Me.GroupSizeLabel.Name = "GroupSizeLabel"
        Me.GroupSizeLabel.Size = New System.Drawing.Size(59, 13)
        Me.GroupSizeLabel.TabIndex = 19
        Me.GroupSizeLabel.Text = "Group Size"
        '
        'TimeIntervalLabel
        '
        Me.TimeIntervalLabel.AutoSize = True
        Me.TimeIntervalLabel.Location = New System.Drawing.Point(206, 297)
        Me.TimeIntervalLabel.Name = "TimeIntervalLabel"
        Me.TimeIntervalLabel.Size = New System.Drawing.Size(68, 13)
        Me.TimeIntervalLabel.TabIndex = 20
        Me.TimeIntervalLabel.Text = "Time Interval"
        '
        'GroupSizeTextBox
        '
        Me.GroupSizeTextBox.Location = New System.Drawing.Point(283, 269)
        Me.GroupSizeTextBox.Name = "GroupSizeTextBox"
        Me.GroupSizeTextBox.Size = New System.Drawing.Size(126, 20)
        Me.GroupSizeTextBox.TabIndex = 21
        '
        'IntervalTextBox
        '
        Me.IntervalTextBox.Location = New System.Drawing.Point(283, 294)
        Me.IntervalTextBox.Name = "IntervalTextBox"
        Me.IntervalTextBox.Size = New System.Drawing.Size(126, 20)
        Me.IntervalTextBox.TabIndex = 22
        '
        'SaveFileLabel
        '
        Me.SaveFileLabel.AutoSize = True
        Me.SaveFileLabel.Location = New System.Drawing.Point(206, 322)
        Me.SaveFileLabel.Name = "SaveFileLabel"
        Me.SaveFileLabel.Size = New System.Drawing.Size(51, 13)
        Me.SaveFileLabel.TabIndex = 23
        Me.SaveFileLabel.Text = "Save File"
        '
        'TeamsFileBox
        '
        Me.TeamsFileBox.Location = New System.Drawing.Point(283, 319)
        Me.TeamsFileBox.Name = "TeamsFileBox"
        Me.TeamsFileBox.Size = New System.Drawing.Size(99, 20)
        Me.TeamsFileBox.TabIndex = 24
        '
        'DotTXTLabel
        '
        Me.DotTXTLabel.AutoSize = True
        Me.DotTXTLabel.Location = New System.Drawing.Point(388, 322)
        Me.DotTXTLabel.Name = "DotTXTLabel"
        Me.DotTXTLabel.Size = New System.Drawing.Size(21, 13)
        Me.DotTXTLabel.TabIndex = 25
        Me.DotTXTLabel.Text = ".txt"
        '
        'SkillGroupBox
        '
        Me.SkillGroupBox.Controls.Add(Me.AverageRadioButton)
        Me.SkillGroupBox.Controls.Add(Me.HighSkillRadio)
        Me.SkillGroupBox.Controls.Add(Me.LowSkillRadio)
        Me.SkillGroupBox.Location = New System.Drawing.Point(15, 34)
        Me.SkillGroupBox.Name = "SkillGroupBox"
        Me.SkillGroupBox.Size = New System.Drawing.Size(170, 86)
        Me.SkillGroupBox.TabIndex = 26
        Me.SkillGroupBox.TabStop = False
        Me.SkillGroupBox.Text = "Skill"
        '
        'AverageRadioButton
        '
        Me.AverageRadioButton.AutoSize = True
        Me.AverageRadioButton.Location = New System.Drawing.Point(6, 43)
        Me.AverageRadioButton.Name = "AverageRadioButton"
        Me.AverageRadioButton.Size = New System.Drawing.Size(65, 17)
        Me.AverageRadioButton.TabIndex = 8
        Me.AverageRadioButton.TabStop = True
        Me.AverageRadioButton.Text = "Average"
        Me.AverageRadioButton.UseVisualStyleBackColor = True
        '
        'TimeControlsGroupBox
        '
        Me.TimeControlsGroupBox.Controls.Add(Me.AddTimeButton)
        Me.TimeControlsGroupBox.Controls.Add(Me.StartLabel)
        Me.TimeControlsGroupBox.Controls.Add(Me.StartTimeTextBox)
        Me.TimeControlsGroupBox.Controls.Add(Me.Label1)
        Me.TimeControlsGroupBox.Controls.Add(Me.EndTimeTextBox)
        Me.TimeControlsGroupBox.Controls.Add(Me.ClearTimeButton)
        Me.TimeControlsGroupBox.Location = New System.Drawing.Point(15, 126)
        Me.TimeControlsGroupBox.Name = "TimeControlsGroupBox"
        Me.TimeControlsGroupBox.Size = New System.Drawing.Size(170, 106)
        Me.TimeControlsGroupBox.TabIndex = 27
        Me.TimeControlsGroupBox.TabStop = False
        Me.TimeControlsGroupBox.Text = "Time Controls"
        '
        'StudentControlsGroupBox
        '
        Me.StudentControlsGroupBox.Controls.Add(Me.UpdateStudentButton)
        Me.StudentControlsGroupBox.Controls.Add(Me.NewStudentButton)
        Me.StudentControlsGroupBox.Controls.Add(Me.RemoveButton)
        Me.StudentControlsGroupBox.Location = New System.Drawing.Point(209, 126)
        Me.StudentControlsGroupBox.Name = "StudentControlsGroupBox"
        Me.StudentControlsGroupBox.Size = New System.Drawing.Size(200, 106)
        Me.StudentControlsGroupBox.TabIndex = 28
        Me.StudentControlsGroupBox.TabStop = False
        Me.StudentControlsGroupBox.Text = "Student Controls"
        '
        'ModeGroupBox
        '
        Me.ModeGroupBox.Controls.Add(Me.OverviewRadioButton)
        Me.ModeGroupBox.Controls.Add(Me.TimeMatchRadioButton)
        Me.ModeGroupBox.Controls.Add(Me.RandomRadioButton)
        Me.ModeGroupBox.Controls.Add(Me.CompetenceRadioButton)
        Me.ModeGroupBox.Location = New System.Drawing.Point(431, 12)
        Me.ModeGroupBox.Name = "ModeGroupBox"
        Me.ModeGroupBox.Size = New System.Drawing.Size(200, 108)
        Me.ModeGroupBox.TabIndex = 29
        Me.ModeGroupBox.TabStop = False
        Me.ModeGroupBox.Text = "Mode Select"
        '
        'TimeMatchRadioButton
        '
        Me.TimeMatchRadioButton.AutoSize = True
        Me.TimeMatchRadioButton.Location = New System.Drawing.Point(7, 64)
        Me.TimeMatchRadioButton.Name = "TimeMatchRadioButton"
        Me.TimeMatchRadioButton.Size = New System.Drawing.Size(95, 17)
        Me.TimeMatchRadioButton.TabIndex = 2
        Me.TimeMatchRadioButton.TabStop = True
        Me.TimeMatchRadioButton.Text = "Time Matching"
        Me.TimeMatchRadioButton.UseVisualStyleBackColor = True
        '
        'RandomRadioButton
        '
        Me.RandomRadioButton.AutoSize = True
        Me.RandomRadioButton.Location = New System.Drawing.Point(7, 41)
        Me.RandomRadioButton.Name = "RandomRadioButton"
        Me.RandomRadioButton.Size = New System.Drawing.Size(65, 17)
        Me.RandomRadioButton.TabIndex = 1
        Me.RandomRadioButton.TabStop = True
        Me.RandomRadioButton.Text = "Random"
        Me.RandomRadioButton.UseVisualStyleBackColor = True
        '
        'CompetenceRadioButton
        '
        Me.CompetenceRadioButton.AutoSize = True
        Me.CompetenceRadioButton.Location = New System.Drawing.Point(7, 20)
        Me.CompetenceRadioButton.Name = "CompetenceRadioButton"
        Me.CompetenceRadioButton.Size = New System.Drawing.Size(85, 17)
        Me.CompetenceRadioButton.TabIndex = 0
        Me.CompetenceRadioButton.TabStop = True
        Me.CompetenceRadioButton.Text = "Competence"
        Me.CompetenceRadioButton.UseVisualStyleBackColor = True
        '
        'OverviewRadioButton
        '
        Me.OverviewRadioButton.AutoSize = True
        Me.OverviewRadioButton.Location = New System.Drawing.Point(7, 85)
        Me.OverviewRadioButton.Name = "OverviewRadioButton"
        Me.OverviewRadioButton.Size = New System.Drawing.Size(117, 17)
        Me.OverviewRadioButton.TabIndex = 3
        Me.OverviewRadioButton.TabStop = True
        Me.OverviewRadioButton.Text = "Time Slot Overview"
        Me.OverviewRadioButton.UseVisualStyleBackColor = True
        '
        'ErrorLabel
        '
        Me.ErrorLabel.AutoSize = True
        Me.ErrorLabel.Location = New System.Drawing.Point(431, 240)
        Me.ErrorLabel.Name = "ErrorLabel"
        Me.ErrorLabel.Size = New System.Drawing.Size(0, 13)
        Me.ErrorLabel.TabIndex = 30
        '
        'SchedulerForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(639, 351)
        Me.Controls.Add(Me.ErrorLabel)
        Me.Controls.Add(Me.ModeGroupBox)
        Me.Controls.Add(Me.StudentControlsGroupBox)
        Me.Controls.Add(Me.TimeControlsGroupBox)
        Me.Controls.Add(Me.SkillGroupBox)
        Me.Controls.Add(Me.DotTXTLabel)
        Me.Controls.Add(Me.TeamsFileBox)
        Me.Controls.Add(Me.SaveFileLabel)
        Me.Controls.Add(Me.IntervalTextBox)
        Me.Controls.Add(Me.GroupSizeTextBox)
        Me.Controls.Add(Me.TimeIntervalLabel)
        Me.Controls.Add(Me.GroupSizeLabel)
        Me.Controls.Add(Me.CalculateButton)
        Me.Controls.Add(Me.NameTextBox)
        Me.Controls.Add(Me.TimesListBox)
        Me.Controls.Add(Me.StudentNameLabel)
        Me.Controls.Add(Me.StudentListBox)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle
        Me.Name = "SchedulerForm"
        Me.Text = "Student Scheduler"
        Me.SkillGroupBox.ResumeLayout(False)
        Me.SkillGroupBox.PerformLayout()
        Me.TimeControlsGroupBox.ResumeLayout(False)
        Me.TimeControlsGroupBox.PerformLayout()
        Me.StudentControlsGroupBox.ResumeLayout(False)
        Me.ModeGroupBox.ResumeLayout(False)
        Me.ModeGroupBox.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents StudentListBox As System.Windows.Forms.ListBox
    Friend WithEvents StudentNameLabel As System.Windows.Forms.Label
    Friend WithEvents TimesListBox As System.Windows.Forms.ListBox
    Friend WithEvents NameTextBox As System.Windows.Forms.TextBox
    Friend WithEvents LowSkillRadio As System.Windows.Forms.RadioButton
    Friend WithEvents HighSkillRadio As System.Windows.Forms.RadioButton
    Friend WithEvents UpdateStudentButton As System.Windows.Forms.Button
    Friend WithEvents NewStudentButton As System.Windows.Forms.Button
    Friend WithEvents AddTimeButton As System.Windows.Forms.Button
    Friend WithEvents ClearTimeButton As System.Windows.Forms.Button
    Friend WithEvents StartTimeTextBox As System.Windows.Forms.TextBox
    Friend WithEvents StartLabel As System.Windows.Forms.Label
    Friend WithEvents EndTimeTextBox As System.Windows.Forms.TextBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents RemoveButton As System.Windows.Forms.Button
    Friend WithEvents CalculateButton As System.Windows.Forms.Button
    Friend WithEvents GroupSizeLabel As System.Windows.Forms.Label
    Friend WithEvents TimeIntervalLabel As System.Windows.Forms.Label
    Friend WithEvents GroupSizeTextBox As System.Windows.Forms.TextBox
    Friend WithEvents IntervalTextBox As System.Windows.Forms.TextBox
    Friend WithEvents SaveFileLabel As System.Windows.Forms.Label
    Friend WithEvents TeamsFileBox As System.Windows.Forms.TextBox
    Friend WithEvents DotTXTLabel As System.Windows.Forms.Label
    Friend WithEvents SkillGroupBox As System.Windows.Forms.GroupBox
    Friend WithEvents AverageRadioButton As System.Windows.Forms.RadioButton
    Friend WithEvents TimeControlsGroupBox As System.Windows.Forms.GroupBox
    Friend WithEvents StudentControlsGroupBox As System.Windows.Forms.GroupBox
    Friend WithEvents ModeGroupBox As System.Windows.Forms.GroupBox
    Friend WithEvents TimeMatchRadioButton As System.Windows.Forms.RadioButton
    Friend WithEvents RandomRadioButton As System.Windows.Forms.RadioButton
    Friend WithEvents CompetenceRadioButton As System.Windows.Forms.RadioButton
    Friend WithEvents OverviewRadioButton As System.Windows.Forms.RadioButton
    Friend WithEvents ErrorLabel As System.Windows.Forms.Label

End Class
