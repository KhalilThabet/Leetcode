class Solution
{
public:
    int tribonacci(int n)
    {
        int sequenceQueue[100] = {0};
        sequenceQueue[1] = 1;
        sequenceQueue[2] = 1;
        for (int i = 3; i < n + 1; i++)
        {
            sequenceQueue[i] = sequenceQueue[i - 1] + sequenceQueue[i - 2] + sequenceQueue[i - 3];
        }
        return sequenceQueue[n];
    }
};
