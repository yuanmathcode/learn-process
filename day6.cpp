#include<vector>
#include<set>
#include<utility>
#include<iostream>

using namespace std;

/* Generate #size sets, store them in a vector.
 * Each set contains n integer numbers range in (a,b),
 * where n \in (cardinality.first, cardinality.second), a = range.first, b = range.second
 */
vector<set<int>> setsGenerator (int size, pair<int,int> cardinality, pair<int,int> range){
	vector<set<int>> vec_of_sets;
	srand(time(nullptr));
	for(auto count=1;count<=size;count++){
		set<int> Newset;
		int temp2=cardinality.first+rand()%(cardinality.second-cardinality.first+1);
		for(int i=1;i<=temp2;i++){
			Newset.insert(range.first+rand()%(range.second-range.first+1));
		}	
		vec_of_sets.push_back(Newset);
	}
	return vec_of_sets;
}


/* Generate #size sets, store them in a vector.
 * Each set is a set of sets, where the candidate sets come from input.
 * Each set contains n sets, where n \in (cardinality.first, cardinality.second)
 */
vector<set<set<int>>> setOfSetsGenerator (int size, pair<int,int> cardinality, vector<set<int>> input){
	vector<set<set<int>>> vec_of_set_sets;
	srand(time(nullptr));
	for(auto count=1;count<=size;count++){
		set<set<int>> set_of_sets;
		int temp3=cardinality.first+rand()%(cardinality.second-cardinality.first+1);
		for(int i=1;i<=temp3;i++){
			int temp4=rand()%(input.size());
			set_of_sets.insert(input[rand()%(input.size())]);
		}
		vec_of_set_sets.push_back(set_of_sets);
		
	}
	return vec_of_set_sets;
	
}
	
// take a vector of sets of sets as input, output a set of integer numbers
// From each set of sets in the vector, pick exactly one set, and add all the integer numbers contained in this set to the output set.vec<set<set>>>
// Maximize the cardinality of the output set
//if set<set>: 1.size> 2.size,pick 1 and add 1 to mergedset
vector<vector<set<int>>> givennewinput(vector<set<set<int>>> input){
        vector<vector<set<int>>> Newinput;
        vector<set<int>> Newinput_vec;
	for(auto i:input){
		for(auto j:i)
			Newinput_vec.push_back(j);
		Newinput.push_back(Newinput_vec);
		Newinput_vec.clear();
	}
/*	for (auto i : Newinput){
                cout<<"{";
	for (auto j : i){
                cout<<"{";
                        for (auto k : j)
                                cout<<k<<", ";
                                cout<<"}, ";
        }
        cout<<"}"<<std::endl;
        }*/
		
	return Newinput;
}

vector<set<int>> Vecofmergedsets(vector<vector<set<int>>> input,int level,vector<set<int>> array,vector<vector<set<int>>> result){
	if(level==input.size()){
		result.push_back(array);
		return array;
	}
	for(auto i:input[level]){
		array.push_back(i);
		Vecofmergedsets(input,level+1,array,result);
//		array.pop_back();
	}

}
vector<vector<set<int>>> Subsets(vector<vector<set<int>>> input){
	vector<vector<set<int>>> combinations;
	vector<set<int>> arr;
	Vecofmergedsets(input,0,arr,combinations);
	return combinations;
}

int main(){

  	auto cardinality1 = make_pair<int,int>(1,5);
  	auto cardinality2 = make_pair<int,int>(1,3);
  	auto range = make_pair<int,int>(1,50);
  	auto vectorOfSets = setsGenerator(10, cardinality1, range);
  	auto vectorOfSetsOfSets = setOfSetsGenerator(5, cardinality2, vectorOfSets);
  	for (auto i : vectorOfSetsOfSets){
		cout<<"{";
    	for (auto j : i){
      		cout<<"{";
			for (auto k : j)
	        		cout<<k<<", ";
				cout<<"}, ";
	}
	cout<<"}"<<std::endl;
  	}
	auto Newinput=givennewinput(vectorOfSetsOfSets);
	auto subsets=Subsets(Newinput);
       /* for (auto i : subsets){
                cout<<"{";
        for (auto j : i){
                cout<<"{";
                        for (auto k : j)
                                cout<<k<<", ";
                                cout<<"}, ";
        }
        cout<<"}"<<std::endl;
        }*/

/*	auto mergedSet = maximizeMergedSet(vectorOfSetsOfSets);

	cout<<"Merged set: {";

	for (auto i : mergedSet)

			cout<<i<<", ";

	cout<<"}"<<endl;
*/
}
