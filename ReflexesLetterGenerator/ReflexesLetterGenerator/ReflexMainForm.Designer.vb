<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class ReflexesForm
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
        Me.RecipientLabel = New System.Windows.Forms.Label()
        Me.RecipientNameTextBox = New System.Windows.Forms.TextBox()
        Me.ReasonLabel = New System.Windows.Forms.Label()
        Me.SalutationsLabel = New System.Windows.Forms.Label()
        Me.ReasonComboBox = New System.Windows.Forms.ComboBox()
        Me.SalutationComboBox = New System.Windows.Forms.ComboBox()
        Me.ReviewerLabel = New System.Windows.Forms.Label()
        Me.ReviewerComboBox = New System.Windows.Forms.ComboBox()
        Me.EditReasonsButton = New System.Windows.Forms.Button()
        Me.EditSalutationsButton = New System.Windows.Forms.Button()
        Me.EditReviewersButton = New System.Windows.Forms.Button()
        Me.SaveLetterButton = New System.Windows.Forms.Button()
        Me.EditReviewers = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'RecipientLabel
        '
        Me.RecipientLabel.AutoSize = True
        Me.RecipientLabel.Location = New System.Drawing.Point(15, 13)
        Me.RecipientLabel.Name = "RecipientLabel"
        Me.RecipientLabel.Size = New System.Drawing.Size(52, 13)
        Me.RecipientLabel.TabIndex = 0
        Me.RecipientLabel.Text = "Recipient"
        '
        'RecipientNameTextBox
        '
        Me.RecipientNameTextBox.Location = New System.Drawing.Point(120, 13)
        Me.RecipientNameTextBox.Name = "RecipientNameTextBox"
        Me.RecipientNameTextBox.Size = New System.Drawing.Size(172, 20)
        Me.RecipientNameTextBox.TabIndex = 1
        '
        'ReasonLabel
        '
        Me.ReasonLabel.AutoSize = True
        Me.ReasonLabel.Location = New System.Drawing.Point(15, 40)
        Me.ReasonLabel.Name = "ReasonLabel"
        Me.ReasonLabel.Size = New System.Drawing.Size(44, 13)
        Me.ReasonLabel.TabIndex = 3
        Me.ReasonLabel.Text = "Reason"
        '
        'SalutationsLabel
        '
        Me.SalutationsLabel.AutoSize = True
        Me.SalutationsLabel.Location = New System.Drawing.Point(15, 67)
        Me.SalutationsLabel.Name = "SalutationsLabel"
        Me.SalutationsLabel.Size = New System.Drawing.Size(54, 13)
        Me.SalutationsLabel.TabIndex = 6
        Me.SalutationsLabel.Text = "Salutation"
        '
        'ReasonComboBox
        '
        Me.ReasonComboBox.FormattingEnabled = True
        Me.ReasonComboBox.Location = New System.Drawing.Point(120, 40)
        Me.ReasonComboBox.Name = "ReasonComboBox"
        Me.ReasonComboBox.Size = New System.Drawing.Size(172, 21)
        Me.ReasonComboBox.TabIndex = 7
        '
        'SalutationComboBox
        '
        Me.SalutationComboBox.FormattingEnabled = True
        Me.SalutationComboBox.Location = New System.Drawing.Point(120, 67)
        Me.SalutationComboBox.Name = "SalutationComboBox"
        Me.SalutationComboBox.Size = New System.Drawing.Size(172, 21)
        Me.SalutationComboBox.TabIndex = 8
        '
        'ReviewerLabel
        '
        Me.ReviewerLabel.AutoSize = True
        Me.ReviewerLabel.Location = New System.Drawing.Point(15, 95)
        Me.ReviewerLabel.Name = "ReviewerLabel"
        Me.ReviewerLabel.Size = New System.Drawing.Size(52, 13)
        Me.ReviewerLabel.TabIndex = 9
        Me.ReviewerLabel.Text = "Reviewer"
        '
        'ReviewerComboBox
        '
        Me.ReviewerComboBox.FormattingEnabled = True
        Me.ReviewerComboBox.Location = New System.Drawing.Point(120, 95)
        Me.ReviewerComboBox.Name = "ReviewerComboBox"
        Me.ReviewerComboBox.Size = New System.Drawing.Size(172, 21)
        Me.ReviewerComboBox.TabIndex = 10
        '
        'EditReasonsButton
        '
        Me.EditReasonsButton.Location = New System.Drawing.Point(18, 124)
        Me.EditReasonsButton.Name = "EditReasonsButton"
        Me.EditReasonsButton.Size = New System.Drawing.Size(136, 23)
        Me.EditReasonsButton.TabIndex = 11
        Me.EditReasonsButton.Text = "Edit Reasons"
        Me.EditReasonsButton.UseVisualStyleBackColor = True
        '
        'EditSalutationsButton
        '
        Me.EditSalutationsButton.Location = New System.Drawing.Point(156, 124)
        Me.EditSalutationsButton.Name = "EditSalutationsButton"
        Me.EditSalutationsButton.Size = New System.Drawing.Size(136, 23)
        Me.EditSalutationsButton.TabIndex = 12
        Me.EditSalutationsButton.Text = "Edit Salutations"
        Me.EditSalutationsButton.UseVisualStyleBackColor = True
        '
        'EditReviewersButton
        '
        Me.EditReviewersButton.Location = New System.Drawing.Point(18, 153)
        Me.EditReviewersButton.Name = "EditReviewersButton"
        Me.EditReviewersButton.Size = New System.Drawing.Size(136, 23)
        Me.EditReviewersButton.TabIndex = 13
        Me.EditReviewersButton.Text = "Edit Reviewers"
        Me.EditReviewersButton.UseVisualStyleBackColor = True
        '
        'SaveLetterButton
        '
        Me.SaveLetterButton.Location = New System.Drawing.Point(156, 153)
        Me.SaveLetterButton.Name = "SaveLetterButton"
        Me.SaveLetterButton.Size = New System.Drawing.Size(136, 23)
        Me.SaveLetterButton.TabIndex = 14
        Me.SaveLetterButton.Text = "Save Letter"
        Me.SaveLetterButton.UseVisualStyleBackColor = True
        '
        'EditReviewers
        '
        Me.EditReviewers.Location = New System.Drawing.Point(18, 153)
        Me.EditReviewers.Name = "EditReviewers"
        Me.EditReviewers.Size = New System.Drawing.Size(136, 23)
        Me.EditReviewers.TabIndex = 13
        Me.EditReviewers.Text = "Edit Reviewers"
        Me.EditReviewers.UseVisualStyleBackColor = True
        '
        'ReflexesForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(304, 185)
        Me.Controls.Add(Me.SaveLetterButton)
        Me.Controls.Add(Me.EditReviewersButton)
        Me.Controls.Add(Me.EditSalutationsButton)
        Me.Controls.Add(Me.EditReasonsButton)
        Me.Controls.Add(Me.ReviewerComboBox)
        Me.Controls.Add(Me.ReviewerLabel)
        Me.Controls.Add(Me.SalutationComboBox)
        Me.Controls.Add(Me.ReasonComboBox)
        Me.Controls.Add(Me.SalutationsLabel)
        Me.Controls.Add(Me.ReasonLabel)
        Me.Controls.Add(Me.RecipientNameTextBox)
        Me.Controls.Add(Me.RecipientLabel)
        Me.Name = "ReflexesForm"
        Me.Text = "Reflexes Letter Generator"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents RecipientLabel As System.Windows.Forms.Label
    Friend WithEvents RecipientNameTextBox As System.Windows.Forms.TextBox
    Friend WithEvents ReasonLabel As System.Windows.Forms.Label
    Friend WithEvents SalutationsLabel As System.Windows.Forms.Label
    Friend WithEvents ReasonComboBox As System.Windows.Forms.ComboBox
    Friend WithEvents SalutationComboBox As System.Windows.Forms.ComboBox
    Friend WithEvents ReviewerLabel As System.Windows.Forms.Label
    Friend WithEvents ReviewerComboBox As System.Windows.Forms.ComboBox
    Friend WithEvents EditReasonsButton As System.Windows.Forms.Button
    Friend WithEvents EditSalutationsButton As System.Windows.Forms.Button
    Friend WithEvents EditReviewersButton As System.Windows.Forms.Button
    Friend WithEvents SaveLetterButton As System.Windows.Forms.Button
    Friend WithEvents EditReviewers As System.Windows.Forms.Button

End Class
