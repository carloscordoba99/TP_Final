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
       Articulo();
       void cargar();
       void mostrar();
       int get_nroart(){return nroart;}
       float get_precio(){return precio;}
       int get_stock(){return stock;}
       bool get_activo(){return activo;}
       const char * get_nombre(){return nombre;}
       void set_nroart(int art){nroart=art;}
       void set_precio(float p){precio=p;}
       void set_stock(int s){stock=s;}
       void set_activo(bool a){activo=a;}
       void set_nombre(const char *n){strcpy(nombre,n);}
       bool Grabar_en_disco();
       bool leer_de_disco(int );
};

//****************
//desarrollo de los metodos
Articulo::Articulo( int n=0,const char *c="0", float p=0.0, int s=0,bool b=true)
  {
    nroart=n;
    strcpy(nombre,c);
    precio=p;
    stock=s;
    activo=b;
    }


void Articulo::cargar(){
    system("cls");
    cout << "INGRESAR NOMBRE: " << endl;
    cin >> nombre;
    cout << "INGRESAR NRO ART: " << endl;
    cin >> nroart;
    cout << "INGRESAR PRECIO: " << endl;
    cin >> precio;
    cout << "INGRESAR STOCK: " << endl;
    cin >> stock;
    activo=true;
}

void Articulo::mostrar(){
    system("cls");
    cout << "INGRESAR NOMBRE: " << endl;
    cin >> nombre;
    cout << "INGRESAR NRO ART: " << endl;
    cin >> nroart;
    cout << "INGRESAR PRECIO: " << endl;
    cin >> precio;
    cout << "INGRESAR STOCK: " << endl;
    cin >> stock;
    activo=true;
}

void BajaLogica(){
    Articulo reg;
    int codart;
    cout << "ingresar cod art: " << endl;
    cin >> codart;

}

void bajaLogica(){
    int dni,pos;
    struct musicos reg;
    cout << "ingresar DNI. " << endl;
    cin >> dni;
    pos=buscarMusico(dni);
    if(pos==-1){
        cout << "no se encuentra el dni en el archivo. " << endl;
    }
    ///else{ cout << "el dni tiene la posicion" << pos << endl; }
    reg=leerMusico(pos);
    reg.activo=false;
    if(modificarRegistroMusico(reg,pos)==false){
        cout << "no se pudo dar de baja " << endl;
    }
    else { cout << "el alumno se dio de baja " << endl;
    }
}


int buscar_art(int codart){
    int pos=0;
    Articulo reg;
    FILE *p;
    p=fopen(articulos.dat,"rb");
    if(p==NULL) return -1;
    while(fread(this,sizeof (Articulo),1,p)==1){
        if(reg.get_nroart()==codart){
            return pos;
        }
        pos++;

    }
    fclose(p);
    return -1;
}

bool Articulo::Grabar_en_disco(){
    FILE *p;
    p=fopen("articulos.dat","ab");
    if(p==NULL) return false;
    bool escribio=fwrite(this,sizeof (Articulo),1,p);
    fclose(p);
    return escribio;
}

bool Articulo::leer_de_disco(int pos){
    Articulo reg;
    FILE *p;
    p=fopen("articulos.dat","rb");
    if(p==NULL) return false;
    fseek(p,sizeof (Articulo)*pos,0);
    bool leyo=fread(this,sizeof (Alumno),1,p); ///tambien puede ser sizeof *this (peso de lo que apunta el puntero).
    fclose(p);
    return leyo;
}

bool leer_art(){
    Articulo reg;
    int pos=0;
    while(leer_de_disco(pos)==true){
        reg.mostrar();
        cout<<endl;
        pos++;
        }
    return true;
}

//******************
//FUNCIONES EXTERNAS

void menu_articulos(){
	int opc;
	while(1)
		{
		system("cls");
		cout<<"MENU ARTICULOS"<<endl;
		cout<<"1. Altas"<<endl;
		cout<<"2. Modificar precio unitario"<<endl;
		cout<<"3. Baja"<<endl;
		cout<<"4. Listado"<<endl;
		cout<<"5. Volver al MENU PRINCIPAL"<<endl;
		cout<<"INGRESE LA OPCION: "<<endl;
		cin>>opc;
		switch(opc)
			{
			 case 1: /**alta_art()*/;break;
			 case 2: /**modifica_pu()*/;break;
			 case 3: /**baja_logica_art()*/;break;
			 case 4:/**listar_art();*// break;
			 case 5: return;
			 default: cout<<"Opcion incorrecta. Presione una tecla para continuar";
								system("pause>null");
								break;
			}
		}
	}

//FIN FUNCIONES EXTERNAS

#endif // ARTICULO_H_INCLUDED
