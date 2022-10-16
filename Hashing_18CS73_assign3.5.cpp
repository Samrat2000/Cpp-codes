#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

//user input for entering elements
void accept(int &k,int *&a)
{
	cout << "Enter number of elements to be entered : ";
	cin >> k;
	a = new int[k];
	cout << "Enter the elements" << endl;
	for(int i=0;i<k;i++)
	{
		cin >> a[i];
	}
	return;
}

void push(Node** head_ref, int new_data)  
{  
    /* 1. allocate node */
    Node* new_node = new Node(); 
  
    /* 2. put in the data */
    new_node->data = new_data;  
  
    /* 3. Make next of new node as head */
    new_node->next = *head_ref;  
  
    /* 4. move the head to point to the new node */
    *head_ref = new_node;  
}   

//storing array elements in respective buckets
void alloc_store(int &k,int *&a,Node **&p)
{
	p = new Node*[k];
	for(int j=0;j<k;j++)
	{
		p[j] = new Node;
		p[j]= NULL;
	}
	for(int i=0;i<k;i++)
	{
		int temp=a[i]%k;
		push(&p[temp],a[i]);
	}
	return;
}

void printList(int &k,Node **&p)
{
	cout << "Printing List " << endl;
	for(int i=0;i<k;i++)
	{
		cout << "Bucket" << i << " : " ;
		int j=i;
		while(p[j]!=NULL)
		{
			cout << " " << p[j]->data;
			p[j] = p[j]->next;
			if(p[j]!=NULL)
				cout << "->";
		}
		cout << endl;
	}
	return;
}

//deallocation
void dealloc(int &k,int *&a,Node **&p)
{
	delete []a;
	for(int i=0;i<k;i++)
	{
		delete []p[i];
	}
	delete []p;
	a=NULL;
	p=NULL;
	return;
}

int main()
{
	int n,*arr;
	Node **r=NULL;
	accept(n,arr);
	alloc_store(n,arr,r);
	printList(n,r);
	dealloc(n,arr,r);
}
