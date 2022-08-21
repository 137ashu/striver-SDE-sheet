class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = prices[0];
        int maxprof = 0;
        
        for(int i : prices){
            minSoFar = min(minSoFar, i);
            maxprof = max(maxprof, i-minSoFar);
        }
            
        return maxprof;
    }
};