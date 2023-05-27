#include "graph.h"

int main(int argc, char *argv[]) {
    string filename = get_arg(argc, argv, "small.txt");
    Graph G;
    file_to_graph(filename, G);

    cout << "MST: ";
    EdgeList mst = Kruskals(G);
    cout << mst << endl;
    cout << "Total weight = " << sum_weights(mst) << endl;

    cout << "DFS traversal: ";
    cout << dfs(G, 0) << endl;

    cout << "BFS traversal: ";
    cout << bfs(G, 0) << endl;
}
