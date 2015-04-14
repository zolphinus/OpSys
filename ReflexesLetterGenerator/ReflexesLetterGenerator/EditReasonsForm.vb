Public Class EditReasonsForm
    Dim EditReasonsList As List(Of ReflexesForm.Reason) = Nothing
    Dim index As Integer

    Sub New(ByRef ReasonsList As List(Of ReflexesForm.Reason), ByVal tempIndex As Integer)
        InitializeComponent()
        EditReasonsList = ReasonsList
        index = tempIndex

    End Sub

    Private Sub EditReasonsForm_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

    End Sub
End Class