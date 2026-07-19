class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()){
            return "";
        }

        vector<int> countT(128, 0);
        int uniqueTargetKeys = 0;
        for(char c : t){
            if(countT[c] == 0) uniqueTargetKeys++;
            countT[c]++;
        }

        int left=0, right=0, formedKeys=0, st_idx=0;
        int minlen = INT_MAX;
        vector<int> countS(128, 0);

        for(right=0; right<s.size(); right++){
            char right_char = s[right];
            countS[right_char]++;
            
            if(countT[right_char] > 0 && countT[right_char] == countS[right_char]){
                formedKeys++;
            }

            while(formedKeys == uniqueTargetKeys){
                int currlen = right-left+1;
                
                if(currlen < minlen){
                    minlen = currlen;
                    st_idx = left;
                }

                char left_char = s[left];
                countS[left_char]--;

                if(countT[left_char] > 0 && countT[left_char] > countS[left_char]){
                    formedKeys--;
                }

                left++;
            }
        }
        return minlen == INT_MAX ? "" : s.substr(st_idx, minlen);
    }
};
