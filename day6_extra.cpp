/* Generate #size sets, store them in a vector.
 * Each set contains n integer numbers range in (a,b),
 * where n \in (cardinality.first, cardinality.second), a = range.first, b = range.second
 */


/* Generate #size sets, store them in a vector.
 * Each set is a set of sets, where the candidate sets come from input.
 * Each set contains n sets, where n \in (cardinality.first, cardinality.second)
 */

// take a vector of sets of sets as input, output a set of integer numbers
// From each set of sets in the vector, pick exactly one set, and add all the integer numbers contained in this set to the output set.vec<set<set>>>
// Maximize the cardinality of the output set
//if set<set>: 1.size> 2.size,pick 1 and add 1 to mergedset
vector<vector<set<int>>> maximizeMergedSet(vector<set<set<int>>> input){
        vector<vector<set<int>>> Newinput;
        vector<set<int>> Newinput_vec;
        set<int> Newinput_set;
        set<set<int>> ori_Set_sets;

        for(auto i:input){
                for(auto j:i){
                        for(auto h:j)
                                Newinput_set.insert(h);
                        Newinput_vec.push_back(Newinput_set);
                }
                Newinput.push_back(Newinput_vec);
        }


/*      for(auto i:input){
                for(auto j:i){
                        if(j.size()>compareset.size()){
                                compareset=j;
                        }
/*              for (auto i : Newinput){
                cout<<"{";
        for (auto j : i){
                cout<<"{";
                        for (auto k : j)
                                cout<<k<<", ";
                                cout<<"}, ";
        }
        cout<<"}"<<std::endl;
        }
*/
        for(int i=0;i<Newinput.size();i++){
                for(auto h:Newinput[i][0])
                        mergedset.insert(h);
                vecofmergedsets.push_back(mergedset);
                mergedset.clear();
        }
        
        /*vector<vector<set<int>>> maximizeMergedSet(vector<set<set<int>>> input){
        vector<vector<set<int>>> Newinput;
        vector<set<int>> Newinput_vec;
        for(auto i:input){
                for(auto j:i)
                        Newinput_vec.push_back(j);
                Newinput.push_back(Newinput_vec);
                Newinput_vec.clear();
        }

        return Newinput;
}*/
/*      auto newinput=maximizeMergedSet(vectorOfSetsOfSets);
        for (auto i : newinput){
                cout<<"{";
        for (auto j : i){
                cout<<"{";
                        for (auto k : j)
                                cout<<k<<", ";
                                cout<<"}, ";
        }
        cout<<"}"<<std::endl;
        }*/



