#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int r=0,c=0;
        while (1){
			if (matrix[r][c]==target)
				return true;
			if (r+1<matrix.size()){
				if (matrix[r+1][c]==target)
					return true;
				else if (matrix[r+1][c]<target){
					r++;
					continue;
				}
			}
			if (c+1<matrix[0].size()){
				if (matrix[r][c+1]==target){
					return true;
				}else if (matrix[r][c+1]<target){
					c++;
					continue;
				}else{
					return false;
				}
			}
			
			return false;
		}
    }
};