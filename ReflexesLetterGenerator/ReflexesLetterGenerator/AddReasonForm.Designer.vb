<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class AddReasonForm
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
        Me.ReasonTitleTextBox = New System.Windows.Forms.TextBox()
        Me.OKButton = New System.Windows.Forms.Button()
        Me.CancelAddButton = New System.Windows.Forms.Button()
        Me.ReasonTextBox = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'ReviewerNameLabel
        '
        Me.ReviewerNameLabel.AutoSize = True
        Me.ReviewerNameLabel.Location = New System.Drawing.Point(13, 13)
        Me.ReviewerNameLabel.Name = "ReviewerNameLabel"
        Me.ReviewerNameLabel.Size = New System.Drawing.Size(67, 13)
        Me.ReviewerNameLabel.TabIndex = 0
        Me.ReviewerNameLabel.Text = "Reason Title"
        '
        'ReasonTitleTextBox
        '
        Me.ReasonTitleTextBox.Location = New System.Drawing.Point(117, 13)
        Me.ReasonTitleTextBox.Name = "ReasonTitleTextBox"
        Me.ReasonTitleTextBox.Size = New System.Drawing.Size(118, 20)
        Me.ReasonTitleTextBox.TabIndex = 1
        '
        'OKButton
        '
        Me.OKButton.Location = New System.Drawing.Point(16, 286)
        Me.OKButton.Name = "OKButton"
        Me.OKButton.Size = New System.Drawing.Size(100, 23)
        Me.OKButton.TabIndex = 4
        Me.OKButton.Text = "Ok"
        Me.OKButton.UseVisualStyleBackColor = True
        '
        'CancelAddButton
        '
        Me.CancelAddButton.Location = New System.Drawing.Point(136, 286)
        Me.CancelAddButton.Name = "CancelAddButton"
        Me.CancelAddButton.Size = New System.Drawing.Size(99, 23)
        Me.CancelAddButton.TabIndex = 5
        Me.CancelAddButton.Text = "Cancel"
        Me.CancelAddButton.UseVisualStyleBackColor = True
        '
        'ReasonTextBox
        '
        Me.ReasonTextBox.AcceptsReturn = True
        Me.ReasonTextBox.AcceptsTab = True
        Me.ReasonTextBox.Location = New System.Drawing.Point(16, 50)
        Me.ReasonTextBox.Multiline = True
        Me.ReasonTextBox.Name = "ReasonTextBox"
        Me.ReasonTextBox.Size = New System.Drawing.Size(219, 230)
        Me.ReasonTextBox.TabIndex = 7
        '
        'AddReasonForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(253, 318)
        Me.Controls.Add(Me.ReasonTextBox)
        Me.Controls.Add(Me.CancelAddButton)
        Me.Controls.Add(Me.OKButton)
        Me.Controls.Add(Me.ReasonTitleTextBox)
        Me.Controls.Add(Me.ReviewerNameLabel)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle
        Me.MaximizeBox = False
        Me.MinimizeBox = False
        Me.Name = "AddReasonForm"
        Me.Text = "Add Reason"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents ReviewerNameLabel As System.Windows.Forms.Label
    Friend WithEvents ReasonTitleTextBox As System.Windows.Forms.TextBox
    Friend WithEvents OKButton As System.Windows.Forms.Button
    Friend WithEvents CancelAddButton As System.Windows.Forms.Button
    Friend WithEvents ReasonTextBox As System.Windows.Forms.TextBox
End Class
