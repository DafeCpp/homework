#include "foonk.h"

void mass(int* ps, int size, int n) {
	for (int i{ 0 }; i < n; ++i) {
		int s{ ps[size-1] };
		for (int j{ size - 1 }; j > 0; --j) {
			ps[j] = ps[j - 1];
		}
		ps[0] = s;
	}
}