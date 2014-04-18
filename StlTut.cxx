using namespace std;
#include<iostream>
#include<vector>

int main(void)
{	vector<int> myVector;
	cout<<"size of vector at initialization: "<<myVector.size()<<endl;
	for(int i = 0; i < 5; ++i)
	{
		myVector.push_back(i);
	}
	cout<<"size of vector after push_back: "<<myVector.size()<<endl; 
	return 0;
}