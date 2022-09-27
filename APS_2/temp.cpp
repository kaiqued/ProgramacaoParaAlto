#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <string.h>

using namespace std;

struct ContagemDeLetras
{
    unsigned char letra;
    int contagem;
    ContagemDeLetras *prox;
};

// ----------------------- //
// Protótipos das Funções: //
// ----------------------- //

// Função que recebe uma letra e retorna esta letra sem acentos
unsigned char LimpaAcento(unsigned char letter);

// Função que converte uma string ou um char para UTF8
string iso_8859_1_to_utf8(string str);
string iso_8859_1_to_utf8(unsigned char it);

// Função que abre um arquivo e retorna um vetor contendo as linhas deste
vector<string> OpenFile(char *fileName);

// ------------ //
// Função Main: //
// ------------ //
int main()
{
    vector<string> Municipios;

    Municipios = OpenFile("./APS_2/Lista_Municípios_com_IBGE_Brasil.txt");

    // Exercício 2:
    int contSemAcento[255];
    for (int i{0}; i < Municipios.size(); ++i)
    {
        string municipio{Municipios.at(i)};

        for (unsigned char letra : municipio)
        {
            ++contSemAcento[toupper(LimpaAcento(letra))];
        }
    }
    cout << contSemAcento[0x41];



    return 0;
}

unsigned char LimpaAcento(unsigned char letter)
{
    if (letter > 0xC0)
    {
        letter = (letter & 0xDF);
        switch (letter)
        {
        case 0xC1:
        case 0xC2:
        case 0xC3:
        case 0xC4:
            letter = 'A';
            break;
        case 0xC7:
            letter = 'C';
            break;
        case 0xC8:
        case 0xC9:
        case 0xCA:
        case 0xCB:
            letter = 'E';
            break;
        case 0xCC:
        case 0xCD:
        case 0xCE:
        case 0xCF:
            letter = 'I';
            break;
        case 0xD2:
        case 0xD3:
        case 0xD4:
        case 0xD5:
        case 0xD6:
            letter = 'O';
            break;
        case 0xD9:
        case 0xDA:
        case 0xDB:
        case 0xDC:
            letter = 'U';
            break;
        }
    }
    else
    {
        return letter;
    }

    return letter;
}

string iso_8859_1_to_utf8(string str)
{
    string strOut;
    for (string::iterator it = str.begin(); it != str.end(); ++it)
    {
        uint8_t ch = *it;
        if (ch < 0x80)
        {
            strOut.push_back(ch);
        }
        else
        {
            strOut.push_back(0xc0 | ch >> 6);
            strOut.push_back(0x80 | (ch & 0x3f));
        }
    }
    return strOut;
}

string iso_8859_1_to_utf8(unsigned char ch)
{
    string strOut;
    if (ch < 0x80)
    {
        strOut.push_back(ch);
    }
    else
    {
        strOut.push_back(0xc0 | ch >> 6);
        strOut.push_back(0x80 | (ch & 0x3f));
    }
    return strOut;
}

vector<string> OpenFile(char *fileName)
{
    string line;
    ifstream myfile(fileName);
    vector<string> temp;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            temp.push_back(line);
        }
        myfile.close();
        return temp;
    }

    else
        cout << "Unable to open file";
}
