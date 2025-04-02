#pragma once
#include "Main_Window.h"

namespace Shop {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;


    public ref class Start_window : public System::Windows::Forms::Form
    {
    public:
        Start_window(void)
        {
            InitializeComponent();
        }

    protected:
        ~Start_window()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ label_inf;
    private: System::Windows::Forms::Label^ label_ins;
    protected:




    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->label_inf = (gcnew System::Windows::Forms::Label());
            this->label_ins = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // label_inf
            // 
            this->label_inf->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->label_inf->AutoSize = true;
            this->label_inf->BackColor = System::Drawing::SystemColors::Info;
            this->label_inf->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label_inf->ForeColor = System::Drawing::SystemColors::InfoText;
            this->label_inf->Location = System::Drawing::Point(109, 90);
            this->label_inf->Name = L"label_inf";
            this->label_inf->Size = System::Drawing::Size(397, 110);
            this->label_inf->TabIndex = 1;
            this->label_inf->Text = L"Приложение разработано в ходе выполнения\r\nзадания учебной практики кафедры \r\nСист"
                L"емное программирование НИУ ЮУрГУ\r\nРазработчик: Девятериков Р.А. КЭ-202\r\n\r\n";
            this->label_inf->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // label_ins
            // 
            this->label_ins->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->label_ins->AutoSize = true;
            this->label_ins->BackColor = System::Drawing::Color::Transparent;
            this->label_ins->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label_ins->Location = System::Drawing::Point(135, 257);
            this->label_ins->Name = L"label_ins";
            this->label_ins->Size = System::Drawing::Size(345, 64);
            this->label_ins->TabIndex = 2;
            this->label_ins->Text = L"Нажмите на окно, чтобы \r\nперейти к программе";
            this->label_ins->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // Start_window
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::HotTrack;
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(633, 443);
            this->Controls->Add(this->label_ins);
            this->Controls->Add(this->label_inf);
            this->Name = L"Start_window";
            this->Text = L"Shop";
            this->Click += gcnew System::EventHandler(this, &Start_window::Start_window_Click);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    //Перенос на другое окно по клику на форму (не label'ы)
    private: System::Void Start_window_Click(System::Object^ sender, System::EventArgs^ e) {
        // Создаем экземпляр формы Main_Window
        Main_Window^ mainForm = gcnew Main_Window();

        // Отображаем форму Main_Window
        mainForm->Show();

        // Закрываем текущую форму
        this->Hide();
    }
    };
}