#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <time.h>

namespace my {


template<typename T>
struct list_Node
{
    T data;
    list_Node<T>* next;
    list_Node<T>* prev;
};


template<typename T, typename RetT=T>
struct list_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
    list_iterator()
        : m_current (nullptr)
    {
    }

    list_iterator(my::list_Node<T>* ptr)
        : m_current (ptr)
    {
    }

    RetT& operator*()
    {
        return m_current->data;
    }

    list_iterator& operator++()
    {
        m_current = m_current->next;
        return *this;
    }

    list_iterator operator++(int)
    {
        list_iterator tmp(m_current);
        ++(*this);
        return tmp;
    }

    list_iterator& operator--()
    {
        m_current = m_current->prev;
        return *this;
    }

    list_iterator operator--(int)
    {
        list_iterator tmp(m_current);
        --(*this);
        return tmp;
    }

    bool operator==(const list_iterator& rhs)
    {
        return m_current==rhs.m_current;
    }

    bool operator!=(const list_iterator& rhs)
    {
        return !(*this==rhs);
    }

private:
        list_Node<T>* m_current;
};



template<class T>
class list
{

    list_Node<T>* const  sentinel = new list_Node<T>{T(), nullptr, nullptr};
    list_Node<T>* head = sentinel;
    list_Node<T>* tail = sentinel;
    size_t size;

    void swap(list& rhs)
    {
        std::swap(rhs.head, head);
        std::swap(rhs.tail, tail);
        std::swap(rhs.sentinel, sentinel);
        std::swap(rhs.size, size);
    }

    void update_sentinel()
    {
        tail->next = sentinel;
        sentinel->prev = tail;
    }

    void update_tail()
    {
        if (sentinel == tail)
        {
            tail = head;
        }
        if (sentinel == head)
        {
            head = tail;
        }
    }

public:
    typedef list_iterator<T> iterator;
    typedef list_iterator<T, const T> const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    list()
        : size(0)
    {
    }

    list(const list& rhs)
        : size(0)
    {
        for(const T& elem : rhs)
        {
            push_front(elem);
        }
        reverse();
    }

    list(list&& rhs)
    {
        rhs.swap(*this);
    }

    list& operator=(const list& rhs)
    {
        list(rhs).swap(*this);
        return *this;
    }

    list& operator=(list&& rhs)
    {
        list(std::move(rhs)).swap(*this);
        return *this;
    }

    const T& front()
    {
        return head->data;
    }

    const T& back()
    {
        return tail->data;
    }

    T pop_front()
    {
        T data = head->data;
        list_Node<T>* tmp = head->next;
        delete head;
        head = tmp;
        size--;
        update_tail();
        update_sentinel();
        return data;
    }

    T pop_back()
    {
        T data = tail->data;
        list_Node<T>* tmp = tail->prev;
        delete tail;
        tail = tmp;
        size--;
        update_tail();
        update_sentinel();
        return data;
    }

    void reverse()
    {
        if(empty()) return;

        list_Node<T> *tmp = head;

        while(head->next != sentinel)
        {
            cout << "Fucntion" << endl;
            std::swap(head->next, head->prev);
            head = head->prev;
        }
        std::swap(head->next, head->prev);
        tail = tmp;

        update_tail();
        update_sentinel();

        cout << "Fucntion" << endl;
    }

    bool empty()
    {
        return head == sentinel;
    }

    void push_front(const T& value)
    {
        list_Node<T>* tmp = new list_Node<T>{value, nullptr, sentinel};
        if (head != sentinel)
        {
            tmp->next = head;
            head->prev = tmp;
        }
        size++;
        head = tmp;
        update_tail();
        update_sentinel();
    }

    void push_front(T&& value)
    {
        list_Node<T>* tmp = new list_Node<T>{std::move(value), nullptr, sentinel};
        if (head != sentinel)
        {
            tmp->next = head;
            head->prev = tmp;
        }
        size++;
        head = tmp;
        update_tail();
        update_sentinel();
    }

    void push_back(const T& elem)
    {
        list_Node<T>* tmp = new list_Node<T>{elem, nullptr, sentinel};
        if (tail != sentinel)
        {
            list_Node<T>* tmpH = head;
            while(head->next != sentinel)
            {
                head = head->next;
            }
            head->next = tmp;
            tmp->prev = head;
            head = tmpH;
        }

        size++;
        tail = tmp;
        update_tail();
        update_sentinel();
    }
    void push_back(T&& elem)
    {
        list_Node<T>* tmp = new list_Node<T>{std::move(elem), nullptr, sentinel};
        if (tail != sentinel)
        {
            list_Node<T>* tmpH = head;
            while(head->next != sentinel)
            {
                head = head->next;
            }
            head->next = tmp;
            tmp->prev = head;
            head = tmpH;
        }

        size++;
        tail = tmp;
        update_tail();
        update_sentinel();
    }

    iterator begin()
    {
        return iterator(head);
    }

    iterator end()
    {
        return iterator(sentinel);
    }

    const_iterator begin() const
    {
        return const_iterator(head);
    }

    const_iterator end() const
    {
        return const_iterator(sentinel);
    }

    const_iterator cbegin() const
    {
        return const_iterator(head);
    }

    const_iterator cend() const
    {
        return const_iterator(sentinel);
    }

    reverse_iterator rbegin() const
    {
        return reverse_iterator(sentinel);
    }

    reverse_iterator rend() const
    {
        return reverse_iterator(head);
    }

    const_reverse_iterator crbegin() const
    {
        return const_reverse_iterator(sentinel);
    }

    const_reverse_iterator crend() const
    {
        return const_reverse_iterator(head);
    }

    ~list()
    {
        cout << __FUNCTION__ <<endl;
        while(head != sentinel)
        {
            list_Node<T>* tmp = head;

            head = head->next;
            delete tmp;
        }

        delete sentinel;
    }

};

}


#endif // LIST_H
