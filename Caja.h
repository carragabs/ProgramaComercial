#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#define NOMINMAX
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include<string>
#include <fstream>

using namespace std;

struct producto
{
    int codigo;
    int cantidad;
    double precioUnitario;
    //double impuesto;
    //string nombre;
    string descripcion;
    bool existe;
};

struct productoReturn
{
    int codigo;
    int cantidad;
    double precioUnitario;
    //double impuesto;
    //string nombre;
    char descripcion[30];
};


#include<iostream>
#include<string>
using namespace std;

int countStrSpaces(string s , char c)
{
    int count = 0;

    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == c)
        {
            count++;
        }
    }
    return count;
    //cout << " The Number Of Spaces In The String: " << count;
}

class Caja
{
public:
    //ATRIBUTOS
    bool abierta;
    double saldoTotal;
    double saldoMinimo; //el min de saldo para que este abierta
    double saldoInicial;
    double ganancias;
    double subtotal, grantotal;
    double ISV;
    ofstream archivo;

    //CONSEGUIR INFO DEL CURSOR EN PANTALLA CONSOLA
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorPos;
    CONSOLE_SCREEN_BUFFER_INFO cursorinfo;

    Caja() //CONSTRUCTOR
    {
        abierta = false;
        saldoTotal = 0;
        saldoMinimo = 0;
        saldoInicial = 0;
        ganancias = 0;
        subtotal = 0;
        grantotal = 0;
        ISV = 0.12;
    }

    //FUNCIONES
    double getSaldo();
    void infoSaldo();
    void actualizarSaldo(double cantidad);
    void reiniciarSaldo();
    void setSaldoInicial(double saldo);
    void reiniciarSaldoInicial();
    void reiniciarGanancias();
    bool compararSaldoMinimo();
    void compararSaldoInicial();
    void marcarAbierta();
    void actualizarGanancias(double cantidad);
    double getGanancias();
    double getSubtotal();
    double getGrantotal();
    double getISV();
    void facturar(vector<producto> pAlmacenados);
    double imprimirFactura(vector<producto> productos,
        vector<double> preciosTotalXProd, string HeaderinfoProducto);
    void calcularCambio(double grantotal, double pago);
    void getDatosFactura();

    bool cerrarCaja();
    void escribirDatosProd(producto prod);
    void ReportesCaja();

private:

};

double Caja::getSaldo()
{
    return saldoTotal;
}

void Caja::infoSaldo()
{
    cout << "SALDO ACTUAL: " << saldoTotal << endl;
}

void Caja::setSaldoInicial(double saldo)
{
    saldoInicial = saldo;
}

void Caja::reiniciarGanancias()
{
    ganancias = 0;
}

void Caja::reiniciarSaldoInicial()
{
    saldoInicial = 0;
}

bool Caja::compararSaldoMinimo()
{
    if (saldoTotal > saldoMinimo)
        return true;

    return false;
}

void Caja::compararSaldoInicial()
{
    double saldoTeorico = saldoInicial + ganancias;
    cout << "SALDO INICIAL: " << saldoInicial << endl;
    cout << "GANACIAS DE ESTA CAJA: " << ganancias << endl;
    cout << "SALDO TEORICO: " << saldoTeorico << endl;
    cout << "SALDO ACTUAL: " << saldoTotal << endl;

    if (saldoTotal == saldoTeorico)
        cout << "El saldo actual concuerda con el saldo teorico." << endl;
    else
        cout << "El saldo actual NO concuerda con el saldo teorico." << endl;
}

double Caja::getGanancias()
{
   return ganancias;
}

double Caja::getSubtotal()
{
    return ganancias;
}

double Caja::getGrantotal()
{
    return ganancias;
}

double Caja::getISV()
{
    return ganancias;
}

void Caja::reiniciarSaldo()
{
    saldoTotal = 0;
    cout << "INFORMACION DE SALDO REINCIADA" << endl;
}

void Caja::actualizarSaldo(double cantidad)
{
    saldoTotal += cantidad;
}

void Caja::actualizarGanancias(double cantidad)
{
    ganancias += cantidad;
}

void Caja::marcarAbierta()
{
    abierta = true;
    cout << "CAJA MARCADA COMO ABIERTA" << endl;
}

void Caja::escribirDatosProd(producto prod)
{

    string codigostr = to_string(prod.codigo);

    //CODIGO
    if (codigostr.size() > 4)
        cout << codigostr.substr(0,4);
    
    else if (codigostr.size() < 4) 
    {
        cout << codigostr;
        for (size_t i = 0; i < 4 - codigostr.size(); i++)
        {
            cout << " ";
        }
    }
    else
        cout << codigostr;
    
    cout << "          ";
    //DESCRIPCION
    if (prod.descripcion.size() > 16)
        cout << prod.descripcion.substr(0, 16);
    else if (prod.descripcion.size() < 16)
    {
        cout << prod.descripcion;
        for (size_t i = 0; i < 16 - prod.descripcion.size(); i++)
        {
            cout << " ";
        }

    }
    else
        cout << prod.descripcion;
    cout << "        " << "       ";
    //PRECIO UNITARIO
    string preciostr = to_string(prod.precioUnitario);

    if (preciostr.size() > 4)
        cout << preciostr.substr(0, 4);

    else if (preciostr.size() < 4)
    {
        cout << preciostr;
        for (size_t i = 0; i < 4 - preciostr.size(); i++)
        {
            cout << " ";
        }
    }
    else
        cout << preciostr;

    
    cout << "                       ";

    GetConsoleScreenBufferInfo(hConsole, &cursorinfo);
    cursorPos = cursorinfo.dwCursorPosition;    

}

void Caja::facturar(vector<producto> pAlmacenados)
{
    vector<producto> productos;
    vector<double> preciosTotalXProd;
    producto prodActual;
    int codigo = 0;
    prodActual = { 0,0,0,"",false };

    string HeaderinfoProducto = "";

    COORD cursorCantCambiar;

    subtotal = 0;
    grantotal = 0;

    while (true)
    {
        system("cls");
        cursorCantCambiar = { 0 , 0 };
        prodActual.existe = false;

        //pedir datos
        system("cls");
        cout << "FACTURACION DE PRODUCTO" << endl;
        cout << "------------------------" << endl << endl;

        HeaderinfoProducto = "  Codigo  \tDescripcion\t\t";
        HeaderinfoProducto += "Precio Unitario\t\tCantidad a Comprar\tTotal\n";

        cout << endl << HeaderinfoProducto;

        for (size_t i = 0; i < HeaderinfoProducto.size()
            + countStrSpaces(HeaderinfoProducto,'\t') * 4
            + countStrSpaces(HeaderinfoProducto, ' ') + 5; i++)
        {
            cout << "-";
        }
        cout << endl;
        for (size_t i = 0; i < productos.size(); i++)
        {
            escribirDatosProd(productos[i]);
            cout << productos[i].cantidad;
            cout << "       \t" << preciosTotalXProd[i];
            cout << endl;
        }

        //LINEA DE INPUT
        cout << "              ****************        "
            << "       0000                       000       \t00000\r";

        GetConsoleScreenBufferInfo(hConsole, &cursorinfo);
        cursorPos = cursorinfo.dwCursorPosition;
        cin >> prodActual.codigo;
        codigo = prodActual.codigo;

        if (codigo == -1)
            break;

        for (size_t i = 0; i < pAlmacenados.size(); i++)
        {
            if (prodActual.codigo == pAlmacenados[i].codigo)
                prodActual = pAlmacenados[i];
        }
       
        if (!prodActual.existe )
        {
            SetConsoleCursorPosition(hConsole, cursorPos);
            cout << "INEXISTENTE";
            system("pause>nul");
            cin.ignore();
            system("cls");
            continue;
        }


        system("cls");


        cout << "FACTURACION DE PRODUCTO" << endl;
        cout << "------------------------" << endl << endl;
        cout << endl << HeaderinfoProducto;

        for (size_t i = 0; i < HeaderinfoProducto.size()
            + countStrSpaces(HeaderinfoProducto, '\t') * 4
            + countStrSpaces(HeaderinfoProducto, ' ') + 5; i++)
        {
            cout << "-";
        }

        cout << endl;

        for (size_t i = 0; i < productos.size(); i++)
        {
            escribirDatosProd(productos[i]);
            if(productos[i].codigo == prodActual.codigo)
            {
                GetConsoleScreenBufferInfo(hConsole, &cursorinfo);
                cursorCantCambiar = cursorinfo.dwCursorPosition;

            }
            cout << productos[i].cantidad;
            cout << "       \t" << preciosTotalXProd[i];
            cout << endl;

        }

        if (cursorCantCambiar.X != 0)
        {
            SetConsoleCursorPosition(hConsole, cursorCantCambiar);
            cout << "   " << "       \t00000";
            SetConsoleCursorPosition(hConsole, cursorCantCambiar);
            cin >> prodActual.cantidad;
            SetConsoleCursorPosition(hConsole, cursorCantCambiar);
        
        } else
        {
            escribirDatosProd(prodActual);
            SetConsoleCursorPosition(hConsole, cursorPos);

            cout << "   " << "       \t00000";

            SetConsoleCursorPosition(hConsole, cursorPos);

            cin >> prodActual.cantidad;
            SetConsoleCursorPosition(hConsole, cursorPos);

        }

        //CANTIDAD
        string cantstr = to_string(prodActual.cantidad);

        if (cantstr.size() > 3)
        {
            cout << cantstr.substr(0, 3);
            prodActual.cantidad = stoi(cantstr);
        }

        else if (cantstr.size() < 3)
        {
            cout << cantstr;
            for (size_t i = 0; i < 3 - cantstr.size(); i++)
            {
                cout << " ";
            }
            prodActual.cantidad = stoi(cantstr);
        }
        else
        {
            cout << cantstr;
            prodActual.cantidad = stoi(cantstr);
        }
        cout << "       \t";

        if (cursorCantCambiar.X != 0)
        {
            for (size_t i = 0; i < productos.size(); i++)
            {
                if (prodActual.codigo == productos[i].codigo)
                {
                    productos[i] = prodActual;
                    preciosTotalXProd[i] = prodActual.precioUnitario * prodActual.cantidad;
                }

            }


        } else
        {
            preciosTotalXProd.push_back(prodActual.precioUnitario * prodActual.cantidad);
            productos.push_back(prodActual);
            //system("pause>nul");
        }

    }
    system("cls");

    if (productos.empty())
    {
        system("cls");
        cout << "No se facturo ningun producto" << endl;
        return;
    }


    //Los valores de vector productos 
    // seran actualizados por inventario, se llamaria una 
    //Funcion de Inventario desde Caja o de Caja desde Inventario
    //RETORNAR VECTOR PRODUCTOS A INVENTARIO PARA ACTUALIZAR CANTIDADES

    double grantotal = imprimirFactura(productos, preciosTotalXProd , HeaderinfoProducto);
    double pago;

    //EL CLIENTE PAGA
    //DALRE EL CAMBIO SI APLICA
    //SI NO SE TIENE CAMBIO, PREGUNTAR SI SE QUIERE AGREGAR MAS BILLETES
    //Y AGREGARLOS SI APLICA
    while (true)
    {
        cout << "Ingrese el pago del cliente: " << endl;
        cin >> pago;
        if(pago < grantotal)
        {
            cout << "EL PAGO ES MENOR AL TOTAL A PAGAR." << "(" << grantotal << ")"
                << " INGRESE LA CANTIDAD CORRECTA" << endl;
            continue;
        }
        break;
    }

    calcularCambio(grantotal,pago);

}


struct fecha
{
    int dia; int mes; int anio;
};

double Caja::imprimirFactura(vector<producto> productos,
    vector<double> preciosTotalXProd, string HeaderinfoProducto)
{

    string nombre;
    long long RTN = 0;
    time_t ttime = time(0);
    char* dt = ctime(&ttime);

    COORD totalespos;

    cout << endl << endl << endl << endl << endl << HeaderinfoProducto;

    for (size_t i = 0; i < HeaderinfoProducto.size()
        + countStrSpaces(HeaderinfoProducto, '\t') * 4
        + countStrSpaces(HeaderinfoProducto, ' ') + 5; i++)
    {
        cout << "-";
    }

    cout << endl;
    for (size_t i = 0; i < productos.size(); i++)
    {
        escribirDatosProd(productos[i]);
        cout << productos[i].cantidad;
        cout << "       \t" << preciosTotalXProd[i];
        cout << endl;
    }

    for (size_t i = 0; i < HeaderinfoProducto.size()
        + countStrSpaces(HeaderinfoProducto, '\t') * 4
        + countStrSpaces(HeaderinfoProducto, ' ') + 5; i++)
    {
        cout << "=";
    }

    cout << endl;
    GetConsoleScreenBufferInfo(hConsole, &cursorinfo);
    totalespos = cursorinfo.dwCursorPosition;

    SetConsoleCursorPosition(hConsole, {0,0} );

    cout << dt;
   /* cout << fechaActual.dia << "/" << fechaActual.mes << "/"
       << fechaActual.anio << "\t\n";*/

    cout << "NOMBRE: ";
    GetConsoleScreenBufferInfo(hConsole, &cursorinfo);
    cursorPos = cursorinfo.dwCursorPosition;
    cout << endl;
    for (size_t i = 0; i < HeaderinfoProducto.size()
        + countStrSpaces(HeaderinfoProducto, '\t') * 4
        + countStrSpaces(HeaderinfoProducto, ' ') + 5; i++)
    {
        cout << " ";
    }
    cout << endl;
    for (size_t i = 0; i < HeaderinfoProducto.size()
        + countStrSpaces(HeaderinfoProducto, '\t') * 4
        + countStrSpaces(HeaderinfoProducto, ' ') + 5; i++)
    {
        cout << "-";
    }

    SetConsoleCursorPosition(hConsole, cursorPos);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, nombre);

    SetConsoleCursorPosition(hConsole,cursorPos);
    cout << nombre;
    cout << "\t\tRTN: ";
    cin >> RTN;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    SetConsoleCursorPosition(hConsole, totalespos);
    
    subtotal = 0;
    producto prodActual;

    for (size_t i = 0; i < preciosTotalXProd.size(); i++)
    {
        subtotal += preciosTotalXProd[i];
    }

    grantotal = subtotal + subtotal * ISV;
    cout << "\nSUBTOTAL      : " << subtotal << endl;
    cout << "I.S.V.        : " << ISV * 100 << "%" << endl;
    cout << "TOTAL A PAGAR : " << grantotal << endl;
    system("pause>null");

    system("cls");
    return grantotal;
}


void Caja::calcularCambio(double grantotal, double pago)
{
    if (pago > grantotal)
    {
        if ((pago - grantotal) > saldoTotal)
        {
            char opcionCambio = ' ';
            cout << "El cajero no tiene suficiente dinero para el cambio" << endl;
            cout << "Debe Ingresar mas billetes o Ingresar el pago exacto." << endl;
            cout << "Desea Ingresar el cambio exacto?(S/N) ";
            cin >> opcionCambio;
            if (opcionCambio == 's' || opcionCambio == 'S')
            {
                system("cls");
                cout << "Pago exacto Ingresado" << endl;
                cout << "PAGO REALIZADO DE " << pago << endl;
                system("pause");
                actualizarSaldo(grantotal);
                actualizarGanancias(grantotal);
                return;
            }
            else
            {
                system("cls");
                cout << "Prosiga cuando se agreguen los billetes necesarios." << endl;
                system("pause");
                system("cls");
                actualizarSaldo(grantotal);
                actualizarGanancias(grantotal);
                cout << "PAGO REALIZADO DE " << pago << endl;
                cout << "CAMBIO AL CLIENTE: " << pago - grantotal << endl;
                return;
            }
        }
        actualizarSaldo( - (pago-grantotal) );
        actualizarSaldo(pago);
        actualizarGanancias(grantotal);
        cout << "PAGO REALIZADO DE " << pago << endl;
        cout << "CAMBIO AL CLIENTE: " << pago - grantotal << endl;
        return;
    }
    actualizarSaldo(pago);
    actualizarGanancias(pago);
    cout << "PAGO REALIZADO DE " << pago << endl;
}

bool Caja::cerrarCaja()
{
    char respCerrar;
    //cout << saldoTotal << endl;
    //cout << ganancias << endl;
    compararSaldoInicial();
    cout << "DESEA CERRAR LA CAJA?(S/N) " << endl;
    cin >> respCerrar;
    if (respCerrar != 'S' && respCerrar != 's')
        return false;

    reiniciarSaldo();
    reiniciarSaldoInicial();
    subtotal = 0; grantotal = 0;
    system("pause");
    abierta = false;
    return true;
}

void Caja::ReportesCaja()
{
    archivo.open("ReportesCaja.csv", ios::_Noreplace);

    archivo << "Total de Ventas: " << " , ";
    archivo << "SubTotal de Ventas: " << subtotal << " , ";
    archivo << "Total de Impuestos: " << ISV << " , ";
    archivo << "Total General de Ventas: " << grantotal << " , ";
    archivo << "Ganancias de caja: " << getGanancias() << endl;

    archivo.close();
}