// class Solution {
// public:
//     int level[100005];
//     // pair<int,int> combine(pair<int,int> p1, pair<int,int> p2)
//     // {
//     //     pair<int,int>  p = {{p1.first+p2.first}, {p1.second + p2.second}};
//     //     return p;
//     // }
//     // pair<int,int> ans(int sc, int par, vector<vector<int>> &graph, int bus, vector<int> buses)
//     // {
//     //     pair<int,int> p = {0,1};
//     //     for(auto &child:graph[sc])
//     //     {
//     //         if(child==par) continue;
//     //         p = combine(p, ans(child, sc, graph, bus));
//     //         p.first += p.second/bus;
//     //         p.second=p.second%bus;
//     //     }
//     //     return p;
//     // }
//     int as = 0;
//     multiset<int> dfs(int seats, int sc, int par, vector<vector<int>> &graph)
//     {
//         multiset<int> c;
//         for(auto &child:graph[sc])
//         {
//             if(child==par) continue;
//             multiset<int> s1 = dfs(seats, child, sc, graph);
//             for(auto &val:s1) c.insert(val);
//         }
//         if(c.size() == 0 || *(c.begin())==seats)
//         {
//             cout<<sc<<" "<<level[sc]<<endl;
//             as +=level[sc];
//             c.insert(1);
//         }
//         else
//         {
//             int f = *c.begin();
//             c.erase(c.begin());
//             f++;
//             c.insert(f);
//         }
//         return c;
//     }
//     long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
//         memset(level, -1, sizeof(level));
//         if(roads.size() == 0) return 0;
//         vector<vector<int>> graph(100005);
//         for(auto &val:roads)
//         {
//             graph[val[0]].push_back(val[1]);
//             graph[val[1]].push_back(val[0]);
//         }
//         int root = roads[0][0];
//         for(int i = 0 ; i < roads.size() ; i++)
//         {
//             if(graph[i].size()>=graph[root].size()) root=i;
//         }
//         queue<int> q;
//         q.push(root);
//         level[q.front()] = 0;
//         while(!q.empty())
//         {
//             int f = q.front();
//             q.pop();
//             for(auto &child:graph[f])
//             {
//                 if(level[child] != -1) continue;
//                 q.push(child);
//                 level[child] = level[f] + 1;
//             }
//         }
//         int a = 0;
//         cout<<root<<endl;
//         for(auto &child:graph[root])
//         {
//            dfs(seats, child, root, graph);
//         }
//         return as;
//     }
// };