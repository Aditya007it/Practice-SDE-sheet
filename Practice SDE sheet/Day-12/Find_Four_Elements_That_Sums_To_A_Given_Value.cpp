

// Submitted on Jun 17, 2022, 12:45:32 PM

#include <bits/stdc++.h>
vector<vector<int>> twosum(vector<int> &nums, int target, int start)
{
    vector<vector<int>> res;
    int left = start;
    int right = nums.size() - 1;
    vector<int> ans;
    while (left < right)
    {
        if (left != start && nums[left] == nums[left - 1])
        {
            left++;
            continue;
        }
        int sum = nums[left] + nums[right];
        if (sum == target)
        {
            ans.push_back(nums[left]);
            ans.push_back(nums[right]);
            res.push_back(ans);
            ans.pop_back();
            ans.pop_back();
            left++;
            right--;
        }
        else if (sum > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    return res;
}

vector<vector<int>> threesum(vector<int> &nums, int start, int target)
{
    vector<vector<int>> ans;
    if (nums.size() - start < 3)
        return ans;
    sort(nums.begin(), nums.end());
    for (int i = start; i < nums.size() - 2; i++)
    {
        if (i != start && nums[i] == nums[i - 1])
        {
            continue;
        }
        int tar = target - nums[i];
        vector<vector<int>> res = twosum(nums, tar, i + 1);

        for (auto &it : res)
        {
            it.push_back(nums[i]);
            ans.push_back(it);
        }
    }
    return ans;
}
string fourSum(vector<int> arr, int target, int n)
{
    // Write your code here.
    vector<vector<int>> ans;
    if (arr.size() < 4)
        return "";
    sort(arr.begin(), arr.end());
    for (int i = 0; i <= arr.size() - 4; i++)
    {
        if (i != 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        int val = arr[i];
        vector<vector<int>> triplet = threesum(arr, i + 1, target - val);

        for (auto &it : triplet)
        {
            it.push_back(val);
            ans.push_back(it);
        }
    }
    string str;
    if (ans.size() != 0)
    {
        str += "Yes";
    }
    else
    {
        str += "No";
    }

    return str;
}
