#pragma once
#include "Start_window.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

[STAThread]
int main(cli::array<String^>^ args)
{ 

    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();    
    
    if (std::filesystem::exists("Base.json") == false) // Сделано для создания первоначального JSON-файла
    {
        // Создание первого хранилища элементов и наполнение его объектами
        Product_list^ productList = gcnew Product_list();
        productList->AddProduct("Suxov", "pictureBox1.Image.jpg", "1 people", 10.0, 5, "01.01.2024");
        productList->AddProduct("Baltika 9", "9.jpg", "0.500 L.", 20.0, 3, "02.01.2024");
        productList->AddProduct("Ohota", "1.png", "0.500 L.", 30.0, 4, "03.01.2024");
        // Преобразование в JSON
        productList->SaveToJsonFile("Base.json");
    
        Product_list^ test = gcnew Product_list();
    }
    
    Shop::Start_window form;
    Application::Run(% form);
    

    return 0;
}