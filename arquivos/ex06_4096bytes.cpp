#include <iostream>
#include <vector>
#include <stdlib.h> 
#include <time.h>
using namespace std;

class Ordenacao{
	public: clock_t inicio, fim;
	void bubblesort(vector<int>& num){
		inicio = clock();
		int troca;
		for(int i = 0; i < num.size(); i++){
			for(int j = 0; j < num.size()-1; j++){
				if(num[j] > num[j+1]){
					troca = num[j];
					num[j] = num[j+1];
					num[j+1] = troca;
				}
			}
		}
		fim = clock();
		printf("\nTempo Gasto Bubblesort: %lf milisegundos\n",(double)(fim-inicio)/((double)CLOCKS_PER_SEC));
	}
	
	void selecao(vector<int>& num) {
		inicio = clock();
		int troca, min;
		for(int i = 0; i < num.size()-1; i++){
			min = i;
			for(int j=i+1; j < num.size(); j++) {
				if(num[j] < num[min]){
					min = j;
				}
			}
			troca = num[i];
			num[i] = num[min];
			num[min] = troca;
		}
		fim = clock();
		printf("Tempo Gasto Selecao: %lf milisegundos\n",(double)(fim-inicio)/((double)CLOCKS_PER_SEC));
	}
	
	void insercao(vector<int>& num) {
		inicio = clock();
		int j, marcada;
		for(int i = 1; i < num.size(); i++) {
			marcada = num[i];
			j = i;
			while((j>0) && (num[j-1])) {
				num[j] = num[j-1];
				j = j-1;
			}
			num[j] = marcada;
		}
		fim = clock();
		printf("Tempo Gasto Insercao: %lf milisegundos\n",(double)(fim-inicio)/((double)CLOCKS_PER_SEC));
	}
	
	void quicksort(vector<int>& num, int esq, int dir) {
		int i = esq;
		int j = dir;
		int pivo = num[(esq+dir)/2];
		do {
			while(num[i] < pivo && i < dir){
				i++;
			}
			while(pivo<num[j] && j>esq){
				j--;
			}
			if(i<=j) {
				int aux = num[i];
				num[i] = num[j];
				num[j] = aux;
				i++; j--;
			}
		} while (i <= j);
		if(esq < j){
			quicksort(num, esq, j);
		}
		if(i < dir){
			quicksort(num, i, dir);
		}
	}
	
	void tempoquicksort(vector<int>& num, int esq, int dir){
		inicio = clock();
		quicksort(num, esq, dir);
		fim = clock();
    	printf("Tempo Gasto Quicksort: %lf milisegundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
	}	
	
	void mergesort(int comeco, int final, vector<int>& num){
		if(comeco == final) {
			return;
		}
		int meio = (comeco+final)/2;
		mergesort(comeco, meio, num);
		mergesort(meio+1, final, num);
		intercala(comeco,meio,final,num);
	}
	
	void intercala(int comeco, int meio, int final, vector<int>& num) {
		int aux[final-comeco+1];
		int i = comeco;
		int j = meio+1;
		int k = 0;
		while(i <= meio && j <= final) {
			if(num[i] <= num[j]){
				aux[k++] = num[i++];
			} else {
				aux[k++] = num[j++];
			}
		}
		while(i <= meio) {
			aux[k++] = num[i++];
		}
		while(j <= final) {
			aux[k++] = num[j++];
		}
		for(i=0; i < k; i++) {
			num[comeco+i] = aux[i];
		}
	}
	
	void tempomergesort(int comeco, int final, vector<int>& num){
		inicio = clock();
		mergesort(comeco, final, num);
		fim = clock();
    	printf("Tempo Gasto Mergesort: %lf milisegundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
	}
};

main() {
    vector<int> original;
    int quantidade, numero;
    srand(time(NULL));

    cout << "Digite a quantidade de elementos que deseja ordenar: ";
    cin >> quantidade;

    for (int i = 0; i < quantidade; i++) {
        numero = rand() % 101;
        original.push_back(numero);
    }
    vector<int> desordenado1 = original;
    vector<int> desordenado2 = original;
    vector<int> desordenado3 = original;
    vector<int> desordenado4 = original;
    vector<int> desordenado5 = original;

    Ordenacao ordenar;
    ordenar.bubblesort(desordenado1);
    ordenar.selecao(desordenado2);
    ordenar.insercao(desordenado3);
    ordenar.tempoquicksort(desordenado4, 0, desordenado4.size() - 1);
    ordenar.tempomergesort(0, desordenado5.size()-1, desordenado5);
    
    system("pause");
}
                                                                                                                                                                                                                                                                            
