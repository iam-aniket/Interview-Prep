#define rep(i,a,n) for(int i = a; i < n; i++)
class Solution {
public:
	int minPathSum(vector<vector<int>>& a)
	{
		int m = a.size();
		int n = m ? a[0].size() : 0;


		rep(i, 1, n)
		a[0][i] += a[0][i - 1];

		rep(i, 1, m)
		a[i][0] += a[i - 1][0];

		rep(i, 1, m)
		{
			rep(j, 1, n)
			{
				a[i][j] += min(a[i - 1][j] , a[i][j - 1]);
			}
		}

		return a[m - 1][n - 1];
	}
};
