//
// Created by mqk on 2020/4/11.
//
#include <map>
#include <vector>
#include <algorithm>
#include "iostream"

using namespace std;

/**
 * A>C>M>E
 * 求指定学生的最好排名及该排名的类别.
 */

int min(int a1, int a2, int a3, int a4) {
    return min(a1, min(a2, min(a3, a4)));
}

int main() {
    int n1, n2;
    while (cin >> n1 >> n2) {
        string stuId;
        double C, M, E, A;
        map<string, int> stuIndex;
        double a_arr[n1];
        double c_arr[n1];
        double m_arr[n1];
        double e_arr[n1];
        vector<double> a_arr_t;
        vector<double> c_arr_t;
        vector<double> m_arr_t;
        vector<double> e_arr_t;
        map<double, int> a_rank;
        map<double, int> c_rank;
        map<double, int> m_rank;
        map<double, int> e_rank;
        double pre = -1;
        int rank_t = 0;
        for (int i = 0; i < n1; ++i) {
            cin >> stuId;
            cin >> C >> M >> E;
            A = (C + M + E) / 3;
            stuIndex[stuId] = i;
            a_arr[i] = A;
            c_arr[i] = C;
            m_arr[i] = M;
            e_arr[i] = E;
            a_arr_t.push_back(A);
            c_arr_t.push_back(C);
            m_arr_t.push_back(M);
            e_arr_t.push_back(E);
        }
        sort(a_arr_t.begin(), a_arr_t.end());
        sort(c_arr_t.begin(), c_arr_t.end());
        sort(m_arr_t.begin(), m_arr_t.end());
        sort(e_arr_t.begin(), e_arr_t.end());
        for (int i = n1-1; i >= 0; --i) {
            double _t = a_arr_t[i];
            rank_t++;
            if (_t == pre) {
                continue;
            }
            a_rank[_t] = rank_t;
            pre = _t;
        }
        pre = -1;
        rank_t = 0;
        for (int i = n1-1; i >= 0; --i) {
            double _t = c_arr_t[i];
            rank_t++;
            if (_t == pre) {
                continue;
            }
            c_rank[_t] = rank_t;
            pre = _t;
        }
        pre = -1;
        rank_t = 0;
        for (int i = n1-1; i >= 0; --i) {
            double _t = m_arr_t[i];
            rank_t++;
            if (_t == pre) {
                continue;
            }
            m_rank[_t] = rank_t;
            pre = _t;
        }
        pre = -1;
        rank_t = 0;
        for (int i = n1-1; i >= 0; --i) {
            double _t = e_arr_t[i];
            rank_t++;
            if (_t == pre) {
                continue;
            }
            e_rank[_t] = rank_t;
            pre = _t;
        }

        string s;
        for (int i = 0; i < n2; ++i) {
            cin >> s;
            if (stuIndex.find(s) == stuIndex.end()) {
                cout << "N/A" << endl;
                continue;
            }
            int index = stuIndex[s];
            int a_rank_i = a_rank[a_arr[index]];
            int c_rank_i = c_rank[c_arr[index]];
            int m_rank_i = m_rank[m_arr[index]];
            int e_rank_i = e_rank[e_arr[index]];
            int max_rank = min(a_rank_i, c_rank_i, m_rank_i, e_rank_i);
            cout << max_rank << " ";

            if (max_rank == a_rank_i) {
                cout << "A" << endl;
            } else if (max_rank == c_rank_i) {
                cout << "C" << endl;
            } else if (max_rank == m_rank_i) {
                cout << "M" << endl;
            } else {
                cout << "E" << endl;
            }
        }
    }
    return 0;
}
