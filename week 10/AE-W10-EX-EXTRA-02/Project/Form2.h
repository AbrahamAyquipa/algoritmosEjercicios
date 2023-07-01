#pragma once
#include "Form3.h"
using namespace System::Media;

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BtnSiguiente;
	private: System::Windows::Forms::Button^ button1;
	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form2::typeid));
			this->BtnSiguiente = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// BtnSiguiente
			// 
			this->BtnSiguiente->BackColor = System::Drawing::Color::Transparent;
			this->BtnSiguiente->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BtnSiguiente.BackgroundImage")));
			this->BtnSiguiente->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->BtnSiguiente->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->BtnSiguiente->FlatAppearance->BorderSize = 0;
			this->BtnSiguiente->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->BtnSiguiente->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->BtnSiguiente->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnSiguiente->ForeColor = System::Drawing::Color::White;
			this->BtnSiguiente->Location = System::Drawing::Point(23, 74);
			this->BtnSiguiente->Name = L"BtnSiguiente";
			this->BtnSiguiente->Size = System::Drawing::Size(238, 115);
			this->BtnSiguiente->TabIndex = 0;
			this->BtnSiguiente->Text = L"Siguiente";
			this->BtnSiguiente->UseVisualStyleBackColor = false;
			this->BtnSiguiente->Click += gcnew System::EventHandler(this, &Form2::BtnSiguiente_Click);
			this->BtnSiguiente->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form2::BtnSiguiente_Paint);
			this->BtnSiguiente->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form2::BtnSiguiente_MouseDown);
			this->BtnSiguiente->MouseEnter += gcnew System::EventHandler(this, &Form2::BtnSiguiente_MouseEnter);
			this->BtnSiguiente->MouseLeave += gcnew System::EventHandler(this, &Form2::BtnSiguiente_MouseLeave);
			this->BtnSiguiente->MouseHover += gcnew System::EventHandler(this, &Form2::BtnSiguiente_MouseHover);
			this->BtnSiguiente->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form2::BtnSiguiente_MouseMove);
			this->BtnSiguiente->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form2::BtnSiguiente_MouseUp);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(108, 26);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Back";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(307, 235);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->BtnSiguiente);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form2";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void BtnSiguiente_Click(System::Object^ sender, System::EventArgs^ e) {
		Form3^ formulario3 = gcnew Form3();
		Hide();
		formulario3->ShowDialog();
		Show();
		//SoundPlayer^ player;
		//player->Stop();
		delete formulario3;
	}
	private: System::Void BtnSiguiente_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		BtnSiguiente->BackColor = Color::Transparent;
	}
	private: System::Void BtnSiguiente_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		BtnSiguiente->BackColor = Color::Transparent;
	}
	private: System::Void BtnSiguiente_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		BtnSiguiente->BackColor = Color::Transparent;
	}
	private: System::Void BtnSiguiente_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		BtnSiguiente->BackColor = Color::Transparent;
	}
	private: System::Void BtnSiguiente_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		BtnSiguiente->BackColor = Color::Transparent;
	}
	private: System::Void BtnSiguiente_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		BtnSiguiente->BackColor = Color::Transparent;
	}
	private: System::Void BtnSiguiente_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		BtnSiguiente->BackColor = Color::Transparent;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Hide();
	}
};
}
