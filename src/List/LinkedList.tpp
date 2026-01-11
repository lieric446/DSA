#include "LinkedList.hpp"
#include <sstream>

template <typename T>
T LinkedList<T>::get(int index) const {
    this->checkIndex(index);
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
int LinkedList<T>::size() const {
    return currentSize;
}

template <typename T>
std::string LinkedList<T>::toString() const {
    std::stringstream ss;
    ss << "[";
    Node* current = head;
    while (current != nullptr) {
        ss << current->data;
        if (current->next != nullptr) {
            ss << ", ";
        }
        current = current->next;
    }
    ss << "]";
    return ss.str();
}

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), currentSize(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

template <typename T>
void LinkedList<T>::add(int index, const T& element) {
    this->checkAddIndex(index);
    Node* newNode = new Node(element);
    if (index == 0) {
        newNode->next = head;
        head = newNode;
        if (currentSize == 0) {
            tail = newNode;
        }
    } else if (index == currentSize) {
        tail->next = newNode;
        tail = newNode;
    } else {
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    currentSize++;
}

template <typename T>
T LinkedList<T>::remove(int index) {
    this->checkIndex(index);
    Node* toDelete;
    T removedData;
    if (index == 0) {
        toDelete = head;
        removedData = head->data;
        head = head->next;
        if (currentSize == 1) {
            tail = nullptr;
        }
    } else {
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        toDelete = current->next;
        removedData = toDelete->data;
        current->next = toDelete->next;
        if (toDelete == tail) {
            tail = current;
        }
    }
    delete toDelete;
    currentSize--;
    return removedData;
}

template <typename T>
bool LinkedList<T>::removeElement(const T& element) {
    Node* current = head;
    Node* previous = nullptr;
    int index = 0;
    while (current != nullptr) {
        if (current->data == element) {
            if (previous == nullptr) {
                head = current->next;
                if (current == tail) {
                    tail = nullptr;
                }
            } else {
                previous->next = current->next;
                if (current == tail) {
                    tail = previous;
                }
            }
            delete current;
            currentSize--;
            return true;
        }
        previous = current;
        current = current->next;
        index++;
    }
    return false;
}

template <typename T>
T LinkedList<T>::set(int index, const T& element) {
    this->checkIndex(index);
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    T oldData = current->data;
    current->data = element;
    return oldData;
}
