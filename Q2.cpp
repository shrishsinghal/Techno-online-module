#include <iostream>
using namespace std;

int GCD(int p, int q) {
	if (p < q) {
		int temp = p;
		p = q;
		q = temp;
	}
	if (p%q == 0) return q;
	return GCD(q, p%q);
}

struct fraction {
	int a, b;
	fraction() {
		a = 0;
		b = 1;
	}
	fraction(int x, int y) {
		a = x;
		b = y;
	}
	fraction operator+(const fraction &f) {
		int den = b*f.b/GCD(b, f.b);
		int num = a * den / b + f.a * den / f.b;
		fraction fr(num, den);
		return fr;
	}
};

fraction fracts[3][3];

void transpose() {
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			cout << fracts[j][i].a << '/' << fracts[j][i].b << ' ';
		}
		cout << endl;
	}
}

void trace() {
	fraction f = fracts[0][0]+fracts[1][1]+fracts[2][2];
	cout << f.a << '/' << f.b << endl;
}

void storeMatrix() {
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			int x, y;
			char s;
			cin >> x >> s >> y;
			fraction f(x, y); 
			fracts[i][j] = f;
		}
	}
}

int main() {
	storeMatrix();
	cout << "Transpose is:\n";
	transpose();
	cout << "Trace is:";
	trace();
	return 0;
}