#include<iostream>
#include<string>
#include<vector>


using namespace std;

int main(){
	std::string name;
	std::cout<<"please enter your name \n>\a";
	std::cin>>name;
	std::cout<<"Hi "
		<<name
		<<" howdy do??!!" << std::endl;
	std::cout<<5u-10<<endl;
	cout<<float(5)/2<<endl;
	
	cout << "How many variables do you want? ";
	int nVars;
	cin >> nVars;
 
	int anArray[nVars]; 
	
	int* ptr=new int(5);
	cout<<"..."<<*ptr<<endl;
	delete ptr;
	ptr=0;
	
	int norm=10;
	int to_const=20;
	int *const ptr2=new int(100);
	norm=30;
	*ptr2=10;
	cout<<"val of const ptr after norm change "<<*ptr2<<endl;
	delete ptr2;
	
	const int *ptr3=&to_const;
	cout<<"before touching.."<<*ptr3<<endl;
	to_const=-12;
	cout<<"after touching..."<<*ptr3<<endl;
	
	
	
	std::vector<int> myvector (5);

  	int* p = myvector.data();

  	*p = 10;
  	++p;
  	*p = 20;
  	p[1] = 100;

  	std::cout << "myvector contains:";
  	for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  	std::cout << '\n';
  	myvector.push_back(899);
  	//myvector.clear();
  	cout<<myvector.size()<<endl;
  	int cons_test=99;
  	int &ref=cons_test;
  	cons_test=1;
  	ref=20;
  	int another=-12;
  	ref=another;
  	cout<<"ref "<<ref<<"parent var "<<cons_test<<endl;
}











