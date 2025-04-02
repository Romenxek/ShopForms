#pragma once
#include "Items_list.cpp"

namespace Shop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Editing_Window : public System::Windows::Forms::Form
	{
	public:
		Editing_Window(Product^ productFromMain)
		{
			InitializeComponent();
			product = productFromMain; // Передаем значение объекта из основного окна
			// Заполняем textBox'ы и maskedTextBox'ы соответствующими полями
			TB_name->Text = product->name; 
			TB_unit->Text = product->unit;
			MTB_quantity->Text = product->quantity.ToString();
			MTB_price->Text = product->price.ToString();
			MTB_date->Text = product->last_delivery->ToString();
			pictureBox1->ImageLocation = product->photo;
		}

	protected:
		~Editing_Window()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Product^ product;
	private: System::Windows::Forms::Button^ btn_edit;


	private: System::Windows::Forms::MaskedTextBox^ MTB_date;
	protected:

	private: System::Windows::Forms::MaskedTextBox^ MTB_price;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ btn_photo;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::MaskedTextBox^ MTB_quantity;

	private: System::Windows::Forms::TextBox^ TB_unit;

	private: System::Windows::Forms::TextBox^ TB_name;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_edit = (gcnew System::Windows::Forms::Button());
			this->MTB_date = (gcnew System::Windows::Forms::MaskedTextBox());
			this->MTB_price = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btn_photo = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->MTB_quantity = (gcnew System::Windows::Forms::MaskedTextBox());
			this->TB_unit = (gcnew System::Windows::Forms::TextBox());
			this->TB_name = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_edit
			// 
			this->btn_edit->Location = System::Drawing::Point(40, 260);
			this->btn_edit->Name = L"btn_edit";
			this->btn_edit->Size = System::Drawing::Size(207, 50);
			this->btn_edit->TabIndex = 26;
			this->btn_edit->Text = L"Отредактировать";
			this->btn_edit->UseVisualStyleBackColor = true;
			this->btn_edit->Click += gcnew System::EventHandler(this, &Editing_Window::btn_edit_Click);
			// 
			// MTB_date
			// 
			this->MTB_date->Location = System::Drawing::Point(42, 222);
			this->MTB_date->Mask = L"00/00/0000";
			this->MTB_date->Name = L"MTB_date";
			this->MTB_date->Size = System::Drawing::Size(196, 22);
			this->MTB_date->TabIndex = 25;
			this->MTB_date->ValidatingType = System::DateTime::typeid;
			// 
			// MTB_price
			// 
			this->MTB_price->Location = System::Drawing::Point(44, 178);
			this->MTB_price->Mask = L"00000000.00";
			this->MTB_price->Name = L"MTB_price";
			this->MTB_price->Size = System::Drawing::Size(123, 22);
			this->MTB_price->TabIndex = 24;
			this->MTB_price->ValidatingType = System::Int32::typeid;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(41, 159);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(126, 16);
			this->label5->TabIndex = 23;
			this->label5->Text = L"Ввод цены товара";
			// 
			// btn_photo
			// 
			this->btn_photo->Location = System::Drawing::Point(388, 238);
			this->btn_photo->Name = L"btn_photo";
			this->btn_photo->Size = System::Drawing::Size(148, 23);
			this->btn_photo->TabIndex = 22;
			this->btn_photo->Text = L"Выбрать фото";
			this->btn_photo->UseVisualStyleBackColor = true;
			this->btn_photo->Click += gcnew System::EventHandler(this, &Editing_Window::btn_photo_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(344, 28);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(225, 204);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 21;
			this->pictureBox1->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(41, 115);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(258, 16);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Ввод количества товаров (до 100 тыс.)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(41, 203);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(206, 16);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Ввод даты последнего завоза";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(39, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(175, 16);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Ввод единицы измерения";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(39, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(156, 16);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Ввод названия товара";
			// 
			// MTB_quantity
			// 
			this->MTB_quantity->Location = System::Drawing::Point(44, 134);
			this->MTB_quantity->Mask = L"00000";
			this->MTB_quantity->Name = L"MTB_quantity";
			this->MTB_quantity->Size = System::Drawing::Size(43, 22);
			this->MTB_quantity->TabIndex = 16;
			this->MTB_quantity->Tag = L"";
			this->MTB_quantity->ValidatingType = System::Int32::typeid;
			// 
			// TB_unit
			// 
			this->TB_unit->Location = System::Drawing::Point(42, 90);
			this->TB_unit->Name = L"TB_unit";
			this->TB_unit->Size = System::Drawing::Size(155, 22);
			this->TB_unit->TabIndex = 15;
			// 
			// TB_name
			// 
			this->TB_name->Location = System::Drawing::Point(42, 46);
			this->TB_name->Name = L"TB_name";
			this->TB_name->Size = System::Drawing::Size(155, 22);
			this->TB_name->TabIndex = 14;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Editing_Window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(609, 337);
			this->Controls->Add(this->btn_edit);
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
			this->Name = L"Editing_Window";
			this->Text = L"Редактирование товара";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// Нажатие на кнопку Выбрать фото
	private: System::Void btn_photo_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->openFileDialog1->Filter = "Image Files(*.BMP;*.JPG;*.PNG;*.JPEG)|*.BMP;*.JPG;*.PNG;*.JPEG|All files (*.*)|*.*";
		if (System::Windows::Forms::DialogResult::OK == this->openFileDialog1->ShowDialog()) // Если фото выбрано
		{
			String^ fileName = openFileDialog1->FileName;
			this->pictureBox1->ImageLocation = fileName;
		}
	}
	// Нажатие на кнопку Редактировать
	private: System::Void btn_edit_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		product->Edit_Product(TB_name->Text, pictureBox1->ImageLocation, TB_unit->Text, Double::Parse(MTB_price->Text),
			Int32::Parse(MTB_quantity->Text), MTB_date->Text);
		this->Close();
	}
	public: Product^ GetProduct() // Метод доступа к значению объекта из других окон
	{
		return product;
	}
};
}
