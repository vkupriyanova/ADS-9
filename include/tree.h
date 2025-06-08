// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <memory>

class PMTree {
public:
    struct Node {
        char valuee;
        std::vector<std::unique_ptr<Node>> branches;
        int tree_size;
        Node(char v) : valuee(v), tree_size(0) {}
    };
    std::unique_ptr<Node> rootT;
    explicit PMTree(const std::vector<char>& elements);

private:
    std::unique_ptr<Node> buildNode(char valuee, const std::vector<char>& elements);

public:
    Node* getRoot() const { return rootT.get(); }
};
std::vector<std::vector<char>> getAllPerms(const PMTree& tree);
std::vector<char> getPerm1(const PMTree& tree, int num);
std::vector<char> getPerm2(const PMTree& tree, int num);
#endif  // INCLUDE_TREE_H_
