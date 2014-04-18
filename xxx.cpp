#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Container
{
private:
	int m_Var1;
	string m_VarName;
public:
	Container() : m_Var1(0), m_VarName("default")
	{

	}

	Container(string name) : m_Var1(0), m_VarName(name)
	{

	}

	void setVar1(int var)
	{
		m_Var1 = var;
	}

	int getVar1() const
	{
		return m_Var1;
	}

	void setVarString(const string& str)
	{
		m_VarName = str;
	}

	const string& getVarString()
	{
		return m_VarName;
	}

};


class Parent
{
protected:
	int m_var1;
public:
	Parent(int var): m_var1(var)
	{
	}

	virtual void setVar1(int var) = 0;

	virtual int getVar1()
	{
		//cout<<"in Parent"<<endl;
		return m_var1;
	}
};

class Child : public Parent
{
public:
	Child(int var): Parent(var)
	{
	}

	int getVar1()
	{
		//cout<<"in child"<<endl;
		return m_var1;
	}

	void setVar1(int var)
	{
		m_var1 = var;
	}
};


int main()
{
	Container def;
	Container custom("custom string");

	def.setVarString("new string");

	cout<<def.getVarString()<<endl;

	Child child(1000);
	cout<<child.getVar1()<<endl;

	Parent& ob = child;
	cout<<ob.getVar1()<<endl;

	Parent* obj = new Child(0);
	cout<<obj->getVar1()<<endl;
	delete obj;

	vector<Child> list(10,Child(100));
	for(int i = 0; i < 100; ++i)
	{
		cout<<"list["<<i<<"]"<<" = "<<list[i].getVar1()<<endl;
	}

}
