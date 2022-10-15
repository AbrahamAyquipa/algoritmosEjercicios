#pragma once
#include "Form2.h"

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;



	private: System::Windows::Forms::Label^ LblRespuesta;
	private: System::Windows::Forms::TextBox^ TxtNombre;
	private: System::Windows::Forms::Button^ BtnPreguntar;









	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->LblRespuesta = (gcnew System::Windows::Forms::Label());
			this->TxtNombre = (gcnew System::Windows::Forms::TextBox());
			this->BtnPreguntar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(110, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombre:";
			// 
			// LblRespuesta
			// 
			this->LblRespuesta->AutoSize = true;
			this->LblRespuesta->Location = System::Drawing::Point(76, 198);
			this->LblRespuesta->Name = L"LblRespuesta";
			this->LblRespuesta->Size = System::Drawing::Size(35, 13);
			this->LblRespuesta->TabIndex = 3;
			this->LblRespuesta->Text = L"label2";
			// 
			// TxtNombre
			// 
			this->TxtNombre->Location = System::Drawing::Point(42, 90);
			this->TxtNombre->Name = L"TxtNombre";
			this->TxtNombre->Size = System::Drawing::Size(200, 20);
			this->TxtNombre->TabIndex = 4;
			// 
			// BtnPreguntar
			// 
			this->BtnPreguntar->Location = System::Drawing::Point(98, 130);
			this->BtnPreguntar->Name = L"BtnPreguntar";
			this->BtnPreguntar->Size = System::Drawing::Size(75, 23);
			this->BtnPreguntar->TabIndex = 5;
			this->BtnPreguntar->Text = L"Preguntar";
			this->BtnPreguntar->UseVisualStyleBackColor = true;
			this->BtnPreguntar->Click += gcnew System::EventHandler(this, &Form1::BtnPreguntar_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->BtnPreguntar);
			this->Controls->Add(this->TxtNombre);
			this->Controls->Add(this->LblRespuesta);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion
		private: System::Void BtnPreguntar_Click(System::Object^ sender, System::EventArgs^ e) {
			Form2^ FormularioVotacion = gcnew Form2();
			FormularioVotacion->MuestraNombre(TxtNombre->Text);
      
			//Show SI permite retroceder
			//ShowDialog NO permite retroceder
			FormularioVotacion->ShowDialog();
			String^ respuesta = FormularioVotacion->retornaVoto();
			LblRespuesta->Text = TxtNombre->Text + " Ha votado por el " + respuesta;
		}
};
}
