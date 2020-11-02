class Solution {
public:
	void transpose(vector<vector<int>>& arr)
	{
		int R = arr.size();
		int C = arr[0].size();
		for (int i = 0; i < R; i++)
			for (int j = i; j < C; j++)
				swap(arr[i][j], arr[j][i]);
	}
	void reverseRows(vector<vector<int>>& arr)
	{
		int R = arr.size();
		int C = arr[0].size();

		for (int i = 0; i < R; i++)
			for (int j = 0, k = C - 1; j < k; j++, k--)
				swap(arr[i][j], arr[i][k]);
	}
	void rotate(vector<vector<int>>& arr)
	{
		transpose(arr);
		reverseRows(arr);
	}
};
