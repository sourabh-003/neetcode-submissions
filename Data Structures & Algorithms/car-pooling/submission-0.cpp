class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> ar(1001,0);
        for(auto t: trips){
            int cap = t[0], u=t[1], v = t[2];
            ar[u]+=cap;
            ar[v]-=cap;
        }
        for(int i=1;i<=1000;i++) ar[i]+=ar[i-1];
        for(int i=0;i<=1000;i++) if(ar[i]>capacity) return false;
        return true;
    }
};