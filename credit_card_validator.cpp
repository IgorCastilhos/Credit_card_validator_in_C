//
// Created by igorc on 7/29/2023.
//
#include <iostream>
using namespace std;

/*
 * Luhn Algorithm
 * ---------------
 * 1. Dobra cada segundo dígito da direita pra esquerda.
 * Se o número dobrado for de 2 dígitos, divida eles.
 * 2. Adicione todos os dígitos únicos do passo 1.
 * 3. Adicione todos os dígitos ímpares da direita para a esquerda
 * 4. Some resultados dos passo 2 & 3
 * 5. Se o passo 4 for divisível por 10, o número é válido
 *
 * 6011 0009 9013 9424
 * 1 2 2  0 0  1 8 2  1 8 4
 * Soma de todos os números = 29
 *
 * 6011 0009 9013 9424
 * 0 1  0 9  0 3  4 4
 * Soma de todos os números ímpares da direita pra esquerda = 21
 * 29 + 21 = 50
 * 50 % 10 = valid
 */

int getDigit(const int number);
int sumOddDigits(const string cardNumber);
int sumEvenDigits(const string cardNumber);

int main() {

    string cardNumber;
    int result = 0;

    cout<<"Enter a credit card #: ";
    cin>>cardNumber;

    result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);

    if (result % 10 == 0) {
        cout<<cardNumber<<" is valid";
    }else {
        cout<<cardNumber<<" is not valid";
    }

    return 0;
}

int getDigit(const int number){
    return number % 10 + (number / 10 % 10);
};
int sumOddDigits(const string cardNumber){
    int sum = 0;  // Observar a soma

    // Iterar o número de cartão em ordem reversa

    for (int i = cardNumber.size() - 1; i >= 0; i-=2) {
        sum += cardNumber[i] - '0';
    }

    return sum;
    return 0;
};
int sumEvenDigits(const string cardNumber){
   int sum = 0;  // Observar a soma

   // Iterar o número de cartão em ordem reversa

    for (int i = cardNumber.size() - 2; i >= 0; i-=2) {
        sum += getDigit((cardNumber[i] - '0') * 2);
    }

    return sum;
};