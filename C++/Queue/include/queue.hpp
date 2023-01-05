
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
class Queue
{
private:
    Node<T> *front;
    Node<T> *rear;
    int count;

public:
    Queue(/* args */);
    ~Queue();
    T serve();
    T retrieve();
    void append(T data);
    int size();
};

template <typename T>
Queue<T>::Queue(/* args */)
{
    front = nullptr;
    rear = nullptr;
    count = 0;
}

template <typename T>
Queue<T>::~Queue()
{
    while (count != 0)
        serve();
}

template <typename T>
void Queue<T>::append(T data)
{
    Node<T> *new_node = new Node<T>(data, nullptr);

    if (front == nullptr)
        front = rear = new_node;
    
    else 
    {
        rear = rear->next;
        rear = new_node;
    }

    count++;
}

template <typename T>
T Queue<T>::serve()
{
    T res = front->data;
    if (count != 0)
    {
        Node<T>* old_node = front;
        front = front->next;
        delete old_node;
        count--;
    }
    return res;
}

template <typename T>
T Queue<T>::retrieve()
{
    return front->data;
}

template <typename T>
int Queue<T>::size()
{
    return count;
}