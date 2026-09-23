class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<int>> map_pref(26,vector<int>(n,0));
        vector<vector<int>> map_suff(26,vector<int>(n,0));

        for(int i=0;i<n;i++){
            char c = s[i];
            int ind = c-'a';
            if(i>0) for(int j=0;j<26;j++) map_pref[j][i] = map_pref[j][i-1];
            map_pref[ind][i]++;
        }
        for(int i=n-1;i>=0;i--){
            char c = s[i];
            int ind = c-'a';
            if(i<n-1) for(int j=0;j<26;j++) map_suff[j][i] = map_suff[j][i+1];
            map_suff[ind][i]++;
        }
        set<pair<int,int>> st;
        for(int i=1;i<n-1;i++){
            for(int j=0;j<26;j++){
                if(map_pref[j][i-1]>0 && map_suff[j][i+1]>0) st.insert({j,s[i]-'a'});
            }
        }
        return st.size();
    }
};