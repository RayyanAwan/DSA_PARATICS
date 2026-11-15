#include<iostream>
using namespace std;

class node {
    public:
        int data;
        node* next;

        node(int val) {
            data = val;
            next = nullptr;
        }
};

class list {
    private:
        node* head;

    public:
        list() {
            head = nullptr;
        }

        void insert_Data(int val) {
            node* temp = new node(val);

            if(head == nullptr) {
                head = temp;
            }
            else {
                node* current = head;
                while(current->next != nullptr) {
                    current = current->next;
                }
                current->next = temp;
            }
        }

        void display_list_all() {
            node* temp = head;
            while(temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout<<"NULL"<< endl;
        }

        void treverse_list_back() {
            node* prev = nullptr;
            node* current = head;
            node* next = nullptr;

            while(current != nullptr) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            head = prev;
        }
};

int main() {
    list l;
    l.insert_Data(5);
    l.insert_Data(14);
    l.insert_Data(10);
    cout<<" Simple Linked List: ";
    l.display_list_all();
    l.treverse_list_back();
    cout<<" Changes Linked List: ";
    l.display_list_all();

    return 0;
}
