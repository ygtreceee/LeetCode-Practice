// Source: https://leetcode.cn/problems/3sum/
// Author : ygtrece
// Date: 2024-08-24

# include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) 
{
    vector<vector<int>> ans;

    map<int, int> cnt;
    for (int i = 0; i < nums.size(); i++)
        cnt[nums[i]]++;
    vector<int> unique_nums;
    for (auto v : cnt) unique_nums.push_back(v.first);

    for (int i = 0; i < unique_nums.size(); i++)
    {
        int x = unique_nums[i];
        if (x == 0 && cnt[x] >= 3) ans.push_back({0, 0, 0});
        int p = i + 1;
        for (int j = i + 1; j < unique_nums.size(); j++)
        {
            int y = unique_nums[j];
            if (cnt[y] >= 2 && x + y * 2 == 0) ans.push_back({x, y, y});
            else if (cnt[x] >= 2 && x * 2 + y == 0) ans.push_back({x, x, y});
            else
            {
                while ((p <= j || x + y + unique_nums[p] < 0) && p + 1 < unique_nums.size()) p++;
                while (x + y + unique_nums[p] > 0 && p - 1 > j) p--;
                int z = unique_nums[p];
                if (p > j && x + y + z == 0) ans.push_back({x, y, z});
            }
        }
    }
    return ans;
}

// two points
// O(n^2)
vector<vector<int>> threeSum2(vector<int>& nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n - 2; i++)
    {
        if (i && nums[i] == nums[i - 1]) continue;
        int x = nums[i];
        if (x + nums[i + 1] + nums[i + 2] > 0) break;
        if (x + nums[n - 1] + nums[n - 2] < 0) continue;
        int p = i + 1, k = n - 1;
        while (p < k)
        {
            int s = x + nums[p] + nums[k];
            if (s > 0) k--;
            else if (s < 0) p++;
            else
            {
                ans.push_back({x, nums[p], nums[k]});
                for (p++; p < k && nums[p] == nums[p - 1]; p++);
                for (k--; p < k && nums[k] == nums[k + 1]; k--);
            }
        }
    }
    return ans;
}

void Print(vector<vector<int>> nums)
{
    for (int i = 0; i < nums.size(); i++)
        for (int j = 0; j < nums[i].size(); j++)
            cout << nums[i][j] << " \n"[j == nums[i].size() - 1];
    return;
}

int main()
{
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<vector<int>> result = threeSum2(nums);
    Print(result);
    return 0;
}

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]

// Input: nums = [0,1,1]
// Output: []

// Input: nums = [0,0,0]
// Output: [[0,0,0]]