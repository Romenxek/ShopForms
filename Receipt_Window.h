#pragma once
#include "Items_list.cpp"

namespace Shop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Receipt_Window : public System::Windows::Forms::Form
	{
	public:
		Receipt_Window(Product^ productFromMain)
		{
			InitializeComponent();
			// Передаем значение объекта из основного окна
			product = productFromMain;
			int quantity = productFromMain->quantity;
			String^ last_delivery = productFromMain->last_delivery;
		}

	protected:
		~Receipt_Window()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Product^ product;
	private: System::Windows::Forms::MaskedTextBox^ MTB_quantity;
	private: System::Windows::Forms::MaskedTextBox^ MTB_date;

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btn_receipt;


	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->MTB_quantity = (gcnew System::Windows::Forms::MaskedTextBox());
			this->MTB_date = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btn_receipt = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// MTB_quantity
			// 
			this->MTB_quantity->Location = System::Drawing::Point(15, 44);
			this->MTB_quantity->Mask = L"00000";
			this->MTB_quantity->Name = L"MTB_quantity";
			this->MTB_quantity->Size = System::Drawing::Size(52, 22);
			this->MTB_quantity->TabIndex = 0;
			this->MTB_quantity->ValidatingType = System::Int32::typeid;
			// 
			// MTB_date
			// 
			this->MTB_date->Location = System::Drawing::Point(15, 93);
			this->MTB_date->Mask = L"00/00/0000";
			this->MTB_date->Name = L"MTB_date";
			this->MTB_date->Size = System::Drawing::Size(100, 22);
			this->MTB_date->TabIndex = 1;
			this->MTB_date->ValidatingType = System::DateTime::typeid;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(291, 32);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Введите количество привезённых товаров\r\nдо 100 тыс.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Дата поставки";
			// 
			// btn_receipt
			// 
			this->btn_receipt->Location = System::Drawing::Point(143, 66);
			this->btn_receipt->Name = L"btn_receipt";
			this->btn_receipt->Size = System::Drawing::Size(159, 48);
			this->btn_receipt->TabIndex = 4;
			this->btn_receipt->Text = L"Регистрация";
			this->btn_receipt->UseVisualStyleBackColor = true;
			this->btn_receipt->Click += gcnew System::EventHandler(this, &Receipt_Window::btn_receipt_Click);
			// 
			// Receipt_Window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(316, 135);
			this->Controls->Add(this->btn_receipt);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->MTB_date);
			this->Controls->Add(this->MTB_quantity);
			this->Name = L"Receipt_Window";
			this->Text = L"Завоз товара";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// Нажатие на кнопку Регистрация
	private: System::Void btn_receipt_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		{
			product->Edit_Product(product->name, product->photo, product->unit, product->price,
				(product->quantity + Int32::Parse(MTB_quantity->Text)), MTB_date->Text);
			this->Close();
		}
	}
	// Метод доступа к объекту товара из других окон
	public: Product^ GetProduct()
	{
		return product;
	}
};
}
