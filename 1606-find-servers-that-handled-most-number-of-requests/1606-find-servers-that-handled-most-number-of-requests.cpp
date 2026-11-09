class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        // Jo servers abhi free hain
        set<int> available;

        // Starting mein saare servers free hain
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {server kab free hoga, server number}
        // Sabse jaldi free hone wala server top par rahega
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > busy;

        // Har server ne kitni requests handle ki
        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            int currentTime = arrival[i];

            // Jo servers current time tak free ho chuke hain,
            // unko available set mein wapas daal do
            while (!busy.empty() && busy.top().first <= currentTime) {

                int serverNumber = busy.top().second;

                available.insert(serverNumber);

                busy.pop();
            }

            // i-th request ka preferred server
            int preferredServer = i % k;

            int serverToUse = -1;

            // preferredServer ya uske baad ka pehla available server
            auto it = available.lower_bound(preferredServer);

            if (it != available.end()) {

                // Preferred server se aage koi server available hai
                serverToUse = *it;

            } else if (!available.empty()) {

                // Aage nahi mila,
                // toh circularly starting server par chale jao
                serverToUse = *available.begin();
            }

            // Agar koi server available hi nahi hai
            if (serverToUse == -1) {
                continue;
            }

            // Server ko available list se hata do
            available.erase(serverToUse);

            // Is server ne ek request handle ki
            count[serverToUse]++;

            // Ye server load[i] time ke baad free hoga
            int freeTime = currentTime + load[i];

            // Busy heap mein daal do
            busy.push({freeTime, serverToUse});
        }

        // Sabse zyada requests handle karne wala count
        int maximumRequests = 0;

        for (int i = 0; i < k; i++) {
            maximumRequests = max(maximumRequests, count[i]);
        }

        // Answer mein woh saare servers daal do
        // jinka count maximum hai
        vector<int> answer;

        for (int i = 0; i < k; i++) {
            if (count[i] == maximumRequests) {
                answer.push_back(i);
            }
        }

        return answer;
    }
};