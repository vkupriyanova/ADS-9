// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
class PMNode {
    public:
        char valuee;
        std::vector<PMNode*> branches;
        explicit PMNode(char valL) : valuee(valL) {}
        ~PMNode();
};
class PMTree {
    private:
        PMNode* rootT;

    public:
        explicit PMTree(const std::vector<char>& data);
        ~PMTree();
        PMNode* getRoot() const;
};
std::vector<std::vector<char>> getAllPerms(PMTree& tree);
std::vector<char> getPerm1(PMTree& tree, int number);
std::vector<char> getPerm2(PMTree& tree, int number);

#endif  // INCLUDE_TREE_H_
