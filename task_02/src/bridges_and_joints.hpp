#include <vector>
#include <set>

struct Edge{
    int first_vertex, second_vertex;
};

struct BridgesAndJoints{
    std::set<Edge> Bridges;
    std::set<int> Joints;

    BridgesAndJoints(){};
};

bool operator==(const Edge a, const Edge b);
bool operator==(const BridgesAndJoints a, const BridgesAndJoints b);
bool operator<(const Edge a, const Edge b);

void dfs(int vertex, std::vector<bool> &visited, std::vector<std::vector<int>> &graph, std::vector <int> &depth, std::vector <int> &minimum_depth, BridgesAndJoints &result, int previous = -1);
BridgesAndJoints Search(std::vector<std::vector<int>> &graph);