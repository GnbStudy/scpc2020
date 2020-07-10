/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>

using namespace std;
typedef long long ll;

ll Answer;

ll next_num(ll n, ll x, ll y, ll N, char UDLR)
{
	if (UDLR == 'R')
	{
		if ((x + y) % 2 == 0)
		{
			if (x + y < N - 1)
				return n + 2 * y + 1;
			if (x + y == N - 1)
				return n + 2 * y;
			else
				return n + 2 * (N - x) - 2;
		}
		else
		{
			if (x + y < N - 1)
				return n + 2 * x + 2;
			if (x + y == N - 1)
				return n + 2 * x + 1;
			else
				return n + 2 * (N - y) - 1;
		}
	}
	if (UDLR == 'D')
	{
		if ((x + y) % 2 == 0)
		{
			if (x + y < N - 1)
				return n + 2 * y + 2;
			if (x + y == N - 1)
				return n + 2 * y + 1;
			else
				return n + 2 * (N - x) - 1;
		}
		else
		{
			if (x + y < N - 1)
				return n + 2 * x + 1;
			if (x + y == N - 1)
				return n + 2 * x;
			else
				return n + 2 * (N - y) - 2;
		}
	}
	if (UDLR == 'L')
	{
		if ((x + y) % 2 == 0)
		{
			if (x + y < N - 1)
				return n - 2 * x;
			if (x + y == N - 1)
				return n - 2 * x;
			else
				return n - 2 * (N - y) + 1;
		}
		else
		{
			if (x + y < N - 1)
				return n - 2 * y - 1;
			if (x + y == N - 1)
				return n - 2 * y - 1;
			else
				return n - 2 * (N - x);
		}
	}
	else
	{
		if ((x + y) % 2 == 0)
		{
			if (x + y < N - 1)
				return n - 2 * x - 1;
			if (x + y == N - 1)
				return n - 2 * x - 1;
			else
				return n - 2 * (N - y);
		}
		else
		{
			if (x + y < N - 1)
				return n - 2 * y;
			if (x + y == N - 1)
				return n - 2 * y;
			else
				return n - 2 * (N - x) + 1;
		}
	}
}

int main(int argc, char **argv)
{
	int T, test_case;
	ll N, K, i, x, y;
	ll num;
	char UDLR_char;
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

		Answer = 1;
		/////////////////////////////////////////////////////////////////////////////////////////////
		cin >> N >> K;
		x = y = 0;
		num = 1;

		for (i = 0; i < K; i++)
		{
			cin >> UDLR_char;

			num = next_num(num, x, y, N, UDLR_char);

			if (UDLR_char == 'U')
				y--;
			else if (UDLR_char == 'D')
				y++;
			else if (UDLR_char == 'L')
				x--;
			else if (UDLR_char == 'R')
				x++;

			Answer += num;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0; //Your program should return 0 on normal termination.
}