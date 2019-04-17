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
  //edit here;
}


/* Generate #size sets, store them in a vector.
 * Each set is a set of sets, where the candidate sets come from input.
 * Each set contains n sets, where n \in (cardinality.first, cardinality.second)
 */
vector<set<set<int>>> setOfSetsGenerator (int size, pair<int,int> cardinality, vector<set<int>> input){
  //edit here;
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
}
