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

#ifndef GRAPHVIS_BREADTHFIRSTSEARCH_H
#define GRAPHVIS_BREADTHFIRSTSEARCH_H


#include "../graph/CGraph.h"
#include "../accessories/Queue.h"

class BreadthFirstSearch {
public:
    /**
     *
     * @param g
     * @param s
     * @param printResult prints predecessor and distance to s
     * @param suppressAdditionalInfo if true suppresses additional printing output about iterations
     */
    void printBFS(CGraph * g, CNode * s,bool printResult, bool suppressAdditionalInfo);
private:
    void BFS(CGraph * g, CNode * s, bool suppressPrint);
};


#endif //GRAPHVIS_BREADTHFIRSTSEARCH_H
