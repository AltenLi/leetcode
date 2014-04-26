#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
		if (numRows<1) return result;
		vector<int> cur;
		cur.push_back(1);
		result.push_back(cur);


		for (int i=2;i<=numRows;i++){
			cur.push_back(1);
			for (int j=cur.size()-2;j>0;j--){
				cur[j]+=cur[j-1];
			}
			result.push_back(cur);
		}
		return result;
    }
};