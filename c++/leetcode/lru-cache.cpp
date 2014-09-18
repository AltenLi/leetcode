#include <map>
using namespace std;

struct node{
	node *pre;
	node *next;
	int key;
	int val;
	node(int k,int v):val(v),key(k),pre(NULL),next(NULL){};
};

class LRUCache{
private:
	map<int,node*> mp;
	node* head;
	node* tail;
	int maxsize;
	int cursize;
public:
    LRUCache(int capacity) {
		if (capacity<1) return;
        maxsize=capacity;
		head=new node(0,0);
		tail=new node(0,0);
		head->next=tail;
		tail->pre=head;
		mp.clear();
		cursize=0;
    }
    
    int get(int key) {
        map<int, node*>::iterator it = mp.find(key);  
        if (it != mp.end()) {  
            node* cur = (*it).second;  
			cur->pre->next = cur->next;  
			cur->next->pre = cur->pre;  
            putToHead(cur);  
            return cur->val;  
        } else  
            return -1;  
    }

	void putToHead(node* cur){
		cur->next = head->next;  
        cur->pre = head;  
        cur->next->pre = cur;  
        head->next = cur; 
	}
    
    void set(int key, int value) {
        if (maxsize<1) return;
		map<int, node*>::iterator it = mp.find(key); 
		if (it!=mp.end()){//found
			node* cur=(*it).second;
			cur->pre->next = cur->next;  
            cur->next->pre = cur->pre;  
            cur->val = value;  
            putToHead(cur); 
		}else{
			node* tmp=new node(key,value);
			putToHead(tmp);
			mp[key]=tmp;
			if (cursize<maxsize){
				cursize++;
			}else{
				node* delnode=tail->pre;
				tail->pre=delnode->pre;
				delnode->pre->next=tail;
				it=mp.find(delnode->key);
				mp.erase(it);
				delete delnode;
			}
		}
    }
};
