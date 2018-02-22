#include<iostream>

using namespace std;
class A
{
	private:
		int i;
		public:
		void f();
		
 };
 void A::f()
 {
 	i=20;
 	cout<<i<<endl;
  } 
  int main()
  {
  	A a;
  	A b;
  	cout<<a.i;
  	a.f();
  	b.f();
  	
  }
