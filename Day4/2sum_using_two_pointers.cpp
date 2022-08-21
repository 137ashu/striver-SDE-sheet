class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v2;
        v2 = nums;
        sort(nums.begin(), nums.end());
        int hi = nums.size()-1;
        int lo = 0;
        int sum = 0;
        while(lo<hi){
            sum = nums[lo]+nums[hi];
            if(sum == target){
                int loi, hii;
                bool flg = 1;
                for(int i = 0; i<v2.size(); i++){
                    
                    if(v2[i]==nums[lo]&&flg){
                        loi = i;
                        flg = 0;
                    }
                    if(v2[i]==nums[hi]){
                        hii = i;
                    }
                }
                return {loi, hii};
            }
            else if(sum<target){
                lo++;
            }
            else{
                hi--;
            }
        }
        
        return {};
    }
};