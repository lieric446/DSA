#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "AbstractList.hpp"

template <typename T>
class LinkedList : public AbstractList<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int currentSize;

public:
    using AbstractList<T>::add;
    LinkedList();
    ~LinkedList();
    
    void add(int index, const T& element) override;
    T remove(int index) override;
    bool removeElement(const T& element) override;
    T set(int index, const T& element) override;
    T get(int index) const override;
    int size() const override;
    std::string toString() const override;
};

#include "LinkedList.tpp"

#endif