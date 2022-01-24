1)  1) F O(n)
    2) T
    3) F O(n)
    4) T
    5) F lf<=1

2)  ข้อดี: findเร็วขึ้น ลบเร็ว
    ข้อเสีย: insertช้า rehashช้า

3)  1) n
    2) n^2
    3) n^2
    4) n^2
    5) n^2

4) 4 2 6 1 3 5 7 8

5)  a) B G D H A E C F
    b) G H D B E F C A

8)
template <typename T>
class list {
protected:
    class node { // มีฟังก์ชันและข้อมูลอื่น ๆ ตามปรกติ แต่มิได้แสดงไว้เพื่อประหยัดพื้นที่
    public:
        T data;
        node *prev, *next;
    };
    node *mHeader; // pointer to a header node
    size_t mSize;

public: // มีฟังก์ชันและข้อมูลอื่น ๆ ตามปรกติ แต่มิได้แสดงไว้เพื่อประหยัดพื้นที่
    void crossover(list<T> &other) {
        node *n1 = mHeader;
        node *n2 = other->mHeader;
        for (int i = 0; i < mSize; ++i) {
            n1 = n1->next;
            n2 = n2->next;
            if (i % 2 == 1) {
                node *tmp = n1;
                n1->prev->next = n2;
                n1->next->prev = n2;
                n2->next->prev = n1;
                n2->prev->next = n1;
                n1->next = n2->next;
                n1->prev = n2->prev;
                n2->next = tmp->next;
                n2->prev = tmp->prev;
            }
        }
    }
};

9)
void mirror(node* n) {
    if (!n)
        return;
    mirror(n->left);
    mirrot(n->right);
    std::swap(n->left, n->right);
}

10)
template <typename KeyT, typename MappedT, typename CompareT = std::less<KeyT> >
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
        node *n = mRoot;
        while (true) {
            if (!n)
                return iterator(n);
            size_t left_size = 0;
            if (n->left)
                left_size = n->left->TreeSize;
            if (k == left_size)
                return iterator(n);
            else if (k < left_size) {
                n = n->left;
            } else {
                k -= left_size + 1;
                n = n->right;
            }
        }
    }
};

11)
template <typename KeyT, typename MappedT, typename CompareT = std::less<KeyT> >
class map_avl {
protected:
    class node {
        friend class map_avl;

    protected:
        ValueT data;
        node *left, *right, *parent;
        int height;
    };
    class tree_iterator {
    protected:
        node *ptr;
    };
    node *mRoot;
    CompareT mLess;
    size_t mSize;

public:
    iterator upper_bound(const KeyT &k) {
        node *n = mRoot, *ans = NULL;
        while (n) {
            if (!mLess(k, n->data.first)) {
                n = n->right;
            } else {
                ans = n;
                n = n->left;
            }
        }
        return ans ? iterator(ans) : iterator(n);
    }
};

12)
template <typename T,typename Comp = std::less<T> >
class priority_queue { // มีฟังก์ชันและข้อมูลอื่น ๆ ตามปรกติ แต่มิได้แสดงไว้เพื่อประหยัดพื้นที่
protected:
    T *mData;
    size_t mCap;
    size_t mSize;
    Comp mLess;

public:
    void get_at_least(vector<T> &v, const &T k) {
        process(v, k, 0);
    }

    void process(vector<T> &v, const &T k, int idx) {
        if (idx >= mSize || mLess(mData[idx], k))
            return;
        v.push_back(mData[idx]);
        process(v, k, idx * 2 + 1);
        process(v, k, idx * 2 + 2);
    }
};

13)
void merge(cs_node *n1, cs_node *n2) {
    n2->next_sibling = n1->left_child;
    n1->left_child = n2;
}

14)
cs_node* generate(int n) {
    if (n == 0) {
        cs_node *a = new cs_node(T(), NULL, NULL);
        return a;
    } else {
        cs_node *a = generate(n - 1);
        cs_node *b = generate(n - 1);
        merge(a, b);
        return a;
    }
}