#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#include<algorithm>
#include<string>
#include<memory>

using namespace std;

/*
 * task 3. op dev class constructor 
 * task 4. op dev class member declared as private
 * task 5. write class function to realize member access
 *
 * */

class op{
public:
      int index;
      char type;

      op(int given_index, char given_type)
       :index(given_index), type(given_type){}
};

class test{
        private:
            int member1;
            int member2;

        public:
            const int member1(){
              return member1;
            }

            const int member2(){
              return member2;
            }

}

class dev{
public:
      int index;
      char type;
  
      dev(int given_index,char given_type)
        :index(given_index),type(given_type){}
};

vector<shared_ptr<op>> operation;
vector<shared_ptr<dev>> device;
vector<operation> testvec;
testvec.push_back(op(1,'b'));
for(int i=0;i<50;i++){
auto adress=rand
//  randchar.
   //  testvec.push_back(op(nr, randchar.));
//operation_backup.push_back(make_shared<op>(1, 'a'));

//vector<op*> operation;
//vector<dev*> device;

int main()
{
    srand(time(nullptr));
    vector<char> op_type;
    op_type.push_back('a');
    op_type.push_back('b');
    op_type.push_back('c');
    op_type.push_back('d');
    
    vector<char> dev_type;
    dev_type.push_back('a');
    dev_type.push_back('b');
    dev_type.push_back('c');
    dev_type.push_back('d');

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

    map<char, dev*> type_dev_map;

    vector<char> types;
    types.push_back('a');
    types.push_back('b');
    types.push_back('c');
    types.push_back('d');

    for (auto & i : types){
      for (auto & j : device){
        if (j->type == i){
          type_dev_map[i] = j;
          break;
        }
      }
    }

    for (auto & i : type_dev_map)
        cout<<"Type "<<i.first<<" has device "<<i.second->index<<endl;

    for (auto & i : operation){
      op_dev_map[i] = type_dev_map[i->type];
    }

    for (auto & i :op_dev_map)
        std::cout<<"Opeartion "<<i.first->index<<" has device "<<i.second->index<<endl;
    /*    set<int> typea;
    set<int> typeb;
    set<int> typec;
    set<int> typed;
    for (auto & i : device)
      std::cout<<"Device "<<i->index<<" is of type "<<i->type<<std::endl;
    for(auto & i : operation)
        for(auto & j : device)
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
            */
}

