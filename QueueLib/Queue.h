#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>

using namespace std;

template <class T>
class TQueue
{
protected:
  int length;
  T* x;
  int ind;
  int end;
  int count;
public:
  TQueue(int size=0);
  TQueue(const TQueue<T>& q);
  ~TQueue();

  TQueue<T>& operator =(TQueue<T>& _v);

  void Push(T d);
  T Get();

  int MinElem();
  int MaxElem();

  template <class T1>
  friend ostream& operator<< (ostream& ostr, const TQueue<T1> &A);
  template <class T1>
  friend istream& operator >> (istream& istr, TQueue<T1> &A);

  int Length();
};

template <class T1>
ostream& operator<< (ostream& ostr, const TQueue<T1> &A) {
  for (int i = A.ind; i < A.end; i++) 
  {
    ostr << A.x[i] << endl;
  }
  return ostr;
}

template <class T1>
istream& operator >> (istream& istr, TQueue<T1> &A) {
    int count;
    istr >> count;
    for (int i = 0; i < count; i++)
    {
        T1 d;
        istr >> d;
        A.Push(d);
    }
    return istr;
}


template <class T>
inline TQueue<T>::TQueue(int size)
{
    if (size > 0)
    {
        this->length = size;
        x = new T[length];
        for (int i = 0; i < length; i++)
            x[i] = 0;
        this->ind = 0;
        this->end = 0;
        this->count = 0;
    }
    else
        throw new exception;
}

template<class T>
TQueue<T>::TQueue(const TQueue<T>& q)
{
    ind = q.ind;
    end = q.end;
    count = q.count;
    length = q.length;
    x = new T[length];
    for (int i = 0; i < length; i++)
    {
        if (q.x[i] != NULL)
            x[i] = q.x[i];
        else
            x[i] = NULL;
    }
}

template <class T>
TQueue<T>::~TQueue()
{
  length = 0;
  if (x != 0)
    delete [] x;
  x = 0;
}

template <class T>
TQueue<T>& TQueue<T>::operator =(TQueue<T>& _v)
{
    if (this == &_v)
        return *this;

    this->length = _v.length;
    delete[] x;
    this->x = new T[length];
    for (int i = 0; i < length; i++)
        x[i] = _v.x[i];
    this->ind = _v.ind;
    this->end = _v.end;
    this->count = _v.count;
    return *this;
}

template<class T>
inline void TQueue<T>::Push(T d)
{
    if (count >= length)
        ind = (ind + 1) % length;
    x[end] = d;
    end = (end + 1) % length;
    count++;
}

template<class T>
inline T TQueue<T>::Get()
{
    if (count == 0)
        throw new exception;
    count--;
    T d = x[ind];
    x[ind] = NULL;
    ind = (ind +1)%length;
    return d;
}

template<class T>
inline int TQueue<T>::MinElem()
{
    int res = x[0];
    for (int i = 1; i < length; i++)
        if (x[i] < res)
            res = x[i];
    return res;
}

template<class T>
inline int TQueue<T>::MaxElem()
{
    int res = x[0];
    for (int i = 1; i < length; i++)
        if (x[i] > res)
            res = x[i];
    return res;
}


template <class T>
int TQueue<T>::Length()
{
  return length;
}


#endif