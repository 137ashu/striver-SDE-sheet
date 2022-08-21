#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> umap;
        vector <int> v;
        for(int i= 0; i< nums.size(); i++){
            if (umap.find(nums[i]) == umap.end()){
                umap[target-nums[i]] = i;
            }
            else{
                v.push_back(i);
                v.push_back(umap[nums[i]]);
            }
        }
        return v;
    }
};