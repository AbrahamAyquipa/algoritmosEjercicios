#pragma once

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
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
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ LblNombre;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ BtnSi;
	private: System::Windows::Forms::Button^ BtnNo;



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
			this->LblNombre = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->BtnSi = (gcnew System::Windows::Forms::Button());
			this->BtnNo = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(111, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Votacion";
			// 
			// LblNombre
			// 
			this->LblNombre->AutoSize = true;
			this->LblNombre->Location = System::Drawing::Point(108, 87);
			this->LblNombre->Name = L"LblNombre";
			this->LblNombre->Size = System::Drawing::Size(39, 13);
			this->LblNombre->TabIndex = 0;
			this->LblNombre->Text = L"Label3";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(88, 138);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"¿Cual es tu voto\?";
			// 
			// BtnSi
			// 
			this->BtnSi->Location = System::Drawing::Point(38, 170);
			this->BtnSi->Name = L"BtnSi";
			this->BtnSi->Size = System::Drawing::Size(75, 23);
			this->BtnSi->TabIndex = 1;
			this->BtnSi->Text = L"Si";
			this->BtnSi->UseVisualStyleBackColor = true;
			this->BtnSi->Click += gcnew System::EventHandler(this, &Form2::BtnSi_Click);
			// 
			// BtnNo
			// 
			this->BtnNo->Location = System::Drawing::Point(173, 170);
			this->BtnNo->Name = L"BtnNo";
			this->BtnNo->Size = System::Drawing::Size(75, 23);
			this->BtnNo->TabIndex = 1;
			this->BtnNo->Text = L"No";
			this->BtnNo->UseVisualStyleBackColor = true;
			this->BtnNo->Click += gcnew System::EventHandler(this, &Form2::BtnNo_Click);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->BtnNo);
			this->Controls->Add(this->BtnSi);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->LblNombre);
			this->Controls->Add(this->label1);
			this->Name = L"Form2";
			this->Text = L"Form2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
	public:
		short voto = 0;

		//Los tipos de variables que empiezan con mayuscula es porque pertenecen a web forms

		void MuestraNombre(String^ nombre) {
			LblNombre->Text = "Hola " + nombre;
		}

		//String^ = puntero a string
		String^ retornaVoto() {
			if (voto == 1) return "Si";
			if (voto == 2) return "No";
		}

		private: System::Void BtnSi_Click(System::Object^ sender, System::EventArgs^ e) {
			voto = 1;
			this->Close();
		}
		private: System::Void BtnNo_Click(System::Object^ sender, System::EventArgs^ e) {
			voto = 2;
			this->Close();
		}
};
}
