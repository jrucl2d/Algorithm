#include <iostream>
#include <string>
#include <vector>
using namespace std;
//bool containsNode(string word) {
//	TrieNode* current = root;
//	for (int i = 0; i < word.length(); i++) {
//		int wordIndex = word[i] - 'A';
//		if (current->children[wordIndex] != NULL) {
//			current = current->children[wordIndex];
//		}
//		else {
//			return false;
//		}
//	}
//	return current->isEnd;
//}

class TrieNode {
public:
	TrieNode* children[26];
	bool isEnd;
	bool isHit;

	TrieNode() { 
		isEnd = false;
		isHit = false;
		for (int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
	}
	void clearHit() {
		isHit = false;
		for (int i = 0; i < 26; i++) {
			if (children[i] != NULL) {
				children[i]->clearHit();
			}
		}
	}
};

TrieNode* root = new TrieNode();
int w, b;
vector<string> board;

void insert(string word) {
	TrieNode* current = root;
	for (int i = 0; i < word.length(); i++) {
		int wordIndex = word[i] - 'A';
		if (current->children[wordIndex] == NULL) {
			current->children[wordIndex] = new TrieNode();
		}
		current = current->children[wordIndex];
	}
	current->isEnd = true;
}


bool visited[4][4];
int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int maxScore = 0;
string longestWord = "";
string nowWord = ""; // string + 연산은 굉장히 느리므로 vector을 쓰는게 맞다. 
int foundCnt = 0;

void search(int x, int y, int length, TrieNode* node) {
	// 체크인
	visited[x][y] = true;
	nowWord += board[x][y];
	// 목적지 도달?
	if (node->isEnd && node->isHit == false) {
		node->isHit = true;
		foundCnt += 1;
		if (longestWord.length() < nowWord.length()) {
			longestWord = nowWord;
		}
		else if (longestWord.length() == nowWord.length()) {
			if (longestWord.compare(nowWord) > 0) {
				longestWord = nowWord;
			}
		}
		switch (nowWord.length()) {
		case 3:
		case 4:
			maxScore += 1;
			break;
		case 5:
			maxScore += 2;
			break;
		case 6:
			maxScore += 3;
			break;
		case 7:
			maxScore += 5;
			break;
		case 8:
			maxScore += 11;
			break;
		}
	}

	// 연결된 곳 가능하면 이동
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
			// 다음 문자를 가지는 노드면 이동
			if (!visited[nx][ny] && node->children[board[nx][ny] - 'A'] != NULL) {
				search(nx, ny, length + 1, node->children[board[nx][ny] - 'A']);
			}
		}
	}
	// 체크아웃
	visited[x][y] = false;
	nowWord = nowWord.substr(0, nowWord.length() - 1);
}

int main() {
	cin >> w;
	for (int i = 0; i < w; i++) {
		string tmp;
		cin >> tmp;
		insert(tmp);
	}
	cin >> b;
	for (int i = 0; i < b; i++) {

		for (int j = 0; j < 4; j++) {
			string tmp;
			cin >> tmp;
			board.push_back(tmp);
		}

		for (int k = 0; k < 4; k++) {
			for (int w = 0; w < 4; w++)
				visited[k][w] = false;
		}

		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				if (root->children[board[x][y] - 'A'] != NULL) {
					search(x, y, 1, root->children[board[x][y] - 'A']);
				}
			}
		}
		cout << maxScore << " " << longestWord << " " << foundCnt << "\n";
		// 정보 초기화
		maxScore = 0;
		longestWord = "";
		foundCnt = 0;
		while (!board.empty()) {
			board.pop_back();
		}
		root->clearHit();
	}
	return 0;
}