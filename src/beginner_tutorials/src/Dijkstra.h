#include <iostream>
#include<vector>
#include<algorithm>
#include "std_msgs/String.h"

#define NODE_NUMBER 7
#define PRE_POINT_OF_START_POINT -1
#define COST_INIT_VALUE 9999

using namespace std;

struct path_cost{
    int next;
    int cost;
};

class Node {
    public:
        int index;
        int pre;
        int total_cost;
        Node (int node_index, int node_pre, int node_total_cost);
};

bool cmpfunction(Node const &a, Node const &b);

bool cmpfunction_by_index(Node const &a, Node const &b);

/* init the graph */
void graph_init(vector<vector<path_cost>>& graph);

/* core algorithm */
void Dijkstra(vector<vector<path_cost>>& graph, vector<Node>& Nodes, int start);

void calc_path(int end);

stringstream Dijkstra_wrapper();