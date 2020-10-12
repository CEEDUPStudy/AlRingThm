// 2024 KB, 0 ms

#include <iostream>
#include <queue>

using namespace std;

int total, connection;
queue<int> q;

int arr[101][101];
bool c[101];

int bfs(int x) {
    int count = -1;
    q.push(x);
    c[x] = 1;

    while (q.size() > 0) {
        int now = q.front();

        q.pop();
        count++;

        for (int i = 1; i <= total; i++) {
            if (arr[now][i] != 0 && c[i] == 0) {
                c[i] = 1;
                q.push(i);
            }
        }
    }
    return count;
}

int main(void) {
    cin >> total >> connection;

    for (int i = 1; i <= connection; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    cout << bfs(1) << endl;
}
