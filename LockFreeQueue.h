#pragma once
#include <queue>
#include "common.h"
#define QSZ     (1<<9)
#define QMSK    (QSZ - 1)
template<class T>
class LockFreeQueue
{
public:
	LockFreeQueue() :_head(0), _tail(0){
		_q = new T[QSZ];
	}
	~LockFreeQueue(){
		delete[] _q;
	}
	bool push( T& v){
		unsigned int head, tail;
		do{
			head = _head;
			tail = _tail;
			if (tail + QSZ == head){
				return false;
			}
		} while (!std::atomic_compare_exchange_weak(&_head, &head,head+1));
		_q[head & QMSK] = v;
		return true;
	}
	const T* pop(){
		unsigned int head, tail,masked;
		T* m;
		do{
			head = _head;
			tail = _tail;
			if (tail == head){
				return NULL;
			}
			masked = tail & QMSK;
			m = &_q[masked];
		} while (!std::atomic_compare_exchange_weak(&_tail,&tail,tail+1));
		return m;
	}
private:
	T*  _q;
	std::atomic<unsigned int> _head;
	std::atomic<unsigned int> _tail;
};

