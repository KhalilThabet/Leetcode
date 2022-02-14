class Solution
{
public:
    int fib(int n)
    {
        int sequenceQueue[100]{0};
        sequenceQueue[1] = 1;
        for (int i = 2; i < n + 1; i++)
        {
            sequenceQueue[i] = sequenceQueue[i - 1] + sequenceQueue[i - 2];
        }
        return sequenceQueue[n];
    }
};
