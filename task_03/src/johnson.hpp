#ifndef JOHNSON_HPP
#define JOHNSON_HPP

#include <vector>
#include <limits>

class JohnsonAlgorithm {
public:
    JohnsonAlgorithm(const std::vector<std::vector<int>>& graph);

    std::vector<std::vector<int>> run();

private:
    const std::vector<std::vector<int>>& graph;
    int numVertices;

    void addVirtualVertex(std::vector<std::vector<int>>& augmentedGraph);
    void removeVirtualVertex(std::vector<std::vector<int>>& augmentedGraph);
    void adjustWeights(std::vector<int>& distances);
};

#endif // JOHNSON_HPP
