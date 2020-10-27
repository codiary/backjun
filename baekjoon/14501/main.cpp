#include <iostream>
#include <algorithm>

using namespace std;

int solution(int N, int *T, int *P) {
	for (int i = N - 1; i >= 0; i--) {
		// �־��� �ð��� ������ ���
		if (T[i] + i > N) {
			P[i] = P[i + 1];
			// P[i] = 0; -> 0���� �����س����� ���� �ݺ������� �ִ밪 ������ �߸��� �� ����
		}
		else {
			P[i] = max(P[i + 1], P[i] + P[i + T[i]]);
		}
	}

	return P[0];
}

int main(void) {

	int N = 0;
	int T[15] = { 0 };
	int P[15] = { 0 };

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}

	int result = solution(N, T, P);
	cout << result << endl;

	return 0;
}