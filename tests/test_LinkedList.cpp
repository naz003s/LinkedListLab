#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/LinkedList.hpp"

TEST_CASE("SERVER builds circular linked list successfully") {
    LinkedList ll;
    CHECK_NOTHROW(ll.SERVER_buildCircularLinkedList());
}

TEST_CASE("SERVER prints the circular linked list successfully") {
    LinkedList ll;
    ll.SERVER_buildCircularLinkedList();
    CHECK_NOTHROW(ll.SERVER_printLinkedList());
}

TEST_CASE("CLIENT prints linked list before deletion successfully") {
    LinkedList ll;
    ll.SERVER_buildCircularLinkedList();
    CHECK_NOTHROW(ll.CLIENT_printLinkedList());
}

TEST_CASE("SERVER deletes the linked list safely") {
    LinkedList ll;
    ll.SERVER_buildCircularLinkedList();
    CHECK_NOTHROW(ll.SERVER_deleteCircularLinkedList());
}

TEST_CASE("CLIENT prints after SERVER deletes the list") {
    LinkedList ll;
    ll.SERVER_buildCircularLinkedList();
    ll.SERVER_deleteCircularLinkedList();
    CHECK_NOTHROW(ll.CLIENT_printLinkedList());
}


