#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

class Ventas
{
private:
    int cod_venta;
    float importe_total;
    int dni_empleado;
    int dni_cliente;
    Fecha fechav;
    bool activo;
public:
    bool cargar();
    void mostrar();
    void set_importe_total(float n)
    {
        importe_total=n;
    }
    void set_acumularimporte(float i){
        importe_total=(importe_total+i);
    }
    void set_dni_emlpeado(int n)
    {
        dni_empleado=n;
    }
    void set_dni_cliente(int n)
    {
        dni_cliente=n;
    }
    void set_activo(bool f)
    {
        activo=f;
    }
    void set_codventa(int cv){
    cod_venta=cv;
    }
    float get_importe_total()
    {
        return importe_total;
    }
    int get_dnicliente(){return dni_cliente;}
    int get_codventa()
    {
        return cod_venta;
    }
    bool get_Activo()
    {
        return activo;
    }
    void Modificar_fecha(int dia,int mes,int anio);
    bool Modificar_de_disco(int );
    bool Grabar_en_disco();
    bool Leer_de_disco(int);

};



bool Ventas::cargar()
{
    system("cls");
    Ventas_detalle reg;
    bool bandera;
    int voto=1,pos;
    float importe;
    int dia,mes,anio,f=-1;
    cod_venta=autonumerico_codventa()+1;
    if(cod_venta==0){
        cod_venta=1;
    }
    cout << "ingresar dni empleado: " << endl;
    cin >> dni_empleado;
    if(buscar_dni_empleado(dni_empleado)!=-1)
    {
        cout << "ingresar dni clinte: " << endl;
        cin >> dni_cliente;
        if(buscar_dni(dni_cliente)!=-1)
        {
            cout<<"fecha "<<endl;
            cout<<"dia: "<<endl;
            cin>>dia;
            cout<<"mes: "<<endl;
            cin>>mes;
            cout<<"año: "<<endl;
            cin>>anio;
            f=comprobar_fecha(dia,mes,anio);
            if(f==-1)return false;
            fechav.setDia(dia);
            fechav.setMes(mes);
            fechav.setAnio(anio);
            activo=true;
            importe_total=0;
            //bandera=Grabar_en_disco();
            int vuelta=1;
            while(voto==1){
                importe=reg.cargar(cod_venta);
                if(importe!=-1){
                        if(vuelta==1) {bandera=Grabar_en_disco();}
                        if(reg.Grabar_en_disco()==true){
                            pos=buscar_codventa(cod_venta);
                                if(Leer_de_disco(pos)==true){
                                    set_acumularimporte(importe);
                                    if(Modificar_de_disco(pos)==true){
                                    }
                                    else{
                                        cout << "no se pudo modificar ." << endl;
                                        system("pause");
                                        return false;
                                    }

                                    cout << "desea cargar otro artículo ? (1:sí / 2:no) " << endl;
                                    cin >> voto;
                                    vuelta++;
                                }
                                else{
                                    cout << "no se pudo leer" << endl;
                                    system("pause");
                                    return false;
                                }
                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        return false;
                    }
            }
            return true;

        }
        else{
            cout << "no existe dni cliente. " << endl;
            system("pause");
            return false;
        }
    }
    else{
        cout << "no existe dni de empleado. " << endl;
        system("pause");
        return false;
    }

}

void Ventas::mostrar()
{
    system("cls");
    cout << "cod. venta: " << cod_venta << endl;
    cout << "importe total: " << importe_total << endl;
    cout << "dni empleado: " << dni_empleado << endl;
    cout << "dni cliente: " << dni_cliente << endl;
    cout<<"fecha: " << fechav.getDia() << "/" << fechav.getMes() << "/" << fechav.getAnio() << endl;

}




bool Ventas::Modificar_de_disco(int pos)
{
    bool listo;
    FILE *p;
    p=fopen("ventas.dat","rb+");
    if(p==NULL)
        return false;
    fseek(p,sizeof (Ventas)*pos,0);
    listo=fwrite(this,sizeof (Ventas),1,p);
    fclose(p);
    return listo;
}



bool Ventas::Grabar_en_disco()
{
    FILE *p;
    p=fopen("ventas.dat","ab");
    if(p==NULL)
        return false;
    bool escribio=fwrite(this,sizeof (Ventas),1,p);
    fclose(p);
    return escribio;
}

bool Ventas::Leer_de_disco(int pos)
{
    Ventas reg;
    FILE *p;
    p=fopen("ventas.dat","rb");
    if(p==NULL)
        return false;
    fseek(p,sizeof (Ventas)*pos,0);
    bool leyo=fread(this,sizeof (Ventas),1,p); ///tambien puede ser sizeof *this (peso de lo que apunta el puntero).
    fclose(p);
    return leyo;
}

int autonumerico_codventa(){
    Ventas reg;
    int pos;
    FILE *p;
    p=fopen("ventas.dat","rb");
    if(p==NULL){
    return -1;}
    fseek(p,0,2);
    pos=ftell(p)/sizeof (Ventas);
    fclose(p);
    return pos;

}




void Ventas::Modificar_fecha(int dia,int mes,int anio){
fechav.setDia(dia);
fechav.setMes(mes);
fechav.setAnio(anio);
};

//******************************************************
//FUNCIONES EXTERNAS

void leer_precio_ventas();

int buscar_codventa(int codventa)
{
    int pos=0;
    Ventas reg;
    while(reg.Leer_de_disco(pos)==true)
    {
        if(reg.get_codventa()==codventa)
        {
            return pos;
        }
        pos++;

    }
    return -1;
}




void baja_ventas()
{
    int pos,codventa;
    Ventas reg;
    cout << "ingresar cod. venta: " << endl;
    cin >> codventa;
    pos=buscar_codventa(codventa);//verifica que exista
    if(pos!=-1){
        if(baja_ventasdetalle(codventa)==true){ //borra todos registros con codventa en vd.
            if(reg.Leer_de_disco(pos)==true){
                reg.set_activo(false);
                if(reg.Modificar_de_disco(pos)==false){
                    cout << "no se pudo dar de baja. " << endl;
                    system("pause");
                }
                else{
                    cout << "la venta se dió de baja. " << endl;
                    system("pause");
                }
            }
        }
        else{
            cout << "no se pudo borrar registros en ventas detalle. " << endl;
            system("pause");
        }
    }
    else{
        cout << "no se encuentra el cod.venta en el archivo. " << endl;
        system("pause");
    }
}


void alta_ventas()
{
    Ventas reg;
    system("cls");
    if(reg.cargar()==true){
        cout << "la venta fue cargada con éxito. " << endl;
        system("pause");
    }

}


bool leer_ventas()
{
    Ventas reg;
    int pos=0;
    while(reg.Leer_de_disco(pos)==true)
    {
        if(reg.get_Activo()==true)
        {
            reg.mostrar();
            system("pause");
            leer_ventas_detalle(reg.get_codventa());

        }


        pos++;
    }
    return true;
}


void busq_cod_ven(){
    Ventas reg;
    int codventa,pos;
    cout << "ingrese cod. venta: " << endl;
    cin >> codventa;
    pos=buscar_codventa(codventa);
    if(pos!=-1){
        if(reg.Leer_de_disco(pos)==true){
                if(reg.get_Activo()==true){
                    reg.mostrar();
                    system("pause");
                    leer_ventas_detalle(codventa);
                }
            }
        }
        else{
            cout << "no existe el cod. venta en archivo ventas! " << endl;
            system("pause");
        }
}


void busq_dni_ventas()
{
    Cliente reg;
    Ventas aux;
    int dni,pos,existe;
    cout << "ingrese dni cliente: " << endl;
    cin >> dni;
    existe=buscar_dni(dni);
    pos=0;
    if(existe!=-1){
            while(aux.Leer_de_disco(pos)==true){
                if(aux.get_dnicliente()==dni){
                    aux.mostrar();
                    system("pause");
                    leer_ventas_detalle(aux.get_codventa());
                }
                pos++;
            }
    }
    else
    {
        cout << "no existe el dni en archivo clientes! " << endl;
        system("pause");
    }
}


int contarRegistrosVentas()
{
    FILE *p;
    p=fopen("ventas.dat", "rb");
    if(p==NULL)
        return 0;
    fseek(p,0,2);
    int cantByte=ftell(p);
    fclose(p);
    return cantByte/sizeof(Ventas);
}


void ordenar_ventas (Ventas *v, int cant)
{
    int i, j, posmin;
    Ventas aux;
    for(i=0; i<cant-1; i++)
    {

        posmin=i;
        for(j=i+1; j<cant; j++)
        {
//        if(strcmp(v[posmin].desc,v[j].desc)>0)
            if(v[posmin].get_importe_total()>v[j].get_importe_total())
            {
                posmin=j;
            }
        }
        aux.set_codventa(v[i].get_codventa());
        aux.set_importe_total(v[i].get_importe_total());
        v[i].set_codventa(v[posmin].get_codventa());
        v[i].set_importe_total(v[posmin].get_importe_total());
        v[posmin].set_importe_total(aux.get_importe_total());
        v[posmin].set_codventa(aux.get_codventa());

    }


}

void leer_precio_ventas()
{

    Ventas reg;
    int tam=0;
    tam=contarRegistrosVentas();
    Ventas *p;
    p=new Ventas[tam];
    if(p==NULL)
    {
        cout << "error de asignación. " << endl;
        system("pause");
        return;
    }
    int pos=0;
    while(reg.Leer_de_disco(pos)==true)
    {
        p[pos].set_codventa(reg.get_codventa());
        p[pos].set_importe_total(reg.get_importe_total());
        pos++;
    }
    ordenar_ventas(p,tam);

    for (int i=0; i<tam; i++)
    {
        pos=buscar_codventa(p[i].get_codventa());
        if(reg.Leer_de_disco(pos)==true)
        {
            if(reg.get_Activo()==true)
            {
                reg.mostrar();
                system("pause");
                leer_ventas_detalle(reg.get_codventa());
            }

        }

    }
    delete p;
}


void menu_ventas()
{

    int opc;
    while(true)
    {
        system("cls");
        cout<<"Menu Ventas"<<endl;
        cout<<"1. Alta"<<endl;
        cout<<"2. Baja"<<endl;
        cout<<"3. Modificación"<<endl;
        cout<<"4. Listado"<<endl;
        cout<<"5. Reportes"<<endl;
        cout<<"0. Atras"<<endl;
        cout<<"Ingrese la opción: "<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            alta_ventas();
            system("pause");
            break;
        case 2:
            baja_ventas();
            system("pause");
            break;
        case 3:
            Mod_ventas();
            break;
        case 4:
            bool b;
            b=leer_ventas();
            break;
        case 5:
            reportes_ventas();
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

void reportes_ventas(){
int opc;
    while(true)
    {
        system("cls");
        cout<<"Reportes Ventas"<<endl;
        cout<<"1. Por cod. de venta"<<endl;
        cout<<"2. Por dni de cliente"<<endl;
        cout<<"3. Por importe ascendiente"<<endl;
        cout<<"0. Atras"<<endl;
        cout<<"Ingrese la opción: "<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            busq_cod_ven();
            break;
        case 2:
            busq_dni_ventas();
            break;
        case 3:
            leer_precio_ventas();
            break;
        case 0:
            return ;
        default:
            cout<<"Opción incorrecta. Presione una tecla para continuar";
            system("pause>null");
            break;
        }
    }

}

#endif // VENTAS_H_INCLUDED
