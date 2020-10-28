#define rep(i,a,n) for(int i = a; i < n; i++)
class Solution {
public:
	int search(vector<int>& arr, int x)
	{
		int pos = 0, n = arr.size();
		//n == 1 and n == 2 are corner cases main logic after it
    if (n == 1)
		{
			if (arr[0] == x)
				return 0;
			else
				return -1;
		}
		else if (n == 2)
		{
			if (arr[0] == x )
				return 0;
			else if (arr[1] == x)
				return 1;
			else
				return -1;
		}
    //Main logic starts here
    
    //U can do this search in LogN
    //https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
    
		rep(i, 0, n-1)
		{
			if (arr[i] >= arr[i + 1])
			{
				pos = i + 1;
				break;
			}
		}
		cout << pos << "\n";
		int l = 0, r = pos - 1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (arr[m] == x)
				return m;

			if (arr[m] < x)
				l = m + 1;
			else
				r = m - 1;
		}
		l = pos; r = n - 1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (arr[m] == x)
				return m;

			if (arr[m] < x)
				l = m + 1;
			else
				r = m - 1;
		}
		return -1;

	}
};
