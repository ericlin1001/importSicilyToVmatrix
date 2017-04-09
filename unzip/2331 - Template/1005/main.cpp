template<typename T>
int find_lower_bound(T seq[], int n, const T& value) {
	T temp;
	int flag;
	int flag2 = 0;
	for (int i = 0; i != n; i++) {
		if (seq[i] < value && flag2 == 0) {
			temp = seq[i];
			flag = i;
			flag2++;
		} else if(seq[i] < value && flag2 != 0 && temp < seq[i]) {
			temp = seq[i];
			flag = i;
		}
	}
	if (flag2 == 0) {
		return -1;
	} else {
		return flag;
	}
}

