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

#ifndef GRAPHVIS_STRONGLYCONNECTEDCOMPONENTS_H
#define GRAPHVIS_STRONGLYCONNECTEDCOMPONENTS_H

#include "DepthFirstSearch.h"
#include <stack>

class StronglyConnectedComponents {
public:
    void SCC(CGraph* g);
    std::map<int, std::vector<CNode *>> * createSCCs(CGraph* g, bool print = false);
private:
    void mainloopDFS(CGraph* g);
    void dfsVisit(CGraph* g, CNode* u);
    int time{};

    /**
     * run SCC on graph g, which creates SCCs
     * key int: first, second,... scc
     * vector scc nodes
     */
    std::map<int, std::vector<CNode*>> sccVector;

};


#endif //GRAPHVIS_STRONGLYCONNECTEDCOMPONENTS_H
