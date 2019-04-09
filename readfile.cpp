#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<memory>
#include<cstring>
#include<sstream>

using namespace std;

class node{
private:
	int _id;
	string  _type;
public:
	node(int given_id,string given_type)
	:_id(given_id),_type(given_type){}
	int &id() {return _id;}
	string &type() {return _type;}
	void define_id(int g_id){
		_id=g_id;}
	void define_type(string g_type){
		_type=g_type;}
};

/*class edge{
private:
	int _id;
	pair<shared_ptr<node>,shared_ptr<node>> _nton;
	double _length;
public:
	const int id() {return _id;}
	pair<shared_ptr<node>,shared_ptr<node>> &nton() {return _nton;}
	const double length() {return _length;}
};

class cchannel{
private:
	int _id;
	set<shared_ptr<node>> _ntoch;
public:
	const int id() {return _id;}
	set<shared_ptr<node>> &ntoch() {return _ntoch;}
};*/

/*vector<shared_ptr<node>> vecnode;
void readfile(const char* filename){
	string node_type;
	int node_index;
	fstream read;
	read.open("design1.txt",fstream::in);
	while(1){ 
		read>>node_type;
		if(read.eof())
			break;
		shared_ptr<node> node;
		node->type()=node_type;
		read>>node_index;
		node->id()=node_index;
		vecnode.push_back(node);
	}
	cout<<vecnode[node_index]->id()<<"  "<<vecnode[node_index]->type()<<" "<<endl;
}*/

int main(){
	string filename;
	cin>>filename;
	ifstream in(filename);
	if(!in.is_open()){
		cerr<<"Fail to open file: "<<filename<<endl;
		return -1;

	}

	string node_type;
	int node_index;
	vector<shared_ptr<node>> nodes;
	while(getline(in,node_type)){
		istringstream record(node_type);
		shared_ptr<node> node;
		node->type()=node_type;
		while(record>>node_index)
			node->id()=node_index;
		nodes.push_back(node);
	}
}






