#ifndef LINKED_LIST_H

#include <string>
#include <sstream>
#include <stdexcept>

template <typename T>
struct Node
{
    T data;
    Node* next;
};

template <typename T>
class LinkedList
{
public:
    LinkedList() : head(nullptr), m_size(0)
    {
    }

    LinkedList(std::initializer_list<T> init_list) : head(nullptr), m_size(0)
    {
        for (const T& elem : init_list)
        {
            Append(elem);
        }
    }

    ~LinkedList()
    {
        delete head;
    }

    void Append(T data)
    {
        Node<T>* temp1 = new Node<T>();
        temp1->data = data;
        temp1->next = nullptr;

        if (m_size == 0)
        {
            temp1->next = head;
            head = temp1;
        }
        else
        {
            Node<T>* temp2 = head;
            for (int i = 0; i < m_size - 1; i++)
            {
                temp2 = temp2->next;
            }
            temp1->next = temp2->next;
            temp2->next = temp1;
        }

        m_size++;
    }

    void Insert(T data, int index)
    {
        Node<T>* temp1 = new Node<T>();
        temp1->data = data;
        temp1->next = nullptr;

        if (index > m_size)
        {
            throw std::out_of_range("Index out of bounds");
        }

        if (index == 0)
        {
            temp1->next = head;
            head = temp1;
        }
        else
        {
            Node<T>* temp2 = head;
            for (int i = 0; i < index - 1; i++)
            {
                temp2 = temp2->next;
            }
            temp1->next = temp2->next;
            temp2->next = temp1;
        }

        m_size++;
    }

    void Delete(int index)
    {
        Node<T>* temp1 = head;

        if (index >= m_size)
        {
            throw std::out_of_range("Index out of bounds");
        }

        if (index == 0)
        {
            head = temp1->next;
            delete temp1;
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                temp1 = temp1->next;
            }

            Node<T>* temp2 = temp1->next;
            temp1->next = temp2->next;
            delete temp2;
        }

        m_size--;
    }

    size_t size() const
    {
        return size;
    }

    T& operator[](int index)
    {
        if (index > m_size)
        {
            throw std::out_of_range("Index out of bounds");
        }

        Node<T>* temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list)
    {
        os << list.getString();

        return os;
    }

private:
    Node<T>* head;
    int m_size;

    std::string getString() const
    {
        std::stringstream ss;
        ss << "{";
        Node<T>* temp = head;
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
