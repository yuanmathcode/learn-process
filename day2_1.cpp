#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#include<algorithm>

using namespace std;

class op{
      public:
      int index;
      char type;
      };
class dev{
      public:
      int index;
      char type;
      };
vector<op*> operation;
vector<dev*> device;
map<int,op*> operation_o;
map<int,dev*> device_o;
map<char,map<int,op*>> device_map;
set<int> typea;
set<int> typeb;
set<int> typec;
set<int> typed;
/* device_map[i][j]=a means:the j-th operation happens in device i with type a. 
device_map[i][j]=b means: the j-th operation happens in device i with type b.
etc*/

int main()
{
    srand(time(nullptr));
    char *op_type="abcd";
    char *dv_type="abcd";
    //build operation

    for(int i=0;i<50;i++){
        auto adress=rand()%4+1;
        operation_o[i]=new op;
        operation_o[i]->index=i; 
        for(auto j=0;j<adress;j++)
            operation_o[i]->type=op_type[j];
        operation.push_back(operation_o[i]);
       //cout<<operation[i]->index<<"  "<<operation[i]->type<<"   "<<endl;
    }

     for(int i=0;i<50;i++){
         auto adress=rand()%4+1;
         device_o[i]=new dev;
         device_o[i]->index=i;
         for(auto j=0;j<adress;j++)
             device_o[i]->type=dv_type[j];
         device.push_back(device_o[i]);
         cout<<device[i]->index<<"  "<<device[i]->type<<"   "<<endl;
    }}
   
   /* for(int j=0;j<operation.size();j++){
        if(operation[j]->type=='a'){
           for(int i=0;j<operation.size();j++){        
	       if(device[i]->type=='a'){
                  device_map[i][j]=new op;
	          device_map[i][j]->index=device[i]->index;
                  }
               cout<<device[i]->index<<"  "<<endl;
	         // device_map[i][j]->type=device[i]->type;
                 // typea.insert(device[i]->index);}
	//	  int mic=49;
                 // for(auto it=typea.begin();it!=typea.end();it++)
          //        {
          //         if(*it<mic)
	//	  {mic=*it; }
                 // cout<<*typea.begin()<<endl;    
}
}
}}*/
