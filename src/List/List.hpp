#ifndef LIST_HPP
#define LIST_HPP

#include <string>

template <typename T>
class List {
public:
    virtual ~List() {}

    virtual void add(const T& element) = 0;
    virtual void add(int index, const T& element) = 0;

    virtual T remove(int index) = 0;
    virtual bool removeElement(const T& element) = 0;

    virtual T set(int index, const T& element) = 0;
    virtual T get(int index) const = 0;

    virtual bool isEmpty() const = 0;
    virtual int size() const = 0;
    virtual std::string toString() const = 0;
};

#endif