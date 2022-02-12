#include <iostream>
#include <fstream>
#include <cstring> //Para copiar la cadena y strtok


using namespace std;

 struct Alumno{

    string matricula;
    string primerApellido;
    string segundoApellido;
    string nombre;

};




bool busquedaBinaria(Alumno a[], Alumno buscado){


	int primero = 0;
	int ultimo = 40 - 1;    //ajustar el tamaño del arreglo
	bool encontrado = false;
	int medio2;


	while (primero <= ultimo and !encontrado){
		int medio = (primero + ultimo)/2;
		if (a[medio].matricula == buscado.matricula){
            cout << endl << endl << "El alumno " << buscado.matricula << " se encuentra en la lista"
            << endl << endl << "Sus datos son los siguientes:";
            cout << endl << endl << "Matricula: " << a[medio].matricula << endl;
             cout << "Apellidos: " << a[medio].primerApellido << " " << a[medio].segundoApellido << endl;
             cout << "Nombre: " << a[medio].nombre << endl << endl;
			encontrado = true;
		}
		else if (buscado.matricula < a[medio].matricula){
			ultimo = medio - 1;
		}
		else{
			primero = medio + 1;
		}
		medio2 = medio;
	}

	if(encontrado == false){
        cout << "El alumno " << buscado.matricula << " no se encuentra en la lista" << endl << endl;
    }

	return encontrado;
}



int main(){

    Alumno alumnos[100];
    int nAlumnos=0;
    int i=0;
    Alumno n;
    string cadena;
    char cadenaArr[200];

    ifstream entrada("alumnos.txt");  //Se crea la unión al archivo

    while (!entrada.eof()) {

        getline(entrada,cadena); //Se lee la línea completa con espacios y separador
        strcpy(cadenaArr,cadena.c_str()); // strtok necesita char[] no string, por eso se convierte

        alumnos[i].matricula = strtok(cadenaArr, ","); //El primer token
        alumnos[i].primerApellido = strtok(NULL, ",");         //El segundo token, NULL hace referencia a la misma cadena
        alumnos[i].segundoApellido = strtok(NULL,",");  //El tercer token
        alumnos[i].nombre = strtok(NULL,","); //El cuarto token

        i++;
        nAlumnos++;
    }
  entrada.close(); //Se cierra el archivo

  cout << "Dame la matricula del alumno que quieres buscar" << endl;
  cin >> n.matricula;

  busquedaBinaria(alumnos, n);


  return 0;

}
