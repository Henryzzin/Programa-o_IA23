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

    int ganhoAnual(){
        std::cout << "Ganho anual: " << salario*12;
        return 0;
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

class Tecnico : public Assistente{
    public:
    Tecnico(){}
    ~Tecnico(){}

    float bonuSalario(){
        float bonusTecnico;
        std::cout << "Qual o valor do bônus salarial de um Assistente Técnico? ";
        std::cin bonusTecnico;
        salario=bonusTecnico+salario;
        return salario;        
    }

    int ganhoAnual (){
        std::cout << "O ganho anual do Assistente Técnico é de: " << (bonusTecnico + salario)*12;
        return 0;
    }
};

class Administrativo : public Assistente{
    public:
    Administrativo(){}
    ~Administrativo(){}

    std::cout << "Se o Assistente Administrativo trabalha de dia, digite 1. Se for de noite, digite 2. ";
    std::cin >> DN;
    if(DN==0){
        float bonuSalario(){
            float bonusTecnico;
            std::cout << "Qual o valor do bônus salarial de um Assistente Administrativo que trabalha de noite? ";
            std::cin >> bonusTecnico;
            salario=bonusTecnico+salario;
            return salario;    
        }
    } else{
        std::cout << "Assistentes Administrativos que trabalham diurnamente não recebem bônus salarial.";
    }

    int ganhoAnual (){
    std::cout << "O ganho anual do Assistente Administrativo é de: " << (bonusTecnico + salario)*12;
    return 0;
    }
    
    private:
    int DN;
}

int main(){

    Assistente GetSet;

    std::string nome;
    float salario;
    int op, matricula, op2;

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
    std::cout << "Digite 1 para Assistente Técnico e 2 para Assistente Administrativo. ";
    std::cin >> op2;
    salario=GetSet.bonuSalario(salario);
    return 0;
}