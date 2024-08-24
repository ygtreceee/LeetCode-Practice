class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int len = nums.size();
        int two_sum = 0;
        for(int i=0;i<len;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<len;j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                int k=len-1;
                two_sum=-nums[i]-nums[j];
                while(j<k && two_sum < nums[k]) k--;
                if(j==k) break;
                if(two_sum==nums[k]) ans.push_back({nums[i],nums[j],nums[k]});
            }
        }
        return ans;
    }
};