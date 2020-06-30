#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

class Cliente:public persona
{

private:
    char email[30];
    bool activo;
public:
    void cargar();
    void mostrar();
    char * get_email(){return email;}
    bool get_activo(){return activo;}
    void set_email(const char *e){strcpy(email,e);}
    void set_activo(bool a){activo=a;}

};

#endif // CLIENTE_H_INCLUDED
