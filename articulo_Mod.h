#ifndef ARTICULO_MOD_H_INCLUDED
#define ARTICULO_MOD_H_INCLUDED
void Modificasion_art()
{

    int opc;
    while(true)
    {
        system("cls");
        cout<<"Modificacion de Articulos"<<endl;
        cout<<"1. Nombre"<<endl;
        cout<<"2. Precio"<<endl;
        cout<<"3. Stock"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Ingrese la opcion: "<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            art_nombre();
            system("pause");
            break;
        case 2:
            art_precio();
            system("pause");
            break;
        case 3:
            art_stok();
            system("pause");
            break;
        case 0:
            return ;
        default:
            cout<<"Opcion incorrecta. Presione una tecla para continuar";
            system("pause>null");
            break;
        }
    }

};

void art_nombre()
{
    system("cls");
    int nro;
    char nombre[20];
    Articulo reg;
    cout<<"indique el Nro de Articulo a cambiar"<<endl;
    cin>>nro;
    int pos=buscar_art(nro);
    if(pos==-1)
    {
        cout<<"no se encontró en los archivos"<<endl;
        return;
    }
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"ingrese el nuevo nombre "<<endl;
        cargarCadena(nombre,19);
        reg.set_nombre(nombre);

            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"Modificó"<<endl;
            }

    }

};

void art_precio()
{
    system("cls");
    int nro;
    float precio;
    Articulo reg;
    cout<<"indique el nro. de Articulo a cambiar"<<endl;
    cin>>nro;
    int pos=buscar_art(nro);
    if(pos==-1)
    {
        cout<<"no se encontró en los archivos"<<endl;
        return;
    }
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"ingrese el nuevo precio"<<endl;
        cin>>precio;
        reg.set_precio(precio);
            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"Modificó"<<endl;
            }
    }

};

void art_stok()
{
    system("cls");
    int nro,stok;
    Articulo reg;
    cout<<"indique el Nro de Articulo a cambiar"<<endl;
    cin>>nro;
    int pos=buscar_art(nro);
    if(pos==-1)
    {
        cout<<"no se encontró en los archivos"<<endl;
        return;
    }
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"ingrese el nuevo stock"<<endl;
        cin>>stok;
        reg.set_stock(stok);
            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"Modificó"<<endl;
            }

    }

};


#endif // ARTICULO_MOD_H_INCLUDED
