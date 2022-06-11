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
#include <map>


#include "algorithms/Dijkstra.h"
#include "algorithms/BreadthFirstSearch.h"
#include "algorithms/DepthFirstSearch.h"
#include "algorithms/TopologicalSort.h"
#include "algorithms/Prim.h"
#include "algorithms/Kruskal.h"
#include "algorithms/BellmanFord.h"
#include "algorithms/SingleSourceShortestPathInDAG.h"
#include "algorithms/StronglyConnectedComponents.h"

using namespace std;



int main() {

    /**
     * DIJKSTRA
     */
    /*CNode n1;
    CNode n2;
    CNode n3;
    CNode n4;
    CNode n5;
    CNode n6;
    CNode n7;

    CEdge n1n2(&n1,&n2,1);
    CEdge n1n4(&n1,&n4,7);

    CEdge n2n1(&n2,&n1,1);
    CEdge n2n4(&n2,&n4,5);
    CEdge n2n3(&n2,&n3,3);

    CEdge n3n2(&n3,&n2,3);
    CEdge n3n4(&n3,&n4,1);
    CEdge n3n6(&n3,&n6,6);
    CEdge n3n7(&n3,&n7,2);

    CEdge n4n1(&n4,&n1,7);
    CEdge n4n2(&n4,&n2,5);
    CEdge n4n3(&n4,&n3,1);
    CEdge n4n5(&n4,&n5,3);

    CEdge n5n4(&n5,&n4,3);
    CEdge n5n6(&n5,&n6,1);
    CEdge n5n7(&n5,&n7,1);

    CEdge n6n3(&n6,&n3,6);
    CEdge n6n5(&n6,&n5,1);

    CEdge n7n3(&n7,&n3,3);
    CEdge n7n5(&n7,&n5,1);

    CGraph g;
    g.addNodesIntoGraph(&n1);
    g.addNodesIntoGraph(&n2);
    g.addNodesIntoGraph(&n3);
    g.addNodesIntoGraph(&n4);
    g.addNodesIntoGraph(&n5);
    g.addNodesIntoGraph(&n6);
    g.addNodesIntoGraph(&n7);
    g.initNODES();
    g.addEdgeToNode(&n1,&n1n2);
    g.addEdgeToNode(&n1,&n1n4);
    g.addEdgeToNode(&n2,&n2n1);
    g.addEdgeToNode(&n2,&n2n4);
    g.addEdgeToNode(&n2,&n2n3);
    g.addEdgeToNode(&n3,&n3n2);
    g.addEdgeToNode(&n3,&n3n4);
    g.addEdgeToNode(&n3,&n3n6);
    g.addEdgeToNode(&n3,&n3n7);
    g.addEdgeToNode(&n4,&n4n1);
    g.addEdgeToNode(&n4,&n4n2);
    g.addEdgeToNode(&n4,&n4n3);
    g.addEdgeToNode(&n4,&n4n5);
    g.addEdgeToNode(&n5,&n5n4);
    g.addEdgeToNode(&n5,&n5n6);
    g.addEdgeToNode(&n5,&n5n7);
    g.addEdgeToNode(&n6,&n6n3);
    g.addEdgeToNode(&n6,&n6n5);
    g.addEdgeToNode(&n7,&n7n3);
    g.addEdgeToNode(&n7,&n7n5);

    Dijkstra dijkstra; dijkstra.SSSPDijkstr(&g,&n1);
    dijkstra.printResult(&g,&n1);*/



    /**
     * BFS
     */
    /*CNode n1;
    CNode n2;
    CNode n3;
    CNode n4;
    CNode n5;
    CNode n6;
    CNode n7;
    CEdge n1n5(&n7,&n5);
    CEdge n1n3(&n7,&n3);
    CEdge n2n4(&n7,&n4);
    CEdge n2n7(&n7,&n7);
    CEdge n3n2(&n7,&n2);
    CEdge n3n5(&n7,&n5);
    CEdge n6n1(&n7,&n1);
    CEdge n6n3(&n7,&n3);
    CEdge n7n3(&n7,&n3);

    CGraph g;
    g.addNodesIntoGraph(&n1);
    g.addNodesIntoGraph(&n2);
    g.addNodesIntoGraph(&n3);
    g.addNodesIntoGraph(&n4);
    g.addNodesIntoGraph(&n5);
    g.addNodesIntoGraph(&n6);
    g.addNodesIntoGraph(&n7);
    g.initNODES();
    g.addEdgeToNode(&n1,&n1n5);
    g.addEdgeToNode(&n1,&n1n3);
    g.addEdgeToNode(&n2,&n2n4);
    g.addEdgeToNode(&n2,&n2n7);
    g.addEdgeToNode(&n3,&n3n2);
    g.addEdgeToNode(&n3,&n3n5);
    g.addEdgeToNode(&n6,&n6n1);
    g.addEdgeToNode(&n6,&n6n3);
    g.addEdgeToNode(&n7,&n7n3);

    BreadthFirstSearch s;
    s.printBFS(&g,&n6, true, false);*/

    /**
     * DFS
     */
    /*CNode n1;
    CNode n2;
    CNode n3;
    CNode n4;
    CNode n5;
    CNode n6;
    CNode n7;
    CEdge n1n5(&n7,&n5);
    CEdge n1n3(&n7,&n3);
    CEdge n2n4(&n7,&n4);
    CEdge n2n7(&n7,&n7);
    CEdge n3n2(&n7,&n2);
    CEdge n3n5(&n7,&n5);
    CEdge n6n1(&n7,&n1);
    CEdge n6n3(&n7,&n3);
    CEdge n7n3(&n7,&n3);

    CGraph g;
    g.addNodesIntoGraph(&n1);
    g.addNodesIntoGraph(&n2);
    g.addNodesIntoGraph(&n3);
    g.addNodesIntoGraph(&n4);
    g.addNodesIntoGraph(&n5);
    g.addNodesIntoGraph(&n6);
    g.addNodesIntoGraph(&n7);
    g.initNODES();
    g.addEdgeToNode(&n1,&n1n5);
    g.addEdgeToNode(&n1,&n1n3);
    g.addEdgeToNode(&n2,&n2n4);
    g.addEdgeToNode(&n2,&n2n7);
    g.addEdgeToNode(&n3,&n3n2);
    g.addEdgeToNode(&n3,&n3n5);
    g.addEdgeToNode(&n6,&n6n1);
    g.addEdgeToNode(&n6,&n6n3);
    g.addEdgeToNode(&n7,&n7n3);

    DepthFirstSearch d;
    d.DFS(&g,true);*/


    /**
     * TOPOLOGICAL SORT
     */
    /*CNode n0;
    CNode n1;
    CNode n2;
    CNode n3;
    CNode n4;
    CNode n5;
    CNode n6;
    CNode n7;

    CEdge n0n3(&n0,&n3);
    CEdge n0n4(&n0,&n4);
    CEdge n1n3(&n1,&n3);
    CEdge n2n5(&n2,&n5);
    CEdge n2n6(&n2,&n6);
    CEdge n6n7(&n6,&n7);

    CGraph g;
    g.addNodesIntoGraph(&n0);
    g.addNodesIntoGraph(&n1);
    g.addNodesIntoGraph(&n2);
    g.addNodesIntoGraph(&n3);
    g.addNodesIntoGraph(&n4);
    g.addNodesIntoGraph(&n5);
    g.addNodesIntoGraph(&n6);
    g.addNodesIntoGraph(&n7);
    g.initNODES();
    g.addEdgeToNode(&n0,&n0n3);
    g.addEdgeToNode(&n0,&n0n4);
    g.addEdgeToNode(&n1,&n1n3);
    g.addEdgeToNode(&n2,&n2n5);
    g.addEdgeToNode(&n2,&n2n6);
    g.addEdgeToNode(&n6,&n6n7);

    TopologicalSort topo;
    topo.printTopologicalOrder(&g);*/



    /*map<CNode*, vector<CEdge>> m;
    CNode n1;
    CNode n2;
    CNode n3;
    CEdge n1n2(&n1,&n2);
    CEdge n1n3(&n1,&n3);
    CEdge n3n2(&n3,&n2);
    m.insert(make_pair(&n1, vector<CEdge>()));
    m.insert(make_pair(&n2, vector<CEdge>()));
    m.insert(make_pair(&n3, vector<CEdge>()));

    m.at(&n1).push_back(n1n2);
    m.at(&n1).push_back(n1n3);
    m.at(&n3).push_back(n3n2);

    vector<CEdge> * ve = &m.at(&n1);

    for (int i = 0; i < ve->size(); ++i) {
        cout << ve->at(i).getEdge().first << " " << ve->at(i).getEdge().second<< endl;
    }
*/

    /**
     * PRIM
     */
    /*CNode a; a.setName("a");
    CNode b; b.setName("b");
    CNode c; c.setName("c");
    CNode d; d.setName("d");
    CNode e; e.setName("e");
    CNode f; f.setName("f");
    CNode g; g.setName("g");
    CNode h; h.setName("h");
    CNode j; j.setName("j");
    CNode k; k.setName("k");
    CNode l; l.setName("l");
    CNode m; m.setName("m");
    CNode n; n.setName("n");
    CNode p; p.setName("p");
    CNode r; r.setName("r");



    CEdge ab(&a,&b,3);
    CEdge ad(&a,&d,2);
    CEdge ag(&a,&g,5);
    CEdge ac(&a,&c,1);
    CEdge af(&a,&f,4);
    CEdge be(&b,&e,8);
    CEdge bn(&b,&n,7);
    CEdge bf(&b,&f,4);
    CEdge ba(&b,&a,3);
    CEdge bd(&b,&d,1);
    CEdge ca(&c,&a,1);
    CEdge cf(&c,&f,5);
    CEdge cg(&c,&g,2);
    CEdge ch(&c,&h,7);
    CEdge db(&d,&b,1);
    CEdge da(&d,&a,2);
    CEdge dh(&d,&h,3);
    CEdge eb(&e,&b,8);
    CEdge fm(&f,&m,7);
    CEdge fb(&f,&b,4);
    CEdge fa(&f,&a,4);
    CEdge fc(&f,&c,5);
    CEdge fh(&f,&h,4);
    CEdge fl(&f,&l,7);
    CEdge ga(&g,&a,5);
    CEdge gc(&g,&c,2);
    CEdge hd(&h,&d,3);
    CEdge hc(&h,&c,7);
    CEdge hf(&h,&f,4);
    CEdge hl(&h,&l,7);
    CEdge jn(&k,&n,5);
    CEdge jk(&k,&k,2);
    CEdge kj(&k,&j,2);
    CEdge km(&k,&m,3);
    CEdge lf(&l,&f,7);
    CEdge lh(&l,&h,7);
    CEdge lr(&l,&r,1);
    CEdge mk(&m,&k,3);
    CEdge mf(&m,&f,7);
    CEdge nb(&n,&b,7);
    CEdge nj(&n,&j,5);
    CEdge pr(&p,&r,3);
    CEdge rp(&r,&p,3);
    CEdge rl(&r,&l,1);



    CGraph graph;
    graph.addNodesIntoGraph(&a);
    graph.addNodesIntoGraph(&b);
    graph.addNodesIntoGraph(&c);
    graph.addNodesIntoGraph(&d);
    graph.addNodesIntoGraph(&e);
    graph.addNodesIntoGraph(&f);
    graph.addNodesIntoGraph(&g);
    graph.addNodesIntoGraph(&h);
    graph.addNodesIntoGraph(&j);
    graph.addNodesIntoGraph(&k);
    graph.addNodesIntoGraph(&l);
    graph.addNodesIntoGraph(&m);
    graph.addNodesIntoGraph(&n);
    graph.addNodesIntoGraph(&p);
    graph.addNodesIntoGraph(&r);
    graph.initNODES();

    graph.addEdgeToNode(&a,&ab);
    graph.addEdgeToNode(&a,&ad);
    graph.addEdgeToNode(&a,&ag);
    graph.addEdgeToNode(&a,&ac);
    graph.addEdgeToNode(&a,&af);
    graph.addEdgeToNode(&b,&be);
    graph.addEdgeToNode(&b,&bn);
    graph.addEdgeToNode(&b,&bf);
    graph.addEdgeToNode(&b,&ba);
    graph.addEdgeToNode(&b,&bd);
    graph.addEdgeToNode(&c,&ca);
    graph.addEdgeToNode(&c,&cf);
    graph.addEdgeToNode(&c,&cg);
    graph.addEdgeToNode(&c,&ch);
    graph.addEdgeToNode(&d,&db);
    graph.addEdgeToNode(&d,&da);
    graph.addEdgeToNode(&d,&dh);
    graph.addEdgeToNode(&e,&eb);
    graph.addEdgeToNode(&f,&fm);
    graph.addEdgeToNode(&f,&fb);
    graph.addEdgeToNode(&f,&fa);
    graph.addEdgeToNode(&f,&fc);
    graph.addEdgeToNode(&f,&fh);
    graph.addEdgeToNode(&f,&fl);
    graph.addEdgeToNode(&g,&ga);
    graph.addEdgeToNode(&g,&gc);
    graph.addEdgeToNode(&h,&hd);
    graph.addEdgeToNode(&h,&hc);
    graph.addEdgeToNode(&h,&hf);
    graph.addEdgeToNode(&h,&hl);
    graph.addEdgeToNode(&j,&jn);
    graph.addEdgeToNode(&j,&jk);
    graph.addEdgeToNode(&k,&kj);
    graph.addEdgeToNode(&k,&km);
    graph.addEdgeToNode(&l,&lf);
    graph.addEdgeToNode(&l,&lh);
    graph.addEdgeToNode(&l,&lr);
    graph.addEdgeToNode(&m,&mk);
    graph.addEdgeToNode(&m,&mf);
    graph.addEdgeToNode(&n,&nb);
    graph.addEdgeToNode(&n,&nj);
    graph.addEdgeToNode(&p,&pr);
    graph.addEdgeToNode(&r,&rp);
    graph.addEdgeToNode(&r,&rl);


    Prim prim;
    prim.MST_Prim(&graph, &a);*/


    /*CNode a; a.setName("a");
    CNode b; b.setName("b");
    CNode c; c.setName("c");
    CNode d; d.setName("d");

    CEdge ab(&a,&b,6);
    CEdge ad(&a,&d,1);
    CEdge ac(&a,&c,6);
    CEdge ba(&b,&a,1);
    CEdge ca(&c,&a,6);
    CEdge cd(&c,&d,3);
    CEdge da(&d,&a,1);
    CEdge dc(&d,&c,3);

    CGraph graph;
    graph.addNodesIntoGraph(&a);
    graph.addNodesIntoGraph(&b);
    graph.addNodesIntoGraph(&c);
    graph.addNodesIntoGraph(&d);
    graph.initNODES();
    graph.addEdgeToNode(&a,&ab);
    graph.addEdgeToNode(&a,&ad);
    graph.addEdgeToNode(&a,&ac);
    graph.addEdgeToNode(&b,&ba);
    graph.addEdgeToNode(&c,&ca);
    graph.addEdgeToNode(&c,&cd);
    graph.addEdgeToNode(&d,&da);
    graph.addEdgeToNode(&d,&dc);
    cout<<"nodes:"<<endl;
    for (int i = 0; i < graph.getNodes()->size(); ++i) {
        graph.getNodes()->at(i)->setKeyMst(INT32_MAX);
        cout<< graph.getNodes()->at(i)->getName()<< " key "<<  graph.getNodes()->at(i)->getKeyMst()<< endl;
    }
    graph.getNodes()->at(2)->setKeyMst(INT32_MIN);
    cout<< graph.getNodes()->at(2)->getName()<< " key "<<  graph.getNodes()->at(0)->getKeyMst()<< endl;
    cout<<"edges"<<endl;
    for (int i = 0; i < graph.getNodes()->size(); ++i) {
        for (int j = 0; j < graph.getMap()->at(graph.getNodes()->at(i)).size(); ++j) {
            cout << graph.getMap()->at(graph.getNodes()->at(i)).at(j)->getEdge().first->getName() << " "<< graph.getMap()->at(graph.getNodes()->at(i)).at(j)->getEdge().second->getName()<<" "<<graph.getMap()->at(graph.getNodes()->at(i)).at(j)->getWeight()<<endl;
        }
    }
    Queue q;
    q.addAll(graph.getNodes());
    q.sortMST();
    while (!q.isEmpty()){
        CNode * n = q.dequeueMSTNode();
        cout << n->getName() << " "<< n->getKeyMst()<<endl;
    }*/

    /**
     *  Kruskal
     */
    /*CNode a; a.setName("a");
    CNode b; b.setName("b");
    CNode c; c.setName("c");
    CNode d; d.setName("d");
    CNode e; e.setName("e");
    CNode f; f.setName("f");
    CNode g; g.setName("g");
    CNode h; h.setName("h");
    CNode j; j.setName("j");
    CNode k; k.setName("k");

    CEdge jk(&j,&k,4);
    CEdge jb(&j,&b,2);
    CEdge je(&j,&e,5);
    CEdge kj(&k,&j,4);
    CEdge kb(&k,&b,3);
    CEdge bk(&b,&k,3);
    CEdge bj(&b,&j,2);
    CEdge be(&b,&e,8);
    CEdge eb(&e,&b,8);
    CEdge ej(&e,&j,5);

    CEdge af(&a,&f,4);
    CEdge ac(&a,&c,1);
    CEdge ag(&a,&g,3);
    CEdge ad(&a,&d,3);
    CEdge fa(&f,&a,4);
    CEdge fc(&f,&c,5);
    CEdge fh(&f,&h,4);
    CEdge hf(&h,&f,4);
    CEdge hc(&h,&c,7);
    CEdge hd(&h,&d,2);
    CEdge dh(&d,&h,2);
    CEdge da(&d,&a,3);
    CEdge ca(&c,&a,1);
    CEdge cf(&c,&f,5);
    CEdge ch(&c,&h,7);
    CEdge cg(&c,&g,2);
    CEdge gc(&g,&c,2);
    CEdge ga(&g,&a,3);

    CGraph graph;
    graph.addNodesIntoGraph(&a);
    graph.addNodesIntoGraph(&b);
    graph.addNodesIntoGraph(&c);
    graph.addNodesIntoGraph(&d);
    graph.addNodesIntoGraph(&e);
    graph.addNodesIntoGraph(&f);
    graph.addNodesIntoGraph(&g);
    graph.addNodesIntoGraph(&h);
    graph.addNodesIntoGraph(&j);
    graph.addNodesIntoGraph(&k);
    graph.initNODES();
    graph.addEdgeToNode(&j,&jk);
    graph.addEdgeToNode(&j,&jb);
    graph.addEdgeToNode(&j,&je);
    graph.addEdgeToNode(&k,&kj);
    graph.addEdgeToNode(&k,&kb);
    graph.addEdgeToNode(&b,&bk);
    graph.addEdgeToNode(&b,&bj);
    graph.addEdgeToNode(&b,&be);
    graph.addEdgeToNode(&e,&eb);
    graph.addEdgeToNode(&e,&ej);
    graph.addEdgeToNode(&a,&af);
    graph.addEdgeToNode(&a,&ac);
    graph.addEdgeToNode(&a,&ag);
    graph.addEdgeToNode(&a,&ad);
    graph.addEdgeToNode(&f,&fa);
    graph.addEdgeToNode(&f,&fc);
    graph.addEdgeToNode(&f,&fh);
    graph.addEdgeToNode(&h,&hf);
    graph.addEdgeToNode(&h,&hc);
    graph.addEdgeToNode(&h,&hd);
    graph.addEdgeToNode(&d,&dh);
    graph.addEdgeToNode(&d,&da);
    graph.addEdgeToNode(&c,&ca);
    graph.addEdgeToNode(&c,&cf);
    graph.addEdgeToNode(&c,&ch);
    graph.addEdgeToNode(&c,&cg);
    graph.addEdgeToNode(&g,&gc);
    graph.addEdgeToNode(&g,&ga);

    Kruskal kruskal;
    kruskal.MST_Kruskal(&graph);*/

    /**
     * BellmanFord
     */
   /* CNode a; a.setName("a");
    CNode b; b.setName("b");
    CNode c; c.setName("c");
    CNode d; d.setName("d");
    CNode e; e.setName("e");
    CNode f; f.setName("f");

    CEdge ac(&a,&c,3);
    CEdge ab(&a,&b,1);
    CEdge cb(&c,&b,-3);
    CEdge cd(&c,&d,2);
    CEdge bd(&b,&d,3);
    CEdge bf(&b,&f,-4);
    CEdge de(&d,&e,-2);
    CEdge ef(&e,&f,2);

    CGraph graph;
    graph.addNodesIntoGraph(&a);
    graph.addNodesIntoGraph(&b);
    graph.addNodesIntoGraph(&c);
    graph.addNodesIntoGraph(&d);
    graph.addNodesIntoGraph(&e);
    graph.addNodesIntoGraph(&f);

    graph.initNODES();
    graph.addEdgeToNode(&a,&ac);
    graph.addEdgeToNode(&a,&ab);
    graph.addEdgeToNode(&c,&cb);
    graph.addEdgeToNode(&c,&cd);
    graph.addEdgeToNode(&b,&bd);
    graph.addEdgeToNode(&b,&bf);
    graph.addEdgeToNode(&d,&de);
    graph.addEdgeToNode(&e,&ef);

    BellmanFord bellmanFord;
    bellmanFord.bellmanFord(&graph,&a);

    bellmanFord.createSCCs(&graph);
*/
    /**
     * SSSPDAG
     */
    /*CNode a; a.setName("1");
    CNode b; b.setName("2");
    CNode c; c.setName("3");
    CNode d; d.setName("4");
    CNode e; e.setName("5");

    CEdge ad(&a,&d,3);
    CEdge de(&d,&e,-2);
    CEdge eb(&e,&b,4);
    CEdge bc(&b,&c,1);
    CEdge ab(&a,&b,6);
    CEdge ac(&a,&c,11);
    CEdge dc(&d,&c,6);

    CGraph g;
    g.addNodesIntoGraph(&a);
    g.addNodesIntoGraph(&b);
    g.addNodesIntoGraph(&c);
    g.addNodesIntoGraph(&d);
    g.addNodesIntoGraph(&e);

    g.initNODES();
    g.addEdgeToNode(&a,&ad);
    g.addEdgeToNode(&a,&ab);
    g.addEdgeToNode(&a,&ac);
    g.addEdgeToNode(&b,&bc);
    g.addEdgeToNode(&d,&de);
    g.addEdgeToNode(&d,&dc);
    g.addEdgeToNode(&e,&eb);


    SingleSourceShortestPathInDAG ssspdag;
    ssspdag.SSSPDAG(&g,&a);

    for (auto & i : *g.getNodes()) {
        cout<<"node: "<<i->getName()
            <<" , " <<i->getDistance();
        if (i->getPredecessor() == nullptr){
            cout<<"/nil"<<endl;
        }else {
            cout<<"/" << i->getPredecessor()->getName()
                << endl;
        }
    }*/

    CNode a; a.setName("1");
    CNode b; b.setName("2");
    CNode c; c.setName("3");
    CNode d; d.setName("4");
    CNode e; e.setName("5");
    CNode f; f.setName("6");
    CNode g; g.setName("7");
    CNode h; h.setName("8");
    CNode i; i.setName("9");

    CEdge ab(&a,&b);
    CEdge ad(&a,&d);
    CEdge bc(&b,&c);
    CEdge be(&b,&e);
    CEdge cf(&c,&f);
    CEdge de(&d,&e);
    CEdge dg(&d,&g);
    CEdge ea(&e,&a);
    CEdge ei(&e,&i);
    CEdge fc(&f,&c);
    CEdge gi(&g,&i);
    CEdge hg(&h,&g);
    CEdge ih(&i,&h);

    CGraph graph;
    graph.addNodesIntoGraph(&a);
    graph.addNodesIntoGraph(&b);
    graph.addNodesIntoGraph(&c);
    graph.addNodesIntoGraph(&d);
    graph.addNodesIntoGraph(&e);
    graph.addNodesIntoGraph(&f);
    graph.addNodesIntoGraph(&g);
    graph.addNodesIntoGraph(&h);
    graph.addNodesIntoGraph(&i);

    graph.initNODES();
    graph.addEdgeToNode(&a,&ab);
    graph.addEdgeToNode(&a,&ad);
    graph.addEdgeToNode(&b,&bc);
    graph.addEdgeToNode(&b,&be);
    graph.addEdgeToNode(&c,&cf);
    graph.addEdgeToNode(&d,&de);
    graph.addEdgeToNode(&d,&dg);
    graph.addEdgeToNode(&e,&ea);
    graph.addEdgeToNode(&e,&ei);
    graph.addEdgeToNode(&f,&fc);
    graph.addEdgeToNode(&g,&gi);
    graph.addEdgeToNode(&h,&hg);
    graph.addEdgeToNode(&i,&ih);

    CGraph invertedGraph;
    StronglyConnectedComponents scc;

    scc.createSCCs(&graph, true);

    return 0;
}
