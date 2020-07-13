#include <iostream>
#define SIZE 400001
#define HALF 200000

using namespace std;

int Answer;
int num[5000];
bool good[SIZE];

int main(int argc, char **argv)
{
  int T, test_case;
  int N, n, i, j, k, idx;

  cin >> T;
  for (test_case = 0; test_case < T; test_case++)
  {

    Answer = 0;
    /////////////////////////////////////////////////////////////////////////////////////////////
    fill_n(good, SIZE, false);

    cin >> N;

    for (n = 0; n < N; n++)
    {
      cin >> num[n];

      for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
        {
          idx = num[i] + num[j] + num[n - 1] + HALF;
          if (idx >= 0 && idx < SIZE)
            good[idx] = true;
        }

      if (good[num[n] + HALF])
        Answer++;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////

    // Print the answer to standard output(screen).
    cout << "Case #" << test_case + 1 << endl;
    cout << Answer << endl;
  }

  return 0; //Your program should return 0 on normal termination.
}