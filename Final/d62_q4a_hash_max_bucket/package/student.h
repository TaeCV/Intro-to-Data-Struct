#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename KeyT,
          typename MappedT,
          typename HasherT,
          typename EqualT>
size_t CP::unordered_map<KeyT, MappedT, HasherT, EqualT>::max_bucket_length() {
    // your code here
    size_t mx = mBuckets[0].size();
    for (auto &bucket : mBuckets) {
        if (mx < bucket.size())
            mx = bucket.size();
    }
    return mx;
}

#endif
