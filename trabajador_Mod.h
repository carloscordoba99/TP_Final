#ifndef TRABAJADOR_MOD_H_INCLUDED
#define TRABAJADOR_MOD_H_INCLUDED
void Mod_empleado()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"Modificación de empleado"<<endl;
        cout<<"1. Nombre"<<endl;
        cout<<"2. Apellido"<<endl;
        cout<<"3. Dirección"<<endl;
        cout<<"4. Numero de Telefono"<<endl;
        cout<<"5. Edad "<<endl;
        cout<<"6. Dni"<<endl;
        cout<<"7. Sueldo"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Ingrese la opción: "<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            emp_Nom();
            break;
        case 2:
            emp_Ape();
            break;
        case 3:
            emp_Direc();
            break;
        case 4:
            emp_Tel();
            break;
        case 5:
            emp_Edad();
            break;
        case 6:
            emp_Dni();
            break;
        case 7:
            emp_Sueldo();
            break;
        case 0:
            return ;
            break;
        default:
            cout<<"Opcion incorrecta. Presione una tecla para continuar";
            system("pause>null");
            break;
        }
    }


};

void emp_Nom()
{
    system("cls");
    int dni,pos;
    char nombre[20];
    Empleado reg;
    cout<<"Ingrese el dni del empleado a Modificar"<<endl;
    cin>>dni;
    pos=buscar_empleado(dni);
    if(pos==-1)
    {
        cout<<"No se encontró el empleado "<<endl;
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

void emp_Ape()
{
    system("cls");
    int dni,pos;
    char apellido[20];
    Empleado reg;
    cout<<"Ingrese el dni del empleado a Modificar"<<endl;
    cin>>dni;
    pos=buscar_empleado(dni);
    if(pos==-1)
    {
        cout<<"No se encontro el empleado "<<endl;
        system("pause");
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
                system("pause");
            }

    }

};

void emp_Direc()
{
    system("cls");
    int dni,pos;
    char direc[20];
    Empleado reg;
    cout<<"Ingrese el dni del empleado a Modificar"<<endl;
    cin>>dni;
    pos=buscar_empleado(dni);
    if(pos==-1)
    {
        cout<<"No se encontró el empleado "<<endl;
        system("pause");
        return ;
    }
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"ingrese la nueva dirección"<<endl;
        cargarCadena(direc,19);
        reg.set_direccion(direc);

            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"Modificó"<<endl;
                system("pause");
            }

    }

};

void emp_Tel()
{
    int dni,pos,tel;
    Empleado reg;
    cout<<"Ingrese el dni del empleado a Modificar"<<endl;
    cin>>dni;
    pos=buscar_empleado(dni);
    if(pos==-1)
    {
        cout<<"No se encontró el empleado "<<endl;
        system("pause");
        return ;
    }
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"ingrese el nuevo Tel"<<endl;
        cin>>tel;
        reg.set_Tel(tel);

            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"Modificó"<<endl;
                system("pause");
            }


    }
};

void emp_Edad()
{
    system("cls");
    int dni,pos,edad;
    Empleado reg;
    cout<<"Ingrese el dni del empleado a Modificar"<<endl;
    cin>>dni;
    pos=buscar_empleado(dni);
    if(pos==-1)
    {
        cout<<"No se encontró el empleado "<<endl;
        system("pause");
        return ;
    }
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"ingrese el nuevo edad"<<endl;
        cin>>edad;
        reg.set_edad(edad);

            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"Modificó"<<endl;
                system("pause");
            }

    }
}


void emp_Dni()
{
    system("cls");
    int dni,pos,dnin;
    Empleado reg;
    cout<<"Ingrese el dni del empleado a Modificar"<<endl;
    cin>>dni;
    pos=buscar_empleado(dni);
    if(pos==-1)
    {
        cout<<"No se encontró el empleado "<<endl;
        system("pause");
        return ;
    }
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"ingrese el nuevo dni"<<endl;
        cin>>dnin;
        reg.set_dni(dnin);

            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"Modificó"<<endl;
                system("pause");
            }


    }
};



void emp_Sueldo()
{
    system("cls");
    int dni,pos,sueldo;
    Empleado reg;
    cout<<"Ingrese el dni del empleado a Modificar"<<endl;
    cin>>dni;
    pos=buscar_empleado(dni);
    if(pos==-1)
    {
        cout<<"No se encontró el empleado "<<endl;
        return ;
    }
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"ingrese el nuevo sueldo"<<endl;
        cin>>sueldo;
        if(reg.set_sueldo(sueldo)==true)
        {
            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"Modificó"<<endl;
            }
        }
    }
};


#endif // TRABAJADOR_MOD_H_INCLUDED
