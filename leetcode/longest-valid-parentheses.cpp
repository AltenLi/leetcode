#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	

    int longestValidParentheses(string s) {
		//vector<int> firstpos;
		int i,j,n;  
		int dp[65536];  
		int max=0;  
		n=s.size();  
		for(i=0;i<65536;i++)  
			dp[i]=0;  
		for(i=n-2;i>=0;i--)  
		{  
			if(s[i]=='(')  
			{  
				j=i+1+dp[i+1];  
				if(j<n && s[j]==')')  
				{  
					dp[i]=dp[i+1]+2;  
					if(j+1<n)  
						dp[i]+=dp[j+1];  
				}  
			}  
			if(max<=dp[i])  
				max=dp[i];  
		}  
		return max; 
    }
};