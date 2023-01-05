#include <iostream>

#include "../include/queue.hpp"

int main()
{
    Queue<int> iQueue = Queue<int>();

    for (int i = 0; i < 10; i++)
    {
        iQueue.append(i);
    }

    while (iQueue.size() != 0)
    {
        std::cout << " " << iQueue.serve();
    }
}