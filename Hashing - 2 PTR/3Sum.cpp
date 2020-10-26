#define rep(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& num)
	{
		vector<vector<int> > ans;
		int i = 0, low = 0, high = 0, n = num.size();
        if(n == 0 || n == 1)return ans;
		sort(num.begin(), num.begin() + n);
		for (i = 0; i < n; i++) 
        {
			if (i > 0 && num[i] == num[i - 1]) continue;
			low = i + 1;
            high = n - 1;
			while (low < high) 
            {
				if (num[i] + num[low] + num[high] > 0) high--;
				else if (num[i] + num[low] + num[high] < 0) low++;
				else 
                {
					vector<int> tmp = {num[i],num[low],num[high]};
					ans.push_back(tmp);
					while (low < high && num[low] == num[low + 1]) low++;
					while (low < high && num[high] == num[high - 1]) high--;
                    high--; low++;
				}
			}
		}
		return ans;
	}
};
