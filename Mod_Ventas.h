#ifndef MOD_VENTAS_H_INCLUDED
#define MOD_VENTAS_H_INCLUDED
void Mod_ventas()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"Modificación de Ventas"<<endl;
        cout<<"1. Dni.Empleado"<<endl;
        cout<<"2. Dni.Cliente"<<endl;
        cout<<"3. Fecha"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Ingrese la opción: "<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            ven_emp();
            system("pause");
            break;
        case 2:
            ven_cli();
            system("pause");
            break;
        case 3:
            ven_fecha();
            system("pause");
            break;
        case 0:
            return ;
        default:
            cout<<"Opción incorrecta. Presione una tecla para continuar";
            system("pause>null");
            break;
        }
    }

};

void ven_emp()
{
    system("cls");
    int cod,dni,pos=-1;
    Ventas reg;
    cout<<"ingrese el código de la venta a editar"<<endl;
    cin>>cod;
    pos=buscar_codventa(cod);
    if(pos!=-1)
    {
        if(reg.Leer_de_disco(pos)==true)
        {

            cout<<"ingrese el nuevo dni del empleado"<<endl;
            cin>>dni;
            pos=buscar_dni_empleado(dni);
            if(pos!=-1){
                reg.set_dni_emlpeado(dni);
                if(reg.Modificar_de_disco(pos)==true)
                {
                    cout<<"Modificó"<<endl;
                }
                else
                {
                    cout<<"Error al Modificar"<<endl;
                }
            }

        }
        else
        {
            cout<<"no se pudo leer de disco"<<endl;
        }

    }
    else
    {
        cout<<"no se encontró el codigo de venta"<<endl;
        return;
    }


};

void ven_cli()
{
    system("cls");
    int cod,dni,pos=-1;
    Ventas reg;
    cout<<"ingrese el codigo de la venta a editar"<<endl;
    cin>>cod;
    pos=buscar_codventa(cod);
    if(pos!=-1)
    {
        if(reg.Leer_de_disco(pos)==true)
        {
            cout<<"ingrese el nuevo dni del cliente"<<endl;
            cin>>dni;
            pos=buscar_dni(dni);
            if(pos!=-1){
               reg.set_dni_cliente(dni);
            {
                if(reg.Modificar_de_disco(pos)==true)
                {
                    cout<<"Modificó"<<endl;
                    system("pause");
                }
                else
                {
                    cout<<"Error al Modificar"<<endl;
                    system("pause");
                }
            }

            }

        }
        else
        {
            cout<<"no se pudo leer de disco"<<endl;
            system("pause");
        }


    }
    else
    {
        cout<<"no se encontró el código de venta"<<endl;
        return;
    }

};


void ven_fecha()
{
    system("cls");
    int cod,dia,mes,anio,pos=-1;
    Ventas reg;
    cout<<"ingrese el código de la venta a editar"<<endl;
    cin>>cod;
    pos=buscar_codventa(cod);
    if(pos!=-1)
    {
        if(reg.Leer_de_disco(pos)==true)
        {

            cout<<"ingrese la  nueva fecha"<<endl;
            cout<<"fecha"<<endl;
            cout<<"dia: "<<endl;
            cin>>dia;
            cout<<"mes: "<<endl;
            cin>>mes;
            cout<<"año: "<<endl;
            cin>>anio;
            pos=comprobar_fecha(dia,mes,anio);
            if(pos!=-1){
            reg.Modificar_fecha(dia,mes,anio);
            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"Modificó"<<endl;
            }
            else
            {
                cout<<"Error al Modificar"<<endl;
            }

            }

        }
        else
        {
            cout<<"no se pudo leer de disco"<<endl;
        }

    }
    else
    {
        cout<<"no se encontró el codigo de venta"<<endl;
        return;
    }

};
#endif // MOD_VENTAS_H_INCLUDED
