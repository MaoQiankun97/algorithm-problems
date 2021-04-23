//
// Created by riddle on 2020/10/9.
//
#include "iostream"
#include "vector"

using namespace std;

struct Bucket {
    int max = INT32_MIN;
    int min = INT32_MAX;
};


class Solution {
public:
    static int maximumGap(vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int _min = INT32_MAX;
        int _max = INT32_MIN;
        for (auto &item: nums) {
            if (item < _min) {
                _min = item;
            }
            if (item > _max) {
                _max = item;
            }
        }
        if (_max == _min) {
            return 0;
        }
        int bucketSize = (_max - _min) / (nums.size() - 1);
        if (bucketSize == 0) {
            bucketSize = 1;
        }
        const int bucketNum = (_max - _min) / bucketSize + 1;
        vector<Bucket*> buckets(bucketNum);
        for (auto &item: nums) {
            int index = (item - _min) / bucketSize;
            if (buckets[index] == nullptr) {
                buckets[index] = new Bucket;
            }
            if (item > buckets[index]->max) {
                buckets[index]->max = item;
            }
            if (item < buckets[index]->min) {
                buckets[index]->min = item;
            }
        }

        int max_gap = 0;
        int pre_max = INT32_MAX;
        for (int j = 0; j < bucketNum; ++j) {
            if (buckets[j] != nullptr && pre_max != INT32_MAX) {
                max_gap = max_gap > buckets[j]->min - pre_max ? max_gap : buckets[j]->min - pre_max;
            }
            if (buckets[j] != nullptr) {
                pre_max = buckets[j]->max;
                max_gap = max_gap > buckets[j]->max - buckets[j]->min ? max_gap : buckets[j]->max - buckets[j]->min;
            }
        }

        return max_gap;
    }
};

int main() {
    vector<int> input = {1,1,1,1,1,5,5,5,5,5};
    cout << Solution::maximumGap(input);

    return 0;
}