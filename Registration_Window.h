#pragma once
#include "Items_list.cpp"

namespace Shop 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Registration_Window : public System::Windows::Forms::Form
	{
	private: Product_list^ test;

	public:
		Registration_Window(Product_list^ productFromMain)
		{
			InitializeComponent();
			test = productFromMain; // Передаем значение хранилища из основного окна
		}

	protected:
		~Registration_Window()
		{
			if (components)
			{
				delete components;
			}
		}
	public:
		Product_list^ GetProductList()
		{
			return test;
		}
	private: System::Windows::Forms::TextBox^ TB_name;
	private: System::Windows::Forms::TextBox^ TB_unit;
	private: System::Windows::Forms::MaskedTextBox^ MTB_quantity;

	public:
	protected:



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btn_photo;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::MaskedTextBox^ MTB_price;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::MaskedTextBox^ MTB_date;
	private: System::Windows::Forms::Button^ btn_reg;




	private: 
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->TB_name = (gcnew System::Windows::Forms::TextBox());
			this->TB_unit = (gcnew System::Windows::Forms::TextBox());
			this->MTB_quantity = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_photo = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->MTB_price = (gcnew System::Windows::Forms::MaskedTextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->MTB_date = (gcnew System::Windows::Forms::MaskedTextBox());
			this->btn_reg = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// TB_name
			// 
			this->TB_name->Location = System::Drawing::Point(49, 52);
			this->TB_name->Name = L"TB_name";
			this->TB_name->Size = System::Drawing::Size(155, 22);
			this->TB_name->TabIndex = 1;
			this->TB_name->Text = L"Название товара";
			this->TB_name->Click += gcnew System::EventHandler(this, &Registration_Window::TB_name_Click);
			// 
			// TB_unit
			// 
			this->TB_unit->Location = System::Drawing::Point(49, 96);
			this->TB_unit->Name = L"TB_unit";
			this->TB_unit->Size = System::Drawing::Size(155, 22);
			this->TB_unit->TabIndex = 2;
			this->TB_unit->Text = L"Единица измерения";
			this->TB_unit->Click += gcnew System::EventHandler(this, &Registration_Window::TB_unit_Click);
			// 
			// MTB_quantity
			// 
			this->MTB_quantity->Location = System::Drawing::Point(51, 140);
			this->MTB_quantity->Mask = L"00000";
			this->MTB_quantity->Name = L"MTB_quantity";
			this->MTB_quantity->Size = System::Drawing::Size(43, 22);
			this->MTB_quantity->TabIndex = 3;
			this->MTB_quantity->Tag = L"";
			this->MTB_quantity->ValidatingType = System::Int32::typeid;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(46, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(156, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Ввод названия товара";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(46, 77);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(175, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Ввод единицы измерения";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(48, 209);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(206, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Ввод даты последнего завоза";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(48, 121);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(258, 16);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Ввод количества товаров (до 100 тыс.)";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(351, 34);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(225, 204);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// btn_photo
			// 
			this->btn_photo->Location = System::Drawing::Point(395, 244);
			this->btn_photo->Name = L"btn_photo";
			this->btn_photo->Size = System::Drawing::Size(148, 23);
			this->btn_photo->TabIndex = 9;
			this->btn_photo->Text = L"Выбрать фото";
			this->btn_photo->UseVisualStyleBackColor = true;
			this->btn_photo->Click += gcnew System::EventHandler(this, &Registration_Window::BTN_photo_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(48, 165);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(126, 16);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Ввод цены товара";
			// 
			// MTB_price
			// 
			this->MTB_price->Location = System::Drawing::Point(51, 184);
			this->MTB_price->Mask = L"00000000.00";
			this->MTB_price->Name = L"MTB_price";
			this->MTB_price->Size = System::Drawing::Size(123, 22);
			this->MTB_price->TabIndex = 11;
			this->MTB_price->ValidatingType = System::Int32::typeid;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MTB_date
			// 
			this->MTB_date->Location = System::Drawing::Point(49, 228);
			this->MTB_date->Mask = L"00/00/0000";
			this->MTB_date->Name = L"MTB_date";
			this->MTB_date->Size = System::Drawing::Size(196, 22);
			this->MTB_date->TabIndex = 12;
			this->MTB_date->ValidatingType = System::DateTime::typeid;
			// 
			// btn_reg
			// 
			this->btn_reg->Location = System::Drawing::Point(47, 266);
			this->btn_reg->Name = L"btn_reg";
			this->btn_reg->Size = System::Drawing::Size(207, 50);
			this->btn_reg->TabIndex = 13;
			this->btn_reg->Text = L"Добавить товар";
			this->btn_reg->UseVisualStyleBackColor = true;
			this->btn_reg->Click += gcnew System::EventHandler(this, &Registration_Window::BTN_reg_Click);
			// 
			// Registration_Window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(609, 337);
			this->Controls->Add(this->btn_reg);
			this->Controls->Add(this->MTB_date);
			this->Controls->Add(this->MTB_price);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->btn_photo);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->MTB_quantity);
			this->Controls->Add(this->TB_unit);
			this->Controls->Add(this->TB_name);
			this->Name = L"Registration_Window";
			this->Text = L"Регистрация товара";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// Нажатие на кнопку Выбрать фото
	private: System::Void BTN_photo_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->openFileDialog1->Filter = "Image Files(*.BMP;*.JPG;*.PNG;*.JPEG)|*.BMP;*.JPG;*.PNG;*.JPEG|All files (*.*)|*.*";
		if (System::Windows::Forms::DialogResult::OK == this->openFileDialog1->ShowDialog()) // Если фото выбрано
		{
			String^ fileName = openFileDialog1->FileName;
			this->pictureBox1->ImageLocation = fileName;
		}
	}
	// Обработка первого нажатия по textBox'у для имени
	private: System::Void TB_name_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (this->TB_name->Text == L"Название товара")
		{
			this->TB_name->Text = L"";
		}
	}
	// Обработка первого нажатия по textBox'у для е.и.
	private: System::Void TB_unit_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (this->TB_unit->Text == L"Единица измерения")
		{
			this->TB_unit->Text = L"";
		}
	}
	// Нажатие на кнопку Добавить товар
	private: System::Void BTN_reg_Click(System::Object^ sender, System::EventArgs^ e) 
	{	
		test->AddProduct(TB_name->Text, pictureBox1->ImageLocation, TB_unit->Text, Double::Parse(MTB_price->Text),
			Int32::Parse(MTB_quantity->Text), MTB_date->Text);
		this->Close();
	}
};
}
