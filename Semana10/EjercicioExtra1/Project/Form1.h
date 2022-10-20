#pragma once

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
	public:
		Form1(void)
		{
			InitializeComponent();
			Panel = this->CreateGraphics();
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

	private:
		
	Graphics^ Panel;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Timer^ timer1;

	private: System::ComponentModel::IContainer^ components;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(313, 182);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(596, 395);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &Form1::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::MyForm_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		//Esta parte del codigo se compila primero
		MessageBox::Show("Alerta");
	}
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		Pen^ Lapiz1 = gcnew Pen(Color::Red, 3);
		//Panel->DrawLine(Pen, x1, y1, x2, y2)
		Panel->DrawLine(Lapiz1, 40, 50, 150, 150);
		Panel->DrawLine(Lapiz1, 5, 5, 100, 10);

		/*1. hacer cuadrado lado 200 solamente con lineas */
		Panel->DrawLine(Lapiz1, 100, 100, 300, 100);
		Panel->DrawLine(Lapiz1, 300, 100, 300, 300);
		Panel->DrawLine(Lapiz1, 300, 300, 100, 300);
		Panel->DrawLine(Lapiz1, 100, 300, 100, 100);

		/*2.  implementar con for la serie de puntos*/
		Point Punto1(20, 20);
		Point Punto2(20, 200);

		for (int i = 1; i <= 10; i++) {
			Panel->DrawLine(Lapiz1, Punto1, Punto2);
			Punto1.X += 20;
			Punto2.X += 20;
		}

		/* 3. dibujar */
		for (int i = 1; i <= 10; i++) {
			Panel->DrawLine(Lapiz1, Punto1, Punto2);
			Punto2.X += 20;
		}

		Pen^ Lapiz2 = gcnew Pen(Color::Blue, 3);
		Panel->DrawRectangle(Lapiz2, 50, 50, 200, 150);

		/* 3. realizar un rectangulo en cada esquina de la ventana */
		int X = 50;
		int Y = 50;
		int Ancho = 200;
		int Alto = 150;

		SolidBrush^ Brocha1 = gcnew SolidBrush(Color::Aquamarine);
		Panel->FillRectangle(Brocha1, 52, 52, 197, 147);

		/*4  serie de rectangulos*/
		for (int i = 1; i <= 10; i++) {
			Panel->DrawRectangle(Lapiz2, X, Y, Ancho, Alto);
			X += 10;
			Y += 10;
		}

		/*5  serie de rectangulos*/
		X = 250;
		Y = 250;
		Ancho = 20;
		Alto = 15;
		for (int i = 1; i <= 10; i++) {
			Panel->DrawRectangle(Lapiz2, X, Y, Ancho, Alto);
			X -= 10;
			Y -= 10;
			Ancho += 10;
			Alto += 10;
		}

		/*6  serie de rectangulos*/
		X = 250;
		Y = 250;
		Ancho = 20;
		Alto = 15;
		for (int i = 1; i <= 10; i++) {
			Panel->DrawRectangle(Lapiz2, X, Y, Ancho, Alto);
			X -= 10;
			Y -= 10;
			Ancho += 10*2;
			Alto += 10*2;
		}

		Pen^ Lapiz3 = gcnew Pen(Color::Green, 1);
		X = 50;
		Y = 50;
		Ancho = 200;
		Alto = 150;
		Panel->DrawRectangle(Lapiz2, X, Y, Ancho, Alto);
		Panel->DrawArc(Lapiz3,X, Y, Ancho, Alto, 180, 180.0);

		/*7  serie de arcos*/
		for (int i = 1; i <= 10; i++) {
			Pen^ Lapiz4;
			if (i % 2 != 0) Lapiz4 = gcnew Pen(Color::Yellow, 5);
			else Lapiz4 = gcnew Pen(Color::Green, 5);
			Panel->DrawArc(Lapiz4, X, Y, Ancho, Alto, 180, 180.0);
			X += 10;
			Y += 10;
			Ancho += 10;
			Alto += 10;
		}
		Panel->DrawEllipse(Lapiz3, X, Y, Ancho, Alto);

		/*8  serie de elipses*/
		for (int i = 1; i <= 10; i++){
			Panel->DrawEllipse(Lapiz3, X, Y, Ancho, Alto);
			X += 10;
			Y += 10;
			Ancho += 10;
			Alto += 10;
		}

		/*9. imagenes*/
		X = 250;
		Y = 50;
		Ancho = 300;
		Alto = 200;
		//Image^ UnaFotito = Image::FromFile("Perrito.jpg");
		Image^ UnaFotito = Image::FromFile("C:\\Users\\Abraham\\Downloads\\632051.png");
		Panel->DrawImage(UnaFotito, X, Y, Ancho, Alto);

		/*10. Letrero*/
		String^ Cadena = "Universidad";
		System::Drawing::Font^ TipoLetra = gcnew System::Drawing::Font("Arial", 16);
		SolidBrush^ Pincel1 = gcnew SolidBrush(Color::Red);
		Point Punto3(50, 50);
		Panel->DrawString(Cadena, TipoLetra, Pincel1, Punto3);
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		/* Usar enable para activar el evento*/
		MessageBox::Show("I'm a virus", "Troyano", MessageBoxButtons::YesNoCancel);
	}
};
}
