#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED
class Ventas
{
private:
    int cod_venta;
    int precio;
    int dni_empleado;
    int dni_cliente;
    int cod_articulos;///podriamos hacerlo auto numerico
    bool activo;
public:
    void cargar();
    void mostrar();
    void set_Precio(int n){precio=n;}
    void set_Stock(int n){stock=n;}
    void set_activo(bool f1){activo=f1;}
    int get_Precio(){return precio;}
    bool get_Activo(){return activo;}
    int get_Stock(){return stock;}
    void añadir_art();
};

class Ventas_detalle
{

private:
    int cod_venta;
    int cod_articulo;
    int cantidad;
    int precio;
    bool activo;
public:
    void cargar();
    void mostrar();
    int get_codventa(){return cod_venta;}
    int get_codarticulo(){return cod_articulo;}
    int get_cantidad(){return cantidad;}
    int get_precio(){return precio;}
    bool get_activo(){return activo;}
    void set_codventa(int c){cod_venta=c;}
    void set_articulo(int art){cod_articulo=art;}
    void set_cantidad(int ca){cantidad=ca;}
    void set_precio(int p){precio=p;}
    void set_activo(bool b){activo=b;}

};


class Reparaciones
{
private:
    int dni_cliente;
    int precio;
    Fecha fecha_ingreso;
    int fecha_retiro;
public:
    void cargar();
    void mostrar();
    int get_dnicliente(){return dni_cliente;}
    int get_precio(){return precio;}
    Fecha get_fechaingreso(){return fecha_ingreso;}
    Fecha get_fecharetiro(){return fecha_retiro;}
    int get_fecharetiro(){return fecha_retiro;}
    void set_dnicliente(int d){dni_cliente=d;}
    void set_precio(int p){precio=p;}
    void set_fechaingreso(Fecha fi){fecha_ingreso=fi;}
    void set_fecharetiro(Fecha fr){fecha_retiro=fr;}
    void set_dnicliente(int d){dni_cliente=d;}
};

class Persona
{
private:
        char nombre[20];
        char apellido[20];
        int edad;
        int dni;
        char direccion[20];
        char localidad[20];
        int nro_tel;
        bool activo;
public:
       void cargar();
       void mostrar();
       const char * get_nombre() {return nombre;}
       const char * get_apellido() {return apellido;}
       int get_edad() {return edad;}
       int get_dni(){return dni;}
       const char * () {return direccion;}
       const char * () {return localidad;}
       int get_nrotel() {return nro_tel;}
       bool get_activo() {return activo;}
       void set_nombre(const char *n) {strcpy(nombre,n);}
       void set_apellido(const char *a) {strcpy(apellido,a);}
       void set_edad(int e) {edad=e;}
       void set_dni(int i){dni=i;}
       void set_direccion(const char *d) {strcpy(direccion,d);}
       void set_localidad(const char *l) {strcpy(localidad,l);}
       int leer_de_disco(int);
};

class Empleado:public Persona
{
private:
    int sueldo;
    Fecha fecha_ingreso;

};




class Articulo
{
private:
    int nroart;
    char nombre[20];
    int precio;
    int stock;
    bool activo;
public:
       void cargar();
       void mostrar();
       int get_nroart(){return nroart;}
       int get_precio(){return precio;}
       int get_stock(){return stock;}
       bool get_activo(){return activo;}
       void set_nroart(int art){nroart=art;}
       void set_precio(int p){precio=p;}
       void set_stock(int s){stock=s;}
       void set_activo(bool a){activo=a;}
};



#endif // CLASES_H_INCLUDED
