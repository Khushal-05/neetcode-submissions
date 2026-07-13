class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.empty()){
            return {};
        }

        int n = nums.size();
        unordered_map<int, int> m;
        vector<int> ans;

        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }

        vector<pair<int, int>> vec(m.begin(), m.end());
        sort(vec.begin(), vec.end(), [](const auto &a, const auto &b){
            if(a.second != b.second){
                return a.second > b.second;
            }
            return a.first < b.first;
        });

        for(int i=0; i<k; i++){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};
