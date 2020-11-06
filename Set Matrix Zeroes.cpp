#define rep(i,a,n) for(int i = a; i < n; i++)
class Solution 
{
public:
	void setZeroes(vector<vector<int>>& a)
	{
		int m = a.size();
		int n = m ? a[0].size() : 0;

		bool row = 0, col = 0;
		rep(i, 0, n)
		{
			if (a[0][i] == 0)
			{
				row = 1;
				break;
			}
		}
		rep(i, 0, m)
		{
			if (a[i][0] == 0)
			{
				col = 1;
				break;
			}
		}
		rep(i, 1, m)
		{
			rep(j, 1, n)
			{
				if (a[i][j] == 0)
				{
					a[i][0] = 0;
					a[0][j] = 0;
				}
			}
		}
		rep(i, 1, m)
		{
			rep(j, 1, n)
			{
				if (a[i][0] == 0 || a[0][j] == 0)
					a[i][j] = 0;
			}
		}
		if (row)
		{
			rep(i, 0, n)
			a[0][i] = 0;
		}
		if (col)
		{
			rep(j, 0, m)
			a[j][0] = 0;
		}
	}
};
