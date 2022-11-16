#pragma once
#include "Controller.h"
#include "File.h"
#include <ctime>
namespace Files {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmMain
	/// </summary>
	public ref class FrmMain : public System::Windows::Forms::Form
	{
	public:
		FrmMain(void)
		{
			InitializeComponent();
			srand(time(NULL));
			cont = 0;
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);
			bmpEnemy = gcnew Bitmap("Images/proton.png");
			controller = new Controller();
			file = new File();
			file->readData();
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ lblTime;
	private: System::Windows::Forms::Timer^ timerMain;
	private: System::Windows::Forms::Timer^ timerTime;
	private: System::Windows::Forms::Timer^ timerEnemies;
	private: System::ComponentModel::IContainer^ components;

	private:
		int cont;
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ bmpEnemy;
		Controller* controller;
		File* file;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblTime = (gcnew System::Windows::Forms::Label());
			this->timerMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerTime = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerEnemies = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(494, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Time";
			// 
			// lblTime
			// 
			this->lblTime->AutoSize = true;
			this->lblTime->Location = System::Drawing::Point(562, 51);
			this->lblTime->Name = L"lblTime";
			this->lblTime->Size = System::Drawing::Size(13, 13);
			this->lblTime->TabIndex = 1;
			this->lblTime->Text = L"0";
			// 
			// timerMain
			// 
			this->timerMain->Enabled = true;
			this->timerMain->Tick += gcnew System::EventHandler(this, &FrmMain::timerMain_Tick);
			// 
			// timerTime
			// 
			this->timerTime->Enabled = true;
			this->timerTime->Interval = 1000;
			this->timerTime->Tick += gcnew System::EventHandler(this, &FrmMain::timerTime_Tick);
			// 
			// timerEnemies
			// 
			this->timerEnemies->Tick += gcnew System::EventHandler(this, &FrmMain::timerEnemies_Tick);
			// 
			// FrmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(701, 572);
			this->Controls->Add(this->lblTime);
			this->Controls->Add(this->label1);
			this->Name = L"FrmMain";
			this->Text = L"FrmMain";
			this->Load += gcnew System::EventHandler(this, &FrmMain::FrmMain_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timerMain_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::WhiteSmoke);
		controller->moveEveything(buffer->Graphics);
		controller->drawEverything(buffer->Graphics, bmpEnemy);
		buffer->Render(g);

	}
	private: System::Void timerTime_Tick(System::Object^ sender, System::EventArgs^ e) {
		cont++;
		lblTime->Text = Convert::ToString(cont);
	}
	private: System::Void timerEnemies_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (controller->getEnemies() < 8) {
			controller->addEnemy(new Enemy(bmpEnemy->Width / 4, bmpEnemy->Height / 4, file->getX(), file->getY()));
		}
	}
private: System::Void FrmMain_Load(System::Object^ sender, System::EventArgs^ e) {
	timerEnemies->Interval = file->getN() * 1000;
	timerEnemies->Enabled = true;
}
};
}
