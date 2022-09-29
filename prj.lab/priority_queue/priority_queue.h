#include <memory>

#ifndef PQ_PQ_H_20220923
#define PQ_PQ_H_20220923


class QueueR {
    public:
        QueueR() : 
            first(nullptr)
        {}

        ~QueueR() = default;

        void push(int value);
        void pop();
        
        int top();

        bool empty();
    private:
        struct Node {
            public:
                Node(int _value) :
                    next_ptr(nullptr),
                    value(_value)
                {}
                
            int value;
            Node* next_ptr;
        };

        Node *first;        
};


bool QueueR::empty(){
    return (first == nullptr);
};


void QueueR::push(int value){
    if (empty()) {
        first = new Node(value);
        return;
    }

    Node *newNode = new Node(value);
    Node *temp = first;

    if (newNode->value < first->value){
        std::swap(first->next_ptr, newNode);
        return;
    }

    while(temp != nullptr)  {
        if (newNode->value < temp->next_ptr->value) {
            newNode->next_ptr = temp->next_ptr;
            temp->next_ptr = newNode;
            break;
        }
        temp = temp->next_ptr;
    }
};


void QueueR::pop() {
    Node *temp = first;

    first = first->next_ptr;

    delete temp;
}

int QueueR::top() {
    return first->value;
}

#endif