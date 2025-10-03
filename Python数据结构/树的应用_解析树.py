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
import operator

class stack:
    def __init__(self):
        self.items = []

    def push(self,item):
        self.items.append(item)

    def isEmpty(self):
        return len(self.items)==0

    def pop(self):
        if not self.isEmpty():
            return self.items.pop()

    def peek(self):
        if not self.isEmpty():
            return self.items[-1]

    def size(self):
        return len(self.items)


def buildParseTree(fpexp):
    fplist = fpexp.split()
    pStack = stack()
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
            currentTree.insertRight('')
            pStack.push(currentTree)
            currentTree = currentTree.getRightChild()
        elif i ==')':
            currentTree=pStack.pop()
        else:
            raise ValueError
    return eTree
def evaluate(parseTree):
    """
    递归方法计算表达式
    :param parseTree: 表达式树
    :return: 表达式的值
    """
    opers = {'+':operator.add ,'-':operator.sub,
             '*':operator.mul , '/':operator.truediv}
    leftC = parseTree.getLeftChild()
    rigthC = parseTree.getRightChild()

    if leftC and rigthC:
        fn = opers[parseTree.getRootVal()]
        return fn(evaluate(leftC),evaluate(rigthC))
    else:
        return parseTree.getRootVal()

def postordereval(tree):
    """
    中序遍历方法计算表达式
    :param tree: 表达式树
    :return: 计算结果
    """
    opers = {'+': operator.add, '-': operator.sub,
             '*': operator.mul, '/': operator.truediv}
    res1 = None
    res2 = None
    if tree:
        res1 = postordereval(tree.getLeftChild())
        res2 = postordereval(tree.getRightChild())
        if res2 and res2:
            return opers[tree.getRootVal()](res1,res2)
        else:
            return tree.getRootVal()

def printexp(tree):
    """
    生成全括号中缀表达式
    :param tree: 表达式树
    :return: 表达式字符串
    """
    sVal = ''
    if tree:
        if tree.leftChild:
            sVal = '('+printexp(tree.getLeftChild())
            sVal = sVal + str(tree.getRootVal())
            sVal = sVal + printexp(tree.getRightChild())+')'
        else:
            sVal = printexp(tree.getLeftChild())
            sVal = sVal + str(tree.getRootVal())
            sVal = sVal + printexp(tree.getRightChild())
    return sVal

if __name__ == '__main__':
    x = "( ( 4 + 3 ) * ( 10 / 2 )"
    tree = buildParseTree(x)
    print(printexp(tree))
    print(postordereval(tree))

