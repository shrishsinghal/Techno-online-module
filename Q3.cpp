#include <iostream>
using namespace std;

int A[3][3][2], O[3][3], D[3][3];

void OR() {
	for (int i =0; i<3; i++) {
		for (int j=0; j<3; j++) {
			O[i][j] = (A[i][j][0] || A[i][j][1]);
		}
	}
}
void AND() {
	for (int i =0; i<3; i++) {
		for (int j=0; j<3; j++) {
			D[i][j] = (A[i][j][0] && A[i][j][1]);
		}
	}
}
int compare() {
	int sum = 0;
	for (int i =0; i<3; i++) {
		for (int j=0; j<3; j++) {
			if (O[i][j] == D[i][j]) sum += (3*i + j + 1);
		}
	}
	return sum;
}

int main() {
	for (int i =0; i<3; i++) {
		for (int j=0; j<3; j++) {
			cin >> A[i][j][0] >> A[i][j][1];
		}
	}
	OR();
	AND();
	cout << compare() << endl;
	return 0;
}