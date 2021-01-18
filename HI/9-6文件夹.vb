/* 
1. New: 定义files和dirs  给dirs赋值folders
2. Output: 将files加入到lstInfo中，递归dirs
3. Depth: 递归计算
4. FilesCount: 计算files的count 递归计算dirs中的count 
5. Search: 计算files的中满足的，递归计算dirs中的
*/
Public class clsDirs
    Private files() As String
    Private dirs() As clsDirs

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

        Return max
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
            If files(i).count(pattern) = True Then
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