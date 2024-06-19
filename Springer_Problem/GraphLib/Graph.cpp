#include "Graph.h"
#include "NodeExistsException.h"
//#include "/home/andy/Schreibtisch/FAP_CPP/fap/SemesterProjektWS2223/Field.h"

class Field;        //For line 96

//Declarations of intern functions
//These functions are for the Graph member function findShortestPathDijkstra
Node *nearestNode(std::list<Node *> Q, std::list<Data> nodeData);    //This function searches the nearest to source in Q
std::list<Node*> getNeighbours(Node* u);
int getDist(Node* u, std::list<Data> nodeData);
void setDist(Node* v, int dist, std::list<Data>& nodeData); //Use reference for the list what should be changed!
void setPrev(Node* v, Node* u, std::list<Data>& nodeData);  //Use reference for the list what should be changed!
std::list<Data> getPath(std::list<Data> nodeData, const Node* src, const Node* dst);

//std::stringstream returnFieldPath(std::list<Data>& result);

//---------------------------------------------------------------------------------------------------------------------

Node* Graph::findNode(const std::string& id){
    // - soll einen Node mit der gegebenen id in m_nodes suchen
    // - gibt den Pointer auf den Node zurück, wenn er gefunden wurde.
    // - gibt NULL zurück, falls kein Node mit der id gefunden wurde.
    for (auto it = m_nodes.begin(); it != m_nodes.end(); ++it) {
        if ((*it)->getID() == id){
            return *it;
        }
    }
        return NULL;
}


//---------------------------------------------------------------------------------------------------------------------

Node& Graph::addNode(Node* pNewNode){
    // bitte diese Zeile entfernen, wenn Sie die Funktion implementieren:
    //return *new Node("");

    // Überprüfen Sie, ob schon ein Node mit der gegeben id im Graph vorhanden ist!
    // Falls ja:
    //  - Exception werfen
    // Falls nein:
    //  - den neuen Node 'pNewNode' in m_nodes einfügen
    //  - Referenz auf den neuen Node zurück geben

    // TEST:
    // Testen Sie die Funktion, indem Sie indem Sie einen Graph mit ein paar Nodes in main.cpp erstellen
    // Testen Sie mit der Funktion 'findNode', ob die hinzugefügten Nodes im Graph vorhanden sind.
    if (findNode(pNewNode->getID()) == NULL){
        m_nodes.push_back(pNewNode);
    }else{
        throw NodeExistsException();
    }
    Node& NewNoderef = *m_nodes.back();     //Return reference of new Node
    return NewNoderef;

}

//---------------------------------------------------------------------------------------------------------------------

Edge& Graph::addEdge(Edge* pNewEdge){
    // bitte diese Zeile entfernen, wenn Sie die Funktion implementieren:
    //return *new Edge(*new Node(), *new Node());

    // - die neue Edge 'pNewEdge' in m_edges einfügen
    // - Referenz auf die neue Edge zurück geben

    // - Testen Sie ob der Source- und Destination-Node von 'pNewEdge' schon im Graph vorhanden ist.
    // -> fügen Sie diese Nodes hinzu, falls nicht (nutzen Sie dafür Graph::addNode)

    // TEST:
    // Testen Sie die Funktion, indem Sie einen Graph mit ein paar Nodes und Edges in main.cpp erstellen
    // Testen Sie mit der Funktion 'findEdges', ob die hinzugefügten Edges im Graph vorhanden sind.
    m_edges.push_back(pNewEdge);
    if (findNode(pNewEdge->getSrcNode().getID()) == NULL){
        addNode(&pNewEdge->getSrcNode());
    }
    if(findNode(pNewEdge->getDstNode().getID()) == NULL){
        addNode(&pNewEdge->getDstNode());
    }
    Edge& NewEdgeref = *m_edges.back();     //Return reference of new Node
    return NewEdgeref;

}


//---------------------------------------------------------------------------------------------------------------------

Graph::~Graph(){
    // - soll alle Edges im Graph löschen (delete)
    for(auto it = m_edges.begin(); it != m_edges.end(); it++){
        delete *it;
    }
    // - soll alle Nodes im Graph löschen (delete)
    for(auto it = m_nodes.begin(); it != m_nodes.end(); it++){
        if ( ((*it)->getID() != "") && (typeid((*it)) == typeid(Field*)) )      //If we have a field pointer, we have not allocated field object
                                                                                //But a mystery: It functions with == but not with !=
        {
            delete *it;
        }
    }
}


//---------------------------------------------------------------------------------------------------------------------

void Graph::remove(Node& rNode){
    //Create a list that stores all edges that are going to be deleted because they are connected to the rNode you want to delete
    std::list<Edge*> edgesToDelete;
    for (auto it = m_edges.begin(); it != m_edges.end(); ++it) {
        if ((*it)->isConnectedTo(rNode)) {
            edgesToDelete.push_back(*it);
        }
    }
    //Now iterate through the edgesToDelete List and delete (in order to free memory space) and remove the element in the m_edges List
    for(auto it = edgesToDelete.begin(); it != edgesToDelete.end(); it++){
        delete *it;
        m_edges.remove(*it);
    }
    // - finden sie den Pointer mit der Adresse von 'rNode' in m_nodes.
    // 		- der Pointer auf rNode soll aus m_nodes entfernt werden!
    // 		- der Pointer auf rNode muss mit 'delete' freigegeben werden!
    auto it = std::find(m_nodes.begin(),m_nodes.end(),&rNode);
    if(*it == &rNode){
        m_nodes.erase(it);
        delete *it;
    }
}


//---------------------------------------------------------------------------------------------------------------------

void Graph::remove(Edge& rEdge){
    // - der Pointer auf rEdge muss aus m_edges entfernt werden!
    // - der Pointer auf rEdge muss mit 'delete' freigegeben werden!
    auto it = std::find(m_edges.begin(),m_edges.end(),&rEdge);
    if(*it == &rEdge){
        delete *it;
        m_edges.erase(it);

    }

    // TEST:
    // Testen Sie die Funktion, indem Sie indem Sie einen Graph mit ein paar Nodes und Edges in main.cpp erstellen
    // und anschließend einzelne Edges wieder löschen.
    // Testen Sie mit der Funktion 'findEdges', ob die gelöschten Edges noch im Graph vorhanden sind.
}


//---------------------------------------------------------------------------------------------------------------------

std::vector<Edge*> Graph::findEdges(const Node& rSrc, const Node& rDst){
    std::vector<Edge*> ret;

    // - findet alle edges, mit rSrc als Source-Node und rDst als Destination-Node.
    // - füge die Zeiger der Edges in den vector 'ret' ein.

    for(auto it=m_edges.begin(); it!=m_edges.end(); it++){
        if((*it)->getSrcNode().getID() == rSrc.getID() && (*it)->getDstNode().getID() == rDst.getID()){
            ret.push_back((*it));
        }
    }
    return ret;

    // TEST:
    // Testen Sie die Funktion, indem Sie indem Sie einen Graph mit ein paar Nodes und Edges in main.cpp erstellen
    // und anschließend ein paar Edges im Graph suchen.
    // Prüfen Sie, ob Edges gefunden wurden und geben Sie die gefunden Edges auf der Kommandozeile aus!

}

///---------------------------------------------------------------------------------------------------------------------

std::list<Node*> Graph::findShortestPathDijkstra(/*std::deque<Edge*>& rPath, */const Node* pSrcNode, const Node* pDstNode) {

    std::list<Data> nodeData, result;       //Data(dist and prev) of each node + resultlist for the end
    Node *u;                                //Ram-node
    std::list<Node *> Q, neighbours, fieldPathNodes;         //Ram-nodelist copy of m_nodes + neihgbournodelit of a node
    int ram = 0;                            //Ram of distance (dist)

    for (auto it = m_nodes.begin(); it != m_nodes.end(); it++) {       //Initialize Q and nodeData
        Q.push_back(*it);
        if ((*it)->getID() == pSrcNode->getID()) {
            nodeData.push_back(Data((*it)->getID(), 0, *it));
        } else {
            nodeData.push_back(Data((*it)->getID()));
        }
    }
    //Q is now a copy of m_nodes
    //nodeData have the Data ID, dist and prev refering to each node of m_nodes
    //The source node data in nodeData has 0 as dist and itself as prev

    //Now Q will be shorter step by step, until it is empty
    while (!Q.empty()) {
        u = nearestNode(Q, nodeData);           //Set u to nearest Node to src, in first case it is src byself
        Q.remove(u);
        neighbours = getNeighbours(u);

        //Only do if there are any neighbours or one neighbour connected with outgoing Edge by u
        if (!neighbours.empty()) {

            int distu;  //Variable to save the dist(u) and use it more times (Saves times for every use of getDistfunc)
            int maxintegervalue = std::numeric_limits<int>::max(); //Shorter version and to compare later

            //Each neighbour node v
            for (auto v = neighbours.begin(); v != neighbours.end(); v++) {

                distu = getDist(u, nodeData);    //Just once using getDistfunc

                if (distu != maxintegervalue) {   //Do only if the current distance from u to src is not the initialized Infinity
                    ram = distu +1;          //ram = dist of u + (lenght between u and v), but this lenght is always 1 here

                    //Compare the lenght ram with the current lenght distance of v
                    //std::cout << "ram: " << ram << "\nDist(v): " << getDist(*v,nodeData) << std::endl; //For debug
                    if (ram < getDist(*v, nodeData)) {
                        setDist(*v, ram, nodeData);     //Set the new and shorter distance lenght if it is shorter
                        //std::cout <<  "Dist(v)set: " << getDist(*v,nodeData) << std::endl; //For debug
                        setPrev(*v, u, nodeData);
                    }
                }
            }
        }
    }

    result = getPath(nodeData, pSrcNode, pDstNode);

    for (auto it = result.begin(); it != result.end(); it++) {
        if (it != result.begin()) {
            fieldPathNodes.push_back((*it).getPrev());
        }
    }
    return fieldPathNodes;
}


//Definitions of intern functions
//These functions are for the Graph member function findShortestPathDijkstra
    Node *nearestNode(std::list<Node *> Q, std::list<Data> nodeData){
        //This function searches the nearest to source in Q
        //It will get the ID of the object of nodeData with the// shortest dist
        Data find;         //Result ID to search in Q at the end
        std::list<Data> ramND;      //Ram the nodeData elements refering to the Q elements
        for (auto itQ = Q.begin(); itQ != Q.end(); itQ++) {
            for (auto itND = nodeData.begin(); itND != nodeData.end(); itND++) {
                if ((*itQ)->getID() == itND->getID()) {
                    ramND.push_back(*itND);
                }
            }
        }
        find = *ramND.begin();
        for (auto it = ramND.begin(); it != ramND.end(); it++) {
            if (it != ramND.begin()) {
                if ((*it).getDist() < find.getDist()) {
                    find = *it;
                }
            }
        }

        for (auto it = Q.begin(); it != Q.end(); it++) {
            if ((*it)->getID() == find.getID()) {
                return *it;
            }
        }
        std::cout << "Error: Nearest Node could not be found. Returned first Q element.";
        return *Q.begin();
    }

    std::list<Node *> getNeighbours(Node *u) {
        std::list<Node *> returnList;
        for (auto it = u->getOutEdges().begin(); it != u->getOutEdges().end(); it++) {
            returnList.push_back(&(*it)->getDstNode());
        }
        return returnList;
    }


    int getDist(Node *u, std::list<Data> nodeData) {
        for (auto it = nodeData.begin(); it != nodeData.end(); it++) {
            if (u->getID() == (*it).getID()) {
                return (*it).getDist();
            }
        }
        std::cout << "Error: Could not get the distance to source from the entered Node." << std::endl;
        return -1;
    }


    void
    setDist(Node *v, int dist, std::list<Data> &nodeData) {     //Use reference for the list what should be changed!
        for (auto it = nodeData.begin(); it != nodeData.end(); it++) {
            if (v->getID() == (*it).getID()) {
                //std::cout << "In setfunc before setting dist: " << (*it).getDist() << std::endl;      //For debug
                (*it).setDist(dist);
                //std::cout << "In setfunc after setting dist: " << (*it).getDist() << std::endl;       //For debug
                break;
            }
        }
    }


    void setPrev(Node *v, Node *u, std::list<Data> &nodeData) {   //Use reference for the list what should be changed!
        //std::cout << "Testsetprev" << std::endl;  //For debug
        for (auto it = nodeData.begin(); it != nodeData.end(); it++) {
            if (v->getID() == (*it).getID()) {
                (*it).setPrev(u);
                break;
            }
        }
    }


    std::list<Data> getPath(std::list<Data> nodeData, const Node *src, const Node *dst) {
        std::list<Data> Path;           //Return at the end
        Data ram;                       //ram the current nodeData element
        //Now finding the nodeData element refering to the dst node
        for (auto it = nodeData.begin(); it != nodeData.end(); it++) {
            if ((*it).getID() == dst->getID()) {
                ram = *it;              //Set ram to the dst Data to begin with next loop
                Path.push_back(*it);
                //std::cout << "it.prev.ID: " << (*it).getPrev()->getID() << "\nram.prev.ID: " << ram.getPrev()->getID() << "\n" << std::endl;    //For debug
                break;
            }
        }
        //Beginning path with dst, filling with the path nodes to src
        while (Path.back().getID() != src->getID()) {
            for (auto it = nodeData.begin(); it != nodeData.end(); it++) {
                //std::cout << "it.ID: " << (*it).getID() << "\nram.prev.ID: " << ram.getPrev()->getID() << "\n" << std::endl;    //For debug
                if ((*it).getID() == ram.getPrev()->getID()) {        //Hit the node what comes before current ram node
                    Path.push_back(*it);
                    ram = *it;
                    break;                                          //If we passed the next previous node already, begin again from start
                }
            }
        }
        Path.reverse();     //To get path from src to dst
        return Path;
    }
/*
std::stringstream returnFieldPath(std::list<Data>& result)
{
    std::stringstream resultField;
    for (auto it = result.begin(); it != result.end(); it++)
    {

    }
}
*/