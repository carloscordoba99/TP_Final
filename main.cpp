#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <clocale>
#include <windows.h>

using namespace std;
#include "prototipos.h"
#include "fecha.h"
#include "persona.h"
#include "cliente.h"
#include "empleado.h"
#include "articulo.h"
#include "ventas_detalle.h"
#include "ventas.h"
#include "articulo_Mod.h"
#include "trabajador_Mod.h"
#include "cliente_Mod.h"
#include "Mod_Ventas.h"


void genera_ar();//prototipo de la funcion que genera los archivos si no existen

void genera_ar()
	{
	FILE *p;
	p=fopen("articulos.dat","rb");
	if(p==NULL)
		p=fopen("articulos.dat","wb");
	fclose(p);


	p=fopen("ventas.dat","rb");
	if(p==NULL)
		p=fopen("ventas.dat","wb");
	fclose(p);

	p=fopen("ventasdetalle.dat","rb");
	if(p==NULL)
		p=fopen("ventasdetalle.dat","wb");
	fclose(p);

	p=fopen("clientes.dat","rb");
	if(p==NULL)
		p=fopen("clientes.dat","wb");
	fclose(p);

	p=fopen("empleados.dat","rb");
	if(p==NULL)
		p=fopen("empleados.dat","wb");
	fclose(p);

        }


int main()
{
setlocale(LC_ALL, "spanish");
SetConsoleCP(1252);
SetConsoleOutputCP(1252);
int opc;
while(true){
		system("cls");
		cout<<"SISTEMA DE GESTION BICICLETERIA MARIANO"<<endl;
		cout<<"Menu Principal"<<endl;
		cout<<"1. Articulos"<<endl;
		cout<<"2. Empleados"<<endl;
		cout<<"3. Clientes"<<endl;
		cout<<"4. Ventas"<<endl;
		cout<<"0. Salir"<<endl;
		cout<<"Ingrese la opcion: "<<endl;
		cin>>opc;
		switch(opc)
			{
			 case 1: menu_articulos();break;
			 case 2: menu_empleado();break;
			 case 3: menu_clientes();break;
			 case 4: menu_ventas();break;
			 case 0: return 0;
			 default: cout<<"Opcion incorrecta. Presione una tecla para continuar";
system("pause>null");
break;
		}
	}
    return 0;
}
