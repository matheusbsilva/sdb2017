import java.io.Serializable;

public class Aluno implements Serializable {

	private String cpf;
	private String nome;
	private String matricula;
	private int idade;
	private String dataNascimento;
	private String sexo;
	private String endereco;
	private String telefone;
	private String nomePai;
	private String nomeMae;
	
	public void setCpf(String cpf){
		this.cpf=cpf;
	}
	public void setNome(String nome){
		this.nome=nome;
	}
	public void setMatricula(String matricula){
		this.matricula=matricula;
	}
	public void setIdade(int idade){
		this.idade=idade;
	}
	public void setDataNascimento(String dataNascimento){
		this.dataNascimento=dataNascimento;
	}
	public void setSexo (String sexo){
		this.sexo=sexo;
	}
	public void setEndereco(String endereco){
		this.endereco=endereco;
	}
	public void setTelefone(String telefone){
		this.telefone=telefone;
	}
	public void setNomePai(String nomePai){
		this.nomePai=nomePai;
	}
	public void setNomeMae(String nomeMae){
		this.nomeMae=nomeMae;
	}
	public String getCpf() {
		return cpf;
	}
	public String getNome() {
		return nome;
	}
	public String getMatricula() {
		return matricula;
	}
	public int getIdade() {
		return idade;
	}
	public String getDataNascimento() {
		return dataNascimento;
	}
	public String getSexo() {
		return sexo;
	}
	public String getEndereco() {
		return endereco;
	}
	public String getTelefone() {
		return telefone;
	}
	public String getNomePai() {
		return nomePai;
	}
	public String getNomeMae() {
		return nomeMae;
	}
	

		
}
