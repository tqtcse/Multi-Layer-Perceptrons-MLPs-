/*
 * File:   DLinkedList.h
 */

#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include "IList.h"

#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;

template <class T>
class DLinkedList : public IList<T>
{
public:
    class Node;        // Forward declaration
    class Iterator;    // Forward declaration
    class BWDIterator; // Forward declaration

protected:
    Node *head; // this node does not contain user's data
    Node *tail; // this node does not contain user's data
    int count;
    bool (*itemEqual)(T &lhs, T &rhs);        // function pointer: test if two items (type: T&) are equal or not
    void (*deleteUserData)(DLinkedList<T> *); // function pointer: be called to remove items (if they are pointer type)

public:
    DLinkedList(
        void (*deleteUserData)(DLinkedList<T> *) = 0,
        bool (*itemEqual)(T &, T &) = 0);
    DLinkedList(const DLinkedList<T> &list);
    DLinkedList<T> &operator=(const DLinkedList<T> &list);
    ~DLinkedList();

    // Inherit from IList: BEGIN
    void add(T e);
    void add(int index, T e);
    T removeAt(int index);
    bool removeItem(T item, void (*removeItemData)(T) = 0);
    bool empty();
    int size();
    void clear();
    T &get(int index);
    int indexOf(T item);
    bool contains(T item);
    string toString(string (*item2str)(T &) = 0);
    // Inherit from IList: END

    void println(string (*item2str)(T &) = 0)
    {
        cout << toString(item2str) << endl;
    }
    void setDeleteUserDataPtr(void (*deleteUserData)(DLinkedList<T> *) = 0)
    {
        this->deleteUserData = deleteUserData;
    }

    bool contains(T array[], int size)
    {
        int idx = 0;
        for (DLinkedList<T>::Iterator it = begin(); it != end(); it++)
        {
            if (!equals(*it, array[idx++], this->itemEqual))
                return false;
        }
        return true;
    }

    /*
     * free(DLinkedList<T> *list):
     *  + to remove user's data (type T, must be a pointer type, e.g.: int*, Point*)
     *  + if users want a DLinkedList removing their data,
     *      he/she must pass "free" to constructor of DLinkedList
     *      Example:
     *      DLinkedList<T> list(&DLinkedList<T>::free);
     */
    static void free(DLinkedList<T> *list)
    {
        typename DLinkedList<T>::Iterator it = list->begin();
        while (it != list->end())
        {
            delete *it;
            it++;
        }
    }

    /* begin, end and Iterator helps user to traverse a list forwardly
     * Example: assume "list" is object of DLinkedList

     DLinkedList<char>::Iterator it;
     for(it = list.begin(); it != list.end(); it++){
            char item = *it;
            std::cout << item; //print the item
     }
     */
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }

    /* last, beforeFirst and BWDIterator helps user to traverse a list backwardly
     * Example: assume "list" is object of DLinkedList

     DLinkedList<char>::BWDIterator it;
     for(it = list.last(); it != list.beforeFirst(); it--){
            char item = *it;
            std::cout << item; //print the item
     }
     */


    BWDIterator bbegin()
    {
        return BWDIterator(this, true);
    }
    BWDIterator bend()
    {
        return BWDIterator(this, false);
    }

protected:
    static bool equals(T &lhs, T &rhs, bool (*itemEqual)(T &, T &))
    {
        if (itemEqual == 0)
            return lhs == rhs;
        else
            return itemEqual(lhs, rhs);
    }
    void copyFrom(const DLinkedList<T> &list);
    void removeInternalData();
    Node *getPreviousNodeOf(int index);

    //////////////////////////////////////////////////////////////////////
    ////////////////////////  INNER CLASSES DEFNITION ////////////////////
    //////////////////////////////////////////////////////////////////////
public:
    class Node
    {
    public:
        T data;
        Node *next;
        Node *prev;
        friend class DLinkedList<T>;

    public:
        Node(Node *next = 0, Node *prev = 0)
        {
            this->next = next;
            this->prev = prev;
        }
        Node(T data, Node *next = 0, Node *prev = 0)
        {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
    };

    //////////////////////////////////////////////////////////////////////
    class Iterator
    {
    private:
        DLinkedList<T> *pList;
        Node *pNode;

    public:
        Iterator(DLinkedList<T> *pList = 0, bool begin = true)
        {
            if (begin)
            {
                if (pList != 0)
                {
                    this->pNode = pList->head;
                }
                else
                    pNode = 0;
            }
            else
            {
                if (pList != 0){
                    if(pList->tail == nullptr) this->pNode = pList->tail;
                    else this->pNode = pList->tail->next;
                    // else this->pNode = pList->tail->prev;
                }
                else
                    pNode = 0;
            }
            this->pList = pList;
        }

        Iterator &operator=(const Iterator &iterator)
        {
            this->pNode = iterator.pNode;
            this->pList = iterator.pList;
            return *this;
        }
        void remove(void (*removeItemData)(T) = 0)
        {
            cout << "ASdas"<< endl;
            if(pNode == nullptr) return;
            if(pNode->prev != nullptr) pNode->prev->next = pNode->next;
            else pList->head = pNode->next;
            if(pNode->next != nullptr) pNode->next->prev = pNode->prev;
            else pList->tail = pNode->prev;
            if (removeItemData != 0)
                removeItemData(pNode->data);
            Node *pNext = pNode->prev; // MUST prev, so iterator++ will go to end
            delete pNode;
            pNode = pNext;
            pList->count -= 1;
        }

        T &operator*()
        {
            return pNode->data;
        }
        bool operator!=(const Iterator &iterator)
        {
            return pNode != iterator.pNode;
        }
        // Prefix ++ overload
        Iterator &operator++()
        {
            if(pNode != nullptr) pNode = pNode->next;
            else pNode = pList->head;
            return *this;
        }
        // Postfix ++ overload
        Iterator operator++(int)
        {
            Iterator iterator = *this;
            ++*this;
            return iterator;
        }

        
    };

    class BWDIterator {
    private:
        typename DLinkedList<T>::Node* currentNode;
        DLinkedList<T>* pList;
    public:
        BWDIterator(DLinkedList<T>* pList, bool begin) {
            this->pList = pList;
            if (begin) {
                currentNode = pList->head;
                for(int i = 0; i < pList->size()-1; i++){
                    currentNode = currentNode->next;
                }
                // currentNode = pList->tail; 
                // cout << currentNode->data << endl;
                // cout << "Dang tro toi " << currentNode->data << endl;
            } else {
                // currentNode = pList->head; 
                currentNode = nullptr; 
                // cout << "Dang tro toi " << currentNode->data << endl;
            }
        }

        BWDIterator& operator=(const BWDIterator& iterator) {
            currentNode = iterator.currentNode;
            pList = iterator.pList;
            return *this;
        }

        T& operator*() {
            return currentNode->data;
        }

        bool operator!=(const BWDIterator& iterator) {
            return currentNode != iterator.currentNode;
        }

        BWDIterator& operator--() {
            if (currentNode != nullptr) {
                currentNode = currentNode->prev;
                // cout << "Dang tro toi " << this->currentNode->data << endl;
            }else{
                // cout << "CurrentNode null" << endl;
            }
            return *this;
        }

        BWDIterator operator--(int) {
            BWDIterator temp = *this;
            // --(*this);
            return temp;
        }

        void remove(void (*removeItemData)(T) = 0) {
            // currentNode->prev->next = currentNode->next;
            // currentNode->next->prev = currentNode->prev;
            // Node* pNext = currentNode->prev; 
            // if (removeItemData != 0) {
            //     removeItemData(currentNode->data);
            // }
            // delete currentNode;
            // currentNode = pNext;
            // pList->count -= 1;
            if(currentNode == nullptr) return;
            // cout << "Remove: " << currentNode->data << endl;
            if(currentNode->prev != nullptr) currentNode->prev->next = currentNode->next;
            else pList->head = currentNode->next;
            if(currentNode->next != nullptr) currentNode->next->prev = currentNode->prev;
            else pList->tail = currentNode->prev;
            Node *pPrev = currentNode->prev; // MUST prev, so iterator++ will go to end
            if (removeItemData != 0)
                removeItemData(currentNode->data);
            delete currentNode;
            currentNode = pPrev;
            pList->count -= 1;
            // cout << "Sau remove tro toi " << currentNode->data << endl;
        }

    };


};
//////////////////////////////////////////////////////////////////////
// Define a shorter name for DLinkedList:

template <class T>
using List = DLinkedList<T>;

//////////////////////////////////////////////////////////////////////
////////////////////////     METHOD DEFNITION      ///////////////////
//////////////////////////////////////////////////////////////////////

template <class T>
DLinkedList<T>::DLinkedList(
    void (*deleteUserData)(DLinkedList<T> *),
    bool (*itemEqual)(T &, T &))
{
    // TODO
    this->head = nullptr;
    this->tail = nullptr;
    this->count = 0;
    this->deleteUserData = deleteUserData;
    this->itemEqual = itemEqual;
}

template <class T>
DLinkedList<T>::DLinkedList(const DLinkedList<T> &list)
{
    // TODO
    this->head = nullptr;
    this->tail = nullptr;
    this->count = 0;

    Node* current = list.head;
    while (current != nullptr) {
        this->add(current->data);  
        current = current->next;
    }

}

template <class T>
DLinkedList<T> &DLinkedList<T>::operator=(const DLinkedList<T> &list)
{
    // TODO
    if (this != &list) {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        head = nullptr;
        tail = nullptr;
        Node* current = list.head;
        while (current) {
            add(current->data);
            current = current->next;
        }
    }
    return *this;
}

template <class T>
DLinkedList<T>::~DLinkedList()
{
    // TODO
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void DLinkedList<T>::add(T e)
{
    // TODO
    // Node* newNode = new Node(e);
    // if(this->count == 0) {
    //     this->head = newNode;
    //     this->tail = newNode;
    // }else{
    //     this->tail->next = newNode;
    //     newNode->prev = this->tail;
    //     this->tail = newNode;
    // }
    // this->count++;

    Node* newNode = new Node(e);
    if(head == nullptr) {
        head = newNode;
    }else{
        Node* current = head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    this->count++;
}
template <class T>
void DLinkedList<T>::add(int index, T e)
{
    // TODO
    if(index < 0 || index > this->count) throw std::out_of_range("Index is out of range!");
    Node *newNode = new Node(e);
    if(this->count == 0) {
        this->head = newNode;
        this->tail = newNode;
    }else if (index == 0) {
        newNode->next = this->head;
        this->head->prev = newNode;
        this->head = newNode;
    }else if (index == this->count) {
        // newNode->prev = this->tail;
        // this->tail->next = newNode;
        // this->tail = newNode;
        add(e);
        return;
    }else{
        Node* current = this->head;
        for(int i = 0; i < index; i++){
            current = current->next;
        }
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }
    this->count++;
}

template <class T>
typename DLinkedList<T>::Node *DLinkedList<T>::getPreviousNodeOf(int index)
{
    /**
     * Returns the node preceding the specified index in the doubly linked list.
     * If the index is in the first half of the list, it traverses from the head; otherwise, it traverses from the tail.
     * Efficiently navigates to the node by choosing the shorter path based on the index's position.
     */
    // TODO
    if(index < 0 || index >= this->count) throw std::out_of_range("Index is out of range!");
    if(index < this->count / 2) {
        Node* current = this->head;
        for(int i = 0; i < index; i++){
            current = current->next;
        }
        return current;
    }else{
        Node* current = this->tail;
        for(int i = this->count - 1; i > index; i--){
            current = current->prev;
        }
        return current;
    }

}

// template <class T>
// T DLinkedList<T>::removeAt(int index)
// {
//     // TODO
//     if(index < 0 || index >= this->count) throw std::out_of_range("Index is out of range!");
//     T current = this->head->data;
//     if(index == 0) {
//         this->head = this->head->next;
//         if(this->head != nullptr) this->head->prev = nullptr;
//         else this->tail = nullptr;
//         this->count--;
//     }else{
//         Node* current = this->head;
//         for(int i = 0; i < index; i++){
//             current = current->next;
//         }
//         if(index == this->count - 1) this->tail = current;
//         else {
//             current->prev->next = current->next;
//             if(current->next != nullptr) current->next->prev = current->prev;
//         }
//         current->next = nullptr;
//         current->prev = nullptr;
//         this->count--;
//     }
//     delete current;
//     return retValue;
// }

template <class T>
T DLinkedList<T>::removeAt(int index)
{
    if (index < 0 || index >= this->count) throw std::out_of_range("Index is out of range!");
    
    Node* current = this->head;
    for (int i = 0; i < index; i++) current = current->next;
    
    T retValue = current->data;

    if (index == 0) { 
        this->head = this->head->next;
        if (this->head != nullptr) this->head->prev = nullptr;
        else this->tail = nullptr; 
    } else if (index == this->count - 1) { 
        this->tail = current->prev;
        if (this->tail != nullptr) this->tail->next = nullptr;
        else this->head = nullptr; 
    } else { 
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
    this->count--;

    return retValue;
}

template <class T>
bool DLinkedList<T>::empty()
{
    // TODO
    if(this->count == 0) return true;
    else return false;
}

template <class T>
int DLinkedList<T>::size()
{
    // TODO
    return this->count;
}

template <class T>
void DLinkedList<T>::clear()
{
    // TODO
    if(this->count == 0) return;
    while(this->count != 0){
        this->removeAt(0);
    }
}

template <class T>
T &DLinkedList<T>::get(int index)
{
    // TODO
    Node* current = this->head;
    if(index < 0 || index >= this->count) throw std::out_of_range("Index is out of range!");
    for(int i = 0; i < index; i++){
        current = current->next;
    }
    return current->data;
}

template <class T>
int DLinkedList<T>::indexOf(T item)
{
    // TODO
    if(this->count == 0) return -1;
    Node *current = this->head;
    for(int i = 0; current != tail; i++){
        // cout << "in loop" << endl;
        // stringstream ss1, ss2;
        // ss1 << current->data;
        // ss2 << item;
        // if(ss1.str() == ss2.str()) return i;
        if(equals(current->data, item, itemEqual)) return i;
        current = current->next;
    }
    return -1;
}

template <class T>
bool DLinkedList<T>::removeItem(T item, void (*removeItemData)(T))
{
    // TODO
    // T current = this->head->data;
    if(this->count == 0) return false;
    // if(this->itemEqual(current, item)) {
    int index = this->indexOf(item);
    if(index == -1) return false;
    // if(equals(current, item, itemEqual)){
    //     this->removeAt(0);
    //     if(removeItemData != 0) removeItemData(item);
    //     return true;
    // }
    T item2 = this->removeAt(index);
    if(removeItemData != 0) removeItemData(item2);
    return true;
}

template <class T>
bool DLinkedList<T>::contains(T item)
{
    // TODO
    if(this->count == 0) return false;
    // T current = this->head->data;
    Node* current = this->head;
    for(int i = 0; i < this->count; i++){
        if(equals(current->data, item, itemEqual)) return true;
        current = current->next;
    }
    return false;
}

template <class T>
string DLinkedList<T>::toString(string (*item2str)(T &))
{
    /**
     * Converts the list into a string representation, where each element is formatted using a user-provided function.
     * If no custom function is provided, it directly uses the element's default string representation.
     * Example: If the list contains {1, 2, 3} and the provided function formats integers, calling toString would return "[1, 2, 3]".
     *
     * @param item2str A function that converts an item of type T to a string. If null, default to string conversion of T.
     * @return A string representation of the list with elements separated by commas and enclosed in square brackets.
     */
    // TODO

    string output = "[";
    Node* current = this->head;
    for(size_t i = 0; i < this->count; i++){
        if(item2str != nullptr) output += item2str(current->data);
        else{
            stringstream ss;
            ss << current->data;
            output += ss.str();
        }
        if(i < this->count - 1) output += ", ";
        current = current->next;
    }
    output += "]";
    return output;
}

template <class T>
void DLinkedList<T>::copyFrom(const DLinkedList<T> &list)
{
    /**
     * Copies the contents of another doubly linked list into this list.
     * Initializes the current list to an empty state and then duplicates all data and pointers from the source list.
     * Iterates through the source list and adds each element, preserving the order of the nodes.
     */
    // TODO
}

template <class T>
void DLinkedList<T>::removeInternalData()
{
    /**
     * Clears the internal data of the list by deleting all nodes and user-defined data.
     * If a custom deletion function is provided, it is used to free the user's data stored in the nodes.
     * Traverses and deletes each node between the head and tail to release memory.
     */
    // TODO
}

#endif /* DLINKEDLIST_H */
