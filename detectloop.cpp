/*
* A linked list is said to contain a cycle if any node is visited more 
* than once while traversing the list. 
* 
* Complete the function provided 
* in the editor below. It has one parameter: a pointer to a Node 
* object named  that points to the head of a linked list. Your 
* function must return a boolean denoting whether or not there 
* is a cycle in the list. If there is a cycle, return true; 
* otherwise, return false.
* 
* Note: If the list is empty, head will be null.
* 
* Input Format
* Our hidden code checker passes the appropriate argument to your 
* function. You are not responsible for reading any input from stdin.
* 
* Constraints
* 0 <= list-size <= 100
* 
* Output Format
* If the list contains a cycle, your function must return true. 
* If the list does not contain a cycle, it must return false. 
* The binary integer corresponding to the boolean value returned by 
* your function is printed to stdout by our hidden code checker.
* 
* Solution:
* Solution is to have two pointers iterating over the linked list, one
* moving forward at normal speed, slow = slow->next. And the second
* pointer moving forward at double the speed, fast = fast->next->next. 
* At certain point, the fast pointer will point to the same element as
* the slow pointer, when running down this linked list. If there is 
* no loop, the fast pointer will halt moving forward when it points to 
* NULL.
*/

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

/*
* Detect a cycle in a linked list. Note that the head pointer may be 
* 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

struct Node {
    int data;
    struct Node* next;
};

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    Node *slow = head;
    Node *fast = head;
    
    while (slow != NULL && fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            return true;
    }
    
    return false;
}

int main() {
    int n;
    
    cin >> n; // number of items in the linked list
    
    srand(time(NULL));
    int loopitem = rand() % n;
    cout << "loop item number=" << loopitem << endl;
    
    // create a linked list with a loop
    Node *head = NULL, *tail = NULL, *loop = NULL;
    for (int i=0; i<n; i++) {
    
        // create new node
        Node *node = new Node();
        node->data = rand();
        node->next = NULL;
        
        // if head is not defined, set the first node as head
        if (head == NULL)
            head = node;
        
        // save the random loop point element
        if (loopitem % 9 != 0 && loopitem == i+1)
            loop = node;
        
        // attach new node to tail element'
        if (tail != NULL)
            tail->next = node;
        
        // mark this node as the tail element of the list
        tail = node;
        cout << "adding node item=" << i << ", data=" << node->data << endl;
        
        // create a loop
        if (i == n-1 && loop != NULL) {
            cout << "creating loop to item="<< loopitem << ", data=" << loop->data << endl;
            node->next = loop;
        }
    }
    
    cout << has_cycle(head) << endl;
}
