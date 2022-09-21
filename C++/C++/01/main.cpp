

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> mp;
	for (int i = 0; i < nums.size(); i++)
	{
		auto it = mp.find(target - nums[i]);
		if (it != mp.end())
		{
			return { it->second,i };
		}
		mp[nums[i]] = i;
	}
	return {};
}
int main()
{
	vector<int> nums({ 3,2,3 });

	for (int i : twoSum(nums, 6))
		std::cout << i << endl;

	return 0;
}
