class Solution:
    # @return a string
    def convert(self, s, nRows):
        if len(s)<=nRows or nRows==1:
            return s
        zig={}
        row=0
        toward=1
        for ch in s:
            if row+toward>nRows or row+toward<1:
                toward=-toward
            row+=toward
            self.addToList(ch,row,zig)
        s=[]
        for i in xrange(1,nRows+1):
            s+=zig[i]
        return ''.join(s)
    def addToList(self,item,pos,dict):
        dict.setdefault(pos,[])
        dict[pos].append(item)

a=Solution()
print a.convert('AB',1)