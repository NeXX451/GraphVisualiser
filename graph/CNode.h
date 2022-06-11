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

#ifndef TEST_CNODE_H
#define TEST_CNODE_H


#include <string>
#include <vector>
#include <iostream>
// #include "CEdge.h" // deprecated

class CNode {

public:
    static int lastId;

    CNode();

    int getId() const;

    void setId(int val);

    const std::string &getName() const;

    void setName(const std::string &name);
    //std::vector<CEdge> *getEdges() ; // deprecated

    //void addEdge(CNode right,int weight); // deprecated
    //void addEdge(CNode right); // deprecated

    void printNode() const;
    //void printEdges(); // deprecated
    bool operator == (CNode * c);
    static int getLastId();

    static void setLastId(int lastId);

    int getColor() const;

    void setColor(int color);

    int getDistance() const;

    void setDistance(int distance);

    int getDiscoveryTime() const;

    void setDiscoveryTime(int discoveryTime);

    int getFinishTime() const;

    void setFinishTime(int finishTime);

    CNode *getPredecessor() const;

    void setPredecessor(CNode *predecessor);

    //void setEdges( std::vector<CEdge> edges ); // deprecated


    const std::string &getNilPredecessor() const;

    void setNilPredecessor(const std::string &nilPredecessor);
    int getKeyMst() const;

    void setKeyMst(int keyMst);


private:

    int COLOR;
    int DISTANCE;
    int DISCOVERY_TIME;
    int FINISH_TIME;
    CNode * PREDECESSOR;

    std::string nilPREDECESSOR;

    int keyMST;
    int id_;
    std::string name_;
    //std::vector<CEdge> edges_; // deprecated


};

#endif //TEST_CNODE_H