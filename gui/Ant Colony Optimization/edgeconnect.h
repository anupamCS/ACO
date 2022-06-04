//Header: edgeconnect.h
#pragma once
#include "Edge.h"
ref class edgeconnect
{
public:
	Edge^ edge;
	char direction;
	edgeconnect(void);
	edgeconnect(Edge^,char);
};

