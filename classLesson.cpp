#include<iostream>

using namespace std;

class Base
{
public:
	Base(int arg)
	{
		if(arg==10)
		{
			cout<<"default"<<endl;
		}
		else
		{
			cout<<"arg = "<<arg<<" in base"<<endl;
		}
	}
		
	Base(string str)
	{
		cout<<"in overloaded cons "<<str<<endl;
	}
	
	 ~Base()
	{
		cout<<"destroying base"<<endl;
	}
};

class Derived: public Base{
public:
	Derived()
	:Base(90)
	{
		cout<<"in derived"<<endl;
	}
	
	~Derived()
	{
		cout<<"destroying derived"<<endl;
	}
};

class Final
{
public:
	int data;
	Final(int data=10)
	{
		this->data=data;
	}
	
	void set(int data)
	{
		this->data=data;
	}
	
	int get()
	{
		return data;
	}
};



int main()
{
	//Derived derived;
	Base b=Derived();
	return 0;
}






















