#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void comb(vector<int> candidates, int index, int sum, int target, vector<vector<int>> &res, vector<int> &path)
    {
		if(sum>target) 
			return;
		if(sum==target){
			res.push_back(path);
			return;
		}
		for(int i= index; i<candidates.size();i++)
		{
			path.push_back(candidates[i]);
			comb(candidates,i+1,sum+candidates[i],target,res,path);
			path.pop_back();
			while(i<candidates.size()-1 && candidates[i]==candidates[i+1])i++;
		}
	}
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(),num.end());
		vector<vector<int>> res;
		vector<int> path;
		comb(num,0,0,target,res,path);
		return res;
    }
};