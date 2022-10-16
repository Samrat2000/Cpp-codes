#include <iostream>
using namespace std;

class Employee
{
	public: 
		int basic, da, bonus;
		Employee(int b, int d, int bon) : basic(b),da(d),bonus(bon){}
		~Employee(){}
		void calcSalary(){
			//cout << "Salary is: " << basic+da*basic/100+bonus << endl;
		}
};

class AdminOfficer : public Employee
{
	public:
		AdminOfficer(int a, int b, int c) : Employee(a,b,c){}
		~AdminOfficer(){}
};

class Faculty : public Employee
{
	public:
		Faculty(int a, int b, int c) : Employee(a,b,c){}
		~Faculty(){}
};

class Dean : public AdminOfficer, public Faculty
{
	public:
		Dean(int a1, int b1, int c1, int a2, int b2, int c2) : AdminOfficer(a1,b1,c1), Faculty(a2, b2, c2){}
		~Dean(){}
		void calcSalary()
		{
			double s1= 
		}
};
