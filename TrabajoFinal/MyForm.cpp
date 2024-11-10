#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

void main() 
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    TrabajoFinal::MyForm^ myForm = gcnew TrabajoFinal::MyForm();  
    myForm->Width = 1302;//1272
    myForm->Height = 896;

    Application::Run(myForm);
}
