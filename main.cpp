#include <iostream>
#include <stdlib.h>

using namespace std;

int menu();
float numeroConcat(float a, float b);

void funcionSuma();
float calculoSuma(float Operador_1,float Operador_2);

void funcionResta();
float calculoResta(float Operador_1,float Operador_2);

void funcionMultiplicacion();
float calculoMultiplicacion(float Operador_1,float Operador_2);

void funcionDivicion();
float calculoDivicion(float Operador_1,float Operador_2);

void funcionRaiz();
int calculoRaiz(int Valor);

void funcionExponencial();
int calculoExponencial(int Base,int Exponente);

void funcionSeno();
float calculoSeno(float angulo);

void funcionCoseno();
float calculoCoseno(float angulo);

void funcionTangente();
float calculoTangente(float angulo);

void funcionSecante();
float calculoSecante(float angulo);

void funcionCosecante();
float calculoCosecante(float angulo);

void funcionCotangente();
float calculoCotangente(float angulo);

int main() {
    bool salir = false;
    do {
        switch(menu()) {
        case 1: {
            funcionSuma();
            break;
        }
        case 2: {
            funcionResta();
            break;
        }
        case 3: {
            funcionMultiplicacion();
            break;
        }
        case 4: {
            funcionDivicion();
            break;
        }
        case 5: {
            funcionExponencial();
            break;
        }
        case 6: {
            funcionRaiz();
            break;
        }
        case 7: {
            funcionSeno();
            break;
        }
        case 8: {
            funcionCoseno();
            break;
        }
        case 9: {
            funcionTangente();
            break;
        }
        case 10: {
            funcionCotangente();
            break;
        }
        case 11: {
            funcionSecante();
            break;
        }
        case 12: {
            funcionCosecante();
            break;
        }
        case 13: {
            salir = true;
            break;
        }
        default: {
            cout << "Valor introducido erroneo";
        }
        }
        system("PAUSE");
    } while(!salir);
    return 0;
}

int menu() {
    int opc;
    system("CLS");
    cout << " Calculadora" << endl << endl;
    cout << " 1) Suma" << endl;
    cout << " 2) Resta" << endl;
    cout << " 3) Multiplicacion" << endl;
    cout << " 4) Divicion" << endl;
    cout << " 5) Exponencial " << endl;
    cout << " 6) Raiz" << endl;
    cout << " 7) Seno " << endl;
    cout << " 8) Coseno " << endl;
    cout << " 9) Tangente " << endl;
    cout << " 10) Cotangente " << endl;
    cout << " 11) Secante " << endl;
    cout << " 12) Cosecante " << endl;
    cout << " 13) Salir " << endl;
    cout << " Ingresa una opcion:  ";
    cin >> opc;
    return opc;
}

/*----------------------Trigonometric Functions---------------*/
void funcionSeno() {
    float Angulo;
    cout << " Introduce el Angulo: ";
    cin  >> Angulo;
    cout << endl << endl << " Sen " << Angulo
         << "  Resultado: " << calculoSeno(Angulo) << endl;
}

float calculoSeno(float angulo) {
    float Respuesta,temp;
    Respuesta = 0;
    __asm__ (
        "FLD  %2;"
        "FSIN;"
        "FSTP %1;"
        : "=g" (temp)
        : "g" (Respuesta), "g" (angulo)
    );
    return Respuesta;
}

void funcionCoseno() {
    float Angulo;
    cout << " Introduce el Angulo: ";
    cin  >> Angulo;
    cout << endl << endl << " Cos " << Angulo
         << "  Resultado: " << calculoCoseno(Angulo) << endl;
}

float calculoCoseno(float angulo) {
    float Respuesta,temp;
    Respuesta = 0;
    __asm__ (
        "FLD  %2;"
        "FCOS;"
        "FSTP %1;"
        : "=g" (temp)
        : "g" (Respuesta), "g" (angulo)
    );
    return Respuesta;
}

void funcionTangente() {
    float Angulo;
    cout << " Introduce el Angulo: ";
    cin  >> Angulo;
    cout << endl << endl << " Tan " << Angulo
         << "  Resultado: " << calculoTangente(Angulo) << endl;
}

float calculoTangente(float angulo) {
    float Respuesta,temp,sen,cos;
    Respuesta = 0;

    sen = calculoSeno(angulo);
    cos = calculoCoseno(angulo);

    __asm__ (
        "FLD  %2;"
        "FDIV %3;"
        "FSTP %1;"
        : "=g" (temp)
        : "g" (Respuesta), "g" (sen), "g"(cos)
    );

    return Respuesta;
}

void funcionSecante() {
    float Angulo;
    cout << " Introduce el Angulo: ";
    cin  >> Angulo;
    cout << endl << endl << " Sec " << Angulo
         << "  Resultado: " << calculoSecante(Angulo) << endl;
}

float calculoSecante(float angulo) {
    float Respuesta,temp,sen,cos;
    Respuesta = 0;
    sen = 1;
    cos = calculoCoseno(angulo);

    __asm__ (
        "FLD  %3;"
        "FDIV %2;"
        "FSTP %1;"
        : "=g" (temp)
        : "g" (Respuesta), "g" (cos), "g"(sen)
    );

    return Respuesta;
}

void funcionCosecante() {
    float Angulo;
    cout << " Introduce el Angulo: ";
    cin  >> Angulo;
    cout << endl << endl << " Csc " << Angulo
         << "  Resultado: " << calculoCosecante(Angulo) << endl;
}

float calculoCosecante(float angulo) {
    float Respuesta,temp,sen,cos;
    Respuesta = 0;
    sen = calculoSeno(angulo);
    cos = 1;

    __asm__ (
        "FLD  %2;"
        "FDIV %3;"
        "FSTP %1;"
        : "=g" (temp)
        : "g" (Respuesta), "g" (cos), "g"(sen)
    );

    return Respuesta;

}

void funcionCotangente() {
    float Angulo;
    cout << " Introduce el Angulo: ";
    cin  >> Angulo;
    cout << endl << endl << " Cot " << Angulo
         << "  Resultado: " << calculoCotangente(Angulo) << endl;
}

float calculoCotangente(float angulo) {
    float Respuesta,temp,sen,cos;
    Respuesta = 0;

    sen = calculoSeno(angulo);
    cos = calculoCoseno(angulo);

    __asm__ (
        "FLD  %2;"
        "FDIV %3;"
        "FSTP %1;"
        : "=g" (temp)
        : "g" (Respuesta), "g" (cos), "g"(sen)
    );

    return Respuesta;
}

/*---------------------Basic Operation---------------------*/

void funcionSuma() {
    float Sumando_1,Sumando_2,Aux_2, Aux_1;
    cout << " introduce el Sumando 1: ";
    cin  >> Sumando_1;
    cout << " Introduce el Sumando 2: ";
    cin  >> Sumando_2;
    Aux_2 = Sumando_2;
    Aux_1 = Sumando_1;
    cout << endl << endl << " " << Sumando_1 << "+" << Sumando_2
         << "  Resultado: " << calculoSuma(Aux_1,Aux_2) << endl;
}

float calculoSuma(float Operador_1, float Operador_2) {
    float Respuesta,temp;
    Respuesta = 0;
    __asm__ (
        "FLD %2;"
        "FADD %3;"
        "FSTP %1;"
        : "=g" (temp)
        : "g" (Respuesta), "g" (Operador_1), "g" (Operador_2)
    );
    return Respuesta;
}

void funcionResta() {
    float Minuendo,Sustraendo,Aux_2, Aux_1;
    cout << " Introduce el Minuendo: ";
    cin  >> Minuendo;
    cout << " Introduce el Sustraendo: ";
    cin  >> Sustraendo;
    Aux_2 = Sustraendo;
    Aux_1 = Minuendo;
    cout << endl << endl << " " << Minuendo << "-" << Sustraendo
         << "  Resultado: " << calculoResta(Aux_1,Aux_2) << endl;
}

float calculoResta(float Operador_1, float Operador_2) {
    float Respuesta,temp;
    Respuesta = 0;
    __asm__ (
        "FLD %2;"
        "FSUB %3;"
        "FSTP %1;"
        : "=g" (temp)
        : "g" (Respuesta), "g" (Operador_1), "g" (Operador_2)
    );
    return Respuesta;
}

void funcionMultiplicacion() {
    float multiplicando,multiplicador,Aux_2, Aux_1;
    cout << " Introduce el Multiplicando: ";
    cin  >> multiplicando;
    cout << " Introduce el Multiplicador: ";
    cin  >> multiplicador;
    Aux_2 = multiplicador;
    Aux_1 = multiplicando;
    cout << endl << endl << " " << multiplicando << "*" << multiplicador
         << "  Resultado: " << calculoMultiplicacion(Aux_1,Aux_2) << endl;
}

float calculoMultiplicacion(float Operador_1, float Operador_2) {
    float Respuesta,temp;
    Respuesta = 0;
    __asm__ (
        "FLD %2;"
        "FMUL %3;"
        "FSTP %1;"
        : "=g" (temp)
        : "g" (Respuesta), "g" (Operador_1), "g" (Operador_2)
    );
    return Respuesta;
}

void funcionDivicion() {
    float Dividendo,Divisor,Aux1, Aux2;
    cout << " Introduce el dividendo: ";
    cin  >> Dividendo;
    cout << " Introduce el divisor: ";
    cin  >> Divisor;
    if(Divisor != 0) {
        Aux1 = Divisor;
        Aux2 = Dividendo;
        cout << endl << endl << " " << Dividendo << "/" << Divisor
             << "  Resultado: " << calculoDivicion(Aux2,Aux1) << endl;
    } else {
        cout << " Division invalida" << endl;
    }
}

float calculoDivicion(float Operador_1, float Operador_2) {
    float Respuesta,temp;
    Respuesta = 0;
    __asm__ (
        "FLD %2;"
        "FDIV %3;"
        "FSTP %1;"
        : "=g" (temp)
        : "g" (Respuesta), "g" (Operador_1), "g" (Operador_2)
    );
    return Respuesta;
}

/*--------------------------------------------------------FUNCIONES ENTERAS----------------------------------------------------------*/

void funcionRaiz() {
    int Valor;
    cout << " Introduce un valor: ";
    cin  >> Valor;
    if(Valor == 0) {
        cout<< endl << endl << " La raiz de:  " << Valor << endl
            << "  Resultado: 0" << endl;
    } else if(Valor > 0) {
        cout<< endl << endl << " La raiz de:  " << Valor << endl
            << "  Resultado: " << calculoRaiz(Valor) << endl;
    } else {
        cout << "Valor invalido" << endl;
    }
}

int calculoRaiz(int Valor) {
    int Respuesta = 0;
    __asm__ (
        "xorl %%eax, %%eax;"/// Limpieza de registros
        "xorl %%ebx, %%ebx;"
        "xorl %%ecx, %%ecx;"
        "xorl %%edx, %%edx;"

        "siguiente:"      /// Diferente de 0
        "incl %%ebx;"
        "movl %%ebx, %%eax;"
        "mull %%eax;"
        "movl %1, %%edx;"
        "cmpl %%edx, %%eax;"
        "jbe siguiente;"

        "movl %%ebx, %0;"    /// Guardado de eax en Resutado

        /// Variables
        : "=g" (Respuesta)
        : "g" (Valor)/// 1 = Valor
    );
    return Respuesta - 1;
}

void funcionExponencial() {
    int Base,Exponente,Aux;
    cout << " Introduce la base: ";
    cin  >> Base;
    cout << " Introduce el Exponente: ";
    cin  >> Exponente;
    Aux = Base;
    if (Base < 0) {
        Aux *= -1;
    }

    if(Exponente >= 0) {
        cout << endl << endl << " " << Base << "^" << Exponente
             << "  Resultado: " << calculoExponencial(Aux,Exponente) << endl;
    } else {
        cout << "Exponente invalido" << endl;
    }
}

int calculoExponencial(int Base, int Exponente) {
    int Respuesta;
    __asm__ (
        "xorl %%eax, %%eax;"/// Limpieza de registros
        "xorl %%ebx, %%ebx;"
        "xorl %%ecx, %%ecx;"
        "xorl %%edx, %%edx;"

        "mov  $0, %%eax;"

        "cmpl %2, %%eax;"   /// Comparacion con expoenete 0
        "je   cero;"
        "jne   exponencial;"

        "cero:"             /// Si es 0
        "movl $1, %%eax;"
        "jmp  fin;"

        "exponencial:"      /// Diferente de 0
        "movl %1, %%eax ;"
        "movl %2, %%ecx;"
        "decl %%ecx;"

        "f_exponencial:"    /// Calculo de exponente
        "mull %1;"
        "decl %%ecx;"
        "cmpl $0, %%ecx;"
        "ja f_exponencial;"

        "fin:"
        "movl %%eax,%0;"    /// Guardado de eax en Resutado

        /// Variables
        : "=g" (Respuesta)
        : "g" (Base), "g" (Exponente) /// 1 = Base   2 = Exponente
    );
    return Respuesta;
}
