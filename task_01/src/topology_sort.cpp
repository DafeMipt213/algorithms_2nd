#include <stdexcept>

#include "topology_sort.hpp"

void Graph::AddRoot(Vertex* root) 
{
    this->_roots.push_back(root);
}

void Graph::AddElement(int number, std::vector<Vertex*> parents) 
{
    if (parents.empty())
        throw std::runtime_error("Vertex has no parents");

    Vertex v = Vertex(number, parents);
}

std::vector<int> Graph::TopologySort()
{
    if (this->_roots.empty())
        throw std::runtime_error("Graph is empty. Nothing to sort");

    std::vector<int> result;
    for(Vertex* root : this->_roots)
    {
        root->ChangeColour(GRAY);
        std::vector<int> current_sorting = this->_TopologySort(root);
        root->ChangeColour(BLACK);
        result.push_back(root->GetNumber());
        result.insert(result.end(), current_sorting.begin(), current_sorting.end());
    }
    return result;
}

std::vector<int> Graph::_TopologySort(Vertex* root)
{
    std::vector<int> result;
    
    for (Vertex* vertex : root->GetChildren())
        {
            Colour vertex_colour = vertex->GetColour(); 
            if(vertex_colour == WHITE)
            {
                vertex->ChangeColour(GRAY);
                std::vector<int> current_sorting = this->_TopologySort(vertex);
                vertex->ChangeColour(BLACK);
                result.push_back(vertex->GetNumber());
                result.insert(result.end(), current_sorting.begin(), current_sorting.end());
            }
            else if (vertex_colour == BLACK)
                continue;
            else if (vertex_colour == GRAY)
                throw std::runtime_error("There is a cycle in the graph");
        }
    return result;
}

void AddEdge(Vertex* root, Vertex* child)
{
    child->AddParent(root);
    root->AddChild(child);
}