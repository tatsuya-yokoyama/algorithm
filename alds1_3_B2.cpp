#include <iostream>

using namespace std;

int S[100010];
int head = 0;
int tail = 1;

void enqueue(int i) {
  S[tail++] = i;
}

int dequeue() {
  return head++;
}

int main() {
  string name[100010];
  int t[100010];
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> name[i] >> t[i];
    enqueue(i);
  }
  int total_time = 0;
  int finished_process_count = 0;
  while(finished_process_count <= n) {
    int head_process = dequeue();
    int rest = q;
    if (t[head_process] <= rest) {
      rest -= t[head_process];
      total_time += t[head_process];
      t[head_process] = 0;
      finished_process_count++;
      cout << "[finished]" << name[head_process] << " rest:" << t[head_process] << " total_time:" << total_time << endl;
    } else {
      total_time += q;
      t[head_process] -= rest;
      cout << "" << name[head_process] << " rest:" << t[head_process] << " total_time:" << total_time << endl;
      enqueue(head_process);
    }
  }
}
