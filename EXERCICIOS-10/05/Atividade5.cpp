#include <iostream>

class Funcionario {
    public:
    Funcionario(){}
    ~Funcionario(){}
    void setSalario (float _salario){
        salario=_salario;
    }
    float DescontoImposto (float salario, float imposto){
        salario=salario-imposto;
    }
    float AumentoBeneficio (float salario, float beneficio){
        salario=salario+beneficio;
    }
    private:
    float salario, imposto, beneficio;
};

int main(){
    Funcionario DescontoAumento;
    std::string nome, cargo;
    float salario, imposto, beneficio;
    std::cout <<"Qual o nome do funcionário? ";
    std::cin >> nome;
    std::cout <<"Qual o cargo do funcionário? ";
    std::cin >> cargo;
    std::cout <<"Qual o salário do funcionário? ";
    std::cin >> salario;
    DescontoAumento.setSalario (salario);
    std::cout <<"Qual o valor do imposto no salário do funcionário? ";
    std::cin >> imposto;
    std::cout <<"Qual o valor dos benefícios recebidos pelo funcionário? ";
    std::cin >> beneficio;
    salario=DescontoAumento.DescontoImposto(salario, imposto);
    salario=DescontoAumento.AumentoBeneficio(salario, beneficio);
    std::cout << "Nome: "<<nome<<"\nCargo: "<<cargo<<"\nSalário final: "<<salario;
}