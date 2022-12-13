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
						cout << "6)-Caja" << endl;
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
							int opcion = 0;
							Caja miCaja;
							HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
							double saldo = 0;
							double saldoin;
							vector<producto> pBodega;
							char respAgregar = ' ';
							bool cerrar;
							double saldoAgregado = 0;
							system("cls");
							while (opcion != 5)
							{
								cout << "MENU DE CAJA" << endl;
								cout << "------------" << endl << endl;
								cout << "1) Depositar Saldo en Bandeja y Activar" << endl;
								cout << "2) Agregar a Saldo " << endl;
								cout << "3) Facturar producto(s) " << endl;
								cout << "4) Cerrar Caja" << endl;
								cout << "5) Volver al Menu Principal" << endl;
								cout << "Eliga una opcion: ";
								cin >> opcion;
								switch (opcion)
								{
								case 1:
									system("cls");
									if (miCaja.compararSaldoMinimo())
									{
										cout << "LA CAJA YA TIENE UNA BANDEJA CON DINERO, DEBE RETIRARLA ANTES." << endl;
										cout << "DEBE RETIRARLA ANTES." << endl;
										break;
									}

									cout << "INGRESE EL SALDO TOTAL DE LA BANDEJA: ";
									cin >> saldoin;
									miCaja.actualizarSaldo(saldoin);

									if (miCaja.compararSaldoMinimo())
									{
										miCaja.setSaldoInicial(saldoin);
										cout << "SALDO ACTUALIZADO" << endl;
										miCaja.infoSaldo();
										miCaja.marcarAbierta();
										break;
									}
									cout << "EL SALDO TOTAL DEBE SER MAYOR QUE " << miCaja.saldoMinimo << endl;
									miCaja.reiniciarSaldo();
									break;
								case 2:
									system("cls");
									if (!miCaja.abierta)
									{
										cout << "Debe activar la Caja antes de proceder." << endl;
										break;
									}
									cout << "Ingrese la Cantidad Total a Ingresar: ";
									cin >> saldoin;
									//validar que no sea negativo en el try catch
									cout << "El saldo a Ingresar es parte de las ganancias?(S/N)" << endl;
									cin >> respAgregar;
									if (respAgregar == 'S' || respAgregar == 's')
										miCaja.actualizarGanancias(saldoin);
									else
										saldoAgregado += saldoin;

									miCaja.actualizarSaldo(saldoin);
									miCaja.infoSaldo();
									cout << "SALDO ACTUALIZADO" << endl;
									system("pause"); system("cls");
									break;
								case 3:

									if (!miCaja.abierta)
									{
										system("cls");
										cout << "Debe activar la Caja antes de proceder." << endl;
										break;
									}
									//cout << "Facturar producto(s) Elegido" << endl;
									//PRODUCTOS EN BODEGAS
									pBodega.push_back({ 01,1500,20,"Oreos Docena" , true });
									pBodega.push_back({ 02,500,1000,"Pollo" , true });
									pBodega.push_back({ 03,2000,60,"Arroz" , true });
									pBodega.push_back({ 04,1500,120,"Cereal" , true });
									pBodega.push_back({ 05,1600,30,"Fanta" , true });
									miCaja.facturar(pBodega);
									break;
								case 4:
									system("cls");
									//cout << "Cerrar Caja Elegido" << endl;

									if (!miCaja.abierta)
									{
										cout << "Debe activar la Caja antes de proceder." << endl;
										break;
									}
									if (saldoAgregado > 0)
										cout << "SALDO AGREGADO FUERA DE GANANCIAS: " << saldoAgregado << endl;
									cerrar = miCaja.cerrarCaja();

									if (!cerrar)
										break;

									opcion = 5; //Esto hace que se salga al menu principal
									system("cls");
									cout << "Ganancias del dia: " << miCaja.getGanancias() << endl; //Se retornan las ganancias para REPORTES
									miCaja.reiniciarGanancias();
									cout << "CAJA CERRADA" << endl;
									break;
								case 5:
									system("cls");
									cout << "Volver Elegido" << endl;
									break;
								default:
									system("cls");
									cout << "ELIGA UNA DE LAS OPCIONES" << endl;
									break;
								}
								system("pause");
								system("CLS");


							}

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
