#include <iostream>
using namespace std;

class Node{
	public : 
		int data;
		Node *next;
};
class stack{
	private : Node *a;
	private :
		int isEmpty()
		{
			if(a==NULL)
				return 1;
			else 
				return 0;
		}
	public:
		stack()
		{
			a = new Node();
			a= NULL;
		}
		/*stack(stack &y)
		{
			a=new Node(*(y.a));
			a=NULL;
		}*/
		~stack()
		{
			delete []a;
		}
		void push(int y)
		{
			Node* temp= new Node();
			temp->data = y;
			temp->next = a;
			a = temp;
			cout << "Pushed successfully" << endl;
		}
		int pop()
		{
			if(!isEmpty())
			{
				Node* temp= new Node();
				temp = a;
				int val= a->data;
				a = a->next;
				temp->next=NULL;
				delete temp;
				return val;
			}
			else
				return -1;
		}
		int peek()
		{
			if(!isEmpty())
			{
				return a->data;
			}
			else
				return -1;
		}
		void display()
		{
			Node* temp= new Node();
			temp = a;
			cout << "Printing stack : " << endl;
			while(temp != NULL){
				cout << temp->data << endl;
				temp= temp->next;
			}
		}
};

int main()
{
	int x,c,temp,t;
	stack s;
	//stack s(m);
	while(1)
	{
		cout<< "\n\n1.push in the stack \n2.pop from the stack \n3.peek from the stack \n4.display the stack \n5.Exit \nEnter your choice: ";
		cin >> c;
		switch(c)
		{
			case 1: cout << "Enter the value to be pushed " << endl;
					cin >> x;
					s.push(x);
					break;
			case 2: cout << " Popping from stack ...." << endl;
					temp=s.pop();
					if(temp!=-1)
						cout << "Popped value : " << temp;
					else
						cout << "Empty stack!!!Can't pop" << endl;
					break;
			case 3: cout << " Peeking from stack ...." << endl;
					t=s.peek();
					if(t!=-1)
						cout << "Peeked value : " << t;
					else
						cout << "Empty stack!!!Can't peek" << endl;
					break;
			case 4: s.display();
					break;
			case 5: exit(0);
		}
	}
}
