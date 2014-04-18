#include<iostream>

using namespace std;

#include <iostream>

class SomeClass {
  private:
    int private1, private2;
  public:
    SomeClass ()
    {
        private1 = private2 = 35;
    }
    void PrintPrivate()
    {
        cout << "private1 = " << private1
             << ", private2 = " << private2 << endl;
    }
    
    
    
};

SomeClass &getClass1()//wrong way!!!! never return a reference to a local var;
{
    SomeClass first;
    return first;
}

SomeClass &getClass2()
{
    SomeClass *second = new SomeClass;
    return *second;
}

SomeClass &getClass3(SomeClass& arg){
	cout<<"in getClass3 ";
	arg.PrintPrivate();
	return arg;
}

int main ()
{
    SomeClass sc1 = getClass1();
    sc1.PrintPrivate();
    SomeClass &sc2 = getClass2();
    sc1.PrintPrivate();
    sc2.PrintPrivate();
    
    SomeClass sc3=getClass3(sc2);
    sc3.PrintPrivate();

    delete &sc2;
    return(0);
}
