class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;
        //prefix
        output.push_back(1);
        int prefix = 1;
        for(int i=1; i<n; i++){
            prefix *= nums[i-1];
            output.push_back(prefix);
        }

        //postfix
        int postfix = 1;
        for(int i = n-1; i>=0; i--){
            output[i] *= postfix;
            postfix *= nums[i];
        }

        return output;
    }
};
