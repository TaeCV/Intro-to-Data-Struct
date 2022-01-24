1)  1) F
    2) F
    3) F
    4) T
    5) F
    6) T
    7) T
    8) F
    9) F
    10) T

5)
template <typename T,typename Comp = std::less<T> >
class priority_queue {
protected:
    T *mData;
    size_t mCap;
    size_t mSize;
    Comp mLess;
    void fixUp(size_t idx) {… }
    void fixDown(size_t idx) {… }

public:
    void set_priority(Comp newMLess) {
        // your code here
        mLess = newMLess;
        for (int i = mSize / 2 - 1; i >= 0; --i) {
            fixDown(i);
        }
    }
};

6)
template <typename KeyT, typename MappedT,typename HasherT = std::hash<KeyT>,
 typename EqualT = std::equal_to<KeyT> >
class unordered_map {
protected:
    typedef pair<KeyT, MappedT> BucketT;
    //-------------------------------------------------------------
    std::vector<BucketT> mBuckets;
    size_t mSize;
    HasherT mHasher;
    EqualT mEqual;
    float mMaxLoadFactor;
    // default constructor
    unordered_map() : mBuckets(std::vector<BucketT>(11)), mSize(0),
                      mHasher(HasherT()), mEqual(EqualT()), mMaxLoadFactor(0.7) {}
    size_t bucket_count() { return mBuckets.size(); }
    size_t hash_to_bucket(const KeyT &key) { return mHasher(key) % mBuckets.size(); }
    size_t find_position(const KeyT &key) {
        size_t homePos = hash_to_bucket(key);
        size_t pos = homePos;
        while ((!mBuckets[pos].first == T()) &&
               (!mEqual(mBuckets[pos].first, key))) {
            pos = (pos + 1) % mBuckets.size();
        }
        return pos;
    }
    // เติมโค้ดตรงนี้ได้ เผื่อประกาศบริการเพิ่ม

    size_t erase(const KeyT &key) {
        // เติมโค้ดตรงนี้
        size_t h = hash_to_bucket(key);
        size_t pos = h;
        bool isFound = false;
        while (h == hash_to_bucket(mBuckets[(pos) % mBuckets.size()])) {
            if (mBuckets[pos % mBuckets.size()] == key) {
                isFound = true;
                break;
            }
            pos++;
            if (pos == h)
                break;
        }
        if (!isFound)
            return 0;
        else {
            mBuckets[pos % mBuckets.size()] = T();
            return 1;
        }
    }
};

7)
vector<size_t> min_hash_signature(set<int> A,vector<HasherT> hs){
    vector<size_t> ans(hs.size());
    for (int i = 0; i < hs.size(); ++i) {
        auto it = A.begin();
        ans[i] = h[i](*it);
        while (++it != A.end())
            if (ans[i] > h[i](*it))
                ans[i] = h[i](*it);
        ans[i] = mn;
    }
    return ans;
}

float min_hash_estimate(vector<size_t> as, vector<size_t> bs) {
    map<size_t, int> m;
    for (auto &x : as)
        m[x]++;
    int count = 0;
    for (auto &x : bs)
        count += m[x];
    return (count + 0.0) / as.size();
}

8)
template <typename T>
class list {
protected:
    class node {
        friend class list;

    protected:
        T data;
        node *prev;
        node *next;
    } node *mHeader; // pointer to a header node
    size_t mSize;

public:
    void append_k_list(vector<list<T>> &Ls) {
        for (auto &x : ls) {
            mHeader->prev->next = x->mHeader->next;
            x->mHeader->next->prev = mHeader->prev;
            x->mHeader->prev->next = mHeader;
            mHeader->prev = x->mHeader->prev;
            x->mHeader->next = x->mHeader;

            x->mHeader->prev = x->mHeader;
            mSize += x->mSize;
            x->mSize = 0;
        }
    }
};

9)
class north_star_tree {
    class node {
    public:
        string name;
        node *left, *right, *parent;
        node(string s, node *left, node *right, node *parent) : name(s), left(left), right(right), parent(parent) {}
    };
    node *root;
    tree(string s) {
        root * = new node(s, NULL, NULL, NULL);
    }
    // นิสิตสามารถเขียนฟังก์ชันอื่น ๆ เพิ่มเติมได้
    void print(node *n, int k, int i) {
        if (!n)
            return;
        if (i == k)
            std::cout << n->name;
        else {
            print(n->left, k, i + 1);
            print(n->right, k, i + 1);
        }
    }

    void printKThLevel(int k) {
        // your code here
        print(root, k, 1);
    }
};

10)
template <typename KeyT, typename MappedT, typename CompareT = std::less<KeyT> >
class map_bst {
protected:
    typedef std::pair<KeyT, MappedT> ValueT;
    class node {
        friend class map_bst;

    protected:
        ValueT data;
        node *left;
        node *right;
        node *parent;
    };
    class tree_iterator {
    protected:
        node *ptr;

    public:
        tree_iterator() : ptr(NULL) {}
        tree_iterator(node *a) : ptr(a) {}
        tree_iterator &operator++(){ …} tree_iterator &operator--(){…} tree_iterator operator++(int){…} tree_iterator operator--(int){…} ValueT &operator*() { return ptr->data; }
        ValueT *operator->() { return &(ptr->data); }
        bool operator==(const tree_iterator &other) { return other.ptr == ptr; }
        bool operator!=(const tree_iterator &other) { return other.ptr != ptr; }
    };
    node *mRoot;
    CompareT mLess;
    size_t mSize;

public:
    typedef tree_iterator iterator;
    iterator find_middle_value(iterator a, iterator b) {
        while (mLess(a.ptr->data, b.ptr->data)) {
            ++a;
            --b;
        }
        if (a.ptr->data == b.ptr->data) {
            return a;
        } else {
            return b;
        }
    }
};

11)
class trie{
public:
    class trie_node {
    public:
        bool valid;
        trie_node *child[25];
        // child[0] is child "a",
        // child[1] is child "b",....,
        // child[25] is child "z"
        trie_node() : valid(false) {
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };

public:
    trie_node *root;
    trie() root(new trie_node()) {
    }
    ~trie() {
        clear(root);
    }

    void clear(trie_node *n) {
        if (!n)
            return;
        for (int i = 0; i < 26; ++i) {
            delete (n->child[i])
        }
        delete n;
    }

    void insert(string s) {
        trie_node *n = root;
        for (auto &c : s) {
            n = n->child[c - 'a'];
            if (!n) {
                n = new trie_node();
            }
        }
        if (n != root)
            n->valid = true;
    }

    bool find(string s) {
        trie_node *n = root;
        for (auto &c : s) {
            n = n->child[c - 'a'];
            if (!n)
                return false;
        }
        return n->valid;
    }

    void erase(string s) {
        trie_node *n = root;
        for (auto &c : s) {
            n = n->child[c - 'a'];
            if (!n)
                return;
        }
        n->valid = false;
    }
}