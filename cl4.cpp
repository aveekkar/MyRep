#include<iostream>
#include<string>

using namespace std;

class A
{
public:
	 void getName()
	{
		cout<<"class A"<<endl;
	}
};

class B: public A
{
public:
	virtual void getName()
	{
		cout<<"class B"<<endl;
	}
	
	void getName() const
	{
		cout<<"B const version"<<endl;
	}
};

class C: public B
{
public:
	void getName()
	{
		cout<<"class C"<<endl;
	}
	
};


class Whatever
{
public:
	int a;
	Whatever(int arg=10)
		:a(arg)
		{
		}
		
	int getA() const
	{
		cout<<"const"<<endl;
		return a;
	}
	
	int getA()
	{
		cout<<"non-const"<<endl;
		return a;
	}
	
	void someFun(const B& b)
	{
		cout<<"somefun"<<endl;
		b.getName();
	}
};

int main()
{
	C c;
	A *a=&c;
	a->getName();
	cout<<endl<<endl;
	Whatever w1;
	const Whatever w2(200);
	w1.getA();
	w2.getA();
	B b;
	w1.someFun(b);
	return 0;
}
