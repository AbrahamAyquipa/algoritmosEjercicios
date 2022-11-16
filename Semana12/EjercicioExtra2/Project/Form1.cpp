#include "Form1.h"
using namespace System;
using namespace System::Windows::Forms; [STAThread]

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Project::Form1());
}
