// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n)
	{
		int l = 0, f = -1, r = n,m = 0;
		while (l <= r)
		{
			m = l + (r - l) / 2;
			if (isBadVersion(m))
			{
				r = m - 1;
				f = m;
			}
			else
				l = m + 1;
		}
		return f;
	}
};
