#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

// dp + 비트 마스크를 사용.  dp[i][j]는 현재 i의 위치에서 j상태의 노드를 방문했음을 나타낸다.
// 비트 마스크 1011은 0번, 1번, 3번 노드를 거쳤다는 뜻이다. 모든 노드를 다 방문하면 11111.. 이런식이 된다.
// 이 결과는 (1 << n) - 1로 나타낼 수 있다.(1 << n이 1하고 0이 n개 붙어있는 꼴이므로)
// 1-3-2-4-5-1이나 3-2-4-5-1-3이나 같은 한 바퀴이고, 최소 값이 같으므로 정점 하나에 대해서만 구하면 된다.
// 따라서 이 문제에서는 편하게 0번 도시에서 출발한다고 가정한다.
#define MAX 16
#define INF 1000000000

int n;
int arr[MAX][MAX];
int dp[MAX][1 << MAX]; // 2진법으로 나타내어야 하므로

int func(int now, int visited) { // 현재 정점 위치, 방문 상태를 나타내는 비트 마스크

	if (visited == (1 << n) - 1) { // 기저사례. 모든 도시를 다 방문했을 때.
		if (arr[now][0] != 0) { // now에서 0(출발 지점)으로 돌아가는 길이 존재하면 그 비용을 리턴
			return arr[now][0];
		}
		else return INF; // now에서 0으로 돌아가는 길이 없다면 INF 리턴
	}

	int& ans = dp[now][visited]; // 현재의 상태 값을 참조형식으로 변수에 넣기(now 위치까지 오기까지의 상태는 visited이다.)
	if (ans != -1)
		return ans; // 방문을 했다면 그 값 리턴
	ans = INF;
	// 다음에 방문할 모든 노드에 대해서
	for (int i = 0; i < n; i++) {
		// 이미 방문한 도시이거나(1 << i는 이진법 상 i번째에 1이 있고, 오른쪽이 모두 0으로 채워진 형태이다.
		// 1 << 3이면 1000이다. 이것은 0번째 도시가 맨 오른쪽이고 세 번째 도시를 방문했다는 뜻이므로 현재의 상태인
		// visited와 and 연산을 했을 때 1이 나온다면 i번째 도시는 방문을 했다는 의미가 된다.)
		// now에서 i로 가는 길이 없는 경우는 제외한다.
		if (visited & (1 << i) || arr[now][i] == 0)
			continue;
		// 새 도시로 갈 수 있다면 간다. 원래 저장되어 있던 now까지의 최소 경비와 "now에서 i까지 가는 경비 + i의 func함수 결과"를 비교.
		// 재귀함수를 타고 방문 도시가 주욱 이어져서 끝에 가면 위의 기저사례의 코드를 통해 끝에 다다랐을 때의 arr[now][0]값이 리턴된다.
		// 그리고 그 값은 마지막 직전 상황에서의 요 아래 코드에서 arr[now][i]와 더해져서 마지막 직전 상황에서부터 시작점 0으로 돌아가는 데
		// 드는 비용이 ans에 저장된다. 그 값은 또 그 직전 상황의 아래 코드에 리턴되어 더해지는 식으로 진행되어 결국에 0번부터 0번까지 돌아가는 데
		// 드는 최소 비용이 ans로 리턴된다.
		ans = min(ans, arr[now][i] + func(i, visited + (1 << i)));
	}
	return ans;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	memset(dp, -1, sizeof(dp)); // dp 배열을 -1로 초기화
	cout << func(0, 1) << "\n"; // 0에서 출발하는 결과(0은 현재 위치이므로 방문한 것으로 여긴다. 그래서 상태가 1).
}