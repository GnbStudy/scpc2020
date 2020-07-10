/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <algorithm>

using namespace std;

int Answer;
int score[300000];

int main(int argc, char **argv)
{
  int T, test_case, N, i, max;
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
    cin >> N;

    for (i = 0; i < N; i++)
      cin >> score[i];

    sort(score, score + N);

    for (i = 0; i < N; i++)
    {
      if (i == 0)
        max = score[i];
      else if (score[i] + N - i > max)
        max = score[i] + N - i;
    }

    for (i = 0; i < N; i++)
      if (score[i] + N >= max)
        Answer++;
    /////////////////////////////////////////////////////////////////////////////////////////////

    // Print the answer to standard output(screen).
    cout << "Case #" << test_case + 1 << endl;
    cout << Answer << endl;
  }

  return 0; //Your program should return 0 on normal termination.
}