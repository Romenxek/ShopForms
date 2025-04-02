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
			// �������� � ������� �������� ����� (� ��� ��������� ���� � ��������� � json, ���� ���� �����������)
			this->FormClosing += gcnew FormClosingEventHandler(this, &Main_Window::OnFormClosing);
			// ��������� ��������� �� Main_Window �����
			test = gcnew Product_list();
			// ��������� ��������� ��� ��������� contextmenustrip->�������� � �������
			purchase = gcnew Product_list();
			// ��������� ���� ���� ������
			test->LoadFromJsonFile("Base.json");
			// ��������� ���� �� � ��� � 0 ����������� � ������� ��
			test->DeleteAllSoldOut();
			//������ �����
			dataGridView1->RowTemplate->Height = 100;
			Product^ current = test->head;// �������� �� ������ � ��������� � dataGridView1
			while (current != nullptr)
			{
				dataGridView1->Rows->Add(current->name, current->unit, current->price, current->last_delivery,
					current->quantity, System::Drawing::Image::FromFile(current->photo));
				current = current->next;
			}
			dataGridView1->ScrollBars = ScrollBars::Both;// ��������� ��� ��������
			dataGridView1->AllowUserToAddRows = false;// ������� ��������� ������ ������
		}



	private:Product_list^ test;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ �������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������ToolStripMenuItem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ unit;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ price;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ date_delivery;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ quantity;
	private: System::Windows::Forms::DataGridViewImageColumn^ photo;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
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
			this->�������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->name->HeaderText = L"������������";
			this->name->MinimumWidth = 6;
			this->name->Name = L"name";
			this->name->Width = 140;
			// 
			// unit
			// 
			this->unit->HeaderText = L"�.�.";
			this->unit->MinimumWidth = 6;
			this->unit->Name = L"unit";
			this->unit->Width = 66;
			// 
			// price
			// 
			this->price->HeaderText = L"����";
			this->price->MinimumWidth = 6;
			this->price->Name = L"price";
			this->price->Width = 72;
			// 
			// date_delivery
			// 
			this->date_delivery->HeaderText = L"���� ����. ��������";
			this->date_delivery->MinimumWidth = 6;
			this->date_delivery->Name = L"date_delivery";
			this->date_delivery->Width = 166;
			// 
			// quantity
			// 
			this->quantity->HeaderText = L"���-�� ������";
			this->quantity->MinimumWidth = 6;
			this->quantity->Name = L"quantity";
			this->quantity->Width = 128;
			// 
			// photo
			// 
			this->photo->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->photo->HeaderText = L"����������";
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
			this->check_price->Text = L"����";
			this->check_price->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(842, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"����� ��:";
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
			this->label_from->Text = L"��:";
			this->label_from->Click += gcnew System::EventHandler(this, &Main_Window::label2_Click);
			// 
			// label_to
			// 
			this->label_to->AutoSize = true;
			this->label_to->Location = System::Drawing::Point(1000, 169);
			this->label_to->Name = L"label_to";
			this->label_to->Size = System::Drawing::Size(27, 16);
			this->label_to->TabIndex = 10;
			this->label_to->Text = L"��:";
			// 
			// btn_purchase
			// 
			this->btn_purchase->Location = System::Drawing::Point(845, 331);
			this->btn_purchase->Name = L"btn_purchase";
			this->btn_purchase->Size = System::Drawing::Size(325, 50);
			this->btn_purchase->TabIndex = 11;
			this->btn_purchase->Text = L"�������� ���";
			this->btn_purchase->UseVisualStyleBackColor = true;
			this->btn_purchase->Click += gcnew System::EventHandler(this, &Main_Window::btn_purchase_click);
			// 
			// btn_registration
			// 
			this->btn_registration->Location = System::Drawing::Point(845, 401);
			this->btn_registration->Name = L"btn_registration";
			this->btn_registration->Size = System::Drawing::Size(325, 48);
			this->btn_registration->TabIndex = 12;
			this->btn_registration->Text = L"���������������� �����";
			this->btn_registration->UseVisualStyleBackColor = true;
			this->btn_registration->Click += gcnew System::EventHandler(this, &Main_Window::btn_registration_click);
			// 
			// btn_reset
			// 
			this->btn_reset->Location = System::Drawing::Point(845, 260);
			this->btn_reset->Name = L"btn_reset";
			this->btn_reset->Size = System::Drawing::Size(325, 54);
			this->btn_reset->TabIndex = 13;
			this->btn_reset->Text = L"�������� �������";
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
			this->check_date->Text = L"���� ���������� ������";
			this->check_date->UseVisualStyleBackColor = true;
			// 
			// check_name
			// 
			this->check_name->AutoSize = true;
			this->check_name->Location = System::Drawing::Point(845, 32);
			this->check_name->Name = L"check_name";
			this->check_name->Size = System::Drawing::Size(130, 20);
			this->check_name->TabIndex = 3;
			this->check_name->Text = L"������������";
			this->check_name->UseVisualStyleBackColor = true;
			this->check_name->CheckedChanged += gcnew System::EventHandler(this, &Main_Window::checkBox3_CheckedChanged);
			// 
			// btn_search
			// 
			this->btn_search->Location = System::Drawing::Point(845, 194);
			this->btn_search->Name = L"btn_search";
			this->btn_search->Size = System::Drawing::Size(325, 54);
			this->btn_search->TabIndex = 14;
			this->btn_search->Text = L"�����";
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
				this->�������������ToolStripMenuItem,
					this->����������������ToolStripMenuItem, this->����������������ToolStripMenuItem, this->�������ToolStripMenuItem
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(219, 100);
			// 
			// �������������ToolStripMenuItem
			// 
			this->�������������ToolStripMenuItem->Name = L"�������������ToolStripMenuItem";
			this->�������������ToolStripMenuItem->Size = System::Drawing::Size(218, 24);
			this->�������������ToolStripMenuItem->Text = L"�������������";
			this->�������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::�������������ToolStripMenuItem_Click);
			// 
			// ����������������ToolStripMenuItem
			// 
			this->����������������ToolStripMenuItem->Name = L"����������������ToolStripMenuItem";
			this->����������������ToolStripMenuItem->Size = System::Drawing::Size(218, 24);
			this->����������������ToolStripMenuItem->Text = L"�������� � �������";
			this->����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::����������������ToolStripMenuItem_Click);
			// 
			// ����������������ToolStripMenuItem
			// 
			this->����������������ToolStripMenuItem->Name = L"����������������ToolStripMenuItem";
			this->����������������ToolStripMenuItem->Size = System::Drawing::Size(218, 24);
			this->����������������ToolStripMenuItem->Text = L"����� �����������";
			this->����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::����������������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(218, 24);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Window::�������ToolStripMenuItem_Click);
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
		System::Void OnFormClosing(System::Object^ sender, FormClosingEventArgs^ e) // �������� ��������� ����
		{
			//test->SaveToJsonFile("Base.json"); // ����� ����������� ��� ����������
			Application::Exit();
		}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {}

	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {}
	// ������� �� ������ ����������� ������
	private: System::Void btn_registration_click(System::Object^ sender, System::EventArgs^ e)
	{
		// ������ ����� ����� � �������� ��������� ��������
		Shop::Registration_Window^ registrationWindow = gcnew Registration_Window(test);
		// ���������� ����
		registrationWindow->Show();
		// ����������� �� ������� �������� ������� ����
		registrationWindow->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Main_Window::RegistrationWindow_FormClosed);
	}
	// ������� �������� ���� ����������� ����� ������
	void Main_Window::RegistrationWindow_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
	{
		// �������� ����������� ��������� � ����������� ��������
		this->test = safe_cast<Registration_Window^>(sender)->GetProductList();
		// ��������� dataGridView
		dataGridView1->Rows->Clear();
		Product^ current = test->head;
		while (current != nullptr)
		{
			dataGridView1->Rows->Add(current->name, current->unit, current->price, current->last_delivery,
				current->quantity, System::Drawing::Image::FromFile(current->photo));
			current = current->next;
		}
	}
	// ������� �� ������ ������� ����
	private: System::Void btn_purchase_click(System::Object^ sender, System::EventArgs^ e)
	{
		// ������ ����� ����� � �������� 2 ��������� ��������: ������� ������� � ���� ������
		Purchase_Window^ purchaseWindow = gcnew Purchase_Window(purchase, test);
		// ����������� �� ������� �������� ������� ����
		purchaseWindow->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Main_Window::PurchaseWindow_FormClosed);
		// ���������� ����
		purchaseWindow->Show();
	}
	// ������� �������� ���� ������� ����
	void Main_Window::PurchaseWindow_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
	{
		dataGridView1->Rows->Clear();
		test->DeleteAllSoldOut(); // �� ����� ���� ����� �������� 0 � ���� ���������� � �������, ������ ��������� ������� ��
		Product^ current = test->head; 
		// ��������� dataGridView
		while (current != nullptr)
		{
			dataGridView1->Rows->Add(current->name, current->unit, current->price, current->last_delivery,
				current->quantity, System::Drawing::Image::FromFile(current->photo));
			current = current->next;
		}
	}
	// ������� �� ������ ������
	private: System::Void btn_search_click(System::Object^ sender, System::EventArgs^ e)
	{
		// ������� ���������, ������� ����� ������������ � dataGridView
		Product_list^ searchList = gcnew Product_list;
		// ������� �������� checkbox'��
		bool usename = check_name->Checked; bool usedate = check_date->Checked; bool useprice = check_price->Checked; 
		// ��������� �����
		searchList = test->Search(TB_name->Text, MTB_delivery->Text, MTB_priceFrom->Text, MTB_priceTo->Text, usename, usedate, useprice);
		dataGridView1->Rows->Clear();
		Product^ current = searchList->head;
		// ������� ��������� �������� ������ � dataGridView
		while (current != nullptr)
		{
			dataGridView1->Rows->Add(current->name, current->unit, current->price, current->last_delivery,
				current->quantity, System::Drawing::Image::FromFile(current->photo));
			current = current->next;
		}
	}
	// ������� �� ������ ������� �������� ������
	private: System::Void btn_reset_click(System::Object^ sender, System::EventArgs^ e)
	{
		// ������� ������ dataGridView
		dataGridView1->Rows->Clear();
		Product^ current = test->head;
		// ��������� dataGridView
		while (current != nullptr)
		{
			dataGridView1->Rows->Add(current->name, current->unit, current->price, current->last_delivery,
				current->quantity, System::Drawing::Image::FromFile(current->photo));
			current = current->next;
		}
		// ������� ������ ������
		dataGridView1->AllowUserToAddRows = false;
	}
	// ��������� ������� ������ ������ � dataGridView (��� ������ contextMenuStrip)
	private: System::Void dataGridView1_CellMouseDown(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e)
	{
		if (e->Button == Windows::Forms::MouseButtons::Right && e->RowIndex >= 0 && e->ColumnIndex >= 0)
		{
			// �������� ������, �� ������� �������� ������ ������� ����
			dataGridView1->CurrentCell = dataGridView1[e->ColumnIndex, e->RowIndex];

			// ���������� ����������� ����
			contextMenuStrip1->Show(Cursor->Position);
		}
	}
	// �������� ���� ������������� contextMenuStrip'�
	private: System::Void �������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// �������� ������ ������ ������, �������� �������� name � unit ��� ���� ������
		int rowIndex = dataGridView1->CurrentCell->RowIndex;
		String^ productName = dataGridView1->Rows[rowIndex]->Cells["name"]->Value->ToString();
		String^ productUnit = dataGridView1->Rows[rowIndex]->Cells["unit"]->Value->ToString();
		Product^ current = test->head;
		while (current != nullptr) // ���� ������ ��������� �� ����� name � unit
		{
			if (current->name == productName && current->unit == productUnit)
			{
				break; // ������� ������ �����
			}
			current = current->next;
		}
		// ������� ���� � �������� � ���� ������ �����
		Editing_Window^ editWin = gcnew Editing_Window(current);
		// ����������� �� ������� �������� ������� ����
		editWin->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Main_Window::EditingWindow_FormClosed);
		// ������� ����
		editWin->Show();
	}
	// ������� �������� ���� �������������� ������
	void Main_Window::EditingWindow_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
	{	
		// ������� ������ dataGridView
		dataGridView1->Rows->Clear();
		test->DeleteAllSoldOut(); // ����� �������� ������� ���� � ��� ����� ��������� Product � ����� quantity = 0, ��������� ������� ���
		Product^ current = test->head;
		while (current != nullptr) // ��������� dataGridView
		{
			dataGridView1->Rows->Add(current->name, current->unit, current->price, current->last_delivery,
				current->quantity, System::Drawing::Image::FromFile(current->photo));
			current = current->next;
		}
	}
	// �������� ���� �������� � ������� contextMenuStrip'�
	private: System::Void ����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// �������� ������ ������ ������, �������� �������� name � unit ��� ���� ������
		int rowIndex = dataGridView1->CurrentCell->RowIndex;
		String^ productName = dataGridView1->Rows[rowIndex]->Cells["name"]->Value->ToString();
		String^ productUnit = dataGridView1->Rows[rowIndex]->Cells["unit"]->Value->ToString();
		Product^ current = test->head; 
		Product^ currentInPurchase;
		bool productFound = false;

		while (current != nullptr) // ���� �� �������� ��� ���� ������
		{
			if (current->name == productName && current->unit == productUnit) // ���� ������ ������� (�� ������� � ������� ������ ������������ � �.�.)
			{
				currentInPurchase = purchase->head; 
				while (currentInPurchase != nullptr) // ���� �� ������� � ���� ��������� ���
				{
					if (currentInPurchase->name == current->name && currentInPurchase->unit == current->unit) // ������ ����� ������
					{
						if (currentInPurchase->quantity < current->quantity) // ���� ������ �� ������, ��� ��� ���� �� ������
						{
							currentInPurchase->quantity += 1; // ��������� � ��� ���������� � �������
							productFound = true;
							break;
						}
						else
						{
							MessageBox::Show("������������ " + current->name + " �� ������.", "������ ��� ����������", MessageBoxButtons::OK, MessageBoxIcon::Error);
							return;
						}
					}
					currentInPurchase = currentInPurchase->next; // ��������� � ���������� ������ � ������� ���� ������� �� ������
				}
				if (!productFound) // ���� ����� �� ������ � �������, �� ��������� ��� � ����������� 1
				{
					purchase->AddProduct(current->name,current->photo,current->unit,current->price,1,current->last_delivery);
				}
				break;
			}
			else (current = current->next);
		}
	}
	private: System::Void dataGridView1_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e){}
	// �������� ���� ����� ����������� contextMenuStrip'�
	private: System::Void ����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// �������� ������ ������ ������, �������� �������� name � unit ��� ���� ������
		int rowIndex = dataGridView1->CurrentCell->RowIndex;
		String^ productName = dataGridView1->Rows[rowIndex]->Cells["name"]->Value->ToString();
		String^ productUnit = dataGridView1->Rows[rowIndex]->Cells["unit"]->Value->ToString();
		Product^ current = test->head;
		while (current != nullptr) // ���� ������ ��������� �� ����� name � unit
		{
			if (current->name == productName && current->unit == productUnit)
			{
				break; // ������� ������ �����
			}
			current = current->next;
		}
		// ������� ���� � �������� � ���� ������ �����
		Receipt_Window^ receiptWin = gcnew Receipt_Window(current);
		// ����������� �� ������� �������� ������� ����
		receiptWin->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Main_Window::ReceiptWindow_FormClosed);
		// ������� ����
		receiptWin->Show();
	}
	// ������� �������� ���� ������ ����������� ������
	void Main_Window::ReceiptWindow_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
	{
		// ������� ������ dataGridView
		dataGridView1->Rows->Clear();
		Product^ current = test->head;
		while (current != nullptr) // ��������� dataGridView
		{
			dataGridView1->Rows->Add(current->name, current->unit, current->price, current->last_delivery,
				current->quantity, System::Drawing::Image::FromFile(current->photo));
			current = current->next;
		}
	}
	// �������� ���� ������� contextMenuStrip'�
	private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// �������� ������ ������ ������, �������� �������� name � unit ��� ���� ������
		int rowIndex = dataGridView1->CurrentCell->RowIndex;
		String^ productName = dataGridView1->Rows[rowIndex]->Cells["name"]->Value->ToString();
		String^ productUnit = dataGridView1->Rows[rowIndex]->Cells["unit"]->Value->ToString();
		Product^ current = test->head;
		while (current != nullptr) // ���� ������ ��������� �� ����� name � unit
		{
			if (current->name == productName && current->unit == productUnit)
			{
				test->DeleteProduct(current); // ������� ��������� �����
				break; // ���������� ����������� ������ �� ���������
			}
			current = current->next;
		}
		dataGridView1->Rows->Clear(); // ������� ������ dataGridView
		current = test->head;
		while (current != nullptr) // ��������� dataGridView
		{
			dataGridView1->Rows->Add(current->name, current->unit, current->price, current->last_delivery,
				current->quantity, System::Drawing::Image::FromFile(current->photo));
			current = current->next;
		}
	}
};
}


