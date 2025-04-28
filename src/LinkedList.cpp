#include "LinkedList.hpp"
#include <iomanip>

LinkedList::LinkedList() {
}

LinkedList::~LinkedList() {
}

void LinkedList::SERVER_buildCircularLinkedList() {
    if (names.empty()) return;

    root = std::make_shared<Node>(names[0]);
    std::shared_ptr<Node> current_node = root;

    for (size_t i = 1; i < names.size(); ++i) {
        current_node->next = std::make_shared<Node>(names[i]);
        current_node = current_node->next;
    }

    current_node->next = root;

    current_node = root;
    do {
        current_node->weak_next = current_node->next;
        current_node = current_node->next;
    } while (current_node != root);
}

void LinkedList::SERVER_printLinkedList() {
    if (!root) {
        std::cout << "[Nothing]" << std::endl;
        return;
    }

    std::shared_ptr<Node> current_node = root;
    do {
        std::cout << "[" << current_node->name << "]: "
                  << "use_count: " << current_node.use_count() << " "
                  << "address: " << current_node.get() << " "
                  << "next (from shared_ptr): " << current_node->next.get()
                  << std::endl;
        current_node = current_node->next;
    } while (current_node != root);
}

void LinkedList::CLIENT_printLinkedList() {
    if (!root) {
         std::cout << "[Nothing]" << std::endl;
        return;
    }

    std::shared_ptr<Node> start_node = root;
    std::shared_ptr<Node> current_node = root;

    do {
        std::shared_ptr<Node> next_node = current_node->weak_next.lock();

        std::cout << "[" << current_node->name << "]: "
                  << "use_count: " << current_node.use_count()
                  << " address: " << current_node.get() << " ";

        if (next_node) {
            std::cout << "next (from weak_ptr): " << next_node.get() << std::endl;
             current_node = next_node;
        } else {
            std::cout << "next (from weak_ptr): 0" << std::endl;
            std::cout << "Yipes! shared_ptr not available" << std::endl;
             break;
        }
        if (current_node == start_node) break;

    } while (true);
}

void LinkedList::SERVER_deleteCircularLinkedList() {
    std::cout << "Server is deleting the shared_ptrs (step 4)" << std::endl;

    if (!root || !root->next) {
        root.reset();
        return;
    }

    std::shared_ptr<Node> current = root;
    while (current->next != root) {
        current = current->next;
         if (current == root) {
             return;
        }
    }

    current->next.reset();

    root.reset(); // Ensure root node is deleted before client tries printing
}
