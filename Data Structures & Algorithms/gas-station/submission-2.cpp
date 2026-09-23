class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin(),gas.end(),0)<accumulate(cost.begin(),cost.end(),0)) return -1;
        int total = 0, ans = 0;
        int n = gas.size();
        for(int i=0;i<n;i++){
            total+=(gas[i]-cost[i]);
            if(total<0){
                total = 0;
                ans=i+1;
            }
        }
        return (ans==n? -1: ans);
    }
};
