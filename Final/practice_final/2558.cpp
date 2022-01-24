1.1 a) n
	b) n
	c) 1
	d) n lg n
	e) n lg n
1.2	a) 1,1
	b) n
	c) 1
	d) i
	e) 4 + (n-1) * 11

5)
T operator[](int k) {
    node *p = mHeader->next;
    if (k < mSize / 2) {
        for (int i = 0; i < k; ++i)
            p = p->next;
    } else {
        k = mSize - k;
        p = mHeader;
        for (int i = 0; i < k; ++i)
            p = p->prev;
    }
    return p->data;
}

7)
node *succ(KeyT v) {
    node *p = mRoot, *tmp = NULL;
    while (true) {
        if (!p) {
            return tmp ? tmp : p;
        }
        int cmp = compare(p->data.first, v);
        if (cmp == 0) {
            if (tmp)
                return tmp;
            p = p->right;
            while (p && p->left)
                p = p->left;
            return p;
        } else if (cmp == 1) {
            tmp = p;
            p = p->left;
        } else {
            p = p->right;
        }
    }
}

8)
bool isWellFormed(const vector<HtmlElement> &v) {
    std::stack<HtmlElement> s;
    for (auto &tag : v) {
        std::string elem = getElementType(tag);
        if (elem.substr(1, 1).compare("/") == 0) {
            std::string str = getElementType(s.top()).substr(1);
            s.pop();
            if (str.compare(elem.substr(2)) != 0)
                return false;
        } else if (elem.compare("<img>") == 0) {
        } else {
            s.push(tag);
        }
    }
    return s.empty();
}

9)
QNode *findPointAt(int x, int y) {
    QNode *ptr = root;
    while (true) {
        if (!ptr)
            return ptr;
        if (ptr->x == x && ptr->y == y)
            return ptr;
        if (ptr->x < x) {
            if (ptr->y < y) {
                ptr = ptr->bottomLeft;
            } else {
                ptr = ptr->topLeft;
            }
        } else {
            if (ptr->y < y) {
                ptr = ptr->bottomRight;
            } else {
                ptr = ptr->topRight;
            }
        }
    }
}

10)
void mirror(){
    process(mRoot);
}

void process(node *n) {
    if (!n)
        return;
    n->left = process(n->right);
    n->right = process(n->left);
    return n;
}

11)
My sol:
template <typename T,typename Comp = std::less<T> >
class MinMaxBHeap {
protected:
    T *mData;
    size_t mCap;
    size_t mSize;
    Comp mLess;

public:
    // ให้ถือว่าคลาสนี้มีฟังก์ชันต่าง ๆ เหมือนกับ priority_queue อยู่แล้ว ให้นิสิตเขียนฟังก์ชันตามที่โจทย์ก าหนดให้เพิ่มเติม
    // ในกรณีที่ฟังก์ชันที่เขียนขึ้นมาใหม่นั้นมี parameter และ ชื่อตรงกับฟังก์ชันที่มีอยู่แล้ว จะถือว่าฟังก์ชันที่เขียนมานั้นมาแทนที่ตัวเดิม
    void expand(size_t capacity) {
        T *arr = new T[capacity]();
        for (size_t i = 0; i < mSize; ++i) {
            arr[i] = mData[i];
        }
        delete mData;
        mData = arr;
        mCap = capacity;
    }

    bool isMinLevel(size_t idx) {
        return idx % 2 == 1;
    }
    const T &top() {
        return mData[0];
    }

    const T &bottom() {
        if (mSize == 1)
            return mData[0];
        else if (mSize == 2)
            return mData[1];
        else if (mSize >= 3)
            return mLess(mData[1], mData[2]) ? mData[1] : mData[2];
    }

    void fixUpMin(size_t idx) {
        T tmp = mData[idx];
        while (idx > 0) {
            int p = ((idx - 1) / 2 - 1) / 2;
            if (mLess(mData[p], tmp))
                break;
            mData[idx] = mData[p];
            idx = p;
        }
        mData[idx] = tmp;
    }

    void fixUpMax(size_t idx) {
        T tmp = mData[idx];
        while (idx > 0) {
            int p = ((idx - 1) / 2 - 1) / 2;
            if (mLess(tmp, mData[p]))
                break;
            mData[idx] = mData[p];
            idx = p;
        }
        mData[idx] = tmp;
    }

    void push(const T &element) {
        if (mSize + 1 > mCap) {
            expand(mCap * 2);
        }
        mData[mSize] = element;
        mSize++;
        int idx = mSize - 1;
        int p = (idx - 1) / 2;
        if (idx == 0)
            return;
        if (isMinLevel(idx)) {
            if (mLess(mData[p], mData[idx])) {
                std::swap(mData[p], mData[idx]);
                fixUpMax(p);
            } else {
                fixUpMin(idx);
            }
        } else {
            if (mLess(mData[idx], mData[p])) {
                std::swap(mData[idx], mData[p]);
                fixUpMin(p);
            } else {
                fixUpMax(idx);
            }
        }
    }
};

Sol : template <typename T, typename Comp = std::less<T>>
      class MinMaxBHeap {
protected:
    T *mData;
    size_t mCap;
    size_t mSize;
    Comp mLess;

public:
    // ให้ถือว่าคลาสนี้มีฟังก์ชันต่าง ๆ เหมือนกับ priority_queue อยู่แล้ว ให้นิสิตเขียนฟังก์ชันตามที่โจทย์ก าหนดให้เพิ่มเติม
    // ในกรณีที่ฟังก์ชันที่เขียนขึ้นมาใหม่นั้นมี parameter และ ชื่อตรงกับฟังก์ชันที่มีอยู่แล้ว จะถือว่าฟังก์ชันที่เขียนมานั้นมาแทนที่ตัวเดิม

    bool isMinLevel(size_t idx) {
    }
    const T &top() {
        return mData[0];
    }

    const T &bottom() {
        if (mSize == 1)
            return mData[0];
        if (mSize == 2)
            return mData[1];
        if (mSize == 3)
            return mLess(mData[1], mData[2]) ? mData[1] : mData[2];
    }

    void fixUpMin(size_t idx) {
        T tmp = mData[idx];
        while (idx > 2) {
            size_t p = (((idx - 1) / 2) - 1) / 2;
            if (mLess(mData[p], tmp))
                break;
            mData[idx] = mData[p];
            idx = p;
        }
        mData[idx] = tmp;
    }

    void fixUpMax(size_t idx) {
        T tmp = mData[idx];
        while (idx > 2) {
            size_t p = (((idx - 1) / 2) - 1) / 2;
            if (mLess(tmp, mData[p]))
                break;
            mData[idx] = mData[p];
            idx = p;
        }
        mData[idx] = tmp;
    }

    void push(const T &element) {
        mData[mSize] = element;
        mSize++;

        int idx = mSize - 1;
        int p = (idx - 1) / 2;
        if (isMinLevel(idx)) {
            if (idx > 0 && mLess(mData[p], mData[idx])) {
                swap(mData[p], mData[idx]);
                fixUpMax(p);
            } else {
                fixUpMin(idx);
            }
        } else {
            if (idx > 0 && mLess(mData[idx], mData[p])) {
                swap(mData[p], mData[idx]);
                fixUpMin(p);
            } else {
                fixUpMax(idx);
            }
        }
    }
};