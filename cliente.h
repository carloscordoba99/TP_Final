#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

class Cliente:public Persona
{

private:
    char email[30];
public:
    bool cargar();
    void mostrar();
    char * get_email()
    {
        return email;
    }
    void set_email(const char *e)
    {
        strcpy(email,e);
    }
    bool Grabar_en_disco();
    bool Leer_de_disco(int );
    bool Modificar_de_disco(int);


};

//****************
//DESARROLO DE LOS METODOS

bool Cliente::cargar()
{
    system("cls");
    Persona::cargar();
    if(buscar_dni(dni)==-1)
    {
        cout << "ingresar email: " << endl;
        cin >> email;
        activo=true;
        return true;
    }
    else
    {
        return false;
    }
}

void Cliente::mostrar()
{
    system("cls");
    Persona::mostrar();
    cout << "email: " << email << endl;
}

bool Cliente::Modificar_de_disco(int pos)
{
    bool listo;
    FILE *p;
    p=fopen("clientes.dat","rb+");
    if(p==NULL)
        return false;
    fseek(p,sizeof (Cliente)*pos,0);
    listo=fwrite(this,sizeof (Cliente),1,p);
    fclose(p);
    return listo;
}

bool Cliente::Grabar_en_disco()
{
    FILE *p;
    p=fopen("clientes.dat","ab");
    if(p==NULL)
        return false;
    bool escribio=fwrite(this,sizeof (Cliente),1,p);
    fclose(p);
    return escribio;
}

bool Cliente::Leer_de_disco(int pos)
{
    Cliente reg;
    FILE *p;
    p=fopen("clientes.dat","rb");
    if(p==NULL)
        return false;
    fseek(p,sizeof (Cliente)*pos,0);
    bool leyo=fread(this,sizeof (Cliente),1,p); ///tambien puede ser sizeof *this (peso de lo que apunta el puntero).
    fclose(p);
    return leyo;
}

//******************************************************
//FUNCIONES EXTERNAS


int buscar_cli_apellido(const char *);
void ordenar_cli(Cliente *v, int);
void leer_alfa_cli();

void ordenar_cli(Cliente *v, int cant)
{
    int i, j, posmin;
    Cliente aux;
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
        aux.set_apellido(v[i].get_apellido());///aux=v[i];
        v[i].set_apellido(v[posmin].get_apellido());///v[i]=v[posmin];
        v[posmin].set_apellido(aux.get_apellido());///v[posmin]=aux;

    }


}


void leer_alfa_cli()
{

    Cliente reg;///apertura del archivo.
    int tam=0;
    tam=contarRegistrosCliente();
    Cliente *p;
    p=new Cliente[tam];
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
    ordenar_cli(p,tam);
    for (int i=0; i<tam; i++)
    {
        pos=buscar_cli_apellido(p[i].get_apellido());
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

int contarRegistrosCliente()
{
    FILE *p;
    p=fopen("clientes.dat", "rb");
    if(p==NULL)
        return 0;
    fseek(p,0,2);
    int cantByte=ftell(p);
    fclose(p);
    return cantByte/sizeof(Cliente);
}


void alta_cliente()
{
    Cliente reg;
    system("cls");
    if(reg.cargar()==true)
    {
        if(reg.Grabar_en_disco()==true)
        {
            cout << "el cliente se grabó con exito. " << endl;
            system("pause");

        }
    }
    else
    {
        cout<<"Ya existe ese cliente";
        cout<<"Presione una tecla para continuar";
        system("pause>null");

    }
}


void baja_cliente()
{
    int pos,dni;
    Cliente reg;
    cout << "ingresar dni: " << endl;
    cin >> dni;
    pos=buscar_dni(dni);
    if(pos==-1)
    {
        cout << "no se encuentra el dni en el archivo. " << endl;
        system("pause");
        return;
    }
    if(reg.Leer_de_disco(pos)==true)
    {
        reg.set_activo(false);
    }
    if(reg.Modificar_de_disco(pos)==false)
    {
        cout << "no se pudo dar de baja. " << endl;
        system("pause");
    }
    else
    {
        cout << "el cliente se dio de baja. " << endl;
        system("pause");
    }
}

bool leer_clientes()
{
    Cliente reg;
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

int buscar_cli_apellido(const char *n)
{
    int pos=0;
    Cliente reg;
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

int buscar_dni(int dni)
{
    int pos=0;
    Cliente reg;
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


void busq_dni_cli()
{
    Cliente reg;
    int dni,pos;
    cout << "ingrese dni cliente: " << endl;
    cin >> dni;
    pos=buscar_dni(dni);
    if(pos!=-1){

        if(reg.Leer_de_disco(pos)==true)
        {
            if(reg.get_activo()==true){
                reg.mostrar();
                system("pause");
            }

        }
    }
    else
    {
        cout << "no existe el dni en archivo clientes! " << endl;
        system("pause");
    }
}


void menu_clientes()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"Menu Clientes"<<endl;
        cout<<"1. Alta"<<endl;
        cout<<"2. baja"<<endl;
        cout<<"3. Modificación"<<endl;
        cout<<"4. Listado"<<endl;
        cout<<"5. Reportes"<<endl;
        cout<<"0. Atras"<<endl;
        cout<<"Ingrese la opción: "<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            alta_cliente();
            system("pause");
            break;
        case 2:
            baja_cliente();
            system("pause");
            break;
        case 3:
            Mod_cliente();
            break;
        case 4:
            bool bandera;
            bandera=leer_clientes();
            break;
        case 5:
            reportes_cli();
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


void reportes_cli()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"Reportes Clientes"<<endl;
        cout<<"1. Por apellido alfabéticamente"<<endl;
        cout<<"2. Por dni"<<endl;
        cout<<"0. Atras"<<endl;
        cout<<"Ingrese la opcion: "<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            leer_alfa_cli();
            system("pause");
            break;
        case 2:
            busq_dni_cli();
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


#endif // CLIENTE_H_INCLUDED
