#include <stdio.h>
#include <string.h>
//Crear la estructura
typedef struct{
    int codigo,edad;
    float promedio;
    char nombre[50],carrera[20],email[25];
}Alumnos;

int CantidadDeAlumnosMax;
int CantidadDeAlumnosRegistrados = 0;

//Capturar los datos del estudiante
void registrar(Alumnos *alumno){
    int validador;
    if(CantidadDeAlumnosRegistrados < CantidadDeAlumnosMax){
        //Limpiar Pantalla
        system("cls");
        //Pedir y asignar datos a las variables
        printf("REGISTRAR ALUMNO\n");
        fflush(stdin);
        do{
            validador = 1;
            system("cls");
            printf("\nIngrese el codigo del Alumno: ");
            scanf("%d",&alumno[CantidadDeAlumnosRegistrados].codigo);
            if (alumno[CantidadDeAlumnosRegistrados].codigo > 0){
                for(int indice = 0;indice < CantidadDeAlumnosRegistrados;indice++){
                    if(alumno[indice].codigo == alumno[CantidadDeAlumnosRegistrados].codigo){
                        printf("Usted ya ha registrado a este alumno");
                        validador = 0;
                    }
                }
            }else{
                printf("\nDebe introducir un numero entero positivo\n");
                system("pause");
                validador = 0;
            }
        }while(validador == 0);
        printf("\nIngrese el nombre del Alumno: ");
        fflush(stdin);
        gets(alumno[CantidadDeAlumnosRegistrados].nombre);
        do{
            validador = 1;
            printf("\nIngrese el Email del Alumno: ");
            fflush(stdin);
            scanf("%s",&alumno[CantidadDeAlumnosRegistrados].email);
            for(int indice = 0;indice < CantidadDeAlumnosRegistrados;indice++)
                if(strcmp(alumno[indice].email,alumno[CantidadDeAlumnosRegistrados].email) == 0)
                    validador = 0;
        }while(validador == 0);
        fflush(stdin);
        printf("\nIngrese la carrera que cursa el Alumno: ");
        gets(alumno[CantidadDeAlumnosRegistrados].carrera);
        fflush(stdin);
        do{
            printf("\nIngrese el promedio del Alumno: ");
            scanf("%f",&alumno[CantidadDeAlumnosRegistrados].promedio);
        }while(alumno[CantidadDeAlumnosRegistrados].promedio < 60 || alumno[CantidadDeAlumnosRegistrados].promedio > 100);
        do{
            printf("\nIngrese la edad del Alumno: ");
            scanf("%d",&alumno[CantidadDeAlumnosRegistrados].edad);
        }while(alumno[CantidadDeAlumnosRegistrados].edad < 12 || alumno[CantidadDeAlumnosRegistrados].edad > 60);
    }else{
        system("cls");
        printf("\nCantidad Maxima de alumnos superada\n");
        system("pause");
        return 0;
        }

    CantidadDeAlumnosRegistrados++;
}

//Mostrar todos los alumnos
void MostrarTodosLosAlumnos(Alumnos *alumno){
    if(CantidadDeAlumnosRegistrados > 0){
        //Limpiar Pantalla
        system("cls");
        printf("MOSTRAR TODOS LOS ALUMNOS REGISTRADOS\n");
        for(int contador = 0; contador<CantidadDeAlumnosRegistrados; contador++){
            //IMPRIMIR TODAS LAS VARIABLES EXISTENTES
            printf("\nALUMNO: %s",alumno[contador].nombre);
            printf("\nEdad: %i\n",alumno[contador].edad);
            printf("\nCODIGO: %i",alumno[contador].codigo);
            printf("\nCARRERA: %s",alumno[contador].carrera);
            printf("\nEMAIL: %s",alumno[contador].email);
            printf("\nPROMEDIO: %.2f\n",alumno[contador].promedio);
            printf("---------------------\n");

        }
        system("pause");
    }else{
        system("cls");
        printf("\nUsted no tiene alumnos registrados\n");
        system("pause");
        return 0;
        }
}

//Mostrar los datos de un estudiante
int MostrarUnAlumno(Alumnos *alumno){
    int opcion,codigoDelAlumno = 0;
    char emailDelAlumno[20] = "no encontrado";
    fflush(stdin);
     if(CantidadDeAlumnosRegistrados > 0){
        system("cls");
        opcion = maneraDeEncontrarUnAlumno();
        system("cls");
        switch(opcion){
            case 1: printf("Dame su email: ");
                    scanf("%s",emailDelAlumno);
                    for(int indice = 0; indice < CantidadDeAlumnosRegistrados;indice++)
                      if(strcmp(emailDelAlumno,alumno[indice].email) == 0){
                        printf("\nALUMNO: %s\n",alumno[indice].nombre);
                        printf("\nCODIGO: %i\n",alumno[indice].codigo);
                        printf("\nCARRERA: %s\n",alumno[indice].carrera);
                        printf("\nEMAIL: %s\n",alumno[indice].email);
                        printf("\nPROMEDIO: %.2f\n",alumno[indice].promedio);
                        printf("\nEdad: %i\n\n",alumno[indice].edad);
                        fflush(stdin);
                        system("pause");
                        return indice;
                      }
                    break;
            case 2: printf("Dame el c%cdigo: ",162);
                    fflush(stdin);
                    scanf("%d",&codigoDelAlumno);
                    for(int indice = 0; indice < CantidadDeAlumnosRegistrados;indice++)
                      if(codigoDelAlumno == alumno[indice].codigo){
                        printf("\nALUMNO: %s\n",alumno[indice].nombre);
                        printf("\nCODIGO: %i\n",alumno[indice].codigo);
                        printf("\nCARRERA: %s\n",alumno[indice].carrera);
                        printf("\nEMAIL: %s\n",alumno[indice].email);
                        printf("\nPROMEDIO: %.2f\n",alumno[indice].promedio);
                        printf("\nEdad: %i\n\n",alumno[indice].edad);
                        fflush(stdin);
                        system("pause");
                        return indice;
                      }
                    system("cls");
                    printf("No se encontro al alumno\n");
                    system("pause");
                    fflush(stdin);
                      return -1;
                      break;
        }
        if(codigoDelAlumno == 0 && strcmp(emailDelAlumno,"no encontrado")){
          system("cls");
          printf("No se encontro al alumno\n");
          system("pause");
          fflush(stdin);
          return -1;
        }
    }else{
        system("cls");
        printf("\nUsted no tiene alumnos registrados\n");
        system("pause");
        return 0;
        }
}
//Eliminar algun estudiante
void EliminarUnAlumno(Alumnos *alumno){
    int opcion,codigoDelAlumno = 0;
    char emailDelAlumno[20] = "no encontrado";
    fflush(stdin);
    system("cls");
     if(CantidadDeAlumnosRegistrados > 0){
        opcion = maneraDeEncontrarUnAlumno();
        system("cls");
        switch(opcion){
          case 1: printf("Dame su email: ");
                  scanf("%s",emailDelAlumno);
                  for(int indice = 0; indice < CantidadDeAlumnosRegistrados;indice++)
                    if(strcmp(emailDelAlumno,alumno[indice].email) == 0){
                      alumno[indice] = alumno[CantidadDeAlumnosRegistrados-1];
                      CantidadDeAlumnosRegistrados--;
                      printf("Eliminado\n");
                      system("pause");
                    }else{
                      system("cls");
                      printf("No se encontro al alumno\n");
                      system("pause");
                      fflush(stdin);
                    }
                  break;
          case 2: printf("Dame el c%cdigo: ",162);
                  fflush(stdin);
                  scanf("%d",&codigoDelAlumno);
                  for(int indice = 0; indice < CantidadDeAlumnosRegistrados;indice++)
                    if(codigoDelAlumno == alumno[indice].codigo){
                      alumno[indice] = alumno[CantidadDeAlumnosRegistrados-1];
                      CantidadDeAlumnosRegistrados--;
                      printf("Eliminado\n");
                      system("pause");
                    }else{
                      system("cls");
                      printf("No se encontro al alumno\n");
                      system("pause");
                      fflush(stdin);
                    }
                    break;
        }
        if(codigoDelAlumno == 0 && strcmp(emailDelAlumno,"no encontrado") == 0){
          system("cls");
          printf("No se encontro al alumno\n");
          system("pause");
          fflush(stdin);
        }
     }else{
        system("cls");
        printf("\nUsted no tiene alumnos registrados\n");
        system("pause");
        return 0;
        }
}

//Editar los datos o el dato de un estudiante
void EditarUnAlumno(Alumnos *alumno){
    int opcion;
    if(CantidadDeAlumnosRegistrados > 0){
        printf("Alumno Encontrado:\n");
        int indexAlumnoEncontrado = MostrarUnAlumno(alumno);
        if(indexAlumnoEncontrado != -1){
            printf("\n\nQue quieres editar?\n");
            printf("1) Nombre\n");
            printf("2) C%cdigo\n",162);
            printf("3) Carrera\n");
            printf("4) Email\n");
            printf("5) Promedio\n");
            printf("6) Salir\n");
            scanf("%d",&opcion);
            switch(opcion){
                case 1:
                    printf("\n\nEditar Nombre\n");
                    printf("\nIngrese el nuevo nombre del Alumno: ");
                    scanf("%s",alumno[indexAlumnoEncontrado].nombre);
                    fflush(stdin);
                    break;
                case 2:
                    printf("\n\nEditar Codigo\n");
                    printf("\nIngrese el nuevo codigo del Alumno: ");
                    scanf("%d",&alumno[indexAlumnoEncontrado].codigo);
                    fflush(stdin);
                    break;
                case 3:
                    printf("\n\nEditar Carrera\n");
                    printf("\nIngrese la nueva carrera que cursa el Alumno: ");
                    scanf("%s",alumno[indexAlumnoEncontrado].carrera);
                    fflush(stdin);
                    break;
                case 4:
                    printf("\n\nEditar Email\n");
                    printf("\nIngrese el nuevo Email del Alumno: ");
                    scanf("%s",alumno[indexAlumnoEncontrado].email);
                    fflush(stdin);
                    break;
                case 5:
                    printf("\n\nEditar Promedio\n");
                    printf("\nIngrese el promedio del Alumno: ");
                    scanf("%f",&alumno[indexAlumnoEncontrado].promedio);
                    break;
                case 6:
                    indexAlumnoEncontrado = -1;
                    break;
                default:
                  printf("Escogi%c una opci%cn no v%clida",162,162,160);
                    break;

            }
        }
    }else{
        system("cls");
        printf("\nUsted no tiene alumnos registrados\n");
        system("pause");
        return 0;
        }
}

int maneraDeEncontrarUnAlumno(){
    int opcion = 0;
    char datoDelAlumno[30];
    while(opcion <1 || opcion >3){
        printf("1) Email\n");
        printf("2) C%cdigo\n\n",162);
        scanf("%d",&opcion);
    }
    return opcion;
}

//Funcion principal
int main (){
    int opcionSeleccionada;
    int CantidadDeAlumnosRegistrados;
    int CodigoBuscado;
    int CantidadValida = 1;
    do{
    //Conseguir el tama�o del arreglo
    system("cls");
    printf("Dame el n%cmero m%cximo de alumnos a registrar (Minimo 10): ",163,160);
    scanf("%d",&CantidadDeAlumnosMax);
    if(CantidadDeAlumnosMax >= 10){
         CantidadValida = 0;
        //Crear el arreglo de los estudiantes
        Alumnos alumnos[CantidadDeAlumnosMax];

        do{
            //Limpiar la pantalla con system("cls")
            system("cls");
            //El menu de opciones
            printf("Qu%c acci%cn quieres hacer\n\n",130,162);
            printf("1) Registrar un alumno\n");
            printf("2) Mostrar los datos o un s%clo dato de un alumno\n",162);
            printf("3) Mostrar los datos de todos los alumnos\n",162);
            printf("4) Dar de baja a un alumno\n");
            printf("5) Editar un dato de alg%cn alumno\n",163);
            printf("6) Salir\n");
            scanf("%d",&opcionSeleccionada);
            switch (opcionSeleccionada){
            case 1:
                registrar(alumnos);
                fflush(stdin);
                break;
            case 2:
                system("cls");
                MostrarUnAlumno(alumnos);
                break;
            case 3:
                MostrarTodosLosAlumnos(alumnos);
                break;
            case 4:
                system("cls");
                EliminarUnAlumno(alumnos);
                break;
            case 5:
                system("cls");
                EditarUnAlumno(&alumnos);
                break;
            case 6: break;
            default:
                  printf("Escogi%c una opci%cn no v%clida",162,162,160);
                  break;
            }
        }while(opcionSeleccionada != 6);
    }else{
        system("cls");
        printf("Debe registrar minimo 10 alumnos\n");
        system("pause");
    }
    }while(CantidadValida != 0);
}
