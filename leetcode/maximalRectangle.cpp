#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
		int num_i=matrix.size();
        if (num_i==0) return 0;
        int num_j=matrix[0].size();
        if (num_j==0) return 0;
		vector<vector<int>> max_x(num_i,vector<int>(num_j,0));

		int area=0;
		for (int i=0;i<num_i;i++)
		{
			for (int j=0;j<num_j;j++)
			{
				if (matrix[i][j]=='1')
				{
					if (j==0) max_x[i][j]=1;
					else max_x[i][j]=max_x[i][j-1]+1;

					int y=1;
					int x=num_j;
					while (i-y+1>0 && matrix[i-j+1][j]=='1')
					{
						x=min(x,max_x[i-y+1][j]);
						area=max(area,x*y);
						y++;
					}
				}
			}
		}
		return area;
    }
};