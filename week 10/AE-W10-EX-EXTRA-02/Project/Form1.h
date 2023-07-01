#pragma once
#include "Form2.h"
using namespace System::Media;

#define ancho_form 800;
#define alto_form 800;

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
			//inicializar player
			player = gcnew SoundPlayer();
			player->SoundLocation = ("C:\\Users\\Abraham\\Downloads\\music.wav");
			player->Load();
			player->PlayLooping();
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
	private: System::Windows::Forms::ProgressBar^ ProgressBar1;
	protected:

	private: System::Windows::Forms::Label^ Lbl1;

	private: System::Windows::Forms::Button^ BtnIniciar;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>	
		
		SoundPlayer^ player;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->ProgressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->Lbl1 = (gcnew System::Windows::Forms::Label());
			this->BtnIniciar = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// ProgressBar1
			// 
			this->ProgressBar1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ProgressBar1->ForeColor = System::Drawing::Color::YellowGreen;
			this->ProgressBar1->Location = System::Drawing::Point(47, 219);
			this->ProgressBar1->Name = L"ProgressBar1";
			this->ProgressBar1->Size = System::Drawing::Size(189, 15);
			this->ProgressBar1->TabIndex = 0;
			// 
			// Lbl1
			// 
			this->Lbl1->AutoSize = true;
			this->Lbl1->Location = System::Drawing::Point(46, 239);
			this->Lbl1->Name = L"Lbl1";
			this->Lbl1->Size = System::Drawing::Size(21, 13);
			this->Lbl1->TabIndex = 1;
			this->Lbl1->Text = L"0%";
			// 
			// BtnIniciar
			// 
			this->BtnIniciar->Location = System::Drawing::Point(105, 155);
			this->BtnIniciar->Name = L"BtnIniciar";
			this->BtnIniciar->Size = System::Drawing::Size(75, 23);
			this->BtnIniciar->TabIndex = 2;
			this->BtnIniciar->Text = L"Iniciar";
			this->BtnIniciar->UseVisualStyleBackColor = true;
			this->BtnIniciar->Click += gcnew System::EventHandler(this, &Form1::BtnIniciar_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->BtnIniciar);
			this->Controls->Add(this->Lbl1);
			this->Controls->Add(this->ProgressBar1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: System::Void BtnIniciar_Click(System::Object^ sender, System::EventArgs^ e) {
		Form2^ formulario2 = gcnew Form2();
		Hide();
		formulario2->ShowDialog();
		Show();
		delete formulario2;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//incrementar de 1 en 1
		ProgressBar1->Increment(5);
		//concatenar el label con el signo %
		Lbl1->Text = ProgressBar1->Value + ("%");
		if (ProgressBar1->Value == 100) Lbl1->Text = "COMPLETADO!!!";
	}
};
}
