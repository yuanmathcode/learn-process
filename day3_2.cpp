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
private:
	int _index;
	char _type;
public:
	const int index() {return _index;}
	const char type() {return _type;}
	op(int given_index, char given_type)
	:_index(given_index), _type(given_type){}
};

class dev{
private:
	int _index;
	char _type;
public:
	const int index() {return _index;}
	const char type() {return _type;}
	dev(int given_index,char given_type)
        :_index(given_index),_type(given_type){}
};

vector<shared_ptr<op>> operation;
vector<shared_ptr<dev>> device;
//operation_backup.push_back(make_shared<op>(1, 'a'));
map<char, shared_ptr<dev>> type_dev_map;
map<shared_ptr<op>,shared_ptr<dev>> op_dev_map;
int main()
{
        srand(time(nullptr));
        vector<char> gtype;
        gtype.push_back('a');
        gtype.push_back('b');
        gtype.push_back('c');
        gtype.push_back('d');

        for(int i=0;i<50;i++){
                auto j=rand()%4;
        //      op_ele=make_shared<op>();(i,gtype[j]);
                                 operation.push_back(make_shared<op>(i,gtype[j]));
//                                        cout<<operation[i]->index()<<"  "<<operation[i]->type()<<"  "<<endl;
        }

//      for (auto & i:operation)
//              cout<<i->index()<<"  "<<i->type()<<"   "<<endl;

        for(int i=0;i<50;i++){
                auto j=rand()%4;
                                device.push_back(make_shared<dev>(i,gtype[j]));
//                                cout<<device[i]->index()<<"  "<<device[i]->type()<<"  "<<endl;
	}
        for(auto &i:gtype){
                for(auto &j:device){
                        if(j->type()==i){
                                type_dev_map[i]=j;
                                break;
                        }
                }
        }
        for(auto &i:operation)
                op_dev_map[i]=type_dev_map[i->type()];

        for(auto &i:type_dev_map)
                cout<<"type  "<<i.first<<"  "<<i.second->index()<<endl;
        for(auto &i:op_dev_map)
                cout<<"Opeartion "<<i.first->index()<<" has device "<<i.second->index()<<endl;
}

                                   
