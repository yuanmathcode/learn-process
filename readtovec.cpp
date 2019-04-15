#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<set>

using namespace std;


vector<int> read_to_vec()
{
	ifstream read("random.txt");
	vector<int> v;
	int temp;
	while(read>>temp)
		v.push_back(temp);
	return v;
//	for(auto &i:v)
//		cout<<i<<endl;
}

void sort_from_big_to_small()
{	
	vector<int> v1;
	v1=read_to_vec();
	for(int i=0;i<v1.size()-1;i++){
		for(int j=0;j<v1.size()-i-1;j++){
			if(v1[j]<v1[j+1]){
				int temp=v1[j];
				v1[j]=v1[j+1];
				v1[j+1]=temp;
			}
		}
	}
//	for(auto &i:v1)
//		cout<<i<<endl;
}
set<int> read_to_set()
{
	ifstream read("random.txt");
	set<int> s;
	int temp1;
	while(read>>temp1)
		s.insert(temp1);
	return s;
}
vector<int> read_from_set()
{	
	set<int> s1;
	s1=read_to_set();
	vector<int> v1;
	for(auto &i:s1)
		v1.push_back(i);
        for(int i=0;i<v1.size()-1;i++){
                for(int j=0;j<v1.size()-i-1;j++){
                        if(v1[j]<v1[j+1]){
                                int temp=v1[j];
                                v1[j]=v1[j+1];
                                v1[j+1]=temp;
			}
		}
	}
	for(auto &j:v1)
		cout<<j<<" "<<endl;
	return v1;
	
}
int main(){
        read_to_vec();
	sort_from_big_to_small();
        read_to_set();
	read_from_set();
}

