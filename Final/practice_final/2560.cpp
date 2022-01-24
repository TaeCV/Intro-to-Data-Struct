1)  1) O(1)
    2) O(1)
    3) O(n)
    4) O(n)
    5) O(n)
    6) O(n)
    7) O(n)
    8) O(n)
    9) O(1)
    10) O(log n)

2)  1) n
    2) n^2
    3) n
    4) n
    5) nlog n

3)  
template <typename KeyT,
 typename MappedT,
 typename HasherT = std::hash<KeyT>,
 typename EqualT = std::equal_to<KeyT> >
class unordered_map
{
protected:
    std::vector<BucketT> mBuckets;
    size_t mSize;
    HasherT mHasher;
    EqualT mEqual;
    float mMaxLoadFactor;

public:
    void remove_colliding_key(const KeyT &m) {
        size_t bi = hash_to_bucket(m); // or bi = mHasher(m) % mBucket.size();
        mBuckets[bi].clear();
    }
};

4)
template <typename KeyT,
 typename MappedT,
 typename HasherT = std::hash<KeyT>,
 typename EqualT = std::equal_to<KeyT> >
class unordered_map
{
protected:
    std::vector<BucketT> mBuckets;
    size_t mSize;
    HasherT mHasher;
    EqualT mEqual;
    float mMaxLoadFactor;

public:
    size_t longest_chain_size() {
        size_t mx = mBuckets[0].size();
        for (size_t i = 1; i < mBuckets.size(); ++i) {
            if (mx < mBuckets[i].size())
                mx = mBuckets[i].size();
        }
        return mx;
    }
};

5)
class LRUCache{
protected:
    std::list l;

public:
    LRUCache(size_t n) {
    }

    char request(size_t addr) {
    }
};

Sol : จงเขียน class LRUCache ดังกล่าว class LRUCache {
    // the list that stores all cached memory, sorted by recently used
    list<pair<size_t, char>> list;
    // map that associate address with the iterator of the list
    unordered_map<size_t, list<int>::iterator> m;

    // capacity of the cache
    size_t n;

public:
    LRUCache(size_t n) {
        this->n = n;
    }

    char request(size_t addr) {
        auto it = m.find(addr);

        if (it == m.end()) {
            // not found, delete the LRU
            auto it2 = m.find(list.back().first);
            m.erase(it2);
            list.erase(list.back());
            // add new address at the front
            List.insert(list.begin(), {addr, get_memory(addr)});
        } else {
            // found, just erase it from the list and reinsert at the front
            list.insert(list.begin(), (it->first, it->second->second));
            list.erase(it->second);
        }

        ma[addr] = list.begin()->second;
        return list.begin()->second;
    }
};

6)
a) list_iterator insert(list_iterator it,const T& element){
    node *n = new node(element, it.ptr->prev, it.ptr);
    it.ptr->prev->next = n;
    it.ptr->prev = n;
    mSize++;
    return list_iterator(n);
}

b) list_iterator moveTo(T data,int position){
    for (auto it = begin(); it != end(); ++it) {
        if (*it == data)
            break;
    }
}

7)
a) void pop(){
    if (mSize <= 0)
        return;
    --mSize;
    mData[0] = mData[mSize];
    int idx = 0, c;
    T tmp = mData[idx];
    while ((c = idx * 2 + 1) < mSize) {
        if (c + 1 < mSize && mLess(mData[c], mData[c + 1]))
            ++c;
        if (mLess(mData[c], tmp))
            break;
        mData[idx] = mData[c];
        idx = c;
    }
    mData[idx] = tmp;
}

b) void changeData(int p,int data){
    if (p < 0 || p >= mSize)
        return;
    mData[p] = data;
    fixUp(p);
    fixDown(p);
}

8)
                            7
        1                           9   
                3               8       10
            2        6                      11


9)
            15
        8           20
    4           18      22

10)
int countNodes(Node* r) {
    // เติมค็ดตรงนี้
    if (!r)
        return 0;
    return 1 + countNodes(r->left) + countNodes(r->right);
}

11)
                                9
            1
        3           7               10
    2           6       8               11
