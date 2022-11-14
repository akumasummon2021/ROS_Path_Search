#include "Dijkstra.h"

static vector<Node> visited;

Node::Node (int node_index, int node_pre, int node_total_cost):index(node_index), pre(node_pre), total_cost(node_total_cost){}

bool cmpfunction(Node const &a, Node const &b) {
    return a.total_cost > b.total_cost;
}

bool cmpfunction_by_index(Node const &a, Node const &b) {
    return a.index < b.index;
}

/* init the graph */
void graph_init(vector<vector<path_cost>>& graph){
    graph.push_back(vector<path_cost> {{1, 12},{2, 9},{4, 21}});
    graph.push_back(vector<path_cost> {{0, 12},{2, 18},{3, 15}});
    graph.push_back(vector<path_cost> {{0, 9},{1, 18},{3, 33},{4, 24}});
    graph.push_back(vector<path_cost> {{1, 15},{2, 33},{4, 6},{5, 30},{6, 6}});
    graph.push_back(vector<path_cost> {{0, 21},{2, 24},{3, 6},{5, 15}});
    graph.push_back(vector<path_cost> {{3, 30},{4, 15},{6, 9}});
    graph.push_back(vector<path_cost> {{3, 6},{5, 9}});
}

/* core algorithm */
void Dijkstra(vector<vector<path_cost>>& graph, vector<Node>& Nodes, int start){
    int index = 0;

    /* put the start node to the end of the vector */
    sort(Nodes.begin(), Nodes.end(), cmpfunction);

    /* until all Notes are visited and poped up from the vector */
    while (Nodes.size() != 0){
        /* last element is the lowest cost node and get the index to find it in the graph */
        auto Nodes_end = Nodes.end()-1;
        index = Nodes_end->index;

        /* loop over the connected nodes */
        for (int i=0;i<graph[index].size();++i){
            /* because Nodes is sorted, can't use index to find out the element */
            for (int j=0;j<Nodes.size();++j){
                if(Nodes[j].index == graph[index][i].next){
                    /* calc the cost of actual node adds the cost to the connected node */
                    int cost = Nodes_end->total_cost + graph[index][i].cost;
                    /* if the new cost is lower than the actual cost of the connected node 
                       then replaces it and update the pre-node */
                    if (Nodes[j].total_cost > cost){
                        Nodes[j].total_cost = cost;
                        Nodes[j].pre = index;
                    }
                    break;
                }
            }
        }
        /* pop up the last node of the vector, vector adds the popped up node */
        visited.push_back(*(Nodes_end));
        Nodes.pop_back();
        /* after pop up, update the vector, the node with the lowest cost should be in the end of the vector */
        sort(Nodes.begin(), Nodes.end(), cmpfunction);
    }
}

void calc_path(int end){
    if (visited[end].pre != -1){
        calc_path(visited[end].pre);
        cout<<" -> "<<end;
    }
    else {
        cout<<end;
    }
}

stringstream Dijkstra_wrapper() {
    int start, end;
    vector<Node> Nodes;
    vector<vector<path_cost>> graph;
	stringstream output;

    for (int i=0;i<NODE_NUMBER;++i){
        Nodes.push_back(Node(i, PRE_POINT_OF_START_POINT, COST_INIT_VALUE));
    }
    
    graph_init(graph);

    start = 1;
    end = 5;
    Nodes[start].total_cost = 0;

    Dijkstra(graph, Nodes, start);
	
	/* print the infomation */
    sort(visited.begin(), visited.end(), cmpfunction_by_index);
    output<<"form start node "<<start<<":"<<endl;
    output<<"lowest cost to node "<<end<<" is: "<<visited[end].total_cost<<endl;
    output<<"shortest path to ode "<<end<<" is: ";

    calc_path(end);
    output<<endl;
	
	return output;
}