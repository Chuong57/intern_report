#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

struct Node {
    int data;
    Node* next;
};

const int SIZE = 10000;

void generateRandomValues(Node*& head) {
    for (int i = 0; i < SIZE; ++i) {
        Node* newNode = new Node;
        newNode->data = rand() % 1000;
        newNode->next = head;
        head = newNode;
    }
}

int readValue(Node* head, int index) {
    Node* current = head;
    for (int i = 0; i < index && current != nullptr; ++i) {
        current = current->next;
    }
    if (current != nullptr) {
        return current->data;
    } else {
        return -1;
    }
}

void writeValue(Node* head, int index, int value) {
    Node* current = head;
    for (int i = 0; i < index && current != nullptr; ++i) {
        current = current->next;
    }
    if (current != nullptr) {
        current->data = value;
    } else {
        std::cout << "Index vuot qua kich thuoc danh sach.\n";
    }
}

void updateValue(Node* head, int index, int increment) {
    Node* current = head;
    for (int i = 0; i < index && current != nullptr; ++i) {
        current = current->next;
    }
    if (current != nullptr) {
        current->data += increment;
    } else {
        std::cout << "Index vuot qua kich thuoc danh sach.\n";
    }
}

void deleteList(Node*& head) {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    Node* myList = nullptr;

    auto start = std::chrono::high_resolution_clock::now();
    generateRandomValues(myList);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    // std::cout << "Thoi gian tao danh sach: " << duration.count() << "ms\n";

    start = std::chrono::high_resolution_clock::now();
    readValue(myList, 0);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Read value, Time: " << duration.count() << "ms\n";

    start = std::chrono::high_resolution_clock::now();
    writeValue(myList, 0, 999);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Write value, Time: " << duration.count() << "ms\n";

    start = std::chrono::high_resolution_clock::now();
    updateValue(myList, 0, 10);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Update value, Time: " << duration.count() << "ms\n";

    return 0;
}
