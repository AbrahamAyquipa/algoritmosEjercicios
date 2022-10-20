#pragma once
#include "Carrera.h"
#include "Rank.h"

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		Carrera* carrera;
		Graphics^ g;
	public:
		Form1(void)
		{
			InitializeComponent();
			carrera = new Carrera();
			g = this->CreateGraphics();
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
	private: System::Windows::Forms::Timer^ clock;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->clock = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// clock
			// 
			this->clock->Enabled = true;
			this->clock->Interval = 50;
			this->clock->Tick += gcnew System::EventHandler(this, &Form1::clock_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(976, 507);
			this->Name = L"MyForm";
			this->Text = L"Mi carrera";
			this->Load += gcnew System::EventHandler(this, &Form1::MyForm_Load_1);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void clock_Tick(System::Object^ sender, System::EventArgs^ e) {

		carrera->mover();
		carrera->mostrar(g);
		if (carrera->getRound() == 10) {
			clock->Enabled = false;
			//(gcnew Rank(carrera))->ShowDialog();
		}
	}
	private: System::Void MyForm_Load_1(System::Object^ sender, System::EventArgs^ e) {

	}
	};
}
