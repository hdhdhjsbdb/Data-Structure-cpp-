"""
前序遍历（preorder）：先访问根结点，再递归地前序访问左子树、最后前序访问右子树；
中序遍历（inorder）：线递归地中序访问左子树，再访问根节点，最后中序访问右子树；
后序遍历（postorder）：先递归地访问左子树，再访问右子树，最后访问根节点。
"""
def preorder(tree):
    if tree:
        print(tree.getRootVal())
        preorder(tree.getLeftChild())
        preorder(tree.getRightChild)

def inorder(tree):
    if tree:
        preorder(tree.getLeftChild())
        print(tree.getRootVal())
        preorder(tree.getRightChild)

def postorder(tree):
    if tree:
        preorder(tree.getLeftChild())
        preorder(tree.getRightChild)
        print(tree.getRootVal())