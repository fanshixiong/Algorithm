/*
1. 在clsBitmap类中定义成员变量source As Bitmap ，构造函数New中赋值
2. Gray中定义Bitmap类型Target赋值source，Color类型的c从GetPixel(), newc从Color.FromArgb改变透明度
*/
Public Class clsBitmap
    Private source As Bitmap
    // ?
    Public Sub New(Byval fname As String)
        source = New Bitmap(fname)
    End Sub
    // ?
    Public Function Gray() As Bitmap
        Dim Target As New Bitmap(Source)
        For i = 0 To Target.width - 1
            For j = 0 To Target.height - 1
                Dim c As Color = Target.getPixel(i, j)
                Dim Newc As Color = Color.FromArgb(60, c)
                Target.SetPixel(i, j, c)
            Next
        Next
        Return Target
    End Function
End Class