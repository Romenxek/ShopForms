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

	public ref class Purchase_Window : public System::Windows::Forms::Form
	{
	private: Product_list^ mainProductList;
	private: Product_list^ purchase;
	private: double cost = 0.0;
	public:
		Purchase_Window(Product_list^ purchaseFromMain, Product_list^ ProductListFromMain)
		{
			InitializeComponent();
			mainProductList = ProductListFromMain;
			purchase = purchaseFromMain;
			dataGridView1->RowTemplate->Height = 100;
			Product^ current = purchase->head;
			while (current != nullptr) // Отображение корзины в dataGridView
			{
				dataGridView1->Rows->Add(current->name, current->unit, current->price, current->last_delivery,
					current->quantity, System::Drawing::Image::FromFile(current->photo));
				cost += current->price * current->quantity; // Формирование суммы ценн товаров
				current = current->next;
			}
			dataGridView1->ScrollBars = ScrollBars::Both;
			dataGridView1->AllowUserToAddRows = false;
			label_cost->Text = "Стоимость корзины: " + cost.ToString("F2"); // Отображение цены
		}

	protected:
		~Purchase_Window()
		{
			if (components)
			{
				delete components;
			}
		}
	public:
		Product_list^ GetPurchaseProductList()
		{
			return purchase;
		}
	private: System::Windows::Forms::Button^ btn_check;
	public:

	public:

	protected:

	private: System::Windows::Forms::Button^ btn_clear;

	private: System::Windows::Forms::Label^ label_cost;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ unit;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ price;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ date_delivery;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ quantity;
	private: System::Windows::Forms::DataGridViewImageColumn^ photo;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->btn_check = (gcnew System::Windows::Forms::Button());
			this->btn_clear = (gcnew System::Windows::Forms::Button());
			this->label_cost = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->unit = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->price = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->date_delivery = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->quantity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->photo = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_check
			// 
			this->btn_check->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_check->Location = System::Drawing::Point(854, 49);
			this->btn_check->Name = L"btn_check";
			this->btn_check->Size = System::Drawing::Size(317, 148);
			this->btn_check->TabIndex = 1;
			this->btn_check->Text = L"Выписать чек";
			this->btn_check->UseVisualStyleBackColor = true;
			this->btn_check->Click += gcnew System::EventHandler(this, &Purchase_Window::btn_check_click);
			// 
			// btn_clear
			// 
			this->btn_clear->Location = System::Drawing::Point(854, 12);
			this->btn_clear->Name = L"btn_clear";
			this->btn_clear->Size = System::Drawing::Size(316, 31);
			this->btn_clear->TabIndex = 2;
			this->btn_clear->Text = L"очистить корзину";
			this->btn_clear->UseVisualStyleBackColor = true;
			this->btn_clear->Click += gcnew System::EventHandler(this, &Purchase_Window::btn_clear_click);
			// 
			// label_cost
			// 
			this->label_cost->AutoSize = true;
			this->label_cost->Location = System::Drawing::Point(851, 200);
			this->label_cost->Name = L"label_cost";
			this->label_cost->Size = System::Drawing::Size(44, 16);
			this->label_cost->TabIndex = 4;
			this->label_cost->Text = L"label2";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->ColumnHeadersHeight = 56;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->name, this->unit,
					this->price, this->date_delivery, this->quantity, this->photo
			});
			this->dataGridView1->Location = System::Drawing::Point(29, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
			this->dataGridView1->RowTemplate->Height = 80;
			this->dataGridView1->Size = System::Drawing::Size(804, 257);
			this->dataGridView1->TabIndex = 5;
			// 
			// name
			// 
			this->name->HeaderText = L"Наименование";
			this->name->MinimumWidth = 6;
			this->name->Name = L"name";
			this->name->Width = 140;
			// 
			// unit
			// 
			this->unit->HeaderText = L"Е.И.";
			this->unit->MinimumWidth = 6;
			this->unit->Name = L"unit";
			this->unit->Width = 66;
			// 
			// price
			// 
			this->price->HeaderText = L"Цена";
			this->price->MinimumWidth = 6;
			this->price->Name = L"price";
			this->price->Width = 72;
			// 
			// date_delivery
			// 
			this->date_delivery->HeaderText = L"Дата посл. поставки";
			this->date_delivery->MinimumWidth = 6;
			this->date_delivery->Name = L"date_delivery";
			this->date_delivery->Width = 166;
			// 
			// quantity
			// 
			this->quantity->HeaderText = L"Кол-во товара";
			this->quantity->MinimumWidth = 6;
			this->quantity->Name = L"quantity";
			this->quantity->Width = 128;
			// 
			// photo
			// 
			this->photo->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->photo->HeaderText = L"Фотография";
			this->photo->ImageLayout = System::Windows::Forms::DataGridViewImageCellLayout::Stretch;
			this->photo->MinimumWidth = 100;
			this->photo->Name = L"photo";
			this->photo->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->photo->Width = 103;
			// 
			// Purchase_Window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1189, 290);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label_cost);
			this->Controls->Add(this->btn_clear);
			this->Controls->Add(this->btn_check);
			this->Name = L"Purchase_Window";
			this->Text = L"Purchase_Window";
			this->Load += gcnew System::EventHandler(this, &Purchase_Window::Purchase_Window_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Purchase_Window_Load(System::Object^ sender, System::EventArgs^ e) {}
	// Нажатие на кнопку Очистить корзину
	private: System::Void btn_clear_click(System::Object^ sender, System::EventArgs^ e) 
	{
		purchase->head = nullptr; // Начало списка = null
		dataGridView1->Rows->Clear(); // Стираем строки из dataGridView
		cost = 0; // Обнуляем цену
		label_cost->Text = "Стоимость корзины: " + cost.ToString("F2"); // Меняем надпись

	}
	// Нажатие кнопки Выписать чек
	private: System::Void btn_check_click(System::Object^ sender, System::EventArgs^ e) 
	{
		// Ставим указатели на начала списков
		Product^ currentTest = mainProductList->head;
		Product^ currentPurchase = purchase->head;
		while (purchase->head != nullptr) // Пока список корзины не пуст
		{
			if (currentPurchase->name == currentTest->name && currentPurchase->unit == currentTest->unit) // Если поля текущих элементов списков совпали
			{
				purchase->DeleteProduct(currentPurchase); // Удаляем указывающий элемент из корзины
				currentTest->quantity -= currentPurchase->quantity; // Меняем количество для соответствующего элемента в базе данных 
				currentTest = mainProductList->head; // Ставим указатель в списке базы данных на начало для того, чтобы начать идти по нему заново
				currentPurchase = currentPurchase->next; // Идем по указателю удаленного элемента
				continue; 
			}
			currentTest = currentTest->next;// Если поля не совпали, то идем по указателю в списке базы данных и ищем нужный элемент среди других
		}
		this->Close(); // Закрываем окно
	}
};
}
