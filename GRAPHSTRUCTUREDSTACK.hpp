#ifndef EXAM_CPP
#define EXAM_CPP

#include "exam.h"

template<typename T, typename Allocator>
Graphstructuredstack<T,Allocator>::Graphstructuredstack(const Allocator& alloc)
        : stack(std::vector<T, Allocator>(alloc)), allocator(alloc) {}

template<typename T, typename Allocator>
void Graphstructuredstack<T,Allocator>::push(const T& value, const std::vector<T>& parents) {
    if (adjList.find(value) != adjList.end()) {
        return;
    }
    stack.push(value);  
    adjList[value] = {};

    for (const auto& parent : parents) {
        adjList[parent].push_back(value);
    }
}

template<typename T, typename Allocator>
void Graphstructuredstack<T, Allocator>::push(const_reference value, const std::vector<iterator>& parents) {
    if(!adjList.contains(value)){
        stack.push(value);
        adjList[value] = {};
    }

    for(const auto& parent : parents) {
        parent->second.push_back(value);
    }
}

template<typename T, typename Allocator>
void Graphstructuredstack<T, Allocator>::pop(const std::vector<value_type>& parentstodelete) {
    if (stack.empty()) {
        throw std::out_of_range("Stack is empty");
    }

    T topElement = stack.top(); 

    if (parentstodelete.size() == 0) {
        for (auto& pair : adjList) {
            auto& child = pair.second;
            child.erase(std::remove(child.begin(), child.end(), topElement), child.end());
        }
        adjList.erase(topElement);
        stack.pop();
        return;
    }
    
    for (int i = 0; i < parentstodelete.size(); ++i) {
        auto& vec = adjList[parentstodelete[i]];
        vec.erase(std::remove(vec.begin(), vec.end(), topElement), vec.end());
    }

    bool nochild = false;
    for (const auto& pair : adjList) {
        const auto& vec = pair.second;

        if (std::find(vec.begin(), vec.end(), topElement) != vec.end()) {
            nochild = true;
            break;
        }
    }

    if (!nochild) {
        stack.pop();
        adjList.erase(topElement);
    }

}

template<typename T, typename Allocator>
T& Graphstructuredstack<T,Allocator>::top() {
    if (stack.empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return stack.top();
}

template<typename T, typename Allocator>
const T& Graphstructuredstack<T,Allocator>::top() const {
    if (stack.empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return stack.top();
}

template<typename T, typename Allocator>
bool Graphstructuredstack<T,Allocator>::empty() const {
    return stack.empty();
}

template<typename T, typename Allocator>
void Graphstructuredstack<T, Allocator>::printgraph() const {
    for (const auto& node : adjList) {
        std::cout << node.first << ": ";
        for (const auto& neighbor : node.second) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T, typename Allocator>
Allocator Graphstructuredstack<T,Allocator>::get_allocator() const {
    return allocator;
}

template<typename T, typename Allocator>
typename std::unordered_map<T, std::vector<T>>::iterator Graphstructuredstack<T,Allocator>::find(const T& nodetoFind) {
    auto it = adjList.find(nodetoFind);
    if (it == adjList.end()) {
        throw std::invalid_argument("Node not found");
    }
    return it;  
}

template<typename T, typename Allocator>
void Graphstructuredstack<T,Allocator>::insert(iterator parentIt, const T& newValue) {
    if (std::find(parentIt->second.begin(), parentIt->second.end(), newValue) == parentIt->second.end()) {
        parentIt->second.push_back(newValue);
    }
    if(!adjList.contains(newValue)){
        adjList[newValue] = {};
        stack.push(newValue);
    }
}

template<typename T, typename Allocator>
void Graphstructuredstack<T,Allocator>::insertbranch(iterator parent, iterator child) {
    if (std::find(parent->second.begin(), parent->second.end(), child->first) == parent->second.end()) {
        parent->second.push_back(child->first);
    }
}


#endif
