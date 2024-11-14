#ifndef SEARCH_H
#define SEARCH_H
#include "..\header\node.h"
#include <queue>

Node Search(Node parent);
void expand(Node parentToExpand, priority_queue<Node> &frontier);

#endif