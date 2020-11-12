class Solution
{
public:
    int removeDuplicates(vector<int>& a) 
    {
        int n = a.size();
        
        if(n == 0 || n == 1 || n == 2)
            return n;
        
        int j = 2;
        
        for(int i = 2; i < n; i++)
        {
            if(a[i] > a[j-2])
                a[j++] = a[i];
        }
        
        return j;
    }
};
