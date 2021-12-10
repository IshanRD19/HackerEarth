/*
Problem
You are given an array  consisting of  positive integers.
Your task is to find an array B of length N satisfying the following conditions:

- B[i] > 0 for all 1 <= i <= N
- B[i] <= B[i+1] for all 1 <= i < N
- B[i] is divisible by A[i] for all 1 <= i <= N
- Sum of B[i] for all 1 <= i <= N is minimum

You are given T test cases.

Input format
The first line contains a single integer  denoting the number of test cases.
The first line of each test case contains a single integer  denoting the length of the array.
The second line of each test case contains  space-separated integers denoting the integer array .

Output format
For each test case (in a separate line), print  space-separated integers denoting . If there are multiple answers, you can print any of them. It is guaranteed that under the given constraints at least 1  exists.

Constraints
- 1 <= T <= 1000
- 1 <= N <= 2.5 * 10^5
- 1 <= A[i] <= 10^9
- Sum of N over all test cases does not exceed 7.5 * 10^5

Sample Input
2
3
2 1 3
2
5 1
Sample Output
2 2 3
5 5
Time Limit: 1
Memory Limit: 256
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  // Variable declaration
  int testcases, t, i, array_size;

  // Store the number of testcases
  cin >> testcases;

  // For each testcase
  while(testcases > 0)
  {
    // Store the length of the array
    cin >> array_size;

    // Declare integer arrays
    int original_array[array_size];
    long int final_array[array_size];

    // Store the original input array
    for(i=0; i<array_size; i++)
    {
      cin >> original_array[i];
    }

    // The first element remains the same
    final_array[0] = (long int) original_array[0];

    // Get the respective non-decreasing array
    for(i=1; i<array_size; i++)
    {
      // Check if next element is already non-decreasing
      if(original_array[i] >= final_array[i-1])
      {
        final_array[i] = original_array[i];
      }

      // Otherwise find the smallest non-decreasing multiple
      else
      {
        final_array[i] = original_array[i] * ceil((double)final_array[i-1] / (double)original_array[i]);
      }
    }

    // Display the final non-decreasing array
    for(i=0; i<array_size; i++)
    {
      cout << final_array[i] << " ";
    }

    // Proceed to the next testcase
    cout << endl;
    testcases--;
  }
  return 0;
}
