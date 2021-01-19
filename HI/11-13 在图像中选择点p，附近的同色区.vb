/*
1. Target, visited, Queue
2. 广度优先遍历
3. RaiseEvent(Target)
*/
Sub SelectRegion(Byval p As Point)
    Target = New Bitmap(Source)
    Dim visited(Source.Width, Source.Height) As Boolean
    For i = 0 To Source.width
        For j = 0 To Source.Height
            visited(i, j) = False
        Next
    Next

    Dim c As Color = Source.GetPixel(p.X, p.Y)
    Dim Q As New Queue(Of Point)
    Q.Enqueue(p) : visited(p.X, p.Y) = True
    While Q.Count > 0:
        p = Q.Dequeue()
        Target.SetPixel(p.X, P.y, Colors.Red) //
        Dim p1 As New Point(p.X-1, p.y), c1 = Target.GetPixel(p1.X, p1.Y)
        Dim p2 As New Point(p.X, p.y-1), c2 = Target.GetPixel(p2.X, p2.Y)
        Dim p3 As New Point(p.X, p.y+1), c3 = Target.GetPixel(p3.X, p3.Y)
        Dim p4 As New Point(p.X+1, p.y), c4 = Target.GetPixel(p4.X, p4.Y)

        If c1 = c And visited(p1.X, p1.Y) = False Then Q.Enqueue(p1) : visited(p1.X, p1.Y) = True
        If c2 = c And visited(p2.X, p2.Y) = False Then Q.Enqueue(p2) : visited(p2.X, p2.Y) = True
        If c3 = c And visited(p3.X, p3.Y) = False Then Q.Enqueue(p3) : visited(p3.X, p3.Y) = True
        If c4 = c And visited(p4.X, p4.Y) = False Then Q.Enqueue(p4) : visited(p4.X, p4.Y) = True
    End While
    RaiseEvent Changed(Target) //
End Sub