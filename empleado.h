#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

class Empleado:public Persona
{
private:
    int sueldo;
    Fecha fecha_ingreso;
public:
    bool cargar();
    void mostrar();
    int get_sueldo()
    {
        return sueldo;
    }
    Fecha get_fechaingreso()
    {
        return fecha_ingreso;
    }
    bool set_sueldo(int s)
    {
        if(s>0){
            sueldo=s;
        return true;
        }else{
        cout<<"Error Sueldo invalido"<<endl;
        return false;
        }

    }
    bool set_fechaingreso(Fecha u)
    {
        fecha_ingreso=u;
        return true;
    }
    bool Grabar_en_disco();
    bool Leer_de_disco(int );
    bool Modificar_de_disco(int);

};



//****************
//DESARROLLO DE LOS METODOS

bool Empleado::cargar()
{
    system("cls");
    int dia,mes,anio,pos=-1,sueldo;
    Persona::cargar();
    if(buscar_dni_empleado(dni)==-1)
    {
        cout << "ingresar sueldo: " << endl;
        cin >> sueldo;
        bool b;
        b=set_sueldo(sueldo);
        cout << "ingresar fecha ingreso (d/m/a): " << endl;
        cin>>dia;
        cin>>mes;
        cin>>anio;
        pos=comprobar_fecha(dia,mes,anio);
        if(pos!=-1){
        fecha_ingreso.setDia(dia);
        fecha_ingreso.setMes(mes);
        fecha_ingreso.setAnio(anio);
        return true;
        }else{
        return false;
        }
    }
    else
    {
        cout << "ya existe el dni. " << endl;
        system("pause");
        return false;
    }

}

void Empleado::mostrar()
{
    system("cls");
    Persona::mostrar();
    cout << "sueldo: " << sueldo << endl;
    cout << "fecha ingreso: " << fecha_ingreso.getDia() << "/" << fecha_ingreso.getMes() << "/" << fecha_ingreso.getAnio() << endl;
}

bool Empleado::Modificar_de_disco(int pos)
{
    bool listo;
    FILE *p;
    p=fopen("empleados.dat","rb+");
    if(p==NULL)
        return false;
    fseek(p,sizeof (Empleado)*pos,0);
    listo=fwrite(this,sizeof (Empleado),1,p);
    fclose(p);
    return listo;
}


bool Empleado::Grabar_en_disco()
{
    FILE *p;
    p=fopen("empleados.dat","ab");
    if(p==NULL)
        return false;
    bool escribio=fwrite(this,sizeof (Empleado),1,p);
    fclose(p);
    return escribio;
}

bool Empleado::Leer_de_disco(int pos)
{
    Empleado reg;
    FILE *p;
    p=fopen("empleados.dat","rb");
    if(p==NULL)
        return false;
    fseek(p,sizeof (Empleado)*pos,0);
    bool leyo=fread(this,sizeof (Empleado),1,p); ///tambien puede ser sizeof *this (peso de lo que apunta el puntero).
    fclose(p);
    return leyo;
}


//******************************************************
//FUNCIONES EXTERNAS


int buscar_empleado_apellido(const char *);
void ordenar_empleado(Empleado *v, int);
void leer_alfa_empleado();
void leer_anti_empleado();
void ordenar_empleado2(Empleado *v,int);
int buscar_empleado_fi(Fecha f);


void ordenar_empleado2(Empleado *v, int cant)
{
    int i, j, posmin;
    Empleado aux;
    for(i=0; i<cant-1; i++)
    {

        posmin=i;
        for(j=i+1; j<cant; j++)
        {
            ///int fecha,fecha1;
            ///fecha=v[posmin].get_fechaingreso.NumeroSerie();
            ///fecha1=v[j].get_fechaingreso.NumeroSerie();
            if(v[posmin].get_fechaingreso().NumeroSerie()>v[j].get_fechaingreso().NumeroSerie())
            {
//        if(strcmp(v[posmin].desc,v[j].desc)>0)
                //if(v[posmin].pu>v[j].pu)
                posmin=j;
            }
        }
        aux.set_fechaingreso(v[i].get_fechaingreso());
        v[i].set_fechaingreso(v[posmin].get_fechaingreso());
        v[posmin].set_fechaingreso(aux.get_fechaingreso());

    }


}


void leer_anti_empleado()
{
    Empleado reg;
    int tam=0;
    tam=contarRegistrosEmpleado();
    Empleado *p;
    p=new Empleado[tam];
    if(p==NULL)
    {
        cout << "error de asignación. " << endl;
        system("pause");
        return;
    }
    int pos=0;
    while(reg.Leer_de_disco(pos)==true)
    {
        p[pos].set_fechaingreso(reg.get_fechaingreso());
        pos++;
    }
    ordenar_empleado2(p,tam);
    for (int i=0; i<tam; i++)
    {
        pos=buscar_empleado_fi(p[i].get_fechaingreso());
        if(reg.Leer_de_disco(pos)==true)
        {
            if(reg.get_activo()==true)
            {
                reg.mostrar();
                system("pause");
            }

        }

    }
    delete p;
}

void ordenar_empleado(Empleado *v, int cant)
{
    int i, j, posmin;
    Empleado aux;
    for(i=0; i<cant-1; i++)
    {

        posmin=i;
        for(j=i+1; j<cant; j++)
        {
            if(strcmp(v[posmin].get_apellido(),v[j].get_apellido())>0)
            {
//        if(strcmp(v[posmin].desc,v[j].desc)>0)
                //if(v[posmin].pu>v[j].pu)
                posmin=j;
            }
        }
        aux.set_apellido(v[i].get_apellido());
        v[i].set_apellido(v[posmin].get_apellido());
        v[posmin].set_apellido(aux.get_apellido());

    }


}


void leer_alfa_empleado()
{
    Empleado reg;
    int tam=0;
    tam=contarRegistrosEmpleado();
    Empleado *p;
    p=new Empleado[tam];
    if(p==NULL)
    {
        cout << "error de asignación. " << endl;
        system("pause");
        return;
    }
    int pos=0;
    while(reg.Leer_de_disco(pos)==true)
    {
        p[pos].set_apellido(reg.get_apellido());
        pos++;
    }
    ordenar_empleado(p,tam);
    for (int i=0; i<tam; i++)
    {
        pos=buscar_empleado_apellido(p[i].get_apellido());
        if(reg.Leer_de_disco(pos)==true)
        {
            if(reg.get_activo()==true){
                reg.mostrar();
                system("pause");
            }

        }

    }
    delete p;
}

int contarRegistrosEmpleado()
{
    FILE *p;
    p=fopen("empleados.dat", "rb");
    if(p==NULL)
        return 0;
    fseek(p,0,2);
    int cantByte=ftell(p);
    fclose(p);
    return cantByte/sizeof(Empleado);
}

void alta_empleado()
{
    Empleado reg;
    system("cls");
    if(reg.cargar()==true)
    {
        if(reg.Grabar_en_disco()==true)
        {
            cout << "el empleado se grabó con exito. " << endl;
            system("pause>null");
        }
    }
    else
    {

    return;

    }
}


bool leer_empleado()
{
    Empleado reg;
    int pos=0;
    while(reg.Leer_de_disco(pos)==true)
    {
        if(reg.get_activo()==true)
        {
            reg.mostrar();
            system("pause");
        }

        pos++;
    }
    return true;
}


int buscar_empleado(int dni)  ///SI NO ANDA ESTA FUNCION POR EL THIS, REEMPLAZAR FREAD POR LEERDEDISCO.
{
    int pos=0;
    Empleado reg;
    while(reg.Leer_de_disco(pos)==true)
    {
        if(reg.get_dni()==dni)
        {
            return pos;
        }
        pos++;

    }
    return -1;
}


void baja_empleado()
{
    int pos,dni;
    Empleado reg;
    cout << "ingresar dni: " << endl;
    cin >> dni;
    pos=buscar_dni_empleado(dni);
    if(pos==-1)
    {
        cout << "no se encuentra el dni en el archivo. " << endl;
        system("pause");
        return;

    }
    if(reg.Leer_de_disco(pos)==true)
    {
        reg.set_activo(false);
            if(reg.Modificar_de_disco(pos)==true){
                cout << "el empleado se dió de baja. " << endl;
                system("pause");
            }
            else{
                cout << "el empleado no se pudo dar de baja. " << endl;
                system("pause");
            }
    }

}

int buscar_empleado_apellido(const char *n)
{
    int pos=0;
    Empleado reg;
    while(reg.Leer_de_disco(pos)==true)
    {
        if(strcmp(reg.get_apellido(),n)==0)
        {
            return pos;
        }
        pos++;

    }
    return -1;
}

int buscar_empleado_fi(Fecha f)
{
    int pos=0;
    Empleado reg;
    while(reg.Leer_de_disco(pos)==true)
    {
        if(reg.get_fechaingreso()==f)
        {
            return pos;
        }
        pos++;

    }
    return -1;
}


int buscar_dni_empleado(int dni)
{
    int pos=0;
    Empleado reg;
    while(reg.Leer_de_disco(pos)==true)
    {
        if(reg.get_dni()==dni)
        {
            return pos;
        }
        pos++;

    }
    return -1;
}

void busq_dni_emp()
{
    Empleado reg;
    int dni,pos;
    cout << "ingrese dni empleado: " << endl;
    cin >> dni;
    if(buscar_dni_empleado(dni)!=-1)
    {
        pos=0;
        while(reg.Leer_de_disco(pos)==true)
        {
            if(reg.get_dni()==dni)
            {
                reg.mostrar();
                system("pause");
            }
            pos++;
        }
    }
    else
    {
        cout << "no existe el dni en archivo empleados! " << endl;
        system("pause");
    }
}


void menu_empleado()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"Menu Empleado"<<endl;
        cout<<"1. Alta"<<endl;
        cout<<"2. baja"<<endl;
        cout<<"3. Modificación"<<endl;
        cout<<"4. Listado"<<endl;
        cout<<"5. Reportes"<<endl;
        cout<<"0. Atras"<<endl;
        cout<<"Ingrese la opcion: "<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            alta_empleado();
            system("pause");
            break;
        case 2:
            baja_empleado();
            system("pause");
            break;
        case 3:
            Mod_empleado();
            break;
        case 4:
            bool bandera;
            bandera=leer_empleado();
            break;
        case 5:
            reportes_empleado();
            break;
        case 0:
            return;
        default:
            cout<<"Opción incorrecta. Presione una tecla para continuar";
            system("pause>null");
            break;
        }
    }

}

void reportes_empleado()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"Reportes Empleados"<<endl;
        cout<<"1. Por apellido alfabéticamente"<<endl;
        cout<<"2. Por antigüedad"<<endl;
        cout<<"3. Por dni"<<endl;
        cout<<"0. Atras"<<endl;
        cout<<"Ingrese la opcion: "<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            leer_alfa_empleado();
            break;
        case 2:
            leer_anti_empleado();
            break;
        case 3:
            busq_dni_emp();
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


#endif // EMPLEADO_H_INCLUDED
