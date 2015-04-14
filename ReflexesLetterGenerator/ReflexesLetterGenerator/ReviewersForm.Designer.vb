<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class ReviewersForm
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
        Me.ReviewerListBox = New System.Windows.Forms.ListBox()
        Me.AddReviewerButton = New System.Windows.Forms.Button()
        Me.DeleteReviewerButton = New System.Windows.Forms.Button()
        Me.EditReviewerButton = New System.Windows.Forms.Button()
        Me.OKButton = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'ReviewerListBox
        '
        Me.ReviewerListBox.FormattingEnabled = True
        Me.ReviewerListBox.Location = New System.Drawing.Point(13, 13)
        Me.ReviewerListBox.Name = "ReviewerListBox"
        Me.ReviewerListBox.Size = New System.Drawing.Size(259, 95)
        Me.ReviewerListBox.TabIndex = 0
        '
        'AddReviewerButton
        '
        Me.AddReviewerButton.Location = New System.Drawing.Point(12, 114)
        Me.AddReviewerButton.Name = "AddReviewerButton"
        Me.AddReviewerButton.Size = New System.Drawing.Size(120, 23)
        Me.AddReviewerButton.TabIndex = 1
        Me.AddReviewerButton.Text = "Add"
        Me.AddReviewerButton.UseVisualStyleBackColor = True
        '
        'DeleteReviewerButton
        '
        Me.DeleteReviewerButton.Location = New System.Drawing.Point(12, 143)
        Me.DeleteReviewerButton.Name = "DeleteReviewerButton"
        Me.DeleteReviewerButton.Size = New System.Drawing.Size(120, 23)
        Me.DeleteReviewerButton.TabIndex = 2
        Me.DeleteReviewerButton.Text = "Delete"
        Me.DeleteReviewerButton.UseVisualStyleBackColor = False
        '
        'EditReviewerButton
        '
        Me.EditReviewerButton.Location = New System.Drawing.Point(138, 114)
        Me.EditReviewerButton.Name = "EditReviewerButton"
        Me.EditReviewerButton.Size = New System.Drawing.Size(134, 23)
        Me.EditReviewerButton.TabIndex = 3
        Me.EditReviewerButton.Text = "Edit"
        Me.EditReviewerButton.UseVisualStyleBackColor = True
        '
        'OKButton
        '
        Me.OKButton.Location = New System.Drawing.Point(138, 143)
        Me.OKButton.Name = "OKButton"
        Me.OKButton.Size = New System.Drawing.Size(134, 23)
        Me.OKButton.TabIndex = 4
        Me.OKButton.Text = "OK"
        Me.OKButton.UseVisualStyleBackColor = True
        '
        'ReviewersForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(284, 169)
        Me.Controls.Add(Me.OKButton)
        Me.Controls.Add(Me.EditReviewerButton)
        Me.Controls.Add(Me.DeleteReviewerButton)
        Me.Controls.Add(Me.AddReviewerButton)
        Me.Controls.Add(Me.ReviewerListBox)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D
        Me.MaximizeBox = False
        Me.MinimizeBox = False
        Me.Name = "ReviewersForm"
        Me.Text = "Reviewer Options"
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents ReviewerListBox As System.Windows.Forms.ListBox
    Friend WithEvents AddReviewerButton As System.Windows.Forms.Button
    Friend WithEvents DeleteReviewerButton As System.Windows.Forms.Button
    Friend WithEvents EditReviewerButton As System.Windows.Forms.Button
    Friend WithEvents OKButton As System.Windows.Forms.Button
End Class
