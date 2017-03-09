
// SBD 2017.1
// Aula 01
// Alunos:
// André de Sousa Costa Filho - 15/0005521
// Matheus Batista Silva - 15/0018029




#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAM 10

typedef struct reg{
    char cpf[15];
    char nome[32];
    char cargo[32];
}Aluno;

void criar(Aluno alunos[TAM]){
    int i;

    FILE *fp;

    fp=fopen("registro.bin","wb");

    for(i=0;i<TAM;i++){
        printf("Digite: cpf, nome e cargo\n");
        fgets(alunos[i].cpf,32,stdin);
        fgets(alunos[i].nome,32,stdin);
        fgets(alunos[i].cargo,32,stdin);
        fwrite(&alunos[i],sizeof(Aluno),1,fp);

    }

    fclose(fp);
}


void mostrar(){
    FILE *fp;
    Aluno aluno;
    fp=fopen("registro.bin","rb");
    while(fread(&aluno,sizeof(Aluno),1,fp) !=0){

        printf("%s",aluno.cpf);
        printf("%s",aluno.nome);
        printf("%s",aluno.cargo);
    }
    printf("Aperte qualquer tecla para continuar...\n");
    getchar();
}
void excluir(char buscacpf[11]){
  Aluno aluno;
  int flag=1;
  FILE *ftemp;
  FILE *fp;

  fp=fopen("registro.bin","rb");
  ftemp=fopen("temp.bin","wb");

  while((fread(&aluno,sizeof(Aluno),1,fp))!=0){
    if(strcmp(buscacpf,aluno.cpf) == 0){
      printf("Funcionario deletado\n\n");
      flag=0;
    }
    else{
      fwrite(&aluno,sizeof(Aluno),1,ftemp);
    }
  }
  if(!flag)
    printf("CPF nao encontrado\n\n");
  fclose(fp);
  fclose(ftemp);

  remove("registro.bin");
  rename("temp.bin","registro.bin");
}

void modificar(char buscacpf[32]){
  Aluno aluno;
  int flag=1;

  FILE *ftemp;
  FILE *fp;

  fp=fopen("registro.bin","rb");
  ftemp=fopen("temp.bin","wb");

  while((fread(&aluno,sizeof(Aluno),1,fp))!=0){
    if(strcmp(buscacpf,aluno.cpf) == 0){
      printf("Digite o novo nome:\n");
      fgets(aluno.nome,32,stdin);
      printf("Digite o novo cargo:\n");
      fgets(aluno.cargo,32,stdin);
      fwrite(&aluno,sizeof(Aluno),1,ftemp);
      printf("Alterado com sucesso\n\n");
      flag=0;
    }
    else{
      fwrite(&aluno,sizeof(Aluno),1,ftemp);
    }
  }
  if(!flag)
    printf("CPF nao encontrado\n\n");

  fclose(fp);
  fclose(ftemp);

  remove("registro.bin");
  rename("temp.bin","registro.bin");
}

int main(){

    Aluno alunos[TAM];
    int op=1;
    char bcpf[15];


    while(op){
        system("clear");
        printf("Escolha a opcao:\n");
        printf("1.Escrever no registro\n2.Para excluir um registro\n3.Modificar o registro\n4.Vizualizar o registro\n0.Sair\n");
        scanf("%d",&op);
        getchar();

        switch (op) {
            case 1:system("clear");
                   criar(alunos);
                   break;
            case 2:system("clear");
                   printf("Digite o cpf:\n");
                   fgets(bcpf,32,stdin);
                   excluir(bcpf);
                   break;
            case 3:system("clear");
                   printf("Digite o cpf:\n");
                   fgets(bcpf,32,stdin);
                   modificar(bcpf);
                   break;
            case 4:system("clear");
                   mostrar();
                   break;
            case 0:return 0;
            default:printf("Opcao invalida\n");

        }

    }


    return 0;
}
