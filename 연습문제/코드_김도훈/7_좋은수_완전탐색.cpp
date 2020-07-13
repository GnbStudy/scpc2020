#include <iostream>

using namespace std;

int Answer;
int num[5000];

int main(int argc, char **argv)
{
  int T, test_case;
  int N, n, i, j, k;
  int flag;

  cin >> T;
  for (test_case = 0; test_case < T; test_case++)
  {

    Answer = 0;
    /////////////////////////////////////////////////////////////////////////////////////////////
    cin >> N;

    for (n = 0; n < N; n++)
    {
      cin >> num[n];
      flag = true;

      for (i = 0; i < n && flag; i++)
      {
        for (j = i; j < n && flag; j++)
        {
          for (k = j; k < n && flag; k++)
          {
            if (num[i] + num[j] + num[k] == num[n])
            {
              Answer++;
              flag = false;
            }
          }
        }
      }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////

    // Print the answer to standard output(screen).
    cout << "Case #" << test_case + 1 << endl;
    cout << Answer << endl;
  }

  return 0; //Your program should return 0 on normal termination.
}