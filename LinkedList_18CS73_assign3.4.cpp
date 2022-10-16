#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

void push(Node** head_ref, int new_data)  
{  
    /* 1. allocate node */
    Node* new_node = new Node(); 
  
    /* 2. put in the data */
    new_node->data = new_data;  
  
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);  
  
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;  
}   

void deleteNode(Node **head_ref, int key) 
{ 
    // Store head node 
    Node* temp = *head_ref, *prev; 
  
    // If head node itself holds the key to be deleted 
    if (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next;   // Changed head 
        delete temp;               // free old head 
        return; 
    } 
    
    // Search for the key to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    // If key was not present in linked list 
    if (temp == NULL) 
	{
		cout << "The key to be deleted is not found" << endl ;
		return;
	} 
  
    // Unlink the node from linked list 
    prev->next = temp->next; 
  
    delete temp;  // Free memory 
}

void printList(Node* head_ref)
{
	Node* temp = head_ref;
	if(temp == NULL)
	{
		cout << "No elements in the List" << endl;
		return;
	}
	while(temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next ;
	}
	return;
}

int main()
{
	int n,i,c;
	//Node *head=NULL;
	Node* head=new Node();
	head=NULL;
	while(1)
	{
		cout<< "\n\n1.Insert At the beginning \n2.Delete a given key \n3.Printing the linked list \n4.Exit \nEnter your choice: ";
		cin >> c;
		switch(c)
		{
			case 1: cout << "Enter the value to be added at the beginning : " << endl;
					cin >> n;
					push(&head,n);
					break;
			case 2: cout << "Enter the key to be deleted : " << endl;
					cin >> n;
					deleteNode(&head,n);
					break;
			case 3: cout << "Printing List:" << endl;
					printList(head);
					break;
			case 4: delete []head;
					exit(0);
		}
	}
}
