
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
    int cpf[11];
    char nome[32];
    char cargo[32];
}Aluno;

void criar(Aluno alunos[TAM]){
    int i;

    FILE *fp;

    fp=fopen("registro.bin","wb");

    for(i=0;i<TAM;i++){
        printf("Digite: cpf, nome e cargo\n");
        scanf("%d",alunos[i].cpf);
        getchar();
        fgets(alunos[i].nome,32,stdin);
        fgets(alunos[i].cargo,32,stdin);
        fwrite(alunos[i].cpf,4,sizeof(alunos[i].cpf),fp);
        fwrite(alunos[i].nome,1,sizeof(alunos[i].nome),fp);
        fwrite(alunos[i].cargo,1,sizeof(alunos[i].cargo),fp);

    }
    fclose(fp);
}

// int busca(char bcpf[32]){
//     int i=0;
//     Aluno busca;
//     FILE *fp;
//
//     fp=fopen("registro.txt","r");
//     while(i<TAM*3){
//         fgets(busca.cpf,32,fp);
//         if(!(strcmp(busca.cpf,bcpf))){
//
//             fclose(fp);
//             return i;
//           }
//         i++;
//     }
//     fclose(fp);
//     return -1;
// }

void mostrar(){
    int i,j;
    FILE *fp;
    Aluno aluno;
    fp=fopen("registro.bin","rb");
    for(i=0;i<TAM;i++){
        fread(aluno.cpf,4,sizeof(aluno.cpf),fp);
        fread(aluno.nome,1,sizeof(aluno.nome),fp);
        fread(aluno.cargo,1,sizeof(aluno.cargo),fp);

        for(j=0;j<11;j++)
            printf("%d",aluno.cpf[j]);
        printf("\n");
        printf("%s",aluno.nome);
        printf("%s",aluno.cargo);
    }
}
void excluir(int position){
  char ch;
  int i=0;

  FILE *temp;
  FILE *fp;

  fp=fopen("registro.txt","r+");
  temp=fopen("temp.txt","w");

  while((ch=fgetc(fp))!=EOF){
    if(ch=='\n')
        i++;
    if(i==position || i==position+1 || i==position+2){
        continue;
    }
    fputc(ch,temp);
  }
  fclose(fp);
  fclose(temp);

  remove("registro.txt");
  rename("temp.txt","registro.txt");
}

void modificar(char bcpf[32],int position){
    char ch,novo_nome[32],novo_cargo[32];
    int i=0;

    FILE *temp;
    FILE *fp;

    fp=fopen("registro.txt","r+");
    temp=fopen("temp.txt","w");

    while((ch=fgetc(fp))!=EOF){
      if(ch=='\n')
          i++;
      if(i==position+1){
          printf("Digite o nome do CPF %s:\n",bcpf);
          fgets(novo_nome,32,stdin);
          fputs(novo_nome,temp);
          continue;
      }
      if(i==position+2){
          printf("Digite o cargo do CPF %s:\n",bcpf);
          fgets(novo_cargo,32,stdin);
          fputs(novo_cargo,temp);
          continue;
      }

      fputc(ch,temp);
    }
    fclose(fp);
    fclose(temp);

    remove("registro.txt");
    rename("temp.txt","registro.txt");
}

int main(){

    Aluno alunos[TAM];
    int op=1;
    char bcpf[32];


    while(op){
        printf("Escolha a opcao:\n");
        printf("1.Escrever no arquivo\n2.Para excluir um registro\n3.Modificar o registro\n0.Sair\n");
        scanf("%d",&op);
        getchar();
        switch (op) {
            case 1:criar(alunos);mostrar();break;
            // case 2:printf("Digite o cpf:\n");
            //        fgets(bcpf,32,stdin);
            //        excluir((busca(bcpf)));
            //        break;
            // case 3:printf("Digite o cpf:\n");
            //        fgets(bcpf,32,stdin);
            //        modificar(bcpf,busca(bcpf));

        }

    }


    return 0;
}
