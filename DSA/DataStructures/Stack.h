#ifndef STACK_H

#include "DataStructures/LinkedList.h"

template <typename T> class Stack
{
  public:
    Stack()
    {
    }

    ~Stack()
    {
    }

    void Push(T data)
    {
        list.Insert(data, 0);
    }

    T Pop()
    {
        T data = list[0];
        list.Delete(0);
        return data;
    }

  private:
    LinkedList<T> list;
};

#endif
