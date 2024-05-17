#include <iostream>

class Funcionario{
    public:
    Funcionario(){}
    ~Funcionario(){}

    void setNome(std::string _nome){
        nome=_nome;
    }
    void setSalario(float _salario){
        salario=_salario;
    }

    float addAumento(float salario){
        float aumento;
        std::cout << "Qual será o aumento no sálario do funcionário? ";
        std::cin >> aumento;

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
    Assistente(){}
    ~Assistente(){}

    void setMatricula(int _matricula){
        matricula=_matricula;
    }
    
    void exibeDados(float salario){
        std::cout << "Nome: " << nome;
        std::cout << "\nSalário: " << salario;
        std::cout << "\nMatrícula " << matricula;
    }

    private:
    int matricula;
};

int main(){

    Assistente GetSet;

    std::string nome;
    float salario;
    int op, matricula;

    std::cout << "Digite o nome do funcionário: ";
    std::cin >> nome;
    std::cout << "Digite o salário do funcionário: ";
    std::cin >> salario;
    GetSet.setNome (nome);
    GetSet.setSalario (salario);
    std::cout << "Digite o número da matrícula do assistente: ";
    std::cin >> matricula;
    GetSet.setMatricula (matricula);
    std::cout << "Digite 1 caso desejo dar um aumento no salário do funcionário, qualquer outro valor se não for o caso: ";
    std::cin >> op;
    if (op==1){
        salario=GetSet.addAumento(salario);
    }
    GetSet.exibeDados(salario);
    return 0;
}