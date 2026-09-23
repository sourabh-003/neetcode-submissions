class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mps, mpt;
        for(char c = 'a';c<='z';c++){
            mps[c] = c; mpt[c] = c;
        }
        for(char c = 'A';c<='Z';c++){
            mps[c] = c; mpt[c] = c;
        } 
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            mps[t[i]]=s[i]; mpt[s[i]]=t[i];
        }
        for(int i=0;i<s.size();i++){
            if(mps[t[i]]!=s[i] || mpt[s[i]]!=t[i]) return false;
        }
        return true;
    }
};