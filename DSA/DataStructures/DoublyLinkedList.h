#ifndef DOUBLY_LINKED_LIST_H

#include <initializer_list>
#include <sstream>
#include <stdexcept>
#include <string>

template <typename T> struct dNode
{
    T      data;
    dNode* prev;
    dNode* next;
};

template <typename T> class DoublyLinkedList
{
  public:
    DoublyLinkedList() : head(nullptr), m_size(0)
    {
    }

    DoublyLinkedList(std::initializer_list<T> init_list) : head(nullptr), m_size(0)
    {
        for (const T& elem : init_list)
        {
            Append(elem);
        }
    }

    ~DoublyLinkedList()
    {
        delete head;
    }

    void Append(T data)
    {
        dNode<T>* temp1 = new dNode<T>();
        temp1->data     = data;
        temp1->prev     = nullptr;
        temp1->next     = nullptr;

        if (m_size == 0)
        {
            temp1->next = head;
            head        = temp1;
        }
        else
        {
            dNode<T>* temp2 = head;
            for (int i = 0; i < m_size - 1; i++)
            {
                temp2 = temp2->next;
            }
            temp2->next = temp1;
            temp1->prev = temp2;
        }

        m_size++;
    }

    void Insert(T data, int index)
    {
        dNode<T>* temp1 = new dNode<T>();
        temp1->data     = data;
        temp1->next     = nullptr;
        temp1->prev     = nullptr;

        if (index > m_size)
        {
            throw std::out_of_range("Index out of bounds");
        }

        if (index == 0)
        {
            temp1->next = head;
            head        = temp1;
        }
        else
        {
            dNode<T>* temp2 = head;
            for (int i = 0; i < index - 1; i++)
            {
                temp2 = temp2->next;
            }
            temp1->next = temp2->next;
            temp2->next = temp1;
            temp1->prev = temp2;
        }

        m_size++;
    }

    void Delete(int index)
    {
        dNode<T>* temp1 = head;

        if (index >= m_size)
        {
            throw std::out_of_range("Index out of bounds");
        }

        if (index == 0)
        {
            head              = temp1->next;
            temp1->next->prev = nullptr;
            delete temp1;
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                temp1 = temp1->next;
            }

            dNode<T>* temp2 = temp1->next;
            temp1->next     = temp2->next;
            temp2->prev     = temp1->prev;
            delete temp2;
        }

        m_size--;
    }

    size_t size() const
    {
        return m_size;
    }

    T& operator[](int index)
    {
        if (index > m_size)
        {
            throw std::out_of_range("Index out of bounds");
        }

        dNode<T>* temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& list)
    {
        os << list.getString();

        return os;
    }

  private:
    dNode<T>* head;
    int       m_size;

    std::string getString() const
    {
        std::stringstream ss;
        ss << "{";
        dNode<T>* temp = head;
        for (int i = 0; i < m_size - 1; i++)
        {
            ss << temp->data << ", ";
            temp = temp->next;
        }
        ss << temp->data;
        ss << "}";

        return ss.str();
    }
};

#endif
