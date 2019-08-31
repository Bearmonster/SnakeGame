#pragma once
#include <cstdlib>
#include<math.h>
#include"Settings.h"
#include"Circle.h"
#include "Imput.h"
using namespace std; 
namespace Snake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();
			gcnew Settings();//lingking setting

			gameTimer->Interval = Settings::GetSpeed();
			gameTimer->Start();
			
			startGame();
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pbCanvas;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ gameTimer;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		//creating a list of array
		System::Collections::Generic::List<Circle^>^ snake = gcnew System::Collections::Generic::List<Circle^>();
		//creating food object
		//Circle^ head = gcnew Circle(10, 5);
		Circle^  food = gcnew Circle();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pbCanvas = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->gameTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbCanvas))->BeginInit();
			this->SuspendLayout();
			// 
			// pbCanvas
			// 
			this->pbCanvas->BackColor = System::Drawing::Color::Gray;
			this->pbCanvas->Location = System::Drawing::Point(13, 13);
			this->pbCanvas->Name = L"pbCanvas";
			this->pbCanvas->Size = System::Drawing::Size(365, 372);
			this->pbCanvas->TabIndex = 0;
			this->pbCanvas->TabStop = false;
			this->pbCanvas->Click += gcnew System::EventHandler(this, &MyForm::PbCanvas_Click);
			this->pbCanvas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::updateGraphics);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Control;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(384, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Score:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::Label1_Click);
			// 
			// gameTimer
			// 
			this->gameTimer->Enabled = true;
			this->gameTimer->Interval = 1000;
			this->gameTimer->Tick += gcnew System::EventHandler(this, &MyForm::GameTimer_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::Control;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(384, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 24);
			this->label2->TabIndex = 2;
			this->label2->Text = L"00";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Yellow;
			this->label3->Location = System::Drawing::Point(131, 161);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(95, 24);
			this->label3->TabIndex = 3;
			this->label3->Text = L"End Text";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label3->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(492, 391);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pbCanvas);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::keyisdown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::keyisup);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbCanvas))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void movePlayer()
		{
			//main loop
			for (int i = snake->Count - 1; i >= 0; i--)
			{
				if (i == 0)
				{
					switch (Settings::GetDirection())
					{
					case Settings::Directions::Right:
						snake[i]->SetX(snake[i]->GetX() + Settings::GetWidth());
						break;
					case Settings::Directions::Left:
						snake[i]->SetX(snake[i]->GetX() - Settings::GetWidth());
						break;
					case Settings::Directions::Down:
						snake[i]->SetY(snake[i]->GetY() + Settings::GetHeight());
						break;
					case Settings::Directions::Up:
						snake[i]->SetY(snake[i]->GetY() - Settings::GetHeight());
						break;
					default:
						break;
					}
					int maxXpos = pbCanvas->Size.Width;
					int maxYpos = pbCanvas->Size.Height;
					if (snake[i]->GetX() < 0 || snake[i]->GetY() < 0 || snake[i]->GetX() > maxXpos - Settings::GetWidth() || snake[i]->GetY() > maxYpos - Settings::GetHeight())
					{
						die();
					}
					for (int j = 1; j < snake->Count; j++)
					{
						if (snake[i]->GetX() == snake[j]->GetX() && snake[i]->GetY() == snake[j]->GetY())
						{
							die();
						}
					}

					if (sqrt((snake[i]->GetX() - food->GetX()) * (snake[i]->GetX() - food->GetX()) + (snake[i]->GetY() - food->GetY()) * (snake[i]->GetY() - food->GetY())) < 16)
					{
						eat();
					}
				}
				else
				{		
					snake[i]->SetX(snake[i - 1]->GetX() );
					snake[i]->SetY(snake[i - 1]->GetY());
				}
			}
		}
	private: System::Void keyisdown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
	{
		Imput::changeState(e->KeyCode, true);
	}
	private: System::Void keyisup(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
	{
		Imput::changeState(e->KeyCode, false);
	}
	private: System::Void updateGraphics(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)	
	{
		//this is wher we will se the snake moving
		Graphics^ canvas = e->Graphics;// create a new graphics class
		if (Settings::GetGameover() == false)
		{
			//if game is not over
			Brush^ snakeColour; //create a new brush
			for (int i = 0; i < snake->Count; i++)
			{
				if (i == 0)
				{
					//head is black
					snakeColour = Brushes::Black;
				}
				else
				{
					//body is green
					snakeColour = Brushes::Green;
				}
				Rectangle rect =  Rectangle(snake[i]->GetX(), snake[i]->GetY(), Settings::GetWidth(), Settings::GetHeight());
				canvas->FillEllipse(snakeColour, rect);//draws snake's body
				Rectangle rect1 = Rectangle(food->GetX(), food->GetY(), Settings::GetWidth(), Settings::GetHeight());
				canvas->FillEllipse(Brushes::Red, rect1);//draws the food
			}
		}
		else
		{
			label3->Text = "Game Over\n Final score is " + Convert::ToString(Settings::GetScore()) + "\n Press Enter to Restart\n";
			label3->Visible = true;
		}

	}
	private: System::Void startGame()
	{
		label3->Visible = false;
		gcnew Settings();
		snake->Clear();
		Circle^ head = gcnew Circle(17, 17);
		snake->Add(head);
		label2->Text = Convert::ToString(Settings::GetScore());
		GenerateFood();
	}
	private:System::Void GenerateFood()
	{
		int maxXpos = pbCanvas->Size.Width;
		int maxYpos = pbCanvas->Size.Height;
		food = gcnew Circle(rand() % (maxXpos - Settings::GetWidth()), rand() % (maxYpos - Settings::GetHeight()));
	}
	private:System::Void die()
	{
		Settings::SetGameOver(true);
	}
	private:System::Void eat()
	{
		int x = 0, y = 0;
		switch (Settings::GetDirection())
		{
		case Settings::Directions::Right:
			x = -10;
			break;
		case Settings::Directions::Left:
			x = 10;
			break;
		case Settings::Directions::Down:
			y = -10;
			break;
		case Settings::Directions::Up:
			y = 10;
			break;
		}
		Circle^ body = gcnew Circle(snake[snake->Count - 1]->GetX() + x, snake[snake->Count-1]->GetY() + y);
		snake->Add(body);
		Settings::SetScore(Settings::GetScore() + Settings::GetPoints());
		label2->Text = Convert::ToString(Settings::GetScore());
		GenerateFood();
	}
	private: System::Void PbCanvas_Click(System::Object^ sender, System::EventArgs^ e) 
	{
	}
	private: System::Void GameTimer_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		if (Settings::GetGameover() == true)
		{
			if (Imput::KeyPress(Keys::Enter))
			{
				
				startGame();
			}
		}
		else
		{
			
			if (Imput::KeyPress(Keys::Right) && Settings::GetDirection() != Settings::Directions::Left)
			{
				Settings::SetDirection(Settings::Directions::Right);
			}
			else if (Imput::KeyPress(Keys::Left) && Settings::GetDirection() != Settings::Directions::Right)
			{
				Settings::SetDirection(Settings::Directions::Left);
			}
			else if(Imput::KeyPress(Keys::Up) && Settings::GetDirection() != Settings::Directions::Down)
			{
				Settings::SetDirection(Settings::Directions::Up);
			}
			else if (Imput::KeyPress(Keys::Down) && Settings::GetDirection() != Settings::Directions::Up)
			{
				Settings::SetDirection(Settings::Directions::Down);
			}
			movePlayer();
		}
		pbCanvas->Invalidate();//update screen
	}
private: System::Void Label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
