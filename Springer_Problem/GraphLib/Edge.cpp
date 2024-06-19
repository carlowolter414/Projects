#include "Edge.h"


//---------------------------------------------------------------------------------------------------------------------
/**
 * Standard Constructor
 * Member initializer list to initialize the m_rSrc and m_rDst member variables with the values of the rSrc and rDst arguments.
 */
Edge::Edge(Node& rSrc, Node& rDst) : m_rSrc(rSrc), m_rDst(rDst){
    // fügt die Edge (this) in m_outgoingEdges des Source-Node ein.
    m_rSrc.getOutEdges().push_back(this);
    // fügt die Edge (this) in m_incomingEdges des Destination-Node ein.
    m_rDst.getInEdges().push_back(this);
    // Hinweis: die Funktionen Node::getOutEdges() und Node::getInEdges() verwenden!
}


//---------------------------------------------------------------------------------------------------------------------
/**
 * @brief Copy Constructor: takes a reference to an Edge object as an argument, rOther,
 * and initializes the member variables m_rSrc and m_rDst with the values of
 * the m_rSrc and m_rDst member variables of the rOther object. It then pushes the objects (respectively)
 * in the back of the list of outgoing and incoming edges.
 * @param rOther object from type Edge
 *
 */

Edge::Edge(const Edge& rOther) : m_rSrc(rOther.m_rSrc), m_rDst(rOther.m_rDst){
    // macht das Selbe wie 'Edge(Node& rSrc, Node& rDst)'
    m_rSrc.getOutEdges().push_back(this);
    m_rDst.getInEdges().push_back(this);

}


//---------------------------------------------------------------------------------------------------------------------

Edge::~Edge(){
    // - entfernt die Edge (this) aus m_outgoingEdges im Source-Node
    auto outEdges = m_rSrc.getOutEdges();
    outEdges.remove(this);
    // - entfernt die Edge (this) aus m_incomingEdges im Destination-Node
    auto inEdges = m_rDst.getInEdges();
    inEdges.remove(this);

}


//---------------------------------------------------------------------------------------------------------------------

bool Edge::isConnectedTo(const Node& rNode) const{
    // - gibt true zurück, wenn rNode entweder m_rSrc und m_rDst ist.
    // Hinweis: Adressen vergleichen, um zu gucken, ob es wirklich das selbe Objekt ist!
    if (&rNode == &m_rSrc || &rNode == &m_rDst){
        return true;
    }else{
        return false;
    }
}


//---------------------------------------------------------------------------------------------------------------------

std::string Edge::toString() const{
    std::string result;
    result = m_rSrc.getID() + " -> " + m_rDst.getID();
    return result;
}


//---------------------------------------------------------------------------------------------------------------------
