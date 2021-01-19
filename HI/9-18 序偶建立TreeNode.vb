/*
1. 定义结构体ParentChild
2. New中先将PCs(0)加入Root，遍历每一对序偶，找到parent对应的TreeNode加入child
3. Search中递归寻找parent
4. 加入TreeView控件  
*/
Structure ParentChild
    Public parent As String
    Public child As String
End Structure
Public Class clsParentChilds
    Private Root As TreeNode
    Public Sub New(PCs As List(Of ParentChild))
        Root = New TreeNode(PCs(0).parent)
        Root.Nodes.Add(PCs(0).child)

        for i = 1 To PCs.count - 1
            Dim parent As TreeNode = Search(Root, Pcs(i).parent)
            pattern.Nodes.Add(PCs(i).child)
        Next
    End Sub

    Public Function Search(Byval Node As TreeNode, ByVal parent As String) As TreeNode
        if Node.Text = parent Then Return Node
        For i = 0 To Node.Nodes.count - 1
            Dim r As TreeNode = Search(Node.Nodes(i), parent)
            If r IsNot Nothing
                Return r
            End If
        Next
        Return Nothing
    End Function
    Public Sub Output(BuVal tvfamily As TreeView)
        tvfamily.Nodes.Add(Root)
    End Sub
End Class

Structure ParentChild
    public parent As String
    public child As String
End Structure

Public Class clsTree
    Private Root As TreeNode
    public Sub New(Pcs As List(Of ParentChild))
        Root = New TreeNode(PCs(0).parent)
        Root.Nodes.Add(PCs(0).child)
        For i = 1 To Pcs.Count - 1
            Dim p As TreeNode = Search(Pcs(i).parent, Root)
            p.Nodes.Add(pcs(i).child)
        Next
    End Sub
    Public Function Search(p As String, node As TreeNode) As TreeNode
        If node.Text = p Then Return node
        For i = 0 To node.Nodes.Count -1 
            Dim r As TreeNode = Search(p, node.Nodes(i))
            If r IsNot Nothing Then Return r
        Next
        Return Nothing
    End Function
    Public Sub Output(tree As TreeView)
        tree.Node.Add(root)
    End Sub
End Class