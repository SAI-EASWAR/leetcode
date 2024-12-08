class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> us(banned.begin(),banned.end());

        int sum = 0;
        int i = 1;
        int cnt = 0;
        while(i <= n){
            if(us.find(i) == us.end()){
                sum += i;
                cnt++;
            }
            if(sum > maxSum){
                return cnt - 1;
            }
            i++;
        }
        return cnt;
    }
};