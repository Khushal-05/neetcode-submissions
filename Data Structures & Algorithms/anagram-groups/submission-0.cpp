class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> ans;
        int n = strs.size();
        for(int i=0; i<n; i++){
            string sort_strs = strs[i];
            sort(sort_strs.begin(), sort_strs.end()); // because sort() sorts in-place and return void it cannot be assigned directly to a string variable
            m[sort_strs].push_back(strs[i]); // assigning value to a vector where m[sort_strs] is the name of that vector
        }

        for(const auto &pairs : m){
            ans.push_back(pairs.second); // second is a member variable, not a function --> second() X
         }
        return ans;
    }
};
