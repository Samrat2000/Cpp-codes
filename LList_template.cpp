#include <iostream>

using namespace std;

template <class T=int>
class Node
{
	public:
		T data;
		Node<T> *next;
		//Constructor 1
		Node(T, Node<T> *);
		~Node();
};
template <class T>
Node<T>::Node(T x, Node<T> *temp)
{
	data=x;
	next=temp;
}
template <class T>
Node<T>::~Node()
{
	//destructor defined
}


template <class T>
class LList
{
	//member data
	private:
		Node<T> *head;
	public:
		int count;
		
		//Constructor 1
		LList()
		{
			count = 0;
			head = NULL;
		}
		
		LList(LList &list)
		{
			count = list.count;
			head = list.head;
		}
		
		//Constructor 2
		//template <class T=int>
		LList(T a,Node<T> *p)
		{
			count++;
			head = new Node<T>(a,p);
		}
		
		//Destructor
		//template <class T>
		~LList()
		{
			Node<T> *k = head;
			for(int i=0;i<count;i++)
			{
				head=head->next;
				delete []k;
				k = head;
			}
			delete []head;
		}
		
		//Add element to the beginning of list
		//template <class T>
		void insertion(T n)
		{
			if(count == 0)
			{
				head = new Node<T> (n,NULL);
				count++;
			}
			else 
			{
				Node<T> *prev=head;
				head = new Node<T>(n,prev);
				count++;
			}
		}
		
		//Delete an element to the beginning of the list
		//template <class T>
		T deletion()
		{
			if(count!=0)
			{
				T r = head->data;
				head = head->next;
				return r;
			}
		}
		
		//Display the list
		//template <class T>
		void display() const
		{
			Node<T> *temp = head;
			if(count == 0)
				cout << "Empty list!!" << endl;
			else
				cout << "Printing list : " << endl;
				while(temp!=NULL)
				{
					cout << temp->data << endl;
					temp = temp->next;
				}
		}
		
		//Searches an element in given key
		//template <class T>
		void search(T key)
		{
			Node<T> *temp = new Node<T>();
			temp = head;
			if(count == 0)
				cout << "Empty list!!" << endl;
			else
			{
				for(int i=0;i<count && temp!= NULL;i++)
				{
					if(temp->data==key)
					{
						cout << "The given key is  at index " << i << endl;
						return;
					}
					temp = temp->next;
				}
			}
			cout << "Empty list!!" <<endl;
		}
		
		//delete an element with given key
		//template <class T>
		void deletion (T k)
		{
			Node<T> *temp = head;
			Node<T> *prev;
			if(temp!=NULL && temp->data == k)
			{
				head = temp->next;
				cout <<k << " is deleted from the list!!" << endl;
				return ;
			}
			while(temp!=NULL && temp->data!= k)
			{
				prev = temp;
				temp = temp->next;
			}
			if(temp == NULL)
				cout << "The entered key is not in the list" << endl;
			prev->next = temp->next;
			cout <<k << " is deleted from the list!!" << endl;
		}
};

int main()
{
	LList<float> (56.7,NULL);
}
/*int main()
{
	int n,i,c,k;
	//Node *head=NULL;
	LList<float> list;
	while(1)
	{
		cout<< "\n\n1.Insert At the beginning \n2.Delete an element at the beginning \n3.Printing actual list \n4.Searches an element using given key \n5.Deletes an element using given key \n6.Display copied list \n7.Exit \nEnter your choice: ";
		cin >> c;
		switch(c)
		{
			case 1: cout << "Enter the value to be added at the beginning : " << endl;
					cin >> n;
					list.insertion(n);
					cout << n << " is inserted at the beginning" << endl;
					break;
			case 2: k = list.deletion();
					if(k==-1)
						cout << "Empty list!!" <<endl;
					else
						cout << k << "is deleted successfully" <<endl;
					break;
			case 3: {
					cout << "Displaying normal list" << endl;
					list.display();
					break;
					}
					
			case 4: cout << "Enter the value to be searched : " << endl;
					cin >> n;
					list.search(n);
					break;
			case 5: cout << "Enter the value to be deleted : " << endl;
					cin >> n;
					k = list.deletion(n);
					if(k==-1)
						cout << "Entered value is not in the list!!" <<endl;
					else
						cout << k << "is deleted successfully" <<endl;
					break;
			case 6: {
					LList l(list);
					cout << "Displaying copied list" << endl;
					l.display();
					break;
					}
			case 7: exit(0);
		}
	}
}	*/
