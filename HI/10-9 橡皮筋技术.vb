/*
1. 全都是Handles处理的事件
2. 当LeftMouseDown左键按下才执行
3. MouseMove中判断lastElem事件，用多态清除以前的画面
*/
Public Class frmTest
    Dim Elems As clsElems
    Dim sp As Point, lastElem As clsElem
    Dim LeftMouseDown As Boolean

    Private Sub frmTest_Load(ByVal sender As System.Object, ByVal e As EventsArgs) Handles MyBase.Load
        Elems = New clsElems
        LeftMouseDown = False
    End Sub
    Private Sub picCanvas_MouseDown(Byval sender As Object, ByVal e As MouseEventsArgs) Handles picCanvas.MouseDown
        sp = e.Location
        LeftMouseDown = True
        lastElem = new clsLine(sp, ep)
    End Sub
    Private Sub picCanvas_MouseMove(Byval sender As Object, ByVal e As MouseEventsArgs) Handles picCanvas.MouseMove
        If LeftMouseDown = False Then Return
        Dim g As Graphics = picCanvas.CreateGraphics()
        Dim ep = e.Location
        If lastElem IsNot Nothing Then
            lastElem.Draw(g, Pens.White)
        End If
        lastElem = New clsLine(sp, ep)
        lastElem.Draw(g)
    End Sub
    Private Sub picCanvas_MouseUp(Byval sender As Object, ByVal e As MouseEventsArgs) Handles picCanvas.MouseUp
        LeftMouseDown = False
        ep = e.Location
        Dim elem As clsElem = New clsLine(sp, ep)
        Elems.Append(lastElem)
    End Sub
End Class