#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int lens=gas.size();
		int sum=0;
		int total=0;
		int start=0;
		for (int i=0;i<lens;i++){
			sum+=gas[i]-cost[i];
			total+=gas[i]-cost[i];
			if (sum<0){
				start=(i+1)%lens;
				sum=0;
			}
			
		}
		
		if (total<0)
			return -1;
		else 
			return start;
    }
};