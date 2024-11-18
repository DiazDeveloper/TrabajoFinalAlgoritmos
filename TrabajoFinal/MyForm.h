#pragma once
#include "Juego.h"

namespace TrabajoFinal {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Media;

    public ref class MyForm : public System::Windows::Forms::Form
    {
        Graphics^ canvas;
        BufferedGraphicsContext^ context;
        BufferedGraphics^ buffer;
        Juego* juego;


    private:
        System::Windows::Forms::Button^ button1;
        System::Windows::Forms::Timer^ timer2;
        System::Windows::Forms::Button^ button2;
        System::Windows::Forms::Timer^ timer1;
        System::ComponentModel::IContainer^ components;

        // Variables para el seguimiento de las teclas
        bool keyWPressed;
        bool keyAPressed; 
        bool keySPressed;
    private: System::Windows::Forms::Timer^ TimerApoyoEscopeta;
           bool keyDPressed;
    private: System::Windows::Forms::Timer^ TimerApoyoPozos;
    private: System::Windows::Forms::Timer^ TimerApoyoBalasEnemigas;
    private: System::Windows::Forms::Timer^ TimerApoyoCreditos;
    private: System::Windows::Forms::Button^ BotonRegresar;



    public:
        SoundPlayer^ sonidoEscopeta = gcnew SoundPlayer("Images/shotgunEffect.wav");
        SoundPlayer^ sonidoOpening = gcnew SoundPlayer("Images/opening.wav"); 
        SoundPlayer^ AFHS = gcnew SoundPlayer("Images/AFHS.wav");
    private: System::Windows::Forms::Timer^ ApoyoMusica;
    public:

    public:
        SoundPlayer^ Himno = gcnew SoundPlayer("Images/Himno.wav");

        MyForm(void)
        {
            InitializeComponent();
            canvas = this->CreateGraphics();
            context = BufferedGraphicsManager::Current;
            buffer = context->Allocate(canvas, this->ClientRectangle);
            juego = new Juego(buffer->Graphics->VisibleClipBounds.Width, buffer->Graphics->VisibleClipBounds.Height);
            // Inicializar variables de teclas
            keyWPressed = false;
            keyAPressed = false;
            keySPressed = false;
            keyDPressed = false;

            // Asignar eventos de teclado
            this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
            this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);

            // Asegurar que el formulario pueda recibir eventos de teclado
            this->KeyPreview = true;
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
            delete juego;
        }

    private:
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
            this->TimerApoyoEscopeta = (gcnew System::Windows::Forms::Timer(this->components));
            this->TimerApoyoPozos = (gcnew System::Windows::Forms::Timer(this->components));
            this->TimerApoyoBalasEnemigas = (gcnew System::Windows::Forms::Timer(this->components));
            this->TimerApoyoCreditos = (gcnew System::Windows::Forms::Timer(this->components));
            this->BotonRegresar = (gcnew System::Windows::Forms::Button());
            this->ApoyoMusica = (gcnew System::Windows::Forms::Timer(this->components));
            this->SuspendLayout();
            // 
            // timer1
            // 
            this->timer1->Enabled = true;
            this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
            // 
            // button1
            // 
            this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
            this->button1->Location = System::Drawing::Point(581, 245);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(340, 91);
            this->button1->TabIndex = 0;
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // button2
            // 
            this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
            this->button2->Location = System::Drawing::Point(581, 375);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(340, 90);
            this->button2->TabIndex = 1;
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
            // 
            // timer2
            // 
            this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
            // 
            // TimerApoyoEscopeta
            // 
            this->TimerApoyoEscopeta->Interval = 1200;
            this->TimerApoyoEscopeta->Tick += gcnew System::EventHandler(this, &MyForm::TimerApoyoEscopeta_Tick);
            // 
            // TimerApoyoPozos
            // 
            this->TimerApoyoPozos->Interval = 1000;
            this->TimerApoyoPozos->Tick += gcnew System::EventHandler(this, &MyForm::TimerApoyoPozos_Tick);
            // 
            // TimerApoyoBalasEnemigas
            // 
            this->TimerApoyoBalasEnemigas->Interval = 4000;
            this->TimerApoyoBalasEnemigas->Tick += gcnew System::EventHandler(this, &MyForm::TimerApoyoBalasEnemigas_Tick);
            // 
            // TimerApoyoCreditos
            // 
            this->TimerApoyoCreditos->Tick += gcnew System::EventHandler(this, &MyForm::TimerApoyoCreditos_Tick);
            // 
            // BotonRegresar
            // 
            this->BotonRegresar->Enabled = false;
            this->BotonRegresar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BotonRegresar.Image")));
            this->BotonRegresar->Location = System::Drawing::Point(12, 12);
            this->BotonRegresar->Name = L"BotonRegresar";
            this->BotonRegresar->Size = System::Drawing::Size(160, 75);
            this->BotonRegresar->TabIndex = 2;
            this->BotonRegresar->UseVisualStyleBackColor = true;
            this->BotonRegresar->Visible = false;
            this->BotonRegresar->Click += gcnew System::EventHandler(this, &MyForm::BotonRegresar_Click);
            // 
            // ApoyoMusica
            // 
            this->ApoyoMusica->Interval = 1000;
            this->ApoyoMusica->Tick += gcnew System::EventHandler(this, &MyForm::ApoyoMusica_Tick);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1346, 866);
            this->Controls->Add(this->BotonRegresar);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->ResumeLayout(false);

        }

    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }

    private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
    {
        buffer->Graphics->Clear(Color::White);
        juego->mostrarMenu(buffer->Graphics);
        buffer->Render(canvas);

    }

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
    {
        button1->Enabled = false;
        button2->Enabled = false;
        timer1->Enabled = false;
        button1->Visible = false;
        button2->Visible = false; 
        timer2->Enabled = true;
    }

    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
    {
        button1->Enabled = false;
        button2->Enabled = false;
        timer1->Enabled = false;
        button1->Visible = false;
        button2->Visible = false;
        TimerApoyoCreditos->Enabled = true;
        BotonRegresar->Enabled = true;
        BotonRegresar->Visible = true;
        sonidoOpening->PlayLooping(); 
    }

    private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e)
    {
        if (juego->getNumeroDePozos() != 0 || juego->getVidas() > 0)
        {
            buffer->Graphics->Clear(Color::White);
            juego->mostrar(buffer->Graphics);
            juego->mover(buffer->Graphics);
            buffer->Render(canvas);

        }
        if (juego->getEstaEnPozo())
        {
            TimerApoyoPozos->Enabled = true;
        }
        /////////////////agregado
        if (juego->getNumeroEnemigos() == 0)
        {
            TimerApoyoBalasEnemigas->Enabled = true;
            
        }

        if (juego->getNumeroDePozos() == 0)
        {    
            timer2->Enabled = false;
            TimerApoyoBalasEnemigas->Enabled = false;
            TimerApoyoPozos->Enabled = false;

            buffer->Graphics->Clear(Color::White);
            juego->mostrarGanaste(buffer->Graphics);  
            buffer->Render(canvas); 

            sonidoOpening->Stop(); 
            AFHS->Stop();     
            sonidoEscopeta->Stop();  
            Himno->Play(); 
            ApoyoMusica->Enabled = true;
        }

        if (juego->getVidas() <= 0)
        {
       
            timer2->Enabled = false; 
            TimerApoyoBalasEnemigas->Enabled = false; 
            TimerApoyoPozos->Enabled = false; 
    
            buffer->Graphics->Clear(Color::White); 
            juego->mostrarPerdiste(buffer->Graphics); 
            buffer->Render(canvas); 
            AFHS->PlayLooping();  
        }

        //////////////// agregado
         
        // Mover al personaje según las teclas presionadas
        if (keyWPressed && keyDPressed)
            juego->moverTeclas(buffer->Graphics, DiagonalArribaDerecha);
        else if (keyWPressed && keyAPressed)
            juego->moverTeclas(buffer->Graphics, DiagonalArribaIzquierda);
        else if (keySPressed && keyDPressed)
            juego->moverTeclas(buffer->Graphics, DiagonalDerechaAbajo);
        else if (keySPressed && keyAPressed)
            juego->moverTeclas(buffer->Graphics, DiagonalAbajoIzquierda);
        else if (keyWPressed)
            juego->moverTeclas(buffer->Graphics, Arriba);
        else if (keyAPressed)
            juego->moverTeclas(buffer->Graphics, Izquierda);
        else if (keySPressed)
            juego->moverTeclas(buffer->Graphics, Abajo);
        else if (keyDPressed)
            juego->moverTeclas(buffer->Graphics, Derecha);
    }

    private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
    {
        // Actualizar el estado de las teclas al presionar
        if (e->KeyCode == Keys::W)
            keyWPressed = true;
        if (e->KeyCode == Keys::A)
            keyAPressed = true;
        if (e->KeyCode == Keys::S)
            keySPressed = true;
        if (e->KeyCode == Keys::D)
            keyDPressed = true;
        if (e->KeyCode == Keys::Space)
        {
            juego->mostrarShotgun(buffer->Graphics);
            buffer->Render(canvas);
            if (juego->getPuedeDisparar())
            {
                juego->disparar();
                sonidoEscopeta->PlayLooping();
                TimerApoyoEscopeta->Enabled = true;
            }
        }

    }

    private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
    {
        // Actualizar el estado de las teclas al soltar
        if (e->KeyCode == Keys::W)
            keyWPressed = false;
        if (e->KeyCode == Keys::A)
            keyAPressed = false;
        if (e->KeyCode == Keys::S)
            keySPressed = false;
        if (e->KeyCode == Keys::D)
            keyDPressed = false;
    }

    private: System::Void TimerApoyoEscopeta_Tick(System::Object^ sender, System::EventArgs^ e)
    {
        sonidoEscopeta->Stop();
    }
    private: System::Void TimerApoyoPozos_Tick(System::Object^ sender, System::EventArgs^ e)
    {
        int seg = juego->getSegundos();
        juego->SetSegundos(seg + 1);

        if (seg == 5)
        {
            seg = 0;
            juego->SetSegundos(seg);
            TimerApoyoPozos->Enabled = false;
        }
    }
    private: System::Void TimerApoyoBalasEnemigas_Tick(System::Object^ sender, System::EventArgs^ e)
    { 
        juego->disparoEnemigo();
    } 
private: System::Void TimerApoyoCreditos_Tick(System::Object^ sender, System::EventArgs^ e) 
    {
        juego->mostrarCreditos(canvas);
    }
private: System::Void BotonRegresar_Click(System::Object^ sender, System::EventArgs^ e) 
    {
         button1->Enabled = true;
         button2->Enabled = true;
         timer1->Enabled = true;
         button1->Visible = true;
         button2->Visible = true;
         TimerApoyoCreditos->Enabled = false;
         BotonRegresar->Enabled = false;
         BotonRegresar->Visible = false;
         sonidoOpening->Stop();  
    }
private: System::Void ApoyoMusica_Tick(System::Object^ sender, System::EventArgs^ e) {
    if (Himno->IsLoadCompleted)
    {
        Himno->PlayLooping();
    }
}
};
}
