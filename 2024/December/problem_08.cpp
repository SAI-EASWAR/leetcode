class Solution {
public:
    int n;
    vector<vector<int>> memo;
    int binarySearch(vector<vector<int>>& events,int search){
        int s = 0;
        int e = n -1;
        int result = n;

        while(s <= e){
            int mid = s + (e - s)/2;

            if(events[mid][0] > search){
                result = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return result;
    }
    int findMax(vector<vector<int>>& events,int index,int two){
        if(index >= events.size() || two == 2)
        return 0;

        if (memo[index][two] != -1) {
            return memo[index][two];
        }

        int taken = 0, notTaken = 0;

        int nextIndex = binarySearch(events,events[index][1]);

        taken = events[index][2] + findMax(events,nextIndex,two+1);


        notTaken = findMax(events,index+1,two);

        return memo[index][two] = max(taken, notTaken);

    }
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();

        sort(events.begin(),events.end());

        memo.resize(n,vector<int> (3,-1));
        return findMax(events,0,0);

    }
};