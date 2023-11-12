#pragma once

#include <string>
#include <vector>

/*
Taryan algotirthm is used there: https://ru.wikipedia.org/wiki/Топологическая_сортировка
In these interpreatation all vertices can be:
    1) "white" (if not visited)
    2) "black" (if visited)
    3) "gray"  (if gone in but not gone out)
*/

namespace Colour
{
    std::string white = "white";
    std::string gray = "gray";
    std::string black = "black";
}

class Vertex
{
    /* Struct of a vertex in a graph */

    public:
        Vertex(size_t number, Vertex* parent = nullptr): 
            _parent{parent}, _number{number} {}

        Vertex* get_parent() {return _parent; };
        std::vector<Vertex*> get_children() {return _children; };

        void add_child(Vertex* children) {_children.push_back(children); };

    private:
        size_t _number;
        Vertex* _parent = nullptr;
        std::vector<Vertex*> _children;
        std::string _colour = Colour::white; // possbile colours are "white", "gray" and "'black"
}
