# LinkedListLab

## Overview

This lab demonstrates how to use `std::shared_ptr` and `std::weak_ptr` to manage a `circular linked list` in C++, demonstrating how `weak_ptr` prevents memory leaks commonly caused by `shared_ptr` reference cycles.

* The `server` creates and manages the list using `shared_ptr`.
* The `client` accesses the list using `weak_ptr` to avoid ownership cycles.

## How to Compile and Run

1.  Compile:
    ```bash
    make
    ```
2.  Run:
    ```bash
    ./main
    ```

## How to Test

1.  Compile tests:
    ```bash
    make test
    ```
2.  Run tests:
    ```bash
    ./test
    ```