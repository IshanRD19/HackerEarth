/*
Problem
You are given an array A of N integers.
You want to choose some integers from the array subject to the condition that the number of distinct integers chosen should not exceed K.
Your task is to maximize the sum of chosen numbers.

You are given T test cases.

Input format
The first line contains a single integer T denoting the number of test cases.
The first line of each test case contains two space-separated integers N and K denoting the length of the array and the maximum number of distinct integers you can choose.
The second line of each test case contains N space-separated integers denoting the integer array A.

Output format
For each test case (in a separate line), print the maximum sum you can obtain by choosing some elements such that the number of distinct integers chosen is at most K.
If you cannot choose any element, output 0.

Constraints
- 1 <= T <= 1000
- 1 <= K <= N <= 5 * 10^5
- -10^9 <= A[i] <= 10^9
- Sum of N over all test cases does not exceed 2 * 10^6

Sample Input
2
4 1
3 -1 2 5
4 2
2 1 2 5

Sample Output
5
9

Time Limit: 1.5
Memory Limit: 256
*/

// Write your code here
#include <iostream>
#include <bits/stdc++.h>
#include <map>

using namespace std;

int main()
{
  // Declare variables
  int T, i, N, K;

  // Store the number of testcases
  cin >> T;

  // For each testcase
  while(T > 0)
  {
    // Store the length of the array and the maximum number of distinct integers to choose
    cin >> N >> K;

    // Declare variables
    long int A[N], max_sum;
    map<long int, long int> integer_map;

    // Variable initialization
    max_sum = 0;

    // Store the input array of integers
    for(i=0; i<N; i++)
    {
      cin >> A[i];
    }

    // For each integer in the input array
    for(i=0; i<N; i++)
    {
      // Ignore if the integer is negative
      if(A[i] < 0)
      {
        continue;
      }

      // Check if integer already exists in map or not
      if(integer_map.find(A[i]) != integer_map.end())
      {
        integer_map.at(A[i]) = integer_map.at(A[i]) + A[i];
      }
      else
      {
        integer_map.insert({A[i], A[i]});
      }
    }

    // Variable declaration
    vector<long int> distinct_integer_sums(integer_map.size());
    long int j;

    // For each key in the integer map
    for(auto j=integer_map.begin(); j!=integer_map.end(); j++)
    {
      // Append the value in the vector
      distinct_integer_sums.push_back(j -> second);
    }

    // Sort the vector
    sort(distinct_integer_sums.begin(), distinct_integer_sums.end(), greater<long int>());

    // Reset index value
    i = 0;

    // Set the minimum number of distinct integers to consider
    if(distinct_integer_sums.size() < K)
    {
      K = distinct_integer_sums.size();
    }

    // Update the maximum sum for respective distinct integers
    while(K>0)
    {
      long int & element = distinct_integer_sums.at(i);
      max_sum = max_sum + element;
      i++;
      K--;
    }
    // Display the maximum sum of at most K distinct integers
    cout << max_sum << endl;
    T--;
  }
  return 0;
}
