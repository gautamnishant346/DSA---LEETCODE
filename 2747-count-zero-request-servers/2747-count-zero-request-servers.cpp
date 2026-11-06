class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        // 1. Logs ko time ke according sort kar do
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        // 2. Queries ko time ke according sort karenge
        vector<pair<int, int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());

        // freq[server] = current window me us server ki requests
        vector<int> freq(n + 1, 0);

        int left = 0;
        int right = 0;

        // Current window me kitne unique servers hain
        int activeServers = 0;

        for (auto [queryTime, originalIndex] : q) {

            int startTime = queryTime - x;

            // Right pointer se naye logs window me add karo
            while (right < logs.size() &&
                   logs[right][1] <= queryTime) {

                int server = logs[right][0];

                if (freq[server] == 0) {
                    activeServers++;
                }

                freq[server]++;
                right++;
            }

            // Jo logs window ke left se bahar ho gaye,
            // unhe remove karo
            while (left < logs.size() &&
                   logs[left][1] < startTime) {

                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0) {
                    activeServers--;
                }

                left++;
            }

            // Total servers - active servers
            ans[originalIndex] = n - activeServers;
        }

        return ans;
    }
};