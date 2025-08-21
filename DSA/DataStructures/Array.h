#ifndef ARRAY_H
#define ARRAY_H

#include <initializer_list>
#include <stdexcept>

template <typename T, size_t Size> class Array
{
  public:
    Array()
    {
        for (size_t i = 0; i < Size; i++)
        {
            arr[i] = T();
        }
    }

    Array(std::initializer_list<T> init_list)
    {
        int i = 0;
        for (const T& elem : init_list)
        {
            if (i < Size)
            {
                arr[i] = elem;
                i++;
            }
            else
            {
                throw std::out_of_range("Initialiser list exceeds array size");
            }
        }

        for (; i < Size; i++)
        {
            arr[i] = T();
        }
    }

    ~Array()
    {
    }

    size_t size() const
    {
        return Size;
    }

    T& operator[](int index)
    {
        if (index > Size)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const Array& array)
    {
        os << "{";
        for (int i = 0; i < Size - 1; i++)
        {
            os << array.arr[i] << ", ";
        }
        os << array.arr[Size - 1] << "}";
        return os;
    }

  private:
    T arr[Size];
};

#endif
