/* 
1. New: 定义files和dirs  给dirs赋值folders
2. Output: 将files加入到lstInfo中，递归dirs
3. Depth: 递归计算
4. FilesCount: 计算files的count 递归计算dirs中的count 
5. Search: 计算files的中满足的，递归计算dirs中的
*/
Public class clsDirs
    Private files() As String // 两个括号
    Private dirs() As clsDirs  // 类型clsDirs

    public Sub New(Byval path As String)
        files = Directory.GetFiles(path)
        Dim folders() As String = Directory.getDirectories(path)
        ReDim dirs(folders.count)
        for i = 0 To folders.count - 1
            dirs(i) = New clsDirs(folers(i))
        Next
    End Sub

    public Sub Output(Byval lstInfo As ListBox)
        for i = 0 To files.count - 1
            lstInfo.Items.Add(files(i))
        Next
        for i = 0 To dirs.count - 1
            dirs(i).Output(lstInfo)
        Next
    End Sub

    public Function Depth() As Integer
        Dim max As Integer = 0
        for i = 0 To dirs.count
            Dim d As Integer = dirs(i).Depth()
            If d > max Then max = d
        Next

        Return max + 1  // 1/+
    End Function

    public Function FilesCount() As Integer
        Dim cnt As Integer = files.count
        for i = 0 To dirs.count
            cnt += dirs(i).FilesCount()
        Next
        Return cnt
    End Function

    public Function Search(Byval pattern As String) As List(Of String)
        Dim res As List(Of String)
        for i = 0 To files.count - 1
            If files(i).contains(pattern) = True Then
                res.add(files(i))
            End If
        Next
        for i = 0 To dirs.count - 1
            Dim r As List(Of String) = dirs(i).Search(pattern)
            res.AddRange(r)
        Next
        Return res
    End Function
End Class

Public Class clsFile
    Private files As String
    Private dirs As List(Of clsFile)
    Public Sub New(path As String)
        files = Directory.getFile(path)
        Dim folders() As String = Directory.getDirectories(path) #
        Redim dirs(folders.Count)
        For i = 0 To folders.Count - 1
            dirs(i) = New clsFile(folders(i))
        Next
    End Sub
    Public Sub Output(lstInfo As ListBox)
        For i = 0 To files.Count - 1
            lstInfo.Items.Add(files(i))
        Next
        For i = 0 To dirs.Count - 1
            dirs(i).Output(lstInfo)
        Next
    End Sub
    Public Funciton Search(p As String) As List(Of String)
        Dim res As List(Of String)
        For i = 0 To files.Count - 1
            If files.Contains(p) = True Then res.Add(files(i))
        Next
        For i = 0 To dirs.Count - 1
            Dim r As List(Of String) = dirs(i).Search(p)
            res.AddRange(r)
        Next
        return res
    End Function
End Class

Public class clsdirs
    Dim files As String
    Dim dirs As clsdirs
    Public Sub New()
    End Sub
end class