class Node {
public:
    Node* nextNode;
    int value, minNumber;

    Node() {
        minNumber = INT_MAX;
    }

    Node(int val, Node* next) {
        value = val;
        nextNode = next;
    }
};

class MinStack {
    Node* headNode;
public:
    MinStack() {
        headNode = new Node();
    }
    
    void push(int val) {
        Node* node = new Node(val, headNode->nextNode);
        node->minNumber = headNode->minNumber;
        headNode->nextNode = node;
        headNode->minNumber = min(val, headNode->minNumber);
    }
    
    void pop() {
        Node* currentNode = headNode->nextNode;
        if(currentNode->value == headNode->minNumber){
            headNode->minNumber = currentNode->minNumber;
        }
        headNode->nextNode = currentNode->nextNode;
        delete currentNode;
    }
    
    int top() {
        return headNode->nextNode->value;
    }
    
    int getMin() {
        return headNode->minNumber;
    }
};