/*
1. 声明MustInherit类clsElem，声明MustOverride函数Draw
2. 定义clsLine继承clsElem，重写Draw方法
3. 定义clsCircle继承clsElement，重写Draw方法
4. 测试类frmTest中，编写picCanvasMouseDown和picCanvasMouseUp委托事件，将状态(圆或者线)对象添加到Elems中
*/

Public MustInherit Class clsElem
    MustOverride Sub Draw(Byval g As Graphics)
End Class

public Class clsCircle
    Inherit clsElem
    Private cp As Point, r As Single
    Public Overrides Sub Draw(Byval g As System.Drawing.Graphics)
        g.DrawEllipse(Pens.Blue, cp.X - r, cp.Y - r, r, r) // 五个参数
    End Sub
End Class

public Class clsLine
    Inherit clsElem
    Private sp As Point, ep As Point
    Public Overrides Sub Draw(Byval g As System.Drawing.Graphics)
        g.drawLine(Pens.Blue, sp, ep)
    End Sub
End Class

public Class clsElems
    Private elems As List(Of clsElem)
    Public Sub Draw(Byval g As Graphics)
        for i = 0 To elems.count - 1
            elems(i).draw(g)
        Next
    End Sub
End Class

Public Class frmTest
    Dim Elems As List(Of clsElem)
    Dim sp As Point, state As Integer
    Private Sub picCanvas_MouseDown(ByVal sender As Object, ByVal e As MouseEventsArgs) Handles picCanvas.MouseDown
        sp = e.Location
    End Sub

    Private Sub picCanvas_MouseUp(Byval sender As Object, ByVal e As MouseEventsArgs) Handles picCanvasMouseUp
        Dim ep As Point = e.Location
        Dim elem As ClsElem = Nothing
        If rbLine.Checked = True Then
            elem = New clsLine(sp, ep)
        End If
        if rbCircle.Checked = True Then
            Dim dx As Integer = ep.X - sp.X, dy  As Integer = ep.Y - sp.Y
            Dim r As Single = Sqrt(dx * dx, dy * dy)
            elem = New clsCircle(sp, r)
        End If
        Elems.Append(elem)
    End Sub
End Class

Public MustInherit Class clsElem
    MustOverride Sub Draw(g As Graphics)
End Class
Public Class clsLine
    Inherit clsElem
    Private sp As Point, ep As Point
    Public Overrides Sub Draw (g As Graphics)
        g.drawLine(Pens.Blue, sp, ep)
    End Sub
End Class

Public Class clsElems
    Private elems As List(Of clsElem)
    Public Sub Draw(g As Graphics)
        For i = 0 To elems.Count - 1
            elems(i).Draw(g)
        Next
    End Sub
End Class

Public Class frmTest
    Dim elems As List(Of clsElem)
    Dim sp As Point
    Public Sub picCanvas_MouseDown(sender As Object, e As MouseEventsArgs) Handles picCanvas.MouseDown
        sp = e.Location
    End Sub
    Public Sub picCanvas_MouseUp(sender As Object, e MouseEventsArgs) Handles picCanvas.MouseUp
        Dim ep As point = e.Location
        Dim elem As clsElem
        If rbLine.Checked = True Then 
            elem = New clsLine(sp, ep)
        End If
        If rbCircle.Checked = True Then 
            Dim r As Single = Sqrt((ep.X - sp. X) * (ep.X - sp. X), (ep.y - sp. y) * (ep.y - sp. y))
            elem = New clsCircle(sp, r)
        End If
        elems.Append(elem)
    End Sub
End Class