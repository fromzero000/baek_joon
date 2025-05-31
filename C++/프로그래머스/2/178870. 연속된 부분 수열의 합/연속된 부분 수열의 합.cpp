#include <vector>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    int start = 0, end = 0;
    int current_sum = 0;
    int min_length = n + 1;
    vector<int> answer(2, 0);

    while (end < n) {
        current_sum += sequence[end];
        while (current_sum > k && start <= end) {
            current_sum -= sequence[start];
            start++;
        }
        if (current_sum == k) {
            int current_len = end - start + 1;
            if (current_len < min_length || 
                (current_len == min_length && start < answer[0])) {
                min_length = current_len;
                answer[0] = start;
                answer[1] = end;
            }
        }
        end++;
    }
    return answer;
}