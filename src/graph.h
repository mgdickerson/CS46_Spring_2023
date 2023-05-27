#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
using namespace std;

void error(string msg);

template
    <typename T>
inline ostream& operator <<(ostream& out, const vector<T> & V)
{
    for (auto && e : V)
        out << e << ' ';
    return out;
}

using Vertex = int;

class DisjointSet {
    struct Set {
        Vertex parent;
    };
    vector<Set> subsets;
public:
    DisjointSet(int numVertices);
    void makeSet(Vertex x);
    Vertex findSet(Vertex x);
    void unionSets(Vertex x, Vertex y);
};

struct Edge {
    Vertex u, v;
    int weight;

    inline friend istream& operator >>(istream& in, Edge & e)
    {
        return in >> e.u >> e.v >> e.weight;
    }

    inline friend ostream& operator <<(ostream& out, const Edge & e)
    {
       return out << "(" << e.u << ","  << e.v << ","  << e.weight << ")" ;
    }
};

using EdgeList = vector<Edge>;
using VertexList = vector<Vertex>;

struct Graph : public EdgeList
{
    int numVertices = 0;
    // each vertex is an integer in range 0..numVertices-1
    // returns a copy of graph with edges sorted ascending by edge weight
    Graph sort_edges() const;
    VertexList edges_from(Vertex vertex) const;
    inline friend istream& operator >>(istream& in, Graph & G)
    {
        if (!(in >> G.numVertices))
            error("unable to find input file");
        for ( Edge e; in >> e; )
            G.push_back(e);
        return in;
    }
};

EdgeList Kruskals(const Graph& G);
int sum_weights(EdgeList const& L); // important for testing - the total cost of MST
void file_to_graph(string filename, Graph & G);

VertexList dfs(const Graph& graph, Vertex startVertex);
VertexList bfs(const Graph& graph, Vertex startVertex);
string get_arg(int argc, char *argv[], string def);
