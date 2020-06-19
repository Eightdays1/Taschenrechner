#include "pch.h"
#include "Controller.h"

using namespace System;

//int main(array<System::String ^> ^args)
//{
//    return 0;
//}

#include "Form1.h"

using namespace System::Windows::Forms;

[STAThread]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew CppCLRWinformsProjekt::Form1()); 



	calculator::Controller c1;
	c1.init();

	return 0;
}