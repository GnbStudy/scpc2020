/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <cmath>

using namespace std;

int Answer;
int Point[] = {6, 13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8, 16, 7, 19, 3, 17, 2, 15, 10};

int main(int argc, char **argv)
{
  int T, test_case, i;
  int A, B, C, D, E, N, x, y, n, base, score;
  double r, p;
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
    cin >> A >> B >> C >> D >> E >> N;

    for (i = 0; i < N; i++)
    {
      cin >> x >> y;
      r = sqrt(x * x + y * y);
      p = atan2((double)y, (double)x);

      if (p < -M_PI / 20)
        p += 2 * M_PI;

      n = floor(p * 10 / M_PI + 0.5);
      base = Point[n];

      if (r < A)
        score = 50;
      else if (B < r && r < C)
        score = base * 3;
      else if (D < r && r < E)
        score = base * 2;
      else if (r > E)
        score = 0;
      else
        score = base;

      Answer += score;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////

    // Print the answer to standard output(screen).
    cout << "Case #" << test_case + 1 << endl;
    cout << Answer << endl;
  }

  return 0; //Your program should return 0 on normal termination.
}