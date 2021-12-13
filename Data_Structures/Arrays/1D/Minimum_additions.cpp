/*
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/minimum-additions-0142ac80/

Problem
You are given an array A of N positive integers.
Your task is to add a minimum number of non-negative integers to the array such that the floor of an average of array A becomes less than or equal to K.

You are given T test cases.

Input format
- The first line contains a single integer T that denotes the number of test cases.
  For each test case:
  - The first line contains two space-separated integers N and K denoting the length of the array and the required bound.
  - The second line contains N space-separated integers denoting the integer array A

Output format
- For each test case (in a separate line), print the minimum number of non-negative integers that should be added to array A such that the floor of an average of array A is less than or equal to K.

Constraints
- 1 <= T <= 10
- 1 <= N <= 2 * 10^5
- 1 <= A[i] <= 10^9
- 0 <= K <= 10^9

Sample Input
2
2 1
3 1
2 2
2 1

Sample Output
1
0

Time Limit: 1
Memory Limit: 256
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  // Variable declaration
  int T, N, K, i;
  long int sum;

  // Store the number of testcases
  cin >> T;

  // For each testcase
  while(T > 0)
  {
    // Variable initialization
    sum = 0;

    // Store the length of the array and the required bound
    cin >> N >> K;

    // Store the input array of integers
    long int A[N];
    for(i=0; i<N; i++)
    {
      cin >> A[i];
      sum = sum + A[i];
    }

    // Check if required condition is already satisfied
  	if(sum / N <= K)
  	{
  		cout << 0 << endl;
  	}

    // Otherwise calculate the minimum number of non-negative integers (0s) to add
  	else
  	{
      // sum / (N+x) < K + 1
      // sum / K < N + x
      // x = (sum / K+1) - N + 1
  		cout << (sum / (K + 1)) - N + 1 << endl;
  	}
    T--;
  }
  return 0;
}
