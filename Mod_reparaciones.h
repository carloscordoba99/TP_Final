#ifndef MOD_REPARACIONES_H_INCLUDED
#define MOD_REPARACIONES_H_INCLUDED
void Mod_reparaciones()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"Modificación de Reparaciones"<<endl;
        cout<<"1. Dni.cliente"<<endl;
        cout<<"2. Precio"<<endl;
        cout<<"3. fecha"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Ingrese la opcion: "<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            rep_Dni_cli();
            system("pause");
            break;
        case 2:
            rep_Precio();
            system("pause");
            break;
        case 3:
            rep_fecha();
            system("pause");
            break;
        case 4:
            return;
        default:
            cout<<"Opcion incorrecta. Presione una tecla para continuar";
            system("pause>null");
            break;
        }
    }

}

void rep_Precio()
{
    int dni,pos=0,precio;
    Reparaciones reg;
    cout<<"introduzca dni del cliente "<<endl;
    cin>>dni;
    pos=buscar_dni_reparaciones(dni);
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"introduzca el nuevo precio"<<endl;
        cin>>precio;
        reg.set_precio(precio);

            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"modificó"<<endl;
                system("pause");
            }
            else
            {
                cout<<"error al grabar"<<endl;
                system("pause");
            }

    }
    else
    {
        cout<<"no se pudo leer el registro"<<endl;
        system("pause");
        return;
    }


}

void rep_Dni_cli()
{
    int dni,pos=0,dnin;
    Reparaciones reg;
    cout<<"introduzca dni del cliente "<<endl;
    cin>>dni;
    pos=buscar_dni_reparaciones(dni);
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"introduzca el nuevo dni del cliente"<<endl;
        cin>>dnin;
        reg.set_dnicliente(dnin);

            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"modificó"<<endl;
                system("pause");
            }
            else
            {
                cout<<"error al grabar"<<endl;
                system("pause");
            }

    }
    else
    {
        cout<<"no se pudo leer el registro"<<endl;
        system("pause");
    }
};



void rep_fecha()
{
    int dni,pos=0,dia,mes,anio;
    Reparaciones reg;
    cout<<"introduzca dni del cliente "<<endl;
    cin>>dni;
    pos=buscar_dni_reparaciones(dni);
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"introduzca la nueva fecha"<<endl;
        cout<<"fecha"<<endl;
        cout<<"dia: "<<endl;
        cin>>dia;
        cout<<"mes: "<<endl;
        cin>>mes;
        cout<<"año: "<<endl;
        cin>>anio;
        reg.Modificar_fecha(dia,mes,anio);
        if(reg.Modificar_de_disco(pos)==true)
        {
            cout<<"modificó"<<endl;
            system("pause");
        }
        else
        {
            cout<<"error al grabar"<<endl;
            system("pause");
        }
    }
    else
    {
        cout<<"no se pudo leer el registro"<<endl;
        system("pause");
    }
};

#endif // MOD_REPARACIONES_H_INCLUDED
