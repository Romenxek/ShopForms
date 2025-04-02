#pragma once
#include <cliext/vector>
#include <nlohmann/json.hpp>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <filesystem>
#include <iostream>

using namespace System;
using namespace System::Drawing;
using namespace System::IO;
using json = nlohmann::json;
namespace fs = std::filesystem;
using namespace std;

//������
ref struct Product
{
    // ����
    String^ name;
    String^ photo;
    String^ unit;
    double price;
    int quantity;
    String^ last_delivery;
    Product^ next;

    // �����������
    Product(String^ name, String^ photo, String^ unit, double price, int quantity, String^ last_delivery, Product^ next)
    {
        this->name = name;
        this->photo = photo;
        this->unit = unit;
        this->price = price;
        this->quantity = quantity;
        this->last_delivery = last_delivery;
        this->next = nullptr;
    }

    // ������ �������
    String^ GetName() { return name; }
    void SetName(String^ value) { name = value; }

    String^ GetPhoto() { return photo; }
    void SetPhoto(String^ value) { photo = value; }

    String^ GetUnit() { return unit; }
    void SetUnit(String^ value) { unit = value; }

    double GetPrice() { return price; }
    void SetPrice(double value) { price = value; }

    int GetQuantity() { return quantity; }
    void SetQuantity(int value) { quantity = value; }

    String^ GetLastDelivery() { return last_delivery; }
    void SetLastDelivery(String^ value) { last_delivery = value; }

    Product^ GetNext() { return next; }
    void SetNext(Product^ value) { next = value; }

    // ������� ��� �������������� ������� � JSON �������������
    json ToJSON()
    {
        nlohmann::json j{};
        msclr::interop::marshal_context context;// �������� ��������� ��� ������������ �������������������
        j["name"] = context.marshal_as<std::string>(name);
        j["photo"] = context.marshal_as<std::string>(photo);
        j["unit"] = context.marshal_as<std::string>(unit);
        j["price"] = std::to_string(price);
        j["quantity"] = std::to_string(quantity);
        j["last_delivery"] = context.marshal_as<std::string>(last_delivery);
        return j;
    }
    // �������������� ����� ��������
    void Edit_Product(String^ newname, String^ newphoto, String^ newunit, double newprice, int newquantity, String^ newlastdelivery)
    {
        this->name = newname;
        this->photo = newphoto;
        this->unit = newunit;
        this->price = newprice;
        this->quantity = newquantity;
        this->last_delivery = newlastdelivery;
    }
};

// ��������� �������� Product
ref class Product_list
{
    // ����
    public: Product^ head; // ������ ������������ ������
    private: int lenght; // ����� ������������ ������
    // �����������
    public:
    Product_list()
    {
        head = nullptr;
        lenght = 0;
    }

    // ���������� � ��������� �� �����
    void AddProduct(String^ name, String^ photo, String^ unit, double price, int quantity, String^ last_delivery)
    {
        Product^ newProduct = gcnew Product(name, photo, unit, price, quantity, last_delivery, nullptr);

        if (head == nullptr) // ���� ������ ������
        {
            head = newProduct; // ����������� - ������ �������
        }
        else // ���� �� ������
        {
            Product^ current = head;
            while (current->next != nullptr) // ���� ��������� ������� ������
            {
                current = current->next;
            }
            current->next = newProduct; // ��������� ����� ������� � ����� ������
        }
        lenght += 1;
    }

    // ���������� � ��������� ��� ������������� �������
    void AddOtherProduct(Product^ product)
    {
        // ������������� ������ �������� � ����� ������, �� ���������� �� null 
        Product^ productcopy = gcnew Product(product->name, product->photo, product->unit, 
            product->price, product->quantity, product->last_delivery, nullptr);
        productcopy->next = nullptr;
        if (head == nullptr) // ���� ������ ������
        {
            head = productcopy; // ����������� - ������ �������
        }
        else // ���� �� ������
        {
            Product^ current = head;
            while (current->next != nullptr) // ���� ��������� ������� ������
            {
                current = current->next;
            }
            current->next = productcopy; // ��������� ����� ������� � ����� ������
        }
        lenght += 1;
    }

    // �������� ����������� �������
    bool DeleteProduct(Product^ needToDelete) // �������� ���������� �� ������� ��������� ���������
    {
        if (head == nullptr) return false; // ���� ������ ����, �� ������ �� ������

        Product^ current = head;

        if (current->name == needToDelete->name && current->unit == needToDelete->unit) // ���� ������ ��������� �� ����� ����� � �.�. 
        {
            this->head = current->next; // ������ ���������� ������
            lenght -= 1;
            return true; // ����� �������
        }

        while (current->next != nullptr) // ���� ������ �� ��������� �� �����, �� ��������� �� ����� ����� � �.�. ���������, ���� ��������� �� null
        {
            if (current->next->name == needToDelete->name || current->next->unit == needToDelete->unit) // ���������
            {
                current->next = current->next->next; // ��������� �� ��������� ��������� �� ��� ���������
                lenght -= 1;
                return true;
            }
            current = current->next; // �� ���������, ���� �� ���������
        }
    }

    // ������������ ��������� ��������
    json To_JSON() 
    {
        json products = json::array();
        Product^ current = head;
        while (current != nullptr)
        {
            products.push_back(current->ToJSON()); // ����������� ������� �� ��������� Product
            current = current->next;
        }
        return products;
    }

    // ������� ��� ���������� ������� ������ � ���� � ������� JSON
    void SaveToJsonFile(std::string filename)
    {
        json needtosave = To_JSON();// �������� JSON ������� ��� ����������

        std::ofstream file(filename);// ��������� ���� ��� ������

        if (file.is_open())// ���� ������
        {
            // ���������� JSON � ����
            file << needtosave.dump(4);
            file.close();
        }
    }

    // ������� ��� �������� ������ �� JSON ����� � ���������� ��������� �������
    void LoadFromJsonFile(std::string filename)
    {
        std::ifstream file(filename);
        if (!file.is_open()) // ���������, ������� �� ������ ����
        {
            throw std::runtime_error("Failed to open file");
        }

        json data;
        file >> data; // ������ ������ �� ����� � JSON ������
        file.close();

        head = nullptr;

        for (const auto& item : data) // ������ �� ���� ��������� � JSON �������
        {
            String^ name = gcnew String(item["name"].get<std::string>().c_str());
            String^ photo = gcnew String(item["photo"].get<std::string>().c_str());
            String^ unit = gcnew String(item["unit"].get<std::string>().c_str());
            double price = std::stod(item["price"].get<std::string>());
            int quantity = std::stoi(item["quantity"].get<std::string>());
            String^ last_delivery = gcnew String(item["last_delivery"].get<std::string>().c_str());

            AddProduct(name, photo, unit, price, quantity, last_delivery);// ���������� � ��������� �� ���������� �����
        }
    }
    // ����� ������
    int Length() { return lenght; };

    /*����� �� �����, ���� ���������� ������, ��������� ���; ������� �������� - ������� ������, ���� 
    true �� ��������������� ������� - ���������� ����������� ����������� ������ �� ���� ��������*/
    Product_list^ Search(String^ name, String^ last_delivery, String^ price_from, String^ price_to, bool use_name, bool use_date, bool use_price)
    {
        Product_list^ result = gcnew Product_list;
        Product^ current = this->head;

        while (current != nullptr)
        {
            bool match = true;// ����� ��� ��������� ���������� ���������� �� ������ �������� ������ (������ �����������)

            if (use_name && !String::IsNullOrEmpty(name)) // ���� ������������ �� ������� ������ � nameTextBox � ������ ���, �� ��������� ���
            {
                if (current->name->ToLower() != name->ToLower()) // ���� �� ��������� �� ����� - �� ��������� 
                {
                    match = false;
                }
            }

            if (use_date && !String::IsNullOrEmpty(last_delivery)) // ���� ������������ �� ������� ������ � last_delivery_TextBox � ������ ���, �� ��������� ���
            {
                if (current->last_delivery != last_delivery) // ���� �� ��������� �� ���� - �� ��������� 
                {
                    match = false;
                }
            }

            if (use_price)
            {
                double price_from_val = System::Convert::ToDouble(price_from);
                double price_to_val = System::Convert::ToDouble(price_to);
                if (current->price < price_from_val || current->price > price_to_val)
                {
                    match = false;
                }
            }

            if (match)
            {
                result->AddProduct(current->name, current->photo, current->unit, current->price, current->quantity, current->last_delivery);
            }

            current = current->next;
        }
        return result;
    }
    
    // ������� ��� � 0 � ���� ���������� (� ������ ��� ��������� ������)
    void DeleteAllSoldOut()
    {
        Product^ current = this->head;
        while (current != nullptr) // ��� �� ���� � ��������� ���� ����������
        {
            if (current->quantity <= 0)
            {
                this->DeleteProduct(current);
            }
            current = current->next;
        }
    }
};

