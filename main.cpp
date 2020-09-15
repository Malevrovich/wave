#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define BIG_NUMBER 2147483647

struct Dot {
	Dot() {
	}

	Dot(int _x, int _y) {
		x = _x;
		y = _y;
	}

	int x;
	int y;
};

void check_and_push(vector<vector<int>> &map, queue<Dot> &stack, int value,
		int new_x, int new_y) {
	if (map[new_x][new_y] > value + 1) {
		map[new_x][new_y] = value + 1;
		stack.push(Dot(new_x, new_y));
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> map(n, vector<int>(m, BIG_NUMBER));

	Dot src;
	cin >> src.x >> src.y;
	map[src.x][src.y] = 0;

	Dot dst;
	cin >> dst.x >> dst.y;

	queue<Dot> queue;
	queue.push(src);

	while (!queue.empty()) {
		Dot cur = queue.front();
		queue.pop();

		if (map[cur.x][cur.y] >= map[dst.x][dst.y]) {
			continue;
		}

		int value = map[cur.x][cur.y];
		if (cur.x >= 2) {
			if (cur.y >= 1) {
				check_and_push(map, queue, value, cur.x - 2, cur.y - 1);
			}
			if (cur.y <= map[0].size() - 2) {
				check_and_push(map, queue, value, cur.x - 2, cur.y + 1);
			}
		}

		if (cur.x < map.size() - 2) {
			if (cur.y >= 1) {
				check_and_push(map, queue, value, cur.x + 2, cur.y - 1);
			}
			if (cur.y <= map[0].size() - 2) {
				check_and_push(map, queue, value, cur.x + 2, cur.y + 1);
			}
		}

		if (cur.y >= 2) {
			if (cur.x >= 1) {
				check_and_push(map, queue, value, cur.x - 1, cur.y - 2);
			}
			if (cur.x <= map[0].size() - 2) {
				check_and_push(map, queue, value, cur.x + 1, cur.y - 2);
			}
		}

		if (cur.y < map.size() - 2) {
			if (cur.x >= 1) {
				check_and_push(map, queue, value, cur.x - 1, cur.y + 2);
			}
			if (cur.x <= map[0].size() - 2) {
				check_and_push(map, queue, value, cur.x + 1, cur.y + 2);
			}
		}
	}

	if(map[dst.x][dst.y] == BIG_NUMBER) {
		cout << "No way" << endl;
		return 0;
	}

	vector<Dot> way;
	way.push_back(dst);

	Dot cur = dst;

	while (map[cur.x][cur.y] != 0) {
		int value = map[cur.x][cur.y];
		if (cur.x >= 2) {
			if (cur.y >= 1) {
				if (map[cur.x - 2][cur.y - 1] == value - 1) {
					cur = Dot(cur.x - 2, cur.y - 1);
					way.push_back(cur);
					continue;
				}
			}
			if (cur.y <= map[0].size() - 2) {
				if (map[cur.x - 2][cur.y + 1] == value - 1) {
					cur = Dot(cur.x - 2, cur.y + 1);
					way.push_back(cur);
					continue;
				}
			}
		}

		if (cur.x < map.size() - 2) {
			if (cur.y >= 1) {
				if (map[cur.x + 2][cur.y - 1] == value - 1) {
					cur = Dot(cur.x + 2, cur.y - 1);
					way.push_back(cur);
					continue;
				}
			}
			if (cur.y <= map[0].size() - 2) {
				if (map[cur.x + 2][cur.y + 1] == value - 1) {
					cur = Dot(cur.x + 2, cur.y + 1);
					way.push_back(cur);
					continue;
				}
			}
		}

		if (cur.y >= 2) {
			if (cur.x >= 1) {
				if (map[cur.x - 1][cur.y - 2] == value - 1) {
					cur = Dot(cur.x - 1, cur.y - 2);
					way.push_back(cur);
					continue;
				}
			}
			if (cur.x <= map[0].size() - 2) {
				if (map[cur.x + 1][cur.y - 2] == value - 1) {
					cur = Dot(cur.x + 1, cur.y - 2);
					way.push_back(cur);
					continue;
				}
			}
		}

		if (cur.y < map.size() - 2) {
			if (cur.x >= 1) {
				if (map[cur.x - 1][cur.y + 2] == value - 1) {
					cur = Dot(cur.x - 1, cur.y + 2);
					way.push_back(cur);
					continue;
				}
			}
			if (cur.x <= map[0].size() - 2) {
				if (map[cur.x + 1][cur.y + 2] == value - 1) {
					cur = Dot(cur.x + 1, cur.y + 2);
					way.push_back(cur);
					continue;
				}
			}
		}
	}

	for (auto i = way.rbegin(); i != way.rend(); i++) {
		cout << "(" << i->x << ";" << i->y << ")" << endl;
	}
	return 0;
}
