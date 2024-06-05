#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


typedef struct
{
    int idRegistro;
    int idpaci;
    int idesp;
    char apellido[20];
    char nombre[20]
    char fecha[20];
    char diagnostico[20];
    char especialiDAD[30];
    char nombreDoc[20];


} stRegistroMedico;




typedef struct // estructura paciente
{

    int idpaci;
    char nombre[25];
    char apellido[25];

} paciente;
typedef struct // estructura especialidad
{

    int idesp;
    char fecha[20];
    char diagnostico[20];
    char especialiDAD[30];
    char nombreDoc[20];


} especialidad;

typedef struct nodoPaci //nodo paciente
{

    paciente p;
    struct nodoPaci* sig;

} nodoPaci;


typedef struct nodoesp //nodo especialidad
{

    especialidad e;
    struct nodoesp* sig;

} nodoesp;


//********************************************************************
nodoPaci *iniclistipaci();
nodoPaci *crearNodoPaci(paciente pa);
nodoPaci *agregarPpioPaci(nodoPaci*lista,nodoPaci*nuevo);
nodoPaci *BuscaNodoPaci(nodoPaci *lista, int idPaciBuscado);
nodopaciEsp *iniclisespPaci();
nodopaciEsp *crearNodoEsp(especialidad esp);
nodopaciEsp *agregarPpioEsp(nodopaciEsp*lista,nodopaciEsp*nuevo);
//*********************************************************************
typedef struct   //estructura compuesta
{

    nodoPaci *listaPaci;
    struct nodoesp *sig;

} nodopaciEsp;


int main()
{
    printf("hola mundo de mierda");
    return 0;
}

//************************************************************************
nodoPaci *iniclistipaci()
{

    return NULL;
}

nodoPaci *crearNodoPaci(paciente pa)
{
    nodoPaci *aux=(nodoPaci*)malloc(sizeof(nodoPaci)):
                      aux->p=pa;
    aux->sig=NULL;
    return aux;
}

nodoPaci *agregarPpioPaci(nodoPaci*lista,nodoPaci*nuevo)
{
    if (lista == NULL)
    {

        nuevo=lista;
    }
    else
    {
        nuevo->sig=lista;
        lista=nuevo;
    }
    return lista;
}

nodoPaci *BuscaNodoPaci(nodoPaci *lista, int idPaciBuscado)
{

    nodoPaci *seg=iniclistipaci();

    if(lista)
    {
        seg=lista;
        while ((seg)&&(seg->p.idpaci==idPaciBuscado))
        {
            seg=seg->sig;

        }


    }
    return seg;
}
//***********************************************funciones estructura compuesta*************************************
nodopaciEsp *iniclisespPaci()
{

    return NULL;
}

nodopaciEsp *crearNodoEsp(especialidad esp)
{
    nodopaciEsp *aux=(nodopaciEsp*)malloc(sizeof(nodopaciEsp)):
                         aux->sig.e=esp;
    aux->sig.sig=NULL;
    return aux;
}

nodopaciEsp *agregarPpioEsp(nodopaciEsp*lista,nodopaciEsp*nuevo)
{
    if (lista == NULL)
    {

        nuevo=lista;
    }
    else
    {
        nuevo->sig=lista;
        lista=nuevo;
    }
    return lista;
}

void pasaArchiToListacomp(char nombreArchi[],nodopaciEsp*lista)
{
    stRegistroMedico r;


    FILE *archi=fopen("nombreArchi","rb"); //abre el archivo
    if(archi)
    {
        while(fread(r,sizeof(stRegistroMedico),archi)>0)  //lo leo
        {
            nodopaciEsp *aux;
            nodoPaci * encontrada=BuscaNodoPaci(lista->listaPaci,r.idpaci); //busco si esta el paciente en lista cabecera
            if(encontrada)
            {
                nodopaciEsp*aux->listaPaci=iniclistipaci();
                strcpy(aux->p.nombre,r.nombre);
                strcpy(aux->p.apellido,r.apellido);     //agrega los datos a la cabecera
                strcpy(aux->sig.e.diagnostico,r.diagnostico);
                strcpy(aux->sig.e.especialiDAD,r.especialiDAD);
                strcpy(aux->sig.e.fecha,r.fecha);
                aux->sig.e.idesp=r.idesp;
                strcpy(aux->sig.e.nombreDoc,r.nombreDoc);// agrega los datos a la lista secundaria
            }
            else()                                        // si no la encuentra crea nodo compuesto y la agrega al principio
            {
                nodopaciEsp *nuevo=crearNodoEsp(r);
                lista=agregarPpioEsp(lista,nuevo);
            }
        }

    }
