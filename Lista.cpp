//Desenvolver métodos de classe
//Lista.cpp

#include "Lista.h"

//construtor
Lista::Lista(){
	this->cabeca = 0; //inicializa lista vazia
	this->qtd = 0;
}

//destrutor
Lista::~Lista(){
	this->libera(); //ideia é liberar free toda memória alocada
	this->qtd = 0;
}

void Lista::insere_inicio(int i){
	//no_dado* novo = (no_dado*) malloc(sizeof(no_dado));
	//novo->info = i;
 	//novo->prox = this->cabeca;
 	no_dado* novo = new no_dado(i, this->cabeca);
  	this->cabeca = novo; //adiciona a partir do início
  	this->qtd++; //incrementa o contador de nó-dado
}

void Lista::imprime(){
	if (!this->isEmpty(this->cabeca)){
		no_dado* p; /* variável auxiliar para percorrer a lista */
		printf("\nInfo = ");
		for (p = this->cabeca; p != NULL; p = p->prox)
			printf("%d - ", p->info);
		printf("\n");	
	} else printf("Lista está vazia!\n");
}

void Lista::vazia(){
	if (!this->isEmpty(this->cabeca))
		printf("Lista não está vazia!\n");
	else
		printf("Lista está vazia!\n");
}

void Lista::libera(){
	no_dado* p = this->cabeca;
	 while (p != NULL) {
	 	no_dado* t = p->prox; // guarda referência para o próximo elemento
		free(p); /* libera a memória apontada por p */
		this->qtd--; //decrementa contador de qtd
	 	p = t; /* faz p apontar para o próximo */
	 }
	 this->cabeca = 0; //inicializa lista vazia
}

void Lista::tamanho(){
	printf("Tamanho ou qtd de elementos: %d\n", this->qtd);
}

//tratamento métodos privados
bool Lista::isEmpty(no_dado* l){
	return l==NULL;
}


void Lista::busca(int num){
	no_dado* p = this->cabeca;
	if(!this->isEmpty(this->cabeca)){
		for(;p!=NULL;p=p->prox){
			if(p->info==num){
				cout << "Numeração encontrada com sucesso!" << endl;
				return;
			}
		}
		cout << "Numeração não encontrada!" << endl;
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
				cout << "Numereação retirada com sucesso!" << endl; 
				return;
			}
		}
		cout << "Numeração não encontrada!" << endl;
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
