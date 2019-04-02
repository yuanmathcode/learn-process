#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#include<algorithm>
#include<string>

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

    for(int i=0;i<50;i++){
        op *op_ele=new op;
        op_ele->index=i;
        auto adress=rand()%4+1;
        for(auto j=0;j<adress;j++)
            op_ele->type=op_type[j];
        operation.push_back(op_ele);

        //cout<<op_ele->index<<"  "<<op_ele->type<<"  "<<endl;
    }
    for(int i=0;i<50;i++){
        dev *dev_ele=new dev;
        dev_ele->index=i;
        auto adress=rand()%4+1;
        for(auto j=0;j<adress;j++)
            dev_ele->type=dv_type[j];
        device.push_back(dev_ele);
     }
    map<op*,dev*> op_dev_map;
    set<int> typea;
    set<int> typeb;
    set<int> typec;
    set<int> typed;

    for(int i=0;i<50;i++)
    for(int j=0;j<50;j++)
    if(operation[i]->type==device[j]->type)
    {
        op_dev_map[operation[i]]=device[j];
	op_dev_map[operation[i]]->index=j;
	op_dev_map[operation[i]]->type=device[j]->type;
	if(device[j]->type=='a')
	  typea.insert(device[j]->index);
        if(device[j]->type=='b')
          typeb.insert(device[j]->index);
        if(device[j]->type=='c')
          typec.insert(device[j]->index);
        if(device[j]->type=='d')
          typed.insert(device[j]->index);
        for(auto &it:typea)
	   cout<<*typea.begin()<<" "<<*typeb.begin()<<"  "<<*typec.begin()<<"  "<<*typed.begin()<<"  "<<endl;

}


    


}








