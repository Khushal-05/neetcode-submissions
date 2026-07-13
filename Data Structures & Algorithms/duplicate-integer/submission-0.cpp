class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]]++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};