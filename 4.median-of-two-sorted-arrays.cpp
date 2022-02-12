#include <vector>
#include <iostream>

using namespace std;
class Solution
{
public:
	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
	{
		int n = nums1.size() - 1;
		int m = nums2.size() - 1;
		int end = m + n + 1;
		int median = (m + n + 2);
		for (int i = 0; i < nums1.size(); i++)
			cout << nums1[i] << " ";
		cout << endl;
		for (int i = 0; i < m + 1; i++)
			nums1.push_back(0);

		while (n >= 0 && m >= 0)
		{
			if (nums1[n] > nums2[m])
			{
				nums1[end--] = nums1[n--];
			}
			if (nums1[n] <= nums2[m])
				nums1[end--] = nums2[m--];
		}
		if (n > m)
			while (n >= 0)
				nums1[end--] = nums1[n--];
		else if (m > n)
			while (m >= 0)
				nums1[end--] = nums2[m--];
		for (int i = 0; i < nums1.size(); i++)
			cout << nums1[i] << " ";
		cout << endl;
		if (median % 2 == 0)
		{
			return (double)(nums1[median / 2] + nums1[median / 2 - 1]) / 2;
		}
		else
			return nums1[median / 2];
	}
};

int main()
{
	Solution s;
	vector<int> v{0, 0, 0, 0, 0};
	vector<int> c{-1, 0, 0, 0, 0, 0, 1};
	cout << s.findMedianSortedArrays(v, c) << endl;
}
