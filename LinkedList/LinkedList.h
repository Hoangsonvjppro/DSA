//
// Created by hoangson-le on 2/21/25.
//

#ifndef INCLUDE_H
#define INCLUDE_H

#include <iostream>

// Định nghĩa kiểu dữ liệu DataType
struct DataType {
    int integer;
    float floatingNumber;
    double doubleNumber;
    char character;
    bool boolean;
};

// Định nghĩa cấu trúc của một nút trong danh sách liên kết
struct tagNode {
    DataType data;
    struct tagNode *next;
};

// Định nghĩa cấu trúc danh sách liên kết
struct tagList {
    tagNode *head;
    tagNode *tail;
};

// Khởi tạo danh sách liên kết
void initList(tagList &list) {
    list.head = nullptr;
    list.tail = nullptr;
}

// Tạo một nút mới
tagNode *createNode(DataType data) {
    tagNode *newNode = new tagNode;
    if (newNode == nullptr) {
        std::cerr << "Memory allocation error!" << std::endl;
        exit(1);
    }
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Thêm một nút vào cuối danh sách
void addNode(tagList &list, DataType data) {
    tagNode *newNode = createNode(data);
    if (list.head == nullptr) {
        list.head = newNode;
        list.tail = newNode;
    } else {
        list.tail->next = newNode;
        list.tail = newNode;
    }
}

// Duyệt danh sách và in dữ liệu
void traverseList(const tagList &list) {
    tagNode *current = list.head;
    while (current != nullptr) {
        std::cout << "Integer: " << current->data.integer
                  << ", Float: " << current->data.floatingNumber
                  << ", Double: " << current->data.doubleNumber
                  << ", Char: " << current->data.character
                  << ", Boolean: " << (current->data.boolean ? "true" : "false")
                  << std::endl;
        current = current->next;
    }
}

// Xóa danh sách và giải phóng bộ nhớ
void clearList(tagList &list) {
    tagNode *current = list.head;
    while (current != nullptr) {
        tagNode *temp = current;
        current = current->next;
        delete temp;
    }
    list.head = nullptr;
    list.tail = nullptr;
}

#endif // INCLUDE_H
