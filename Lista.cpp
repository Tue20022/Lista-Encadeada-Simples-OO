//Desenvolver m�todos de classe
//Lista.cpp

#include "Lista.h"

//construtor
Lista::Lista(){
	this->cabeca = 0; //inicializa lista vazia
	this->qtd = 0;
}

//destrutor
Lista::~Lista(){
	this->libera(); //ideia � liberar free toda mem�ria alocada
	this->qtd = 0;
}

void Lista::insere_inicio(int i){
	//no_dado* novo = (no_dado*) malloc(sizeof(no_dado));
	//novo->info = i;
 	//novo->prox = this->cabeca;
 	no_dado* novo = new no_dado(i, this->cabeca);
  	this->cabeca = novo; //adiciona a partir do in�cio
  	this->qtd++; //incrementa o contador de n�-dado
}

void Lista::imprime(){
	if (!this->isEmpty(this->cabeca)){
		no_dado* p; /* vari�vel auxiliar para percorrer a lista */
		printf("\nInfo = ");
		for (p = this->cabeca; p != NULL; p = p->prox)
			printf("%d - ", p->info);
		printf("\n");	
	} else printf("Lista est� vazia!\n");
}

void Lista::vazia(){
	if (!this->isEmpty(this->cabeca))
		printf("Lista n�o est� vazia!\n");
	else
		printf("Lista est� vazia!\n");
}

void Lista::libera(){
	no_dado* p = this->cabeca;
	 while (p != NULL) {
	 	no_dado* t = p->prox; // guarda refer�ncia para o pr�ximo elemento
		free(p); /* libera a mem�ria apontada por p */
		this->qtd--; //decrementa contador de qtd
	 	p = t; /* faz p apontar para o pr�ximo */
	 }
	 this->cabeca = 0; //inicializa lista vazia
}

void Lista::tamanho(){
	printf("Tamanho ou qtd de elementos: %d\n", this->qtd);
}

//tratamento m�todos privados
bool Lista::isEmpty(no_dado* l){
	return l==NULL;
}


void Lista::busca(int num){
	no_dado* p = this->cabeca;
	if(!this->isEmpty(this->cabeca)){
		for(;p!=NULL;p=p->prox){
			if(p->info==num){
				cout << "Numera��o encontrada com sucesso!" << endl;
				return;
			}
		}
		cout << "Numera��o n�o encontrada!" << endl;
	}else{
		cout << "Lista Vazia!" << endl;
	}
}

void Lista::retira(int num){
	no_dado* p = this->cabeca;
	no_dado* ant = NULL;
	
	if(!this->isEmpty(this->cabeca)){
		for(; p!=NULL; (ant=p)&&(p=p->prox)){
			if(p->info==num){
				ant->prox = p->prox;
				this->qtd--;
				free(p);
				cout << "Numerea��o retirada com sucesso!" << endl; 
				return;
			}
		}
		cout << "Numera��o n�o encontrada!" << endl;
	}else{
		cout << "Lista Vazia!" << endl;
	}
}

void Lista::insere_fim(int num){
	no_dado* novo= new no_dado(num, NULL);
	no_dado* p = this->cabeca;
	
	if(!this->isEmpty(this->cabeca)){
		for(; p->prox!=NULL; p=p->prox);
		p->prox = novo;
	}else{
		this->cabeca = novo;	
	}
	this->qtd++;
}

void Lista::retira_inicio(){
	if(!this->isEmpty(this->cabeca)){
		no_dado* p = this->cabeca;
		this->cabeca = p->prox;
		free(p);
		this->qtd--;
	}else
		cout << "Lista vazia!" << endl;	
}

void Lista::retira_fim(){
	if(!this->isEmpty(this->cabeca)){
		no_dado* p = this->cabeca;
		if(p->prox==NULL){
			free(p);
			this->cabeca = NULL;
			this->qtd--;
			return;
		}
		no_dado* ant = NULL; 
		for(; p->prox!=NULL; (ant=p)&&(p=p->prox));
		ant->prox = NULL;
		free(p);
		this->qtd--;
	}else
		cout<< "Lista vazia!" << endl;
}

void Lista::imprime_inicio(){
	if(!this->isEmpty(this->cabeca)){
		no_dado* p = this->cabeca;
		cout<< "Info: " << p->info << endl;
	}else
		cout<< "Lista vazia!" << endl;
}

void Lista::imprime_fim(){
		if(!this->isEmpty(this->cabeca)){
		no_dado* p = this->cabeca;
		for(; p->prox!=NULL; p= p->prox);
		cout<< "Info: " << p->info << endl;
	}else
		cout<< "Lista vazia!" << endl;
}
