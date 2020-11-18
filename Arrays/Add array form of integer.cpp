class Solution {
public:
	vector<int> addToArrayForm(vector<int>& a, int k)
	{
		//Here k itself used as carry
		
        for (int i = a.size() - 1; i >= 0 && k > 0; --i) 
        {
            a[i] += k;
            k = a[i] / 10;  
            a[i] %= 10;
        }
        
        while(k > 0)
        {
            a.insert(a.begin(), k%10);
            k /= 10;
        }
        
		return a;
	}
};
