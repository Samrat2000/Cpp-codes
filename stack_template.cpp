#include<iostream>
//#include<iomanip>

using namespace std;


template <class T=int, int n=10>
class stack
{
	// member data
	public:
		T *p;
		int top,size;

	// member methods
		stack(int x=n);
		stack(const stack<T,n> &x);
		~stack();
		int push(T);
		void display(void) const;

	private:
		int overflow(void);
		int underflow(void);
		
	
}; // end of class stack

// method definitions
template <class T, int n> 
stack<T,n>::stack(int x)
		{
			p=new T[x]; //n++;
			top=-1;
			size=x;
		}
template <class T, int n> 
stack<T,n>::stack(const stack<T,n> &x)
		{
			p=new int[x.size];
			top=x.top;
			size=x.size;
			for(int i=0;i<=top;i++)
				p[i]=x.p[i];

		}

template <class T, int n> 
stack<T,n>::~stack()
		{
			delete []p;
		}

template <class T, int n> 
int stack<T,n>::push(T  x)
		{
			if(!overflow())
			{
				top++;
				p[top]=x;
				return 1;
			}
			else
				return -1;
		}

template <class T, int n> 
void stack<T,n>::display(void) const
		{
			cout<<"displaying stack"<<endl;
			for(int i=0;i<=top;i++)
				cout<<p[i]<<endl;
		}

template <class T, int n> 
int stack<T,n>::overflow(void)
		{
			if(top==(size-1))
				return 1;
			else
				return 0;
		}
		
template <class T, int n> 
int stack<T,n>::underflow(void)
{
	
}

int  main(void)
{
     stack<int, 5> s,r[5];
     stack<float,2>  a;

     stack<int, 5> b(s);

     //stack<int>   *p=new stack<int,2>;

     cout<<a.push(3)<<"..top="<<a.top<<endl;
     cout<<a.push(56)<<"..top="<<a.top<<endl;
     cout<<a.push(65)<<"..top="<<a.top<<endl;
     a.display();

     stack<>   c;

     cout<<c.push(78.9)<<"..top="<<c.top<<endl;
     c.display();
}
