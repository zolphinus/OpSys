<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class ReasonsForm
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
        Me.ReasonsListBox = New System.Windows.Forms.ListBox()
        Me.AddReasonsButton = New System.Windows.Forms.Button()
        Me.DeleteReasonsButton = New System.Windows.Forms.Button()
        Me.EditReasonsButton = New System.Windows.Forms.Button()
        Me.OKButton = New System.Windows.Forms.Button()
        Me.ReasonTextBox = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'ReasonsListBox
        '
        Me.ReasonsListBox.FormattingEnabled = True
        Me.ReasonsListBox.Location = New System.Drawing.Point(12, 12)
        Me.ReasonsListBox.Name = "ReasonsListBox"
        Me.ReasonsListBox.Size = New System.Drawing.Size(219, 56)
        Me.ReasonsListBox.TabIndex = 0
        '
        'AddReasonsButton
        '
        Me.AddReasonsButton.Location = New System.Drawing.Point(12, 255)
        Me.AddReasonsButton.Name = "AddReasonsButton"
        Me.AddReasonsButton.Size = New System.Drawing.Size(101, 23)
        Me.AddReasonsButton.TabIndex = 1
        Me.AddReasonsButton.Text = "Add"
        Me.AddReasonsButton.UseVisualStyleBackColor = True
        '
        'DeleteReasonsButton
        '
        Me.DeleteReasonsButton.Location = New System.Drawing.Point(12, 285)
        Me.DeleteReasonsButton.Name = "DeleteReasonsButton"
        Me.DeleteReasonsButton.Size = New System.Drawing.Size(101, 23)
        Me.DeleteReasonsButton.TabIndex = 2
        Me.DeleteReasonsButton.Text = "Delete"
        Me.DeleteReasonsButton.UseVisualStyleBackColor = False
        '
        'EditReasonsButton
        '
        Me.EditReasonsButton.Location = New System.Drawing.Point(128, 255)
        Me.EditReasonsButton.Name = "EditReasonsButton"
        Me.EditReasonsButton.Size = New System.Drawing.Size(103, 23)
        Me.EditReasonsButton.TabIndex = 3
        Me.EditReasonsButton.Text = "Edit"
        Me.EditReasonsButton.UseVisualStyleBackColor = True
        '
        'OKButton
        '
        Me.OKButton.Location = New System.Drawing.Point(128, 285)
        Me.OKButton.Name = "OKButton"
        Me.OKButton.Size = New System.Drawing.Size(103, 23)
        Me.OKButton.TabIndex = 4
        Me.OKButton.Text = "OK"
        Me.OKButton.UseVisualStyleBackColor = True
        '
        'ReasonTextBox
        '
        Me.ReasonTextBox.AcceptsReturn = True
        Me.ReasonTextBox.AcceptsTab = True
        Me.ReasonTextBox.Location = New System.Drawing.Point(12, 74)
        Me.ReasonTextBox.Multiline = True
        Me.ReasonTextBox.Name = "ReasonTextBox"
        Me.ReasonTextBox.ReadOnly = True
        Me.ReasonTextBox.Size = New System.Drawing.Size(219, 175)
        Me.ReasonTextBox.TabIndex = 6
        '
        'ReasonsForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(244, 320)
        Me.Controls.Add(Me.ReasonTextBox)
        Me.Controls.Add(Me.OKButton)
        Me.Controls.Add(Me.EditReasonsButton)
        Me.Controls.Add(Me.DeleteReasonsButton)
        Me.Controls.Add(Me.AddReasonsButton)
        Me.Controls.Add(Me.ReasonsListBox)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D
        Me.MaximizeBox = False
        Me.MinimizeBox = False
        Me.Name = "ReasonsForm"
        Me.Text = "Reviewer Options"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents ReasonsListBox As System.Windows.Forms.ListBox
    Friend WithEvents AddReasonsButton As System.Windows.Forms.Button
    Friend WithEvents DeleteReasonsButton As System.Windows.Forms.Button
    Friend WithEvents EditReasonsButton As System.Windows.Forms.Button
    Friend WithEvents OKButton As System.Windows.Forms.Button
    Friend WithEvents ReasonTextBox As System.Windows.Forms.TextBox
End Class
