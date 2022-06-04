//Header: Form1.h
#pragma once
#include "Vertex.h"
#include "edgeweight.h"
//#include "Edge.h"
namespace AntColonyOptimization {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	/// <summary>
	/// Summary for Form1
	/// </summary>
	
	public ref class Form1 : public System::Windows::Forms::Form
	{
		//int count;	//for vertices numbering
		Vertex^ selectedvertex;
		Edge^ drawingedge;	//currently drawing edge
		Pen^ edgepen;	//for drawing edge lines
		Pen^ highlighter;
		List<Edge^>^ edges;	//list of all the edges displayed
		List<Vertex^>^ vertices;	//list of all the vertices displayed
		StringFormat^ center;	//for centering vertex number within vertex
		int **distance;
		List<Edge^>^ highlight;
		Vertex^ start;
		System::Drawing::Font^ vertextext;	//vertex number font


	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  removeToolStripMenuItem;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::ToolStripMenuItem^  removeEdgeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripStatusLabel^  spring;

	private: System::Windows::Forms::ToolStripStatusLabel^  mouselocation;

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button4;

	private: System::Windows::Forms::CheckBox^  checkBox2;

			 
	public:
		Form1(void)
		{
			InitializeComponent();
			this->FormBorderStyle=System::Windows::Forms::FormBorderStyle::FixedDialog;
			vertices= gcnew List<Vertex^>();
			edges=gcnew List<Edge^>();
			center=gcnew StringFormat();
			center->LineAlignment = StringAlignment::Center;
            center->Alignment = StringAlignment::Center;
			vertextext=gcnew System::Drawing::Font("Century Gothic",12,FontStyle::Bold);
			edgepen=gcnew Pen(Color::Black,2);
			highlighter=gcnew Pen(Color::Red,4);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->removeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeEdgeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->spring = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->mouselocation = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->contextMenuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox1->ContextMenuStrip = this->contextMenuStrip1;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(678, 357);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseUp);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->removeToolStripMenuItem, 
				this->removeEdgeToolStripMenuItem});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->ShowImageMargin = false;
			this->contextMenuStrip1->Size = System::Drawing::Size(122, 48);
			this->contextMenuStrip1->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::contextMenuStrip1_Opening);
			// 
			// removeToolStripMenuItem
			// 
			this->removeToolStripMenuItem->Name = L"removeToolStripMenuItem";
			this->removeToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->removeToolStripMenuItem->Text = L"Remove";
			this->removeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::removeToolStripMenuItem_Click);
			// 
			// removeEdgeToolStripMenuItem
			// 
			this->removeEdgeToolStripMenuItem->Name = L"removeEdgeToolStripMenuItem";
			this->removeEdgeToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->removeEdgeToolStripMenuItem->Text = L"Remove Edge";
			this->removeEdgeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::removeEdgeToolStripMenuItem_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->Appearance = System::Windows::Forms::Appearance::Button;
			this->checkBox1->AutoSize = true;
			this->checkBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->checkBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->checkBox1->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkBox1->Location = System::Drawing::Point(3, 3);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(55, 25);
			this->checkBox1->TabIndex = 1;
			this->checkBox1->Text = L"Vertex";
			this->checkBox1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->toolStripStatusLabel1, 
				this->spring, this->mouselocation});
			this->statusStrip1->Location = System::Drawing::Point(0, 430);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(702, 22);
			this->statusStrip1->TabIndex = 4;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(0, 17);
			// 
			// spring
			// 
			this->spring->Name = L"spring";
			this->spring->Size = System::Drawing::Size(656, 17);
			this->spring->Spring = true;
			// 
			// mouselocation
			// 
			this->mouselocation->Name = L"mouselocation";
			this->mouselocation->Size = System::Drawing::Size(0, 17);
			// 
			// checkBox2
			// 
			this->checkBox2->Appearance = System::Windows::Forms::Appearance::Button;
			this->checkBox2->AutoSize = true;
			this->checkBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->checkBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->checkBox2->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkBox2->Location = System::Drawing::Point(64, 3);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(55, 25);
			this->checkBox2->TabIndex = 5;
			this->checkBox2->Text = L"Edge";
			this->checkBox2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox2_CheckedChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(433, 398);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(93, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Distance Matrix";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(12, 375);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(128, 52);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Draw";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel1->Controls->Add(this->checkBox1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->checkBox2, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(3, 18);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(122, 31);
			this->tableLayoutPanel1->TabIndex = 6;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(168, 396);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 25);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Clear All";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(291, 396);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(90, 25);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Connect All";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(564, 397);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(117, 23);
			this->button4->TabIndex = 11;
			this->button4->Text = L"Start Simulation";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(702, 452);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->pictureBox1);
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ant Colony";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->contextMenuStrip1->ResumeLayout(false);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		Point^ dragp;	//offset point to maintain while dragging
		bool dragvertex;	//flag for dragging vertex
		bool drawedge;	//flag to indicate event drawing edge when drag from a vertex
		bool grabbed;	//flag for grabbing the end point of edge when drawing
		bool selected;	//flag for mouse over select vertex
		bool removingedge;	//flag to indicate event removing an edge;
		bool displayresult;
		Vertex^ grabbingvertex;
		//------mouse down event-----//
	private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		{
				if(removingedge)	//when deleting an edge
				{
					if(!selected)
					{
						MessageBox::Show("Select a Vertex","Vertex",MessageBoxButtons::OK,MessageBoxIcon::Error);
						return;
					}
					if(grabbingvertex==selectedvertex)	//if the same vertex is selected
					{
						MessageBox::Show("You selected the same Vertex","Edge",MessageBoxButtons::OK,MessageBoxIcon::Information);
						return;
					}
					edgeconnect ^e1,^e2;
					for(int i=0;i<selectedvertex->connections->Count;i++)
					{
						e1=selectedvertex->connections[i];
						for(int j=0;j<grabbingvertex->connections->Count;j++)
						{
							e2=grabbingvertex->connections[j];
							if(e1->edge==e2->edge)
							{
								edges->Remove(e1->edge);
								selectedvertex->connections->Remove(e1);
								grabbingvertex->connections->Remove(e2);
								//assigning -1 in the distance [][] where the edge was
								if(selectedvertex->number<grabbingvertex->number)
									distance[selectedvertex->number][grabbingvertex->number]=-1;
								else
									distance[grabbingvertex->number][selectedvertex->number]=-1;
								toolStripStatusLabel1->Text="";
								removingedge=false;
								return;
							}
						}
					}
					MessageBox::Show("No Edge exist b/w the 2 Vertices","Edge",MessageBoxButtons::OK,MessageBoxIcon::Error);
					return;
				}		
				if(contextMenuStrip1->Visible)
				{
					contextMenuStrip1->Visible=false;
					return;
				}
				 //select vertex if mouse down on any one
				 if(selected)
				 {
						if(!checkBox2->Checked)	//do not drag vertex when drawing edge
						{
							dragp=gcnew Point(e->X-selectedvertex->location->X,e->Y-selectedvertex->location->Y);
							dragvertex=true;
						}
						else if(checkBox2->Checked)
						{
								 grabbed=false;
								drawedge=true;
								drawingedge=gcnew Edge(Point(selectedvertex->location->X+10,selectedvertex->location->Y+10), Point(e->X,e->Y));
								//v->connections->Add(drawingedge->v1);	//adding the edge to the vertex edge collection
								edges->Add(drawingedge);
						}
						return;
				 }
				 //add vertex if vertex button is down
				 if(checkBox1->Checked&&e->Button==System::Windows::Forms::MouseButtons::Left)
				 {
					 selectedvertex=gcnew Vertex(gcnew Point(e->X-10,e->Y-10),vertices->Count);
					 selected=true;
					vertices->Add(selectedvertex);					
					if(vertices->Count>1)
					{
						int **temp;	//temp pointer to hold distance matrix b4 adding the new vertex
						temp=distance;
						//dynamically allocating space to distance mat of new size
						distance=new int * [vertices->Count];
						for(int i=0;i<vertices->Count;i++)
							distance[i]=new int [vertices->Count];
						//copy the values from temp matrix to distance matrix
						for(int i=0;i<vertices->Count;i++)
						{
							for(int j=0;j<vertices->Count;j++)
							{
								if(i<vertices->Count-1&&j<vertices->Count-1&&vertices->Count>2)
										distance[i][j]=temp[i][j];
								else
								{
									if(i<j)
										distance[i][j]=-1;
									else if(i==j)
										distance[i][j]=9999;
									else
										distance[i][j]=0;
								}
							}
						}
						delete temp;
					}
					//refreshing picturebox
					pictureBox1->Invalidate();
				 }
		}
			 //find mid point of edge to show the weight
		Point findmid(Edge^ e)
		{
			return( Point((e->v1.X+e->v2.X)/2,(e->v1.Y+e->v2.Y)/2));
		}
		//Point mid;
		//------DRAW ITEMS IN PICTUREBOX------//
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
		 {
			 //rendering in high quality settings
            e->Graphics->InterpolationMode = Drawing2D::InterpolationMode::HighQualityBicubic;
            e->Graphics->CompositingQuality = Drawing2D::CompositingQuality::HighQuality;
			e->Graphics->TextRenderingHint = System::Drawing::Text::TextRenderingHint::ClearTypeGridFit;
            e->Graphics->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
            e->Graphics->PixelOffsetMode = Drawing2D::PixelOffsetMode::HighQuality;

			//drawing all the edges
			for each(Edge^ x in edges)
			{
				e->Graphics->DrawLine(edgepen,x->v1,x->v2);
				if(!drawedge||(drawedge&&x!=drawingedge))
				{
					//mid=findmid(x);
					//e->Graphics->FillRectangle(Brushes::White,mid.X+2,mid.Y+2,20,20);
					e->Graphics->DrawString(Convert::ToString(x->weight),vertextext,Brushes::DeepSkyBlue,findmid(x));
				}
			}

			if(displayresult)
			{
				for each(Edge^ x in highlight)
				{
					e->Graphics->DrawLine(highlighter,x->v1,x->v2);
					e->Graphics->DrawString(Convert::ToString(x->weight),vertextext,Brushes::DeepSkyBlue,findmid(x));
				}
			}
			if(drawedge&&!grabbed)	//small circle at the dragging end when drawing a new edge
				e->Graphics->FillEllipse(Brushes::Orange,drawingedge->v2.X-5,drawingedge->v2.Y-5,10,10);

			 //drawing all the vertices in picturebox
			 for each(Vertex^ v in vertices)
			{
				if(drawedge&&grabbed&&v==grabbingvertex)	//vertex colour when grabbing edge
					e->Graphics->FillRectangle(Brushes::Orange,v->location->X,v->location->Y,20,20);
				else if(selected&&v==selectedvertex)	//vertex colour when mouse over i.e. selecting
					e->Graphics->FillRectangle(Brushes::LimeGreen,v->location->X,v->location->Y,20,20);
				else if(removingedge&&v==grabbingvertex)	//vertex colour of 1st vertex when removing edge
					e->Graphics->FillRectangle(Brushes::DeepSkyBlue,v->location->X,v->location->Y,20,20);
				else if(displayresult&&start==v)
					e->Graphics->FillRectangle(Brushes::Crimson,v->location->X,v->location->Y,20,20);				
				else										//normal vertex colour
					e->Graphics->FillRectangle(Brushes::White,v->location->X,v->location->Y,20,20);				
				e->Graphics->DrawRectangle(Pens::Black,v->location->X,v->location->Y,20,20);
				//adjusting vertices' number font according to its size
				System::Drawing::Font^ temp=vertextext;
				while(e->Graphics->MeasureString(Convert::ToString(v->number),temp).Width>=20)
					temp=gcnew System::Drawing::Font(temp->FontFamily,temp->Size-1,FontStyle::Bold);
				e->Graphics->DrawString(Convert::ToString(v->number),temp,Brushes::Black, RectangleF(v->location->X,v->location->Y,20,20),center);
			 }
		 }
		 //return true if any edge is connected b/w 2 vertices
		 Edge^ connected(Vertex^ v1,Vertex^ v2)
		 {
			 for each(edgeconnect^ e1 in v1->connections)
			 {
				 for each (edgeconnect^ e2 in v2->connections)
				 {
					 if(e1->edge==e2->edge)
						 return e1->edge;
				 }
			 }
			 return nullptr;
		 }
		  //-----------MOUSE MOVE----------//
private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		 {
			 mouselocation->Text="X: "+e->X+" Y: "+e->Y;	//shows mouse location in status bar

			 if(contextMenuStrip1->Visible)
					return;
			 //selecting vertex on mouse over
			 if(!drawedge&&!dragvertex)
			 {
				selected=false;
				for each(Vertex^ v in vertices)
				{
					//if the mouse location is inside an existing vertex
					if((gcnew Rectangle(v->location->X,v->location->Y,20,20))->Contains(e->X,e->Y))
					{
						selected=true;
						selectedvertex=v;
						break;
					}
				}
			 }
			//drag vertex
			 if(dragvertex&&pictureBox1->ClientRectangle.Contains(e->X,e->Y))
			 {
				 //changing location of the selected vertex to the mouse location
				selectedvertex->location=gcnew Point(e->X-dragp->X,e->Y-dragp->Y);
				for each(edgeconnect^ x in selectedvertex->connections)
				{
					switch(x->direction)
					{
						case 'i':
							x->edge->v2=Point(selectedvertex->location->X+10,selectedvertex->location->Y+10);
						break;
						case 'o':
							x->edge->v1=Point(selectedvertex->location->X+10,selectedvertex->location->Y+10);
					}
				}		
			 }
			 else if(drawedge&&pictureBox1->ClientRectangle.Contains(e->X,e->Y))
			 {
				 //drawing the edge
				 for each(Vertex^ v in vertices)
				 {
					 if(v==selectedvertex||connected(v,selectedvertex))	//same vertex or connected vertex
							 continue;
					 if((v->getrectangle()).Contains(e->Location))	//dragging point of edge is within range of vertex
					 {
						 grabbingvertex=v;
						 grabbed=true;
						 break;
					 }
					 else
						 grabbed=false;
				 }
				 if(grabbed)
					 drawingedge->v2= Point(grabbingvertex->location->X+10,grabbingvertex->location->Y+10);
				 else
					drawingedge->v2=e->Location;
			 }
			 pictureBox1->Invalidate();
		 }
		 //-------------MOUSE UP---------//
private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		 {
			 if(drawedge&&!grabbed)	
				edges->Remove(drawingedge); //edge is remove if not connected properly
			 else if(drawedge&&grabbed)
		     {
				 connectnewedge("",selectedvertex,drawingedge,grabbingvertex);
			 }
			 //flags false when mouse up
			 dragvertex=false;			 
			 drawedge=false;
			 
		 }
		 void connectnewedge(String^ caption,Vertex^ vert1,Edge^ edge,Vertex^ vert2)
		 {
			 //pop-up dialoge box to give weight of the edge created
			  edgeweight^ w=gcnew edgeweight();
			  w->label1->Text=caption;
				 while(w->ShowDialog()!=System::Windows::Forms::DialogResult::OK);
				 edge->weight=(int)w->numericUpDown1->Value;
				 //adding edge to the vertices' connection list
				 vert1->connections->Add(gcnew edgeconnect(edge,'o'));
				 vert2->connections->Add(gcnew edgeconnect(edge,'i'));
				 //adding value to distance in upper triangular matrix way
				 if(vert1->number<vert2->number)
					 distance[vert1->number][vert2->number]=edge->weight;
				 else
					 distance[vert2->number][vert1->number]=edge->weight;
		 }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
		 {
			 if(checkBox1->Checked)
			 {
				 removingedge=false;
				 checkBox2->Checked=false;
				 toolStripStatusLabel1->Text="Click to add vertices";
			 }
			 else
				 toolStripStatusLabel1->Text="";
			 pictureBox1->Invalidate();
		 }
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
		 {
			 if(checkBox2->Checked)
			 {
				 removingedge=false;
				checkBox1->Checked=false;
				toolStripStatusLabel1->Text="Drag from one Vertex to another to draw an Edge";
			 }
			 else
				toolStripStatusLabel1->Text="";
			 pictureBox1->Invalidate();
		 }
private: System::Void contextMenuStrip1_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
		 {
			 if(!selected)
				 e->Cancel=true;
		 }
		 void removeedge(edgeconnect^ remove)
		 {
			 for each(Vertex^ v in vertices)
				 {
					 if(v==selectedvertex)
						 continue;
					 for(int i=0;i<v->connections->Count;i++)
					 {
						 if(v->connections[i]->edge==remove->edge)
						 {
							v->connections->Remove(v->connections[i]);
							return;
						 }
					 }
				 }
		 }
private: System::Void removeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 for each(edgeconnect^ x in selectedvertex->connections)
			 {
				 removeedge(x);
				 edges->Remove(x->edge);
			 }
			 //deleting row and column from distance[][] and shifting the other vertices;
			 int **temp=distance;
			 //making new distance[][] of new size
			 distance=new int * [vertices->Count-1];
			 for(int i=0;i<vertices->Count-1;i++)
				 distance[i]=new int [vertices->Count-1];
			 //copy values from temp[][] to distance[][]
			 for(int i=0, r=0;i<vertices->Count;i++)
			 {
				 if(i==selectedvertex->number)
					 continue;
				 for(int j=0, c=0;j<vertices->Count;j++)
				 {
					 if(j!=selectedvertex->number)
					 distance[r][c++]=temp[i][j];
				 }
				 r++;
			 }
			 delete temp;
			 //decrement the vertices number greater than deleting vertex
			 for(int i=selectedvertex->number+1;i<vertices->Count;i++)
				 vertices[i]->number-=1;
			 //remove from vertices list
			 vertices->Remove(selectedvertex);
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 if(vertices->Count<2)
			 {
				 MessageBox::Show("SERIOUSLY?\nWHAT ARE YOU EXPECTING TO SEE");
				 return;
			 }
			 String^ text="";
			 for(int i=0;i<vertices->Count;i++)
			 {
				 for(int j=0;j<vertices->Count;j++)
					 text+=distance[i][j]+" ";
				 text+="\n";
			 }
			 MessageBox::Show(text);
		 }
private: System::Void removeEdgeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 if(selectedvertex->connections->Count==0)
			 {
				 MessageBox::Show("No Edge is connected to the Vertex","Edge",MessageBoxButtons::OK,MessageBoxIcon::Information);
				 return;
			 }
			 checkBox1->Checked=false;
			 checkBox2->Checked=false;
			 toolStripStatusLabel1->Text="Select the Vertex from which you want to remove the Edge";
			 grabbingvertex=selectedvertex;
			 removingedge=true;
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 //set all flags to false
			 removingedge=dragvertex=drawedge=grabbed=selected=false;
			 //unchecking the vertex and edge buttons
			 checkBox1->Checked=false;
			 checkBox2->Checked=false;
			 //removing vertices and edges from lists
			 vertices->Clear();
			 edges->Clear();
			 //intializing distance [][]
			 distance=new int *();
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			for(int i=0;i<vertices->Count;i++)
			{
				for(int j=i+1;j<vertices->Count;j++)
				{
					if(!connected(vertices[i],vertices[j]))
					{
						selected=true;
						selectedvertex=vertices[i];
						drawedge=grabbed=true;
						grabbingvertex=vertices[j];
						pictureBox1->Invalidate();
						drawingedge=gcnew Edge(Point(vertices[i]->location->X+5,vertices[i]->location->Y+5),Point(vertices[j]->location->X+5,vertices[j]->location->Y+5));
						connectnewedge("Vertex "+selectedvertex->number+" to Vertex "+grabbingvertex->number,selectedvertex,drawingedge,grabbingvertex);
						edges->Add(drawingedge);
						selected=grabbed=drawedge=false;
						pictureBox1->Invalidate();
					}
				}
			}
		 }
		 
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 for(int i=0;i<vertices->Count;i++)
			 {
				 for(int j=i+1;j<vertices->Count;j++)
				 {
					 if(!connected(vertices[i],vertices[j]))
					 {
						 MessageBox::Show("Vertex "+vertices[i]->number+" is not connected to "+vertices[j]->number,"Not Connected",MessageBoxButtons::OK,MessageBoxIcon::Error);
						 return;
					 }
				 }
			 }

			 IO::StreamWriter^ data=gcnew IO::StreamWriter("C:\\Users\\Anupam\\Documents\\ACO\\data.txt");			 
			 data->WriteLine("Number of Vertices");
			 data->WriteLine(Convert::ToString(vertices->Count));
			 data->WriteLine("Distance");
			 String ^text;
			 for(int i=0;i<vertices->Count;i++)
			 {
				 text="";
				 for(int j=0;j<vertices->Count;j++)
					 text+=distance[i][j]+" ";
				 data->WriteLine(text);
			 }
			 data->Close();
			 Diagnostics::Process::Start("C:\\Users\\Anupam\\Documents\\ACO\\AntColony.exe");

			 while(!File::Exists("C:\\Users\\Anupam\\Documents\\ACO\\read_tour.txt"));
			 Threading::Thread::Sleep(1000);
			 //List<Vertex^>^ final=gcnew List<Vertex^>();
			 highlight=gcnew List<Edge^>();
			 StreamReader^ sr=gcnew StreamReader("C:\\Users\\Anupam\\Documents\\ACO\\read_tour.txt");
			 String ^tour=sr->ReadLine();
			 MessageBox::Show("Best possible tour: "+tour+"\nBest possible tour length: "+sr->ReadLine());
			 array<String^>^ t=tour->Split(' ');
			 start=vertices[int::Parse(t[0])];
			 for(int i=0;i<vertices->Count;i++)
				 highlight->Add(connected(vertices[int::Parse(t[i])],vertices[int::Parse(t[i+1])]));
			 displayresult=true;
			 pictureBox1->Invalidate();
			 sr->Close();
			 File::Delete("C:\\Users\\Anupam\\Documents\\ACO\\read_tour.txt");
			 
		 }
};
}
