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
	char  _type;
public:
	node()=default;
	node(int given_id,char given_type)
	:_id(given_id),_type(given_type){}
	int &id() {return _id;}
	char &type() {return _type;}
	void define_id(int g_id){
		_id=g_id;}
	void define_type(char g_type){
		_type=g_type;}
};

class edge{
private:
	int _id;
	pair<shared_ptr<node>,shared_ptr<node>> _origintoend;
	shared_ptr<node> _origin;
	shared_ptr<node> _end;
	double _length;
public:
	edge()=default;
	edge(shared_ptr<node> given_origin,shared_ptr<node> given_end, double given_length)
	:_origin(given_origin),_end(given_end),_length(given_length){}
	int &id() {return _id;}
	pair<shared_ptr<node>,shared_ptr<node>> &origintoend() {return _origintoend;}
	const shared_ptr<node> &origin() {return _origin;}
	const shared_ptr<node> &end() {return _end;}
	double &length() {return _length;}
        void define_id(int g_id){
                _id=g_id;}
        void define_length(double g_length){
                _length=g_length;}
	void define_orgin(shared_ptr<node> g_orgin){
		_origin=g_orgin;}
	void define_end(shared_ptr<node> g_end){
		_end=g_end;}

};

/*class cchannel{
private:
	int _id;
	set<shared_ptr<node>> _ntoch;
public:
	const int id() {return _id;}
	set<shared_ptr<node>> &ntoch() {return _ntoch;}
};*/
vector<shared_ptr<node>> vecnode;
vector<shared_ptr<edge>> vecedge;

void readfile(const char* filename){
	ifstream read(filename);
	string str_temp;
	int int_temp,int_temp1,int_temp2;
	double double_temp;
	while (read>> str_temp){
		//read inlets
		if(str_temp=="Inlet:"){
			while(read>>str_temp){
				if(str_temp=="end")
					break;
			int_temp=stoi(str_temp);
			shared_ptr<node> node_temp=make_shared<node>(int_temp,'i');
			vecnode.push_back(node_temp);
			}
		}
		//read outlet
		if(str_temp=="Outlet:"){
                        while(read>>str_temp){
                                if(str_temp=="end")
                                        break;
                        int_temp=stoi(str_temp);
                        shared_ptr<node> node_temp=make_shared<node>(int_temp,'o');
                        vecnode.push_back(node_temp);
                        }
                }
		//read branch
		if(str_temp=="Branch:"){
                        while(read>>str_temp){
                                if(str_temp=="end")
                                        break;
                        int_temp=stoi(str_temp);
                        shared_ptr<node> node_temp=make_shared<node>(int_temp,'b');
                        vecnode.push_back(node_temp);
                        }
                }
		//read valve
		if(str_temp=="Valve:"){
                        while(read>>str_temp){
                                if(str_temp=="end")
                                        break;
                        int_temp=stoi(str_temp);
                        shared_ptr<node> node_temp=make_shared<node>(int_temp,'v');
                        vecnode.push_back(node_temp);
                        }
                }
		if(str_temp=="Edge:"){
	//		int index_temp=0;
			while(getline(read,str_temp)){
				if(str_temp=="end")
					break;
				if(str_temp.empty())
					continue;
	//		index_temp++;
			istringstream edge_record(str_temp);
			edge_record>>int_temp1>>int_temp2>>double_temp;
			shared_ptr<node> node_temp1, node_temp2;
			for(auto &i:vecnode){
				if(i->id()==int_temp1)
					node_temp1=i;
			}
			for(auto &j:vecnode){
				if(j->id()==int_temp2)
					node_temp2=j;
			}
			shared_ptr<edge> edge_temp=make_shared<edge>(node_temp1,node_temp2,double_temp);
			vecedge.push_back(edge_temp);
			}

		}
	}
}
int main(){
	readfile("design.txt");
	for(int i=0;i<vecedge.size();i++)
		cout<<vecedge[i]->length()<<" "<<endl;
}














