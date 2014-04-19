using namespace std;
#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<map>

template<typename T>
void printVector(vector<T> vec);

template<typename K, typename V>
void printMap(map<K, V> myMap);
const string getRandomString(int size);
int toss();

typedef vector<int>::iterator vecIter;

int main(void)
{	
	/////////////////////now vector//////////////////////////////////////////////////////////////////////////////////
	vector<int> myVector;
	cout<<"size of vector at initialization: "<<myVector.size()<<endl;
	for(int i = 0; i < 5; ++i)
	{
		myVector.push_back(i);
	}
	cout<<"size of vector after push_back: "<<myVector.size()<<endl; 
	for(vecIter itr = myVector.begin(); itr != myVector.end(); ++itr)
	{
		//cout<<"trying to mod: "<<*itr<<endl;
		*itr = (*itr)*2 + 1; 
	}
	cout<<"vector after mod: "<<endl;
	printVector(myVector);
	int arr[] = {100,200,300,400};
	myVector.assign(arr,arr+4);
	cout<<"after assign:\n";
	cout<<"size of myVector: "<<myVector.size()<<'\n';
	cout<<"capacity: "<<myVector.capacity()<<endl; 
	for(int i = 0; i < myVector.size(); ++i)
	{
		myVector.at(i) = myVector.at(i) - myVector[0];
	}
	printVector(myVector);
	myVector.insert(myVector.begin()+1, arr+1, arr+3);
	printVector(myVector);

	///////////////////////////now map///////////////////////////////////////////////////////////////////////////////

	cout<<"random string is: "<<getRandomString(6)<<"\n";
	map<string, int> myMap;
	vector<string> mapKeys;

	for(int i = 0; i < 5; ++i)
	{	
		string key = getRandomString(5);
		mapKeys.push_back(key);
		myMap.insert(pair<string, int>(key, i));
	}

	printMap<string, int>(myMap);
	myMap["blah"];
	printMap<string, int>(myMap);

	for(int i = 0; i < mapKeys.size(); ++i)
	{
		string updateKey = mapKeys.at(i);
		if(myMap.count(updateKey) == 1)
		{
			myMap.at(updateKey) = myMap.at(updateKey)*20 + i;
		}
	}

	printMap(myMap);

	///////////////////////now string////////////////////////////////////////////////////////////////////////////////

	///////////////////////now list//////////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	return 0;
}

template<typename T>
void printVector(vector<T> vec)
{	if(vec.size() == 0)
	{
		cout<<"empty vector"<<endl;
		return;
	}
	typedef typename vector<T>::const_iterator Iter;
	cout<<"printing vector:"<<endl;
	for(Iter iter = vec.begin(); iter != vec.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
}

const string getRandomString(int size)
{
	map<int, char> myMap;
	for(int i = 97; i <= 122; ++i)
	{
		myMap[i] = static_cast<char>(i);
	}
	string random = "";
	for(int i = 0; i < size; ++i)
	{	char temp = toss() ? myMap.find((rand()%26) + 97)->second : toupper(myMap.find((rand()%26) + 97)->second);
		random.append(1u, temp);
	}

	return random;
}

int toss()
{
	return (rand() % 2);
}

template<typename K, typename V>
void printMap(map<K, V> myMap)
{	
	if(myMap.empty())
	{
		cout<<"map is empty\n";
		return;
	}
	cout<<"___________________________________________________\n";
	typedef typename map<K, V>::const_iterator Iter;
	for(Iter iter = myMap.begin(); iter != myMap.end(); ++iter)
	{
		cout<<iter->first<<" => "<<iter->second<<"\n";
	}
	cout<<"___________________________________________________\n";

}