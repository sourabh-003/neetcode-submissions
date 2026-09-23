class Solution {
public:
    int helper(string a, char c){
        char temp = c;
        int ans = 0;
        for(char ch: a){
            if(ch!=temp) ans++;
            if(temp=='0') temp='1';
            else temp = '0';
        }
        return ans;
    }
    int minOperations(string s) {
        int n = s.size();
        return min(helper(s,'0'),helper(s,'1'));
    }
};