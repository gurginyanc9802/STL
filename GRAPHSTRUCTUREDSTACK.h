#ifndef EXAM_H
#define EXAM_H

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <list>
#include <memory>
#include <algorithm>

template<typename T, typename Allocator = std::allocator<T>>
class Graphstructuredstack {
    public:
        using value_type = T;
        using size_type = size_t;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = value_type*;
        using const_pointer = const value_type*; 
        using allocator_type = Allocator;
        using iterator = typename std::unordered_map<T, std::vector<T>>::iterator;
        using const_iterator = typename std::unordered_map<T, std::vector<T>>::const_iterator;

    public:
        Graphstructuredstack(const Allocator& alloc = Allocator());
        ~Graphstructuredstack() {}

    public:
        void push(const_reference value, const std::vector<value_type>& parents = {});
        void push(const_reference value, const std::vector<iterator>& parents = {});
        void pop(const std::vector<value_type>& parentstodelete = {});
        reference top();
        const_reference top() const;
        bool empty() const;
        void printgraph() const;
        Allocator get_allocator() const;
        iterator find(const_reference nodetofind);
        void insert(iterator parentIt, const T& newValue);
        void insertbranch(iterator parent, iterator child);
    private:    
        std::unordered_map<T, std::vector<T>> adjList;
        std::stack<T, std::vector<T, Allocator>> stack; 
        Allocator allocator; 
     
};

#include "exam.hpp"
#endif



