#include <iostream>

class Funcionario{
    public:
    Funcionario(std::string _nome, float _salario){
    	nome = _nome;
    	salario = _salario;
    }
    ~Funcionario(){}

    void setNome(std::string _nome){
        nome=_nome;
    }
    void setSalario(float _salario){
        salario=_salario;
    }

    float addAumento(float aumento){
        salario=salario+aumento;
        return salario;
    }

    void ganhoAnual(){
        std::cout << "Ganho anual: " << salario*12;
    }

    void exibeDados(){
        std::cout << "Nome: " << nome;
        std::cout << "\nSalário: " << salario;
    }

    protected:
    std::string nome;
    float salario;
};

class Assistente : public Funcionario{
    public:
    Assistente(std::string _nome, float _salario, int _matricula) : Funcionario(_nome, _salario){
    	matricula = _matricula;
    }
    ~Assistente(){}

    void setMatricula(int _matricula){
        matricula=_matricula;
    }

    void exibeDados(){
        std::cout << "Nome: " << nome;
        std::cout << "\nSalário: " << salario;
        std::cout << "\nMatrícula " << matricula;
    }

    protected:
    int matricula;
};

class Tecnico : public Assistente{
    public:
    Tecnico(std::string _nome, float _salario, int _matricula) : Assistente(_nome, _salario, _matricula){}
    ~Tecnico(){}

    float pergBonus(){
        std::cout << "Qual o bônus salarial do assistente técnico? ";
        std::cin >> bonusSalarioT;
        return bonusSalarioT;
    }
    float bonusTecnico(){
        salario=salario+bonusSalarioT;
        return salario;
    }
    void exibeDados(){
        std::cout << "Nome: " << nome;
        std::cout << "\nSalário: " << salario;
        std::cout << "\nMatrícula: " << matricula;
        std::cout << "\nCargo: Técnico";
    }

    void ganhoAnual(){
        std::cout << "\nGanho anual: " << salario*12;
    }

    private:
    float bonusSalarioT;
};

class Administrativo : public Assistente{
    public:
    Administrativo(std::string _nome, float _salario, int _matricula) : Assistente(_nome, _salario, _matricula){}
    ~Administrativo(){}

    int getdianoite(){
    	return dianoite;
    }

    float DN(){
        std::cout << "Se o técnico administrativo trabalhar de dia, digite 1. Caso trabalhe no turno da noite, digite 2. ";
        std::cin >> dianoite;
        return dianoite;
    }
    float bonusNoturno (){
        std::cout << "Qual o bônus salarial do técnico administrativo que trabalha no turno da noite? ";
        std::cin >> bonusSalarioA;
        return bonusSalarioA;
    }
    float bonusAdministrativo(){
        salario=salario+bonusSalarioA;
        return salario;
    }

    void ganhoAnual(){
        std::cout << "\nGanho anual: " << salario*12;
    }

    private:
    int dianoite;
    float bonusSalarioA;
};

int main(){
    std::string nome;
    float salario;
    float aumento = 0;
    int op, matricula, a, b;

    std::cout << "Digite o nome do funcionário: ";
    std::cin >> nome;
    std::cout << "Digite o salário do funcionário: ";
    std::cin >> salario;
    std::cout << "Digite 1 caso desejo dar um aumento no salário do funcionário, qualquer outro valor se não for o caso: ";
    std::cin >> op;
    if (op==1){
        std::cout << "Qual será o aumento no sálario do funcionário? ";
        std::cin >> aumento;
    }
    std::cout << "Digite 1 se o Funcionário for um Assistente: ";
    std::cin >> a;

    if(a==1){
        std::cout << "Digite o número da matrícula do assistente: ";
        std::cin >> matricula;
        std::cout << "Digite 1 caso o assistente seja Técnico e 2 se for Administrativo: ";
        std::cin >> b;
        if(b==1){
        	Tecnico Objeto(nome, salario, matricula);
            Objeto.pergBonus();
            Objeto.bonusTecnico();
        	Objeto.addAumento(aumento);
            Objeto.exibeDados();
            return 0;
        }
        else if (b==2){
        	Administrativo Objeto(nome, salario, matricula);
            Objeto.DN();
            if (Objeto.getdianoite()){
            	Objeto.bonusNoturno();
        	}
            Objeto.bonusAdministrativo();
        	Objeto.addAumento(aumento);
        	Objeto.exibeDados();
        	return 0;
        } else{
            std::cout << "Valor INVÁLIDO para cargo do ASSISTENTE.";
            return -1;
        }
    }
   
    Funcionario Objeto(nome, salario);
    Objeto.addAumento(aumento);
    Objeto.exibeDados();
    return 0;
}