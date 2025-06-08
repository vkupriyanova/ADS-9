// Copyright 2022 NNTU-CS
#include  <iostream>
#include <algorithm>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"
PMNode::~PMNode() {
  for (auto* b : branches) {
    delete b;
  }
}
void createTree (PMNode* node, std::vector<char> remaining) {
  if (remaining.empty()) return;
  for (size_t i = 0; i < remaining.size(); ++i) {
    char valL = remaining[i];
    std::vector<char> next = remaining;
    next.erase(next.begin() + i);
    PMNode* branch = new PMNode(valL);
    node->branches.push_back(branch);
    createTree(branch, next);
  }
}
PMTree::PMTree(const std::vector<char>& data) {
  root = new PMNode('\0');
  buildTree(rootT, data);
}
PMTree::~PMTree() {
  delete rootT;
}

PMNode* PMTree::getRoot() const {
  return rootT;
}
void collectPerms(PMNode* node, std::vector<char>& path, std::vector<std::vector<char>>& result) {
  if (node->valuee != '\0') {
    path.push_back(node->valuee);
  }
if (node->branches.empty()) {
    if (!path.empty())
      result.push_back(path);
  } else {
    for (auto* branch : node->branches) {
      collectPerms(branch, path, result);
    }
  }
if (!path.empty() && node->valuee != '\0') {
    path.pop_back();
  }
}
std::vector<std::vector<char>> getAllPerms(PMTree& tree) {
  std::vector<std::vector<char>> result;
  std::vector<char> path;
  collectPerms(tree.getRoot(), path, result);
  return result;
}

std::vector<char> getPerm1(PMTree& tree, int number) {
  if (number < 1) return {};

  std::vector<std::vector<char>> all = getAllPerms(tree);
  if (number > all.size()) return {};
  return all[number - 1];
}

std::vector<char> getPerm2(PMTree& tree, int number) {
  if (number < 1) return {};
std::vector<char> result;
  PMNode* node = tree.getRoot();
  --number;

  int sizeBT = node->branches.size();
  for (int i = sizeBT; i >= 1; --i) {
    int factl = 1;
    for (int j = 2; j < i; ++j)
      factl *= j;

    int index = number / factl;
    if (index >= node->branches.size())
      return {};

    node = node->branches[index];
    result.push_back(node->valuee);
    number %= factl;
  }

  return result;
}
