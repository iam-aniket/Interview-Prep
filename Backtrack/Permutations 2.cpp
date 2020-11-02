class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& a)
	{
		int n = a.size();
		vector<vector<int>> ans;
		per(a, ans, 0, n);
		return ans;
	}

	void per(vector<int>& a, vector<vector<int> >& ans, int l, int r)
	{
		if (l == r)
		{
			ans.push_back(a);
			return;
		}
    //Use unordered_set to avoid swapping same elements
		unordered_set<int> st;

		for (int i = l; i < r; ++i)
		{
			if (st.count(a[i]) == 1)
				continue;

			st.insert(a[i]);
			swap(a[l], a[i]);
			per(a, ans, l + 1, r);
			swap(a[l], a[i]);
		}
	}
};
