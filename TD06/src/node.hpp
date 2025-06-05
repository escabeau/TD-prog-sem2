#pragma once

#include <iostream>
#include <vector>
#include <string>

struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    bool is_leaf() const;
    void insert(int value);
    int height() const;
    void delete_children();
    void display_infix() const;
    std::vector<Node*> prefix() const;
};


Node* create_node(int value);

void pretty_print_left_right(Node const& node, std::string const& prefix = "", bool is_left = true);
