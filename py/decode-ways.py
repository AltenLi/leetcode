class Solution:
    # @param s, a string
    # @return an integer
    def numDecodings(self, s):
        if len(s)<1 or s[0]=='0':
            return 0
        counts={}
        counts[len(s)]=1
        if s[-1]=='0':
            counts[len(s)-1]=0
        else:
            counts[len(s)-1]=1
        for i in xrange(len(s)-2,-1,-1):
            if s[i]=='0' :
                if s[i+1]=='0':
                    return 0
                else:
                    counts[i]=0
            elif int(s[i])<3 and int(s[i])>0 and int(s[i:i+2])<27 and int(s[i:i+2])>0:
                counts[i]=counts[i+2]+counts[i+1]
            else:
                counts[i]=counts[i+1]
        print counts
        return counts[0]

a=Solution()
print a.numDecodings('10')