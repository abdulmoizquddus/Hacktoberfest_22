#include <iostream>
using std::cout;

struct Node{
    int data_;
    Node* address_;
    
    Node(int data) {
        data_ = data;
        address_ = nullptr;
    }
};


class LinkedList{
public:
    LinkedList(){
        head_ = tail_ = nullptr;
    }

    // recursive method....
    const Node* traverseFrom(const Node* node){
        
        if (node != nullptr){
            cout << node->data_ << " ";
            return traverseFrom(node = node->address_);
        }
        
        // to avoid the garbage value.... 
        return nullptr; 
    }
    
    void insert(Node* create){ 
        if (head_ == nullptr){
            head_  = tail_ = create;
        }
        tail_->address_ = create;
        tail_ = tail_->address_;
    }
    
private:
    Node *head_, *tail_;
};


int main(){
    Node* node1 = new Node(2);
    Node* node2 = new Node(4);
    Node* node3 = new Node(6);
    Node* node4 = new Node(8);
    Node* node5 = new Node(10);
    Node* node6 = new Node(12);
    
    LinkedList list;
    list.insert(node1);
    list.insert(node2);
    list.insert(node3);
    list.insert(node4);
    list.insert(node5);
    list.insert(node6);
    
    cout << list.traverseFrom(node3);
    
return 0;
}




