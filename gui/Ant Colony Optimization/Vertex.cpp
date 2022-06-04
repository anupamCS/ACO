//Vertex.cpp
#include "stdafx.h"
#include "Vertex.h"

Vertex::Vertex(void)
{}
Vertex::Vertex(System::Drawing::Point^ loc,int n)
{
	location=loc;
	number=n;
	connections= gcnew System::Collections::Generic::List<edgeconnect^>();
}
System::Drawing::Rectangle Vertex::getrectangle()
{
	return(System::Drawing::Rectangle(this->location->X-5,this->location->Y-5,30,30));
}
