#ifndef VENTAS_DETALLE_H_INCLUDED
#define VENTAS_DETALLE_H_INCLUDED


class Ventas_detalle
{

private:
    int cod_venta;
    int nroart;
    int cantidad;
    float importe;
    bool activo;
public:
    float cargar(int);
    void mostrar();
    int get_codventa()
    {
        return cod_venta;
    }
    int get_nroart()
    {
        return nroart;
    }
    int get_cantidad()
    {
        return cantidad;
    }
    float get_importe()
    {
        return importe;
    }
    bool get_activo()
    {
        return activo;
    }
    void set_codventa(int c)
    {
        cod_venta=c;
    }
    bool set_nroart(int art)
    {
        Articulo reg;
        if(buscar_art(art)!=-1){
        nroart=art;
        return true;
        }
        else{
            return false;
        }
    }
    bool set_cantidad(int ca)
    {
        if(ca>0){
        cantidad=ca;
        return true;
        }
        else{
            return false;
        }
    }
    void set_importe(float p)
    {
        if(p>0){
        importe=p;
        }
    }
    void set_activo(bool b)
    {
        activo=b;
    }
    bool Modificar_de_disco(int);
    bool Grabar_en_disco();
    bool Leer_de_disco(int);

};



bool calcular_stock(int cantidad, int nroart){
    Articulo reg;
    int pos;
    pos=buscar_art(nroart);
    if(reg.Leer_de_disco(pos)==true){
        if(reg.get_stock()>=cantidad){
            reg.set_restarstock(cantidad);
            if(reg.Modificar_de_disco(pos)==true){
            return true;
            }
        }
        else{
            cout << "no hay suficiente stock " << endl;
            system("pause");
            return false;
        }
    }else{
    cout<<"Erro al leer"<<endl;
    return false;
    }

}



float Ventas_detalle::cargar(int autonumerico)
{
    system("cls");
    int nroart,cantidad;
    float importe;
    cod_venta=autonumerico;
    cout << "ingresar nro. articulo: " << endl;
        cin >> nroart;
        if(set_nroart(nroart)==true){
            cout << "ingresar cantidad: " << endl;
            cin >> cantidad;
            if(set_cantidad(cantidad)==true){
                importe=calcular_importe(nroart,cantidad);
                if(calcular_stock(cantidad,nroart)==true){
                      set_importe(importe);
                      set_activo(true);
                      //if(Grabar_de_disco()==true){
                      return importe;
                      //}
                }
                else{
                return -1;
                }

            }
            else{
                cout << "cantidad incorrecta. " << endl;
                system("pause");
                return -1;
            }
        }
        else{
            cout << "no existe el articulo ." << endl;
            system("pause");
            return -1;
        }

}



void Ventas_detalle::mostrar()
{
    system("cls");
    cout << "cod. venta: " << cod_venta << endl;
    cout << "nro articulo: " << nroart << endl;
    cout << "cantidad: " << cantidad << endl;
    cout << "importe: " << importe << endl;


}


bool Ventas_detalle::Modificar_de_disco(int pos)
{
    bool listo;
    FILE *p;
    p=fopen("ventasdetalle.dat","rb+");
    if(p==NULL)
    return false;
    fseek(p,sizeof (Ventas_detalle)*pos,0);
    listo=fwrite(this,sizeof (Ventas_detalle),1,p);
    fclose(p);
    return listo;
}



bool Ventas_detalle::Grabar_en_disco()
{
    FILE *p;
    p=fopen("ventasdetalle.dat","ab");
    if(p==NULL)
        return false;
    bool escribio=fwrite(this,sizeof (Ventas_detalle),1,p);
    fclose(p);
    return escribio;
}

bool Ventas_detalle::Leer_de_disco(int pos)
{
    Ventas_detalle reg;
    FILE *p;
    p=fopen("ventasdetalle.dat","rb");
    if(p==NULL)
        return false;
    fseek(p,sizeof (Ventas_detalle)*pos,0);
    bool leyo=fread(this,sizeof (Ventas_detalle),1,p); ///tambien puede ser sizeof *this (peso de lo que apunta el puntero).
    fclose(p);
    return leyo;
}



//******************************************************
//FUNCIONES EXTERNAS


bool baja_ventasdetalle(int codventa) //busca que exista dicho "codventa" en vd y borra todos con este.
{
    int pos;
    Ventas_detalle reg;
    pos=buscar_codventa_ventasdetalle(codventa);
    if(pos==-1)
    {
        cout << "no se encuentra el cod. venta en el archivo ventas" << endl;
        system("pause");
        return false;
    }
    else{
        pos=0;
        while(reg.Leer_de_disco(pos)==true){
            if(reg.get_codventa()==codventa){
                reg.set_activo(false);
                if(reg.Modificar_de_disco(pos)==false){
                    cout << "no se pudo dar de baja. " << endl;
                    system("pause");
                    return false;
                }

            }
        pos++;
        }

    }
    return true;
}



int buscar_codventa_ventasdetalle(int codventa)
{
    int pos=0;
    Ventas_detalle reg;
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


int buscar_art_ventasdetalle(int codventa,int nroart)
{
    int pos=0;
    Ventas_detalle reg;
    while(reg.Leer_de_disco(pos)==true)
    {
        if(reg.get_codventa()==codventa)
        {
            if(reg.get_nroart()==nroart){
                return pos;
            }
        }
        pos++;

    }
    return -1;
}



void leer_ventas_detalle(int codventa)
{
    Ventas_detalle reg;
    int pos=0;
    while(reg.Leer_de_disco(pos)==true)
    {
        if(reg.get_codventa()==codventa){
             if(reg.get_activo()==true)
             {
                  reg.mostrar();
                  system("pause");
             }
        }

        pos++;
    }

}




#endif // VENTAS_DETALLE_H_INCLUDED
