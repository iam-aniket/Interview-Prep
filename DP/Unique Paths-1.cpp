#define rep(i,a,n) for(int i = a; i < n; i++)

class Solution {
public:
	int uniquePaths(int m, int n)
	{
		int a[m + 1][n + 1];

		rep(i, 0, n)
		a[0][i] = 1;

		rep(i, 0, m)
		a[i][0] = 1;

		rep(i, 1, m)
		rep(j, 1, n)
		a[i][j] = (a[i][j - 1] + a[i - 1][j]) ;

		return a[m - 1][n - 1];
	}
};
