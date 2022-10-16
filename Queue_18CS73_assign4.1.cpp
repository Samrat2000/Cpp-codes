#include <iostream>

using namespace std;

class Node
{
	public:
		int data;
		Node *next;
		
		// Constructor 1
		Node()
		{
			data = -1;
			next = NULL;
		}
		
		//Constructor 2
		Node(int x)
		{
			data = x;
			next = NULL;
		}
		
		~Node()
		{
			//Destructor defined
		}
};

class Queue{
	public : Node *f,*r;
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
		Queue(Queue &q)
		{
			f=q.f;
			r=q.r;
		}
		//Destructor
		~Queue()
		{
			Node *k = f;
			while(f!=NULL)
			{
				f=f->next;
				delete []k;
				k = f;
			}
			delete []f;
		}
		inline void enqueue(int y)
		{
			Node *temp = new Node(y);
			if(r==NULL)
				f = r = temp;
			else
			{
				r->next = temp;
				r = temp;
			}
			
			cout << "Value enqueued successfully" << endl;
		}
		inline void dequeue()
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
		void display()
		{
			if(f==NULL)
			{
				cout << "Empty queue " <<endl;
				return;
			}
			Node* temp= f;
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
	int x,c,temp,t;
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
	}
}
