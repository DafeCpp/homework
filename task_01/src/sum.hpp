int ps(int a, int b, int c) {
	int max{ a };
	int min{ a };
	for (int i{ 0 }; i < 3; ++i) {
		if (max < b) {
			max = b;
		}
		if (max < c) {
			max = c;
		}
		if (min > b) {
			min = b;
		}
		if (min > c) {
			min = c;
		}

	}
	return a + b + c - min - max;
}