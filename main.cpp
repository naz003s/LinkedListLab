#include "LinkedList.hpp"
#include <iostream>

int main() {
    LinkedList myList;

    // Step 1
    myList.SERVER_buildCircularLinkedList();

    // Step 2
    std::cout << "Server (step 2):" << std::endl;
    myList.SERVER_printLinkedList();
    std::cout << std::endl;

    // Step 3
    std::cout << "Client (step 3):" << std::endl;
    myList.CLIENT_printLinkedList();
    std::cout << std::endl;

    // Step 4
    myList.SERVER_deleteCircularLinkedList();


    // Step 5
    std::cout << "\nClient after linked list deleted (step 5 alternatively):" << std::endl;
    std::cout << "Client after linked list deleted:" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    myList.CLIENT_printLinkedList(); // Should print [Nothing]

    return 0;
}


