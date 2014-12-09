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
        Me.SkillLabel = New System.Windows.Forms.Label()
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
        Me.SuspendLayout()
        '
        'StudentListBox
        '
        Me.StudentListBox.FormattingEnabled = True
        Me.StudentListBox.Location = New System.Drawing.Point(12, 12)
        Me.StudentListBox.Name = "StudentListBox"
        Me.StudentListBox.Size = New System.Drawing.Size(200, 108)
        Me.StudentListBox.TabIndex = 1
        '
        'StudentNameLabel
        '
        Me.StudentNameLabel.AutoSize = True
        Me.StudentNameLabel.Location = New System.Drawing.Point(226, 12)
        Me.StudentNameLabel.Name = "StudentNameLabel"
        Me.StudentNameLabel.Size = New System.Drawing.Size(38, 13)
        Me.StudentNameLabel.TabIndex = 2
        Me.StudentNameLabel.Text = "Name "
        '
        'SkillLabel
        '
        Me.SkillLabel.AutoSize = True
        Me.SkillLabel.Location = New System.Drawing.Point(226, 34)
        Me.SkillLabel.Name = "SkillLabel"
        Me.SkillLabel.Size = New System.Drawing.Size(26, 13)
        Me.SkillLabel.TabIndex = 3
        Me.SkillLabel.Text = "Skill"
        '
        'TimesListBox
        '
        Me.TimesListBox.FormattingEnabled = True
        Me.TimesListBox.Location = New System.Drawing.Point(229, 57)
        Me.TimesListBox.Name = "TimesListBox"
        Me.TimesListBox.Size = New System.Drawing.Size(150, 95)
        Me.TimesListBox.TabIndex = 4
        '
        'NameTextBox
        '
        Me.NameTextBox.Location = New System.Drawing.Point(279, 12)
        Me.NameTextBox.Name = "NameTextBox"
        Me.NameTextBox.Size = New System.Drawing.Size(100, 20)
        Me.NameTextBox.TabIndex = 5
        '
        'LowSkillRadio
        '
        Me.LowSkillRadio.AutoSize = True
        Me.LowSkillRadio.Location = New System.Drawing.Point(279, 34)
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
        Me.HighSkillRadio.Location = New System.Drawing.Point(332, 34)
        Me.HighSkillRadio.Name = "HighSkillRadio"
        Me.HighSkillRadio.Size = New System.Drawing.Size(47, 17)
        Me.HighSkillRadio.TabIndex = 7
        Me.HighSkillRadio.TabStop = True
        Me.HighSkillRadio.Text = "High"
        Me.HighSkillRadio.UseVisualStyleBackColor = True
        '
        'UpdateStudentButton
        '
        Me.UpdateStudentButton.Location = New System.Drawing.Point(229, 240)
        Me.UpdateStudentButton.Name = "UpdateStudentButton"
        Me.UpdateStudentButton.Size = New System.Drawing.Size(150, 23)
        Me.UpdateStudentButton.TabIndex = 8
        Me.UpdateStudentButton.Text = "Update Student"
        Me.UpdateStudentButton.UseVisualStyleBackColor = True
        '
        'NewStudentButton
        '
        Me.NewStudentButton.Location = New System.Drawing.Point(229, 269)
        Me.NewStudentButton.Name = "NewStudentButton"
        Me.NewStudentButton.Size = New System.Drawing.Size(150, 23)
        Me.NewStudentButton.TabIndex = 10
        Me.NewStudentButton.Text = "&Add New Student"
        Me.NewStudentButton.UseVisualStyleBackColor = True
        '
        'AddTimeButton
        '
        Me.AddTimeButton.Location = New System.Drawing.Point(229, 158)
        Me.AddTimeButton.Name = "AddTimeButton"
        Me.AddTimeButton.Size = New System.Drawing.Size(150, 23)
        Me.AddTimeButton.TabIndex = 11
        Me.AddTimeButton.Text = "Add Time"
        Me.AddTimeButton.UseVisualStyleBackColor = True
        '
        'ClearTimeButton
        '
        Me.ClearTimeButton.Location = New System.Drawing.Point(229, 211)
        Me.ClearTimeButton.Name = "ClearTimeButton"
        Me.ClearTimeButton.Size = New System.Drawing.Size(150, 23)
        Me.ClearTimeButton.TabIndex = 12
        Me.ClearTimeButton.Text = "Clear Time"
        Me.ClearTimeButton.UseVisualStyleBackColor = True
        '
        'StartTimeTextBox
        '
        Me.StartTimeTextBox.Location = New System.Drawing.Point(259, 185)
        Me.StartTimeTextBox.Name = "StartTimeTextBox"
        Me.StartTimeTextBox.Size = New System.Drawing.Size(40, 20)
        Me.StartTimeTextBox.TabIndex = 13
        '
        'StartLabel
        '
        Me.StartLabel.AutoSize = True
        Me.StartLabel.Location = New System.Drawing.Point(226, 188)
        Me.StartLabel.Name = "StartLabel"
        Me.StartLabel.Size = New System.Drawing.Size(29, 13)
        Me.StartLabel.TabIndex = 14
        Me.StartLabel.Text = "Start"
        '
        'EndTimeTextBox
        '
        Me.EndTimeTextBox.Location = New System.Drawing.Point(332, 185)
        Me.EndTimeTextBox.Name = "EndTimeTextBox"
        Me.EndTimeTextBox.Size = New System.Drawing.Size(47, 20)
        Me.EndTimeTextBox.TabIndex = 15
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(305, 188)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(26, 13)
        Me.Label1.TabIndex = 16
        Me.Label1.Text = "End"
        '
        'RemoveButton
        '
        Me.RemoveButton.Location = New System.Drawing.Point(229, 299)
        Me.RemoveButton.Name = "RemoveButton"
        Me.RemoveButton.Size = New System.Drawing.Size(150, 23)
        Me.RemoveButton.TabIndex = 17
        Me.RemoveButton.Text = "&Remove Student"
        Me.RemoveButton.UseVisualStyleBackColor = True
        '
        'CalculateButton
        '
        Me.CalculateButton.Location = New System.Drawing.Point(12, 128)
        Me.CalculateButton.Name = "CalculateButton"
        Me.CalculateButton.Size = New System.Drawing.Size(200, 23)
        Me.CalculateButton.TabIndex = 18
        Me.CalculateButton.Text = "&Calculate Teams"
        Me.CalculateButton.UseVisualStyleBackColor = True
        '
        'GroupSizeLabel
        '
        Me.GroupSizeLabel.AutoSize = True
        Me.GroupSizeLabel.Location = New System.Drawing.Point(9, 163)
        Me.GroupSizeLabel.Name = "GroupSizeLabel"
        Me.GroupSizeLabel.Size = New System.Drawing.Size(59, 13)
        Me.GroupSizeLabel.TabIndex = 19
        Me.GroupSizeLabel.Text = "Group Size"
        '
        'TimeIntervalLabel
        '
        Me.TimeIntervalLabel.AutoSize = True
        Me.TimeIntervalLabel.Location = New System.Drawing.Point(9, 189)
        Me.TimeIntervalLabel.Name = "TimeIntervalLabel"
        Me.TimeIntervalLabel.Size = New System.Drawing.Size(68, 13)
        Me.TimeIntervalLabel.TabIndex = 20
        Me.TimeIntervalLabel.Text = "Time Interval"
        '
        'GroupSizeTextBox
        '
        Me.GroupSizeTextBox.Location = New System.Drawing.Point(86, 160)
        Me.GroupSizeTextBox.Name = "GroupSizeTextBox"
        Me.GroupSizeTextBox.Size = New System.Drawing.Size(126, 20)
        Me.GroupSizeTextBox.TabIndex = 21
        '
        'IntervalTextBox
        '
        Me.IntervalTextBox.Location = New System.Drawing.Point(86, 186)
        Me.IntervalTextBox.Name = "IntervalTextBox"
        Me.IntervalTextBox.Size = New System.Drawing.Size(126, 20)
        Me.IntervalTextBox.TabIndex = 22
        '
        'SaveFileLabel
        '
        Me.SaveFileLabel.AutoSize = True
        Me.SaveFileLabel.Location = New System.Drawing.Point(9, 215)
        Me.SaveFileLabel.Name = "SaveFileLabel"
        Me.SaveFileLabel.Size = New System.Drawing.Size(51, 13)
        Me.SaveFileLabel.TabIndex = 23
        Me.SaveFileLabel.Text = "Save File"
        '
        'TeamsFileBox
        '
        Me.TeamsFileBox.Location = New System.Drawing.Point(86, 212)
        Me.TeamsFileBox.Name = "TeamsFileBox"
        Me.TeamsFileBox.Size = New System.Drawing.Size(99, 20)
        Me.TeamsFileBox.TabIndex = 24
        '
        'DotTXTLabel
        '
        Me.DotTXTLabel.AutoSize = True
        Me.DotTXTLabel.Location = New System.Drawing.Point(191, 215)
        Me.DotTXTLabel.Name = "DotTXTLabel"
        Me.DotTXTLabel.Size = New System.Drawing.Size(21, 13)
        Me.DotTXTLabel.TabIndex = 25
        Me.DotTXTLabel.Text = ".txt"
        '
        'SchedulerForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(399, 330)
        Me.Controls.Add(Me.DotTXTLabel)
        Me.Controls.Add(Me.TeamsFileBox)
        Me.Controls.Add(Me.SaveFileLabel)
        Me.Controls.Add(Me.IntervalTextBox)
        Me.Controls.Add(Me.GroupSizeTextBox)
        Me.Controls.Add(Me.TimeIntervalLabel)
        Me.Controls.Add(Me.GroupSizeLabel)
        Me.Controls.Add(Me.CalculateButton)
        Me.Controls.Add(Me.RemoveButton)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.EndTimeTextBox)
        Me.Controls.Add(Me.StartLabel)
        Me.Controls.Add(Me.StartTimeTextBox)
        Me.Controls.Add(Me.ClearTimeButton)
        Me.Controls.Add(Me.AddTimeButton)
        Me.Controls.Add(Me.NewStudentButton)
        Me.Controls.Add(Me.UpdateStudentButton)
        Me.Controls.Add(Me.HighSkillRadio)
        Me.Controls.Add(Me.LowSkillRadio)
        Me.Controls.Add(Me.NameTextBox)
        Me.Controls.Add(Me.TimesListBox)
        Me.Controls.Add(Me.SkillLabel)
        Me.Controls.Add(Me.StudentNameLabel)
        Me.Controls.Add(Me.StudentListBox)
        Me.Name = "SchedulerForm"
        Me.Text = "Student Scheduler"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents StudentListBox As System.Windows.Forms.ListBox
    Friend WithEvents StudentNameLabel As System.Windows.Forms.Label
    Friend WithEvents SkillLabel As System.Windows.Forms.Label
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

End Class
