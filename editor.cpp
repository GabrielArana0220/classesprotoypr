#include <iostream>
#include <math.h>
#include <string>
using namespace std;


class elemento
{
    string nombre;
public:
    elemento()
    {
        nombre = "Vacio";
    }
    elemento(string x)
    {
        nombre = x;
    }
    elemento( elemento &o)
    {
        nombre=o.getnombre();
    }
    void set_elemento(string x)
    {
        nombre =x;
    }
    string getnombre()
    {
        return nombre;
    }

};

class rama_elemental
{

    elemento *lista[10];
    int **tabla_debilidades;
    int numero;
public:
    rama_elemental(int x)
    {
        numero = x;
        for (int i = 0; i < numero; i++)
            lista[i] = new elemento;
        tabla_debilidades = new int *[numero];
        for(int i =0; i<x;i++)
            tabla_debilidades[i]=new int [numero];
        for(int l=0;l<numero;l++)
            for(int m=0; m<numero;m++)
                tabla_debilidades[l][m]= 1;

    }
    void set_element(string x, int y)
    {
        lista[y]->set_elemento(x);
    }
    void set_debilidad_fortaleza(string x, string y, string z)
    {
        bool validacion=false;
        for(int i = 0; i<numero; i++)
            if (x==lista[i]->getnombre())
                for(int j = 0; j<numero; j++)
                    if (y==lista[j]->getnombre())
                        for(int k = 0; k<numero; k++)
                            if (z==lista[k]->getnombre())
                                validacion = true;
        if (validacion==true)
            for(int i = 0; i<numero; i++)
                if (x==lista[i]->getnombre())
                    for(int j = 0; j<numero; j++)
                        if (y==lista[j]->getnombre())
                            for(int k = 0; k<numero; k++)
                                if (z==lista[k]->getnombre())
                                {
                                    for(int l=0;l<numero;l++)
                                        for(int m=0; m<numero;m++)
                                        {
                                            if (j==k){
                                                tabla_debilidades[i][j]=3;
                                                tabla_debilidades[j][i]=3;}
                                            else
                                            {
                                                tabla_debilidades[i][j]=2;
                                                tabla_debilidades[i][k]=0;
                                                tabla_debilidades[j][i]=0;
                                                tabla_debilidades[k][i]=2;

                                            }
                                        }
                                }
    }
    void mostrar_tabla()
    {
        for(int l=0;l<numero;l++){
            for(int m=0; m<numero;m++)
                cout << tabla_debilidades[l][m] << " ";
            cout << endl;
            }
    }
    elemento get_elemento(int x)
    {
        return *lista[x];
    }
    string get_nombre(int x)
    {
        return lista[x]->getnombre();
    }

};

class estadistica
{
    int valor;
    string nombre;
public:
    estadistica()
    {
        valor=0;
        nombre="VACIO";
    }
    estadistica(string x, int y)
    {
        valor = y;
        nombre = x;
    }
    estadistica(estadistica &o)
    {
        valor = o.get_valor();
        nombre = o.getnom();
    }
    int get_valor()
    {
        return valor;
    }
    string getnom()
    {
        return nombre;
    }
    int set_valor(int x)
    {
        valor = x;
    }
    int set_nombre(string x)
    {
        nombre = x;
    }
    int sumar_valor(int x)
    {
        valor +=x;
    }
};

class stats
{
    estadistica *S;
    int tamano;
public:
    stats()
    {
        tamano=7;
        S= new estadistica[tamano];
        for(int i = 0; i<tamano; i++){
            (S+i)->set_nombre("llenar");
            (S+i)->set_valor(10);
        }
    }
    stats(int x, string l[], int m[])
    {
        tamano = x;
        S= new estadistica[tamano];
        for(int i = 0; i<tamano; i++)
            *(S+i)= estadistica(l[i],m[i]);
    }
    stats( stats &o)
    {
        tamano = o.get_tamano();
        S= new estadistica[tamano];
        for(int i = 0; i<tamano; i++)
            *(S+i)= estadistica(o.get_stats_nombre(i),get_stats_valor(i));
    }
    int get_tamano()
    {
        return tamano;
    }
    int get_stats_valor(int x)
    {
        return (S+x)->get_valor();
    }
    string get_stats_nombre(int x)
    {
        return (S+x)->getnom();
    }
    void mostrar_stats()
    {
        for(int i =0;i<tamano;i++)
            cout << "ESTADISTICA " << i+1 << ":  "<<get_stats_nombre(i)<<" VALOR:  "<<get_stats_valor(i)<<endl;
    }
};

class nivel
{
    double nive;
    double experiencia;
    double exp_necesaria;
    double nivel_maximo;
    double constante;
public:
    nivel()
    {
        nive = 1;
        experiencia = 0;
        exp_necesaria = 10;
        nivel_maximo = 100;
        constante = 2.7818;
    }
    nivel (double x, double y, double z, double w, double i)
    {
        nive = x;
        experiencia = y;
        exp_necesaria = z;
        nivel_maximo = w;
        constante = i;
    }
    nivel ( nivel &o)
    {
        nive = o.getnivel();
        experiencia = o.getexp();
        exp_necesaria = o.getexpn();
        nivel_maximo = o.getnivel_max();
        constante = o.get_constante();
    }
    double getnivel()
    {
        return nive;
    }
    double getexp()
    {
        return experiencia;
    }
    double getexpn()
    {
        return exp_necesaria;
    }
    double getnivel_max()
    {
        return nivel_maximo;
    }
    double get_constante()
    {
        return constante;
    }
    void set_exnec()
    {
        exp_necesaria = pow(get_constante(),nive/10)*100;
    }
    void aumentar_exp(double x)
    {
        experiencia += x;
    }
    void subir_nivel()
    {
        experiencia = 0;
        nive++;
        set_exnec();
    }
    void sistema_de_validacion()
    {
        if (getexp()>=getexpn())
            subir_nivel();
    }

};

class estado
{
    string nombre;
    string codigo_efecto;
public:
    estado()
    {
        nombre = "Normal";
        codigo_efecto = "00000";
    }
    estado(estado &o)
    {
        nombre = o.getnombre();
        codigo_efecto = o.get_codigo();
    }
    estado (string x, string y)
    {
        nombre = x;
        codigo_efecto = y;
    }
    void setnombre(string x)
    {
        nombre = x;
    }
    void set_codigo(string x)
    {
        codigo_efecto = x;
    }
    string getnombre()
    {
        return nombre;
    }
    string get_codigo()
    {
        return codigo_efecto;
    }
};

class habilidad
{
    string nombre;
    int potencia;
    elemento elem;
    estado stad;
public:
    habilidad()
    {
        nombre = "INSERTE DATOS";
        potencia = 0;
    }
    habilidad(string x, int y, rama_elemental z, int zx, string r, string k)
    {
        nombre = x;
        potencia = y;
        elem.set_elemento(z.get_nombre(zx));
        stad.setnombre(r);
        stad.set_codigo(k);
    }
    string get_nombre()
    {
        return nombre;
    }
    int get_potencia()
    {
        return potencia;
    }
    string get_elemento()
    {
        return elem.getnombre();
    }
    string get_estado()
    {
        return stad.getnombre();
    }
    void set_nombre(string x)
    {
        nombre = x;
    }
    void set_potencia(int x)
    {
        potencia = x;
    }
    void set_elemento(rama_elemental x, int y)
    {
        elem.set_elemento(x.get_nombre(y));
    }
    void set_estado (estado x)
    {
        stad.setnombre(x.getnombre());
        stad.set_codigo(x.get_codigo());
    }
    void mostrar_datos()
    {
        cout << "Nombre: "<<get_nombre()<<endl;
        cout << "Potencia: "<<get_potencia()<<endl;
        cout << "Elemento: "<<get_elemento()<<endl;
        cout << "Estado: "<<get_estado()<<endl;
    }
};

class item
{
protected:
    string name;
    string description;
public:
    item()
    {
        name = "ITEM VACIO";
        description = "SIN DESCRIPCION";
    }
    item(string x, string y)
    {
        name = x;
        description = y;
    }
    string get_nombre()
    {
        return name;
    }
    string get_description()
    {
        return description;
    }
    void set_nombre(string x)
    {
        name = x;
    }
    void set_descripcion(string x)
    {
        description = x;
    }
};

class tipo_de_arma
{
    string tipo;
public:
    tipo_de_arma()
    {
        tipo = "ninguno, esto no es un arma";
    }
    tipo_de_arma(string x)
    {
        tipo = x;
    }
    void set_tipo(string x)
    {
        tipo = x;
    }
    string get_tipo()
    {
        return tipo;
    }
};

class weapon:item
{
    int tamano;
    string *stat_mejorado;
    int *aumento;
    elemento element;
    tipo_de_arma tip;
public:
    weapon(int x)
    {
        item();
        tip = tipo_de_arma();
        stat_mejorado = new string[x];
        aumento = new int[x];
        tamano = x;
        element=elemento();
    }
    weapon (string descr, string x, string y[],int f, int z[], string elem, tipo_de_arma typ)
    {
        set_nombre(x);
        set_descripcion(descr);
        tamano = f;
        stat_mejorado = new string[f];
        for(int i = 0; i < tamano; i++)
            stat_mejorado[i]=y[i];
        aumento = new int[f];
        for(int i = 0; i < tamano; i++)
            aumento[i]=z[i];
        element = elemento(elem);
        tip = tipo_de_arma(typ.get_tipo());
    }
    weapon (weapon &o)
    {
        tamano = o.get_tamano();
        item(o.nombre(),o.description());
        stat_mejorado = new string[tamano];
        for(int i = 0; i < tamano; i++)
            stat_mejorado[i]=o.get_stat_mejorado(i);
        aumento = new int[tamano];
        for(int i = 0; i < tamano; i++)
            aumento[i]=o.get_aumento(i);
        element = o.get_elemento();
    }
    string description()
    {
        return get_description();
    }
    int get_tamano()
    {
        return tamano;
    }
    string nombre()
    {
        return get_nombre();
    }
    string get_stat_mejorado(int x)
    {
        return stat_mejorado[x];
    }
    int get_aumento(int x)
    {
        return aumento[x];
    }
    string get_elemento()
    {
        return element.getnombre();
    }

    void set_stats_mejorador_plus_stat_(string x[], int y[])
    {
        for(int i = 0; i < tamano; i++)
            stat_mejorado[i]=x[i];
        for(int i = 0; i < tamano; i++)
            aumento[i]=y[i];
    }
    void set_elemento(elemento r)
    {
        element.set_elemento(r.getnombre());
    }
    void mostrar_datos()
    {
        cout << "NOMBRE DEL WEAPON:  " <<nombre()<<"\n\n\n"<<"DESCRIPCION:  "<<description()<<endl;
        cout << "STATS Y AUMENTOS Y/O DECREMENTOS:  "<<"\n\n";
        for(int i = 0; i < tamano; i++)
            cout << "STAT MODIFICADO:  "<<get_stat_mejorado(i) << "  MODIFICACION:   "<< get_aumento(i)<<endl;
        cout << "ELEMENTO  "<< get_elemento();
    }
    ~weapon()
    {}

};


class clase
{
    string nombre;
    int tam;
    habilidad *H[20];
    int *niveles_para_llegar[20];
    string beneficio_stats;
    string beneficio_armas;
public:
    clase(int x)
    {
        nombre = "vacio";
        tam = x;
        for(int i=0;i<tam;i++)
            H[i]=new habilidad;
        for(int j=0;j<tam;j++)
            niveles_para_llegar[j]=new int;
        beneficio_stats="0000000";
        beneficio_armas="xxxxxxx";
    }
    void nombrar(string x)
    {
        nombre = x;
    }
    void setear_stats(string x)
    {
        beneficio_stats = x;
    }
    void setear_armas(string x)
    {
        beneficio_armas = x;
    }
    void set_habilidades(int o, int niv,string x, int y, rama_elemental z, int zx, estado cf)
    {
        H[o]->set_nombre(x);
        H[o]->set_potencia(y);
        H[o]->set_elemento(z,zx);
        H[o]->set_estado(cf);
        *niveles_para_llegar[o]=niv;
    }
    habilidad gethab(int x)
    {
        return *H[x];
    }
    string getnom()
    {
        return nombre;
    }
    string getbenar()
    {
        return beneficio_armas;
    }
    string getbenst()
    {
        return beneficio_stats;
    }
    int getniv(int x)
    {
        return *niveles_para_llegar[x];
    }
    void mostrar_datos()
    {
        cout << "NOMBRE DE LA CLASE: "<<getnom()<< "\n\n\n";
        cout << "CODIGO DE VERIFICACION DE ARMAS: "<< getbenar() << "\n";
        cout << "CODIGO DE VERIFICACION DE STATS: "<< getbenst() << "\n";
        for (int i = 0; i < tam; i++){
            cout << "HABILIDAD: ";
            H[i]->mostrar_datos();
            cout<< "NIVEL NECESARIO: "<< getniv(i)<<"\n\n";
        }
    }

};



int main()
{
    rama_elemental rama(7);
    rama.set_element("fuego",0);
    rama.set_element("agua",1);
    rama.set_element("viento",2);
    rama.set_element("oscuridad",3);
    rama.set_element("rayo",4);
    rama.set_element("luz",5);
    rama.set_element("neutro",6);
    rama.set_debilidad_fortaleza("fuego","viento","agua");
    rama.set_debilidad_fortaleza("viento","rayo","fuego");
    rama.set_debilidad_fortaleza("rayo","agua","viento");
    rama.set_debilidad_fortaleza("luz","oscuridad","oscuridad");
    rama.set_debilidad_fortaleza("oscuridad","luz","luz");
    rama.mostrar_tabla();
    estado envenenado("veneno", "00001");
    estado normal;
    habilidad ataksin("ataque sin",100,rama,0,envenenado.getnombre(),envenenado.get_codigo());
    ataksin.mostrar_datos();
    habilidad nada;
    nada.mostrar_datos();
    cout << endl << endl;
    clase aprendiz(7);
    aprendiz.nombrar("aprendiz");
    aprendiz.setear_armas("aaaaaaa");
    aprendiz.setear_stats("5555555");
    aprendiz.set_habilidades(0,10,"libra",0,rama,6,normal);
    aprendiz.set_habilidades(1,20,"sablazo de luz",50,rama,5,normal);
    aprendiz.set_habilidades(2,30,"fuego envenenado",70,rama,0,envenenado);
    aprendiz.set_habilidades(3,40,"ataque de peso",80,rama,6,normal);
    aprendiz.set_habilidades(4,50,"desgarro",150,rama,6,normal);
    aprendiz.set_habilidades(5,60,"rayo",100,rama,4,normal);
    aprendiz.set_habilidades(6,90,"ataque final",200,rama,6,normal);
    aprendiz.mostrar_datos();
    string estad[7] = {"vida","puntos magia","ataque","defensa","ataque magico","defensa magica","velocidad"};
    int estadnom[7] = {100,100,100,100,100,100,100};
    stats r(7,estad,estadnom);
    r.mostrar_stats();
    string stts[2]={"ataque","velocidad"};
    int valores_stts[2]={10, -5};
    tipo_de_arma espada("espada");
    cout << "\n\n";
    weapon espada_corriente("una espada comun y corriente","espada corriente",stts,2,valores_stts, rama.get_nombre(6),espada);
    espada_corriente.mostrar_datos();

}

