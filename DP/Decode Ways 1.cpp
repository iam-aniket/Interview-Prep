class Solution {
public:
	int numDecodings(string str)
	{
		int n = str.size();
		int dp[101] = {0};

		dp[0] = 1;
		dp[1] = str[0] != '0' ? 1 : 0;

		for (int i = 2; i <= n; ++i)
		{
			dp[i] = 0;

			char c1 = str[i - 2] - '0';
			char c2 = str[i - 1] - '0';
			
			//If char at 2 pos earlier was '1' or already 'two digit number has occured' with max as 26;
			//Then just use the value of dp at two positions earlier
			
			if (c1 == 1 || (c1 == 2 && c2 <= 6)) dp[i] += dp[i - 2];
			
			//Else the number is surely possible to form another 2 digit number
			//So just check if its non zero and add dp value at previous location
			
            if (c2 != 0) dp[i] += dp[i - 1];
		}
		return dp[n];
	}
};
