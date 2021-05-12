#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


struct Pe {
    int age;
    int score;

    Pe(int _age, int _score) : age(_age), score(_score) {}
};

bool compare(Pe *a, Pe *b) {
    if (a-> age == b->age) {
        return a->score < b->score;
    }
    return a->age < b->age;
}

class Solution {
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages) {
        vector<Pe *> pe;
        for (int i = 0; i < ages.size(); ++i) {
            Pe *p = new Pe(ages[i], scores[i]);
            pe.push_back(p);
        }
        sort(pe.begin(), pe.end(), compare);
        // 查找连续上升子序列 计算其分数总和 返回最高的一个
        for (int i = 0; i < scores.size(); ++i) {
            scores[i] = pe[i]->score;
        }
        vector<int> cur_max(scores.size(), 0);
        vector<int> _result(scores.size(), 0);
        int r = -1;
        for (int i = 0; i < scores.size(); ++i) {
            if (i == 0) {
                cur_max[i] = scores[i];
                _result[i] = scores[i];
            } else {
                _result[i] = scores[i];
                cur_max[i] = scores[i];
                for (int j = i-1; j >= 0; --j) {
                    if (scores[i] >= cur_max[j]) {
                        if (_result[j] + scores[i] > _result[i]) {
                            _result[i] = _result[j] + scores[i];
                            cur_max[i] = scores[i];
                        }
                    }
                }
            }
            if (_result[i] > r) {
                r = _result[i];
            }
        }

        return r;
    }
};

int main() {
    Solution a;
    vector<int> input1 = {1, 2, 3, 5};
    vector<int> input2 = {8, 9, 10, 1};
    cout << a.bestTeamScore(input1, input2);

    return 0;
}
