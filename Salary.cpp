#include <iostream>

using namespace std;

int count=0; //global variable to keep track how many Salary objects are created in total
class Salary
{
	//basic salary and gross salary are made private 
	int basic;
	float grossal;
	public:
		//bonus is made constant
		const int bonus;
		//DA belongs the Salary class, so made static
		static float da;
		//to confirm the creation of a salary object 
		static int objCount;	
		
		//Constructor
		Salary(int x=10000) : bonus(2000), grossal(0)   //Constructor initialiaser list
		{
			basic=x;
			Salary::objCount++;
			//cout << "Object created\n";
		}
		
		//Destructor
		~Salary()
		{
			Salary::objCount--;
			//cout << "Object destroyed\n";
		}
		
		//static method for DA hike
		static void dahike(float f)
		{
			Salary::da+=f;
		}
		
		//method to calculate salary
		float calSal()
		{
			grossal=basic+basic*(Salary::da/100)+bonus;
			return grossal;
		}
		
		//constant method to display salary
		void dispSal() const
		{
			cout << "Gross Salary: " << grossal << endl;
		}
		
		//friend function to calculate the average salary
		friend float average(float avg, Salary &sal)
		{
			avg = ((count-1)*avg + sal.grossal)/count;
			return avg;
		}
};

//declaring and initialising static members
float Salary::da=5;
int Salary::objCount;

int main()
{
	char c;
	cout << "Presnt DA is 5%. Is there any hike in DA (Y/N):";
	cin >> c;
	if(c=='Y')
	{
		float hike;
		cout << "Enter the hike in DA : ";
		cin >> hike;
		Salary::dahike(hike);
	}
	char k='Y';
	float a=0;
	while(k=='Y')
	{
		int n;
		cout << "\nEnter basic of an employee : ";
		cin >> n;
		Salary s(n);
		s.calSal();
		s.dispSal();
		count += Salary::objCount;
		a=average(a,s);
		cout << "Want to calculate salaries of more employees (Y/N) :";
		cin >> k;
	}
	cout << "\n\nTotal number of objects created : "<< count << endl;
	cout << "\nAverage gross salaries of all the employees : " << a <<endl;
}
