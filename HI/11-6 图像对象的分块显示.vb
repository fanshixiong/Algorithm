/*
1. clsBitmap类中 Source，WithEvent：ticker， Event：changed
2. ticker.Tick 函数RaiseEvent Changed()
3. Slide: Target，wx，Pixel的获取和设置
4. frmTest类：WithEvents：bk， btn_click事件，Handles Changed事件
*/
Public Class clsBitmap
    Private Source As Bitmap
    Private WithEvents ticker As Timer
    Event Changed()
    Public Sub New(Byval fname As String, Byval Kind As SlideKind)
        Source = New Bitmap(fname)
        Ticker = New Timer
        Ticker.Interval = 1000 : Ticker.Enable = False
    End Sub
    Public Sub Start() 
        Ticker.Enable = True
    End Sub
    Public Sub Ticker_Tick(Byval sender As Object, Byval e As EventArgs) Handles Ticker.Tick
        wx = (wx + dx) Mod Source.Width
        RaiseEvent Changed()
    End Sub
    Public Function Slide() As Bitmap
        Dim Target As Bitmap(Source.Width, Source. Height)
        Dim xmax As Integer, ymax As Integer
        xmax = wx : ymax = Source.Height
        For i = 0 To xmax - 1
            For j = 0 To ymax - 1
                Dim c As Color = Source.GetPixel(i, j)
                Target.setPixel(i, j, c)
            Next
        Next
        Return Target
    End Function 
End Class

Public Class frmTest
    Dim WithEvents bk As clsBitmap
    Private Sub gameStart_click(Byval sender As Object, Byval e As EventsArgs) Handles gameStart.Click
        bk = New clsBitmap("bk.jpg")
        bk.Start()
    End Sub
    Private Sub bk_Changed() Handles bk.Changed
        picCanvas.Image = bk.Slide()
    End Sub
End Class