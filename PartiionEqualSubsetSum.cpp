#include <bits/stdc++.h>
using namespace std;

// // Using recursion
// bool isSubsetSum(int arr[] , int n , int sum){
//     // base case
//     if(sum == 0)
//         return true;
//     if(n == 0 && sum != 0)
//         return false;

//     // if last element is greater then sum , then ignore
//     if(arr[n-1] > sum)
//         return isSubsetSum(arr, n-1,sum);

//     return isSubsetSum(arr, n-1, sum) || isSubsetSum(arr, n-1,sum-arr[n-1]);
// }
// bool findPartiion(int arr[], int n)
// {
//     // Calculate sum of the elements in array
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//         sum += arr[i];

//     // If sum is odd, there cannot be two subsets
//     // with equal sum
//     if (sum % 2 != 0)
//         return false;

//     // Find if there is subset with sum equal to
//     // half of total sum
//     return isSubsetSum(arr, n, sum / 2);

// }
// int main()
// {
//     int arr[] = { 3, 1, 5, 9, 12 };
//     int n = sizeof(arr) / sizeof(arr[0]);

//     // Function call
//     if (findPartiion(arr, n) == true)
//         cout << "Can be divided into two subsets of equal sum";
//     else
//         cout << "Can not be divided into two subsets of equal sum";
//     return 0;
// }
// // T.C = O(2^n)
// // S.C = O(N)

// // Using memoization
// bool isSubsetSum(int arr[] , int n , int sum , vector<vector<int> >& dp){
//     // base case
//     if(sum == 0)
//         return true;
//     if(n == 0 && sum != 0)
//         return false;

//     if(dp[n][sum != -1]){
//         return dp[n][sum];
//     }
//     // if last element is greater then sum , then ignore
//     if(arr[n-1] > sum)
//         return isSubsetSum(arr, n-1,sum,dp);

//     return isSubsetSum(arr, n-1, sum, dp) || isSubsetSum(arr, n-1,sum-arr[n-1], dp);
// }
// bool findPartiion(int arr[], int n)
// {
//     // Calculate sum of the elements in array
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//         sum += arr[i];

//     // If sum is odd, there cannot be two subsets
//     // with equal sum
//     if (sum % 2 != 0)
//         return false;

//     // to store overlapping subproblems
//     vector<vector<int> > dp(n+1 , vector<int>(sum + 1, -1));

//     // Find if there is subset with sum equal to
//     // half of total sum
//     return isSubsetSum(arr, n, sum / 2 , dp);

// }
// int main()
// {
//     int arr[] = { 3, 1, 5, 9, 12 };
//     int n = sizeof(arr) / sizeof(arr[0]);

//     // Function call
//     if (findPartiion(arr, n) == true)
//         cout << "Can be divided into two subsets "
//                 "of equal sum";
//     else
//         cout << "Can not be divided into two subsets"
//                 " of equal sum";

//     int arr2[] = { 3, 1, 5, 9, 14 };
//     int n2 = sizeof(arr2) / sizeof(arr2[0]);

//     if (findPartiion(arr2, n2) == true)
//         cout << endl
//              << "Can be divided into two subsets "
//                 "of equal sum";
//     else
//         cout << endl
//              << "Can not be divided into two subsets"
//                 " of equal sum";
//     return 0;
// }

// T.C = O(sum * N)
// S.C = O(sum * N)

// Space optimization

bool findPartiion(int arr[], int n)
{
    int sum = 0;
    int i, j;

    // calculate sum of all element
    for (i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 != 0)
        return false;

    bool part[sum / 2 + 1];

    for (i = 0; i <= sum / 2; i++)
    {
        part[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = sum / 2; j >= arr[i]; j--)
        {
            if (part[j - arr[i]] == 1 || j == arr[i])
                part[j] = 1;
        }
    }
    return part[sum / 2];
}
int main()
{
    int arr[] = {1, 3, 3, 2, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (findPartiion(arr, n) == true)
        cout << "Can be divided into two subsets "
                "of equal sum";
    else
        cout << "Can not be divided into two subsets"
                " of equal sum";

    return 0;
}
// T.C = O(sum * N)
// S.C = O(sum)