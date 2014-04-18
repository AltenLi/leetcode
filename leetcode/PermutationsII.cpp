#include <vector>
#include <set>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> ret;
        if (num.size()==1){
            ret.push_back(num);
            return ret;
        } 

        int back = num.back();
        num.pop_back();
        set<string> s;
        vector<vector<int>> res = permuteUnique(num);
        for(int i =0; i <res.size(); ++i)
        {
            vector<int> localVector = res[i];

            helper(back, localVector, &ret,s);
        }
        return ret;
    }

    void helper(int val, vector<int> v, vector<vector<int>>* ret,set<string>& s)
    {
        vector<int>::iterator it;
        for (int i =0; i <=v.size(); ++i)
        {
            vector<int> temp = v;
            it = temp.begin();
            it += i;
            temp.insert(it, val);

            if (!contains(s,temp))
            {
                //Only add the vector if it is not a duplicate.
                ret->push_back(temp);
            }
        }

    }

    bool contains(set<string>& s, vector<int> v)
    {
        string str = "";
        for(int i = 0; i < v.size(); ++i)
        {
            str += to_string(v[i]);
        }
        if (s.find(str)!=s.end())
        {
            return true;
        }
        else
        {
            s.insert(str);
            return false;
        }
    }
};