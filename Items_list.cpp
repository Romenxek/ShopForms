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

//объект
ref struct Product
{
    // Поля
    String^ name;
    String^ photo;
    String^ unit;
    double price;
    int quantity;
    String^ last_delivery;
    Product^ next;

    // Конструктор
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

    // Методы доступа
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

    // Функция для преобразования объекта в JSON представление
    json ToJSON()
    {
        nlohmann::json j{};
        msclr::interop::marshal_context context;// Создание контекста для межъязыковой интероперабельности
        j["name"] = context.marshal_as<std::string>(name);
        j["photo"] = context.marshal_as<std::string>(photo);
        j["unit"] = context.marshal_as<std::string>(unit);
        j["price"] = std::to_string(price);
        j["quantity"] = std::to_string(quantity);
        j["last_delivery"] = context.marshal_as<std::string>(last_delivery);
        return j;
    }
    // Редактирование полей продукта
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

// Хранилище объектов Product
ref class Product_list
{
    // Поля
    public: Product^ head; // Начало односвязного списка
    private: int lenght; // Длина односвязного списка
    // Конструктор
    public:
    Product_list()
    {
        head = nullptr;
        lenght = 0;
    }

    // Добавление в хранилище по полям
    void AddProduct(String^ name, String^ photo, String^ unit, double price, int quantity, String^ last_delivery)
    {
        Product^ newProduct = gcnew Product(name, photo, unit, price, quantity, last_delivery, nullptr);

        if (head == nullptr) // Если список пустой
        {
            head = newProduct; // Добавляемый - первый элемент
        }
        else // Если не пустой
        {
            Product^ current = head;
            while (current->next != nullptr) // Ищем последний элемент списка
            {
                current = current->next;
            }
            current->next = newProduct; // Добавляем новый продукт в конец списка
        }
        lenght += 1;
    }

    // Добавление в хранилище уже существующего объекта
    void AddOtherProduct(Product^ product)
    {
        // Инициализация нового продукта с этими полями, но указателем на null 
        Product^ productcopy = gcnew Product(product->name, product->photo, product->unit, 
            product->price, product->quantity, product->last_delivery, nullptr);
        productcopy->next = nullptr;
        if (head == nullptr) // Если список пустой
        {
            head = productcopy; // Добавляемый - первый элемент
        }
        else // Если не пустой
        {
            Product^ current = head;
            while (current->next != nullptr) // Ищем последний элемент списка
            {
                current = current->next;
            }
            current->next = productcopy; // Добавляем новый продукт в конец списка
        }
        lenght += 1;
    }

    // Удаление конкретного объекта
    bool DeleteProduct(Product^ needToDelete) // Удаление происходит по первому найденому вхождению
    {
        if (head == nullptr) return false; // Если список пуст, то ничего не делаем

        Product^ current = head;

        if (current->name == needToDelete->name && current->unit == needToDelete->unit) // Если первый совпадает по полям имени и е.и. 
        {
            this->head = current->next; // Второй становится первым
            lenght -= 1;
            return true; // Конец функции
        }

        while (current->next != nullptr) // Если первый не совпадает по полям, то проверяем по полям имени и е.и. следующий, пока следующий не null
        {
            if (current->next->name == needToDelete->name || current->next->unit == needToDelete->unit) // Совпадает
            {
                current->next = current->next->next; // Указатель на следующий указывает на его следующий
                lenght -= 1;
                return true;
            }
            current = current->next; // Не совпадает, идем на следующий
        }
    }

    // Сериализация хранилища объектов
    json To_JSON() 
    {
        json products = json::array();
        Product^ current = head;
        while (current != nullptr)
        {
            products.push_back(current->ToJSON()); // Одноименная функция из структуры Product
            current = current->next;
        }
        return products;
    }

    // Функция для сохранения объекта класса в файл в формате JSON
    void SaveToJsonFile(std::string filename)
    {
        json needtosave = To_JSON();// Получаем JSON объекты для сохранения

        std::ofstream file(filename);// Открываем файл для записи

        if (file.is_open())// Если открыт
        {
            // Записываем JSON в файл
            file << needtosave.dump(4);
            file.close();
        }
    }

    // Функция для загрузки данных из JSON файла и обновления состояния объекта
    void LoadFromJsonFile(std::string filename)
    {
        std::ifstream file(filename);
        if (!file.is_open()) // Проверяем, успешно ли открыт файл
        {
            throw std::runtime_error("Failed to open file");
        }

        json data;
        file >> data; // Чтение данных из файла в JSON объект
        file.close();

        head = nullptr;

        for (const auto& item : data) // Проход по всем элементам в JSON объекте
        {
            String^ name = gcnew String(item["name"].get<std::string>().c_str());
            String^ photo = gcnew String(item["photo"].get<std::string>().c_str());
            String^ unit = gcnew String(item["unit"].get<std::string>().c_str());
            double price = std::stod(item["price"].get<std::string>());
            int quantity = std::stoi(item["quantity"].get<std::string>());
            String^ last_delivery = gcnew String(item["last_delivery"].get<std::string>().c_str());

            AddProduct(name, photo, unit, price, quantity, last_delivery);// Добавление в хранилище по полученным полям
        }
    }
    // Длина списка
    int Length() { return lenght; };

    /*Поиск по имени, дате последнего завоза, интервалу цен; булевые значения - маркера поиска, если 
    true на соответствующем маркере - возвращает пересечение результатов поиска по этим маркерам*/
    Product_list^ Search(String^ name, String^ last_delivery, String^ price_from, String^ price_to, bool use_name, bool use_date, bool use_price)
    {
        Product_list^ result = gcnew Product_list;
        Product^ current = this->head;

        while (current != nullptr)
        {
            bool match = true;// Метка для избегания повторного добавления по разным маркерам поиска (логика пересечения)

            if (use_name && !String::IsNullOrEmpty(name)) // Если пользователь не написал ничего в nameTextBox и выбрал его, то выберутся все
            {
                if (current->name->ToLower() != name->ToLower()) // Если не совпадает по имени - не добавляем 
                {
                    match = false;
                }
            }

            if (use_date && !String::IsNullOrEmpty(last_delivery)) // Если пользователь не написал ничего в last_delivery_TextBox и выбрал его, то выберутся все
            {
                if (current->last_delivery != last_delivery) // Если не совпадает по дате - не добавляем 
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
    
    // Удаляем все с 0 в поле количества (и меньше для избегания ошибок)
    void DeleteAllSoldOut()
    {
        Product^ current = this->head;
        while (current != nullptr) // Идём по всем и проверяем поле количества
        {
            if (current->quantity <= 0)
            {
                this->DeleteProduct(current);
            }
            current = current->next;
        }
    }
};

