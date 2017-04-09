Complex operator*(const Complex &c1, const Complex &c2) {
	Complex temp;
	temp.real = c1.real * c2.real - c2.imag * c1.imag;
	temp.imag = c1.real * c2.imag + c2.real * c1.imag;
	return temp;
}
istream& operator>>(istream &input, Complex& k) {
	string temp;
	input >> temp;
	int i, j;
	if (temp[0] != '-') k.real = temp[0] - '0';
	else k.real = -1;
	for (i = 1; temp[i] >= '0' && temp[i] <='9'; ++i) {

		k.real = 10 * k.real + temp[i] - '0';
	}
	for (j = i + 1; j <= temp.length() - 2; ++j) {
		k.imag = 10 * k.imag + temp[j] - '0';
	}
	if (temp[i] == '-') k.imag*= -1;
	return input;
}
ostream& operator<<(ostream &output, const Complex &k) {
	output << k.real;
	if (k.imag >= 0) output << '+';
	output << k.imag << 'i';
	return output;
}

