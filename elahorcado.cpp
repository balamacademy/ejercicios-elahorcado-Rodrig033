#include <iostream>
#include <string>
using namespace std;

bool letraYaIntentada(char letra, string letras);
// Muestra la palabra oculta, con las letras adivinadas: 
void mostrarPalabraOculta(string palabra_oculta){
    cout << "\nPalabra: " << palabra_oculta << endl;
}
// Letras incorrectas:
void mostrarLetrasIncorrectas(string letras_erroneas){
    cout << "Letras erroneas: " << letras_erroneas << endl;
}

// Vidas restantes:
void mostrarVidas(short int intentos){
    cout << "Vidas: " << intentos << endl;
}

//

// Función que evalúa la letra y actualiza variables según sea correcta, incorrecta o repetida:
void evaluarLetra(
    char letra,
    string palabra_adivinar,
    string& palabra_oculta,
    string& letras_correctas,
    string& letras_erroneas,
    short int& intentos
) {
    bool letra_correcta = false;

    if (letraYaIntentada(letra, letras_correctas) || letraYaIntentada(letra, letras_erroneas))
    {
        cout << "Ya has intentado con esa letra.\n";
        return;
    }
    

    // Comprobar si la letra está en la palabra
    for (int i = 0; i < palabra_adivinar.length(); i++) {
        if (palabra_adivinar[i] == letra) {
            palabra_oculta[i] = letra;
            letra_correcta = true;
        }
    }

    if (letra_correcta) {
        letras_correctas += letra;
        cout << "\n¡¡Bien hecho, sigue así!!\n";
    } else {
        letras_erroneas += letra;
        intentos--;
        cout << "Opps, la letra no está en la palabra.\n";
    }
}


void dibujarAhorcado(int vidas) {
    switch (vidas) {
        case 7:
            cout << "\n\n +---+\n"
                    " |   |\n"
                    "     |\n"
                    "     |\n"
                    "     |\n"
                    "     |\n"
                    "=========\n";
            break;
        case 6:
            cout << "\n\n +---+\n"
                    " |   |\n"
                    " O   |\n"
                    "     |\n"
                    "     |\n"
                    "     |\n"
                    "=========\n";
            break;
        case 5:
            cout << "\n\n +---+\n"
                    " |   |\n"
                    " O   |\n"
                    " |   |\n"
                    "     |\n"
                    "     |\n"
                    "=========\n";
            break;
        case 4:
            cout << "\n\n +---+\n"
                    " |   |\n"
                    " O   |\n"
                    "/|   |\n"
                    "     |\n"
                    "     |\n"
                    "=========\n";
            break;
        case 3:
            cout << "\n\n +---+\n"
                    " |   |\n"
                    " O   |\n"
                    "/|\\  |\n"
                    "     |\n"
                    "     |\n"
                    "=========\n";
            break;
        case 2:
            cout << "\n\n +---+\n"
                    " |   |\n"
                    " O   |\n"
                    "/|\\  |\n"
                    "/    |\n"
                    "     |\n"
                    "=========\n";
            break;
        case 1:
            cout << "\n\n +---+\n"
                    " |   |\n"
                    " O   |\n"
                    "/|\\  |\n"
                    "/ \\  |\n"
                    "     |\n"
                    "=========\n";
            break;
        case 0:
            cout << "\n\n +---+\n"
                    " |   |\n"
                    " [X] |\n"
                    "/|\\  |\n"
                    "/ \\  |\n"
                    "     |\n"
                    "=========\n";
            break;
    }
}

bool letraYaIntentada(char letra, string letras){
    for (int i = 0; i < letras.length(); i++)
    {
        if (letras[i] == letra)
        {
            return true;
        }
    }
    return false;
}

int main() {
    // Variables
    string palabra_adivinar = "programacion";
    string palabra_oculta = "____________";
    short int intentos = 7;
    string letras_erroneas = "";
    string letras_correctas = "";
    char letra;

    cout << "¡¡Hola, bienvenido al ahorcado!!";

    while (intentos > 0 && palabra_oculta != palabra_adivinar) {
        mostrarPalabraOculta(palabra_oculta);
        mostrarLetrasIncorrectas(letras_erroneas);
        mostrarVidas(intentos);
        dibujarAhorcado(intentos);

        // Entrada de usuario:
        cout << "Ingresa una letra: ";
        cin >> letra;

        // Evaluar la letra
        evaluarLetra(letra, palabra_adivinar, palabra_oculta, letras_correctas, letras_erroneas, intentos);

        // Verificar si ya ganó o perdió
        if (palabra_oculta == palabra_adivinar) {
            cout << "\n¡Felicidades! Has salvado a Michael de las manos del capitalismo...\n";
            cout <<  "(❛ ͜ʖ❛)" << endl;
            cout << "- | -" << endl;
            cout << " / \\  " << endl;
            break;
        }

        if (intentos == 0) {
            cout << "\nHas perdido, Michael cayó en las manos del capitalismo...\n";
            cout << "La palabra secreta era: " << palabra_adivinar << endl;
        }
    }

    return 0;
}