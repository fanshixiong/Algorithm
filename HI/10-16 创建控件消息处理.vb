/*
1. clsButton 定义x, y, k, btn是System.Windos.Forms.Button
2. btn 的position  size name text 赋值 定义AddHandle btn.click Address btn_click
3. btnCreate_click 创建5个btn， 将btns加入Controls中
*/
Public Class clsBtn
    Private Const width As Integer = 50
    Public Btn As System.Windows.Forms.Button
    Private x As Integer, y As Integer
    Private k As Integer

    Sub New (Byval x As Integer, Byval y As Integer, Byval k As Integer)
        Btn = New System.Windows.Forms.Button()
        Btn.Location = New System.Drawing.Point(x, y)
        Btn.Size = New System.Drawing.Size(width, width)
        Btn.Name = "MyBtn" & k
        Btn.Text = k
        AddHandle Btn.Click, AddressOf Btn_Click
    End Sub
    Private Sub Btn_Click(Byval sender As Object, Byval e As EventArgs)
        Dim it As Button = sender
        MsgBox(it.Name)
    End Sub
End Class
Public Class frmTest
    Dim Btns As List(Of clsBtn)
    Private Sub btnCreate_Click(Byval sender As Object, Byval e As EventArgs) Handles btnCreate.Click
        Btns = New List(Of clsBtn)
        For i = 0 To 5
            Btns.Add(New clsBtn(100 + i * 60, 100, i))
        Next

        For i = 0 To Btns.Count - 1
            Controls.Add(Btns(i).Btn)
        Next
    End Sub
End Class

Public Class clsBtn
    Private Btns As System.Forms.Button
    x, y, k
    Public Sub New(x, y, k)
        btns = New System.Forms.Button
        Btns.Name = "j"&k
        Btns.Text = k
        AddHandle btns.Click, AddressOf btns_Click
    End Sub
    Public Sub btns_Click(sender, e)
        Dim it As Button = sender
        MsgBox(it.Text)
    End Sub
End Class
Public Class frmTest
    Dim btns As List(Of clsBtn)
    Private Sub btnCreate_Click(Byval sender As Object, Byval e As EventArgs) Handles btnCreate.Click
        For i = 0 To 5
            btns.Add(New clsBtn(20, 22, i))
        Next
        For i = 0 To 5
            Controls.Add(btns(i).Btns)
        Next
    End Sub
End Class