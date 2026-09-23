/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> start,end;
        for(auto it: intervals){
            start.push_back(it.start);
            end.push_back(it.end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int ans = 0, cur=0,p1=0,p2=0;
        while(p1<n){
            if(end[p2]<=start[p1]){
                cur--;
                p2++;
            }
            else{
                cur++;
                p1++;
            }
            ans = max(ans,cur);
        }
        return ans;
    }
};
