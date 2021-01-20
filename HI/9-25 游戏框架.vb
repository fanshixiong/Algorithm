/*
1. 定义clsGame类，一个WithEvents事件ticker和Event HasChanged
2. Start
3. ticker_Tick, RaiseEvent HasChanged 
4. frmTest中game.HasChanged实现
*/
Public Class clsGame
    Private box As ClsBox
    Private ball As ClsBall
    Private WithEvents ticker As Timer
    Public Event HasChanged()

    Public Sub New()
        box = New ClsBox(200, 200, 200, 200)
        ball = New ClsBall(200, 200, 5, 1.2, 1.2)
        ticker = New Timer
        ticker.Interval = 100
        ticker.Enable = False
    End Sub
    Public Sub Start()
        ticker.Enable = True
    End Sub
    Private Sub ticker_Tick(Byval sender As Object, Byval e As System.EventArgs) Handles ticker.Tick
        ball.Move(box) //?
        RaiseEvent HasChanged()
    End Sub
    Public Sub Draw(ByVal g As Graphics) // ?
        ball.Draw(g)
        box.Draw(g)
    End Sub
End Class

Public Class frmTest
    Dim WithEvents game As clsGame
    Private Sub btnStart_click(Byval sender As Object, ByVal e As EventArgs) Handles btnStart_click
        game = New ClsGame
        game.start()
    End Sub
    Private Sub game_HasChanged() Handles game.HasChanged
        Dim g As Graphics = picCanvas.CreateGraphics()
        game.Draw(g)
    End Sub
End Class