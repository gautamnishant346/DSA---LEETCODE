class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        
        long long ans = 0;
        long long cost = 0;

        // deque me pair:
        // {value, kitne elements is value par hain}
        deque<pair<int, int>> dq;

        int n = nums.size();

        // Right se left ja rahe hain
        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {

            int num = nums[i];
            int count = 1;

            // Agar current num bada hai,
            // to peeche ke chhote values ko current num tak badhana padega
            while (!dq.empty() && dq.back().first < num) {

                int smallValue = dq.back().first;
                int smallCount = dq.back().second;

                dq.pop_back();

                count += smallCount;

                // Itne elements ko smallValue -> num karna padega
                cost += 1LL * (num - smallValue) * smallCount;
            }

            // Current value ko deque me daal do
            dq.push_back({num, count});


            // Agar operations k se zyada ho gaye,
            // right side se elements hatao
            while (cost > k) {

                int value = dq.front().first;
                int cnt = dq.front().second;

                dq.pop_front();

                // nums[j] ko value tak badhaya gaya tha
                // ab us element ko window se remove kar rahe hain
                cost -= 1LL * (value - nums[j]);

                j--;

                // Agar same value ke aur elements bache hain
                if (cnt > 1) {
                    dq.push_front({value, cnt - 1});
                }
            }

            // [i ... j] ke andar:
            // [i], [i+1...j], ..., [j]
            // total = j-i+1 valid subarrays
            ans += (j - i + 1);
        }

        return ans;
    }
};