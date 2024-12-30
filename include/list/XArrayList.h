/*
 * File:   XArrayList.h
 */

#ifndef XARRAYLIST_H
#define XARRAYLIST_H
#include "IList.h"
#include <memory.h>
#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;

template <class T>
class XArrayList : public IList<T>
{
public:
    class Iterator; // forward declaration

protected:
    T *data;                                 // dynamic array to store the list's items
    int capacity;                            // size of the dynamic array
    int count;                               // number of items stored in the array
    bool (*itemEqual)(T &lhs, T &rhs);       // function pointer: test if two items (type: T&) are equal or not
    void (*deleteUserData)(XArrayList<T> *); // function pointer: be called to remove items (if they are pointer type)

public:
    XArrayList(
        void (*deleteUserData)(XArrayList<T> *) = 0,
        bool (*itemEqual)(T &, T &) = 0,
        int capacity = 10);
    XArrayList(const XArrayList<T> &list);
    XArrayList<T> &operator=(const XArrayList<T> &list);
    ~XArrayList();

    // Inherit from IList: BEGIN
    int getCapacity();
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
    // Inherit from IList: BEGIN

    void println(string (*item2str)(T &) = 0)
    {
        cout << toString(item2str) << endl;
    }
    void setDeleteUserDataPtr(void (*deleteUserData)(XArrayList<T> *) = 0)
    {
        this->deleteUserData = deleteUserData;
    }

    Iterator begin()
    {
        return Iterator(this, 0);
    }
    Iterator end()
    {
    		if(capacity == 0) return Iterator(this, 1);
        return Iterator(this, count);
    }

    /** free:
     * if T is pointer type:
     *     pass THE address of method "free" to XArrayList<T>'s constructor:
     *     to:  remove the user's data (if needed)
     * Example:
     *  XArrayList<Point*> list(&XArrayList<Point*>::free);
     *  => Destructor will call free via function pointer "deleteUserData"
     */
    static void free(XArrayList<T> *list)
    {
        typename XArrayList<T>::Iterator it = list->begin();
        while (it != list->end())
        {
            delete *it;
            it++;
        }
    }

protected:
    void checkIndex(int index);     // check validity of index for accessing
    void ensureCapacity(int index); // auto-allocate if needed

    /** equals:
     * if T: primitive type:
     *      indexOf, contains: will use native operator ==
     *      to: compare two items of T type
     * if T: object type:
     *      indexOf, contains: will use native operator ==
     *      to: compare two items of T type
     *      Therefore, class of type T MUST override operator ==
     * if T: pointer type:
     *      indexOf, contains: will use function pointer "itemEqual"
     *      to: compare two items of T type
     *      Therefore:
     *      (1): must pass itemEqual to the constructor of XArrayList
     *      (2): must define a method for comparing
     *           the content pointed by two pointers of type T
     *          See: definition of "equals" of class Point for more detail
     */
    static bool equals(T &lhs, T &rhs, bool (*itemEqual)(T &, T &))
    {
        if (itemEqual == 0)
            return lhs == rhs;
        else
            return itemEqual(lhs, rhs);
    }

    void copyFrom(const XArrayList<T> &list);

    void removeInternalData();

    //////////////////////////////////////////////////////////////////////
    ////////////////////////  INNER CLASSES DEFNITION ////////////////////
    //////////////////////////////////////////////////////////////////////
public:
    // Iterator: BEGIN
    class Iterator
    {
    private:
        int cursor;
        XArrayList<T> *pList;

    public:
        Iterator(XArrayList<T> *pList = 0, int index = 0)
        {
            this->pList = pList;
            this->cursor = index;
        }
        Iterator &operator=(const Iterator &iterator)
        {
            cursor = iterator.cursor;
            pList = iterator.pList;
            return *this;
        }
        void remove(void (*removeItemData)(T) = 0)
        {
            T item = pList->removeAt(cursor);
            if (removeItemData != 0)
                removeItemData(item);
            cursor -= 1; // MUST keep index of previous, for ++ later
        }

        T &operator*()
        {
            return pList->data[cursor];
        }
        bool operator!=(const Iterator &iterator)
        {
            return cursor != iterator.cursor;
        }
        // Prefix ++ overload
        Iterator &operator++()
        {
            this->cursor++;
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
    // Iterator: END
};

//////////////////////////////////////////////////////////////////////
////////////////////////     METHOD DEFNITION      ///////////////////
//////////////////////////////////////////////////////////////////////

template <class T>
XArrayList<T>::XArrayList(
    void (*deleteUserData)(XArrayList<T> *),
    bool (*itemEqual)(T &, T &),
    int capacity)
{
    this->data = data;
    this->deleteUserData = deleteUserData;
    this->itemEqual = itemEqual;
    this->count = 0;
    this->capacity = capacity;
    //if(capacity == 0) this->capacity = 10;
    if(capacity == 0) this->data = new T[1];
    else this->data = new T[capacity];
}

template <class T>
void XArrayList<T>::copyFrom(const XArrayList<T> &list) //optional
{
    /*
     * Copies the contents of another XArrayList into this list.
     * Initializes the list with the same capacity as the source list and copies all elements.
     * Also duplicates user-defined comparison and deletion functions, if applicable.
     */
    
}

template <class T>
void XArrayList<T>::removeInternalData() //optional
{
    /*
     * Clears the internal data of the list by deleting the dynamic array and any user-defined data.
     * If a custom deletion function is provided, it is used to free the stored elements.
     * Finally, the dynamic array itself is deallocated from memory.
     */
    // TODO
}

template <class T>
XArrayList<T>::XArrayList(const XArrayList<T> &list)
{
    // TODO
    T *newData = new T[capacity];
    for(int i = 0; i < this->count; i++){
        newData[i] = this->data[i];
    }
    // delete[] this->data;
    this->data = newData;
    this->deleteUserData = list.deleteUserData;
    this->itemEqual = list.itemEqual;
    this->count = list.count;
    this->capacity = list.capacity;

}

template <class T>
XArrayList<T> &XArrayList<T>::operator=(const XArrayList<T> &list)
{
    // TODO
    // this->capacity = list.capacity;
    // this->count = list.count;
    // this->deleteUserData = list.deleteUserData;
    // this->itemEqual = list.itemEqual;
    // this->count = list.count;
    // delete[] this->data;
    // this->data = new T[list.count];
    // for(int i = 0; i < list.count; i++){
    //     this->data[i] = list.data[i];
    // }
    // return *this;
    if (this != &list) {
        delete[] this->data;
        this->capacity = list.capacity;
        this->count = list.count;
        this->deleteUserData = list.deleteUserData;
        this->itemEqual = list.itemEqual;
        this->data = new T[list.count];
        for(int i = 0; i < list.count; i++){
            this->data[i] = list.data[i];
        }
    }
    return *this;
}

template <class T>
XArrayList<T>::~XArrayList()
{
    // TODO
    if(deleteUserData != 0) deleteUserData(this);
    delete[] this->data;
}

template <class T>
int XArrayList<T>::getCapacity(){
    return this->capacity;
}

template <class T>
void XArrayList<T>::add(T e)
{
    // TODO
    if(count == capacity && capacity != 0) { //full stack
        T *newData = new T[capacity*2];
        for(int i = 0; i < this->count; i++){
            newData[i] = this->data[i];
        }
        delete[] this->data;
        this->data = newData;
        this->capacity *= 2;
    }
    if(this->count == 0 || capacity == 0) {
        this->data[0] = e;
    }
    else {
		this->data[this->count] = e;
	}
    this->count++;
}

template <class T>
void XArrayList<T>::add(int index, T e)
{
    // TODO
    if(index < 0 || index > this->count) throw std::out_of_range("Index is out of range!");

    if(count == capacity && capacity != 0) { //full stack
        T *newData = new T[capacity*2];
        for(int i = 0; i < this->count; i++){
            newData[i] = this->data[i];
        }
        delete[] this->data;
        this->data = newData;
        this->capacity *= 2;
    }

    if(this->count == 0 || capacity == 0) this->data[0] = e;
    else {
        for(int i = this->count; i > index; i--) this->data[i] = this->data[i-1];
        this->data[index] = e;
    }
    this->count++;
}

template <class T>
T XArrayList<T>::removeAt(int index)
{
    // TODO
    if(index >= this->count || index < 0) throw std::out_of_range("Index is out of range!");
    T item = this->data[index];
    for(int i = index; i < this->count - 1; i++) this->data[i] = this->data[i+1];
    this->data[this->count-1] = 0;
    this->count--;
    return item;
}

template <class T>
bool XArrayList<T>::removeItem(T item, void (*removeItemData)(T))
{
    // TODO
    if(this->count == 0) return false;
    int index = this->indexOf(item);
    if(index == -1) return false;
    T item2 = this->removeAt(index);
    if(removeItemData != 0) removeItemData(item2);
    return true;    
}

template <class T>
bool XArrayList<T>::empty()
{
    // TODO
    if(this->count == 0) return true;
    else return false;
}

template <class T>
int XArrayList<T>::size()
{
    // TODO
    return this->count;
}

template <class T>
void XArrayList<T>::clear()
{
    // TODO
    if(this->count == 0) return;
    // deleteUserData(this);
    delete[] this->data;
    this->count = 0;
    this->capacity = 10;
    this->data = new T[10];
}

template <class T>
T &XArrayList<T>::get(int index)
{
    // TODO
    if(this->count == 0 || (index < 0 || index >= this->count -1)) throw std::out_of_range("Index is out of range!");
    else return this->data[index];
}

template <class T>
int XArrayList<T>::indexOf(T item)
{
    // TODO
    for(int i = 0; i < this->count; i++){
        if(equals(this->data[i], item, itemEqual)) return i;
    }
    return -1;
}
template <class T>
bool XArrayList<T>::contains(T item)
{
    // TODO
    if(empty()) return false;
    for(int i = 0; i < this->count; i++){
        // if(this->data[i] == item) return true;
        if(equals(this->data[i], item, itemEqual)) return true;
    }
    return false;
}

template <class T>
string XArrayList<T>::toString(string (*item2str)(T &))
{
    /**
     * Converts the array list into a string representation, formatting each element using a user-defined function.
     * If no function is provided, it uses the default string representation for each element.
     * Example: Given an array list with elements {1, 2, 3} and a function that converts integers to strings, calling toString would return "[1, 2, 3]".
     *
     * @param item2str A function pointer for converting items of type T to strings. If null, default to the string conversion of T.
     * @return A string representation of the array list with elements separated by commas and enclosed in square brackets.
     */
    
    string output = "[";
    // TODO
    for(int i = 0; i < this->count; i++){
        if(item2str != nullptr) output += item2str(this->data[i]);
        else{
            stringstream ss;
            ss << this->data[i];
            output += ss.str();
        }
        if(i < this->count - 1) output += ", ";
    }
    output += "]";
    return output;
}

//////////////////////////////////////////////////////////////////////
//////////////////////// (private) METHOD DEFNITION //////////////////
//////////////////////////////////////////////////////////////////////
template <class T>
void XArrayList<T>::checkIndex(int index) //optional
{
    /**
     * Validates whether the given index is within the valid range of the list.
     * Throws an std::out_of_range exception if the index is negative or exceeds the number of elements.
     * Ensures safe access to the list's elements by preventing invalid index operations.
     */
    // TODO
    if(index < 0 || index < this->count) throw std::out_of_range("Index is out of range!");

}
template <class T>
void XArrayList<T>::ensureCapacity(int index) //optional
{
    /**
     * Ensures that the list has enough capacity to accommodate the given index.
     * If the index is out of range, it throws an std::out_of_range exception. If the index exceeds the current capacity,
     * reallocates the internal array with increased capacity, copying the existing elements to the new array.
     * In case of memory allocation failure, catches std::bad_alloc.
     */
    // TODO
    if(this->count < index) throw std::out_of_range("Index is out of range!");
}

#endif /* XARRAYLIST_H */
