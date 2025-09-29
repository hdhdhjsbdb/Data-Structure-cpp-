#语法树的应用：词法、语法检查、表达式的分解
#自然语言处理：机器翻译、语义理解
#######################dwf
#从左到右扫描全括号表达式，依据规则创建解析树：
#当是（：为当前结点创建一个新左子结点，当前结点下降为新结点
#如果是操作符+-*/：将当前结点的值设为此符号，为当前添加一个新结点作为其右子结点，当前结点下降为新结点
#如果是操作数：将当前结点的值设为此数，当前结点上升到父节点
#如果是）：当前节点上升到父节点
######################
from 树的链表法实现 import BinaryTree

def buildParseTree(fpexp):
    fplist = fpexp.split()
    pStack = Stack()
    eTree = BinaryTree('')
    pStack.push(eTree)
    currentTree = eTree
    for i in fplist:
        if i =='(':
            currentTree.insertLeft('')
            pStack.push(currentTree)
            currentTree = currentTree.getLeftChild()
        elif i not in ['+','-','*','/',')']:
            currentTree.setRootVal(int(i))
            parent = pStack.pop()
            currentTree = parent
        elif i in ['+','-','*','/']:
            currentTree.setRootVal(i)
            currentTree.insertLeft('')
            pStack.push(currentTree)
            currentTree = currentTree.getRightChild()
        elif i ==')':
            currentTree=pStack.pop()
        else:
            raise ValueError
    return eTree

