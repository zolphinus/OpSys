<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class SalutationsForm
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
        Me.SalutationListBox = New System.Windows.Forms.ListBox()
        Me.AddSalutationButton = New System.Windows.Forms.Button()
        Me.DeleteSalutationButton = New System.Windows.Forms.Button()
        Me.EditSalutationButton = New System.Windows.Forms.Button()
        Me.OKButton = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'SalutationListBox
        '
        Me.SalutationListBox.FormattingEnabled = True
        Me.SalutationListBox.Location = New System.Drawing.Point(13, 13)
        Me.SalutationListBox.Name = "SalutationListBox"
        Me.SalutationListBox.Size = New System.Drawing.Size(259, 95)
        Me.SalutationListBox.TabIndex = 0
        '
        'AddSalutationButton
        '
        Me.AddSalutationButton.Location = New System.Drawing.Point(12, 114)
        Me.AddSalutationButton.Name = "AddSalutationButton"
        Me.AddSalutationButton.Size = New System.Drawing.Size(120, 23)
        Me.AddSalutationButton.TabIndex = 1
        Me.AddSalutationButton.Text = "Add"
        Me.AddSalutationButton.UseVisualStyleBackColor = True
        '
        'DeleteSalutationButton
        '
        Me.DeleteSalutationButton.Location = New System.Drawing.Point(12, 143)
        Me.DeleteSalutationButton.Name = "DeleteSalutationButton"
        Me.DeleteSalutationButton.Size = New System.Drawing.Size(120, 23)
        Me.DeleteSalutationButton.TabIndex = 2
        Me.DeleteSalutationButton.Text = "Delete"
        Me.DeleteSalutationButton.UseVisualStyleBackColor = False
        '
        'EditSalutationButton
        '
        Me.EditSalutationButton.Location = New System.Drawing.Point(138, 114)
        Me.EditSalutationButton.Name = "EditSalutationButton"
        Me.EditSalutationButton.Size = New System.Drawing.Size(134, 23)
        Me.EditSalutationButton.TabIndex = 3
        Me.EditSalutationButton.Text = "Edit"
        Me.EditSalutationButton.UseVisualStyleBackColor = True
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
        'SalutationsForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(284, 169)
        Me.Controls.Add(Me.OKButton)
        Me.Controls.Add(Me.EditSalutationButton)
        Me.Controls.Add(Me.DeleteSalutationButton)
        Me.Controls.Add(Me.AddSalutationButton)
        Me.Controls.Add(Me.SalutationListBox)
        Me.Name = "SalutationsForm"
        Me.Text = "Salutation Options"
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents SalutationListBox As System.Windows.Forms.ListBox
    Friend WithEvents AddSalutationButton As System.Windows.Forms.Button
    Friend WithEvents DeleteSalutationButton As System.Windows.Forms.Button
    Friend WithEvents EditSalutationButton As System.Windows.Forms.Button
    Friend WithEvents OKButton As System.Windows.Forms.Button
End Class
