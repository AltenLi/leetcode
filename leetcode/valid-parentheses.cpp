#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        vector<char> str;
		for (int i=0;i<s.length();i++){
            switch (s[i]){
				case '(':
				case '{':
				case '[':
					str.push_back(s[i]);
					break;
				case ')':
					if (!str.empty() && str.back()=='('){
						str.pop_back();
					}else{
						return false;
					}
					break;
				case '}':
					if (!str.empty() && str.back()=='{'){
						str.pop_back();
					}else{
						return false;
					}
					break;
				case ']':
					if (!str.empty() && str.back()=='['){
						str.pop_back();
					}else{
						return false;
					}
					break;
			}
        }
		if (str.empty())
			return true;
		else
			return false;
    }
};