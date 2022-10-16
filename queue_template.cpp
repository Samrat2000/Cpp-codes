#include <iostream>

using namespace std;

template <class T=int>
class Node
{
	public:
		T data;
		Node<T> *next;
		//Constructor 1
		Node(T);
		~Node();
};
template <class T>
Node<T>::Node(T x)
{
	data=x;
	next=NULL;
}
template <class T>
Node<T>::~Node()
{
	//destructor defined
}

template <class T=int>
class Queue{
	public : Node<T> *f,*r;
	private :
		int isEmpty()
		{
			if(f==NULL)
				return 1;
			else 
				return 0;
		}
	public:
		//Constructor
		Queue()
		{
			f=NULL;
			r=NULL;
		}
		//CopyConstructor
		Queue(Queue<T> &q)
		{
			f=q.f;
			r=q.r;
		}
		//Destructor
		~Queue()
		{
			Node<T> *k = f;
			while(f!=NULL)
			{
				f=f->next;
				delete []k;
				k = f;
			}
			delete []f;
		}
		void enqueue(T y)
		{
			Node<T> *temp = new Node<T>(y);
			if(r==NULL)
				f = r = temp;
			else
			{
				r->next = temp;
				r = temp;
			}
			
			cout << "Value enqueued successfully" << endl;
		}
		void dequeue()
		{
			if(isEmpty())
				cout << "empty queue!!!" << endl;
			else
			{
				cout << "Value dequeued : " << f->data << endl;
				f = f->next;
				if(f==NULL)
					r=NULL;
			}
		}
		void display() const
		{
			if(f==NULL)
			{
				cout << "Empty queue " <<endl;
				return;
			}
			Node<T> *temp= f;
			cout << "Printing queue : " << endl;
			while(temp != NULL){
				cout << temp->data << endl;
				temp= temp->next;
			}
			delete []temp;
		}
};

int main()
{
	Queue<float> k;
	Queue<float>m(k);
	Queue<> q;
	k.enqueue(2.5);
	m.enqueue(9);
	q.enqueue(88);
	/*int x,c,temp,t;
	Queue k;
	while(1)
	{
		cout<< "\n\n1.Enqueue \n2.Dequeue \n3.Front element \n4.Rear Element \n5.display Queue \n6.Exit \nEnter your choice: ";
		cin >> c;
		switch(c)
		{
			case 1: cout << "Enter the value to be enqueued " << endl;
					cin >> x;
					k.enqueue(x);
					break;
			case 2: cout << " Dequeuing ...." << endl;
					k.dequeue();
					break;
			case 3: cout << "Front element is " << k.f->data << endl;
					break;
			case 4: cout << "Rear element is " << k.r->data << endl;
					break;
			case 5: {
					cout << "Displaying normal queue" << endl;
					k.display();
					Queue q(k);
					cout << "Displaying copied queue" << endl;
					q.display();
					}
					break;
					
			case 6: exit(0);
		}
	}*/
}
