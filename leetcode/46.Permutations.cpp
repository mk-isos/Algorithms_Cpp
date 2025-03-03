class Solution
{
public:
    vector<vector<int>> result;

    void backtrack(vector<int> &nums, vector<int> &temp, vector<bool> &used)
    {
        if (temp.size() == nums.size())
        {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
                continue; // 이미 사용한 숫자는 패스

            used[i] = true;
            temp.push_back(nums[i]);

            backtrack(nums, temp, used);

            // 백트래킹 (되돌리기)
            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        vector<int> temp;
        backtrack(nums, temp, used);
        return result;
    }
};
