#pragma once

namespace Project3 {

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
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ BtnMiboton;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::GroupBox^ Gb1;
	private: System::Windows::Forms::Button^ BtnSumar;
	private: System::Windows::Forms::TextBox^ TxtNumero1;
	private: System::Windows::Forms::TextBox^ TxtNumero2;
	private: System::Windows::Forms::TextBox^ TxtSuma;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->BtnMiboton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Gb1 = (gcnew System::Windows::Forms::GroupBox());
			this->BtnSumar = (gcnew System::Windows::Forms::Button());
			this->TxtNumero1 = (gcnew System::Windows::Forms::TextBox());
			this->TxtNumero2 = (gcnew System::Windows::Forms::TextBox());
			this->TxtSuma = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(110, 193);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(149, 20);
			this->textBox1->TabIndex = 1;
			// 
			// BtnMiboton
			// 
			this->BtnMiboton->Location = System::Drawing::Point(133, 80);
			this->BtnMiboton->Name = L"BtnMiboton";
			this->BtnMiboton->Size = System::Drawing::Size(126, 69);
			this->BtnMiboton->TabIndex = 2;
			this->BtnMiboton->Text = L"Botón";
			this->BtnMiboton->UseVisualStyleBackColor = true;
			this->BtnMiboton->Click += gcnew System::EventHandler(this, &Form1::BtnMiboton_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(330, 85);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(129, 63);
			this->button1->TabIndex = 3;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Gb1
			// 
			this->Gb1->Location = System::Drawing::Point(54, 247);
			this->Gb1->Name = L"Gb1";
			this->Gb1->Size = System::Drawing::Size(192, 161);
			this->Gb1->TabIndex = 4;
			this->Gb1->TabStop = false;
			this->Gb1->Text = L"Grupo de botones";
			// 
			// BtnSumar
			// 
			this->BtnSumar->Location = System::Drawing::Point(330, 193);
			this->BtnSumar->Name = L"BtnSumar";
			this->BtnSumar->Size = System::Drawing::Size(130, 60);
			this->BtnSumar->TabIndex = 5;
			this->BtnSumar->Text = L"Suma";
			this->BtnSumar->UseVisualStyleBackColor = true;
			this->BtnSumar->Click += gcnew System::EventHandler(this, &Form1::BtnSumar_Click);
			// 
			// TxtNumero1
			// 
			this->TxtNumero1->Location = System::Drawing::Point(377, 321);
			this->TxtNumero1->Name = L"TxtNumero1";
			this->TxtNumero1->Size = System::Drawing::Size(159, 20);
			this->TxtNumero1->TabIndex = 6;
			// 
			// TxtNumero2
			// 
			this->TxtNumero2->Location = System::Drawing::Point(379, 360);
			this->TxtNumero2->Name = L"TxtNumero2";
			this->TxtNumero2->Size = System::Drawing::Size(156, 20);
			this->TxtNumero2->TabIndex = 7;
			// 
			// TxtSuma
			// 
			this->TxtSuma->Location = System::Drawing::Point(377, 401);
			this->TxtSuma->Name = L"TxtSuma";
			this->TxtSuma->Size = System::Drawing::Size(156, 20);
			this->TxtSuma->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(305, 327);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Número 1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(305, 360);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Número 2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(305, 404);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(34, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Suma";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(635, 655);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->TxtSuma);
			this->Controls->Add(this->TxtNumero2);
			this->Controls->Add(this->TxtNumero1);
			this->Controls->Add(this->BtnSumar);
			this->Controls->Add(this->Gb1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->BtnMiboton);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Mi Formulario Algortimos";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnMiboton_Click(System::Object^ sender, System::EventArgs^ e) {

		Random^ r = gcnew Random();
		//definir y crear un botón
		Button^ Miboton = gcnew Button();
		Miboton->Left = r->Next(this->ClientSize.Width);
		Miboton->Top = r->Next(this->ClientSize.Height);

		Miboton->Text = "Hola";
		Miboton->Parent = Gb1;

		BtnMiboton->Text = "Soy el mismo botón";
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		TextBox^ Text = gcnew TextBox();
		Text->Left = 50;
		Text->Top = 80;
		Text->Parent = this;
	}
	private: System::Void BtnSumar_Click(System::Object^ sender, System::EventArgs^ e) {
		double n1, n2, n3;

		if (TxtNumero1->Text == "")
			MessageBox::Show("Ingresar dato");
		else {
			n1 = Convert::ToDouble(TxtNumero1->Text);
			n2 = Convert::ToDouble(TxtNumero2->Text);
			n3 = n1 + n2;
			TxtSuma->Text = Convert::ToString(n3);
		}
	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
