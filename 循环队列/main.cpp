#include"SeqQueue.h"

int main()
{
	SeqQueue<int> q(5);
	q.EnQueue(1);
	q.EnQueue(1);
	q.EnQueue(1);
	cout<<q<<endl;
	system("pause");
	return 0;
}