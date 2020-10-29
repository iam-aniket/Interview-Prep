class Solution {
public:
	void nextPermutation(vector<int>& nums)
	{
		int n = nums.size(), k, l;
		//Find first Index from right not following descending order
		for (k = n - 2; k >= 0; k--)
		{
			if (nums[k] < nums[k + 1])
				break;
		}
		//If it comes till 0 then no next_permutation so just REV
		if (k < 0)
			reverse(nums.begin(), nums.end());
		else
		{
			//Find first index from right which is greater than nums[k]
			for (l = n - 1; l > k; l--)
			{
				if (nums[l] > nums[k])
					break;
			}
			//Swap them
			swap(nums[k], nums[l]);
			//Just Reverse to sort rest
			reverse(nums.begin() + k + 1, nums.end());
		}
		for (int i = 0; i < n; i++)
			cout << nums[i];
	}
};
