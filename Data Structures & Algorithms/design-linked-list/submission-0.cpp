class MyLinkedList {
private:
    struct Node {
        shared_ptr<Node> prev = nullptr;
        shared_ptr<Node> next = nullptr;
        int val = 0;

        Node() {}
        Node(int _val) : val(_val) {}
    };

    shared_ptr<Node> head = nullptr;
    shared_ptr<Node> tail = nullptr;

    shared_ptr<Node> at(int index)
    {
        if (index < 0 || index >= size) return nullptr;
        auto lookup = head;
        int counter = 0;
        while (lookup)
        {
            if (counter == index)
            {
                return lookup;
            }
            lookup = lookup->next;
            counter++;
        }
        return nullptr;
    }

    int size = 0;
public:
    MyLinkedList() {
        
    }
    
    int get(int index) {
        auto ptr = at(index);
        return !ptr ? -1 : ptr->val;
    }
    
    void addAtHead(int val) {
        auto insert = make_shared<Node>(val);
        if (head)
        {
            head->prev = insert;
            insert->next = head;
            head = insert;
        }
        else
        {
            head = tail = insert;
        }
        size++;
    }
    
    void addAtTail(int val) {
        auto insert = make_shared<Node>(val);
        if (tail)
        {
            tail->next = insert;
            insert->prev = tail;
            tail = insert;
        }
        else
        {
            head = tail = insert;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) addAtHead(val);
        else if (index == size) addAtTail(val);
        else if (index > 0 && index < size) {
            auto ptr = at(index);
            auto insert = make_shared<Node>(val);
            insert->prev = ptr->prev;
            insert->next = ptr;
            ptr->prev->next = insert;
            ptr->prev = insert;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        auto ptr = at(index);
        if (ptr)
        {
            if (ptr->prev) ptr->prev->next = ptr->next;
            else head = ptr->next;
            if (ptr->next) ptr->next->prev = ptr->prev;
            else tail = ptr->prev;
            size--;
        }
    }
};