#include <iostream>
#include<fstream> 
#include<string.h>
using namespace std; 
  
// A linked list node  
class Node  
{  
    public: 
    string reg;
    string name;
	string roll;
	string gender;  
    Node *next; 
    //Constructor
	Node(string Nm,string Rl, string Gndr,string regnmbr, Node* ptr)
	{
		name=Nm;
		roll=Rl;
		gender= Gndr;
		reg=regnmbr;
		
		next=ptr;
	}
	//Destructor
	~Node()
	{
		//cout<<"node destroyed"<<endl;
	}  
	void display(Node*) const;  
}; 
//to display the searched node 
void Node :: display(Node* t) const
{
	cout<< "\nReg number : "<<t->reg<<endl;
	cout<< "Roll number : "<<t->roll<<endl;
	cout<< "Name : "<<t->name<<endl;
	cout<< "Gender : "<<t->gender << "\n\n" <<endl;	
}






class LinkedList
{

	Node* head;
	public:
	int ncount;
	//Constructor
	LinkedList()
	{
		ncount++;
		head=NULL;
	}
	
	//Destructor
	~LinkedList()
	{
		Node* temp;
		while(head!=NULL)
		{
			temp=head->next;
			delete []head;
			head=temp;
		}
		//cout<<"Linked List is destroyed";
	}
	void disposeoff();
	void insertion(string, string,string, string);
	void searchLL(string);
	
};
//
void LinkedList::disposeoff() //to dispose off linked list from hash table
{
	Node* temp;
	while(head!=NULL)
	{
		temp=head->next;
		delete []head;
		head=temp;
	}	
}

void LinkedList:: insertion(string reg, string roll,string name, string gender )   //to insert data in hash table
{  
    /* 1. allocate node */
    Node* new_node = new Node(name,roll, gender,reg, head); 
  
    /* 4. move the head to point to the new node */
    head = new_node; 
	ncount++; 
} 
void LinkedList :: searchLL(string roll_key)  //to get of searched Roll No.
{
	Node* temp= head;
	while(temp!=NULL &&  temp->roll!=roll_key)	
	{
		temp=temp->next;
	}
	if(temp!=NULL)
	{
		Node x=*temp;
		x.display(temp);
		return;
	}
	cout << "No entry of this Roll no. " << endl;
}

	


class hashT
{
	public:
	LinkedList * ht;
	int htSize;
	//constructor
	hashT(int s)
	{
			ht= new LinkedList[s];
			htSize=s;		
	}
	//Destructor
	~hashT()
	{
		for(int i=0; i<htSize; i++)
		{
			ht[i].disposeoff();
		}
		delete []ht;
	}
	
	//insert inside hash table
	void insertHt(string regnmbr, string Roll, string name, string Gndr)
	{
		int x= hashFunc(Roll);
		ht[x].insertion(regnmbr,Roll,name, Gndr);
		cout<<"Inserted in hash table sucessfully at " << hashFunc(Roll) <<endl;
	}
	
	int hashFunc(string);
	void search(string);
};

//to get which bucket the info is stored
void hashT :: search(string key)
{
	int x;
	x=hashFunc(key);
	ht[x].searchLL(key);
	
}

int hashT :: hashFunc(string rollnmbr)  //Hash function of h(k)=rollno.%7
{
	int i=0;
	
	int x;
	
	for(i=7;i>4;i--)
	{
		switch(i)
		{
			case 7:
				x=rollnmbr[i]-'0';
				//cout << rollnmbr[i]-'0'<<endl;
				break;
			case 6:
				x=x+(rollnmbr[i]-'0')*10;
				//cout << rollnmbr[i]-'0'<<endl;
				break;
			case 5:
				x=x+ (rollnmbr[i]-'0')*100;
				//cout << rollnmbr[i]-'0'<<endl;
				break;
		}
	}
	
	//cout<<"Stored at position: "<<x%htSize<<endl;
	return (x%htSize);
}



int main(void)
{
	hashT H1(10);
	ifstream file;
	file.open("4thSemCS_Sec_Y_2020.txt");
	string line;
	if(!file.is_open())
	{
		cout<<"error while opening the file"<<endl;
	}
	else
	{
		// to tokenize the string and display tokened file
		while(file.good())
		{
			getline(file, line);
			//cout<<line;
			string reg1, roll1,name1, gen1;
			char* lin1;
			int k=line.length();
			lin1= new char[k];
			
			for(int j=0; j<line.length();j++)
			{
				lin1[j]=line[j];
			}
			
			char* tok =new char[100];
			tok= strtok(lin1,"\t");
			reg1= tok;
			
			cout<<"\n"<< reg1<<endl;
			int j=0,c=0;
			while(tok!=NULL)
			{
				c++;
			
				tok=strtok(NULL, "\t");
				
				switch(j)
				{
					case 0:
						roll1=tok;
						cout<<roll1<<endl;
						break;
					case 1:
						name1=tok;
						cout<< name1<<endl;
						break;
					case 2:
						gen1=tok;
						cout<< gen1<<endl;
						break;
				}
				j++;
			}
			
			
			H1.insertHt(reg1, roll1, name1, gen1);
			
		}
	}
	
	
	
	int ch;
	string key;
	while(1)
	{
		cout<<"\n\t1. search"<<endl<<"\t2.exit"<<endl<<"Enter your choice :";
		cin>>ch;
		
		switch(ch)
		{
			case 1: 
				cout<<"enter roll Number :";
				cin >>key;
				H1.search(key);
				break;
			case 2:
				exit(0);
		}
	}
}
