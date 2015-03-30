<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class AddSalutationForm
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
        Me.SalutationNameLabel = New System.Windows.Forms.Label()
        Me.SalNameTextBox = New System.Windows.Forms.TextBox()
        Me.SalTextBox = New System.Windows.Forms.TextBox()
        Me.SalutationLabel = New System.Windows.Forms.Label()
        Me.OKButton = New System.Windows.Forms.Button()
        Me.CancelAddButton = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'SalutationNameLabel
        '
        Me.SalutationNameLabel.AutoSize = True
        Me.SalutationNameLabel.Location = New System.Drawing.Point(13, 13)
        Me.SalutationNameLabel.Name = "SalutationNameLabel"
        Me.SalutationNameLabel.Size = New System.Drawing.Size(85, 13)
        Me.SalutationNameLabel.TabIndex = 0
        Me.SalutationNameLabel.Text = "Salutation Name"
        '
        'SalNameTextBox
        '
        Me.SalNameTextBox.Location = New System.Drawing.Point(117, 13)
        Me.SalNameTextBox.Name = "SalNameTextBox"
        Me.SalNameTextBox.Size = New System.Drawing.Size(119, 20)
        Me.SalNameTextBox.TabIndex = 1
        '
        'SalTextBox
        '
        Me.SalTextBox.Location = New System.Drawing.Point(117, 40)
        Me.SalTextBox.Name = "SalTextBox"
        Me.SalTextBox.Size = New System.Drawing.Size(119, 20)
        Me.SalTextBox.TabIndex = 2
        '
        'SalutationLabel
        '
        Me.SalutationLabel.AutoSize = True
        Me.SalutationLabel.Location = New System.Drawing.Point(13, 40)
        Me.SalutationLabel.Name = "SalutationLabel"
        Me.SalutationLabel.Size = New System.Drawing.Size(54, 13)
        Me.SalutationLabel.TabIndex = 3
        Me.SalutationLabel.Text = "Salutation"
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
        'AddSalutationForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(247, 93)
        Me.Controls.Add(Me.CancelAddButton)
        Me.Controls.Add(Me.OKButton)
        Me.Controls.Add(Me.SalutationLabel)
        Me.Controls.Add(Me.SalTextBox)
        Me.Controls.Add(Me.SalNameTextBox)
        Me.Controls.Add(Me.SalutationNameLabel)
        Me.Name = "AddSalutationForm"
        Me.Text = "Add Salutation"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents SalutationNameLabel As System.Windows.Forms.Label
    Friend WithEvents SalNameTextBox As System.Windows.Forms.TextBox
    Friend WithEvents SalTextBox As System.Windows.Forms.TextBox
    Friend WithEvents SalutationLabel As System.Windows.Forms.Label
    Friend WithEvents OKButton As System.Windows.Forms.Button
    Friend WithEvents CancelAddButton As System.Windows.Forms.Button
End Class
