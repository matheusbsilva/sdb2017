// SBD 2017.1
// Aula 01
// Alunos:
// André de Sousa Costa Filho - 15/0005521
// Matheus Batista Silva - 15/0018029

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAM 3

typedef struct reg{
    char cpf[32];
    char nome[32];
    char cargo[32];
}Aluno;

void criar(FILE *fp,Aluno alunos[TAM]){
    int i;
    for(i=0;i<TAM;i++){
        printf("Digite: cpf, nome e cargo\n");
        fgets(alunos[i].cpf,32,stdin);
        fgets(alunos[i].nome,32,stdin);
        fgets(alunos[i].cargo,32,stdin);
        fputs(alunos[i].cpf,fp);
        fputs(alunos[i].nome,fp);
        fputs(alunos[i].cargo,fp);
    }
}

int busca(FILE *fp,char bcpf[15]){
    int i=0;
    Aluno busca;

    while(i<TAM){
        fgets(busca.cpf,32,fp);
        if(!(strcmp(busca.cpf,bcpf)))
            return i;
        i++;
    }

}

void excluir(FILE *fp,Aluno alunos[TAM]){
    
}


int main(){
    FILE *fp;
    Aluno alunos[TAM];
    int op=1,i;
    fp=fopen("registro.txt","w");

    while(op){
        printf("Escolha a opcao:\n");
        printf("1.Escrever no arquivo\n0.Sair\n");
        scanf("%d",&op);
        getchar();
        switch (op) {
            case 1:criar(fp,alunos);break;

        }

    }

    fclose(fp);
    return 0;
}
