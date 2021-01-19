/*
1. frmTest: WithEvents Bitmap, WithEvents Worker, btnSave_Click(), Worker_DoWorker()
2.          setProgessRange() --> deleSetProgessBegin() --> Bitmaps_SaveBegin() -> SaveBegin()
            setProgessValue() --> deleSetProgessValue() --> Bitmaps_SaveProgess() -> SaveProgress()
            setProgessEnd()   --> deleSetProgessEnd()   --> Bitmaps_SaveEnd() ->SaveEnd()
3. clsBitmap: bitmaps (List), Event SaveBegin(), SaveProgess(), SaveEnd()
                Save()
*/
Public Class frmTest
    Dim WithEvents Bitmaps As clsBitmap
    Dim WithEvents Worker As BackgroundWorker

    Private Sub btnOpen_Click(Byval sender As Object, Buval e As EventsArgs) Handles btnOpen.Click
        Bitmaps = New clsBitmap("1.jpg")
    End Sub
    Private Sub btnSave_Click(Byval sender As Object, Buval e As EventsArgs) Handles btnSave.Click
        Worker = New BackgroundWorker
        Worker.RunWorkerAsync(True)
    End Sub
    Private Sub Worker_DoWorker(Byval sender As Object, Buval e As DoWorkerEventsArgs) Handles Worker.DoWorker
        Bitmaps.Save()
    End Sub
    Delegate Sub deleSetProgessBegin(Byval min As Integer, Byval max As Integer)
    Delegate Sub deleSetProgessValue(Byval value As Integer)
    Delegate Sub deleSetProgessEnd()
    Private Sub SetProgessRange(Byval min As Integer, Byval max As Integer)
        pbProgess1.Min = min : pbProgess1.Max = Max
        pbProgess1.value = min
        btnSave.Enable = False
    End Sub
    Private Sub SetProgessValue(value As Integer)
        pbProgess1.value = value
    End Sub
    Private Sub SetProgessEnd()
        pbProgess1.value = pbProgess1.Min
        btnSave.Enable = True
    End Sub

    Public Sub Bitmaps_SaveBegin(ByVal max As Integer) Handles Bitmaps.SaveBegin
        Dim f As deleSetProgessBegin = New deleSetProgessBegin(AddressOf SetProgessRange)
        Invoke(f, {0, max})
    End Sub
    Public Sub Bitmaps_SaveProgess(ByVal value As Integer) Handles Bitmaps.SaveProgess
        Dim f As deleSetProgessValue = New deleSetProgessValue(AddressOf SetProgessValue)
        invoke(f, {value})
    End Sub
    Public Sub Bitmaps_SaveEnd() Handles Bitmaps.SaveEnd
        Dim f = deleSetProgessEnd = New deleSetProgessEnd
        invoke(f)
    End Sub
End Class

Public Class clsBitmap
    Private Bitmaps As List(Of Bitmap)
    Event SaveBegin(ByVal max As Integer)
    Event SaveProgess(ByVal value As Integer)
    Event SaveEnd()

    Public Sub Save(Byval path as String)
        RaiseEvent SaveBegin(N)
        For i = 0 To N - 1:
            Bitmaps(i).Save(path & "xy" & i & ".bmp", Imaging.ImageFormat.Bmp)
            RaiseEvent SaveProgess(i)
        Next
        RaiseEvent SaveEnd()
    End Sub
End Class