import java.io.*;
import java.util.*;


public class Registro extends Aluno {
	public int tamanho = 10; //tamanho do Registro
	private Aluno[] alunos;
	
	
	public void createRegistro(Scanner in){
		FileOutputStream fout=null;
		ObjectOutputStream objout=null;

		alunos=new Aluno[tamanho];
		
		try {

			fout=new FileOutputStream("registro.txt");
			objout=new ObjectOutputStream(fout);
			
			for(int i=0;i<tamanho;i++){
				
				alunos[i]=new Aluno();
				
				System.out.println("Digite o CPF:");
				alunos[i].setCpf(in.nextLine()+"\n");
				
				System.out.println("Digite o Nome:");
				alunos[i].setNome(in.nextLine()+"\n");
	
				System.out.println("Digite a matricula:");
				alunos[i].setMatricula(in.nextLine()+"\n");
				
				System.out.println("Digite a idade:");
				alunos[i].setIdade(in.nextInt());in.nextLine();
	
				System.out.println("Digite a data de nascimento:");
				alunos[i].setDataNascimento(in.nextLine()+"\n");
	
				System.out.println("Digite o sexo:");
				alunos[i].setSexo(in.nextLine()+"\n");
	
				System.out.println("Digite o endereco:");
				alunos[i].setEndereco(in.nextLine()+"\n");
	
				System.out.println("Digite o telefone:");
				alunos[i].setTelefone(in.nextLine()+"\n");
	
				System.out.println("Digite o nome do Pai:");
				alunos[i].setNomePai(in.nextLine()+"\n");
	
				System.out.println("Digite o nome da Mae:");
				alunos[i].setNomeMae(in.nextLine()+"\n");
	
				objout.writeObject(alunos[i]);
				
			}
	
		} catch (Exception e) {
			e.printStackTrace();
			
		}finally{
			try {
				objout.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}	
	}
	
	public void readRegistro(String fileName){
		Aluno temp=null;
		FileInputStream fin=null;
		ObjectInputStream objin=null;
		boolean end=false;
		
		try{
			fin=new FileInputStream(fileName);
			objin=new ObjectInputStream(fin);
			while(!(end)){
			temp= (Aluno) objin.readObject();
			System.out.println("CPF:"+temp.getCpf() + "Nome:"+temp.getNome() + "Matricula:"+temp.getMatricula() + "Idade:"+temp.getIdade()+"\n" + 
					"Data de Nascimento:"+temp.getDataNascimento() + "Sexo:"+temp.getSexo() + "Endereco"+temp.getEndereco() +
					"Telefone:"+temp.getTelefone() + "Nome do Pai:"+temp.getNomePai() + "Nome da Mae:"+temp.getNomeMae());
			}
			objin.close();
		}catch(EOFException e){
			end=true;
		}catch(Exception e){
			e.printStackTrace();
		}
		
	}

	public void deleteRegistro(String fileName,String cpfDelete){
		File inputFile = new File(fileName);
		File tempFile = new File("temp.txt");
		
		FileInputStream fin=null;
		ObjectInputStream objin=null;
		
		FileOutputStream fout=null;
		ObjectOutputStream objout=null;
		
		boolean end=false;
		
		try {
			fin=new FileInputStream(inputFile);
			objin=new ObjectInputStream(fin);
			
			fout=new FileOutputStream(tempFile);
			objout=new ObjectOutputStream(fout);
			
			Aluno temp= new Aluno();
			
			
			try{
				while(!(end)){
					
					temp= (Aluno) objin.readObject();
					if(temp.getCpf().equals(cpfDelete)) continue;
					
					objout.writeObject(temp);
					
					
				}
			}catch(EOFException e){
				end=true;
			}
			objin.close();
			objout.close();
			tempFile.renameTo(inputFile);
			
		}catch (Exception e) {
			e.printStackTrace();
		}		
	}
	
	public void modifyRegistro(String fileName,String cpfMod,Scanner in){
		File inputFile = new File(fileName);
		File tempFile = new File("temp.txt");
		
		FileInputStream fin=null;
		ObjectInputStream objin=null;
		
		FileOutputStream fout=null;
		ObjectOutputStream objout=null;
		
		boolean end=false;
		
		try {
			fin=new FileInputStream(inputFile);
			objin=new ObjectInputStream(fin);
			
			fout=new FileOutputStream(tempFile);
			objout=new ObjectOutputStream(fout);
			
			Aluno temp= new Aluno();
			
			
			try{
				while(!(end)){
					
					temp= (Aluno) objin.readObject();
					
					if(temp.getCpf().equals(cpfMod)){

						System.out.println("Digite o Nome:");
						temp.setNome(in.nextLine()+"\n");

						System.out.println("Digite a matricula:");
						temp.setMatricula(in.nextLine()+"\n");
						
						System.out.println("Digite a idade:");
						temp.setIdade(in.nextInt());in.nextLine();

						System.out.println("Digite a data de nascimento:");
						temp.setDataNascimento(in.nextLine()+"\n");

						System.out.println("Digite o sexo:");
						temp.setSexo(in.nextLine()+"\n");

						System.out.println("Digite o endereco:");
						temp.setEndereco(in.nextLine()+"\n");

						System.out.println("Digite o telefone:");
						temp.setTelefone(in.nextLine()+"\n");

						System.out.println("Digite o nome do Pai:");
						temp.setNomePai(in.nextLine()+"\n");

						System.out.println("Digite o nome da Mae:");
						temp.setNomeMae(in.nextLine()+"\n");
					}
					
					objout.writeObject(temp);
					
				}
			}catch(EOFException e){
				end=true;
			}
			
			objin.close();
			objout.close();
			tempFile.renameTo(inputFile);
			
		} catch (Exception e) {
			e.printStackTrace();
		}		
	}
	
}
