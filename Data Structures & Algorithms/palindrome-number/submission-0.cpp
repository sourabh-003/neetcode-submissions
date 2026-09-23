class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int temp = x;
        vector<int> ar;
        while(temp){
            ar.push_back(temp%10);
            temp/=10;
        }
        vector<int> br = ar;
        reverse(br.begin(),br.end());
        return (ar==br);
    }
};