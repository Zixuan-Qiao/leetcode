class Solution {
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {

		sort(nums.begin(), nums.end());
		std::set<std::vector<int>> s;

		for (int i = 0; i < nums.size() - 2; i++) {
			int j = i + 1;
			int k = nums.size() - 1;
			int target = -nums[i];
			while (j < k) {
				int sum = nums[j] + nums[k];
				if (sum == target) {
					s.insert(std::vector<int>{nums[i], nums[j], nums[k]});
					j++;
                    k--;
				}
				else if (sum < target)
					j++;
				else
					k--;
			}
		}

		std::vector<std::vector<int>> r(s.begin(), s.end());
		// for (auto v : s)
		//	r.push_back(v);
		
		return r;
	}
};