#include <bits/stdc++.h>
#define N 1000001
using namespace std;

typedef long long ll;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i) {
      while (!dq.empty() && dq.front() <= i - k)
        dq.pop_front();
      while (!dq.empty() && nums[dq.back()] < nums[i])
        dq.pop_back();

      dq.push_back(i);
      if (i >= k - 1)
        ans.push_back(nums[dq.front()]);
    }

    return ans;
  }
};

int main() {
    ll n, k;
    Solution solution;
    cin >> n >> k;
    vector<int> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> result = solution.maxSlidingWindow(a, k);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i]<<"\n";
    }
    return 0;
}

