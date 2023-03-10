#define 입력 cin 
#define 출력 cout 
#define 반복 for 
#define 만약 if 
#define 사용 using 
#define 이름공간 namespace 
#define 표준 std
#define 정수 int
#define 벡터 vector
#define 묶음 pair 
#define 할때까지반복 while 
#define 없다 void
#define 중심지 main
#define 넣다 push
#define 정렬하다 sort
#define 우선순위큐형 priority_queue
#define 비어있다 empty
#define 빼다 pop
#define 최고위치 top
#define 크기 size
#define 계속하다 continue
#define 비우다 clear
#define 뒤에넣다 push_back
#define 첫번째 first
#define 두번째 second
#define 줄바꿈 '\n'
#define 앞 begin
#define 뒤 end
#define 공백 " "
#define 널 NULL
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


사용 이름공간 표준;

정수 무한대 = 10000000;

벡터<묶음<정수, 정수>> 거리[2010];
벡터<정수> 후보지;
정수 반복횟수;
정수 s의거리[2010];
정수 g의거리[2010];
정수 h의거리[2010];
정수 가야하는곳1과가야하는곳2의거리;
정수 교차로개수, 도로개수, 목적지후보개수;
정수 예술가출발지, 가야하는곳1, 가야하는곳2;
없다 초기화();

없다 다익스트라(정수 시작,정수 임시최소길이[2010]) {
	임시최소길이[시작] = 0;
	우선순위큐형<묶음<정수, 정수>> 우선순위큐;
	우선순위큐.넣다({ 시작,0 });

	할때까지반복 (!우선순위큐.비어있다()) {
		정수 현재 = 우선순위큐.최고위치().첫번째;
		정수 현재길이 = -우선순위큐.최고위치().두번째;
		우선순위큐.빼다();

		만약 (임시최소길이[현재] < 현재길이) 계속하다;
		정수 거리현재크기 = 거리[현재].크기();
		반복 (정수 임시1 = 0; 임시1 < 거리현재크기; 임시1++) {
			정수 다음 = 거리[현재][임시1].첫번째;
			정수 다음거리 = 현재길이 + 거리[현재][임시1].두번째;

			만약 (다음거리 < 임시최소길이[다음]) {
				임시최소길이[다음] = 다음거리;
				우선순위큐.넣다({ 다음,-다음거리 });
			}
		}
	}
}
없다 초기화() {
	반복 (정수 임시1 = 0; 임시1 < 2010; 임시1++) {
		거리[임시1].비우다();
		s의거리[임시1] = 무한대;
		g의거리[임시1] = 무한대;
		h의거리[임시1] = 무한대;
	}
	후보지.비우다();
}

정수 중심지()
{
	ios::sync_with_stdio(false);
	입력.tie(널);
	출력.tie(널);
	입력 >> 반복횟수;
	반복 (정수 임시1 = 0; 임시1 < 반복횟수; 임시1++) {
		초기화();
		입력 >> 교차로개수 >> 도로개수 >> 목적지후보개수;
		입력 >> 예술가출발지 >> 가야하는곳1 >> 가야하는곳2;
		반복 (정수 임시2 = 0; 임시2 < 도로개수; 임시2++) {
			정수 연결노드, 상대노드, 가중치;
			입력 >> 연결노드 >> 상대노드 >> 가중치;
			거리[연결노드].뒤에넣다({ 상대노드,가중치 });
			거리[상대노드].뒤에넣다({ 연결노드,가중치 });
		}
		반복(정수 임시1 = 0; 임시1 < 목적지후보개수; 임시1++) {
			정수 목적지후보;
			입력 >> 목적지후보;
			후보지.뒤에넣다(목적지후보);
		}
		다익스트라(예술가출발지, s의거리);
		다익스트라(가야하는곳1, g의거리);
		가야하는곳1과가야하는곳2의거리 = g의거리[가야하는곳2];
		다익스트라(가야하는곳2, h의거리);
		정렬하다(후보지.앞(), 후보지.뒤());
		정수 후보지크기 = 후보지.크기();
		반복(정수 임시3 = 0; 임시3 < 후보지크기; 임시3++) {
			정수 후보목적지선정 = 후보지[임시3];
			만약(s의거리[후보목적지선정] == s의거리[가야하는곳1] + 가야하는곳1과가야하는곳2의거리 + h의거리[후보목적지선정] || s의거리[후보목적지선정] == s의거리[가야하는곳2] + 가야하는곳1과가야하는곳2의거리 + g의거리[후보목적지선정]) {
				출력 << 후보목적지선정 << 공백;
			}
			
		}
		출력 << 줄바꿈;
	}
}