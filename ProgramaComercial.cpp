#include <iostream>
#include "Users.h"

using namespace std;

int main() {

	Users User;

	//Manejadores para 	
	int codigo;

	int passWord;
	int claveAcces = 1234;

	int pin = 0, num = 0;
	int code = 0, codigoCuentaEstado = 0;
	int clave = 0;

	//control de Whiles
	int control = 0;
	int control1 = 0;
	int control2 = 0;
	int control7 = 0;



	do
	{
		system("cls");
		cout << "Menu Inicial Proyecto Comercial" << endl;
		cout << "1)-Inicio de sesion" << endl;
		cout << "2)-Crear " << endl;
		cout << "3)-Salir" << endl;

		cin >> control;
		switch (control) {
			//Menu Administratvos
		case 1: {
			system("cls");
			cout << "Ingrese la codigo de cuenta del USUARIO :" << endl;
			cin >> codigo;

			cout << "Ingrese la clave super secreta de administracion:" << endl;
			cin >> clave;

			if (User.validarususarios(codigo, clave) == true) {
				cout << "Accediendo Al menu" << endl;
				if (User.ValidarAdmin(codigo)) {
					system("pause");
					do {

						system("cls");
						cout << "------Menu Administrativo------" << endl;
						cout << "1)-Administracion del sistema" << endl;
						cout << "2)-" << endl;
						cout << "3)-" << endl;
						cout << "4)-" << endl;
						cout << "5)-" << endl;
						cout << "6)-" << endl;
						cout << "7)-opciones de Usuarios" << endl;
						cout << "8)-" << endl;
						cout << "9)-Menu principal" << endl;
						cin >> control1;
						switch (control1) {
						case 1: {
							do {

								system("cls");
								cout << "------Menu Administracion del sistema------" << endl;
								cout << "1)-Crear usuarios" << endl;
								cout << "2)-Dar de baja un usuario/o dejar de dar de baja al usuario" << endl;
								cout << "3)-Regresar al menu pricipal" << endl;

								cin >> control2;
								switch (control2) {
								case 1: {
									User.crearUser();
									system("PAUSE");
									break;
								}

								case 2: {
									cout << "Ingrese la codigo de cuenta del USUARIO :" << endl;
									cin >> codigoCuentaEstado;
									User.CambiarEstado(codigoCuentaEstado);
									system("PAUSE");
									break;
								}
								case 3: {

									cout << "Regresando al menu...." << endl;
									system("PAUSE");
									break;
								}


								default: {
									cout << "Ingrese el dato indicado!!" << endl;
									break;
								}

								}
							} while (control2 != 3);
							break;
							system("PAUSE");
						}

						case 2: {



							system("PAUSE");
							break;
						}
						case 3: {


							system("PAUSE");
							break;
						}
						case 4: {


							system("PAUSE");
							break;
						}
						case 5: {

							system("PAUSE");
							break;
						}
						case 6: {


							system("PAUSE");
							break;
						}
						case 7: {
							do {

								system("cls");
								cout << "------Opciones de Usuario------" << endl;
								cout << "1)-Cambiar clave" << endl;
								cout << "2)-Regresar al menu pricipal" << endl;

								cin >> control7;
								switch (control7) {
								case 1: {
									cout << "ingrese la clave para proceder:" << endl;
									cin >> clave;
									User.cambiarClave(clave, codigo);
									system("PAUSE");
									break;
								}

								case 2: {

									cout << "Regresando al menu...." << endl;
									system("PAUSE");
									break;
								}


								default: {
									cout << "Ingrese el dato indicado!!" << endl;
									break;
								}



								}
							} while (control7 != 2);
							system("PAUSE");
							break;
						}

							  system("PAUSE");
							  break;
						}
		case 8: {


			system("PAUSE");
			break;
		}
		case 9: {

			cout << "Regresando al Menu Princial" << endl;

			break;
		}

					} while (control1 != 5);

				}
				cout << "clave de Acceso Incorrecta" << endl;
				system("pause");
			}

			break; }
			  //Menu retiros	
		case 2: {

			User.crearUser();


			break;
		}		case 3: {



			break;
		}

		default: {
			cout << "Ingrese el dato indicado!!" << endl;
			break;
		}


		}
	} while (control != 3);

	return 0;



}
