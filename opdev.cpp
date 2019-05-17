#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<memory>
#include<iomanip>
#include<algorithm>

using namespace std;

class operation;
class operation{
private:
	int _id;
	int _time;
public:
	const int &time(){return _time;}	
	const int &id(){return _id;}
	operation(int given_id, int given_time)
	:_id(given_id), _time(given_time){}
};

class device{
private:
	int _id;
public:
	const int &id(){return _id;}
	device(int given_id):_id(given_id){}
};

class variable{
public:
	int id;
	int type;
	double upbound;
	double lobound;
	bool bool_value;
	int int_value;
	double double_value;
	set<int> constr_involved;
	map<int,double> constr_coeff;

};
int objcons;
int sum_constr;
map<int,int> constr_sense_map;
map<int,double> constr_rightside_map;
map<int,set<shared_ptr<variable>>> constr_variable_map;
vector<shared_ptr<variable>> vvar;
map<int,map<int,shared_ptr<variable>>> device_map;
shared_ptr<variable> Finaltime;
map<int,shared_ptr<variable>> device_working;
vector<shared_ptr<operation>> operations;
vector<shared_ptr<device>> devices;


int main(int argc, char* argv[]){
        operations.push_back(make_shared<operation>(1, 10);
	operations.push_back(make_shared<operation>(2, 20);
        operations.push_back(make_shared<operation>(3, 30);
        operations.push_back(make_shared<operation>(4, 40);
	operations.push_back(make_shared<operation>(5, 50);
	operations.push_back(make_shared<operation>(6, 60);
	for(int j=1;j<=3;j++)
		devices.push_back(make_shared<device>(j));
	if(argc=1){
		set_device_working_map();
		set_constraint_group1();
		set_device_workingtime();
		set_constraint_group2();
		set_final_time();
		set_constraint_group3();
		objcons=sum_constr;
		funcGurobi(30,0,1);
	}			
}

/*device_map[i][j]=1 means the j-th operation happens in device i;*/
void set_device_working_map(){
	for(int i=1;i<=devices.size();i++){
		for(int j=1;j<=operations.size();j++){
			device_map[i][j]=shared_ptr<variable>;
			device_map[i][j]->id=vvar.size();
			device_map[i][j]->type=0;
			device_map[i][j]->upbound=1;
			device_map[i][j]->lobound=0;
			vvar.push_back(device_map[i][j]);
		}
	}

}

/*each operation can only be executed in one device;*/
void set_constraint_group1(){
	for(int j=1;j<=operations.size();i++){
		sum_constr++;
		constr_sense_map[sum_constr]=0;
		constr_rightside_map[sum_constr]=1;
		for(int i=1;i<=device_map.size();i++){
			constr_variable_map[sum_constr].insert(device_map[i][j]);
			device_map[i][j]->constr_involved.insert(sum_constr);
			device_map[i][j]->constr_coeff[sum_constr]=1;
		}
	}
}

void set_device_workingtime(){
	for(int i=1;i<=devices.size();i++){
		device_working[i]=shared_ptr<variable>;
		device_working[i]->id=vvar.size();
		device_working[i]->type=1;
		device_working[i]->upbound=1000;
		device_working[i]->lobound=0;
		vvar.push_back(device_working[i]);
	}
}

/*device working time equal the sum of d[i][j]*operation->time*/
void set_constraint_group2(){
	for(int i=1;i<=devices.size();i++){
		sum_constr++;
		constr_sense_map[sum_constr]=0;
		constr_rightside_map[sum_constr]=0;
		for(int j=1;j<=operations.size();j++){
			constr_variable_map[sum_constr].insert(device_working[j]);
			device_working[j]->constr_involved.insert(sum_constr);
			device_working[j]->constr_coeff[sum_constr]=-1;
			constr_variable_map[sum_constr].insert(device_map[i][j]);
			device_map[i][j]->constr_involved.insert(sum_constr);
			device_map[i][j]->constr_coeff[sum_constr]=operations[j-1]->time();
		}
	}
}

/*set the final working time of the max of three devices*/

void set_final_time(){
	Finaltime=shared_ptr<variable>;
	Finaltime->id=vvar.size();
	Finaltime->type=1;
	Finaltime->upbound=1000;
	Finaltime->lobound=0;
	vvar.push_back(Finaltime);
}

/*Finaltime>=every device working time*/
void set_constraint_group3(){
	for(int i=1;i<=devices.size();i++){
		sum_constr++;
		constr_sense_map[sum_constr]=1;
		constr_rightside_map[sum_constr]=0;
		constr_variable_map[sum_constr].insert(Finaltime);
		Finaltime->constr_involved.insert(sum_constr);
		FInaltime->constr_coeff[sum_constr]=1;
		constr_variable_map[sum_constr].insert(device_working[i]);
		device_working[i]->constr_involved.insert(sum_constr);
		device_working[i]->constr-coeff[sum_constr]=-1;
	}
}






























