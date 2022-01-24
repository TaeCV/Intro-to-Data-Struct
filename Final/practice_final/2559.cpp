3)	a) n
	b) n^2
	c) n
	d) n
	e) 2^(n/2)

4) A,B,D,E,H,C,F,G

5)
void remove_kth(size_t k) {
    for (int i = k; i < mSize - 1; ++i) {
        mData[(mFront + i) % mCap] = mData[(mFront + i + 1) % mCap];
    }
    --mSize;
}

6)
bool isAHeap(vector<int> v) {
    for (int i = v.size() - 1; i > 0; --i) {
        if (v[(i - 1) / 2] < v[i])
            return false;
    }
    return true;
}

7) 
size_t find_position(const KeyT& key) {
    size_t homePos = hash_to_bucket(key);
    size_t pos = homePos, m = mBucket.size(), col_count = 0;
    while (!mBucket[pos].empty() && !mEqual(mBuckets[pos].value.first, key)) {
        col_count++;
        pos = (homePos + col_count * g(key)) % m;
    }
    return pos;
}

8)
void eraseEveryOther() {
    // เติม C++ code ตรงนี้
    node *n = mHeader->next;
    while (n != mHeader) {
        node *tmp = n;
        n->prev->next = n->next;
        n->next->prev = n->prev;
        mSize--;
        delete tmp;
        n = n->next->next;
    }
}

9)
class node {
public:
    int data;
    node *left;
    node *right;
    size_t size; // จำนวนปมทั้งหมดที่อยู่ภายใต้ปมนี้ รวมถึงตัวเองด้วย
};
node *get_kth(node *r, size_t k) {
    while (true) {
        if (!r || k > r->size)
            return NULL;
        size_t left_size = 0;
        if (r->left)
            left_size = r->left->size;
        if (left_size == k)
            return r;
        else if (k > left_size) {
            k -= left_size + 1;
            r = r->right;
        } else {
            r = r->left;
        }
    }
}

10)
int process(node *n){
    if (!n)
        return 0;
    if (!n->left && !n->right)
        return 1;
    return process(n->left) + process(n->right);
}

int count_leaves() {
    return process(mRoot);
}

11)
class BloomFilter {
protected:
    vector<bool> table;
    vector<std::hash<T>> h;

public:
    BloomFilter(size_t K, vector<std::hash<T>> hash) {
        table.resize(K);
        h = hash;
    }

    void insert(const T &data) {
        for (auto &x : h) {
            table[x(data)] = true;
        }
    }

    bool exist(const T &value) {
        for (auto &x : h) {
            if (!table[x(value)])
                return false;
        }
        return true;
    }
};