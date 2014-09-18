class Solution:
    # @param start, a string
    # @param end, a string
    # @param dict, a set of string
    # @return an integer
    alp='abcdefghijklmnopqrstuvwxyz'
    def ladderLength(self, start, end, dict):
        if cmp(end,start)==0: return 1
        if self.checkStr(end,start): return 2
        rlist=[start]
        visited={start:1}
        while len(rlist)>0:
            nowstr=rlist[0]
            depth=visited[nowstr]
            if self.checkStr(end,nowstr):
                return depth+1
            for i in xrange(len(nowstr)):
                # repstr=nowstr
                for p in self.alp:
                    repstr=nowstr[:i]+p+nowstr[i+1:]
                    if cmp(repstr,nowstr)!=0 and (repstr in dict) and (repstr not in visited):
                        visited[repstr]=depth+1
                        rlist.append(repstr)
                        dict.remove(repstr)

        ##  OTE
        # rlist=[start]
        # dlist=[1]
        # wordlist=list(dict)
        # visit=[0]*len(wordlist)
        # while len(rlist)>0:
        #     nowstr=rlist[0]
        #     depth=dlist[0]
        #     if self.checkStr(end,nowstr):
        #         return depth+1
        #     for i in xrange(len(wordlist)):
        #         if visit[i]==0:
        #             if self.checkStr(wordlist[i],nowstr):
        #                 rlist.append(wordlist[i])
        #                 dlist.append(depth+1)
        #                 visit[i]=depth+1
                    
            del rlist[0]
            # del dlist[0]
        return 0

    def checkStr(self, str1, str2):
        diffn=0
        for pt in xrange(len(str1)):
            if str1[pt]!=str2[pt]:
                diffn+=1
        if diffn==1:
            return True
        else:
            return False
            

a=Solution()
print a.ladderLength("nape", "mild", set(["dose","ends","dine","jars","prow","soap","guns","hops","cray","hove","ella","hour","lens","jive","wiry","earl","mara","part","flue","putt","rory","bull","york","ruts","lily","vamp","bask","peer","boat","dens","lyre","jets","wide","rile","boos","down","path","onyx","mows","toke","soto","dork","nape","mans","loin","jots","male","sits","minn","sale","pets","hugo","woke","suds","rugs","vole","warp","mite","pews","lips","pals","nigh","sulk","vice","clod","iowa","gibe","shad","carl","huns","coot","sera","mils","rose","orly","ford","void","time","eloy","risk","veep","reps","dolt","hens","tray","melt","rung","rich","saga","lust","yews","rode","many","cods","rape","last","tile","nosy","take","nope","toni","bank","jock","jody","diss","nips","bake","lima","wore","kins","cult","hart","wuss","tale","sing","lake","bogy","wigs","kari","magi","bass","pent","tost","fops","bags","duns","will","tart","drug","gale","mold","disk","spay","hows","naps","puss","gina","kara","zorn","boll","cams","boas","rave","sets","lego","hays","judy","chap","live","bahs","ohio","nibs","cuts","pups","data","kate","rump","hews","mary","stow","fang","bolt","rues","mesh","mice","rise","rant","dune","jell","laws","jove","bode","sung","nils","vila","mode","hued","cell","fies","swat","wags","nate","wist","honk","goth","told","oise","wail","tels","sore","hunk","mate","luke","tore","bond","bast","vows","ripe","fond","benz","firs","zeds","wary","baas","wins","pair","tags","cost","woes","buns","lend","bops","code","eddy","siva","oops","toed","bale","hutu","jolt","rife","darn","tape","bold","cope","cake","wisp","vats","wave","hems","bill","cord","pert","type","kroc","ucla","albs","yoko","silt","pock","drub","puny","fads","mull","pray","mole","talc","east","slay","jamb","mill","dung","jack","lynx","nome","leos","lade","sana","tike","cali","toge","pled","mile","mass","leon","sloe","lube","kans","cory","burs","race","toss","mild","tops","maze","city","sadr","bays","poet","volt","laze","gold","zuni","shea","gags","fist","ping","pope","cora","yaks","cosy","foci","plan","colo","hume","yowl","craw","pied","toga","lobs","love","lode","duds","bled","juts","gabs","fink","rock","pant","wipe","pele","suez","nina","ring","okra","warm","lyle","gape","bead","lead","jane","oink","ware","zibo","inns","mope","hang","made","fobs","gamy","fort","peak","gill","dino","dina","tier"]))