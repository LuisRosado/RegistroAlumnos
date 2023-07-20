# RegistroAlumnos
Programa basico que se podria utilizar como database de algun maestro

Este código es un programa en lenguaje C que permite realizar un registro de alumnos y realizar diversas acciones como registrar un nuevo alumno, mostrar los datos de un alumno en particular, mostrar los datos de todos los alumnos registrados, dar de baja a un alumno y editar un dato de algún alumno.

A continuación, te explico cómo funciona el programa:

Definición de la estructura: Se define la estructura Alumnos que contiene los campos codigo, edad, promedio, nombre, carrera y email, para almacenar los datos de cada alumno.

Variables globales: Se declaran algunas variables globales, como CantidadDeAlumnosMax para indicar el número máximo de alumnos a registrar, y CantidadDeAlumnosRegistrados para llevar un contador de los alumnos registrados.

Función registrar: Esta función permite capturar los datos de un nuevo alumno y almacenarlos en el arreglo de alumnos alumnos[].

Función MostrarTodosLosAlumnos: Muestra los datos de todos los alumnos registrados en el arreglo alumnos[].

Función MostrarUnAlumno: Permite mostrar los datos de un alumno específico buscado por su email o código.

Función EliminarUnAlumno: Permite eliminar a un alumno específico buscado por su email o código.

Función EditarUnAlumno: Permite editar un dato de un alumno específico buscado por su email o código.

Función maneraDeEncontrarUnAlumno: Esta función muestra un menú para que el usuario elija la manera en que quiere buscar al alumno (por email o código).

Función main: Es la función principal del programa. Solicita al usuario el número máximo de alumnos a registrar (debe ser al menos 10) y crea un arreglo alumnos[] con el tamaño proporcionado. Luego, muestra un menú para que el usuario seleccione una de las acciones disponibles, como registrar un alumno, mostrar datos de alumnos, eliminar o editar alumnos, o salir del programa.

El programa permite interactuar con los datos de los alumnos, realizar operaciones de registro, consulta, edición y eliminación, y se repite hasta que el usuario decide salir.
