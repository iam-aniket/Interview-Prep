/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/
#define pb push_back
#define rep(i,a,n) for(int i = a; i < n; i++)
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& s)
	{
		vector<vector<string>> ans;
		int n = s.size();

		unordered_map<string, vector<string>> mp;

		rep(i, 0, n)
		{
			string temp = s[i];
			sort(temp.begin(), temp.end());
			mp[temp].pb(s[i]);
		}

		for (auto x : mp)
			ans.pb(x.second);

		return ans;
	}
};
