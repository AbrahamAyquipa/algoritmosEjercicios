#pragma once
#include "Hero.h"
#include "Controller.h"
#include <ctime>

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmMain
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			srand(time(NULL));
			g = pnlCanvas->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, pnlCanvas->ClientRectangle);
			bmpHero = gcnew Bitmap("Images/rojo.png");
			bmpEnemy = gcnew Bitmap("Images/bruno.png");
			bmpMap = gcnew Bitmap("Images/fondo.png");
			bmpBullet = gcnew Bitmap("Images/pokeball.png");
			hero = new Hero(bmpHero->Width / 4, bmpHero->Height / 4);
			controller = new Controller();
			controller->createEnemies(bmpEnemy->Width / 4, bmpEnemy->Height / 4);
		}
	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Panel^ pnlCanvas;
	protected:
	private: System::ComponentModel::IContainer^ components;
	private:
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ bmpHero;
		Bitmap^ bmpEnemy;
		Bitmap^ bmpMap;
		Bitmap^ bmpBullet;
		Hero* hero;
		Controller* controller;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlCanvas = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// pnlCanvas
			// 
			this->pnlCanvas->Location = System::Drawing::Point(-2, -1);
			this->pnlCanvas->Name = L"pnlCanvas";
			this->pnlCanvas->Size = System::Drawing::Size(745, 429);
			this->pnlCanvas->TabIndex = 0;
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(744, 428);
			this->Controls->Add(this->pnlCanvas);
			this->Name = L"frmMain";
			this->Text = L"frmMain";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::presionar);
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//clear
		buffer->Graphics->Clear(Color::WhiteSmoke);
		//collision
		controller->collision(buffer->Graphics);
		//move para el personaje se hara con teclas
		controller->moveEveryThing(buffer->Graphics);
		//draw
		buffer->Graphics->DrawImage(bmpMap, 0, 0, bmpMap->Width * 2.2, bmpMap->Height * 1.8);
		controller->drawEveryThing(buffer->Graphics, bmpEnemy, bmpBullet);
		hero->draw(buffer->Graphics, bmpHero);
		//Render
		buffer->Render(g);
	}

	private: System::Void presionar(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::A:
			hero->move(buffer->Graphics, 'A'); break;
		case Keys::D:
			hero->move(buffer->Graphics, 'D'); break;
		case Keys::S:
			hero->move(buffer->Graphics, 'S'); break;
		case Keys::W:
			hero->move(buffer->Graphics, 'W'); break;
		case Keys::Space:
			Bullet* b = new Bullet(hero->getX(), hero->getY(), bmpBullet->Width, bmpBullet->Height, hero->getDirection());
			controller->addBullet(b);

		}
	}
	};
}
