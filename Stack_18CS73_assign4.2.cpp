#include <iostream>
using namespace std;
class stack{
	private : int *a,top,n;
	public : int size;
	private :
		int isEmpty()
		{
			if(top==-1)
				return 1;
			else 
				return 0;
		}
		int isFull()
		{
			if(top==(n-1))
				return 1;
			else
				return 0;
		}
	public:
		//Constructor
		stack(int x)
		{
			n = x;
			top = -1;
			a = new int[n];
			size = 0;
		}
		//Copy Constructor
		stack(stack &y)
		{
			n = y.n;
			top=y.top;
			a=new int(*(y.a));
			size=0;
			cout << "Copy constructor used" << endl;
		}
		//Destructor
		~stack()
		{
			delete []a;
		}
		inline int push(int y)
		{
			if(!isFull())
			{
				top++;
				size++;
				a[top] = y;
				return 1;
			}
			else
				return 0;
		}
		inline int pop()
		{
			if(!isEmpty())
			{
				int x=a[top];
				top--;
				size--;
				return x;
			}
			else
				return -1;
		}
		inline int peek()
		{
			if(!isEmpty())
			{
				int x=a[top];
				return x;
			}
			else
				return -1;
		}
		void display()
		{
			if(top==-1){
				cout << "Empty stack" <<endl;
				return;
			}
			cout << "Printing stack : " << endl;
			for(int i=size-1;i>=0;i--){
				cout << a[i] << endl;
			}
		}
};

int main()
{
	int n,x,c,temp,t;
	cout << "Enter no. of elements in the stack : ";
	cin >> n;
	stack m(n);
	stack s(m);
	
	while(1)
	{
		cout<< "\n\n1.push in the stack \n2.pop from the stack \n3.peek from the stack \n4.display the stack \n5.Exit \nEnter your choice: ";
		cin >> c;
		switch(c)
		{
			case 1: cout << "Enter the value to be pushed " << endl;
					cin >> x;
					if(s.push(x))
					{
						cout << "Value pushed in successfully" << endl;
					}
					else
					{
						cout << "Value not pushed in " << endl;
					}
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
					
			case 4: cout << "Displaying normal stack" << endl;
					m.display();
					cout << "Displaying Copied stack" << endl;
					s.display();
					break;
			case 5: exit(0);
		}
	}
}
