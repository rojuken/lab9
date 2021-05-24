#include <iostream>
#include "QueueList.h"

int main()
{
	TQueueList<int> q;
	q.Push(10);
	q.Push(11);
	cout << q.Get() << "\n";
	return 0;
}
