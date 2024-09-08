class MinStack {
    struct Node{
        int value;
        int min;
        Node* next;
        Node(int value, int min){
            this->value = value;
            this->min = min;
            this->next = nullptr;
        }
    };
    Node* head;
    
public:
    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        if(head == nullptr){
            head = new Node(val, val);
        }else{
            Node* n = new Node(val, min(val, head->min));
            n->next = head;
            head = n;
        }
    }
    
    void pop() {
        if(head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    int top() {
        if(head != nullptr)
            return head->value;
        return -1;
    }
    
    int getMin() {
        if(head != nullptr)
            return head->min;
        return -1;
    }

    ~MinStack(){
        while(head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */