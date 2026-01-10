#include "ArrayList.hpp"

template <typename T>
ArrayList<T>::ArrayList(int initialCapacity) : capacity(initialCapacity), currentSize(0) {
    data = new T[capacity];
}

template <typename T>
ArrayList<T>::~ArrayList() {
    delete[] data;
}

template <typename T>
void ArrayList<T>::increaseCapacity() {
    int newCapacity = capacity * 2;
    T* newData = new T[newCapacity];
    for (int i = 0; i < currentSize; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template <typename T>
void ArrayList<T>::add(int index, const T& element) {
    this->checkAddIndex(index);
    if (currentSize == capacity) {
        increaseCapacity();
    }
    for (int i = currentSize; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = element;
    currentSize++;
}

template <typename T>
T ArrayList<T>::remove(int index) {
    this->checkIndex(index);
    T removedElement = data[index];
    for (int i = index; i < currentSize - 1; i++) {    
        data[i] = data[i + 1];
    }
    currentSize--;
    return removedElement;
}

template <typename T>
T ArrayList<T>::set(int index, const T& element) {
    this->checkIndex(index);
    T oldElement = data[index];
    data[index] = element;
    return oldElement;
}

template <typename T>
T ArrayList<T>::get(int index) const {
    this->checkIndex(index);
    return data[index];
}

template <typename T>
int ArrayList<T>::size() const {
    return currentSize;
}

template <typename T>
std::string ArrayList<T>::toString() const {
    std::string result = "[";
    for (int i = 0; i < currentSize; i++) {
        result += std::to_string(data[i]);
        if (i < currentSize - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}
