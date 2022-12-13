#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;
struct Persona
{
	char nombre[20];
	int Codecuenta;
	int clave;
	bool rol;
	bool estatus;
};

class Users {

private:


public:
    Users();
    ~Users();

    bool validarRespuesta(char);
    void crearUser();
    bool validarususarios(int, int);
    bool validarExistencia(int);
    bool archivo_existe(string);
    queue<Persona> DevolverQueue();
    void cambiarClave(int , int );
    void CambiarEstado(int );
    bool ValidarAdmin(int );
};

 Users::Users() {
     queue<Persona> test;
     test = DevolverQueue();
     int contador = 0;
     while (!test.empty())
     {
         contador++;
         test.pop();
     }

     //crea un nuevo usuario si no existe 
     if (contador<=1) {
         Persona miPersona;
         string name = "Admin";
         miPersona.nombre, name.c_str();
         miPersona.Codecuenta = 1234;
         miPersona.clave = 12345;
         miPersona.rol = true;

         miPersona.estatus = true;
         ofstream archivo;  // objeto de la clase ofstream

         archivo.open("usuariosC.tes", ios::binary | ios::out | ios::app); //Indicamos la ubicación y nombre del archivo

         if (archivo_existe("usuariosC.tes") == false) {

             cout << "Ya existe";
             system("pause");
         }
         else
         {
             cout << "Escribiendo...";

             archivo.write((char*)&miPersona, sizeof(Persona));
             system("pause");
         }
     }
 }
 Users::~Users() {


 }
 void Users::crearUser() {
     
     char resp;
     queue<Persona> test;
     Persona miPersona;

     bool continuar = true;
     char respuesta;

     ofstream archivo;  // objeto de la clase ofstream

     archivo.open("usuariosC.tes", ios::binary | ios::out | ios::app); //Indicamos la ubicación y nombre del archivo

     cout << "Desea registrar una persona? (S/N):";
     cin >> respuesta;
     continuar = validarRespuesta(respuesta);



     while (continuar)
     
     {
         system("cls");
         cout << "Creador de usuarios" << endl;
         cout << "--------------------" << endl;
         cout << "Ingrese el nombre de la persona: ";
         cin >> miPersona.nombre;
         cout << "Ingresar el rol de la admin a la persona S/N?";
         cin >> resp;
         if (resp == 'S' || resp == 's')
         {
             miPersona.rol = true;
         }
         else
         {
             miPersona.rol = false;
         }
         cout << "Ingrese el numero de cuenta de la persona: ";
         cin >> miPersona.Codecuenta;
         miPersona.clave = 12345;
         miPersona.estatus = true;
        
         test.push(miPersona);

         //se usa el objeto archivo con el operador << para escribir en el archivo
         //usenlo similar al cout
         cout << endl << endl;

        if (validarExistencia(miPersona.Codecuenta) == false) {
             cout << "Escribiendo archivo..." << endl;

             archivo.write((char*)&miPersona, sizeof(Persona));


             cout << "Persona registrada con exito!" << endl;

         }
         else {
             cout << "No Se Puede Escribir el archivo" << endl;

             cout << "El codigo de cuenta ya existe" << endl;

         }

         cout << endl << endl;
         cout << "Registrar otra persona? (S/N):";
         cin >> respuesta;

         if (respuesta == 'N' || respuesta == 'n')
         {
             continuar = false;
         }

    }
     archivo.close();
   }


 bool Users::validarususarios(int Username, int Password) {

     Persona miPersona;
     bool encontrado = false;
     string usuaroAct;
     string PassAct;

     fstream archivo("usuariosC.tes", ios::binary | ios::in);  // objeto de la clase ifstream


     while (!archivo.eof() || encontrado==false)
     {

     archivo.read((char*)&miPersona, sizeof(Persona));

         if (!archivo.eof()) //sin esto el último se muestra 2 veces
         {
        

             if (miPersona.clave==Password && miPersona.Codecuenta==Username) {
             
                 cout << "Iniciando sesion Con clave de acceso" << endl;

                 //iniciar sesion
                 system("pause");
                 
                 encontrado= true;
                 break;
             }
             else {
                
                 //No se inicia sesion
                 cout << "No se ha  podido iniciar sesion " << endl;
                 encontrado = false;

                 system("pause");
                 
             }
           
         }
         else { break; }
     }
     return encontrado;
 }
 
 bool Users :: validarRespuesta(char respuesta)
 {
     if (respuesta == 'S' || respuesta == 's')
     {
         return true;
     }

     if (respuesta == 'N' || respuesta == 'n')
     {
         return false;
     }
 
 }


 bool Users::validarExistencia(int code) {

     Persona miPersona;
     bool existe = false;


     fstream archivo("usuariosC.tes", ios::binary | ios::in);  // objeto de la clase ifstream



     while (!archivo.eof() || existe == false)
     {

         archivo.read((char*)&miPersona, sizeof(Persona));
    
             if (!archivo.eof()) //sin esto el último se muestra 2 veces
             {
                 cout << "Nombre: " << miPersona.nombre << endl;
                 cout << "Code: " << miPersona.Codecuenta << endl;

                 if (miPersona.Codecuenta == code) {

                     cout << "Este Code ya existe" << endl;

                     //iniciar sesion
                     

                     existe = true;
                     break;
                 }
                 else {

                     //No se inicia sesion
                     cout << "No se ha encontrado el user " << endl;
                    // existe = false;

                    

                 }

             }
             else { break; }
         
     }
       
     return existe;
 }

 bool Users :: archivo_existe(string nombre)
 {
     ifstream archivo(nombre.c_str());
     return archivo.good();
 }


 queue<Persona> Users::DevolverQueue() {
 
 
     Persona miPersona;
     queue<Persona> existe;
  

     fstream archivo("usuariosC.tes", ios::binary | ios::in);  // objeto de la clase ifstream

     if (archivo.good() == true) {


         while (!archivo.eof())
         {

             archivo.read((char*)&miPersona, sizeof(Persona));

             if (!archivo.eof()) //sin esto el último se muestra 2 veces
             {

                 existe.push(miPersona);

             }
             else { break; }


         }

     }
     else { Persona nuevo;
     existe.push(nuevo);
     }
     return existe;

 }
 

 void Users::cambiarClave(int clave, int code) {

     queue<Persona> listaP = DevolverQueue();
     queue<Persona> temp;
     int claveNueva=0, clavenuevaTemp=0;
     int cont1 = 0, cont2 = 0;


     while (!listaP.empty())
     {
       
         if (code == listaP.front().Codecuenta)
         {
             if (clave == listaP.front().clave)
             {
                 cout << "Ingrese la nueva clave" << endl;
                 cin >> claveNueva;

                 cout << "Ingrese la nueva clave una vez mas" << endl;
                 cin >> clavenuevaTemp;
                 if (clavenuevaTemp == claveNueva) {

                     listaP.front().clave = clavenuevaTemp;

                     temp.push(listaP.front());
                     cont1++;
                     listaP.pop();

                 }
             }
         }
         else
         {
             temp.push(listaP.front());
             listaP.pop();
             cont1++;
         }

     }

     ofstream archivo;
     Persona miPersona;

     archivo.open("usuariosC.tes", ios::binary | ios::out);
     while (!temp.empty())
     {
        
         for (int j = 0; j < 20; j++)
         {
             miPersona.nombre[j] = temp.front().nombre[j];
         }

         miPersona.rol = temp.front().rol;
         miPersona.Codecuenta = temp.front().Codecuenta;
         miPersona.clave = temp.front().clave;
         miPersona.estatus = temp.front().estatus;

         archivo.write((char*)&miPersona, sizeof(Persona));

         temp.pop();
         cont2++;
     }

 }

 void Users::CambiarEstado(int code) {

     queue<Persona> listaP = DevolverQueue();
     queue<Persona> temp;
     int claveNueva=0, clavenuevaTemp=0;
     int cont1 = 0, cont2 = 0;


     while (!listaP.empty())
     {

         if (code == listaP.front().Codecuenta)
         {
 
             if (listaP.front().estatus == true) {

                 cout << "Se ha vuelto falso" << endl;
                 listaP.front().estatus = false;

                 temp.push(listaP.front());
                 cont1++;
                 listaP.pop();

             }
             else {
                 listaP.front().estatus = true;
                 cout << "Se ha vuelto Verdadero " << endl;
                 temp.push(listaP.front());
                 cont1++;
                 listaP.pop();

             }
         }
         else
         {
             temp.push(listaP.front());
             listaP.pop();
             cont1++;
         }

     }

     ofstream archivo;
     Persona miPersona;

     archivo.open("usuariosC.tes", ios::binary | ios::out);
     while (!temp.empty())
     {
    
         for (int j = 0; j < 20; j++)
         {
             miPersona.nombre[j] = temp.front().nombre[j];
         }

         miPersona.rol = temp.front().rol;
         miPersona.Codecuenta = temp.front().Codecuenta;
         miPersona.clave = temp.front().clave;
         miPersona.estatus = temp.front().estatus;

         archivo.write((char*)&miPersona, sizeof(Persona));

         temp.pop();
         cont2++;
     }

 }

 bool Users::ValidarAdmin(int code) {

     bool Esadmin = false;
     queue<Persona> listaP = DevolverQueue();

     int claveNueva=0, clavenuevaTemp=0;
     int cont1 = 0, cont2 = 0;


     while (!listaP.empty())
     {
         if (code ==listaP.front().Codecuenta)
         {

             
                 
                 if (true == listaP.front().rol)
                 {
                     cout << "Usuario ADMIN" << endl;
                     Esadmin = true;
                     break;
                 }


                 else
                 {

                     listaP.pop();
                     cont1++;
                     Esadmin = false;
                 }
             
         }
         else {
             listaP.pop();

         }

     }
     return Esadmin;

 }

 