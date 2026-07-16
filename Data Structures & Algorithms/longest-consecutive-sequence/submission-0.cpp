class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;   
        for(int v : s){
            if(!s.count(v-1)){
                // start point of sequence
                int length = 0;
                while(s.count(v + length)){
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
