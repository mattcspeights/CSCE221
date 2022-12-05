#pragma once
#include <cassert>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>


struct edge{
    size_t vertexFrom;
    size_t vertexTo;
    double weight;

    public:
        edge(): vertexFrom(), vertexTo(), weight(){}
        edge(size_t vertexFrom, size_t vertexTo, double weight): vertexFrom(vertexFrom), vertexTo(vertexTo), weight(weight){}
        edge(const edge& other): vertexFrom(other.vertexFrom), vertexTo(other.vertexTo), weight(other.weight){}
        edge& operator=(const edge& other){
            vertexFrom = other.vertexFrom;
            vertexTo = other.vertexTo;
            weight = other.weight;
            return *this;
        }

        bool operator==(const edge& other){
            if (this->vertexTo == other.vertexTo){
                return true;
            }
            return false;
        }
};


struct vertex{
    size_t value;
    double distance;
    bool known;
    std::vector<edge> edges;
    std::queue<edge> path;

    public:
        vertex(): value(), distance(INFINITY), known(false), edges(), path(){}
        vertex(size_t value): value(value), distance(INFINITY), known(false), edges(), path(){}
        vertex(const vertex& other): value(other.value), distance(other.distance), known(other.known),
         edges(other.edges), path(other.path){}
        vertex& operator=(const vertex& other){
            if (this != &other){
                value = other.value;
                distance = other.distance;
                known = other.known;
                edges = other.edges;
                path = other.path;    
            }
            return *this;
        }

        bool operator==(const vertex& other){
            if (this->value == other.value){
                return true;
            }
            return false;
        }

};

struct hashVertex{
    template <class Hash=std::hash<size_t>>
    std::size_t operator() (const vertex& vert) const {
        size_t hash = std::hash<size_t>()(vert.value);
        return hash;
    }
};

std::vector<edge> merge_lists(std::vector<edge>& left, std::vector<edge>& right);

std::vector<edge> merge_lists(std::vector<edge>& left, std::vector<edge>& right){
    size_t i = 0, j = 0, h = 0;
    std::vector<edge> output;
    while (i < left.size() && j < right.size()){
        if (left.at(i).weight < right.at(j).weight){
            output.insert(output.begin() + h, left.at(i));
            ++i;
            ++h;
        }
        else{
            output.insert(output.begin() + h, right.at(j));
            ++j;
            ++h;
        }
    }
    while (i < left.size()){
        output.insert(output.begin() + h, left.at(i));
        ++i;
        ++h;
    }
    while (j < right.size()){
        output.insert(output.begin() + h, right.at(j));
        ++j;
        ++h;
    }

    return output;
}

class Graph {
    // TODO(student): Task 1: implement Graph to represent a digraph
    std::unordered_map<size_t, vertex> adjaceny_list;
    size_t numVertex;
    size_t numEdges;

    public:
        // constructors
        Graph(): adjaceny_list(0), numVertex(0), numEdges(0) {}
        Graph(const Graph& other): adjaceny_list(other.adjaceny_list), numVertex(other.numVertex),
         numEdges(other.numEdges){}
        Graph& operator=(const Graph& other){
            if (this != & other){
                this->adjaceny_list = other.adjaceny_list;
                numVertex = other.numVertex;
                numEdges = other.numEdges;
            }
            return *this;
        }

        // accessors
        size_t vertex_count() const { return numVertex;}
        size_t edge_count() const { return numEdges;}

        bool contains_vertex(size_t id) const {
            try{
                this->adjaceny_list.at(id);
            }catch(const std::out_of_range& e){
                return false;
            }
            return true;
        }

        bool contains_edge(size_t src, size_t dest) const {
            if (this->contains_vertex(src)){
                std::vector<edge> edgeList = adjaceny_list.at(src).edges;

                for (edge& value : edgeList){
                    if (value.vertexTo == dest){
                        return true;
                    }
                }
            }
            return false;
        }

        double cost(size_t src, size_t dest) const {
            if (this->contains_edge(src, dest)){
                std::vector<edge> edgeList = adjaceny_list.at(src).edges;

                for (edge& value : edgeList){
                    if (value.vertexTo == dest){
                        return value.weight;
                    }
                }

                return INFINITY;
            }
            else {
                return INFINITY;
            }
        }

        // modifiers
        bool add_vertex(size_t id){
            if (this->contains_vertex(id)){
                return false;
            }
            vertex newVertex(id);
            this->adjaceny_list.insert({id, newVertex});
            numVertex++;
            return true;
        }

        bool add_edge(size_t src, size_t dest, double weight=1){
            if (this->contains_edge(src, dest)){
                return false;
            }
            if (!this->contains_vertex(src) || !this->contains_vertex(dest)){
                return false;
            }
            edge newEdge(src, dest, weight);
            bool addedEdge = false;
            std::vector<edge>& edgeList = this->adjaceny_list.at(src).edges;
            if (edgeList.size() == 0){
                edgeList.push_back(newEdge);
                addedEdge = true;
            }
            else{
                for (size_t i = 0; i < edgeList.size(); ++i){
                    if (newEdge.weight < edgeList.at(i).weight){
                        edgeList.insert(edgeList.begin() + i, newEdge);
                        addedEdge = true;
                        break;
                    }
                }
            }
            if (!addedEdge){
                edgeList.push_back(newEdge);
            }
            numEdges++;
            return true;
        }

        bool remove_vertex(size_t id){
            if (!this->contains_vertex(id)){
                return false;
            }
            std::cout << this->adjaceny_list.at(id).edges.size() << std::endl;
            numEdges -= this->adjaceny_list.at(id).edges.size();
            this->adjaceny_list.erase(id);
            numVertex--;
            for (auto& keyVal : adjaceny_list){
                for(auto it = keyVal.second.edges.begin(); it != keyVal.second.edges.end();){
                    if(it->vertexTo == id){
                        it = keyVal.second.edges.erase(it);
                        numEdges--;
                    }
                    else
                        ++it;
                }
            }
            return true;
        }

        bool remove_edge(size_t src, size_t dest){
            if (!this->contains_edge(src, dest)){
                return false;
            }
            bool foundEdge = false;
            std::vector<edge> edgeList = adjaceny_list.at(src).edges;
            for(auto it = edgeList.begin(); it != edgeList.end();){
                if(it->vertexTo == dest){
                    it = edgeList.erase(it);
                    numEdges--;
                }
                else
                    ++it;
            }
            return foundEdge;
        }

    void printGraph(){
        for (auto& [key, value] : this->adjaceny_list){
            std::cout << value.value << std::endl;
        }
    }

    // TODO(student): Task 2: implement Dijkstra's algorithm
    void dijkstra(size_t source_id){
        if (!this->contains_vertex(source_id)){
            return;
        }
        bool done = false;
        if (this->numVertex == 0){
            done = true;
        }
        this->adjaceny_list.at(source_id).known = true;
        this->adjaceny_list.at(source_id).distance = 0;
        std::vector<edge> currentEdges = this->adjaceny_list.at(source_id).edges;
        while (!done){
            // traverse to closest vertex
            edge& closestEdge = currentEdges.at(0);
            while (adjaceny_list.at(closestEdge.vertexTo).known){
                currentEdges.erase(currentEdges.begin());
                if (currentEdges.size() == 0){
                    return;
                }
                closestEdge = currentEdges.at(0);
            }
            vertex& currentVertex = this->adjaceny_list.at(closestEdge.vertexTo);
            vertex& prevVertex = this->adjaceny_list.at(closestEdge.vertexFrom);
            currentVertex.path = prevVertex.path;
            currentVertex.path.push(closestEdge);
            currentVertex.distance = closestEdge.weight;
            for (edge& ed : currentVertex.edges){
                vertex& temp = adjaceny_list.at(ed.vertexTo);
                if (temp.known){
                    if (currentVertex.distance + ed.weight < temp.distance){
                        temp.distance = currentVertex.distance + ed.weight;
                        temp.path = currentVertex.path;
                        temp.path.push(ed);
                    }
                }
                ed.weight += currentVertex.distance;
            }
            // add new edges into current edges
            currentEdges = merge_lists(currentEdges, currentVertex.edges);
            currentVertex.known = true;
            done = true;
            currentEdges.erase(currentEdges.begin());
            for (auto& [key, vert] : adjaceny_list){
                if (!vert.known){
                    done = false;
                    break;
                }
            }
            if (currentEdges.size() == 0){
                done = true;
            }
        }
    }

    double distance(size_t id) const {
        double dist;
        try{
            dist = this->adjaceny_list.at(id).distance;
        }catch(const std::out_of_range& e){
                return INFINITY;
            }
        return dist;
    }

    void print_shortest_path(size_t dest_id, std::ostream& os=std::cout) const {
        if (!this->contains_vertex(dest_id)){
            os << "<no path>\n";
            return;
        }
        vertex vertex = this->adjaceny_list.at(dest_id);
        if (vertex.path.size() == 0){
            os << vertex.value << " --> " << dest_id << " distance: " << vertex.distance << std::endl;
        }
        while (!vertex.path.empty()){
            if (vertex.path.size() != 1){
                os << vertex.path.front().vertexFrom << " --> ";
            }
            else{
                os << vertex.path.front().vertexFrom << " --> " << dest_id << " distance: " << vertex.distance << std::endl;
            }
            vertex.path.pop();
        }
    }
};
