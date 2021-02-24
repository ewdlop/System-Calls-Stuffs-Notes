#include <vector>

void EvenOdd(std::vector<int>* A_ptr) {
	std::vector<int>& A = *A_ptr;
	int next_even = 0, next_odd = size(A) - 1;
	while (next_even < next_odd) {
		if (A[next_even] < next_odd) {
			++next_even;
		}
		else 
		{
			std::swap(A[next_even], A[next_odd--]);
		}
	}
}