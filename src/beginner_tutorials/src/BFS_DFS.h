#include <vector>
#include <deque>
#include <chrono>
#include <iostream>
#include "std_msgs/String.h"

#define TREE_DEPTH 10

using namespace std;

void tree_init(vector<vector<int>>& tree);

void DFS(vector<vector<int>>& tree, int* visited, int branch);

stringstream DFS_wrapper(vector<vector<int>>& tree);
stringstream BFS(vector<vector<int>>& tree);