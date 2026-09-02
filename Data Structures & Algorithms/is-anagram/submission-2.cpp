class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> seen(26, 0);

        if(s.length() != t.length()){
            return false;
        }

        for(int i=0; i<s.length(); i++){
            seen[s[i]-'a']++;
            seen[t[i]-'a']--;
        }

        for(auto c : seen){
            if(c != 0){
                return false;
            }
        }
        return true;
    }
};
