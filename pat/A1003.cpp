//
// Created by mqk on 2020/3/14.
//
#include <iostream>
using namespace std;

int main() {
    int city_num, road_num, start_city, target_city;
    while (cin>>city_num>>road_num>>start_city>>target_city) {
        // 每个城市救援队数量
        int city_member_num[city_num];
        // graph[i][j] 表示从i城市直接到j城市的路径距离.
        int graph[city_num][city_num];
        for (int i = 0; i < city_num; ++i) {
            cin>>city_member_num[i];
        }
        for (int k = 0; k < city_num; ++k) {
            for (int i = 0; i < city_num; ++i) {
                graph[k][i] = (k == i ? 0 : INT16_MAX);
            }
        }
        int s, t, len;
        for (int j = 0; j < road_num; ++j) {
            cin>>s>>t>>len;
            graph[s][t] = len;
            graph[t][s] = len;
        }

        /// 打印数组
//        for (int i = 0; i < city_num; ++i) {
//            for (int j = 0; j < city_num; ++j) {
//                printf("%7d", graph[i][j]);
//            }
//            cout<<endl;
//            cout<<endl;
//        }

        // 求单源最短路径
        // ss[i]表示i城市是否已求得最短路径
        // member_num[i]表示到达i城市以后最大的救援队数量
        // road_num_to[i]表示从起始城市到i城市的最短路径数量
        // dist[i]表示从起始城市到i城市的最短路径长度
        bool ss[city_num];
        int member_num[city_num];
        int road_num_to[city_num];
        int dist[city_num];
        for (int l = 0; l < city_num; ++l) {
            ss[l] = false;
            member_num[l] = 0;
            dist[l] = INT16_MAX;
            road_num_to[l] = -1;
        }
        member_num[start_city] = city_member_num[start_city];
        road_num_to[start_city] = 1;
        ss[start_city] = true;
        dist[start_city] = 0;
        // 从start_city开始更新dist数组, 找最短路径, 如果与start_city相连的城市中dc城市距离最近, 则找到一条最短路径start_city - dc
        // 再查看dc相连的城市, 更新dist数组, 找最短路径.
        // 直到找不到最短路径或者所有城市的最短路径都已求出.
        int index = start_city;
        for (int i = 0; i < city_num; ++i) {
            cout<<endl;
            cout<<"find shortest: "<<index<<endl;
            cout<<"dist: ";
            for (int l = 0; l < city_num; ++l) {
                cout<<dist[l]<<" ";
            }
            cout<<endl;
            cout<<"member_num: ";
            for (int l = 0; l < city_num; ++l) {
                cout<<member_num[l]<<" ";
            }
            cout<<endl;
            cout<<"road_num_to: ";
            for (int l = 0; l < city_num; ++l) {
                cout<<road_num_to[l]<<" ";
            }
            cout<<endl;
            // 更新dist数组
            for (int j = 0; j < city_num; ++j) {
                // index为上一个找到最短路径的城市, 从index开始更新dist数组
                if (j == index) {
                    continue;
                }
                if (graph[index][j] != INT16_MAX) {
                    if (dist[index] + graph[index][j] < dist[j]) {
                        dist[j] = dist[index] + graph[index][j];
                        road_num_to[j] = road_num_to[index];
                        member_num[j] = member_num[index] + city_member_num[j];
                    } else if (dist[index] + graph[index][j] == dist[j]) {
                        road_num_to[j]++;
                        member_num[j] = max(member_num[j], member_num[index] + city_member_num[j]);
                    }
                }
            }
            // 查找最短路径.
            int _min_ = INT16_MAX; int _min_index_ = -1;
            for (int k = 0; k < city_num; ++k) {
                // 已查找到最短路径的城市不管.
                if (ss[k]) {
                    continue;
                }
                if (dist[k] < _min_) {
                    _min_ = dist[k];
                    _min_index_ = k;
                }
            }
            // 如果未找到最短路径, 说明已无与start_city连通的城市
            if (_min_index_ == -1) {
                break;
            }
            index = _min_index_;
            ss[index] = true;
        }

        // 查找完毕, 输出start_city -> target_city的最短路径条数和最大救援队数量.
        cout<<road_num_to[target_city]<<" "<<member_num[target_city]<<endl;
    }

    return 0;
}

//test file
//6 7 0 5
//1 2 1 1 2 1
//0 1 1
//0 2 2
//1 2 1
//2 3 1
//2 4 1
//3 5 1
//4 5 1
//
//5 6 0 2
//1 2 1 5 3
//0 1 1
//0 2 2
//0 3 1
//1 2 1
//2 4 1
//3 4 1