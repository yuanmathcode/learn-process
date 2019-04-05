#include<iostream>
#include<map>
#include<set>
#include <vector>
#include <fstream>
#include <string>
#include <memory>
#include <cstring>

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

class edge{
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
};

shared_ptr<node> singlenode;
shared_ptr<edge> singleedge;
void readfile(const char* filename){
	string node_type;
	int node_index;
	fstream read;
	read.open("design.txt",fstream::in);
	while(1){
		read>>node_type;
		if(read.eof())
			break;
		singlenode->type()=node_type;
		read>>node_index;
		singlenode->id()=node_index;
	}
	cout<<singlenode->id()<<"  "<<singlenode->type()<<" "<<endl;
}

int main(){
readfile("design.txt");
}






