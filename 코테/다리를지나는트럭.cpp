#include <string>
#include <vector>
#include <queue> // 큐

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int tot_w = 0;
    int t_front = 0;
    int t_cur = 0;

    int sec = 0;

    queue <int> q; // 큐 생성
    while (t_front != truck_weights.size()) {
        if (!q.empty() && (sec - q.front() == bridge_length)) {
            tot_w -= truck_weights[t_front];
            ++t_front;
            q.pop();
        }
        if (t_cur != truck_weights.size() && tot_w + truck_weights[t_cur] <= weight) {
            tot_w += truck_weights[t_cur];
            ++t_cur;
            q.push(sec);
        }
        ++sec;
    }
    answer = sec;
    return answer;
}

int main(void)
{
    vector<int> vecName;
    vecName.push_back(7);
    vecName.push_back(4);
    vecName.push_back(5);
    vecName.push_back(6);

    printf("%d", solution(2, 10, vecName));
}
