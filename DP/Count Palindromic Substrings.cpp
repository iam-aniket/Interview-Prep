#define rep(i,a,n) for(int i = a; i < n; i++)

class Solution {
public:
	int countSubstrings(string s)
	{
        int n = s.size();
		int dp[1001][1001] = {0},ct = 0;

		rep(i, 0, n + 1)
		rep(j, 0, n + 1)
		dp[i][j] = 0;
    //GAP method - Visualize first with table then code is cakewalk
    
    //PEP coding - Best Explain - 
		//https://www.youtube.com/watch?v=XmSOWnL6T_I&t=1057s
    //https://www.youtube.com/watch?v=WpYHNHofwjc
		for (int gap = 0; gap < n; gap++)
		{
			for (int i = 0, j = gap; i < n, j < n; j++, i++)
			{
				if (gap == 0 || gap == 1)
				{
					dp[i][j] = (s[i] == s[j]) ? 1 : 0;
					if (dp[i][j] == 1)ct++;
				}
				else
				{
					if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
					{
						dp[i][j] = 1;
						ct++;
					}
					else
						dp[i][j] = 0;
				}
			}
		}
		return ct;
	}
};
