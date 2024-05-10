#include <iostream>
#define pi 3.14

    class Circulo{
        public:
            Circulo(){};
            ~Circulo(){};
            float calcularArea(){
                float area;
                area=pi*(raio*raio);
                return area;
            }
            float calcularPerimetro(){
                float perimetro;
                perimetro=pi*2*raio;
                return perimetro;
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
    float perimetro;
    float raio;
    std::cout<< "Digite o valor do raio em metros: ";
    std::cin>>raio;
    conta.setRaio(raio);
    area=conta.calcularArea();
    perimetro=conta.calcularPerimetro();
    std::cout<< "A área é de " << area << " metros.\n";
    std::cout<< "O perímetro é de " << perimetro << " metros.\n";
}