#include <iostream>

using namespace std;

int maxProfit(int* prices, int size)
{
    if (size == 0)
    {
        return 0;
    }

    int maxTransactions = 3;

    int*** dp = new int** [size];
    for (int i = 0; i < size; ++i)
    {
        dp[i] = new int* [maxTransactions + 1];
        for (int j = 0; j <= maxTransactions; ++j)
        {
            dp[i][j] = new int[2];
            dp[i][j][0] = 0;           
            dp[i][j][1] = -prices[0];  
        }
    }

    for (int i = 1; i < size; ++i)
    {
        for (int j = 0; j <= maxTransactions; ++j)
        {
            dp[i][j][0] = dp[i - 1][j][0];
            if (j > 0)
            {
                if (dp[i - 1][j][1] + prices[i] > dp[i][j][0])
                {
                    dp[i][j][0] = dp[i - 1][j][1] + prices[i];
                }
            }
            dp[i][j][1] = dp[i - 1][j][1];
            if (j > 0)
            {
                if (dp[i - 1][j - 1][0] - prices[i] > dp[i][j][1])
                {
                    dp[i][j][1] = dp[i - 1][j - 1][0] - prices[i];
                }
            }
        }
    }

    int maxProfit = 0;
    for (int j = 0; j <= maxTransactions; ++j)
    {
        if (dp[size - 1][j][0] > maxProfit)
        {
            maxProfit = dp[size - 1][j][0];
        }
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j <= maxTransactions; ++j)
        {
            delete[] dp[i][j];
        }
        delete[] dp[i];
    }
    delete[] dp;

    return maxProfit;
}

int main()
{
    int size;
    cout << "Enter the number of days: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid number of days." << endl;
        return 1;
    }

    int* prices = new int[size];
    cout << "Enter the prices: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> prices[i];
    }

    cout << "Maximum Profit: " << maxProfit(prices, size) << endl;

    delete[] prices;
    return 0;
}
