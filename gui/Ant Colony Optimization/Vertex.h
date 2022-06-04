// Header: Vertex.h
#pragma once
#include "edgeconnect.h"
ref class Vertex
{
public:
	System::Drawing::Point^ location;
	int number;
	System::Collections::Generic::List<edgeconnect^>^ connections;
	Vertex(void);
	Vertex(System::Drawing::Point^,int);
	System::Drawing::Rectangle getrectangle();
};

