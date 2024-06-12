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
    char nombre[20];
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

typedef struct // estructura especialidad paciente
{

    int idesp;
    char fecha[20];
    char diagnostico[20];
    char especialiDAD[30];
    char nombreDoc[20];
    int idpaci;
    char nombre[25];
    char apellido[25];

} especialidadPaciente;

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
typedef struct   //estructura compuesta
{

    nodoesp *listaesp;
    struct nodoPaci *sig;

} nodoespaci;

//********************************************************************
nodoPaci *iniclistipaci();
nodoPaci *crearNodoPaci(paciente pa);
nodoPaci *agregarPpioPaci(nodoPaci*lista,nodoPaci*nuevo);
nodoPaci *BuscaNodoPaci(nodoPaci *lista, int idPaciBuscado);
nodoespaci *iniclisespPaci();
nodoespaci *crearNodoespaci(especialidadPaciente exp);
nodoespaci *agregarPpioEsp(nodoespaci*lista,nodoespaci*nuevo);
nodoespaci *BuscaNodoEsp(nodoPaci *lista, int idespBuscado);
void pasaArchiToListacomp(char nombreArchi[],nodoespaci*lista);
nodoespaci *crearNodoespaci( especialidadPaciente exp);
void muestraUnespPaci(nodoespaci *n);
void muestralistaEspPaci(nodoespaci *lista);
nodoespaci *carga1NodoCompuesto();
void cargaListaManual(nodoespaci *lista);
nodoespaci *BuscaNodoPaciApe(nodoPaci *lista, char apell[],char name[]);
int BuscaPaci(nodoespaci*lista,char nombre[], char apellido[]);
//*********************************************************************
// *********************{ el Main }***********************************


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
    nodoPaci *aux = (nodoPaci*)malloc(sizeof(nodoPaci));
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
nodoespaci *iniclisespPaci()
{

    return NULL;
}

nodoespaci *crearNodoespaci( especialidadPaciente exp)
{
    nodoespaci *aux=(nodoespaci*)malloc(sizeof(nodoespaci));
    strcpy(aux->listaesp->e.diagnostico,exp.diagnostico);
    strcpy(aux->listaesp->e.especialiDAD,exp.especialiDAD);
    strcpy(aux->listaesp->e.fecha,exp.fecha);
    strcpy(aux->listaesp->e.nombreDoc,exp.nombreDoc);
    //****************cargo lista secundaria****************************
    strcpy(aux->sig->p.nombre,exp.nombre);
    strcpy(aux->sig->p.apellido,exp.apellido);
    aux->sig->p.idpaci=exp.idpaci;
    aux->listaesp->sig=NULL;
    aux->sig->sig=NULL;
    return aux;
}

nodoespaci *agregarPpioEsp(nodoespaci*lista,nodoespaci*nuevo)
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

nodoespaci *BuscaNodoEsp(nodoPaci *lista, int idespBuscado)
{

    nodoespaci *seg=iniclisespPaci();

    if(lista)
    {
        seg=lista;
        while ((seg)&&(seg->listaesp->e.idesp==idespBuscado))
        {
            seg=seg->sig;

        }


    }
    return seg;
}
//punto 2

void pasaArchiToListacomp(char nombreArchi[],nodoespaci*lista)
{
    stRegistroMedico r;


    FILE *archi=fopen("nombreArchi","rb"); //abre el archivo
    if(archi)
    {
        while(fread(&r,sizeof(stRegistroMedico),1,archi)>0)  //lo leo
        {
            nodoespaci *aux;
            nodoespaci * encontrada=BuscaNodoPaci(lista->listaesp->e.idesp,r.idesp); //busco si el id esp esta
            if(encontrada)
            {
                aux->listaesp->e.idesp=r.idesp;
                strcpy(aux->listaesp->e.diagnostico,r.diagnostico);
                strcpy(aux->listaesp->e.especialiDAD,r.especialiDAD);
                strcpy(aux->listaesp->e.fecha,r.fecha);
                strcpy(aux->listaesp->e.nombreDoc,r.nombreDoc);
                //****************cargo lista secundaria****************************
                strcpy(aux->sig->p.nombre,r.nombre);
                strcpy(aux->sig->p.apellido,r.apellido);
                aux->sig->p.idpaci=r.idpaci;

            }
            else                                       // si no la encuentra crea nodo compuesto y la agrega al principio
            {
                especialidadPaciente esp;
                r.idesp=esp.idesp;
                strcpy(esp.diagnostico,r.diagnostico);
                strcpy(esp.especialiDAD,r.especialiDAD);
                strcpy(esp.fecha,r.fecha);
                strcpy(esp.nombreDoc,r.nombreDoc);
                strcpy(esp.nombre,r.nombre);
                strcpy(esp.apellido,r.apellido);
                r.idpaci=esp.idpaci;


                nodoespaci *nuevo=crearNodoespaci(esp);

                lista=agregarPpioEsp(lista,nuevo);
            }
        }
        fclose(archi);

    }

//punto 3

    void muestraUnespPaci(nodoespaci *n)
    {

        printf("isesp :.....",n->listaesp->e.idesp);
        printf("diagnostico :.....",n->listaesp->e.diagnostico);
        printf("fecha :.....",n->listaesp->e.fecha);
        printf("nombre doctor :.....",n->listaesp->e.nombreDoc);
        printf("nombre paciente :.....",n->sig->p.nombre);
        printf("apellido paciente :.....",n->sig->p.apellido);
        printf("idPaciente :.....",n->sig->p.idpaci);

    }

    void muestralistaEspPaci(nodoespaci *lista)
    {
        nodoespaci *seg=iniclisespPaci();
        seg=lista;
        while(seg)
        {
            muestraUnespPaci(seg);
            seg=seg->sig;
        }

    }
}

//punto 4



nodoespaci *carga1NodoCompuesto()
{
    especialidadPaciente e;
    nodoespaci *n=iniclisespPaci();

    printf(" ingrese el isesp :.....");
    scanf("%i",e.idesp);
    printf("diagnostico :.....");
    scanf("%s",e.diagnostico);
    printf("fecha :...........");
    scanf("%s",e.fecha);
    printf("nombre doctor :.....");
    scanf("%s",e.nombreDoc);
    printf("nombre paciente :.....");
    scanf("%s",e.nombre);
    printf("apellido paciente :.....");
    scanf("%s",e.apellido);
    printf("idPaciente :.....");
    scanf("%i",e.idpaci);
    n=crearNodoespaci(e);
    return n;
}

void cargaListaManual(nodoespaci *lista)
{
    char flag='s';
    printf("ingrese los datos con 's'  para la carga"); //preguntar si es la que va

    while(flag=='s')
    {
        nodoespaci *encontrado=iniclisespPaci();

        nodoespaci *aux=iniclisespPaci();

        aux=carga1NodoCompuesto();
        if(encontrado=BuscaNodoEsp(lista,aux->listaesp->e.idesp)==NULL)
        {
            lista=agregarPpioEsp(lista,aux);
        }
        else
        {
            printf("la especialidad ya existe");

        }

        printf("ingresa mas datos ....ingrese 's'");
        scanf("%c",flag);
        flag=getchar();
    }


}

//punto 5

nodoespaci *BuscaNodoPaciApe(nodoPaci *lista, char apell[],char name[])
{

    nodoespaci *seg=iniclistipaci();

    if(lista)
    {
        seg=lista;
        while ((seg)&&(strcmp(seg->sig->p.apellido,apell)==0)&&(strcmp(seg->sig->p.nombre,name)==0))
        {
            seg=seg->sig;

        }


    }
    return seg;
}

int BuscaPaci(nodoespaci*lista,char nombre[], char apellido[])
{
    int flag=0;
    nodoespaci *aux=iniclisespPaci();
    aux=BuscaNodoPaciApe(lista,nombre,apellido);
    if(aux)
    {

        flag=1;
    }

    return flag;
}

//punto 6

//preguntar como hacer.........



//punto 7

void carga1nodoToArchi( nodoespaci *lista, char nombreArchi[], char especiLidad[])
{
    stRegistroMedico r;
    FILE *archi=fopen("nombreArchi","ab");
    if(archi)
    {
        nodoespaci*seg;

        seg=lista;

        while ((seg)&&(strcmp(lista->listaesp->e.especialiDAD,especiLidad)==0))
        {
            strcpy(r.diagnostico,seg->listaesp->e.diagnostico);
            strcpy(r.especialiDAD, seg->listaesp->e.especialiDAD);
            r.idesp=seg->listaesp->e.idesp;
            strcpy(r.fecha, seg->listaesp->e.fecha);
            strcpy(r.nombreDoc, seg->listaesp->e.nombreDoc);
            strcpy(r.nombre, seg->sig->p.nombre);
            strcpy(r.apellido, seg->sig->p.apellido);
            r.idpaci=seg->sig->p.idpaci;


            fwrite(&r,sizeof(stRegistroMedico),1,archi);



            seg=seg->listaesp->sig;
        }
    }
    fclose(archi);


}





