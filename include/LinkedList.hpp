#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <vector>
#include <string>
#include <memory>

struct Node;

class LinkedList {
private:
    std::shared_ptr<Node> root;
    std::vector<std::string> names = {"zero", "one", "two", "three", "four", "five"};

public:
    LinkedList();
    ~LinkedList();

    void SERVER_buildCircularLinkedList();
    void SERVER_deleteCircularLinkedList();
    void SERVER_printLinkedList();
    void CLIENT_printLinkedList();
};

struct Node {
    std::string name;
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> weak_next;

    Node(std::string name) : name{name} {}

    ~Node() {
        std::cout << "Node [" << name << "] destructor" << std::endl;
    }
};

#endif


