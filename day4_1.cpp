#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#include<algorithm>
#include<string>
#include<memory>

using namespace std;

class op;
class op{
private:
	int _index;
	char _type;
//	double _time;
        set<shared_ptr<op>> _child;

public:
	double time;
	op(int given_index,char given_type)
	:_index(given_index),_type(given_type){}
       /* op(int given_index, char given_type, shared_ptr<op> &given_child)
        :_index(given_index),_type(given_type){
                _child.insert(given_child);
        }*/
	set<shared_ptr<op>> &child() {return _child;}
        const char type() {return _type;}
	const int index() {return _index;}
//	double time() {return _time;}
	
};

class dev{
private:
	int _index;
	char _type;
//	double  _time;
public:
	double time;
	const int index() {return _index;}
	const char type() {return _type;}
//	const double time() {return _time;}
	dev(int given_index,char given_type)
	:_index(given_index),_type(given_type){}
};

vector<shared_ptr<op>> operation;
vector<shared_ptr<dev>> device;
map<shared_ptr<op>,shared_ptr<dev>> op_dev_map;

int main(){
	vector<char> gtype;
        gtype.push_back('a');
        gtype.push_back('b');
        gtype.push_back('c');
        gtype.push_back('d');
	gtype.push_back('e');
	for(int i=0;i<50;i++){
		if(i%5==0)
			operation.push_back(make_shared<op>(i,gtype[0]));
		if(i%5==1)
			operation.push_back(make_shared<op>(i,gtype[1]));
                if(i%5==2)
                        operation.push_back(make_shared<op>(i,gtype[2]));
                if(i%5==3)
                        operation.push_back(make_shared<op>(i,gtype[3]));
                if(i%5==4)
                        operation.push_back(make_shared<op>(i,gtype[4]));
//	cout<<operation[i]->index()<<"  "<<operation[i]->type()<<"  "<<endl;
	}
        for(int i=0;i<50;i++){
		if(i%2==1){
                	operation[i]->child().insert(operation[i-1]);
//			cout<<"the child of "<<operation[i]->index()<<" is  "<<operation[i]->child()->index()<<endl;	
		}
		for(auto &it:operation[i]->child())
			cout<<it->index()<<"  "<<endl;
	}
	
	for(int i=0;i<10;i++){
		if(i%5==0)
			device.push_back(make_shared<dev>(i,gtype[0]));
		if(i%5==1)
			device.push_back(make_shared<dev>(i,gtype[1]));

		if(i%5==2)
			device.push_back(make_shared<dev>(i,gtype[2]));

		if(i%5==3)
			device.push_back(make_shared<dev>(i,gtype[3]));
		if(i%5==4)
			device.push_back(make_shared<dev>(i,gtype[4]));
		cout<<device[i]->index()<<"  "<<device[i]->type()<<"  "<<endl;

	}
}
void calculate_time(map<shared_ptr<op>,shared_ptr<dev>>){
	set<double> time_of_dev;
	for(auto &i:operation){
		for(auto &j:device){
			if(op_dev_map[i]==j){
				j->time+=i->time;
			}
			time_of_dev.insert(j->time);
			for(auto &h:time_of_dev)
				cout<<*time_of_dev.end()<<"  "<<endl;
		}
	}
}




