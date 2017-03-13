
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Registro alunos=new Registro();
		Scanner in= new Scanner(System.in);
		String inputFile = new String("registro.txt");
		
		int op=1;
		
		
		while(true){
			System.out.println("Digite:\n1.Criar Registro\n2.Mostrar Registro\n3.Modificar Registro\n4.Excluir aluno registrado\n0.Sair");
			op= in.nextInt();
			in.nextLine();
			switch (op) {
			case 1:
				alunos.createRegistro(in);
				break;
			case 2:
				alunos.readRegistro(inputFile);
				break;
			case 3:
				String cpfMod;
				System.out.println("Digite CPF:");
				cpfMod=in.nextLine()+"\n";
				alunos.modifyRegistro(inputFile, cpfMod, in);
				break;
			case 4:
				String cpfDel;
				System.out.println("Digite CPF:");
				cpfDel=in.nextLine()+"\n";
				alunos.deleteRegistro(inputFile, cpfDel);
				break;
			case 0:
				System.exit(0);
			default:
				System.out.println("Opcao indisponivel");
				break;
			}
		}
	}

}
