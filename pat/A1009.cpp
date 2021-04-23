//
// Created by mqk on 2020/4/7.
//
#include <map>
#include "iostream"

using namespace std;

int main() {
    int a_item_num, b_item_num, c_item_num;
    map<int, double> a_item, b_item, c_item;
    while (cin>>a_item_num) {
        a_item.clear();
        b_item.clear();
        c_item.clear();
        c_item_num = 0;

        // 读取数据.
        int t; double c;
        for (int i = 0; i < a_item_num; ++i) {
            cin>>t>>c;
            a_item[t] = c;
        }
        cin>>b_item_num;
        for (int i = 0; i < b_item_num; ++i) {
            cin>>t>>c;
            b_item[t] = c;
        }

        // 计算并将结果放入c_item中
        for (const auto &_item_a : a_item) {
            int k_a = _item_a.first; // a的指数
            double v_a = _item_a.second; // a的系数
            for (const auto &_item_b : b_item) {
                int k_b = _item_b.first; // b的指数
                double v_b = _item_b.second; // b的系数
                int k_c = k_a + k_b;
                double v_c = v_a * v_b;
                if (c_item.find(k_c) != c_item.end()) {
                    c_item[k_c] = c_item[k_c] + v_c;
                    if (c_item[k_c] == 0.0) {
                        c_item_num--;
                        c_item.erase(k_c);
                    }
                } else {
                    c_item[k_c] = v_c;
                    c_item_num++;
                }
            }
        }
        cout<<c_item_num;
        if (c_item_num > 0) {
            c_item.key_comp();
            for (auto _item_c = c_item.end(); _item_c-- != c_item.begin();) {
                printf(" %d %.1lf", _item_c->first, _item_c->second);
            }
        }
        cout<<endl;
    }
    return 0;
}
//2 1 2.4 0 3.2
//2 2 1.5 1 0.5
//
//Sample Output:
//3 3 3.6 2 6.0 1 1.6
