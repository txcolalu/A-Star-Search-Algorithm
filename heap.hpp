//
//  heap.hpp
//  test
//
//  Created by jiawei on 2022/3/8.
//

#ifndef heap_hpp
#define heap_hpp

#include <iostream>
template<typename T>
class Heap{
private:
    T _mArr[10000];
    size_t _mSize;
    void heapify(size_t idx){
        size_t l = 2*idx + 1;
        size_t r = 2*idx + 2;
        size_t m = idx;
        if(isMinHeap){
            if(l<_mSize && _mArr[m] > _mArr[l]) m = l;
            if(r<_mSize && _mArr[m] > _mArr[r]) m = r;
        }
        else{
            if(l<_mSize && _mArr[m] < _mArr[l]) m = l;
            if(r<_mSize && _mArr[m] < _mArr[r]) m = r;
        }
        if(m != idx){
            std::swap(_mArr[idx],_mArr[m]);
            heapify(m);
        }
    }
    void heapify(){
        for(long i = (_mSize - 1) >> 1;i>=0 ;i--){
            heapify(i);
        }
    }
    bool isMinHeap;
public:
    enum HeapType{
        MinHeap,
        MaxHeap
    };
    Heap(HeapType type = MinHeap){
        isMinHeap = type == MinHeap ? true : false;
        _mSize = 0;
    }
    Heap(T arr[],size_t n,HeapType type = MinHeap){
        isMinHeap = type == MinHeap ? true : false;
        _mSize = n;
        for(size_t i = 0;i<n;i++) _mArr[i] = arr[i];
        heapify();
    }
    void push(const T& n){
        _mArr[_mSize++] = n;
        heapify();
    }
    T pop(){
        T tmp = _mArr[0];
        swap(_mArr[0],_mArr[--_mSize]);
        heapify();
        return tmp;
    }
    T top(){
        return _mArr[0];
    }
    bool empty(){
        return _mSize == 0;
    }
    size_t size(){
        return _mSize;
    }
    void travel_list(){
        for(int i = 0;i<_mSize;i++){
            std::cout<<_mArr[i]<<" ";
        }
        puts("");
    }
};

#endif /* heap_hpp */
