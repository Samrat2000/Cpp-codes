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
		
		//to deallocate hashtable
		void disposeoff(LList &k)
		{
			Node *m = k->head;
			for(int i=0;i<count;i++)
			{
				k->head=k->head->next;
				delete []m;
				m = k->head;
			}
			delete []k->head;
		}
		
		//Add element to the beginning of list
		void insertion(int n)
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
		
		//Display the list
		void display()
		{
			Node *temp = head;
			while(temp!=NULL)
			{
				cout << temp->data;
				temp = temp->next;
				if(temp!=NULL)
					cout << " -> " ;
				else
					cout << endl;
			}
		}
		
		//Searches an element in given key
		int search(int key,Node *prev)
		{
			Node *temp = head;
			prev =  NULL;
			while(temp!=NULL)
			{
				if(temp->data==key)
				{
					return 1;
				}
				else
				{
					prev = temp;
					temp=temp->next;
				}
			}
			return 0;	
		}
		
		//delete an element with given key
		void deletion (int k)
		{
			Node *temp;
			Node *prev;
			if(search(k,prev))
			{
				if(prev==NULL)
				{
					temp = head->next;
					delete []head;
					head=temp;
				}
				else
				{
					temp=prev->next;
					prev->next=prev->next->next;
					delete []temp;
				}
			}
		}
};

class Hasht
{
	LList *ht;
	int htsize;
	
	public:
		//Constructor
		Hasht(int s)
		{
			ht = new LList[s];
			htsize = s;
		}
		
		
		//Destructor
		~Hasht()
		{
			for(int i=0; i<htsize; i++)
			{
				LList::disposeoff(ht[i]);
			}
			delete []ht;
		}
		
		insertht(int b)
		{
			int x= hashFunc(b);
			ht[x].insertion(x);
			cout<<"Inserted in hash table sucessfully at " << hashFunc(b) <<endl;
		}
};

