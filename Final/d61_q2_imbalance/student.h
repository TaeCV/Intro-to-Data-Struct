// Your code here
int cal(node *&n, KeyT &ans, int &maxImb) {
    if (!n)
        return -1;
    int hl = cal(n->left, ans, maxImb);
    int hr = cal(n->right, ans, maxImb);
    int imb = std::abs(hl - hr);
    if (maxImb < imb) {
        maxImb = imb;
        ans = n->data.first;
    } else if (maxImb == imb && n->data.first < ans) {
        ans = n->data.first;
    }
    return std::max(hl, hr) + 1;
}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    int maxImb = 0;
    node *n = mRoot;
    KeyT ans = n->data.first;
    cal(n, ans, maxImb);
    return ans;
}
