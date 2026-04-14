#include <iostream>

struct Node {
    int val;
    Node* next;
};

void solve_subtask1(int n) {
    if (n == 1) {
        return;
    }
    Node* head = new Node{1, nullptr};
    Node* curr = head;
    for (int i = 2; i <= n; ++i) {
        curr->next = new Node{i, nullptr};
        curr = curr->next;
    }
    curr->next = head;
    
    for (int i = 1; i < n; ++i) {
        curr = curr->next;
        Node* to_delete = curr->next;
        curr->next = to_delete->next;
        delete to_delete;
        std::cout << curr->next->val << "\n";
    }
    delete curr;
}

void solve_subtask2(long long n) {
    long long p = 1;
    while (p <= n) {
        p <<= 1;
    }
    p >>= 1;
    long long ans = 2 * (n - p) + 1;
    std::cout << ans << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int id;
    long long n;
    if (std::cin >> id >> n) {
        if (id == 1) {
            solve_subtask1(n);
        } else if (id == 2) {
            solve_subtask2(n);
        }
    }
    return 0;
}
