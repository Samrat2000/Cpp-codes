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
		Node(int x, Node *temp)
		{
			data = x;
			next = temp;
		}
		
		~Node()
		{
			//Destructor defined
		}
};

class LList
{
	//member data
	private:
		Node *head;
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
		LList(int a,Node *p)
		{
			count++;
			head = new Node(a,p);
		}
		
		//Destructor
		~LList()
		{
			Node *k = head;
			for(int i=0;i<count;i++)
			{
				head=head->next;
				delete []k;
				k = head;
			}
			delete []head;
		}
		
		//Add element to the beginning of list
		inline void insertion(int n)
		{
			if(count == 0)
			{
				head = new Node (n,NULL);
				count++;
			}
			else 
			{
				Node *prev=head;
				head = new Node(n,prev);
				count++;
			}
		}
		
		//Delete an element to the beginning of the list
		inline int deletion()
		{
			if(count==0)
				return -1;
			else
			{
				int r = head->data;
				head = head->next;
				return r;
			}
		}
		
		//Display the list
		void display()
		{
			Node *temp = head;
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
		void search(int key)
		{
			Node *temp = new Node();
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
		inline int deletion (int k)
		{
			Node *temp = head;
			Node *prev;
			if(temp!=NULL && temp->data == k)
			{
				head = temp->next;
				return k;
			}
			while(temp!=NULL && temp->data!= k)
			{
				prev = temp;
				temp = temp->next;
			}
			if(temp == NULL)
				return -1;
			prev->next = temp->next;
			return k;
		}
};

int main()
{
	int n,i,c,k;
	//Node *head=NULL;
	LList list;
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
}	
