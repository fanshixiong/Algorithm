/*
1. clsOple类MustInherit，MustOverride方法DoWork，UnDo
2. clsDeleteOp: length, deleteTxt,
3. clsInsertOp: newchars
4. clsUpdateOp: length, newTxt, oldTxt
5. clsOps: txt, Ops,  its, UnDo(), ReDo()
*/
Public MustInherit clsOp
    MustOverride Sub DoWork(Byval txt As TextBox) /// ?
    MustOverride Sub UnDo(Byval txt As TextBox)
End Class
Public Class clsDeleteOp
    Inherit clsOp
    Dim position As Integer, length As Integer
    Dim deleteTxt As String
    Public Overrides Sub DoWork(Byval txt As TextBox)
        Dim left As String = txt.Text.Substring(0, position)
        Dim right As String = txt.Text.Sunstring(position + lenth)
        txt.Text = left & right
    End Sub
    Public Overrides Sub UnDo(Byval txt As TextBox)
        Dim left As String = txt.Text.Substring(0, position)
        Dim right As String = txt.Text.Substring(position)
        txt.Text = left & deleteTxt & right
    End Sub
End Class
Public Class clsInsertOp
    Inherit clsOp
    Private position As integer
    Private newchars As String
    Public MustOverrides Sub DoWork(byval txt As TextBox)
        Dim left As String = txt.Text.Substring(0, position)
        Dim right As String = txt.Text.Sunstring(position)
        txt.Text = left & newchars & right
    End Sub
    Public MustOverrides Sub UnDo(Byval txt As TextBox)
        Dim left As String = txt.Text.Substring(0, position)
        Dim right As String = txt.Text.Substring(position + 1)
        txt.Text = left & right
    End Sub
End Class
Public Class clsUpdateOp
    Inherit clsOp
    Private position As integer, length As Integer
    Private oldtxt As String, newtxt As string
    Public MustOverrides Sub DoWork(byval txt As TextBox)
        Dim left As String = txt.Text.Substring(0, position)
        Dim right As String = txt.Text.Sunstring(position + length)
        txt.Text = left & newtxt & right
    End Sub
    Public MustOverrides Sub UnDo(Byval txt As TextBox)
        Dim left As String = txt.Text.Substring(0, position)
        Dim right As String = txt.Text.Substring(position + newtxt.Length)
        txt.Text = left & oldtxt & right
    End Sub
End Class

Public Class clsOps
    Private txt As TextBox
    Private Ops As List(Of clsOp)
    Private its As Integer
    Public sub Undo()
        If its = 0 Then Return
        Ops(its-1).UnDo(txt)
        its -= 1
    End Sub
    Public Sub ReDo()
        If its = Ops.Count Then Return
        Ops(its+1).DoWork(txt)
        its += 1
    End Sub
End Class