/*
1. WithEvents Watcher As FileSystemWatcher
2. frmTest_load: New初始化
3. deleCreateFile --> opCreate --> Watcher_Create --> CreateFile
   deleRemoveFile --> opRemove --> Watcher_Deleted --> removeFile
   deleRenameFile --> opRename --> Watcher_Renamed --> renameFile
*/
Public Class frmTest
    Public WithEvents Watcher As FileSystemWacher
    Delegate Sub deleCreateFile(fname As String)
    Delegate Sub deleRemoveFile(fname As String)
    Delegate Sub DeleRenameFile(oname As String, nname As String)

    Dim opCreate As deleCreateFile
    Dim opRemove As deleRemoveFile
    Dim opRename As DeleRenameFile

    Private Sub frmTest_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        opCreate = New deleCreateFile(AddressOf Me.CreateFile)
        opRemove = New deleRemoveFile(AddressOf Me.RemoveFile)
        opRename = New DeleRenameFile(AddressOf Me.RenameFile)
    End Sub

    Private Sub Watcher_Created(sender As Object, e As EventArgs) Handles Watcher.Create
        Invoke(opCreate, e.FullPath)
    End Sub
    Private Sub CreateFile(fname As String)
        lstFile.Items.Add(fname)
    End Sub
    Private Sub Watcher_Deleted(sender As Object, e As EventArgs) Handles Watcher.Deleted
        Invoke(opRemove, e.FullPath)
    End Sub
    Private Sub removeFile(fname As String)
        lstFile.Items.Remove(fname)
    End Sub
    Private Sub Watcher_Renamed(sender As Object, e As EventArgs) Handles Watcher.Renamed
        Dim oname As String = e.OldFullPath
        Dim nname As String = e.FullPath
        invoke(opRename, New String(){oname, nname})
    End Sub
    Private Sub RenameFile(oname As String, nname As String)
        Dim k As Integer = lstFile.Items.IndexOf(oname)
        lstFile.Items(k) = nname
    End Sub
End Class