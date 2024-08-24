class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n_size = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n_size - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int target = -nums[i];
            int left = i + 1;
            int right = n_size - 1;
            
            while (left < right) {
                int left_right_sum = nums[left] + nums[right];
                if (left_right_sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (left_right_sum < target) {
                    left++;
                } else if (left_right_sum > target){
                    right--;
                }
            }
        }
        
        return result;
    }
};
