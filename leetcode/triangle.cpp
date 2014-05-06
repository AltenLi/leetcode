#include <string>
#include <math.h>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		vector<vector<int> > tmp=triangle;
		int depth=triangle.size();
		if (depth<=0) return 0;
		for (int i=depth-2;i>=0;i--){
			for (int j=0;j<=i;j++){
				tmp[i][j]=min(tmp[i+1][j],tmp[i+1][j+1])+triangle[i][j];
			}
		}
		return tmp[0][0];
    }
};