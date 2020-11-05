class Solution
{
public:
	vector<vector<int>> generateMatrix(int n)
	{
        int m = n;  //Seperate dummy value to track columns
		vector<vector<int>> ans(n , vector<int> (n, 0));
		int i = 0, k = 0, l = 0;
        int val = 1;        //Value to be assigned in each cell

		/*
			k - starting row index
		    m - ending row index

		    l - starting column index
		    n - ending column index

		    i - iterator
		*/

		while (k < m && l < n)
		{
			//First Row Movement Left to Right
			for (i = l; i < n; ++i)
			{
				ans[k][i] = val;
				val++;
			}
			k++;

			//Last column going Top to Down
			for (i = k; i < m; ++i)
			{
				ans[i][n - 1] = val;
				val++;
			}
			n--;

			//Last row going Right to Left
			if (k < m)
			{
				for (i = n - 1; i >= l; --i)
				{
					ans[m - 1][i] = val;
					val++;
				}
				m--;
			}

			//First column from Down to Top
			if (l < n)
			{
				for (i = m - 1; i >= k; --i)
				{
					ans[i][l] = val;
					val++;
				}
				l++;
			}
		}
		return ans;
	}
};
