#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED
////Cargar cadena
void cargarCadena(char *pal, int tam)
{

    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n')
            break;
    }
    pal[i]='\0';
    fflush(stdin);

};
////

void menu_reportes();
///////////////// ARTICULO /////////////////
void alta_articulo();
void bajaLogica();
void listado_por_codart();
bool leer_art();
int buscar_art(int );
void menu_articulos();
int contarRegistrosArticulo();
void reportes_art();
int buscar_art_nombre(const char *);
float calcular_importe(int ,int);


void Modificasion_art();
void art_nombre();
void art_precio();
void art_stok();
///////////////// CLIENTE /////////////////
void alta_cliente();
void baja_cliente();
bool leer_clientes();
int buscar_dni(int );
void menu_clientes();
int contarRegistrosCliente();
void reportes_cli();
void busq_dni_cli();


void Mod_cliente();
void cli_Nom();
void cli_Ape();
void cli_Direc();
void cli_Tel();
void cli_Edad();
void cli_Dni();
void cli_gmail();

///////////////// VENTAS DETALLE /////////////////
void alta_ventas_detalle();
int buscar_codventa_ventasdetalle(int);
void leer_ventas_detalle(int);
void menu_ventas_detalle();
int buscar_art_ventasdetalle(int,int);
bool baja_ventasdetalle(int);
int autonumerico_codventa();
bool calcular_stock(int,int);

void Mod_ventas_detalles();
void ven_de_cantidad();
void ven_de_imp();
void ven_de_fecha();

///////////////// VENTAS /////////////////
int buscar_codventa(int );
void baja_ventas();
void alta_ventas();
bool leer_ventas();
void menu_ventas();
void reportes_ventas();
void busq_dni_ventas();
int contarRegistrosVentas();

void leer_precio_ventas();

void Mod_ventas();
void ven_emp();
void ven_cli();
void ven_fecha();
int comprobar_fecha(int dia,int mes,int anio);
///////////////// EMPLEADO /////////////////
void alta_empleado();
bool leer_empleado();
int buscar_empleado(int );
void baja_empleado();
int buscar_dni_empleado(int );
void menu_empleado();
void reportes_empleado();
int contarRegistrosEmpleado();

void Mod_empleado();
void emp_Nom();
void emp_Ape();
void emp_Direc();
void emp_Tel();
void emp_Edad();
void emp_Dni();
void emp_Sueldo();
///////////////// REPARACIONES /////////////////
bool leer_reparaciones();
void baja_reparaciones();
void alta_reparaciones();
int buscar_dni_reparaciones(int );
void menu_reparaciones();
void reportes_reparaciones();
void busq_dni_rep();
void busq_fecha_rep();


void Mod_reparaciones();
void rep_Precio();
void rep_Dni_cli();
void rep_fecha();



/*void ordenarvector(){
    Articulo reg;
    int pos=0,cant=0;
    while(reg.Leer_de_disco(pos)==true){
        cant++;
        pos++;
    }
    Articulo *v;
    v=new Articulo[cant];
    if(p==NULL) return;
    int i;
    for (i=0;i<cant;i++){
       v[i].Leer_de_disco(i);///PQ ESTO COPIA EL ARCHIVO EN EL VECTOR?
    }
    ///ordenar vector.
    for (i=0;i<cant;i++){
        v[i].mostrar();
    }
    delete v;

}*/


#endif // PROTOTIPOS_H_INCLUDED
