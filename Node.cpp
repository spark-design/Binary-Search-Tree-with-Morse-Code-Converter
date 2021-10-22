#include "Node.h"
#include <iostream>

using namespace::std;

int Node::degree()
{
    int childCnt = 0;

	if (left != nullptr)
    {
        childCnt++;
    }

    if (right != nullptr)
    {
        childCnt++;
    }

    return childCnt;
}