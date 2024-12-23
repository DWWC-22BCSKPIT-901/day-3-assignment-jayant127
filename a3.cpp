#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(); // Dummy node to simplify logic
        ListNode* current = dummy;
        int carry = 0; // Initialize carry

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // Start with carry from previous iteration

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10; // Update carry for next iteration
            current->next = new ListNode(sum % 10); // Add node with current digit
            current = current->next; // Move to next node
        }

        return dummy->next; // Return head of the resulting list
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;

    for (int value : values) {
        if (head == nullptr) {
            head = new ListNode(value);
            current = head;
        } else {
            current->next = new ListNode(value);
            current = current->next;
        }
    }

    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Example 1
    vector<int> vals1 = {2, 4, 3};
    vector<int> vals2 = {5, 6, 4};
    ListNode* l1 = createLinkedList(vals1);
    ListNode* l2 = createLinkedList(vals2);

    cout << "Input: l1 = [2,4,3], l2 = [5,6,4]" << endl;
    ListNode* result = solution.addTwoNumbers(l1, l2);
    printLinkedList(result);

    return 0;
}
