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
