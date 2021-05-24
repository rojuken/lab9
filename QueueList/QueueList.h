#ifndef _QUEUELIST_
#define _QUEEULIST_

#include <iostream>
#include<fstream>
#include "List.h"

using namespace std;

template <class T>
class TQueueList
{
protected:
    TList<T> list;
public:
    TQueueList();
    TQueueList(TQueueList<T>& _v);
    ~TQueueList();

    TQueueList<T>& operator =(TQueueList<T>& _v);

    void Push(T d);
    T Get();

    bool IsEmpty() const;
    bool IsFull() const;

    int MinElem();
    int MaxElem();
    void LoadToFile();

    template <class T1>
    friend ostream& operator<< (ostream& ostr, const TQueueList<T1>& A);
    template <class T1>
    friend istream& operator >> (istream& istr, TQueueList<T1>& A);

    int Length();
};

template<class T1>
inline ostream& operator<<(ostream& ostr, const TQueueList<T1>& A)
{
    return ostr << A.list;
}

template<class T1>
inline istream& operator>>(istream& istr, TQueueList<T1>& A)
{
    return istr >> A.list;
}

template<class T>
inline TQueueList<T>::TQueueList()
{
}

template<class T>
inline TQueueList<T>::TQueueList(TQueueList<T>& _v)
{
    list = _v.list;
}

template<class T>
inline TQueueList<T>::~TQueueList()
{
}

template<class T>
inline TQueueList<T>& TQueueList<T>::operator=(TQueueList<T>& _v)
{
    if (this == &_v)
        return *this;

    list = _v.list;
    return *this;
}

template<class T>
inline void TQueueList<T>::Push(T d)
{
    list.InsLast(d);
}

template<class T>
inline T TQueueList<T>::Get()
{
    if (list.IsEmpty())
        throw new exception;

    T tmp = list.GetFirst()->GetData();
    list.DelFirst();

    return tmp;
}

template<class T>
inline bool TQueueList<T>::IsEmpty() const
{
    return list.IsEmpty();
}

template<class T>
inline bool TQueueList<T>::IsFull() const
{
    return list.IsFull();
}

template<class T>
inline int TQueueList<T>::MinElem()
{
    int min = this->list.GetFirst()->GetData();
    int j = this->Length();
    for (int i = 0; i < j; i++)
    {
        int k = this->Get();
        if (k < min)
            min = k;
    }
    return min;
}

template<class T>
inline int TQueueList<T>::MaxElem()
{
    int max = this->list.GetFirst()->GetData();
    int j = this->Length();
    for (int i = 0; i < j; i++)
    {
        int k = this->Get();
        if (k > max)
            max = k;
    }
    return max;
}

template<class T>
inline void TQueueList<T>::LoadToFile()
{
    ofstream fout("QueueList.txt");
    if (!fout)
        throw new exception;
    int j = this->Length();
    for (int i = 0; i < j; i++)
        fout << this->Get() << " ";
}

template<class T>
inline int TQueueList<T>::Length()
{
    return list.GetCount();
}

#endif