class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 0;
        int start = 0;
        int max_freq = 0;
        vector<int> count(26, 0);
        for(int end = 0; end<s.size(); end++){
            count[s[end]-'A']++;
            max_freq = max(max_freq, count[s[end]-'A']);

            while((end - start + 1) - max_freq > k){
                count[s[start]-'A']--;
                start++;
            }

            result = max(result, (end-start+1));
        }
        return result;
    }
};
