class BrowserHistory {
    public:
    struct Node {
        string data;
        Node* next;
        Node* prev;
        
        Node(string val) {
            data = val;
            next = NULL;
            prev = NULL;
        }
    };
    
    Node* current = NULL;
    	    
    BrowserHistory(string homepage) {
        Node* nn = new Node(homepage);
        current = nn;
    }
    
    void visit(string url) {
        Node* nn = new Node(url);
		current->next = nn;
		nn->prev = current;
		nn->next = nullptr;
        current = nn;
    }
    
    string back(int steps) {
        while (steps > 0 && current->prev != nullptr) {
            current = current->prev;
            steps--;
        }
        return current->data;
    }
    
    string forward(int steps) {
        while (steps > 0 && current->next != nullptr) {
            current = current->next;
            steps--;
        }
        return current->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */