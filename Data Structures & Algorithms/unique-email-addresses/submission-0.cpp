class Solution {
public:
    string helper(string s){
        string ans = "";
        for(char c: s){
            if(c=='.') continue;
            if(c=='@' || c=='+') break;
            ans+=c;
        }
        return ans;
    }
    string domain(string s){
        string ans = ""; bool found = false;
        for(char c: s){
            if(found) ans+=c;
            if(c=='@') found = true;
        }
        return ans;
    }
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;
        for(string s: emails){
            string temp = helper(s)+domain(s);
            st.insert(temp);
        }
        return st.size();
    }
};