#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int, int>> ass;
int DAY[1001];

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) //점수가 같은 경우 마감일이 빠른 과제를 우선으로
		return a.first < b.first;
	else
		return a.second > b.second; //점수가 같지 않은 경우, 점수가 큰 과제를 우선으로
}

int main() {
	int n, d, w, day;
	int ans = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> d >> w;
		ass.push_back({ d, w }); //데드라인과 과제 점수를 pair로 묶어 ass 벡터에 저장
	}
	sort(ass.begin(), ass.end());

	for (int i = 0; i < n; i++) {
		day = ass[i].first; //마지막 마감일 day에 저장

		while (day >= 1) {
			if (DAY[day] == 0) { //저장된 마감일에 과제가 없으면
				DAY[day] = ass[i].second; //점수가 큰 과제 저장
				break;
			}
			else { //그렇지 않다면
				day--; //과제가 없을 때까지 day 감소
			}
		}
	}

	for (int i = 1; i < 1000; i++) {
		ans += DAY[i]; //마감일 전까지 할 수 있는 과제 점수 합하기
	}

	cout << ans << "\n"; //결과 출력
}
