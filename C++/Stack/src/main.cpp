#include <iostream>
#include "../include/stack.hpp"

int main()
{
    Stack<int> s;

    // push
    std::cout << "Push : ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << i << " ";
        s.push(i);
    }
    std::cout << std::endl;

    // size
    std::cout << "Size : " << s.size() << std::endl;

    // top
    std::cout << "Top : " << s.top() << std::endl;

    // pop
    std::cout << "Pop : ";
    while (s.size() > 0)
        std::cout << s.pop() << " ";
    std::cout << std::endl;

    // size
    std::cout << "Size : " << s.size() << std::endl;

    return 0;
}