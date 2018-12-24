#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
#define DataType int
#include<exception>

#if 0

typedef struct NodeList
{
	DataType _data;
	struct NodeList *_next;
	struct NodeList *_rand;
}NodeList, *pNodeList, **ppNodeList;









int main()
{
	pNodeList Node;

	return 0;
}
#endif



template<class T>
class cycleQueue
{
public:
	cycleQueue(unsigned size)
		:m_size(size),
		 m_front(0),
		 m_rear(0)
	{
		m_data = new T[size];
	}

	~cycleQueue()
	{
		delete[] m_data;
	}

	bool isEmpty()
	{
		return m_front == m_rear;
	}

	bool isFull()
	{
		return m_front == (m_rear + 1) % m_size;
	}

	void push(T ele)throw(bad_exception)
	{
		if (isFull())
		{
			throw bad_exception();
		}
		m_data[m_rear] = ele;
		m_rear = (m_rear + 1) % m_size;
	}

	T pop() //throw(bad_exception)
	{
		if (isEmpty())
		{
			//throw bad_exception();
			return 0;
		}
		T tmp = m_data[m_front];
		m_front = (m_front + 1) % m_size;
		return tmp;
	}


private:
	unsigned int m_size;
	int m_front;
	int m_rear;
	T *m_data;
};







int main()
{
	cycleQueue<int> Q(5);
	Q.push(1);
	Q.push(2);
	Q.push(3);
	Q.push(4);
	for (int i = 0; i < 4; i++)
	{
		int temp = Q.pop();
		cout << temp << endl;
	}
		
	Q.push(5);
	Q.push(5);
	
	cout << Q.pop() << endl;
	cout << Q.pop() << endl;
	cout << Q.pop() << endl;
	cout << Q.pop() << endl;

	return 0;
}
