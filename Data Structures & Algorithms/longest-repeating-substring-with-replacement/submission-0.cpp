class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0, maxlen = 0, maxf = 0;
        vector<int> char_count(26, 0);

        for(int right = 0; right < n; right++){
            char_count[s[right] - 'A']++;
            maxf = max(maxf, char_count[s[right] - 'A']);

            while((right-left+1) - maxf > k){
                char_count[s[left] - 'A']--;
                left++;
            }
            
            maxlen = max(maxlen, (right-left+1));
        }
        return maxlen;
    }
};
