#ifndef ABSTRACT_LIST_HPP
#define ABSTRACT_LIST_HPP

#include "List.hpp"
#include <stdexcept>

template <typename T>
class AbstractList : public List<T> {
protected:
    void checkIndex(int index) const {
        if (index < 0 || index >= this->size()) {
            throw std::out_of_range("Index out of bounds");
        }
    }

    void checkAddIndex(int index) const {
        if (index < 0 || index > this->size()) {
            throw std::out_of_range("Index out of bounds for adding an element");
        }
    }

public:
    void addFirst(const T& element) override {
        this->add(0, element);
    }

    void addLast(const T& element) override {
        this->add(this->size(), element);
    }

    T removeFirst() override {
        return this->remove(0);
    }

    T removeLast() override {
        return this->remove(this->size() - 1);
    }

    T getFirst() const override {
        return this->get(0);
    }

    T getLast() const override {
        return this->get(this->size() - 1);
    }

    bool isEmpty() const override {
        return this->size() == 0;
    }
};

#endif