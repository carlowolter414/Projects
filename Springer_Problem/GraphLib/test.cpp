#include "test.h"

#include "Edge.h"
#include "Node.h"
#include "Graph.h"
#include <list>
#include <iostream>
#include <algorithm>
//#include <string>


//______________________________________________________________________________________________________________________
//Function declarations (functions used by testfunctions), see the definitions below testfunctions
bool findEdge(std::list<Edge*> TestEdgeList, Edge* TestEdge);   //Function to find an edge pointer in an edge pointer list (Important for testEdgeConstructor())
void checkEdgelists(Edge* pTestedge, int i);   //Function to check if edge is content in the lists outlist of srcnode and inlist of dstnode


//______________________________________________________________________________________________________________________
//Testfunctions for main.cpp

//Test the constructor of Edge
void testEdgeConstructor(){
    //Description: see the following couts
    std::cout << "_________________________________________________________________________" << std::endl;
    std::cout << "This is a test of the constructor Edge(Node& rSrc, Node& rDst)." << std::endl;
    std::cout << "It will create SourceNode and DestinationNode of type Node and pTestEdge pointer of type Edge*." << std::endl;
    std::cout << "The pointer points to an object of type edge and this object will be saved in an allocated memory of the heap." << std::endl;
    std::cout << "This pointer system is important for accessing the Edge object in different functions." << std::endl;
    std::cout << "_________________________________________________________________________\n" << std::endl;

    //Creating the Nodes
    Node SourceNode = Node();
    Node DestinationNode = Node();

    //Creating the Edge pointer what points to the edge between that nodes
    Edge* pTestEdge = new Edge(SourceNode, DestinationNode);

    //Giving output if pTestEdge is a content of the Output list of SourceNode
    if (findEdge(SourceNode.getOutEdges(), pTestEdge)) {
        std::cout << "--> pTestEdge was found in the output list of Edge pointers of the source node." << std::endl;
    } else {
        std::cout << "--> pTestEdge was NOT found in the output list of Edges of the source node." << std::endl;
    }

    //Giving output if pTestEdge is a content of the Input list of DestinationNode
    if (findEdge(DestinationNode.getInEdges(), pTestEdge)) {
        std::cout << "--> pTestEdge was found in the input list of Edge pointers of the destination node." << std::endl;
    } else {
        std::cout << "--> pTestEdge was NOT found in the input list of Edges of the destination node." << std::endl;
    }
}


//Test the destructor of Edge
void testEdgeDestructor(){
    //Description: see the following couts
    std::cout << "_________________________________________________________________________" << std::endl;
    std::cout << "This is a test of the deconstructor ~Edge()." << std::endl;
    std::cout << "It will deallocate the memory what was used by the edge and delete the this pointer from the source and destination node." << std::endl;
    std::cout << "First we create 3 Edge pointers with Edges created with new operator. All having the same source and destination node." << std::endl;
    std::cout << "Then we delete the third pointer, it will cause the destructor of its Edge." << std::endl;
    std::cout << "We will check then if the first two edge pointers could be found in the edge lists of src and dst node." << std::endl;
    std::cout << "Then if the two edges are the only elements of that lists, the third was deleted successfully." << std::endl;
    std::cout << "_________________________________________________________________________\n" << std::endl;

    //Creating the Nodes
    Node SourceNode = Node();
    Node DestinationNode = Node();

    //Creating three Edge pointers with the same src and dst nodes
    Edge* pTestEdge1 = new Edge(SourceNode, DestinationNode);
    Edge* pTestEdge2 = new Edge(SourceNode, DestinationNode);
    Edge* pTestEdge3 = new Edge(SourceNode, DestinationNode);

    //Deletig only pTestEdge3
    delete pTestEdge3;

    //Check the pointers in their edges lists and outputs
    checkEdgelists(pTestEdge1, 1);
    checkEdgelists(pTestEdge2,2);


    //The first should be found, check number of elements in that lists
    //If the found elements are the right ones and the only ones, the other ist successfully deleted
    std::cout << "Number of elements of outlist of the source node: " << SourceNode.getOutEdges().size() << std::endl;
    std::cout << "Number of elements of inlist of the destination node: " << DestinationNode.getInEdges().size() << std::endl;

    //Check if SourceNode and DestinationNode are connected to pTestEdge1 and 2
    if (pTestEdge1->isConnectedTo(SourceNode) && pTestEdge1->isConnectedTo(DestinationNode)){
        std::cout << "SourceNode and DestinationNode are connected to pTestEdge1." << std::endl;
    }else{
        std::cout << "SourceNode and/or DestinationNode ARE NOT connected to pTestEdge1." << std::endl;
    }
    if (pTestEdge2->isConnectedTo(SourceNode) && pTestEdge2->isConnectedTo(DestinationNode)){
        std::cout << "SourceNode and DestinationNode are connected to pTestEdge2." << std::endl;
    }else{
        std::cout << "SourceNode and/or DestinationNode ARE NOT connected to pTestEdge2." << std::endl;
    }
    //Deleting the other ones: pTestEdge1 and 2; To release the reserved allocated memory
    delete pTestEdge1;
    delete pTestEdge2;
}



void testFindNode() {
    //Description: see the following couts
    std::cout << "_________________________________________________________________________" << std::endl;
    std::cout << "This is a test of the member function findNode()." << std::endl;
    std::cout << "It will create a Graph and add a Node Pointer to the Graphs nodelist." << std::endl;
    std::cout << "After that it sends the pointer to the mentioned function. It gives an output about the result." << std::endl;
    std::cout << "At the end we test the NULL-Return-case." << std::endl;
    std::cout << "_________________________________________________________________________\n" << std::endl;

    //Create a Graph and a Node and a pointer to the Node
    Graph TestGraph;
    Node TestNode;
    Node *pTestNode = &TestNode;

    //To test the NULL return case
    Node TestNodeOther;
    Node *pTestNodeOther = &TestNodeOther;

    //Add the Node pointer to the Graph
    TestGraph.addNode(pTestNode);

    //Output the id of TestNode
    std::cout << "The ID of TestNode is: " << TestNode.getID() << std::endl;
    std::cout << "The ID of TestNodeOther is: " << TestNodeOther.getID() << std::endl;

    //Output now, if the found pointer has the same ID or if it is not there (NULL)
    Node *pReturnNode = TestGraph.findNode(pTestNode->getID());
    if (pReturnNode == NULL) {
        std::cout << "pTestNode was not found." << std::endl;
    } else if(pReturnNode->getID() == pReturnNode->getID()){
        std::cout << "The ID of the found Node for searching pTestNode is: " << pReturnNode->getID() << std::endl;
    }

    pReturnNode = TestGraph.findNode(pTestNodeOther->getID());
    if (pReturnNode == NULL) {
        std::cout << "pTestNodeOther was not found." << std::endl;
    } else if(pReturnNode->getID() == pReturnNode->getID()){
        std::cout << "The ID of the found Node for searching pTestNodeOther is: " << pReturnNode->getID() << std::endl;
    }
}


void testAddNode(){
    //Description: see the following couts
    std::cout << "_________________________________________________________________________" << std::endl;
    std::cout << "This is a test of the member function addNote()." << std::endl;
    std::cout << "It will create a Graph and add three Node Pointers to the Graphs nodelist." << std::endl;
    std::cout << "After that it gives an output about the Node IDś and then the Node IDś of the nodelist by Graph." << std::endl;
    std::cout << "At the end we test throwing the specific exception by adding an already existing pointer." << std::endl;
    std::cout << "_________________________________________________________________________\n" << std::endl;
    //Create a Graph and 3 Nodes with 3 pointers
    Graph TestGraph;
    Node TestNode1;
    Node *pTestNode1 = &TestNode1;
    Node TestNode2;
    Node *pTestNode2 = &TestNode2;
    Node TestNode3;
    Node *pTestNode3 = &TestNode3;

    //Add the Node pointers to the Graph
    TestGraph.addNode(pTestNode1);
    TestGraph.addNode(pTestNode2);
    TestGraph.addNode(pTestNode3);

    //Output the IDś of TestNodes
    std::cout << "The ID of TestNode1 is: " << TestNode1.getID() << std::endl;
    std::cout << "The ID of TestNode2 is: " << TestNode2.getID() << std::endl;
    std::cout << "The ID of TestNode3 is: " << TestNode3.getID() << std::endl;

    //Output the IDś of Nodes the Node pointers by the graph points at
    int i = 1;
    for (auto it=TestGraph.getNodes().begin(); it!=TestGraph.getNodes().end(); it++){
        std::cout << "Node " << i << " of the Graph has the ID: " << (*it)->getID() << std::endl;
        i++;
    }

    //Adding pTestNode3 again to check if the already existing check functions and the exception is thrown
    std::cout << "\nNow we test if the function recognizes an already existing Node pointer and throws the Exception" << std::endl;
    std::cout << "NodeExistsException. We add an already existing one..." << std::endl;
    TestGraph.addNode(pTestNode3);
}

//This function also tests addEdge() !!!!!
void testFindEdges(){
    //Description: see the following couts
    std::cout << "_________________________________________________________________________" << std::endl;
    std::cout << "This is a test of the member function findEdges() of class Graph." << std::endl;
    std::cout << "We will create a Graph with Nodes A to F and following edges:" << std::endl;
    std::cout << "-> Edge 1: A to B\n-> Edge 2: B to C\n-> Edge 3: B to C\n-> Edge 4: B to E\n-> Edge 5: D to E\n-> Edge 6: E to F " << std::endl;
    std::cout << "The function should return a list of edges having the same src and dst nodes." << std::endl;
    std::cout << "If we search edges with giving B as src and C as dst nodes we should get Edge 2 and 3." << std::endl;
    std::cout << "_________________________________________________________________________\n" << std::endl;
    //Creating graphs, Nodes and Node pointers
    Graph TestGraph;
    Node A("A"); // B, C, D, E, F;  FUNKTIONIERT AB 2. OBJEKT NICHT MEHR, WHY??
    Node B("B");
    Node C("C");
    Node D("D");
    Node E("E");
    Node F("F");
    Node* pA; //pB, pC, pD, pE, pF;
    Node* pB;
    Node* pC;
    Node* pD;
    Node* pE;
    Node* pF;

    //Let the Node pointers points on the nodes
    pA = &A;
    pB = &B;
    pC = &C;
    pD = &D;
    pE = &E;
    pF = &F;

    //Creating the edges
    Edge* pEdge1 = new Edge(A,B);
    Edge* pEdge2 = new Edge(B,C);
    Edge* pEdge3 = new Edge(B,E);
    Edge* pEdge4 = new Edge(B,E);
    Edge* pEdge5 = new Edge(D,E);
    Edge* pEdge6 = new Edge(E,F);

    //Adding the Node pointer and Edge pointer to the Graph's list
    TestGraph.addNode(pA); TestGraph.addNode(pB); TestGraph.addNode(pC);
    TestGraph.addNode(pD); TestGraph.addNode(pE); TestGraph.addNode(pF);
    TestGraph.addEdge(pEdge1); TestGraph.addEdge(pEdge2); TestGraph.addEdge(pEdge3);
    TestGraph.addEdge(pEdge4); TestGraph.addEdge(pEdge5); TestGraph.addEdge(pEdge6);

    //Finding Edge 3 and 4, they have same src and dst
    std::cout << "We check now with findEdges(B, E) if we have edges with B as src and E as dst..." << std::endl;
    std::vector<Edge*> TestFoundEdges = TestGraph.findEdges(B,E);
    std::cout << "The vector of found edges has " << TestFoundEdges.size() << " elements." << std::endl;
    int i = 1;  //To numerize the found edges
    for (auto it=TestFoundEdges.begin(); it!=TestFoundEdges.end(); it++){
        std::cout << "-> Found edge " << i << " goes from " << (*it)->getSrcNode().getID() << " to " << (*it)->getDstNode().getID() << std::endl;
        i++;
    }

    //Deleting the Edges to release reserved allocated memory
    delete pEdge1;
    delete pEdge2;
    delete pEdge3;
    delete pEdge4;
    delete pEdge5;
    delete pEdge6;
}

void testGraphDestructor(){
        //Test the destructor of Graph class
#if 1
        Graph* Testgraph = new Graph();
    Node* TestNode1 = new Node();
    Node* TestNode2 = new Node();
    Edge* TestEdge1 = new Edge(*TestNode1, *TestNode2);
    std::cout << "We have such nice two Nodes: " << TestNode1->getID() << " and " << TestNode2->getID() << std::endl;
    std::cout << "We will add them into the Graph and an Edge between them..." << std::endl;
    Testgraph->addNode(TestNode1);
    Testgraph->addNode(TestNode2);
    Testgraph->addEdge(TestEdge1);
    std::cout << "Now we check if the Graph gives us the same Nodes: " << Testgraph->getNodes().front()->getID() <<
    " and " << Testgraph->getNodes().back()->getID() << std::endl;
    std::cout << "Super cool! Now we check how many edges we have in that graph and show the connections, should be just the one we have mentioned." << std::endl;
    int i = 1;
    for (auto it=Testgraph->getEdges().begin(); it!=Testgraph->getEdges().end(); it++){
        std::cout << "Edge " << i << " of the graph has the following connection... Src: " << (*it)->getSrcNode().getID()
        << " Dst: " << (*it)->getDstNode().getID() << std::endl;
        i++;
    }

    //Ist schon alles richtig, nur das Thema wenn man Edge oder Node deleted muss im Destructor vorher aus den Listen in Graph removen??
#if 0
    std::cout << "Wonderful! Now we destruct that Edge and check, if it is away." << std::endl;
    delete TestEdge1;
    std::cout << "We check the amount of elements of outlist of the src Node" << Testgraph->getNodes().front()->getID()
    << ": " << Testgraph->getNodes().front()->getOutEdges().size() << std::endl;
    std::cout << "We check the amount of elements of outlist of the dst Node" << Testgraph->getNodes().back()->getID()
              << ": " << Testgraph->getNodes().back()->getOutEdges().size() << std::endl;
    std::cout << "Wonderful again! Now we check the Edgelist of the Graph, if it is away." << std::endl;
    std::cout << "We check the amount of elements of Edgelist of the graph, amount of elements is: " << Testgraph->getEdges().size() << std::endl;
    std::cout << "Problem! The Edge is deleted and also out of the lists of the nodes but not of the list of graph." << std::endl;
    std::cout << "The src and dst of the found edge in list of graph is: "
    << Testgraph->getEdges().back()->getSrcNode().getID() << " and " << Testgraph->getEdges().front()->getDstNode().getID() << std::endl;
    std::cout << "Okay we will discuss that with the Mr. Albrecht, but also why it can display Node_0002 but not 0001" << std::endl;
    std::cout << "Should not be able to show anything, giving back an error message or whatever, that is mysterious." << std::endl;
#endif

    std::cout << "Whatever, now we destruct the whole Graph, BAM!" << std::endl;
    delete Testgraph;

#if 0
    std::cout << "Let us check, if we can acess the list of nodes, for example the last element, like before." << std::endl;
    std::cout << Testgraph->getNodes().back()->getID() << std::endl;
    std::cout << "Yes! That shows us, that it should be deleted, we cannot really acess and get any cryptical signs." << std::endl;
    std::cout << "What about the Edge..." << std::endl;
    i = 1;
    for (auto it=Testgraph->getEdges().begin(); it!=Testgraph->getEdges().end(); it++){
        std::cout << "Edge " << i << " of the graph has the following connection... Src: " << (*it)->getSrcNode().getID()
                  << " Dst: " << (*it)->getDstNode().getID() << std::endl;
        i++;
    }
#endif

#endif

}


void testRemove(){
    //Description: see the following couts
    std::cout << "_________________________________________________________________________" << std::endl;
    std::cout << "This is a test of the member function remove() of class Graph." << std::endl;
    std::cout << "We will create a Graph with Nodes A, B and C following edges:" << std::endl;
    std::cout << "-> Edge 1: A to B\n-> Edge 2: B to C" << std::endl;
    std::cout << "The function should remove a Node from the graph. So it also remove and delete all connected Edges." << std::endl;
    std::cout << "At the end it deletes the Node byself." << std::endl;
    std::cout << "_________________________________________________________________________\n" << std::endl;
    //Creating graphs, Nodes
    Graph* TestGraph = new Graph();
    Node* A = new Node("A");
    Node* B = new Node("B");
    Node* C = new Node("C");

    //Creating the edges
    Edge* Edge1 = new Edge(*A,*B);
    Edge* Edge2 = new Edge(*B,*C);

    //Adding the Node pointer and Edge pointer to the Graph's list
    TestGraph->addNode(A);
    TestGraph->addNode(B);
    TestGraph->addNode(C);
    TestGraph->addEdge(Edge1);
    TestGraph->addEdge(Edge2);

    std::cout << "Ok we go through the Nodelist of our graph. We have following nodes..." << std::endl;
    //Showing the Nodes for the public
    for(auto it=TestGraph->getNodes().begin(); it!=TestGraph->getNodes().end(); it++){
        std::cout << "-> Node: " << (*it)->getID() << std::endl;
    }



    //HIER LIEGT EIN FEHLER VOR Code: 139, Signal 11: SIGSEGV
    std::cout << "\nNow we remove A and C." << std::endl;
    //Removing node A and B
    Node& rA = *A;
    Node& rC = *C;
    TestGraph->remove(rA);
    TestGraph->remove(rC);

    std::cout << "\nWe will check the amount of the Edgelist of the graph." << std::endl;
    std::cout << "Both and the only edges was connected with A or C, so the amount should be zero." << std::endl;
    std::cout << "Amount of edgepointers in the edgelist of graph:" << TestGraph->getEdges().size() << std::endl;

    std::cout << "\nOkay cool. Let us check now what Nodes are still in the graph. It should be only B:" << std::endl;
    //Showing the Nodes what are still existing
    for(auto it=TestGraph->getNodes().begin(); it!=TestGraph->getNodes().end(); it++){
        std::cout << "-> Node: " << (*it)->getID() << std::endl;
    }

    std::cout << "\nSuper. Last check: Trying to get ID of A, I mean the Pointer I created at beginning, not from Graph list." << std::endl;
    std::cout << "We should get an error or any cryptical signs, because we deleted the object, it was pointing to." << std::endl;
    std::cout << "ID of A: " << A->getID() << std::endl;
    std::cout << "The same with Node C" << std::endl;
    std::cout << "ID of C: " << C->getID() << std::endl;

    std::cout << "\nVery well, but what about that pointers I created at beginning?? Let us delete that, too." << std::endl;
    delete A;
    delete C;
    //std::cout << "ID of A: " << A->getID() << std::endl; //give successfully the error


    //Deleting the whole Graph to release reserved allocated memory
    delete TestGraph;
}




//______________________________________________________________________________________________________________________
//Function definitions
bool findEdge(std::list<Edge*> TestEdgeList, Edge* TestEdge) {
    //fin() uses the content of TestEdge (Address of the Edge object) and compares with addresses of the pointers in the list
    //In the constructor of the Edge object, its this pointer should be added what points to the address of the Edge
    auto it = std::find(TestEdgeList.begin(), TestEdgeList.end(), TestEdge);
    if (it != TestEdgeList.end()) {
        return true;
    } else {
        return false;
    }
}

void checkEdgelists(Edge* pTestedge, int i){
    //Giving output if pTestEdge is a content of the Output list of SourceNode
    if (findEdge(pTestedge->getSrcNode().getOutEdges(), pTestedge)) {
        std::cout << "--> pTestedge" << i << " was found in the output list of Edge pointers of the source node." << std::endl;
    } else {
        std::cout << "--> pTestedge" << i << " NOT found in the output list of Edges of the source node." << std::endl;
    }
    //Giving output if pTestEdge1 is a content of the Input list of DestinationNode
    if (findEdge(pTestedge->getDstNode().getInEdges(), pTestedge)) {
        std::cout << "--> pTestedge" << i << " was found in the input list of Edge pointers of the destination node." << std::endl;
    } else {
        std::cout << "--> pTestedge" << i << " was NOT found in the input list of Edges of the destination node." << std::endl;
    }
}

void testFindShortestPathDijkstra1(){
    //Introduction
    std::cout << "______________________________________________________________________________________________________" << std::endl;
    std::cout << "This is a test function to test the member function findShortestPathDijkstra of the Graph class." << std::endl;
    std::cout << "We create this Graph:" << std::endl;
    std::cout << "          A " << std::endl;
    std::cout << "        /   \\ " << std::endl;
    std::cout << "      |/_   _\\| " << std::endl;
    std::cout << "     B  <----  C" << std::endl;
    std::cout << "     |" << std::endl;
    std::cout << "    \\|/" << std::endl;
    std::cout << "     D" << std::endl;
    std::cout << "     |" << std::endl;
    std::cout << "    \\|/" << std::endl;
    std::cout << "     E" << std::endl;
    std::cout << "     |" << std::endl;
    std::cout << "    \\|/" << std::endl;
    std::cout << "     F" << std::endl;
    std::cout << "__________________________________________________" << std::endl;
    std::cout << "A is the source node and F is the destination node. The function has to find the shortest path from A to F." << std::endl;
    std::cout << "So it should findout that the shortest path is A->B->D->E->F. The total lenght should be 4." << std::endl;
    std::cout << "__________________________________________________" << std::endl;
    std::cout << "Result:\n" << std::endl;



    //First Graph
    //First create a Graph with A as src and F as dst as follows:
    /*          A
     *        /   \
     *      |/_   _\|
     *     B  <----  C
     *     |
     *    \|/
     *     D
     *     |
     *    \|/
     *     E
     *     |
     *    \|/
     *     F
     */


    Graph* graph = new Graph();

    Node* A = new Node("A");
    Node* B = new Node("B");
    Node* C = new Node("C");
    Node* D = new Node("D");
    Node* E = new Node("E");
    Node* F = new Node("F");

    Edge* AB = new Edge(*A,*B);
    Edge* AC = new Edge(*A,*C);
    Edge* CB = new Edge(*C,*B);
    Edge* BD = new Edge(*B,*D);
    Edge* DE = new Edge(*D,*E);
    Edge* EF = new Edge(*E,*F);

    graph->addNode(A);
    graph->addNode(B);
    graph->addNode(C);
    graph->addNode(D);
    graph->addNode(E);
    graph->addNode(F);

    graph->addEdge(AB);
    graph->addEdge(AC);
    graph->addEdge(CB);
    graph->addEdge(BD);
    graph->addEdge(DE);
    graph->addEdge(EF);

    graph->findShortestPathDijkstra(A, F);

    delete graph;
    std::cout << "______________________________________________________________________________________________________\n\n" << std::endl;
}






void testFindShortestPathDijkstra2(){
    //Introduction
    std::cout << "______________________________________________________________________________________________________" << std::endl;
    std::cout << "This is a test function to test the member function findShortestPathDijkstra of the Graph class." << std::endl;
    std::cout << "We create this Graph:" << std::endl;
    std::cout << "          A " << std::endl;
    std::cout << "        /   \\ " << std::endl;
    std::cout << "      |/_   _\\| " << std::endl;
    std::cout << "     B         C" << std::endl;
    std::cout << "     |         |" << std::endl;
    std::cout << "    \\|/        |" << std::endl;
    std::cout << "     D         |" << std::endl;
    std::cout << "     |         |" << std::endl;
    std::cout << "    \\|/        |" << std::endl;
    std::cout << "     E  /______|"<< std::endl;
    std::cout << "     |  \\" << std::endl;
    std::cout << "    \\|/" << std::endl;
    std::cout << "     F" << std::endl;
    std::cout << "__________________________________________________" << std::endl;
    std::cout << "A is the source node and F is the destination node. The function has to find the shortest path from A to F." << std::endl;
    std::cout << "So it should findout that the shortest path is A->C->E->F. The total lenght should be 3." << std::endl;
    std::cout << "__________________________________________________" << std::endl;
    std::cout << "Result:\n" << std::endl;

//Second Graph
    //First create a Graph with A as src and F as dst as follows:
    /*          A
     *        /   \
     *      |/_   _\|
     *     B         C
     *     |         |
     *    \|/        |
     *     D         |
     *     |         |
     *    \|/        |
     *     E  /______|
     *     |  \
     *    \|/
     *     F
     */


    Graph* graph = new Graph();

    Node* A = new Node("A");
    Node* B = new Node("B");
    Node* C = new Node("C");
    Node* D = new Node("D");
    Node* E = new Node("E");
    Node* F = new Node("F");

    Edge* AB = new Edge(*A,*B);
    Edge* AC = new Edge(*A,*C);
    Edge* CE = new Edge(*C,*E);
    Edge* BD = new Edge(*B,*D);
    Edge* DE = new Edge(*D,*E);
    Edge* EF = new Edge(*E,*F);

    graph->addNode(A);
    graph->addNode(B);
    graph->addNode(C);
    graph->addNode(D);
    graph->addNode(E);
    graph->addNode(F);

    graph->addEdge(AB);
    graph->addEdge(AC);
    graph->addEdge(CE);
    graph->addEdge(BD);
    graph->addEdge(DE);
    graph->addEdge(EF);

    graph->findShortestPathDijkstra(A, F);

    delete graph;
    std::cout << "______________________________________________________________________________________________________\n\n" << std::endl;
}




void testFindShortestPathDijkstra3(){
    //Introduction
    std::cout << "______________________________________________________________________________________________________" << std::endl;
    std::cout << "This is a test function to test the member function findShortestPathDijkstra of the Graph class." << std::endl;
    std::cout << "We create this Graph:" << std::endl;
    std::cout << "          A " << std::endl;
    std::cout << "        /  " << std::endl;
    std::cout << "      |/_  " << std::endl;
    std::cout << "     B  ______\\ C" << std::endl;
    std::cout << "     |    __  / |" << std::endl;
    std::cout << "    \\|/    / \\  |" << std::endl;
    std::cout << "     D    /     |" << std::endl;
    std::cout << "     |   /      |" << std::endl;
    std::cout << "    \\|/ /       |" << std::endl;
    std::cout << "     E  /_______|"<< std::endl;
    std::cout << "     |  \\" << std::endl;
    std::cout << "    \\|/" << std::endl;
    std::cout << "     F" << std::endl;
    std::cout << "__________________________________________________" << std::endl;
    std::cout << "A is the source node and F is the destination node. The function has to find the shortest path from A to F." << std::endl;
    std::cout << "So it should findout that the shortest path is one of that two paths: A->B->D->E->F or A->B->C->E->F . The total lenght should be 4." << std::endl;
    std::cout << "__________________________________________________" << std::endl;
    std::cout << "Result:\n" << std::endl;

//Second Graph
    //First create a Graph with A as src and F as dst as follows:
    /*          A
     *        /
     *      |/_
     *     B  ______\ C
     *     |    __  / |
     *    \|/    / \  |
     *     D    /     |
     *     |   /      |
     *    \|/ /       |
     *     E  /_______|
     *     |  \
     *    \|/
     *     F
     */


    Graph* graph = new Graph();

    Node* A = new Node("A");
    Node* B = new Node("B");
    Node* C = new Node("C");
    Node* D = new Node("D");
    Node* E = new Node("E");
    Node* F = new Node("F");

    Edge* AB = new Edge(*A,*B);
    Edge* BC = new Edge(*B,*C);
    Edge* CE = new Edge(*C,*E);
    Edge* BD = new Edge(*B,*D);
    Edge* DE = new Edge(*D,*E);
    Edge* EC = new Edge(*E,*C);
    Edge* EF = new Edge(*E,*F);

    graph->addNode(A);
    graph->addNode(B);
    graph->addNode(C);
    graph->addNode(D);
    graph->addNode(E);
    graph->addNode(F);

    graph->addEdge(AB);
    graph->addEdge(BC);
    graph->addEdge(CE);
    graph->addEdge(BD);
    graph->addEdge(DE);
    graph->addEdge(EC);
    graph->addEdge(EF);


    graph->findShortestPathDijkstra(A, F);

    delete graph;
    std::cout << "______________________________________________________________________________________________________\n\n" << std::endl;
}
n
