//Header: Edge.h
#pragma once
ref class Edge
{
public:
	System::Drawing::Point v1;
	int weight;
	System::Drawing::Point v2;
	Edge(void);
	Edge(System::Drawing::Point,System::Drawing::Point);
};

