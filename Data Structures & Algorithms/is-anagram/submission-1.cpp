class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> seen1;
        unordered_map<char, int> seen2;
        for(char c : s){
            seen1[c] += 1;
        }

        for(char c : t){
            seen2[c] +=1;
        }
        return seen1 == seen2;
    }
};
