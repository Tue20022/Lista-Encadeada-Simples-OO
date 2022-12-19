//Matheus Vianna Nunes - ED
#include <iostream>
#include <locale> //habilitar padrões de caracter de teclado PTb
#include "Lista.h"

void menu(){
	cout << endl;
	cout << "Menu - Escolha opção:\n" <<endl;
	cout << "1- Insere Inicio" << endl;
	cout << "2- Imprime" << endl;
	cout << "3- Vazia" << endl;
	cout << "4- Tamanho" << endl;
	cout << "5- Libera" << endl;
	cout << "6- Busca" << endl;
	cout << "7- Retira" << endl;
	cout << "8- Insere fim" << endl;
	cout << "9- Retira inicio" << endl;
	cout << "10- Retira fim" << endl;
	cout << "11- Imprime inicio" << endl;
	cout << "12- Imprime fim" << endl;
	cout << "Qualquer outra para sair\n";
	cout << "Opção: ";
}

float ler_numero(int i){
	float tmp;
	cout << "Informe um número: ";
	cin >> tmp;
	return tmp;
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	Lista l;
	int n;
	
	int op(0);
	do{
		menu();
		cin >> op;
		
		switch(op){
			case 1: //insere inicio
				l.insere_inicio(ler_numero(n));
				cout<< endl;
				break;
			
			case 2: //imprime
				l.imprime();
				cout<< endl;
				break;
			
			case 3: //vazia
				l.vazia();
				cout<< endl;
				break;
			
			case 4: //tamanho
				l.tamanho();
				cout<< endl;
				break;
			
			case 5://libera
				l.libera();
				cout<< endl;
				break;
			
			case 6://busca
				l.busca(ler_numero(n));
				cout<< endl;
				break;
				
			case 7://retira
				l.retira(ler_numero(n));
				cout<< endl;
				break;		
				
			case 8://insere fim 
				l.insere_fim(ler_numero(n));
				cout<<endl;
				break;
			
			case 9://retira inicio
				l.retira_inicio();
				cout<<endl;
				break;	
			
			case 10://retira fim
				l.retira_fim();
				cout<<endl;	
				break;
				
			case 11://imprime inicio
				l.imprime_inicio();
				cout<<endl;
				break;
			
			case 12://imprime fim
				l.imprime_fim();
				cout<<endl;
				break;
			default: cout << "Opção inválida e fim de programa!\n";		
		}
	}while(op>=1 && op<=13);
	
	cout << "Fim de programa!\n";
	system("pause");
	return 0;
}
	
