#define pb push_back
#define rep(i,a,n) for(int i = a; i < n; i++)

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& x)
	{
		vector<vector<int>> ans;
		int n = a.size(),i = 0;
		
        // add all the intervals ending before newInterval starts
        // Left part (no intersection with newInterval)
        while (i < n && a[i][1] < x[0])
		{
			ans.pb(a[i]);
			i++;
		}
        
        // merge all overlapping intervals to one considering newInterval
		// newInterval part (with or without merge)
        while (i < n && a[i][0] <= x[1])
		{
			x[0] = min(a[i][0], x[0]);
			x[1] = max(a[i][1], x[1]);
			i++;
		}
		
        ans.pb(x);// add the union of intervals we got
        
		// add all the rest - since they are defintely larger
        // Right part (no intersection with newInterval)
        while (i < n)
		{
			ans.pb(a[i]);
			i++;
		}
		return ans;
	}
};
