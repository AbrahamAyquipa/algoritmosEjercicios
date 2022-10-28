#pragma once
#include "Hero.h"
#include "Enemy.h"

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmMain
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			g = pnlCanvas->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, pnlCanvas->ClientRectangle);
			bmpHero = gcnew Bitmap("Images/rojo.png");
			bmpMap = gcnew Bitmap("Images/fondo.png");
			bmpEnemy = gcnew Bitmap("Images/bruno.png");
			hero = new Hero(bmpHero->Width / 4, bmpHero->Height / 4);
			enemyH = new Enemy(bmpEnemy->Width / 4, bmpEnemy->Height / 4, 1);
			enemyV = new Enemy(bmpEnemy->Width / 4, bmpEnemy->Height / 4, 2);
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
	private: System::Windows::Forms::Panel^ pnlCanvas;
	protected:
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ bmpHero;
		Bitmap^ bmpMap;
		Bitmap^ bmpEnemy;
		Hero* hero;
		Enemy* enemyH;
		Enemy* enemyV;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlCanvas = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// pnlCanvas
			// 
			this->pnlCanvas->Location = System::Drawing::Point(0, 1);
			//this->pnlCanvas->Margin = System::Windows::Forms::Padding(2);
			this->pnlCanvas->Name = L"pnlCanvas";
			this->pnlCanvas->Size = System::Drawing::Size(692, 530);
			this->pnlCanvas->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// FrmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(692, 530);
			this->Controls->Add(this->pnlCanvas);
			//this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"FrmMain";
			this->Text = L"FrmMain";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::FrmMain_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Clear
		buffer->Graphics->Clear(Color::WhiteSmoke);
		//Move
		enemyH->move(buffer->Graphics);
		enemyV->move(buffer->Graphics);
		//Draw
															//dimensiones del fondo
		buffer->Graphics->DrawImage(bmpMap, 0, 0, bmpMap->Width * 2, bmpMap->Height * 2.2);
		hero->draw(buffer->Graphics, bmpHero);
		enemyH->draw(buffer->Graphics, bmpEnemy);
		enemyV->draw(buffer->Graphics, bmpEnemy);
		//Render
		buffer->Render(g);

	}
	private: System::Void FrmMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		switch (e->KeyCode) {
		case Keys::A:
			hero->move(buffer->Graphics, 'A'); break;
		case Keys::S:
			hero->move(buffer->Graphics, 'S'); break;
		case Keys::D:
			hero->move(buffer->Graphics, 'D'); break;
		case Keys::W:
			hero->move(buffer->Graphics, 'W'); break;
		}
	}
	};
}
