//
// Created by riddle on 10/11/20.
//
#include "iostream"
#include "vector"
#include "unordered_map"
#include "unordered_set"


using namespace std;

class Solution {
public:
    vector<int> findSwapValues(vector<int> &array1, vector<int> &array2) {
        unordered_set<int> set1;
        unordered_set<int> set2;
        long offset = 0;
        int i = 0;
        while (i < array1.size() && i < array2.size()) {
            offset += array1[i] - array2[i];
            set1.insert(array1[i]);
            set2.insert(array2[i]);
            i++;
        }
        while (i < array1.size()) {
            offset += array1[i];
            set1.insert(array1[i]);

            i++;
        }
        while (i < array2.size()) {
            offset -= array2[i];
            set2.insert(array2[i]);

            i++;
        }
        vector<int> result;
        if (offset % 2 != 0) {
            return result;
        }
        offset >>= 1;
        for (auto &item: array1) {
            if (set2.find(item-offset) != set2.end()) {
                result.push_back(item);
                result.push_back(item-offset);

                return result;
            }
        }

        return result;
    }
};


int main() {
    vector<int> input1 = {4, 1, 1, 1, 2, 2};
    vector<int> input2 = {3, 6, 3, 3};
    Solution a;
    vector<int> result = a.findSwapValues(input1, input2);
    for (auto &item: result)
        cout<<item<<" ";

    return 0;
}
