#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED


class Persona
{
protected:
    char nombre[20];
    char apellido[20];
    int edad;
    int dni;
    char direccion[20];
    int nro_tel;
    bool activo;
public:
    void cargar();
    void mostrar();
    const char * get_nombre()
    {
        return nombre;
    }
    const char * get_apellido()
    {
        return apellido;
    }
    int get_edad()
    {
        return edad;
    }
    int get_dni()
    {
        return dni;
    }
    const char * get_direccion()
    {
        return direccion;
    }
    int get_nrotel()
    {
        return nro_tel;
    }
    bool get_activo()
    {
        return activo;
    }
    void set_nombre(const char *n)
    {
        strcpy(nombre,n);
    }
    void set_apellido(const char *a)
    {
        strcpy(apellido,a);
    }
    void set_edad(int e)
    {
        edad=e;
    }
    void set_dni(int i)
    {
        dni=i;
    }
    void set_direccion(const char *d)
    {
        strcpy(direccion,d);
    }
    void set_activo(bool j)
    {
        activo=j;
    }
    void set_Tel(int Tel)
    {

        nro_tel=Tel;
    }
    bool Grabar_en_disco();
    bool Leer_de_disco(int );
    bool Modificar_de_disco(int);

};

//****************
//DESARROLLO DE LOS METODOS

void Persona::cargar()
{
    system("cls");
    cout << "ingresar dni: " << endl;
    cin >> dni;
    cout << "ingresar nombre: " << endl;
    cargarCadena(nombre,19);
    cout << "ingresar apellido: " << endl;
    cargarCadena(apellido,19);
    cout << "ingresar edad:" << endl;
    cin >> edad;
    cout << "ingresar dirección: " << endl;
    cargarCadena(direccion,19);
    cout << "ingresar nro. tel: " << endl;
    cin >> nro_tel;
    activo=true;

}

void Persona::mostrar()
{
    system("cls");
    cout << "nombre: " << nombre << endl;
    cout << "apellido: " << apellido << endl;
    cout << "dni: " << dni << endl;
    cout << "edad:" << edad << endl;
    cout << "direccion: " << direccion << endl;
    cout << "nro. tel: " << nro_tel << endl;

}

//******************************************************
//FUNCIONES EXTERNAS


#endif // PERSONA_H_INCLUDED
