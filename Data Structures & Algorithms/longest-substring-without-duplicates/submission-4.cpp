class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // dynamic hash map {char -> index}
        // once we have a duplicate, shrink the window to the first occurence
        unordered_map<char, int> seen;
        int start = 0;
        int longest = 0;
        for(int i = 0; i<s.length(); i++){
            // if char is seen, shrink left side to the next letter of last seen
            // remove char from seen
            if(seen.find(s[i]) != seen.end() && seen[s[i]] >= start){
                start=seen[s[i]]+1;
            }

            seen[s[i]] = i;
            
            longest = max(longest, (i-start+1));

        }
        return longest;
    }
};
