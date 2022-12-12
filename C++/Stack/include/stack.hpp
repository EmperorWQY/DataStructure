template <typename T>
struct Node
{
    T data;
    Node *next;
    Node(T data, Node *next);
};

template <typename T>
Node<T>::Node(T data, Node *next)
{
    this->data = data;
    this->next = next;
}

template <typename T>
class Stack
{
private:
    Node<T> *pTop;
    int count;

public:
    Stack();
    ~Stack();
    T pop();
    void push(T data);
    int size() const;
    T top() const;
};

template <typename T>
Stack<T>::Stack()
{
    pTop = nullptr;
    count = 0;
}

template <typename T>
Stack<T>::~Stack()
{
    while (pTop != nullptr)
    {
        delete pTop;
        pTop = pTop->next;
    }
    count = 0;
}

template <typename T>
void Stack<T>::push(T data)
{
    Node<T> *new_node = new Node<T>(data, pTop);
    pTop = new_node;
    count++;
}

template <typename T>
T Stack<T>::pop()
{
    if (pTop != nullptr)
    {
        Node<T> *old_node = pTop;
        T ret = old_node->data;
        pTop = pTop->next;
        delete old_node;
        count--;
        return ret;
    }
}

template <typename T>
T Stack<T>::top() const
{
    return pTop->data;
}

template <typename T>
int Stack<T>::size() const
{
    return count;
}
