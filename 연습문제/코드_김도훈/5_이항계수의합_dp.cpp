/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>

using namespace std;

int Answer;
int value[100][100];
int found[100][100];
const int D = 1000000007;

int combination(int n, int k)
{
  if (found[n][k])
    return value[n][k];

  int result;

  if (n == 0 || k == 0 || n == k)
    result = 1;

  else
    result = (combination(n - 1, k - 1) % D + combination(n - 1, k) % D) % D;

  value[n][k] = result;
  found[n][k] = 1;

  return result;
}

int main(int argc, char **argv)
{
  int T, test_case;
  int N, M, i, j;
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

    for (i = 0; i <= N; i++)
      for (j = 0; j <= M; j++)
        Answer += combination(i + j, i);
    /////////////////////////////////////////////////////////////////////////////////////////////

    // Print the answer to standard output(screen).
    cout << "Case #" << test_case + 1 << endl;
    cout << Answer << endl;
  }

  return 0; //Your program should return 0 on normal termination.
}