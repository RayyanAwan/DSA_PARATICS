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
        void insert(int val) {
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
        void delete_first() {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    void sum_all(){
        int total = 0 ;
        node* temp = head;
        while(temp != nullptr){
            total =total+ temp->data;
            temp = temp->next;
        }
        cout<<" Sum of the node values : "<<total<<endl;
    }
    void key_data(int key){
        node* temp= head;
        bool found = false;
        while(temp != nullptr){
            if(temp->data == key ){
                cout<<"key found : "<<temp->data<<endl;
                found = true;
            }
            temp = temp->next;
        }
        if(found == false){
        cout<<"key not found "<<endl;
            
        }
    }

     void lastnode(){
         node* current = head;
         node* current2 = head->next;
        while(current2->next != nullptr){
              current = current->next;
              current2 = current2->next;
          }
         current->next = nullptr;
         delete current2;
     }
        void display() {
            node* temp = head;

            while(temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
};

int main() {
    list l;
    l.insert(20);
    l.insert(30);
    l.insert(40);
    l.insert(50);
    l.insert(60);
    l.display();
    cout<<endl;
        l.sum_all();
    l.delete_first();
    l.display();
    cout<<endl;
    l.key_data(30);
    l.lastnode();
    cout<<"after delete 1node & last node "<<endl;
    l.display();

    return 0;
}
