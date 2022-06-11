/**
*    GraphVis is a console-based graph visualiser.
*    Copyright (C) 2022  Tomas Duchac
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
*/

#ifndef TEST_CGRAPH_H
#define TEST_CGRAPH_H

/*#include <list>
#include "map"*/
#include <map>
#include "CNode.h"
#include "CEdge.h"


class CGraph {
public:
    CGraph();
    CGraph(bool directed_,
           bool weighed_,
           bool DAG);
    ~CGraph();

    std::vector<CNode*> *getNodes();

    void addNodesIntoGraph( CNode * node);
    bool isDirected() const;

    bool isWeighed() const;

    bool isDag() const;

    std::map<CNode *, std::vector<CEdge*>> *getMap();

    void initNODES();
    //void addInitNodeONLY(CNode * node);
    void addEdgeToNode(CNode * nodeKey, CEdge * edgeToAdd);

    void addInitNodeONLY(CNode * node);

    void addToNodeSet(CNode * key, CNode * nodeToAdd);

    std::map<CNode *, std::vector<CNode*>> &getNodeSet() ;

    void initNodeSetONLY();
    const std::map<int, CNode *> &getIdToCNode() const;
    void changeSet(CNode * n,std::vector<CNode*> set);

    std::vector<CEdge*>& allEdges(bool forceRewrite = false);

    void invertEdges();
private:

    std::vector<CNode *> nodes_;
    std::map<int, CNode *> idToCNode_;
    std::map<CNode * , std::vector<CEdge *>> map_;
    std::map<CNode * , std::vector<CNode*>> node_set_;
    std::vector<CEdge*> allEdgesInGraph;

    bool allEdgesInGraphInit = false;
    bool directed_{};
    bool weighed_{};
    bool DAG{};


};


#endif //TEST_CGRAPH_H
