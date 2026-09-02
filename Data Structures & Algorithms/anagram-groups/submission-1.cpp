class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for(string word : strs){
            vector<int> letters(26, 0);
            for(char c : word){
                letters[c-'a']++;
            }
            
            string key;
            for(int count: letters){
                key += to_string(count) +'#';
            }

            groups[key].push_back(word);
        }

        vector<vector<string>> answer;
        for(auto& [key, group] : groups){
            answer.push_back(group);
        }

        return answer;
    }
};
