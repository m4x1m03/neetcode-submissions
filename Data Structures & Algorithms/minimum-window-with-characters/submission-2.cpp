class Solution {
public:
    string minWindow(string s, string t) {
        int best_start = 0;
        int best_len = INT_MAX;
        int have = 0;

        unordered_map<char, int> to_find;
        for(char c : t){
            to_find[c]++;
        }

        int start = 0;
        for(int end = 0; end < s.size(); end++){
            // if the current letter is one we are looking for, increase have counter, decrease how many we need of that letter (make sure its not 0 or less to prevent incrementing have when not needed)
            if(to_find.count(s[end])){
                to_find[s[end]]--;
                if(to_find[s[end]] >= 0){
                    have++;
                }
            }
            // once we have all letters in window, shrink left until count is not equal anymore, update best result at every shrink
            if(have == t.size()){
                while(have == t.size()){
                    if(end - start + 1 < best_len){
                        best_len = end - start + 1;
                        best_start = start;
                    }
                    if(to_find.count(s[start])){
                        to_find[s[start]]++;
                        if(to_find[s[start]] > 0){
                            have--;
                        }
                    }
                    start++;
                }
            }
        }
        return best_len == INT_MAX ? "" : s.substr(best_start, best_len);
    }
};
