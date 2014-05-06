#include <string>
#include <math.h>
#include <vector>
class Solution {
public:
    int uniquePaths(int m, int n) {
		if (m<=0 || n<=0) return 0;
        int *path=new int[m*n];
		for (int i=0;i<n;i++)
			path[i*m]=1;
		for (int i=0;i<m;i++)
			path[i]=1;
		for (int i=1;i<n;i++)
			for (int j=1;j<m;j++)
				path[i*m+j]=path[i*m+j-1]+path[(i-1)*m+j];
		return path[m*n-1];
    }
};