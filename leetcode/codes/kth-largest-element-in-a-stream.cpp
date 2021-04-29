//
// Created by riddle on 2020/11/24.
//
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (int i = 0; i < nums.size(); ++i) {
            _add(nums[i]);
        }
    }

    int add(int val) {
        _add(val);

        return _getKth();
    }

private:
    vector<int> _help;
    int _k;

    int _getKth() {
        return _help[0];
    }

    void _add(int val) {
        if (_help.size() < _k) {
            _help.push_back(val);
            if (_help.size() == _k) {
                sort(_help.begin(), _help.end());
            }
        } else {
            if (_help[0] < val) {
                int i = 0;
                for (; i < _k - 1; ++i) {
                    if (_help[i] < val && _help[i + 1] <val) {
                        _help[i] = _help[i+1];
                    }
                }
                _help[i] = val;
            }
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */