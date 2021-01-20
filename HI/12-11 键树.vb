/*
1. Node
2. New: Content读取IO.FileStream(".txt", FileMode.Open)
        StreamReader(fs, System.Text.Encoding.Default)
        sr.ReadToEnd()

        separator() As Char{vbLf, vbCr} /// content.Split(separator, StringSplitOptions.RemoveEmptyEntries)
        InsertWord()
3. InsertWord: Asc(word(i))
*/
Public Class clsKeyTree
    Class Node
        Public nextc() As Node
        Public Sub New()
            ReDim nextc(25)
        End Sub
    End Class

    Private Root As Node
    Public Sub New()
        Root = New Node
        Dim content As String
        Using fs As New IO.FileStream("Word.txt", FileMode.Open)
            Using sr As New StreamReader(fs, System.Text.Encoding.Default)
                content = sr.ReadToEnd()
            End Using
        End Using
        Dim separator() As Char = {vbLf, vbCr}
        Dim Words() As String = content.Split(separator, StringSplitOptions.RemoveEmptyEntries)
        For i = 0 To Words.Count - 1
            InsertWord(Words(i).ToLower) // tolower
        Next
    End Sub

    Private Sub InsertWord(Byval word As String)
        Dim p As Node = Root
        For i = 0 To word.Count - 1
            Dim f As Integer = Asc(word(i)) - Asc("a")
            If p.nextc(f) is Nothing Then p.nextc(f) = New Node
            p = nextc(f)
        Next
    End Sub
End Class