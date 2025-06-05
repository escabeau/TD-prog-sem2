#include "node.hpp"

Node* create_node(int value) {
    return new Node{value, nullptr, nullptr};
}

bool Node::is_leaf() const {
    return left == nullptr && right == nullptr;
}

void Node::insert(int val) {
    if (val < value) {
        if (left) left->insert(val);
        else left = create_node(val);
    } else {
        if (right) right->insert(val);
        else right = create_node(val);
    }
}

int Node::height() const {
    int left_height = left ? left->height() : 0;
    int right_height = right ? right->height() : 0;
    return 1 + std::max(left_height, right_height);
}

void Node::delete_children() {
    if (left) {
        left->delete_children();
        delete left;
        left = nullptr;
    }
    if (right) {
        right->delete_children();
        delete right;
        right = nullptr;
    }
}

void Node::display_infix() const {
    if (left) left->display_infix();
    std::cout << value << " ";
    if (right) right->display_infix();
}

std::vector<Node*> Node::prefix() const {
    std::vector<Node*> result;
    result.push_back(const_cast<Node*>(this));
    if (left) {
        auto left_prefix = left->prefix();
        result.insert(result.end(), left_prefix.begin(), left_prefix.end());
    }
    if (right) {
        auto right_prefix = right->prefix();
        result.insert(result.end(), right_prefix.begin(), right_prefix.end());
    }
    return result;
}

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}
