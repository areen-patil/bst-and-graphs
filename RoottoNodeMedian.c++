#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct graph
{
    ordered_multiset<int> v;
    vector<vector<int>> conn;
    vector<long long> values, ans;
    int size, n;

    void init(int size1)
    {
        size = size1;
        values.resize(size);
        ans.assign(size, 0);
        conn.resize(size);
    }

    void build(vector<int> &p)
    {
        for (int i = 0; i < size; i++)
        {
            conn[i].push_back(p[i]);
            if (p[i] != -1)
                conn[p[i]].push_back(i);
        }
    }

    void dfs(int vertex, int parent)
    {
        v.insert(values[vertex]);
        for (auto i : conn[vertex])
        {
            if (i != parent)
            {
                dfs(i, vertex);
            }
        }
        int sz = v.size();
        ans[vertex] = *(v.find_by_order((sz - 1) / 2));
        v.erase(v.find_by_order(v.order_of_key(values[vertex])));
    }
};

int main(void)
{
    int n, root;
    cin >> n;

    vector<int> p(n);
    graph gg;
    gg.init(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (p[i] == -1)
            root = i;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> gg.values[i];
    }

    gg.build(p);
    gg.dfs(root, -1);
    for (auto x : gg.ans)
        cout << x << ' ';
    cout << endl;
}