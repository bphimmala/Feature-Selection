#ifndef SEARCH_H
#define SEARCH_H
#include <queue>
#include "..\header\node.h"

Node Search(Node parent);
void expand(Node parentToExpand, priority_queue<Node> &frontier);

#endif