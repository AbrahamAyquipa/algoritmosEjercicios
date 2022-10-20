#pragma once
#include "Carrera.h"

namespace Figuras {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Rank
	/// </summary>
	public ref class Rank : public System::Windows::Forms::Form
	{
		Carrera* carrera;
	public:
		Rank(Carrera* carrera)
		{
			InitializeComponent();
			this->carrera = carrera;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Rank()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Rank
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(332, 319);
			this->Name = L"Rank";
			this->Text = L"Rank";
			this->Load += gcnew System::EventHandler(this, &Rank::Rank_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Rank::Rank_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Rank_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		carrera->mostrar(CreateGraphics());
	}
	private: System::Void Rank_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
