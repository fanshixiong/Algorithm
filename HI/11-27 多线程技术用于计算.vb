/*
1. clsWorkA: Delegate Sub AppendMessage, para, ReportProgress, Worker, frmOut, Event WorkerComplete
             Run(), DoWorker(), Complete()
2. frmTest: worker(clsWorkA), startBtn_Click(), WorkerComplete(), AppendMessage()
*/
Public Class clsWorkA
    Delegate Sub AppendMessage(Byval id As Integer, Byval msg As String)
    Private para As WorkPara
    Private Worker As BackgroundWorker
    Private frmOut As frmTest
    Private ReportProgress As AppendMessage
    Public Event WorkerComplete(result As WorkerResult)

    Public Sub New(para As WorkerPara, frmOut As frmTest)
        Me.para = para : Me.frmOut = frmOut
        Me.Worker = New BackgroundWorker
        AddHandle Worker.DoWorker, AddressOf DoWorker
        AddHandle Worker.RunWorkerCompleted, AddressOf Completed
        Me.ReportProgree = New AppendMessage(AddressOf frmOut.AppendMessage)
    End Sub
    Public Sub Run()
        Me.Worker.RunWorkerAsync(para)
    End Sub
    Private Sub DoWorker(sender As Object, e As DoWorkerEventArgs)
        Dim sum As Integer = 0
        For k = 0 To 2000
            For i = para.n1 To para.n2
                sum += 1
            Next

            frmOut.Invoke(ReportProgress, para.id, sum.ToString & vbTab & k)
        Next
        Dim result As WorkerResult
        result.id = para.id : result.sum = sum
        e.Result = result
    End Sub
    Private Sub Complete(sender As Object, e As RunWorkerCompletedEventArgs)
        Dim result As WorkerResult = e.Result
        RaiseEvent WorkerComplete(result)
    End Sub
End Class

Public Class frmTest
    Private Worker As clsWorkA
    Private Sub startBtn_Click(sender As Object, e As EventArgs) Handles startBtn.Click
        Dim para As WorkerPara
        para.id = 1 : para.n1 = 1 : para.n2 = 100
        Me.Worker = New clsWorkA(para, Me)
        AddHandle Me.Worker.WorkerComplete, AddressOf WorkerComplete
        Me.Worker.Run()
    End Sub
    Public Sub WorkerComplete(result As WorkerResult)
        lstProgress1.Items.Add(result.sum)
    End Sub
    Public Sub AppendMessage(id As Integer, msg As String)
        lstProgress1.Items.Add(msg)
        lstProgress1.SelectedIndex = lstProgress1.Items.Count - 1
    End Sub
End Class
