class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        sort(num.begin(), num.end());
        vector<vector<int>> ans;
        
        for(int i = 0; i<num.size() -2; i++){
            
            //iterating for same test cases, and going in if condition only if the number is unique
            if(i==0 || (i>0 && num[i]!=num[i-1])){
                int lo = i+1, hi = num.size()-1, sum = 0-num[i];
                while(lo<hi){
                    if(num[lo]+num[hi]==sum){
                        vector<int> temp = {num[i], num[lo], num[hi]};
                        ans.push_back(temp);
                    
                    while(lo<hi && num[lo]==num[lo+1]) lo++;
                    while(lo<hi && num[hi]==num[hi-1]) hi--;
                    
                    lo++;
                    hi--;
                    }
                    else if(num[lo]+num[hi]<sum) lo++;
                    else hi--;
                }
            }
            
        }
        return ans;
    }
};