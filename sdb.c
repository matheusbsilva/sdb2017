
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

    fp=fopen("registro.txt","w");

    for(i=0;i<TAM;i++){
        printf("Digite: cpf, nome e cargo\n");
        fgets(alunos[i].cpf,32,stdin);
        fgets(alunos[i].nome,32,stdin);
        fgets(alunos[i].cargo,32,stdin);
        fputs(alunos[i].cpf,fp);
        fputs(alunos[i].nome,fp);
        fputs(alunos[i].cargo,fp);
    }
    fclose(fp);
}

int busca(FILE *fp,char bcpf[15]){ //TA FUNCIONANDO!!!!
    int i=0;
    Aluno busca;

    fp=fopen("registro.txt","r");
    while(i<TAM*3){
        fgets(busca.cpf,15,fp);
        if(!(strcmp(busca.cpf,bcpf))){

            fclose(fp);
            return i;
          }
        i++;
    }
    fclose(fp);
    return -1;
}
void excluir(FILE *fp,int position){
  int i;
  char car;
  fp=fopen("registro.txt","a");
  for(i=0;i<3;i++){
    fgetc(fp);
  }
  fputs("oi",fp);
  // for(i=0;i<3;i++){
  //   fseek(fp,busca+i,SEEK_SET);
  //   fputs("",fp);
  // }
  fclose(fp);
}

int main(){
    FILE *fp;
    Aluno alunos[TAM];
    int op=1;
    char bcpf[32];


    while(op){
        printf("Escolha a opcao:\n");
        printf("1.Escrever no arquivo\n2.Para excluir um registro\n0.Sair\n");
        scanf("%d",&op);
        getchar();
        switch (op) {
            case 1:criar(fp,alunos);break;
            case 2:printf("Digite o cpf:\n");
                   fgets(bcpf,32,stdin);

                   excluir(fp,(busca(fp,bcpf)));
                   break;


        }

    }


    return 0;
}
