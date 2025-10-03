"""
ADT BinaryHeap操作定义：
BinaryHeap()：创建一个空二叉堆
insert(k)：将新key加入到堆中
findMin()：返回堆中最小项，最小项仍保留在堆中
delMin()：返回堆中最小项，同时从堆中删除
isEmpty()：返回堆是否为空
size()：返回堆中key的个数
buildHeap(list)：从一个key列表创建新堆

完全二叉树：结点下标为p，左子节点洗标为2p，右子节点下标为2p+1
父节点下标为p//2
在堆当中，然和一个结点，其父节点中的key，都小于结点当中的key
堆当中任何一个路径，均是一个一已排序数列
"""
class BinHeap:
    def __init__(self):
        self.heapList = [0] #0占位，根节点从1开始
        self.currentSize = 0

    def percUP(self,i):
        """
        让key上浮，使之符合堆的排序原则
        :param i: 下标
        """
        while i // 2 >0:
            if self.heapList[i] < self.heapList[i//2]:
                temp = self.heapList[i//2]
                self.heapList[i//2] = self.heapList[i]
                self.heapList[i] = temp
            else:
                break #如果已经满足堆的性质，退出循环
            i = i//2

    def insert(self,k):
        """
        插入新key
        :param k: key值
        """
        self.heapList.append(k)
        self.currentSize += 1
        self.percUP(self.currentSize)

    def percDown(self,i):
        while (i*2)<=self.currentSize:
            mc = self.minChild(i)
            if self.heapList[i]>self.heapList[mc]:
                temp = self.heapList[i]
                self.heapList[i] = self.heapList[mc]
                self.heapList[mc] = temp
            i = mc

    def minChild(self,i):
        if i*2+1>self.currentSize:
            return i*2
        else:
            if self.heapList[i*2]<self.heapList[i*2+1]:
                return i*2
            else:
                return i*2+1

    def delMin(self):
        retval = self.heapList[1]
        self.heapList[1] = self.heapList[self.currentSize]
        self.currentSize -= 1
        self.heapList.pop()
        self.percDown(1)
        return retval

    def buildHeap(self,alist):
        i = len(alist) // 2
        self.currentSize = len(alist)
        self.heapList = [0] + alist[:]
        print(len(self.heapList),i)
        while i>0:
            print(self.heapList,i)
            self.percDown(i)
            i = i -1
        print(self.heapList,i)

if __name__ == '__main__':
    alist = [2,5,9,8,6,3,4]
    heap = BinHeap()
    heap.buildHeap(alist)