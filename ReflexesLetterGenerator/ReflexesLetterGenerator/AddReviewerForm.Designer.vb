<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class AddReviewerForm
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
        Me.ReviewerNameLabel = New System.Windows.Forms.Label()
        Me.RevNameTextBox = New System.Windows.Forms.TextBox()
        Me.OKButton = New System.Windows.Forms.Button()
        Me.CancelAddButton = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'ReviewerNameLabel
        '
        Me.ReviewerNameLabel.AutoSize = True
        Me.ReviewerNameLabel.Location = New System.Drawing.Point(13, 13)
        Me.ReviewerNameLabel.Name = "ReviewerNameLabel"
        Me.ReviewerNameLabel.Size = New System.Drawing.Size(83, 13)
        Me.ReviewerNameLabel.TabIndex = 0
        Me.ReviewerNameLabel.Text = "Reviewer Name"
        '
        'RevNameTextBox
        '
        Me.RevNameTextBox.Location = New System.Drawing.Point(117, 13)
        Me.RevNameTextBox.Name = "RevNameTextBox"
        Me.RevNameTextBox.Size = New System.Drawing.Size(119, 20)
        Me.RevNameTextBox.TabIndex = 1
        '
        'OKButton
        '
        Me.OKButton.Location = New System.Drawing.Point(16, 66)
        Me.OKButton.Name = "OKButton"
        Me.OKButton.Size = New System.Drawing.Size(100, 23)
        Me.OKButton.TabIndex = 4
        Me.OKButton.Text = "Ok"
        Me.OKButton.UseVisualStyleBackColor = True
        '
        'CancelAddButton
        '
        Me.CancelAddButton.Location = New System.Drawing.Point(136, 66)
        Me.CancelAddButton.Name = "CancelAddButton"
        Me.CancelAddButton.Size = New System.Drawing.Size(100, 23)
        Me.CancelAddButton.TabIndex = 5
        Me.CancelAddButton.Text = "Cancel"
        Me.CancelAddButton.UseVisualStyleBackColor = True
        '
        'AddReviewerForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(247, 93)
        Me.Controls.Add(Me.CancelAddButton)
        Me.Controls.Add(Me.OKButton)
        Me.Controls.Add(Me.RevNameTextBox)
        Me.Controls.Add(Me.ReviewerNameLabel)
        Me.Name = "AddReviewerForm"
        Me.Text = "Add Salutation"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents ReviewerNameLabel As System.Windows.Forms.Label
    Friend WithEvents RevNameTextBox As System.Windows.Forms.TextBox
    Friend WithEvents OKButton As System.Windows.Forms.Button
    Friend WithEvents CancelAddButton As System.Windows.Forms.Button
End Class
