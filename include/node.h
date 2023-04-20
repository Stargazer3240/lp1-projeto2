// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
    private:
        T value;
        Node* next;
    public:
        Node(T v, Node* n) : value{v}, next{n} {} 

        const T getValue() {return value;}
        const Node* getNext() {return next;}

        void setValue(const T& v) {value = v;}
        void setNext(const Node* n) {next = n;}
};

#endif
