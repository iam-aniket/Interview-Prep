#define pb push_back
class Solution {
public:
	vector<int> searchRange(vector<int>& arr, int x)
	{
		vector<int> v;
		int n = arr.size();
		if (n == 1)
		{
			if (arr[0] == x)
			{
				v.pb(0);
				v.pb(0);
			}
			else
			{
				v.pb(-1);
				v.pb(-1);
			}
			return v;
		}
		int first = -1, second = -1;
		int l = 0, r = n - 1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (arr[m] == x)
			{
				r = m - 1;
				first = m;
			}
			else if (arr[m] < x)
				l = m + 1;
			else
				r = m - 1;
		}
		l = 0, r = n - 1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (arr[m] == x)
			{
				//cout<<"l = "<<m<<'\n';
				l = m + 1;
				second = m;
			}
			else if (arr[m] < x)
				l = m + 1;
			else
				r = m - 1;
		}
		if (first == -1 && second == -1)
		{
			v.clear();
			v.pb(-1); v.pb(-1);
			return v;
		}
		else
		{
			//cout<<"S = "<<second<<"\n";
			v.pb(first);
			v.pb(second);
			return v;
		}
	}
};
