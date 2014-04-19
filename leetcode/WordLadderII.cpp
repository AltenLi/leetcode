#include <vector>
#include <queue>
#include <map>
#include <boost/unordered_set.hpp>
using namespace std;
using namespace boost::unordered;


class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        map<string,vector<string> > path;
 
        unordered_set<string>rightside=dict;
 
        rightside.erase(start);
        
        unordered_set<string>curStep;
        unordered_set<string>nextStep;
        curStep.insert(start);
        while(curStep.find(end)==curStep.end()&&!rightside.empty()){
            unordered_set<string>::iterator iter_us_cur;
            for(iter_us_cur=curStep.begin();iter_us_cur!=curStep.end();++iter_us_cur){
                string temp;
                for(int i=0;i<(*iter_us_cur).length();++i){
                    for(int j = 0;j<26;j++){
                        temp = *iter_us_cur;
                        if(temp[i]!=('a'+j)){
                            temp[i] = ('a'+j);
                        }
                        
                        if(rightside.count(temp)==1){
                            nextStep.insert(temp);
                            if(path.find(*iter_us_cur)==path.end()){
                                vector<string> emptyV;
                                path.insert(make_pair(*iter_us_cur,emptyV));
                            }
                            
                            path[*iter_us_cur].push_back(temp);
                        }
                    }                    
                }
            }
            
            if(nextStep.empty())break;
            unordered_set<string>::iterator iter_set;
            for(iter_set=nextStep.begin();iter_set!=nextStep.end();++iter_set){
                rightside.erase(*iter_set);
            }
            curStep = nextStep;
            nextStep.clear();
        }
        
        vector<vector<string> > result;
        vector<string> temp;
        
        if(curStep.find(end)!=curStep.end()){
            output(path,start,end,result,temp);
        }
 
        return result;
 
    }
    
    void output(map<string,vector<string> >&path,string start,string end,vector<vector<string> >&result,vector<string> & temp) {
        temp.push_back(start);
 
        if(start==end){
            result.push_back(temp);return;
        }
 
        vector<string>::iterator iter_v;
        
        for(iter_v=path[start].begin();iter_v!=path[start].end();++iter_v){
            output(path,*iter_v,end,result,temp);temp.pop_back();
        }
    }
};