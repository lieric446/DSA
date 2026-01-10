#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP


#include "AbstractList.hpp"

template <typename T>
class ArrayList : public AbstractList<T> {
private:
    T* data;
    int capacity;
    int currentSize;
    void increaseCapacity();

public:
    ArrayList(int initialCapacity = 10);
    ~ArrayList();
    void add(int index, const T& element) override;
    T remove(int index) override;
    T set(int index, const T& element) override;
    T get(int index) const override;
    int size() const override;
    std::string toString() const override;
};

#include "ArrayList.tpp"

#endif