#include <iostream>
#include <string>
#include<fstream>

using namespace std;

struct CitaDental {
	string nombre="Sin registros";
	string tratamiento;
	string hora;
	int precio=0;
	int cantidad_tratamiento = 0;
	CitaDental* anterior=nullptr;
	CitaDental* siguiente=nullptr;
	int numero= 0;
	
};

int num_cita = 0;
CitaDental* cita_auxiliar = nullptr;
CitaDental* primera_cita = nullptr;
CitaDental* ultima_cita = nullptr;

void mostrar_citas(){
	cita_auxiliar = primera_cita;

	while (cita_auxiliar) {
	cout << "==============================\n";
	cout << "            #Cita: "<< cita_auxiliar->numero << endl;
	cout << "==============================\n";
	cout << "NOMBRE:   " << cita_auxiliar->nombre << endl;
	cout << "\nHORA DE LA CITA:   " << cita_auxiliar->hora << "hrs" << endl;
	cout << "\nTRATAMIENTO:   " << cita_auxiliar->tratamiento << endl;
	cout << "\nCANTIDAD:" << cita_auxiliar->cantidad_tratamiento << endl;
	cout << "\nTOTAL:   " << cita_auxiliar->precio << "MXN\n";
	cout << "==============================\n";
	
	if (cita_auxiliar->siguiente) {
		cout << "Cita Siguiente: " << cita_auxiliar->siguiente->nombre << endl;
		}

	cita_auxiliar = cita_auxiliar->siguiente;
	system("pause");
	}
	
};

void registrar_citas() {


	ofstream archivo("Citas_Dentales.txt");
	
	if (archivo) {
		
		cita_auxiliar = primera_cita;
		
		while (cita_auxiliar) {
			archivo << cita_auxiliar->nombre << endl;
			archivo << cita_auxiliar->tratamiento << endl;
			archivo << cita_auxiliar->cantidad_tratamiento << endl;
			archivo << cita_auxiliar->precio << endl;
			archivo << cita_auxiliar->hora << endl;
			cita_auxiliar = cita_auxiliar->siguiente;
		}
		cout << "se han guardado las citas\n";
		archivo.close();
	}
	else {
		cout << "Error al abrir el archivo";
	}
}

int leer_archivo() {

	ifstream archivo("Citas_Dentales.txt");
	if (archivo) {
		string linea;
		string descripcion_trat;
		string descripcion_trat2;

			cita_auxiliar=new CitaDental;

		while(getline(archivo, linea)){
			cita_auxiliar->nombre = linea;
			getline(archivo,linea);
			cita_auxiliar->tratamiento = linea;
			getline(archivo, descripcion_trat);
			getline(archivo, descripcion_trat2);
			//Juntar las lineas del tratamiento
			cita_auxiliar->tratamiento = cita_auxiliar->tratamiento + "\n" + descripcion_trat + "\n" + descripcion_trat2;
			getline(archivo, linea);
			cita_auxiliar->cantidad_tratamiento = stoi(linea);
			getline(archivo, linea);
			cita_auxiliar->precio = stoi(linea);
			getline(archivo, linea);
			cita_auxiliar->hora = linea;

			num_cita++;//asignar siguientes y anteriores
				if (num_cita == 1) {
					cita_auxiliar->numero = 1;
					primera_cita = cita_auxiliar;
					ultima_cita = cita_auxiliar;
				}
				else {
					cita_auxiliar->anterior = ultima_cita;
					ultima_cita->siguiente = cita_auxiliar;
					cita_auxiliar->numero = ultima_cita->numero + 1;
					ultima_cita = cita_auxiliar;
				}
				cita_auxiliar = new CitaDental;
		}
		cita_auxiliar = nullptr;

		return(num_cita);
	}
	return(0);
}

int main() {

	num_cita = leer_archivo();
	if (num_cita!=0){
		cout << "Citas cargadas correctamente\n";
			system("pause");
			system("cls");
	}
	
	int opc = 0, opc_trat = 0, num_modificar=0;
	while (opc != 6) {
		cout << "Bienvenido al menu\n";//Menu principal
		cout << "_______________________________________\n";
		cout << "1. Agendar Cita\n";
		cout << "2. Modificar cita\n";
		cout << "3. Eliminar cita\n";
		cout << "4. Lista de citas dentales\n";
		cout << "5. Limpiar pantalla\n";
		cout << "6. Salir\n";
		cout << "________________________________________\n";
		cout << "Ingrese una opcion para continuar:\n";
		cin >> opc;
		switch (opc) {
		case 1:
			system("cls");
			do {
				"\t\t---Agendar cita---\n\n";
				cout << "__________________Tratamientos______________\n";//Menu de tratamientos
				cout << "1. Blanqueamiento dental    Precio:2000\n";
				cout << "2. Carillas bucales         Precio:5000\n";
				cout << "3. Extraccion de muelas     Precio:100\n";
				cout << "4. Implantes dentales       Precio:8000\n";
				cout << "5. Ferula dental            Precio:4000\n";
				cout << "6. Ortodoncia de brackets   Precio:5000\n";
				cout << "7. Regresar al menu principal\n";
				cin >> opc_trat;

					CitaDental* nueva_cita = new CitaDental;
					if (opc_trat >= 7) {
						delete nueva_cita;
					}

				switch (opc_trat) {
				case 1:
					cout << "Ha elegido Blanqueamiento dental\n";
					nueva_cita->tratamiento = "Blanqueamiento dental:\nQuitar las manchas que puede tener los dientes\nPrecio unitario:2000";
					cout << "cuantos blanqueamientos realizara?\n";
					cin >> nueva_cita->cantidad_tratamiento;
					nueva_cita->precio = nueva_cita->cantidad_tratamiento *2000;
					
					break;
				case 2:
					cout << "Ha elegido Carillas bucales\n";
					nueva_cita->tratamiento = "Carillas Bucales:\nImplantacion de fundas esteticas de porcelana y resina dental\nPrecio unitario:5000";
					cout << "Ingrese la cantidad de tratamientos:\n";
					cin >> nueva_cita->cantidad_tratamiento;
					nueva_cita->precio = nueva_cita->cantidad_tratamiento* 5000;
					break;
				case 3:
					cout << "Ha elegido Extraccion de muelas\n";
					nueva_cita->tratamiento = "Extraccion de Muelas:\nExtraccion de muelas de juicio u otras piezas bucales\nPrecio unitario:100 por muela";
					cout << "¿Cuantas muelas extraera?\n";
					cin >> nueva_cita->cantidad_tratamiento;
					nueva_cita->precio = nueva_cita->cantidad_tratamiento * 100;
					break;
				case 4:
					cout << "Ha elegio Implantes dentales\n";
					nueva_cita->tratamiento = "Implantes Dentales:\nSustucion de piezas bucales dañadas con la intencion de ser a largo plazo\nPrecio unitario:8000";
					cout << "¿Cuantos implantes necesitara?\n";
					cin >> nueva_cita->cantidad_tratamiento;
					nueva_cita->precio = nueva_cita->cantidad_tratamiento * 8000;
					break;
				case 5:
					cout << "Ha elegido Ferula dental\n";
					nueva_cita->tratamiento = "Ferula Dental:\nPieza que se coloca en el arcado superior de la cavidad bucal para proteger los dientes de la friccion\nPrecio unitario:4000";
					cout << "Ingrese la cantidad de tratamientos:\n";
					cin >> nueva_cita->cantidad_tratamiento;
					nueva_cita->precio = nueva_cita->cantidad_tratamiento * 4000;
					break;
				case 6:
					cout << "Ha elegido Ortodoncia en brackets\n";
					nueva_cita->tratamiento = "Ortodoncia en Brackets:\ncorreccion de los problemas de mordida, alineando los dientes y la mandibula\nPrecio unitario:5000";
					cout << "Ingrese la cantidad de tratamientos:\n";
					cin >> nueva_cita->cantidad_tratamiento;
					nueva_cita->precio = nueva_cita->cantidad_tratamiento * 5000;
					break;
				case 7:
					break;
				default:
					cout << "Opcion invalida";
					break;
				}

				//"Si ha elegido un tratamiento..."
				if (opc_trat >= 1 && opc_trat <= 6) {
					
					//Pedir datos al ususario
					cout << "Ingrese su nombre:\n";
					cin.ignore();
					getline(cin, nueva_cita->nombre);
					cout << "Ingrese la hora de la cita(Formato 24 horas ejemp: 17:00):\n";
					cin >> nueva_cita->hora;
					
					num_cita++;

						//El lio de los siguientes y anteriores
						if (num_cita == 1) {
							nueva_cita->numero = 1;
							primera_cita = nueva_cita;
							ultima_cita = nueva_cita;

						}else{

							nueva_cita->anterior = ultima_cita;
							ultima_cita->siguiente = nueva_cita;
							nueva_cita->numero = ultima_cita->numero+1;
							ultima_cita = nueva_cita;
	
						}
							

					cout << "¿Desea agendar otra cita?\nSi=1  No=0\n";
					cin >> opc_trat;
				}

				system("cls");
			} while (opc_trat == 1);

			cout << "Se agendaron " << num_cita << " cita(s)\n\n";
			system("pause");
			system("cls");
			break;
			
		case 2:	//Modificar Cita
			system("cls");
			if (num_cita == 0) {
				cout << "No hay citas registradas :c\n";
				system("pause");
				system("cls");
				break;
			}

			cout << "\t\t---Modificar cita---\n";
			cout << "Ingrese el numero de cita que desea modificar:\n";
			cin >> num_modificar;

			cita_auxiliar = primera_cita;

			while(cita_auxiliar){
				 
				if (num_modificar == cita_auxiliar->numero) {
					int opc_count = 0;
					cout << "se MODIFICARA la siguiente cita:\n\n";
					cout << "      #Cita: " << cita_auxiliar->numero << endl;
					cout << "============================\n";
					cout << "NOMBRE:   " << cita_auxiliar->nombre << endl;
					cout << "\nHORA DE LA CITA:   " << cita_auxiliar->hora << "hrs" << endl;
					cout << "\nTRATAMIENTO:   " << cita_auxiliar->tratamiento << endl;
					cout << "\nCANTIDAD:" << cita_auxiliar->cantidad_tratamiento << endl;
					cout << "\nTOTAL:   " << cita_auxiliar->precio << "MXN\n";
					cout << "============================\n\n";
					cout << "\nDesea continuar?\nSi:1 No:0\n";
					cin >> opc_count;
					system("cls");
					if (opc_count == 1) {
						
						cout << "\t\tMODIFICAR TRATAMIENTO\n";
						cout << "1. Blanqueamiento dental    Precio:2000\n";
						cout << "2. Carillas bucales         Precio:5000\n";
						cout << "3. Extraccion de muelas     Precio:100\n";
						cout << "4. Implantes dentales       Precio:8000\n";
						cout << "5. Ferula dental            Precio:4000\n";
						cout << "6. Ortodoncia de brackets   Precio:5000\n";
						cin >> opc_trat;
						switch (opc_trat) {
						case 1:
							cout << "Ha elegido Blanqueamiento dental\n";
							cita_auxiliar->tratamiento = "Blanqueamiento dental:\nQuitar las manchas que puede tener los dientes\nPrecio:2000";
							cout << "cuantos blanqueamientos realizara?\n";
							cin >> cita_auxiliar->cantidad_tratamiento;
							cita_auxiliar->precio = cita_auxiliar->cantidad_tratamiento * 2000;
							break;
						case 2:
							cout << "Ha elegido Carillas bucales\n";
							cita_auxiliar->tratamiento = "Carillas Bucales:\nImplantacion de fundas esteticas de porcelana y resina dental\nPrecio:5000";
							cout << "Ingrese la cantidad de tratamientos:\n";
							cin >> cita_auxiliar->cantidad_tratamiento;
							cita_auxiliar->precio = cita_auxiliar->cantidad_tratamiento * 5000;
							break;
						case 3:
							cout << "Ha elegido Extraccion de muelas\n";
							cita_auxiliar->tratamiento = "Extraccion de Muelas:\nExtraccion de muelas de juicio u otras piezas bucales\nPrecio:100 por muela";
							cout << "¿Cuantas muelas extraera?\n";
							cin >> cita_auxiliar->cantidad_tratamiento;
							cita_auxiliar->precio = cita_auxiliar->cantidad_tratamiento * 100;
							break;
						case 4:
							cout << "Ha elegio Implantes dentales\n";
							cita_auxiliar->tratamiento = "Implantes Dentales:\nSustucion de piezas bucales dañadas con la intencion de ser a largo plazo\nPrecio:8000";
							cout << "¿Cuantos implantes necesitara?\n";
							cin >> cita_auxiliar->cantidad_tratamiento;
							cita_auxiliar->precio = cita_auxiliar->cantidad_tratamiento * 8000;
							break;
						case 5:
							cout << "Ha elegido Ferula dental\n";
							cita_auxiliar->tratamiento = "Ferula Dental:\nPieza que se coloca en el arcado superior de la cavidad bucal para proteger los dientes de la friccion\nPrecio:4000";
							cout << "Ingrese la cantidad de tratamientos:\n";
							cin >> cita_auxiliar->cantidad_tratamiento;
							cita_auxiliar->precio = cita_auxiliar->cantidad_tratamiento * 4000;
							break;
						case 6:
							cout << "Ha elegido Ortodoncia en brackets\n";
							cita_auxiliar->tratamiento = "Ortodoncia en Brackets:\ncorreccion de los problemas de mordida, alineando los dientes y la mandibula\nPrecio:5000";
							cout << "Ingrese la cantidad de tratamientos:\n";
							cin >> cita_auxiliar->cantidad_tratamiento;
							cita_auxiliar->precio = cita_auxiliar->cantidad_tratamiento * 5000;
							break;
						default:
							cout << "Opcion invalida";
							break;
						}
						cout << "\tMODIFICAR NOMBRE:\n";
						cin.ignore();
						getline(cin, cita_auxiliar->nombre);

						//Cambiar el "siguiente" de la cita anterior
						if (cita_auxiliar->anterior) {
						cita_auxiliar->anterior->siguiente->nombre = cita_auxiliar->nombre;
						}
						
						cout << "\tMODIFICAR HORA:\n";
						cin >> cita_auxiliar->hora;

						system("cls");
						cout << "La cita se ha modificado con exito :D\n";

						system("pause");
						system("cls");
					}
					else {
						cout << "cita no encontrada";
						cita_auxiliar = ultima_cita;
					}
				}
				cita_auxiliar = cita_auxiliar->siguiente;
			}
			system("cls");
			break;
		case 3://Eliminar cita
			system("cls");
			if (num_cita == 0) {
				cout << "No hay citas registradas :c\n";
				system("pause");
				system("cls");
				break;
			}
			cout << "\t\t---Eliminar cita---\n";
			cout << "Ingrese el numero de cita que desea eliminar:\n";
			cin >> num_modificar;

			cita_auxiliar = primera_cita;

			do{
				//Buscar la cita e imprimirla
				if (num_modificar == cita_auxiliar->numero) {
					int opc_count = 0;
					cout << "se ELIMINARA la siguiente cita:\n\n";
					cout << "      #Cita: " << cita_auxiliar->numero << endl;
					cout << "================================\n";
					cout << "NOMBRE:   " << cita_auxiliar->nombre << endl;
					cout << "\nHORA DE LA CITA:   " << cita_auxiliar->hora << "hrs" << endl;
					cout << "\nTRATAMIENTO:   " << cita_auxiliar->tratamiento << endl;
					cout << "\nCANTIDAD:" << cita_auxiliar->cantidad_tratamiento << endl;
					cout << "\nTOTAL:   " << cita_auxiliar->precio << "MXN\n";
					cout << "================================\n\n";
					cout << "\nDesea continuar?\nSi:1 No:0\n";
					cin >> opc_count;
					system("cls");
						

					if (opc_count == 1) {
							//Si es la primera cita
						if (cita_auxiliar->numero == 1) {

							primera_cita = primera_cita->siguiente;
							cita_auxiliar = nullptr;
						}
						else {//Si es una cita del medio

							if(cita_auxiliar->anterior) {

								if (cita_auxiliar->siguiente) {
											cita_auxiliar->anterior->siguiente = cita_auxiliar->siguiente;
											cita_auxiliar->siguiente->anterior = cita_auxiliar->anterior;
											 
								}
								else { //Si es la ultima cita

									ultima_cita = cita_auxiliar->anterior;
									cita_auxiliar->anterior->siguiente = nullptr;	
								}
							}
						}
						cita_auxiliar=nullptr;
						cout << "La cita #" << num_modificar << " se ha ELIMINADO con exito\n";
						system("pause");
						num_cita--;
					}else {
						cita_auxiliar = nullptr;
					}
				}else{		
							cita_auxiliar = cita_auxiliar->siguiente;
					}
			} while (cita_auxiliar != nullptr);

			system("cls");
			break;
		case 4://Mostrar Citas
			system("cls");

			if (num_cita == 0) {

				cout << "\nNo hay citas registradas :c" << endl;
				system("pause");
			}else{

			cout << "---Lista de citas dentales---\n";
			cout << "Las citas agendadas son:\n";
			cout << "_______________________\n";
			mostrar_citas();
			}
			system("cls");
			break;
		case 5:
			system("cls");
			break;
		case 6:
			registrar_citas();
			cout << "Hasta pronto";
			return(0);
			break;
		default:
			cout << "Ingrese una opcion valida";
		}
	};
}
