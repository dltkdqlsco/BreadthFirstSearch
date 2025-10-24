#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 10;
vector<int> graph[N];
bool visited[N];

void bfs(int startNode)
{
    queue<int> q;

    q.push(startNode);
    visited[startNode] = true;
    cout << "BFS 방문 순서: ";

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main()
{
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[2].push_back(4);
    graph[3].push_back(1);
    graph[3].push_back(2);
    graph[4].push_back(2);

    cout << "그래프에서 BFS 시작 (노드 1):" << endl;

    bfs(1);

    cout << endl;

    return 0;
}