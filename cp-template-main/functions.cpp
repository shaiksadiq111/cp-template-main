class UnionFind {
    public:
     vector<int> parent;
     vector<int> rank;

     UnionFind(int n){
        parent.resize(n);
        rank.resize(n);

        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0;
        }

     }

    int find(int a){
        if(parent[a] == a){
            return a;
        }

        return parent[a] = find( parent[a]);
    }


    void Union(int a, int b){
         a = find( a);
         b = find(b);

        if(rank[a] == rank[b]){
            parent[b] = a;
            rank[a]++;
            return;
        }

        if(rank[a] > rank[b]){
            parent[b] = a;
            return;
        }

        if(rank[b] > rank[a]){
            parent[a] = b;
            return;
        }
    }
};

class Seg{
    public:
    vector<int> segArr;
    int n;

    Seg(int t){
        n = t;
        segArr = vector<int>(t*4 + 1 , 0);
    }

    //0. 0, n -1 , data
     int build(int index, int l , int r, vector<int>& data){
        if(l == r){
            return segArr[index] = data[l];
        }
        int mid = l + (r - l)/2;
        build(2*index + 1, l,  mid , data);
        build(2*index + 2, mid + 1 , r, data);
        return segArr[index] = segArr[2*index + 1] + segArr[2*index +2 ];
    }

    //0. index, val, 0, n -1 
     void updateMe(int indexSeg ,  int index, int val, int l , int r){
       if(l == r && l == index){
           segArr[indexSeg] = val;
           return;
       }
       int mid = l + (r-l)/2;
       if(index > mid){
           updateMe(2*indexSeg +2 , index , val, mid + 1, r);
       }else{
           updateMe(2*indexSeg +1 , index , val, l, mid);
       }

       segArr[indexSeg] = segArr[2*indexSeg+1] + segArr[2*indexSeg+2];
    } 


    //0, 0, n-1, x, y
     int query(int index, int l, int r, int x, int y){
        if(l == x && r == y){
            return segArr[index];
        }
        int mid = l + (r - l)/2;
        int answer = 0;
        if(y > mid){
            answer += query(2*index+2, mid+1, r, max(mid+1, x), y);
        }
        if(x <= mid){
            answer += query(2*index + 1 , l , mid , x, min(mid, y));
        }
        return answer;
    }
};


class Trie{
    public: 
    bool end = false;
    vector<Trie*> next;
    Trie(){
        next =vector<Trie*> (26, nullptr);
    }

     void insert(string &s, Trie* root) {
        Trie* cur = root;
        for(int i = 0; i < s.size(); i++){
            int idx = s[i] - 'a';
            if(cur->next[idx] == nullptr){
                cur->next[idx] = new Trie();
            }

            cur = cur->next[idx];
        }
        cur->end = true;
    }


    bool search(string &s, Trie* root) {
        Trie* cur = root;
        for(int i = 0; i <  s.size(); i++){
            int id = s[i] - 'a';
            if(cur->next[id] != nullptr){
                cur = cur->next[id];
            }else{
                return false;
            }
        }
        return cur->end;
    }
};
