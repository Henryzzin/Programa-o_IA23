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

    protected:
    int matricula;
};

class Tecnico : public Assistente{
    public:
    Tecnico(){}
    ~Tecnico(){}

    float pergBonus(){
        std::cout << "Qual o bônus salarial do assistente técnico?";
        std::cin >> bonusSalarioT;
        return bonusSalarioT;
    }
    float bonusTecnico(){
        salario=salario+bonusSalarioT;
        return salario;
    }
    void exibeDados(float salario){
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
    Administrativo(){}
    ~Administrativo(){}

    float DN(){
        std::cout << "Se o técnico administrativo trabalhar de dia, digite 1. Caso trabalhe no turno da noite, digite 2.";
        std::cin >> dianoite;
        return dianoite;
    }
    float bonusNoturno (){
        std::cout << "Qual o bônus salarial do técnico administrativo que trabalha no turno da noite?";
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

    Funcionario* Objeto = new Funcionario();

    std::string nome;
    float salario;
    int op, matricula, a, b;

    std::cout << "Digite o nome do funcionário: ";
    std::cin >> nome;
    std::cout << "Digite o salário do funcionário: ";
    std::cin >> salario;
    Objeto.setNome(nome);
    Objeto.setSalario(salario);
    std::cout << "Digite 1 se o Funcionário for um Assistente: ";
    std::cin >> a;
    if(a==1){
        Objeto = dynamic_cast<Assistente*>(Objeto);
        std::cout << "Digite o número da matrícula do assistente: ";
        std::cin >> matricula;
        std::cout << "Digite 1 caso o assistente seja Técnico e 2 se for Administrativo: ";
        std::cin >> b;
        if(b==1){
            Objeto.pergBonus();
            Objeto.bonusTecnico();
        }
        else if (b==2){
            Objeto.DN();
            Objeto.bonusNoturno();
            Objeto.bonusAdministrativo();
        } else{
            std::cout << "Valor INVÁLIDO para cargo do ASSISTENTE.";
        }
    }
    Objeto.exibeDados(salario);
    return 0;
    std::cout << "Digite 1 caso desejo dar um aumento no salário do funcionário, qualquer outro valor se não for o caso: ";
    std::cin >> op;

    float aumento;
    if (op==1){
        aumento=Objeto.addAumento(salario);
    }
}