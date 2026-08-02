class BrowserHistory {
    struct Node {
        shared_ptr<Node> prev = nullptr;
        shared_ptr<Node> next = nullptr;
        string _url;

        Node(string url) : _url(std::move(url)) {}
    };
    shared_ptr<Node> home;
    shared_ptr<Node> tail;
    shared_ptr<Node> curr;
    int depth = 0;
    int size = 0;
public:
    BrowserHistory(string homepage)
    {
        home = tail = curr = make_shared<Node>(homepage);
        depth++;
        size++;
    }
    
    void visit(string url)
    {
        auto insert = make_shared<Node>(url);
        insert->prev = curr;
        curr->next = insert;
        tail = curr = insert;
        if (size > depth)
        {
            size = depth;
        }
        depth++;
        size++;

    }
    
    string back(int steps)
    {
        if (steps >= depth)
        {
            curr = home;
            depth = 1;
            return curr->_url;
        }

        while (steps)
        {
            curr = curr->prev;
            steps--;
            depth--;
        }

        return curr->_url;
    }
    
    string forward(int steps)
    {
        if (steps >= size - depth)
        {
            curr = tail;
            depth = size;
            return curr->_url;
        }

        while (steps)
        {
            curr = curr->next;
            steps--;
            depth++;
        }

        return curr->_url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */