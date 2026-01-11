#ifndef ABSTRACT_LIST_HPP
#define ABSTRACT_LIST_HPP

#include <stdexcept>

#include "List.hpp"

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
    using List<T>::add;
    void add(const T& element) override {
        this->add(this->size(), element);
    }

    bool isEmpty() const override {
        return this->size() == 0;
    }
};

#endif