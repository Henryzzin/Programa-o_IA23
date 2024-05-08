#include <iostream>

    class Circulo{
        public:
            Circulo();
            ~Circulo();
            float calcularArea(){
                float area;
                area=3.14*(raio*raio);
                return area;
            }
            void setRaio(float raio2){
                raio=raio2;
            }
        private:
        float raio;
    };

int main (){
    Circulo conta;
    float area;
    float raio;
    std::cout<< "Digite o valor do raio: ";
    std::cin>>raio;
    conta.setRaio(raio);
    area=conta.calcularArea();
    std::cout<< area;
}