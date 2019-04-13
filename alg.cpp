#include<iostream>
#include<set>
#include<fstream>

using namespace std;

int main(){
	ofstream myfile("random.txt");
	srand(time(nullptr));
	set<int> Randomset;
	for(int i=0;i<50;i++)
		Randomset.insert(rand()%100);
	if(myfile.is_open())
	{
		for(auto &j:Randomset)
			myfile<<j;
		myfile.close();
	}
	else cout<<"Unable to open file";
	return 0;
}
