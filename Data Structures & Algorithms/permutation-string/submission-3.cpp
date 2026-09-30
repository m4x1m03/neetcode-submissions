class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()){return false;}
        int count1[26] = {};
        for(char c : s1){
            count1[c-'a']++;
        }

        int count2[26] = {};
        int start = 0;
        int end = 0;
        for(end; end<s1.length(); end++){
            count2[s2[end]-'a']++;
        }
        while(end != s2.length()){
            if(std::equal(count1, count1 + 26, count2)){return true;}
            count2[s2[start]-'a']--;
            start++;
            count2[s2[end]-'a']++;
            end++;
        }
        return std::equal(count1, count1 + 26, count2);
    }
};
