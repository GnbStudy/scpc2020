/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#define D 1000000007

using namespace std;
typedef long long ll;

ll Answer, Max;
ll memo[2000004];

ll factorial(int n)
{
  ll result = 1;

  for (int i = Max + 1; i <= n; i++)
    memo[i] = ((i % D) * memo[i - 1]) % D;

  if (Max < n)
    Max = n;

  return memo[n];
}

ll fast_power(ll base, ll power)
{
  ll result = 1;
  while (power > 0)
  {
    if (power & 1)
    {
      result = (result * base) % D;
    }
    base = (base * base) % D;
    power >>= 1;
  }
  return result;
}

ll combination(int n, int k)
{
  ll numerator, denominator, result;

  numerator = factorial(n);
  denominator = (factorial(k) * factorial(n - k)) % D;
  result = (numerator * fast_power(denominator, D - 2)) % D;

  return result;
}

int main(int argc, char **argv)
{
  int T, test_case;
  int N, M, i, j;

  memo[0] = 1;

  /*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

  // freopen("input.txt", "r", stdin);

  cin >> T;
  for (test_case = 0; test_case < T; test_case++)
  {

    Answer = 0;
    /////////////////////////////////////////////////////////////////////////////////////////////
    cin >> N >> M;
    Answer = combination(N + M + 2, N + 1) - 1;
    /////////////////////////////////////////////////////////////////////////////////////////////

    // Print the answer to standard output(screen).
    cout << "Case #" << test_case + 1 << endl;
    cout << Answer << endl;
  }

  return 0; //Your program should return 0 on normal termination.
}