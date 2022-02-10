class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int pointerOne = m - 1;
        int pointerTwo = n - 1;
        int end = nums1.size() - 1;
        while (pointerOne >= 0 && pointerTwo >= 0)
        {
            if (nums1[pointerOne] > nums2[pointerTwo])
            {
                nums1[end--] = nums1[pointerOne--];
            }
            else if (nums1[pointerOne] <= nums2[pointerTwo])
            {
                nums1[end--] = nums2[pointerTwo--];
            }
        }
        if (pointerTwo > pointerOne)
        {
            for (; end >= 0; end--)
            {
                nums1[end] = nums2[pointerTwo--];
            }
        }
    }
};