class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a list of strings
    res=[]
    # path=[]
    records={}
    def wordBreak(self, s, dict):
        if not s:
            tmp=' '.join(self.path)
            self.res.append(tmp)
            return self.res
        for i in range(len(s)+1):
            self.records[i]=[]
        self.wordBreakHelper(s, 0, dict)
        return self.records[0]

    def wordBreakHelper(self, s, k, dict):
        if not s:
            # tmp=' '.join(self.path)
            # self.res.append(tmp)
            return []
        if self.records[k]:
            return self.records[k]

        # not processed,then process and copy
        for i in range(k,len(s)):
            if s[k:i+1] in dict:
                poststrs=self.wordBreakHelper(s,i+1,dict)
                if not poststrs:
                    self.records[k].append(s[k:i+1])
                else:
                    for s1 in poststrs:
                        self.records[k].append(s[k:i+1]+' '+s1)
        return self.records[k]


# print ' '.join(['1','2','3'])
a=Solution()
s="catsanddog"
dict = set(["cat", "cats", "and", "sand", "dog"])
s="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
dict=["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
print a.wordBreak(s,dict)