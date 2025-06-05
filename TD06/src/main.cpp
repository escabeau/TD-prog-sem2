#include "node.hpp"

void delete_tree(Node* node) {
    if (!node) return;
    node->delete_children();
    delete node;
}

int main() {
    std::vector<int> valeurs = {5, 3, 7, 2, 4, 6, 8, 1, 9, 0};
    
    Node* root = create_node(valeurs[0]);
    for (size_t i = 1; i < valeurs.size(); ++i) {
        root->insert(valeurs[i]);
    }

    std::cout << "Affichage infixe : ";
    root->display_infix();
    std::cout << "\n";

    auto prefix_nodes = root->prefix();
    int somme = 0;
    for (auto node : prefix_nodes) {
        somme += node->value;
    }

    std::cout << "\nSomme des valeurs : " << somme << "\n";
    std::cout << "Hauteur de l arbre : " << root->height() << "\n";

    delete_tree(root);
    root = nullptr;

    return 0;
}
