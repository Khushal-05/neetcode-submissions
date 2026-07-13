class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n = nums.size();
        if(nums.empty()){
            return {};
        }

        for(int i=0; i<n; i++){
            int complement = target - nums[i];
            if(m.find(complement)!= m.end()){
                return {m[complement], i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
