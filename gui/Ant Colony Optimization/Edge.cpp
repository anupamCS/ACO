//Edge.cpp
#include "stdafx.h"
#include "Edge.h"
#include "Vertex.h"


Edge::Edge(void)
{}
Edge::Edge(System::Drawing::Point one,System::Drawing::Point two)
{
	v1=one;
	v2=two;
}
