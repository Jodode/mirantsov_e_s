#include <memory>

#ifndef PQ_PQ_H_20220923
#define PQ_PQ_H_20220923


class QueueR {
    public:
        QueueR() : 
            first(nullptr),
            last(nullptr)
        {}

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

        Node *first, *last;        
};

bool QueueR::empty(){
    return (first == nullptr);
}



#endif