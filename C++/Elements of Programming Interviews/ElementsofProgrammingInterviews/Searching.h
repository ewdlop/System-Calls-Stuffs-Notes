#pragma once
#include <vector>

class Searching {
public:
	int bsearch(int t, const std::vector<int>& A)
	{
		int L = 0, U = size(A) - 1;
		while (L <= U)
		{
			int M = (L + U) / 2;
			if (A[M] < t)
			{
				L = M + 1;
			}
			else
				if (A[M] == t)
				{
					return M;
				}
				else
				{
					U = M - 1;
				}
		}
		return -1;
	}
};