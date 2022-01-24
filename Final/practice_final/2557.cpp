1)  1) n
    2) n or 1
    3) 1
    4) log n
    5) log n

2)  1) n/2
    2) nullptr
    3) i 
    4) i 
    5) x.begin(),x.end(), {(n-1)*13,99}

3)  1) 
    2) 
    3) Reverse
    4) Sort Decending

6)
template <typename T>
class list {
protected:
    class node {
    public:
        T data;
        node *next;
        node() : data(T()), next(NULL) {}
        node(T e, node *a_next) : data(e), next(a_next) {}
    };
    node *mLast;
    size_t mSize;
    //คลาสนี้มีฟังก์ชันอื่น ๆ ตามปรกติทุกอย่าง และสามารถเรียกใช้ได้ ให้ท าการแก้ไขเฉพาะฟังก์ชัน push_back เท่านั้น
public:
    void push_back(T &e) {
        if (mLast) {
            node *n = new node(e, mLast->next);
            mLast->next = n;
            mLast = n;
        } else {
            node *n = new node(e, NULL);
            n->next = n;
            mLast = n;
        }
        mSize++;
    }
};

7)
right, new_root->set_right(r), left, new_root->set_left(r), r->set_left(rotate_right_child(r->left)), r= rotate_left_child(r)

8)
template <typename T,typename Comp = std::less<T> >
class priority_queue {
protected:
    T *mData;
    size_t mCap;
    size_t mSize;
    Comp mLess;
    //คลาสนี้มีฟังก์ชันอื่น ๆ ตามปรกติทุกอย่าง และสามารถเรียกใช้ได้ ให้ท าการแก้ไขเฉพาะฟังก์ชัน FixDown เท่านั้น
    void fixDown(size_t idx) {
        T tmp = mData[idx];
        size_t c;
        while ((c = 3 * idx + 1) < mSize) {
            size_t homeC = c;
            for (int i = 1; i < 3; ++i) {
                if (homeC + i < mSize && mLess(mData[c], mData[homeC + i]))
                    c = homeC + i;
            }
            if (mLess(mData[c], tmp))
                break;
            mData[idx] = mData[c];
            idx = c;
        }
        mData[idx] = tmp;
    }
};

9)
class MyPriorityQueue {
protected:
    int *mData;
    int mSize, mCap;

public:
    MyPriorityQueue() {
        mData = new int[1];
        mCap = 1;
        mSize = 0;
    }
    ~MyPriorityQueue() { delete mData; }
    void push(int x) {
        if (mSize == mCap) {
            mCap = 2 * mCap;
            int *arr = new int[mCap]();
            for (int i = 0; i < mSize; ++i) {
                arr[i] = mData[i];
            }
            delete[] mData;
            mData = arr;
        }
        int idx = mSize - 1;
        while (idx >= 0 && x < mData[idx]) {
            mData[idx + 1] = mData[idx];
            --idx;
        }
        mData[++idx] = x;
        mSize++;
    }

    int top() {
        return mData[mSize - 1];
    }

    void pop() {
        --mSize;
    }
};

10)
class coalesced_hash {
protected:
    class node {
        friend class coalesced_hash;

    protected:
        int data;
        node *next;

    public:
        node() {}
        node(int a_data, node *a_next) : data(a_data), next(a_next) {}
    };
    vector<node *> mBuckets;
    int mSize;

public:
    coalesced_hash() {
        mBuckets.resize(1007);
        mSize = 0;
    }

    bool find(int e) {
        int idx = e % mBuckets.size();
        node *n = mBuckets[idx];
        while (n) {
            if (n->data == e)
                return true;
            n = n->next;
        }
        return false;
    }
    void insert(int e) {
        int idx = e % mBuckets.size();
        node *p = new node(e, NULL);
        node *n = mBuckets[idx];
        if (n) {
            int i = mBuckets.size() - 1;
            while (mData[i])
                --i;
            mData[i] = p;
            while (n->next)
                n = n->next;
            n->next = mData[i];
        } else {
            n = p;
        }
        mSize++;
    }
};

11)
template <typename KeyT, typename MappedT, typename CompareT = std::less<KeyT> >
class map_bst { //คลาส map_bst, iterator และ node มีฟังก์ชันอื่น ๆ ตามปรกติทุกอย่าง และสามารถเรียกใช้ได้ตามปรกติ
protected:
    typedef std::pair<KeyT, MappedT> ValueT;
    class node {
    protected:
        ValueT data;
        node *left;
        node *right;
        node *parent;
    };
    class iterator {
    protected:
        *ptr;

    public:
        iterator() : ptr(NULL) {}
        iterator(node *a) : ptr(a) {}
    };
    node *mRoot;
    CompareT mLess;
    size_t mSize;

public:
    iterator find_lca(iterator ia, iterator ib) {
        node *n = mRoot;
        while ((mLess(ia.ptr->data, n->data) && mLess(ib.ptr->data, n->data)) || (mLess(n->data, ia.ptr->data) && mLess(n->data, ib.ptr->data))) {
            if (mLess(ia.ptr->data, n->data) && mLess(ib.ptr->data, n->data)) {
                n = n->left;
            } else {
                n = n->right;
            }
        }
        return iterator(n);
    }
};

12)
class Book {
public:
    string name, author;
    vector<string> type;
    vector<unsigned char> pdf;
    float score;
    Book(string name, string author, vector<unsigned char> pdf, vector<string> type, float score) : name(name), author(author), pdf(pdf), type(type), score(score) {}

    bool operator<(const &Book other) const {
        return score < other.score;
    }
};

class CPReadr {

protected:
    map<pair<string, string>, Book *> books;

public:
    CPReadr() : {}
    void add_book(string name, string author, vector<unsigned char> pdf, vector<string> type, double score) {
    }
    Book *search(string title, string author) {
    }
    void remove_book(string title, string author) {
    }
    vector<Book *> recommend(Book &b, int K) {
    }
};

template <typename KeyT, typename MappedT, typename CompareT = std::less<KeyT>>
class map_bst {
protected:
    class node { // มีฟังก์ชันและข้อมูลอื่น ๆ ตามปรกติ แต่มิได้แสดงไว้เพื่อประหยัดพื้นที่
    public:
        ValueT data;
        node *left, *right, *parent;
        int TreeSize; // ขนาดของต้นไม้ย่อยที่มีปมนี้เป็นราก เรียกใช้ได้เลย
    };

public: // มีฟังก์ชันและข้อมูลอื่น ๆ ตามปรกติ แต่มิได้แสดงไว้เพื่อประหยัดพื้นที่
    iterator get_kth(int k) {
        if (k >= mSize)
            return end();
        node *n = root;
        while (true) {
            int size_left = 0;
            if (n->left != NULL) {
                size_left = n->left.TreeSize;
            }
            if (k < size_left) {
                n = n->left;
            } else if (k == size_left) {
                return iterator(n);
            } else {
                k -= size_left + 1;
                n = n->right;
            }
        }
    }
};