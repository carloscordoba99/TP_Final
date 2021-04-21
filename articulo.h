#ifndef ARTICULO_H_INCLUDED
#define ARTICULO_H_INCLUDED

class Articulo
{
private:
    int nroart;
    char nombre[20];
    float precio;
    int stock;
    bool activo;
public:
    int autonumerico_nroart();
    Articulo(int,const char*,float,int,bool);
    bool cargar();
    void mostrar();
    int get_nroart()
    {
        return nroart;
    }
    float get_precio()
    {
        return precio;
    }
    int get_stock()
    {
        return stock;
    }
    bool get_activo()
    {
        return activo;
    }
    const char * get_nombre()
    {
        return nombre;
    }
    void set_nroart(int art)
    {
        nroart=art;
    }
    void set_restarstock(int cant){
        int s;
        s=stock;
        stock=(s-cant);
    }
    void set_precio(float p)
    {
        precio=p;
    }
    void set_stock(int s)
    {
        stock=s;
    }
    void set_activo(bool a)
    {
        activo=a;
    }
    void set_nombre(const char *n)
    {
        strcpy(nombre,n);
    }
    bool Grabar_en_disco();
    bool Leer_de_disco(int );
    bool Modificar_de_disco(int);
};

//****************
//DESARROLLO DE LOS METODOS
Articulo::Articulo( int n=0,const char *c="nombreX", float p=0, int s=0,bool b=true)
{
    nroart=n;
    strcpy(nombre,c);
    precio=p;
    stock=s;
    activo=b;
}



bool Articulo::cargar()
{
    system("cls");
    cout << "ingresar nombre: " << endl;
    cargarCadena(nombre,19);
    if(buscar_art_nombre(nombre)!=-1){
        cout << "ya se encuentra registrado el nombre de articulo. " << endl;
        system("pause");
        return false;
    }

    nroart=autonumerico_nroart()+1;
    if(nroart==0){
        nroart=1;
    }
    cout << "ingresar precio: " << endl;
    cin >> precio;
    cout << "ingresar stock: " << endl;
    cin >> stock;
    activo=true;
    return true;
}

void Articulo::mostrar()
{
    system("cls");
    cout << "nro art: " << nroart << endl;
    cout << "nombre: " << nombre << endl;
    cout << "precio: " << precio << endl;
    cout << "stock: " << stock << endl;
}



bool Articulo::Modificar_de_disco(int pos)
{
    bool listo;
    FILE *p;
    p=fopen("articulos.dat","rb+");
    if(p==NULL)
        return false;
    fseek(p,sizeof (Articulo)*pos,0);
    listo=fwrite(this,sizeof (Articulo),1,p);
    fclose(p);
    return listo;
}


bool Articulo::Grabar_en_disco()
{
    FILE *p;
    p=fopen("articulos.dat","ab");
    if(p==NULL)
        return false;
    bool escribio=fwrite(this,sizeof (Articulo),1,p);
    fclose(p);
    return escribio;
}

bool Articulo::Leer_de_disco(int pos)
{
    Articulo reg;
    FILE *p;
    p=fopen("articulos.dat","rb");
    if(p==NULL)
    return false;
    fseek(p,sizeof (Articulo)*pos,0);
    bool leyo=fread(this,sizeof (Articulo),1,p); ///tambien puede ser sizeof *this (peso de lo que apunta el puntero).
    fclose(p);
    return leyo;
}


int Articulo::autonumerico_nroart(){
    Articulo reg;
    int pos;
    FILE *p;
    p=fopen("articulos.dat","rb");
    if(p==NULL)
    return -1;
    fseek(p,0,2);
    pos=ftell(p)/sizeof (Articulo);
    fclose(p);
    return pos;

}

///////////////// REPORTES /////////////////
int buscar_art_nombre(const char *);
int buscar_art_precio(float);
void ordenar_art(Articulo *v, int);
void ordenar_art2 (Articulo *v, int);
void leer_alfa_art();
void leer_precio_art();


//******************************************************
//FUNCIONES EXTERNAS


float calcular_importe(int nroart,int cantidad){
    Articulo reg;
    int pos=0;
    float importe;
    while(reg.Leer_de_disco(pos)==true){
        if(reg.get_nroart()==nroart){
            importe=reg.get_precio()*cantidad;
            return importe;
        }
    pos++;
    }
    cout<<"Erro No se encontro el registro"<<endl;
    return false;

}

void ordenar_art2 (Articulo *v, int cant)
{
    int i, j, posmin;
    Articulo aux;
    for(i=0; i<cant-1; i++)
    {

        posmin=i;
        for(j=i+1; j<cant; j++)
        {
//        if(strcmp(v[posmin].desc,v[j].desc)>0)
            if(v[posmin].get_precio()>v[j].get_precio())
            {
                posmin=j;
            }
        }
        aux.set_precio(v[i].get_precio());
        v[i].set_precio(v[posmin].get_precio());
        v[posmin].set_precio(aux.get_precio());

    }


}


void ordenar_art (Articulo *v, int cant)
{
    int i, j, posmin;
    Articulo aux;
    for(i=0; i<cant-1; i++)
    {

        posmin=i;
        for(j=i+1; j<cant; j++)
        {
            if(strcmp(v[posmin].get_nombre(),v[j].get_nombre())>0)
            {
//        if(strcmp(v[posmin].desc,v[j].desc)>0)
                //if(v[posmin].pu>v[j].pu)
                posmin=j;
            }
        }
        aux.set_nombre(v[i].get_nombre());///aux=v[i];
        v[i].set_nombre(v[posmin].get_nombre());///v[i]=v[posmin];
        v[posmin].set_nombre(aux.get_nombre());///v[posmin]=aux;

    }


}

void leer_precio_art()
{

    Articulo reg;
    int tam=0;
    tam=contarRegistrosArticulo();
    Articulo *p;
    p=new Articulo[tam];
    if(p==NULL)
    {
        cout << "error de asignación. " << endl;
        system("pause");
        return;
    }
    int pos=0;
    while(reg.Leer_de_disco(pos)==true)
    {
        p[pos].set_precio(reg.get_precio());
        pos++;
    }
    ordenar_art2(p,tam);
    cout << "Articulos por precio: " << endl;
    for (int i=0; i<tam; i++)
    {
        pos=buscar_art_precio(p[i].get_precio());
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


void leer_alfa_art()
{

    Articulo reg;///apertura del archivo.
    int tam=0;
    tam=contarRegistrosArticulo();
    Articulo *p;
    p=new Articulo[tam]; ///DEVOLVERLA.
    if(p==NULL)
    {
        cout << "error de asignación. " << endl;
        system("pause");
        return;
    }
    int pos=0;
    while(reg.Leer_de_disco(pos)==true)
    {
        p[pos].set_nombre(reg.get_nombre());
        pos++;
    }
    ///ordenar vector
    ordenar_art(p,tam);///GUIARSE POR EL VECTOR ORDENADO Y BUSCAR LOS ARCHIVOS CORRESPONDIENTES PARA MOSTRARLOS EN ORDEN
    for (int i=0; i<tam; i++)
    {
        pos=buscar_art_nombre(p[i].get_nombre());
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

int contarRegistrosArticulo()
{
    FILE *p;
    p=fopen("articulos.dat", "rb");
    if(p==NULL)
        return 0;
    fseek(p,0,2);
    int cantByte=ftell(p);
    fclose(p);
    return cantByte/sizeof(Articulo);
}



void alta_art()
{
    Articulo reg;
    system("cls");
    if(reg.cargar()==true)
    {
        if(reg.Grabar_en_disco()==true)
        {
            cout << "el articulo se grabó con exito. " << endl;
            system("pause");
        }
    }

}


void baja_articulo()
{
    system("cls");
    int pos,cod;
    Articulo reg;
    cout << "ingresar cod. art: " << endl;
    cin >> cod;
    pos=buscar_art(cod);
    if(pos==-1)
    {
        cout << "no se encuentra el cod. en el archivo. " << endl;
        system("pause");
    }
    if(reg.Leer_de_disco(pos)==true)
    {
        reg.set_activo(false);
    }
    if(reg.Modificar_de_disco(pos)==false)
    {
        cout << "no se pudo dar de baja. " << endl;
        system("pause");
        return;
    }
    else
    {
        cout << "el articulo se dio de baja. " << endl;
        system("pause");
    }
}


bool leer_art()
{
    Articulo reg;
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

int buscar_art_precio(float precio)
{
    int pos=0;
    Articulo reg;
    while(reg.Leer_de_disco(pos)==true)
    {
        if(reg.get_precio()==precio)
        {
            return pos;
        }
        pos++;

    }
    return -1;
}


int buscar_art_nombre(const char *n)
{
    int pos=0;
    Articulo reg;
    while(reg.Leer_de_disco(pos)==true)
    {
        if(strcmp(reg.get_nombre(),n)==0)
        {
            return pos;
        }
        pos++;

    }
    return -1;
}


int buscar_art(int codart)
{
    int pos=0;
    Articulo reg;
    while(reg.Leer_de_disco(pos)==true)
    {
        if(reg.get_nroart()==codart)
        {
            if(reg.get_activo()==true){
            return pos;
            }

        }
        pos++;

    }
    return -1;
}


void menu_articulos()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"Menu Articulos"<<endl;
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
            alta_art();
            system("pause");
            break;
        case 2:
            baja_articulo();
            system("pause");
            break;
        case 3:
            Modificasion_art();
            system("pause");
            break;
        case 4:
            bool b;
            b=leer_art();
            system("pause");
            break;
        case 5:
            reportes_art();
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

void reportes_art()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"Reportes Articulos"<<endl;
        cout<<"1. Por nombre alfabético"<<endl;
        cout<<"2. Por precio"<<endl;
        cout<<"0. Atras"<<endl;
        cout<<"Ingrese la opción: "<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            leer_alfa_art();
            system("pause");
            break;
        case 2:
            leer_precio_art();
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


//FIN FUNCIONES EXTERNAS
#endif // ARTICULO_H_INCLUDED
