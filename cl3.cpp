#include<iostream>

class A
{
private:
	int val;
public:
	A(int val=-1)
	{
		this->val=val;
	}
	
	int& getVal()
	{
		return this->val;
	}
};


int main()
{
	using namespace std;
	A a;
	A b(5);
	a=b;
	a.getVal()=99;
	cout<<"a "<<a.getVal()<<" b "<<b.getVal()<<endl;
	cout<<&a<<" "<<&b<<endl;
	int c=7;
	int &d(c);
	cout<<d<<endl;
	return 0;
}
