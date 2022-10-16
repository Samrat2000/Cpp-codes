#include <iostream>
using namespace std;

// Base Class
class Tool
{
	public:
		int strength;    // strength of each tool
		char type;      // type of each tool
		
		// to set strength
		void setStrength(int s)
		{
			strength = s;
		}
};

// Derived Class
class Rock: public Tool
{
	public:
		Rock(int s)
		{
			setStrength(s);
			type = 'r';
		}
		~Rock(){}
		
		// fight with other 2 types on the basis of strength advantages
		int fight(Tool &t)
		{
			if(t.type=='s') return strength*2>t.strength?1:0;
			if(t.type=='p') return strength>t.strength*2?1:0;
		}
};

// Derived Class
class Paper: public Tool
{
	public:
		Paper(int s)
		{
			setStrength(s);
			type = 'p';
		}
		~Paper(){}
		
		// fight with other 2 types on the basis of strength advantages
		int fight(Tool &t)
		{
			if(t.type=='s') return strength>t.strength*2?1:0;
			if(t.type=='r') return strength*2>t.strength?1:0;
		}
};

// Derived Class
class Scissors: public Tool
{
	public:
		Scissors(int s)
		{
			setStrength(s);
			type = 's';
		}
		~Scissors(){}
		
		// fight with other 2 types on the basis of strength advantages
		int fight(Tool &t)
		{
			if(t.type=='r') return strength>t.strength*2?1:0;
			if(t.type=='p') return strength*2>t.strength?1:0;
		}
};

int main() {
	// Example main function
	// You may add your own testing code if you like
	Scissors s1(5);
	Paper p1(7);
	Rock r1(15);
	cout << s1.fight(p1) << p1.fight(s1) << endl;
	cout << p1.fight(r1) << r1.fight(p1) << endl;
	cout << r1.fight(s1) << s1.fight(r1) << endl;
	return 0;
}

