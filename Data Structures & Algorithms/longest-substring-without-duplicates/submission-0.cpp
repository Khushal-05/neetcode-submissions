class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0, r=0, maxlen=0, len=0;
        unordered_set<char> window;
        while(l<=r && r<n){
            if(window.find(s[r]) == window.end()){
                window.insert(s[r]);
                len++;
                maxlen = max(len, maxlen);
                r++;
            }
            else{
                window.erase(s[l]);
                len--;
                l++;
            }
        }
        return maxlen;
    }
};
