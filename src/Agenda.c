1.	/*
2.		Name: Questão 4
3.		Copyright: 
4.		Author: Leonardo Fernandes Gomez, Jhonatan Oliveira dos Santos, Igor Matheus Barbosa Oliveira 
5.		Date: 28/05/16 14:22
6.		Description: Agenda de horários que permite inserção de dados, remoção e edição
7.	*/
8.	
9.	
10.	#include <stdio.h>
11.	#include <stdlib.h>
12.	#include <string.h>
13.	
14.	//Se o sistema for Windows adiciona determinada biblioteca, e definindo comandos de limpar e esperar
15.	#include <windows.h>
16.	#define LIMPA_TELA system("cls") //limpando a tela
17.	
18.	#define N 10
19.	void enqueue(); //adiciona
20.	void dequeue(); //tira
21.	void mostra(); //mostra
22.	void altera(); //altera
23.	void mostra_erro(); //mostra o erro de digitação
24.	
25.	
26.	
27.		char texto[N][20];
28.		char horario[N][6];
29.		int i;
30.		int p = -1;
31.		int u = -1;
32.		int contador = 0;
33.		
34.	main(){
35.		int escolha;
36.	
37.		    do {
38.	        //Limpando a tela, e mostrando o menu
39.	        LIMPA_TELA;
40.	        printf("\nAgenda Diaria\n\n");
41.	        printf("Escolha uma opcao: \n");
42.	        printf("\t1 - Inserir horario na agenda\n");
43.	        printf("\t2 - Remover horario na agenda\n");
44.	        printf("\t3 - Mostrar horario na agenda\n");
45.	        printf("\t4 - Altera horario na agenda\n");        
46.	        printf("\t9 - Sair\n\n");
47.	        printf("Opcao selecionada: ");
48.	        scanf("%c", &escolha); //lendo a escolha do usuario
49.	        fflush(stdin); //limpando
50.	        switch(escolha) {
51.	            //Inserindo
52.	            case '1': //caso escolha do usuario for 1 chamará a função enqueue (adicionar) abaixo
53.	                enqueue(); 
54.	                break;
55.	            //Excluindo
56.	            case '2': // caso escolha do usuário for 2 chamara a função dequeue (retirar) abaixo
57.	                if(contador != 0){ //garantindo que a lista não está vazia
58.	                    dequeue();
59.	                }
60.	                else{ // caso a lista não possua elementos
61.	                    printf("\nA Fila esta vazia!\n");
62.	                    getchar();
63.	                }
64.	                break;                
65.	            //Mostrando
66.	            case '3': // caso escolha 3 chamara a função responsável por mostrar a lista
67.	                if(contador != 0){ // garantindo que a lista nao esta vazia
68.	                    mostra(); 
69.	                }
70.	                else{ // caso a lista esteja vazia
71.	                    printf("\nA Fila esta vazia!\n"); 
72.	                    getchar();
73.	                }
74.	                break;
75.				//Alterando
76.				case '4': // caso para alterar dados
77.					altera();
78.					break;	                
79.	            case '9':
80.	                printf("\nObrigado por utilizar esse programa!\n");
81.	                printf("------>Terminal de Informacao<------\n\n");
82.	                exit(0);
83.	                break;
84.	            //Se foi algum valor inválido
85.	            default:
86.	                mostra_erro();
87.	                break;
88.	        }
89.	        //Impedindo sujeira na gravação da escolha
90.	        getchar();
91.	    }
92.	    while (escolha > 0); //Loop Infinito
93.	
94.		system("pause");
95.	}
96.	
97.	void enqueue(){ //enqueue função de adicionar
98.		LIMPA_TELA;
99.		int prox;
100.		prox = (u+1) % N; // prox recebe resto da variavel u+1 dividido por n
101.		u = prox; //u recebe prox
102.		
103.		printf("Digite o horario no formato (00:00): ");
104.		gets(horario[u]); //guardando o valor horário no vetor u
105.		printf("O que vai fazer as %s : ", horario[u]);
106.		gets(texto[u]);
107.		
108.		if (p==-1) 
109.			p=0;
110.		contador++;
111.	  
112.		printf("\nHorario salvo!\n");
113.	    printf("--------------------------------------\n");
114.	}
115.	
116.	//Exclusão
117.	void dequeue(){ //funcao de excluir
118.	 
119.	  	if (p == u) p=u=-1;
120.		else p=(p+1) % N;
121.	 	contador--;
122.	    
123.	    /*printf("\nQuantidade de horario [%d], retirado da fila [%d]\n",contador,p);*/
124.	    
125.		printf("\nHorario  excluido!\n");
126.	    printf("--------------------------------------");
127.	    getchar();
128.	}
129.	
130.	//Lista horarios
131.	void mostra(){ //função que lista os horários
132.		LIMPA_TELA;
133.	    printf("\nMostrando Horarios: \n");
134.	    printf("--------------------------------------\n");
135.	    printf("Quantidade de horarios inseridos %d\n", contador);
136.	    printf("--------------------------------------");
137.	    int count;
138.	
139.	    for(count=p ; count <= u ; count++){
140.	        printf("\n\t%i - As %s : %s\n",count, horario[count], texto[count]);
141.	    }  
142.	}
143.	
144.	//Alterar
145.	void altera(){ // função para alteração de dados
146.		int count, indice;
147.	
148.	    for(count=p ; count <= u ; count++){
149.	        printf("\n\t%i - As %s : %s\n",count, horario[count], texto[count]);
150.	    }
151.		
152.		printf("\n"); 
153.		printf("Digite o indice que deseja alterar: ");
154.		scanf("%i", &indice);
155.		fflush(stdin);
156.		printf("Digite o horario no formato (00:00): ");
157.		gets(horario[indice]);
158.		printf("Oque vai fazer as %s : ", horario[u]);
159.		gets(texto[indice]);
160.		 
161.	}
162.	
163.	//Mostra erro de digitação
164.	void mostra_erro(){ //função para erro
165.	    LIMPA_TELA;
166.	    printf("\nErro de Digitacao: \n");
167.	    printf("--------------------------------------\n");
168.	    printf("\nDigite uma opcao valida (pressione -Enter- p/ continuar)!\n\n");
169.	    printf("--------------------------------------");
170.	    getchar();
171.	}

