#pragma once
#include "Items_list.cpp"
#include "Purchase_Window.cpp"
#include "Registration_Window.h"
#include "Editing_Window.h"
#include "Receipt_Window.h"
#include <Windows.h>

using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace Microsoft::VisualBasic;
namespace Shop 
{
	public ref class Main_Window : public System::Windows::Forms::Form
	{

	public:
		Main_Window(void)
		{
			InitializeComponent();
			// Привязка к событию закрытия формы (в ней закрываем окно и сохраняем в json, если снят комментарий)
			this->FormClosing += gcnew FormClosingEventHandler(this, &Main_Window::OnFormClosing);
			// Хранилище продуктов на Main_Window форме
			test = gcnew Product_list();
			// Хранилище продуктов для обработки contextmenustrip->Добавить в корзину
			purchase = gcnew Product_list();
			// Загружаем нашу базу данных
			test->LoadFromJsonFile("Base.json");
			// Проверяем есть ли в ней с 0 количеством и удаляем их
			test->DeleteAllSoldOut();
			//Высота строк
			dataGridView1->RowTemplate->Height = 100;
			Product^ current = test->head;// Проходим по списку и добавляем в dataGridView1
			while (current != nullptr)
			{
				dataGridView1->Rows->Add(current->name, current->unit, current->price, current->last_delivery,
					current->quantity, System::Drawing::Image::FromFile(current->photo));
				current = current->next;
			}
			dataGridView1->ScrollBars = ScrollBars::Both;// Сохраняем оба ползунка
			dataGridView1->AllowUserToAddRows = false;// Удаляем последнюю пустую строку
		}



	private:Product_list^ test;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ редактироватьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ добавитьВКарзинуToolStripMenuItem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ unit;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ price;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ date_delivery;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ quantity;
	private: System::Windows::Forms::DataGridViewImageColumn^ photo;
	private: System::Windows::Forms::ToolStripMenuItem^ новоеПоступлениеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ удалитьToolStripMenuItem;
	private:Product_list^ purchase;
		~Main_Window()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::CheckBox^ check_price;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ TB_name;
	private: System::Windows::Forms::MaskedTextBox^ MTB_delivery;


	private: System::Windows::Forms::Label^ label_from;
	private: System::Windows::Forms::Label^ label_to;
	private: System::Windows::Forms::Button^ btn_purchase;
	private: System::Windows::Forms::Button^ btn_registration;




	private: System::Windows::Forms::Button^ btn_reset;








	private: System::Windows::Forms::CheckBox^ check_date;

	private: System::Windows::Forms::CheckBox^ check_name;
	private: System::Windows::Forms::Button^ btn_search;
	private: System::Windows::Forms::MaskedTextBox^ MTB_priceFrom;
	private: System::Windows::Forms::MaskedTextBox^ MTB_priceTo;




	private: System::ComponentModel::IContainer^ components;

	protected:


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->unit = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->price = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->date_delivery = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->quantity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->photo = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->check_price = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->MTB_delivery = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label_from = (gcnew System::Windows::Forms::Label());
			this->label_to = (gcnew System::Windows::Forms::Label());
			this->btn_purchase = (gcnew System::Windows::Forms::Button());
			this->btn_registration = (gcnew System::Windows::Forms::Button());
			this->btn_reset = (gcnew System::Windows::Forms::Button());
			this->check_date = (gcnew System::Windows::Forms::CheckBox());
			this->check_name = (gcnew System::Windows::Forms::CheckBox());
			this->btn_search = (gcnew System::Windows::Forms::Button());
			this->MTB_priceFrom = (gcnew System::Windows::Forms::MaskedTextBox());
			this->MTB_priceTo = (gcnew System::Windows::Forms::MaskedTextBox());
			this->TB_name = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->редактироватьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->добавитьВКарзинуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->новоеПоступлениеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->удалитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
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
			this->dataGridView1->Location = System::Drawing::Point(26, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
			this->dataGridView1->RowTemplate->Height = 80;
			this->dataGridView1->Size = System::Drawing::Size(780, 437);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellBeginEdit += gcnew System::Windows::Forms::DataGridViewCellCancelEventHandler(this, &Main_Window::dataGridView1_CellBeginEdit);
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Main_Window::dataGridView1_CellContentClick);
			this->dataGridView1->CellMouseDown += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &Main_Window::dataGridView1_CellMouseDown);
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
			// check_price
			// 
			this->check_price->AutoSize = true;
			this->check_price->Location = System::Drawing::Point(845, 140);
			this->check_price->Name = L"check_price";
			this->check_price->Size = System::Drawing::Size(62, 20);
			this->check_price->TabIndex = 1;
			this->check_price->Text = L"Цене";
			this->check_price->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(842, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Поиск по:";
			this->label1->Click += gcnew System::EventHandler(this, &Main_Window::label1_Click);
			// 
			// MTB_delivery
			// 
			this->MTB_delivery->Location = System::Drawing::Point(845, 112);
			this->MTB_delivery->Mask = L"00/00/0000";
			this->MTB_delivery->Name = L"MTB_delivery";
			this->MTB_delivery->Size = System::Drawing::Size(100, 22);
			this->MTB_delivery->TabIndex = 6;
			this->MTB_delivery->ValidatingType = System::DateTime::typeid;
			// 
			// label_from
			// 
			this->label_from->AutoSize = true;
			this->label_from->Location = System::Drawing::Point(842, 169);
			this->label_from->Name = L"label_from";
			this->label_from->Size = System::Drawing::Size(27, 16);
			this->label_from->TabIndex = 9;
			this->label_from->Text = L"От:";
			this->label_from->Click += gcnew System::EventHandler(this, &Main_Window::label2_Click);
			// 
			// label_to
			// 
			this->label_to->AutoSize = true;
			this->label_to->Location = System::Drawing::Point(1000, 169);
			this->label_to->Name = L"label_to";
			this->label_to->Size = System::Drawing::Size(27, 16);
			this->label_to->TabIndex = 10;
			this->label_to->Text = L"До:";
			// 
			// btn_purchase
			// 
			this->btn_purchase->Location = System::Drawing::Point(845, 331);
			this->btn_purchase->Name = L"btn_purchase";
			this->btn_purchase->Size = System::Drawing::Size(325, 50);
			this->btn_purchase->TabIndex = 11;
			this->btn_purchase->Text = L"Выписать чек";
			this->btn_purchase->UseVisualStyleBackColor = true;
			this->btn_purchase->Click += gcnew System::EventHandler(this, &Main_Window::btn_purchase_click);
			// 
			// btn_registration
			// 
			this->btn_registration->Location = System::Drawing::Point(845, 401);
			this->btn_registration->Name = L"btn_registration";
			this->btn_registration->Size = System::Drawing::Size(325, 48);
			this->btn_registration->TabIndex = 12;
			this->btn_registration->Text = L"Зарегистрировать товар";
			this->btn_registration->UseVisualStyleBackColor = true;
			this->btn_registration->Click += gcnew System::EventHandler(this, &Main_Window::btn_registration_click);
			// 
			// btn_reset
			// 
			this->btn_reset->Location = System::Drawing::Point(845, 260);
			this->btn_reset->Name = L"btn_reset";
			this->btn_reset->Size = System::Drawing::Size(325, 54);
			this->btn_reset->TabIndex = 13;
			this->btn_reset->Text = L"Сбросить фильтры";
			this->btn_reset->UseVisualStyleBackColor = true;
			this->btn_reset->Click += gcnew System::EventHandler(this, &Main_Window::btn_reset_click);
			// 
			// check_date
			// 
			this->check_date->AutoSize = true;
			this->check_date->Location = System::Drawing::Point(845, 86);
			this->check_date->Name = L"check_date";
			this->check_date->Size = System::Drawing::Size(192, 20);
			this->check_date->TabIndex = 2;
			this->check_date->Text = L"Дате последнего завоза";
			this->check_date->UseVisualStyleBackColor = true;
			// 
			// check_name
			// 
			this->check_name->AutoSize = true;
			this->check_name->Location = System::Drawing::Point(845, 32);
			this->check_name->Name = L"check_name";
			this->check_name->Size = System::Drawing::Size(130, 20);
			this->check_name->TabIndex = 3;
			this->check_name->Text = L"Наименованию";
			this->check_name->UseVisualStyleBackColor = true;
			this->check_name->CheckedChanged += gcnew System::EventHandler(this, &Main_Window::checkBox3_CheckedChanged);
			// 
			// btn_search
			// 
			this->btn_search->Location = System::Drawing::Point(845, 194);
			this->btn_search->Name = L"btn_search";
			this->btn_search->Size = System::Drawing::Size(325, 54);
			this->btn_search->TabIndex = 14;
			this->btn_search->Text = L"Поиск";
			this->btn_search->UseVisualStyleBackColor = true;
			this->btn_search->Click += gcnew System::EventHandler(this, &Main_Window::btn_search_click);
			// 
			// MTB_priceFrom
			// 
			this->MTB_priceFrom->Location = System::Drawing::Point(880, 163);
			this->MTB_priceFrom->Mask = L"00000000.00";
			this->MTB_priceFrom->Name = L"MTB_priceFrom";
			this->MTB_priceFrom->Size = System::Drawing::Size(95, 22);
			this->MTB_priceFrom->TabIndex = 15;
			// 
			// MTB_priceTo
			// 
			this->MTB_priceTo->Location = System::Drawing::Point(1033, 163);
			this->MTB_priceTo->Mask = L"00000000.00";
			this->MTB_priceTo->Name = L"MTB_priceTo";
			this->MTB_priceTo->Size = System::Drawing::Size(113, 22);
			this->MTB_priceTo->TabIndex = 16;
			this->MTB_priceTo->ValidatingType = System::Int32::typeid;
			// 
			// TB_name
			// 
			this->TB_name->Location = System::Drawing::Point(845, 58);
			this->TB_name->Name = L"TB_name";
			this->TB_name->Size = System::Drawing::Size(192, 22);
			this->TB_name->TabIndex = 17;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->редактироватьToolStripMenuItem,
					this->добавитьВКарзинуToolStripMenuItem, this->новоеПоступлениеToolStripMenuItem, this->удалитьToolStripMenuItem
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(219, 100);
			// 
			// редактироватьToolStripMenuItem
			// 
			this->редактироватьToolStripMenuItem->Name = L"редактироватьToolStripMenuItem";
			this->редактироватьToolStripMenuItem->Size = System::Drawing::Size(218, 24);
			this->редактироватьToolStripMenuItem->Text = L"Редактировать";
			this->редактироватьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::редактироватьToolStripMenuItem_Click);
			// 
			// добавитьВКарзинуToolStripMenuItem
			// 
			this->добавитьВКарзинуToolStripMenuItem->Name = L"добавитьВКарзинуToolStripMenuItem";
			this->добавитьВКарзинуToolStripMenuItem->Size = System::Drawing::Size(218, 24);
			this->добавитьВКарзинуToolStripMenuItem->Text = L"Добавить в корзину";
			this->добавитьВКарзинуToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::добавитьВКарзинуToolStripMenuItem_Click);
			// 
			// новоеПоступлениеToolStripMenuItem
			// 
			this->новоеПоступлениеToolStripMenuItem->Name = L"новоеПоступлениеToolStripMenuItem";
			this->новоеПоступлениеToolStripMenuItem->Size = System::Drawing::Size(218, 24);
			this->новоеПоступлениеToolStripMenuItem->Text = L"Новое поступление";
			this->новоеПоступлениеToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::новоеПоступлениеToolStripMenuItem_Click);
			// 
			// удалитьToolStripMenuItem
			// 
			this->удалитьToolStripMenuItem->Name = L"удалитьToolStripMenuItem";
			this->удалитьToolStripMenuItem->Size = System::Drawing::Size(218, 24);
			this->удалитьToolStripMenuItem->Text = L"Удалить";
			this->удалитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::удалитьToolStripMenuItem_Click);
			// 
			// Main_Window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1188, 470);
			this->Controls->Add(this->TB_name);
			this->Controls->Add(this->MTB_priceTo);
			this->Controls->Add(this->MTB_priceFrom);
			this->Controls->Add(this->btn_search);
			this->Controls->Add(this->btn_reset);
			this->Controls->Add(this->btn_registration);
			this->Controls->Add(this->btn_purchase);
			this->Controls->Add(this->label_to);
			this->Controls->Add(this->label_from);
			this->Controls->Add(this->MTB_delivery);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->check_name);
			this->Controls->Add(this->check_date);
			this->Controls->Add(this->check_price);
			this->Controls->Add(this->dataGridView1);
			this->Location = System::Drawing::Point(845, 58);
			this->Name = L"Main_Window";
			this->Text = L"Shop";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void OnFormClosing(System::Object^ sender, FormClosingEventArgs^ e) // Закрытие основного окна
		{
			//test->SaveToJsonFile("Base.json"); // Снять комментарий для сохранения
			Application::Exit();
		}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {}

	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {}
	// Нажатие на кнопку регистрации товара
	private: System::Void btn_registration_click(System::Object^ sender, System::EventArgs^ e)
	{
		// Создаём новую форму и передаем хранилище объектов
		Shop::Registration_Window^ registrationWindow = gcnew Registration_Window(test);
		// Показываем окно
		registrationWindow->Show();
		// Подписываем на событие закрытия данного окна
		registrationWindow->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Main_Window::RegistrationWindow_FormClosed);
	}
	// Событие закрытия окна регистрации нвого товара
	void Main_Window::RegistrationWindow_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
	{
		// Получаем обновленное хранилище с добавленным объектом
		this->test = safe_cast<Registration_Window^>(sender)->GetProductList();
		// Обновляем dataGridView
		dataGridView1->Rows->Clear();
		Product^ current = test->head;
		while (current != nullptr)
		{
			dataGridView1->Rows->Add(current->name, current->unit, current->price, current->last_delivery,
				current->quantity, System::Drawing::Image::FromFile(current->photo));
			current = current->next;
		}
	}
	// Нажатие на кнопку выписки чека
	private: System::Void btn_purchase_click(System::Object^ sender, System::EventArgs^ e)
	{
		// Создаём новую форму и передаем 2 хранилища объектов: корзину покупок и базу данных
		Purchase_Window^ purchaseWindow = gcnew Purchase_Window(purchase, test);
		// Подписываем на событие закрытия данного окна
		purchaseWindow->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Main_Window::PurchaseWindow_FormClosed);
		// Показываем окно
		purchaseWindow->Show();
	}
	// Событие закрытия окна выписки чека
	void Main_Window::PurchaseWindow_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
	{
		dataGridView1->Rows->Clear();
		test->DeleteAllSoldOut(); // Из этого окна можем получить 0 в поле количества у товаров, значит требуется удалить их
		Product^ current = test->head; 
		// Заполняем dataGridView
		while (current != nullptr)
		{
			dataGridView1->Rows->Add(current->name, current->unit, current->price, current->last_delivery,
				current->quantity, System::Drawing::Image::FromFile(current->photo));
			current = current->next;
		}
	}
	// Нажатие на кнопку поиска
	private: System::Void btn_search_click(System::Object^ sender, System::EventArgs^ e)
	{
		// Создаем хранилище, которое будет отображаться в dataGridView
		Product_list^ searchList = gcnew Product_list;
		// Передаём значения checkbox'ов
		bool usename = check_name->Checked; bool usedate = check_date->Checked; bool useprice = check_price->Checked; 
		// Выполняем поиск
		searchList = test->Search(TB_name->Text, MTB_delivery->Text, MTB_priceFrom->Text, MTB_priceTo->Text, usename, usedate, useprice);
		dataGridView1->Rows->Clear();
		Product^ current = searchList->head;
		// Выводим хранилище объектов поиска в dataGridView
		while (current != nullptr)
		{
			dataGridView1->Rows->Add(current->name, current->unit, current->price, current->last_delivery,
				current->quantity, System::Drawing::Image::FromFile(current->photo));
			current = current->next;
		}
	}
	// Нажатие на кнопку очистки фильтров поиска
	private: System::Void btn_reset_click(System::Object^ sender, System::EventArgs^ e)
	{
		// Очищаем строки dataGridView
		dataGridView1->Rows->Clear();
		Product^ current = test->head;
		// Заполняем dataGridView
		while (current != nullptr)
		{
			dataGridView1->Rows->Add(current->name, current->unit, current->price, current->last_delivery,
				current->quantity, System::Drawing::Image::FromFile(current->photo));
			current = current->next;
		}
		// Удаляем пустую строку
		dataGridView1->AllowUserToAddRows = false;
	}
	// Обработка нажатия правой кнопки в dataGridView (для вызова contextMenuStrip)
	private: System::Void dataGridView1_CellMouseDown(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e)
	{
		if (e->Button == Windows::Forms::MouseButtons::Right && e->RowIndex >= 0 && e->ColumnIndex >= 0)
		{
			// Выделяем ячейку, по которой кликнули правой кнопкой мыши
			dataGridView1->CurrentCell = dataGridView1[e->ColumnIndex, e->RowIndex];

			// Показываем контекстное меню
			contextMenuStrip1->Show(Cursor->Position);
		}
	}
	// Выбираем поле Редактировать contextMenuStrip'а
	private: System::Void редактироватьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Получаем индекс строки ячейки, значения столбцов name и unit для этой строки
		int rowIndex = dataGridView1->CurrentCell->RowIndex;
		String^ productName = dataGridView1->Rows[rowIndex]->Cells["name"]->Value->ToString();
		String^ productUnit = dataGridView1->Rows[rowIndex]->Cells["unit"]->Value->ToString();
		Product^ current = test->head;
		while (current != nullptr) // Ищем первое вхождение по полям name и unit
		{
			if (current->name == productName && current->unit == productUnit)
			{
				break; // Находим данный товар
			}
			current = current->next;
		}
		// Создаем окно и передаем в него данный товар
		Editing_Window^ editWin = gcnew Editing_Window(current);
		// Подписываем на событие закрытия данного окна
		editWin->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Main_Window::EditingWindow_FormClosed);
		// Выводим окно
		editWin->Show();
	}
	// Событие закрытия окна редактирования товара
	void Main_Window::EditingWindow_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
	{	
		// Очищаем строки dataGridView
		dataGridView1->Rows->Clear();
		test->DeleteAllSoldOut(); // После закрытия данного окна у нас может появиться Product с полем quantity = 0, требуется удалить его
		Product^ current = test->head;
		while (current != nullptr) // Обновляем dataGridView
		{
			dataGridView1->Rows->Add(current->name, current->unit, current->price, current->last_delivery,
				current->quantity, System::Drawing::Image::FromFile(current->photo));
			current = current->next;
		}
	}
	// Выбираем поле Добавить в корзину contextMenuStrip'а
	private: System::Void добавитьВКарзинуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// Получаем индекс строки ячейки, значения столбцов name и unit для этой строки
		int rowIndex = dataGridView1->CurrentCell->RowIndex;
		String^ productName = dataGridView1->Rows[rowIndex]->Cells["name"]->Value->ToString();
		String^ productUnit = dataGridView1->Rows[rowIndex]->Cells["unit"]->Value->ToString();
		Product^ current = test->head; 
		Product^ currentInPurchase;
		bool productFound = false;

		while (current != nullptr) // Пока не пройдена вся база данных
		{
			if (current->name == productName && current->unit == productUnit) // Если найден продукт (по первому с равными полями наименования и е.и.)
			{
				currentInPurchase = purchase->head; 
				while (currentInPurchase != nullptr) // Идем по корзине и ищем вхождение там
				{
					if (currentInPurchase->name == current->name && currentInPurchase->unit == current->unit) // Данный товар найден
					{
						if (currentInPurchase->quantity < current->quantity) // Если товара не больше, чем его есть на складе
						{
							currentInPurchase->quantity += 1; // Добавляем к его количеству в корзине
							productFound = true;
							break;
						}
						else
						{
							MessageBox::Show("Недостаточно " + current->name + " на складе.", "Ошибка при добавлении", MessageBoxButtons::OK, MessageBoxIcon::Error);
							return;
						}
					}
					currentInPurchase = currentInPurchase->next; // Переходим к кследющему товару в корзине если текущий не совпал
				}
				if (!productFound) // Если товар не найден в корзине, то добавляем его с количеством 1
				{
					purchase->AddProduct(current->name,current->photo,current->unit,current->price,1,current->last_delivery);
				}
				break;
			}
			else (current = current->next);
		}
	}
	private: System::Void dataGridView1_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e){}
	// Выбираем поле Новое поступление contextMenuStrip'а
	private: System::Void новоеПоступлениеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// Получаем индекс строки ячейки, значения столбцов name и unit для этой строки
		int rowIndex = dataGridView1->CurrentCell->RowIndex;
		String^ productName = dataGridView1->Rows[rowIndex]->Cells["name"]->Value->ToString();
		String^ productUnit = dataGridView1->Rows[rowIndex]->Cells["unit"]->Value->ToString();
		Product^ current = test->head;
		while (current != nullptr) // Ищем первое вхождение по полям name и unit
		{
			if (current->name == productName && current->unit == productUnit)
			{
				break; // Находим данный товар
			}
			current = current->next;
		}
		// Создаем окно и передаем в него данный товар
		Receipt_Window^ receiptWin = gcnew Receipt_Window(current);
		// Подписываем на событие закрытия данного окна
		receiptWin->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Main_Window::ReceiptWindow_FormClosed);
		// Выводим окно
		receiptWin->Show();
	}
	// Событие закрытия окна нового поступления товара
	void Main_Window::ReceiptWindow_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
	{
		// Очищаем строки dataGridView
		dataGridView1->Rows->Clear();
		Product^ current = test->head;
		while (current != nullptr) // Обновляем dataGridView
		{
			dataGridView1->Rows->Add(current->name, current->unit, current->price, current->last_delivery,
				current->quantity, System::Drawing::Image::FromFile(current->photo));
			current = current->next;
		}
	}
	// Выбираем поле Удалить contextMenuStrip'а
	private: System::Void удалитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// Получаем индекс строки ячейки, значения столбцов name и unit для этой строки
		int rowIndex = dataGridView1->CurrentCell->RowIndex;
		String^ productName = dataGridView1->Rows[rowIndex]->Cells["name"]->Value->ToString();
		String^ productUnit = dataGridView1->Rows[rowIndex]->Cells["unit"]->Value->ToString();
		Product^ current = test->head;
		while (current != nullptr) // Ищем первое вхождение по полям name и unit
		{
			if (current->name == productName && current->unit == productUnit)
			{
				test->DeleteProduct(current); // Удаляем найденный товар
				break; // Дальнейшее прохождение списка не требуется
			}
			current = current->next;
		}
		dataGridView1->Rows->Clear(); // Очищаем строки dataGridView
		current = test->head;
		while (current != nullptr) // Обновляем dataGridView
		{
			dataGridView1->Rows->Add(current->name, current->unit, current->price, current->last_delivery,
				current->quantity, System::Drawing::Image::FromFile(current->photo));
			current = current->next;
		}
	}
};
}


