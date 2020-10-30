class Solution {
public:
	vector<vector<int>> permute(vector<int>& a)
	{
		int n = a.size();
		vector<vector<int>> ans;
		per(a, ans, 0, n);
		return ans;
	}
private:
	void per(vector<int>& a, vector<vector<int>>& ans, int l, int r)
	{
		if (l == r)
		{
			ans.push_back(a);
			return;
		}
		else
		{
			for (int i = l; i < r; i++)
			{
				swap(a[l], a[i]);
				per(a, ans, l + 1, r);
				swap(a[l], a[i]);
			}
		}
	}
};
