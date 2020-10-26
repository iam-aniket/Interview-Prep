class Solution 
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int n = s.size();
		if (n == 0 || n == 1)return n;
		int i = 0, j = 0;
		vector<int> ct(255, 0);
		ct[s[0]]++;
		int ans = 1;
		while (j != n - 1)
		{
			if (ct[s[j+1]] == 0)
			{
				j++;
				ct[s[j]]++;
				ans = max(ans, j - i + 1);
			}
			else
			{
				ct[s[i]]--;
				i++;
			}
		}
		return ans;
	}
};
