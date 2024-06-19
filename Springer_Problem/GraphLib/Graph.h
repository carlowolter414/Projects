#include "Node.h"
#include "Edge.h"
#include <limits>
#include <vector>

class Graph
{

public:

    virtual ~Graph();



    Node& addNode(Node* pNewNode);

    Edge& addEdge(Edge* pNewEdge);

    void remove(Node& rNode);

    void remove(Edge& rEdge);


    const std::list<Node*>& getNodes() { return m_nodes; }

    const std::list<Edge*>& getEdges() { return m_edges; }

    Node* findNode(const std::string& id);

    std::vector<Edge*> findEdges(const Node& rSrc, const Node& rDst);

    // original it was const Node& rSrcNode, same to dst
    std::list<Node*> findShortestPathDijkstra(/*std::deque<Edge*>& rPath, */const Node* pSrcNode, const Node* pDstNode);


protected:

    std::list<Node*> m_nodes;
    std::list<Edge*> m_edges;

};



class Data
{
private:
    std::string ID;
    int dist;
    Node* prev;
    int maxintegervalue = std::numeric_limits<int>::max();

public:
    Data() { ID = "NULL"; dist = maxintegervalue; }
    Data(std::string ID) { this->ID = ID; dist = maxintegervalue; }
    Data(std::string ID, int dist) { this->ID = ID; this->dist = dist; }
    Data(std::string ID, int dist, Node* prev) { this->ID = ID; this->dist = dist; this->prev = prev; }
    std::string getID() { return ID; }
    int getDist() { return dist; }
    Node* getPrev() { return prev; }
    void setID(std::string ID) { this->ID = ID; }
    void setDist(int dist) { this->dist = dist; }
    void setPrev(Node* prev) { this->prev = prev; }
};

//---------------------------------------------------------------------------------------------------------------------


