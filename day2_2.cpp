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

int main()
{
    srand(time(nullptr));
    char *op_type="abcd";
    char *dv_type="abcd";
   
    for(int i=1;i<=50;i++){
        op *op_ele=new op;
        op_ele->index=i;
        auto adress=rand()%4+1;
	for(auto j=0;j<adress;j++)
	    op_ele->type=op_type[j];
        operation.push_back(op_ele);
    
        //cout<<op_ele->index<<"  "<<op_ele->type<<"  "<<endl;
    }
    for(int i=1;i<=50;i++){
        dev *dev_ele=new dev;
        dev_ele->index=i;
        auto adress=rand()%4+1;
        for(auto j=0;j<adress;j++)
            dev_ele->type=dv_type[j];
        device.push_back(dev_ele);
     }
     
    map<int,map<int,dev*>> op_dev_map; 
    //if op[i]->type=dev[j]->type,then op_dev_map[{op[i],dev[j]}]=1;
    //if ......,then ....=0;
    for(int i=0;i<50;i++)
    for(int j=0;j<50;j++)
    if(operation[i]->type=='a'&&device[j]->type=='a'){
        op_dev_map[i][j]=new dev;
        op_dev_map[i][j]->index=device[j]->index;
        op_dev_map[i][j]->type=device[j]->type;
        //cout<<device[j]->index<<"  "<<device[j]->type<<"  "<<endl;
        cout<<op_dev_map[i][j]->index<<"  "<<op_dev_map[i][j]->type<<" "<<endl;}

    for(int i=0;i<50;i++)
    for(int j=0;j<50;j++)
    if(operation[i]->type=='b'&&device[j]->type=='b'){
        op_dev_map[i][j]=new dev;
        op_dev_map[i][j]->index=device[j]->index;
        op_dev_map[i][j]->type=device[j]->type;
        //cout<<device[j]->index<<"  "<<device[j]->type<<"  "<<endl;
        cout<<op_dev_map[i][j]->index<<"  "<<op_dev_map[i][j]->type<<" "<<endl;}


    for(int i=0;i<50;i++)
    for(int j=0;j<50;j++)
    if(operation[i]->type=='c'&&device[j]->type=='c'){
        op_dev_map[i][j]=new dev;
        op_dev_map[i][j]->index=device[j]->index;
        op_dev_map[i][j]->type=device[j]->type;
        //cout<<device[j]->index<<"  "<<device[j]->type<<"  "<<endl;
        cout<<op_dev_map[i][j]->index<<"  "<<op_dev_map[i][j]->type<<" "<<endl;}


    for(int i=0;i<50;i++)
    for(int j=0;j<50;j++)
    if(operation[i]->type=='d'&&device[j]->type=='d'){
        op_dev_map[i][j]=new dev;
        op_dev_map[i][j]->index=device[j]->index;
        op_dev_map[i][j]->type=device[j]->type;
        //cout<<device[j]->index<<"  "<<device[j]->type<<"  "<<endl;
        cout<<op_dev_map[i][j]->index<<"  "<<op_dev_map[i][j]->type<<" "<<endl;}

}
