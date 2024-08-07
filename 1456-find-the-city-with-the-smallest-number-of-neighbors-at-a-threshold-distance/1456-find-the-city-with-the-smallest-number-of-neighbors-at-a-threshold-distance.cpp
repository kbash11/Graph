class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(int i=0;i<edges.size();i++){
            dist[edges[i][0]][edges[i][1]]=edges[i][2];
            dist[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }
        int ans = 0;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= mini) {
                mini = count;
                ans = i;
            }
        }
        return ans;
    }
    // void solve(int src, vector<list<pair<int, int>>>& adj, vector<int>& arr) {
    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //     pq.push({0, src});
    //     arr[src] = 0; 

    //     while (!pq.empty()) {
    //         auto [dist, node] = pq.top();
    //         pq.pop();

    //         for (auto it : adj[node]) {
    //             if (dist + it.second < arr[it.first]) {
    //                 pq.push({dist + it.second, it.first});
    //                 arr[it.first] = dist + it.second;
    //             }
    //         }
    //     }
    // }

    // int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    //     vector<list<pair<int, int>>> adj(n); 
    //     for (const auto& edge : edges) {
    //         adj[edge[0]].push_back({edge[1], edge[2]});
    //         adj[edge[1]].push_back({edge[0], edge[2]}); // Consider undirected graph
    //     }

    //     vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    //     for (int i = 0; i < n; i++) {
    //         vector<int> arr(n, INT_MAX);
    //         solve(i, adj, arr);
    //         dist[i] = arr; 
    //     }

    //     int ans = 0;
    //     int mini = INT_MAX;
    //     for (int i = 0; i < n; i++) {
    //         int count = 0;
    //         for (int j = 0; j < n; j++) {
    //             if (i != j && dist[i][j] <= distanceThreshold) {
    //                 count++;
    //             }
    //         }
    //         if (count <= mini) {
    //             mini = count;
    //             ans = i;
    //         }
    //     }
    //     return ans;
    // }
};