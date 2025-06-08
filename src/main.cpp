// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <fstream>

#include "tree.h"

std::vector<char> genAlbet(int n) {
  std::vector<char> result;
  for (int i = 0; i < n; ++i) {
    result.push_back('a' + i);
  }
  return result;
}
int factor(int n) {
  int f = 1;
  for (int i = 2; i <= n; ++i) {
    f *= i;
  }
  return f;
}

int main() {
  std::ofstream fout("result/plot.csv");
  fout << "n,getAllPerms,getPerm1,getPerm2\n";
  for (int n = 1; n <= 10; ++n) {
    std::vector<char> in = genAlbet(n);
    PMTree tree(in);
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dist(1, factor(n));
    int number = dist(gen);
    auto start = std::chrono::high_resolution_clock::now();
    auto all = getAllPerms(tree);
    auto end = std::chrono::high_resolution_clock::now();
    auto timeAll = std::chrono::duration<double, std::milli>(
        end - start).count();
    start = std::chrono::high_resolution_clock::now();
    auto p1 = getPerm1(tree, number);
    end = std::chrono::high_resolution_clock::now();
    auto timeOne = std::chrono::duration<double, std::milli>(
        end - start).count();
    start = std::chrono::high_resolution_clock::now();
    auto p2 = getPerm2(tree, number);
    end = std::chrono::high_resolution_clock::now();
    auto timeTwo = std::chrono::duration<double, std::milli>(
        end - start).count();
    fout << n << "," << timeAll << "," << timeOne << ","
         << timeTwo << "\n";
    std::cout << "n = " << n << " done.\n";
  }
  fout.close();
  return 0;
}
