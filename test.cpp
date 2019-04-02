#include<iostream>
#include<vector>

using namespace std;


int main()
{
    vector<int> v={0,1,2,3,4,5};
    for (const int& i:v)
    cout<<i<<" ";
    }
