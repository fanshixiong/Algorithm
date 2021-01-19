/*
1. 定义clsElem MustInherit和MustOverride SelectPoint
2. clsElems中判断每个clsElem是否被选中，RaiseEvent ChangedSelected事件
3. frmTest中实现ChangedSelected事件，和鼠标移动事件选择SelectPoint
*/
Public MustInherit Class clsElem
    MustOverride Bool Function SelectByPoint(Byval p As Point)
End Class
Public Class clsLine
    Inherit clsElem
End Class
Public Class clsCircle
    Inferit clsElem
End Class

Public Class clsElems
    Private Elems As List(Of clsElem)
    Event ChangedSelected(e As clsElem) //参数
    Sub SelectByPoint (Byval p As Point)
        For i = 0 To Elems.Count - 1
            If Elems(i).SelectByPoint(p) = True Then
                RaiseEvent ChangedSelected(Elems(i))
                Exit Sub
            End If
        Next
    End Sub
    Sub Draw()
        draw()
    End Sub
End Class
Public Class frmTest
    Dim WithEvents Elems As clsElems
    Private Sub picCanvas_MouseDown(Byval sender As Object, Byval e As MouseEventsArgs) Handles picCanvas.MouseDown
        Elems.SelectByPoint(e.Location)
    End Sub
    Private Sub ElemsDraw(e As clsElem) Handles Elems.ChangedSelected
        Dim g As Graphics = picCanvas.CreateGraphics()
        Elems.Draw(g)
    End Sub
End Class