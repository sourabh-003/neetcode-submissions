#define pli pair<long long , int>
class Solution {
public:
    const long long INF = 1e9;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: times){
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v,w});
        }
        vector<long long> distance(n+1,INF); distance[k] = 0;
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto p = pq.top(); pq.pop();
            int node = p.second; long long curdist = p.first;
            if(distance[node]<curdist) continue;
            for(auto nbrp: adj[node]){
                int nbr = nbrp.first;
                long long nbrdist = nbrp.second;
                if(curdist+nbrdist < distance[nbr]){
                    distance[nbr] = curdist+nbrdist;
                    pq.push({curdist+nbrdist, nbr});
                }
            }
        }
        long long maxi = 0;
        for(int i=1;i<=n;i++) maxi = max(maxi, distance[i]);
        return (maxi==INF? -1: maxi);
    }
};
