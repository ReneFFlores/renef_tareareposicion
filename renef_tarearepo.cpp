#include <iostream>
#include <iomanip>

using std::cin;
using std::endl;
using std::cout;

int main(int argc, char* argv[]){
	int tam_col_1, tam_col_2, resp;
	cout << "Ingrese tamaño de columna A" << endl;
	cin >> tam_col_1;
	cout << "Ingrese tamaño de columna B" << endl;
	cin >> tam_col_2;

	char columna_a[tam_col_1][20];
	char columna_b[tam_col_2][20];	
	int menor_intento;

	if(tam_col_1 > tam_col_2){
		menor_intento = tam_col_2;
	}else{
		menor_intento = tam_col_1;
	}

	int pares[menor_intento][2];


	//pide datos columna a
	cout << "Columna A" << endl;
	for(int i = 0; i < tam_col_1; i++){
		cout << "Ingrese palabra " << i << endl;
		cin >> columna_a[i];
	}

	//pide datos columna b
	cout << "Columna B" << endl;
	for(int i = 0; i < tam_col_2; i++){
		cout << "Ingrese palabra " << i << endl;
		cin >> columna_b[i];
	}

	//pide los pares correctos
	for(int i = 0; i < menor_intento; i++){
		cout << "Ingrese par correcto (columna a) " << i << endl;
		cin >> pares[i][0];
		cout << "Ingrese par correcto (columna b) " << i << endl;
		cin >> pares[i][1];
	}

	//empieza el juego
	int col_a_intento, col_b_intento, aciertos = 0;
	while(true){

		cout << "Columna A" << endl;
		for(int i = 0; i < tam_col_1; i++){
			cout << i << " " << columna_a[i] << endl;
		}

		cout << "Columna B"<< endl;
		for(int i = 0; i < tam_col_2; i++){
			cout << i << " " << columna_b[i] << endl;
		}

		cout << "Ingrese par ordenado (columna a)" <<endl;
		cin >> col_a_intento;
		if(col_a_intento > tam_col_1){
			cout << "No existe este numero" << endl;
			cin >> col_a_intento;
		}

		cout << "Ingrese par ordenado (columna b)" <<endl;
		cin >> col_b_intento;
		if(col_b_intento > tam_col_2){
			cout << "No existe este numero" << endl;
			cin >> col_b_intento;
		}

		if(col_a_intento > tam_col_1 || col_b_intento > tam_col_2){
			cout << "Intento mayor que el arreglo" << endl << endl;
			continue;
		}else{
			for(int i = 0; i < menor_intento; i++){
				if(pares[i][0] == col_a_intento){
					if(pares[i][1] == col_b_intento){
						cout << "Intento correcto!" << endl;
						aciertos++;
						break;
					}else{
						if(i == menor_intento-1){
							cout << "Error!" << endl;
						}
					}
				}else{
					if(i == menor_intento-1){
						cout << "Error!" << endl;
					}
				}
				
			}//for
		}//else de que si es menor

		if(aciertos == menor_intento-1){
			cout << "Ha ganado! " << (aciertos/menor_intento*100) << "% de aciertos!" << endl;
			break;
		}else{
				cout << "Desea seguir? 1 si, demas no" << endl;
				cin >> resp;
				if(resp!=1){
					cout << "Adios!" << endl << (aciertos/menor_intento*100) << "% de aciertos!" << endl;
					break;
				}
		}
	}//while true

	return 0;
}