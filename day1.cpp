#include<iostream>
#include<set>
#include<vector>

using namespace std;
int main(){
  /*  set<int> s1;
    for(int i=1;i<101;i++)
        s1.insert(s1.end(),i);
    for(set<int>::iterator setit=s1.begin();setit!=s1.end();setit++)
        cout<<*setit<<endl;*/

    srand(time(nullptr));

/*    while(a<50)
    {
    vector<int> nums(10);
    for (int i = 0; i < 10; ++i)
    {
        nums[i] = 1 + (rand() % 100);
        cout<< nums[i] << " "<<endl;
        cout<< nums.size()<<endl;
    }
    
    a++;	
    }*/
    vector<set<int>> vector_of_sets;
    for(auto count=1; count<=50; count++)
    {
        set<int> newset;
	auto size=rand()%10+1;
        for(int i=0;i<size;i++)
            newset.insert(1+(rand()%100));
	vector_of_sets.push_back(newset);
	

/*        for(set<int>::iterator setit=rs.begin();setit!=rs.end();setit++)
            cout<<*setit<<endl;*/
 
    }
/*    while(a<50)
    {
        set<int> rs;
        for(int i=0;i<10;i++) 
            rs.insert(1+(rand()%100));
        for(set<int>::iterator setit=rs.begin();setit!=rs.end();setit++)
            cout<<*setit<<endl;

        a++;
    }*/
    vector<vector<set<int>>> newV;
    
    for(auto count=1;count<=10;count++)
    {
    vector<set<int>> newS;
    auto size=rand()%5+1;
    for(int i=0;i<size;i++)
    {
         auto id=rand()%50;
	 newS.push_back(vector_of_sets[id]);
	} 
    newV.push_back(newS);
    }
    
    set<int> finalSet;
    for(auto &i:newV)
    {
    auto id=rand()%(i.size())+1;
    auto temp=i[id];
    for(auto &h:temp)
    finalSet.insert(h);
    }

}
