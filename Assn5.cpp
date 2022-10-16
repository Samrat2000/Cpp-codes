#include <iostream>
using namespace std;

class List
{
	public:
		int size,f,r;
		int *arr;
		virtual ~List();
		int isFull()
		{
			return ((r+1)%size==f)?1:0;
		}
		int isEmpty()
		{
			return (f==r)?1:0;
		}
		virtual void addbeg(int)=0;
		virtual void delbeg()=0;
		virtual void addend(int)=0;
		virtual void delend()=0;
		void display();
};

void List::addbeg(int a)
{
	if(!isFull()){
		f=(f-1)%size;
		arr[f]=a;
	}
	else if(isEmpty()){
		arr[f]=a;
	}
	else cout << "List is full" << endl;
}

void List::delbeg()
{
	if(!isEmpty())	f=(f+1)%size;
	else cout<<"List is empty"<<endl;
}

void List::addend(int a)
{
	if(!isFull()){
		r=(r+1)%size;
		arr[r]=a;
	}
	else if(isEmpty()){
		arr[f]=a;
	}
	else cout << "List is full" << endl;
}

void List::delend()
{
	if(!isEmpty())	r=(r-1)%size;
	else cout<<"List is empty"<<endl;
}

void List::display()
{
	cout << "Printing list: " << endl;
	for(int i=f;i!=r;i++){
		cout << arr[i%size] << endl;
	}
}



class Stack: private List
{
	public:
		using List::display;
		Stack(int s) {
			size=s;
			f=r=0;
			arr= new int[size];
		} 
		virtual ~Stack(){
			delete []arr;
		}
		void push(int x){	addend(x);		}
		void pop(){   delend();		}
		
};


int main()
{
	List *list = new Stack(4);
	st->push(3);
}
