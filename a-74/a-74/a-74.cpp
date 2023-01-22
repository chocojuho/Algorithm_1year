#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#define MOD 10000

using namespace std;

//PRINT는 최대 20번만 실행되므로, PRINT를 포함하지 않는 블록을 동차좌표를 이용한 27 x 27 행렬로 요약하여 시간을 줄임.

//인라인 함수로 나머지 연산 정의 MOD
inline long long mod(long long x) {
	return (x % MOD + MOD) % MOD;
}
//명령어 줄대로 저장
vector<string> program;
//몇번째 줄인지 쓴것
long long line;


//행렬 구조체 정의
struct matrix {
	vector<long long>  now;
	long long n, m;
	long long & operator()(long long r, long long s) {
		return now[r * m + s];
	}
	//구조체 생성자 오버로딩
	matrix(long long N, long long M) {
		n = N;
		m = M;
		now.resize(n * m);
		for (long long i = 0; i < n; i++) {
			for (long long j = 0; j < m; j++) {
				now[i * m + j] = 0;
			}
		}
	}
	//friend는 내부의 클래스에 접근하기 위하여 사용
	//opertaor연산자는 *,/,-,+,^등 일반적인 연산을 오버로딩 한것이다.
	//곱하기 연산자 재정의
	friend matrix operator * (matrix A, matrix B) {
		matrix C(A.n, B.m);
		for (long long i = 0; i < C.n; i++) {
			for (int j = 0; j < C.m; j++) {
				C(i, j) = 0;
				for (int k = 0; k < A.m; ++k) {
					C(i, j) += A(i, k) * B(k, j);
					C(i, j) %= MOD;
				}
			}
		}
		return C;
	}
	// 제곱 연산자 재정의
	friend matrix operator ^ (matrix A, long long k) {
		//거듭제곱을 이용한 분할정복
		if (k == 1) {
			// 지수가 1일때
			return A;
		}
		if (k % 2 == 1) {
			//지수가 홀수 일때
			return A * (A ^ (k - 1));
		}
		// 나머지
		matrix ans = A ^ (k / 2);
		return ans * ans;
	}
};

pair<matrix, long long> compiler(matrix condition) {
	matrix transition(27, 27);
	for (int i = 0; i < 27; i++) {
		transition(i, i) = 1;
	}
	long long print = 0;
	while (true) {
		//파싱
		istringstream iss(program[line]);
		//저장후 다음줄로 이동
		line += 1;
		string str;
		//공백제거 (파싱)
		iss >> str;
		// 명령어 계산
		// -명령어 정지(탈출 끝)
		if (str == "STOP") {
			break;
		}
		//명령어 반복문
		else if (str == "REPEAT") {
			long long num;
			//파싱(2번째) 몇번 반복할지 값
			iss >> num;
			long long temp = line;
			pair<matrix, long long> t = compiler(transition * condition);
			print |= t.second;
			if (t.second == 1) {
				transition = t.first * transition;
				for (int i = 0; i < num; i++) {
					line = temp;
					transition = compiler(transition * condition).first * transition;
				}
			}
			else {
				transition = (t.first ^ num) * transition;
			}
		}
		// 출력
		else if (str == "PRINT") {
			print = 1;
			string var;
			iss >> var;
			cout << var << "=" << mod((transition * condition)(var[0] - 'a', 0)) << '\n';
		}
		// 식부분 k = k+2
		else {
			matrix val(27, 27);
			for (long long i = 0; i < 27; i++) {
				val(i, i) = 1;
			}
			val(str[0] - 'a', str[0] - 'a') = 0;
			string oper, var;
			while (iss >> oper >> var) {
				long long k = 1;
				long long v = 26;
				if (isalpha(var[var.size() - 1])) {
					v = var[var.size() - 1] - 'a';
				}
				if (var[0] == '-' || isdigit(var[0])) {
					sscanf(var.c_str(), "%d", &k);
				}
				if (oper == "-") {
					k *= -1;
				}
				val(str[0] - 'a', v) += k;
			}
			transition = val * transition;
		}
	}
	return { transition,print };
}

int main()
{
	//입력 바르게
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	matrix condition(27, 1);
	condition(26, 0) = 1;
	//begin 건너 띔
	line = 1;
	//명령어 입력
	for (string i; getline(cin, i); program.push_back(i));
	compiler(condition);
	return 0;
}
