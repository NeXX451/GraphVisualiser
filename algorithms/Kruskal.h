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

#ifndef GRAPHVIS_KRUSKAL_H
#define GRAPHVIS_KRUSKAL_H


#include "../graph/CGraph.h"

class Kruskal {
public:
    std::vector<CEdge*>  MST_Kruskal(CGraph * g);
private:
    std::vector<CNode*> unionNode(CGraph* g, CNode* u, CNode* v);
    std::vector<CEdge*> unionEdge(CGraph* g,std::vector<CEdge *> A, CEdge* edge);
    void print(CGraph* g,CEdge *pEdge, CNode *pNode, CNode *pNode1, std::vector<CNode *> *pVector, bool b);
};


#endif //GRAPHVIS_KRUSKAL_H
