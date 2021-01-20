/*
  游戏框架类似
1. clsBox类 r, x, y
2. clsCell, clsFood, clsHead(dx, dy), clsSnake(head, body(List clsCell), )
3. clsSnake: head, body(List clsCell); Move(), Draw()
4. clsGame: WithEvents(ticker), Event(changed()), snake, gbox; Start(), ticker_Tick(Handles ticker.Tick) Draw()
5. frmTest: WithEvents(game(clsGame)), Handles Changed, load, btn_start()
*/
Public MustInherit Class clsBox
    Protected Shared r As Integer = 5
    Protected x As Integer, y As Integer
    Public MustOverride Sub Draw(Byval g As Graphics)
End Class

Public Class clsCell
    Inherit clsBox
    Public Overrides Sub Draw(Byval g As Graphics)
        g.DrawRectangle(Pens.Black, x-r, x-r, 2*r, 2*r)
    End Sub
End Class

Public Class clsFood
    Inherit clsBox
    Public Overrides Sub Draw(Byval g As Graphics)
        g.FillEllipse(Brushes.GreenYellow, x-r, x-r, 2*r, 2*r)
    End Sub
End Class

Public Class clsHead
    Inherit clsBox
    Private dx As Integer, dy As Integer
    Public Overrides Sub Draw(Byval g As Graphics)
        g.DrawRectangle(Pens.Blue, x-r, x-r, 2*r, 2*r)
    End Sub
End Class

Public Class clsSnake
    Private head As clsHead
    Private body As List(Of clsCell)
    Sub Move()
        Head.Move()
        //BodyMove
    End Sub
    Sub Draw(Byval g As Graphics)
        Head.Draw(g)
        // body.draw()
    End Sub
End Class


Public Class clsGame
    Private box As clsGBox
    Private snake As clsSnake
    Private food As clsFood
    Public WithEvents ticker As Timer
    Event Changed()
    Public Sub Start()
        ticker.Enable = True
    End Sub
    Public Sub ticker_Tick(Byval sender As Object, Byval e As EventsArgs) Handles ticker.Tick
        snake.Move()
        RaiseEvent Changed()
    End Sub
    Public Sub Draw(Byval g As Graphics)
        g.Clear(Colors.White)
        box.Draw(g)
        snake.Draw(g)
        food.Draw(g)
        g.Flush()
    End Sub
End Class

Public Class frmTest
    Dim WithEvents game As clsGame
    Private Sub frmTest_load(Byval sender As Object, Byval e As EventsArgs) Handles MyBase.Load
        game = new clsGame(10, 10, 10, 01)
    End Sub
    Public Sub start_Click(Byval sender As Object, Byval e As EventsArgs) Handles start.Click
        game.Start()
    End Sub
    Public Sub game_Changed() Handles game.Changed
        game.Draw(picCanvas.CreateGraphics())
    End Sub
End Class