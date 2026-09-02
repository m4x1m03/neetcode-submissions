class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(const string& str : strs){
            encoded += to_string(str.length());
            encoded += '#';
            encoded += str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        int n = s.length();

        while(i < n){
            int j = i;
            while(s[j] != '#'){
                j++;
            }

            //get length of next word
            int length = stoi(s.substr(i, j - i));

            //push back the word
            int start = j+1;
            decoded.push_back(s.substr(start, length));

            i = start+length;
        }
        return decoded;
    }
};
