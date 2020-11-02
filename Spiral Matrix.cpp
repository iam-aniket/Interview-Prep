#define pb push_back
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& a)
	{
		int m = a.size();
		//VVI - as input can be empty then no a[0] is present so accessing it will cause RUNTIME error
    int n = m ? a[0].size() : 0;
		vector<int> ans;
		int i, k = 0, l = 0;

		/* k - starting row index
		    m - ending row index
		    l - starting column index
		    n - ending column index
		    i - iterator
		*/
		while (k < m && l < n)
		{
			/* Print the first row from
			       the remaining rows */
			for (i = l; i < n; ++i)
			{
				ans.pb(a[k][i]);
			}
			k++;

			/* Print the last column
			 from the remaining columns */
			for (i = k; i < m; ++i)
			{
				ans.pb(a[i][n - 1]);
			}
			n--;

			/* Print the last row from
			        the remaining rows */
			if (k < m)
			{
				for (i = n - 1; i >= l; --i)
				{
					ans.pb(a[m - 1][i]);
				}
				m--;
			}

			/* Print the first column from
			           the remaining columns */
			if (l < n) {
				for (i = m - 1; i >= k; --i)
				{
					ans.pb(a[i][l]);
				}
				l++;
			}
		}
		return ans;
	}
};
