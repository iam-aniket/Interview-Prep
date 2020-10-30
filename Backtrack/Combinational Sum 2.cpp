class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		std::sort(candidates.begin(), candidates.end());
		std::vector<std::vector<int> > res;
		std::vector<int> combination;
		combinationSum(candidates, target, res, combination, 0);
		return res;
	}
private:
	void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin)
	{
		if (!target)
		{
			res.push_back(combination);
			return;
		}
		for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) // iterative component
		{
			if (i > begin && candidates[i] == candidates[i - 1]) continue; /** skip duplicates */
			combination.push_back(candidates[i]);
			combinationSum(candidates, target - candidates[i], res, combination, i + 1); // recursive componenet
			combination.pop_back();
		}
	}
};
