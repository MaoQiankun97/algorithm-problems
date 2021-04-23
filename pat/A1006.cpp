//
// Created by mqk on 2020/3/27.
//
#include <iostream>
#include "vector"

using namespace std;


int main() {
    int n; // 数量.
    while (cin>>n) {
        string stu_name[n];
        int in_time[3][n]; // 到达的时、分、秒
        int out_time[3][n];// 离开的时、分、秒
        for (int i = 0; i < n; ++i) {
            cin>>stu_name[i];
            scanf("%d:%d:%d %d:%d:%d", &in_time[0][i], &in_time[1][i], &in_time[2][i], &out_time[0][i], &out_time[1][i], &out_time[2][i]);
        }

        // 查找到达最早的stu下标和最迟离开的stu下标
        vector<int> min_index_collection;
        vector<int> max_index_collection;
        for (int i = 0; i < n; ++i) {
            min_index_collection.push_back(i);
            max_index_collection.push_back(i);
        }
        // 三次遍历
        // 第一次查找出最小的in_hour下标集合和最大的out_hour下标集合
        // 第二次查找对最小的in_hour下标集合中的min最小的一批和最大的out_hour下标集合中min最大的一批
        // 第三次查找sec
        for (int i = 0; i < 3; ++i) {
            vector<int> min_i_index; int min = INT32_MAX;
            vector<int> max_i_index; int max = -1;
            for (int _index : min_index_collection) {
                if (in_time[i][_index] < min) {
                    min = in_time[i][_index];
                    min_i_index.clear();
                    min_i_index.push_back(_index);
                } else if (in_time[i][_index] == min) {
                    min_i_index.push_back(_index);
                }
            }
            for (int _index : max_index_collection) {
                if (out_time[i][_index] > max) {
                    max = out_time[i][_index];
                    max_i_index.clear();
                    max_i_index.push_back(_index);
                } else if (out_time[i][_index] == min) {
                    max_i_index.push_back(_index);
                }
            }
            min_index_collection = min_i_index;
            max_index_collection = max_i_index;
        }

        cout<<stu_name[min_index_collection[0]]<<" "<<stu_name[max_index_collection[0]]<<endl;
    }

    return 0;
}
//
//3
//CS301111 15:30:28 17:00:10
//SC3021234 08:00:00 11:25:25
//CS301133 21:45:00 21:58:40
//
// SC3021234 CS301133