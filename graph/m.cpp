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

#include <iostream>
#include "CGraph.h"

using namespace std;

int main(){
    CNode n0;
    CNode n1;
    CNode n2;
    CNode n3;
    CNode n4;
    CNode n5;



    CGraph graph;
    n0.addEdge(n1);
    n0.addEdge(n2);
    n0.addEdge(n3);
    n1.addEdge(n2);
    n1.addEdge(n5);
    n2.addEdge(n3);
    n3.addEdge(n0);
    n4.addEdge(n3);
    n4.addEdge(n1);
    n5.addEdge(n0);
    graph.addNodesIntoGraph(n0);
    graph.addNodesIntoGraph(n1);
    graph.addNodesIntoGraph(n2);
    graph.addNodesIntoGraph(n3);
    graph.addNodesIntoGraph(n4);
    graph.addNodesIntoGraph(n5);

    for(CNode n: graph.getNodes()){
        n.printEdges();
    }





    return 0;
}

