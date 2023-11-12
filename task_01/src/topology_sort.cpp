#include <stdexcept>

#include "topology_sort.hpp"

void Graph::add_element(Vertex* parent) 
{
    Vertex v = Vertex(this->_cur_number, parent);
    this->_cur_number++;
}

std::vector<Vertex*> Graph::topology_sort()
{
    if (this->_roots.empty())
        throw std::runtime_error("Graph is empty. Nothing to sort");

    // for(Vertex* root : this->_roots)
    // {
    //     root.
    // }
}
