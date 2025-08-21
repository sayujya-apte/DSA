#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include <stdexcept>

template <typename T> class List
{
  public:
    List() : end(-1), max_size(16)
    {
        arr = new T[max_size];
    }

    List(std::initializer_list<T> init_list) : end(-1), max_size(16)
    {
        arr   = new T[max_size];
        int i = 0;
        for (const T& elem : init_list)
        {
            arr[i] = elem;
            i++;
            end++;
        }
    }

    ~List()
    {
        delete[] arr;
    }

    void Append(T x)
    {
        if (end < max_size - 1)
        {
            arr[++end] = x;
        }
        else
        {
            doubleSize();
            arr[++end] = x;
        }
    }

    void Insert(T x, int index)
    {
        if (index > end + 1)
        {
            throw std::out_of_range("Index out of bounds");
        }
        else if (index == end + 1)
        {
            Append(x);
            return;
        }
        else
        {
            T temp = arr[index];
            end++;
            for (int i = index; i < end; i++)
            {
                T temp2    = arr[i + 1];
                arr[i + 1] = temp;
                temp       = temp2;
            }
            arr[index] = x;
        }
    }

    void Delete(int index)
    {
        if (index > end)
        {
            throw std::out_of_range("Index out of bounds");
        }

        T temp = arr[index + 1];
        for (int i = index; i < end; i++)
        {
            T temp2 = arr[i + 2];
            arr[i]  = temp;
            temp    = temp2;
        }

        end--;
    }

    size_t size() const
    {
        return end + 1;
    }

    T& operator[](size_t index)
    {
        if (index > end)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const List& list)
    {
        os << "{";
        for (int i = 0; i < list.size() - 1; i++)
        {
            os << list.arr[i] << ", ";
        }
        os << list.arr[list.size() - 1] << "}";
        return os;
    }

  private:
    T*  arr;
    int max_size;
    int end;

    void doubleSize()
    {
        T* temp = new T[max_size];

        for (int i = 0; i < max_size; i++)
        {
            temp[i] = arr[i];
        }

        max_size *= 2;
        arr = new T[max_size];

        for (int i = 0; i < (max_size / 2); i++)
        {
            arr[i] = temp[i];
        }
    }
};

#endif
