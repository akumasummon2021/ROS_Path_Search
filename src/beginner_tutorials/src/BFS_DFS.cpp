#include "BFS_DFS.h"

using namespace std;

void tree_init(vector<vector<int>>& tree){
    tree.push_back(vector<int> {1, 2});
    tree.push_back(vector<int> {3});
    tree.push_back(vector<int> {7});
    tree.push_back(vector<int> {4,5,6});
    tree.push_back(vector<int> {});
    tree.push_back(vector<int> {});
    tree.push_back(vector<int> {});
    tree.push_back(vector<int> {8,9});
    tree.push_back(vector<int> {});
    tree.push_back(vector<int> {});
}

stringstream BFS(vector<vector<int>>& tree){
    int visited[TREE_DEPTH] = {0};
    deque<int> queen;
    chrono::system_clock::time_point start, end;
    double duration = 0;
	stringstream output;
	int counter = 1;

    start = chrono::system_clock::now();

    /* init */
    queen.push_back(0);
    visited[0] = counter++;

    /* BFS algo */
    while (queen.size() != 0){
        int temp = queen[0];
        queen.pop_front();
        for(int i=0;i<tree[temp].size();++i){
            queen.push_back(tree[temp][i]);
            visited[tree[temp][i]] = counter++;
        }
    }

    end = chrono::system_clock::now();
    duration = double(chrono::duration_cast<chrono::nanoseconds>(end - start).count());
    output<<"BFS finished in "<<duration<<" ns"<<endl;
	
	output<<"Sequence of Node searching: ";

    /* print visited */
    for (int i=0;i<TREE_DEPTH;++i){
		for (int j=0; j<TREE_DEPTH;++j){
			if ((i+1) == visited[j]){
				output<<j<<", ";
			}
		}
    }
    output<<endl;
	
	return output;
}

void DFS(vector<vector<int>>& tree, int* visited, int branch, int counter){
    for (int i=0; i<tree[branch].size();++i){
        if (0 == visited[tree[branch][i]]){
            visited[tree[branch][i]] = counter++;
            DFS(tree, visited, tree[branch][i], counter);
        }
    }
}

stringstream DFS_wrapper(vector<vector<int>>& tree){
    int visited[TREE_DEPTH] = {0};
    chrono::system_clock::time_point start, end;
    double duration = 0;
	stringstream output;
	int counter = 1;

    /* init */
    ++visited[0];
    int temp = 0;

    start = chrono::system_clock::now(); 

    /* DFS algo */
    DFS(tree, visited, temp, counter);

    end = chrono::system_clock::now();
    duration = double(chrono::duration_cast<chrono::nanoseconds>(end-start).count());
    output<<"DFS finished in "<<duration<<" ns"<<endl;

	output<<"Sequence of Node searching: ";
	
    /* print visited */
    for (int i=0;i<TREE_DEPTH;++i){
		for (int j=0; j<TREE_DEPTH;++j){
			if ((i+1) == visited[j]){
				output<<j<<", ";
			}
		}
    }
    output<<endl;

	return output;
}


