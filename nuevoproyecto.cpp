#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

#include "fecha.h"
#include "persona.h"
#include "cliente.h"
#include "trabajador.h"
#include "articulo.h"
#include "ventas.h"
#include "reparaciones.h"

void genera_ar();//prototipo de la funcion que genera los archivos si no existen

/*void genera_ar()
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

	p=fopen("clientes.dat","rb");
	if(p==NULL)
		p=fopen("clientes.dat","wb");
	fclose(p);

	p=fopen("trabajador.dat","rb");
	if(p==NULL)
		p=fopen("trabajador.dat","wb");
	fclose(p);


        p=fopen("reparaciones.dat","rb");
	if(p==NULL)
		p=fopen("reparaciones.dat","wb");
	fclose(p);
        }
*/

int main()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"Menu Principal"<<endl;
        cout<<"1. Articulos"<<endl;
        cout<<"2. Trabajador"<<endl;
        cout<<"3. Clientes"<<endl;
        cout<<"4. Ventas"<<endl;
        cout<<"5. Reparaciones"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Ingrese la opcion: "<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            menu_articulos();
            break;
        case 2:
            menu_clientes();
            break;
        case 3:
            menu_ventas();
            break;
        case 4:
            menu_proveedores();
            break;
        case 5:
            return 0;
        default:
            cout<<"Opcion incorrecta. Presione una tecla para continuar";
            system("pause>null");
            break;
        }
    }
    return 0;
}


/**
int persona::leer_de_disco(int pos)
{
    int x;
    FILE *p;
    persona reg;
    p=fopen("persona.dat","rb");
    if(p==NULL)
    {
        cout<<"No existe el archivo";
        cout<<"Presione una tecla para continuar";
        system("pause>null");
        return 0;
        fseek(p,pos* sizeof *this /*puede ser q falte un puntero justo antes de this, 0);
        x=fread(this,sizeof *this,1,p);
        return x;
        close(p);

    }
    pos++;
    close(p)
    return -1;
}
*/
