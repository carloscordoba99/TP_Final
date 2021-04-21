#ifndef CLIENTE_MOD_H_INCLUDED
#define CLIENTE_MOD_H_INCLUDED
void Mod_cliente()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"Modificación de empleado"<<endl;
        cout<<"1. Nombre"<<endl;
        cout<<"2. Apellido"<<endl;
        cout<<"3. Direccion"<<endl;
        cout<<"4. Numero de Telefono"<<endl;
        cout<<"5. Edad "<<endl;
        cout<<"6. Dni"<<endl;
        cout<<"7. gmail"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Ingrese la opción: "<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            cli_Nom();
            system("pause");
            break;
        case 2:
            cli_Ape();
            system("pause");
            break;
        case 3:
            cli_Direc();
            system("pause");
            break;
        case 4:
            cli_Tel();
            system("pause");
            break;
        case 5:
            cli_Edad();
            system("pause");
            break;
        case 6:
            cli_Dni();
            system("pause");
            break;
        case 7:
            cli_gmail();
            system("pause");
            break;
        case 0:
            return ;
            break;
        default:
            cout<<"Opción incorrecta. Presione una tecla para continuar";
            system("pause>null");
            break;
        }
    }



};

void cli_Nom()
{
    system("cls");
    int dni,pos;
    char nombre[20];
    Cliente reg;
    cout<<"Ingrese el dni del cliente a Modificar"<<endl;
    cin>>dni;
    pos=buscar_dni(dni);
    if(pos==-1)
    {
        cout<<"No se encontró el cliente "<<endl;
        return ;
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

void cli_Ape()
{
    system("cls");
    int dni,pos;
    char apellido[20];
    Cliente reg;
    cout<<"Ingrese el dni del cliente a Modificar"<<endl;
    cin>>dni;
    pos=buscar_dni(dni);
    if(pos==-1)
    {
        cout<<"No se encontró el cliente "<<endl;
        return ;
    }
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"ingrese el nuevo Apellido "<<endl;
        cargarCadena(apellido,19);
        reg.set_apellido(apellido);

            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"Modificó"<<endl;
            }


    }
};

void cli_Direc()
{
    system("cls");
    int dni,pos;
    char direc[20];
    Cliente reg;
    cout<<"Ingrese el dni del cliente a Modificar"<<endl;
    cin>>dni;
    pos=buscar_dni(dni);
    if(pos==-1)
    {
        cout<<"No se encontró el cliente "<<endl;
        return ;
    }
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"ingrese la Nuevo direccion "<<endl;
        cargarCadena(direc,19);
        reg.set_direccion(direc);

            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"Modificó"<<endl;
            }


    }
};

void cli_Tel()
{
    system("cls");
    int dni,pos,tel;
    Cliente reg;
    cout<<"Ingrese el dni del cliente a Modificar"<<endl;
    cin>>dni;
    pos=buscar_dni(dni);
    if(pos==-1)
    {
        cout<<"No se encontró el cliente "<<endl;
        return ;
    }
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"ingrese el Nuevo Tel "<<endl;
        cin>>tel;
        reg.set_Tel(tel);

            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"Modificó"<<endl;
            }


    }
};

void cli_Edad()
{
    system("cls");
    int dni,pos,edad;
    Cliente reg;
    cout<<"Ingrese el dni del cliente a Modificar"<<endl;
    cin>>dni;
    pos=buscar_dni(dni);
    if(pos==-1)
    {
        cout<<"No se encontró el cliente "<<endl;
        return ;
    }
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"ingrese la nuevo edad "<<endl;
        cin>>edad;
        reg.set_edad(edad);

            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"Modificó"<<endl;
            }


    }

};

void cli_Dni()
{
    system("cls");
    int dni,pos,dni_n;
    Cliente reg;
    cout<<"Ingrese el dni del cliente a Modificar"<<endl;
    cin>>dni;
    pos=buscar_empleado(dni);
    if(pos==-1)
    {
        cout<<"No se encontró el cliente "<<endl;
        return ;
    }
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"ingrese el nuevo dni "<<endl;
        cin>>dni_n;
        reg.set_dni(dni_n);

            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"Modificó"<<endl;
            }


    }
};

void cli_gmail()
{
    system("cls");
    int dni,pos;
    char gmail[30];
    Cliente reg;
    cout<<"Ingrese el dni del cliente a Modificar"<<endl;
    cin>>dni;
    pos=buscar_dni(dni);
    if(pos==-1)
    {
        cout<<"No se encontró el cliente "<<endl;
        return ;
    }
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"ingrese el Nuevo gmail "<<endl;
        cargarCadena(gmail,29);
        reg.set_email(gmail);
            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"Modificó"<<endl;
                system("pause");
            }


    }

};

#endif // CLIENTE_MOD_H_INCLUDED
