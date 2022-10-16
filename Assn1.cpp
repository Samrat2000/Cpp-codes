#include <iostream>
using namespace std;

class A 
{
  public:
	virtual void fn(int i) {  cout<<"A::fn(int)"<<endl;}
	virtual void gn(double d) {  cout<<"A::gn(double)"<<endl;}
	int hn(A* a) {  cout<<"A::hn(A*)"<<endl;}
};
class B : public A 
{
  public:
	void fn(int i) {  cout<<"B::fn(int)"<<endl;}
	virtual int hn(B* a) {  cout<<"B::hn(B*)"<<endl;}
};
class C : public B 
{
  public:
	void gn(double d) {  cout<<"C::gn(double)"<<endl;}
	int hn(B* a) {  cout<<"C::hn(B*)"<<endl;}
};

int main(void)
{  A a; B b; C c;
   A *pA; B *pB;
   pB=&c;
   pB->fn(3);	
   pB->gn(3.5);	
   //pB->hn(&a);	
   pB->hn(&b);

}

