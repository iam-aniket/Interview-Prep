class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& a)
	{
		vector<vector<int>> res;
		int n = a.size();

		if (n == 0) return res;

		sort(a.begin(), a.end(), [](vector<int> x, vector<int> y) {return x[0] < y[0];});

		res.push_back(a[0]);

		for (int i = 1; i < n; ++i)
		{
			vector<int> backVec = res.back();

			if (a[i][0] > backVec[1])
				res.push_back(a[i]);
			else
				res.back()[1] = max(res.back()[1], a[i][1]);
		}

		return res;
	}
};
