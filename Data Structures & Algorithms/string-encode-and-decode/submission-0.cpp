class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for(string s : strs){
            str += s.length()-0;
            str += s;
        }
        return str;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int c = 0, i = 0;
        while(i < s.length()){
            c = s[i];
            i++;
            strs.push_back(s.substr(i,c));
            i += c;
        }
        return strs;
    }
};
