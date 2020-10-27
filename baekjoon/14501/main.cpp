#include <iostream>
#include <algorithm>

using namespace std;

int solution(int N, int *T, int *P) {
	for (int i = N - 1; i >= 0; i--) {
		// 주어진 시간을 지나는 경우
		if (T[i] + i > N) {
			P[i] = P[i + 1];
			// P[i] = 0; -> 0으로 설정해놓으면 이후 반복문에서 최대값 추출이 잘못될 수 있음
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