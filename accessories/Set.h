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

#ifndef GRAPHVIS_SET_H
#define GRAPHVIS_SET_H


#include <vector>
#include "../graph/CNode.h"
#include "../graph/CEdge.h"


class Set {
public:


    std::vector<CNode*> &getNodeSet();

    std::vector<CEdge*> &getEdgeSet() ;

    void addToSet(CNode * node);
    void addToSet(CEdge * edge);

    void setNodeSet(std::vector<CNode*> *nodeSet);

    void setEdgeSet( std::vector<CEdge*> *edgeSet);

private:
    std::vector<CNode*> nodeSet_;
    std::vector<CEdge*> edgeSet_;
};


#endif //GRAPHVIS_SET_H
