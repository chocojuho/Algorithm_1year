#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
	int (*list)[3];
	int i, students;
	cout << "학생의 수 : ";
	cin >> students;
	list = (int**)malloc(8 * 3);
	*(list+0) = (int*)malloc(4* 3);
	if (list == NULL) {
		cout << "동적메모리 할당 오류";
		exit(1);
	}
	for (i = 0; i < students; i++) {
		for (auto j = 0; j < 3; j++) {
			cin >> *(*(list +i)+j);
		}
	}
	cout << "==============================\n";
	for (i = 0; i < students; i++) {
		cout << *(list + i) << ' ';
	}
	cout << "==============================\n";
	free(list);
}