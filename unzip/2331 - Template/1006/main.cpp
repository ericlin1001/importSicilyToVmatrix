template<class T>
void swapVar(T &var1, T &var2) {
	T tmp;
	tmp = var1;
	var1 = var2;
	var2 = tmp;
}

