#ifndef CIRCULAR_ARRAY_H

#include "DataStructures/Array.h"

template <typename T, size_t Size> class CircularArray
{
  public:
    CircularArray()
    {
        arr = new Array<T, Size>();
    }

    CircularArray(std::initializer_list<T> init_list)
    {
        arr = new Array<T, Size>(init_list);
    }

    ~CircularArray()
    {
        delete arr;
    }

    size_t size() const
    {
        return Size;
    }

    T& operator[](int index)
    {
        return arr->arr[(index % Size)];
    }

    friend std::ostream& operator<<(std::ostream& os, const CircularArray& array)
    {
        os << "{";
        for (int i = 0; i < Size - 1; i++)
        {
            os << array.arr->arr[i] << ", ";
        }
        os << array.arr->arr[Size - 1] << "}";
        return os;
    }

  private:
    Array<T, Size>* arr;
};

#endif
