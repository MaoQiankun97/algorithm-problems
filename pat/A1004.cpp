//
// Created by mqk on 2020/3/27.
//
#include <iostream>
#include <map>
#include <vector>

using namespace std;


int main() {
    // N: 总结点数 M: 非叶结点数
    int N, M;
    while (cin>>N) {
        if (N == 0) {
            break;
        }
        cin>>M;
        map<string, vector<string> > tree;
        for (int i = 0; i < M; ++i) {
            // 结点id
            string node_id;
            // 该结点子结点数量
            int k;
            // 该结点子结点id.
            vector<string> node_child_id_collection;
            string node_child_id;
            cin>>node_id>>k;
            for (int j = 0; j < k; ++j) {
                cin>>node_child_id;
                node_child_id_collection.push_back(node_child_id);
            }
            tree[node_id] = node_child_id_collection;
        }

        if (tree["01"].size() == 0) {
            cout<<1<<endl;
        } else {
            vector<string> level; // 每层的结点.
            vector<int> level_leaves_num; // 每层的叶子结点数
            level_leaves_num.push_back(0); // 第一层叶子结点数为0
            level.push_back("01"); // 第一层的结点id为 01
            while (level.size() != 0) {
                int i = 0;
                vector<string> child_node_id;
                for (int l = 0; l < level.size(); ++l) {
                    for (string t: tree[level[l]]) {
                        child_node_id.push_back(t);
                    }
                }
                if (child_node_id.size() != 0) {
                    for (int j = 0; j < child_node_id.size(); ++j) {
                        if (tree[child_node_id[j]].size() == 0) {
                            i++;
                        }
                    }
                    level = child_node_id;
                    level_leaves_num.push_back(i);
                } else {
                    break;
                }
            }
            for (int m = 0; m < level_leaves_num.size(); ++m) {
                cout << level_leaves_num[m];
                if (m + 1 < level_leaves_num.size()) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}
//5 2
//01 3 02 03 04
//02 1 05
//e: 0 2 1