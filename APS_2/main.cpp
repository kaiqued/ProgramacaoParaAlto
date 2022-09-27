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

// Função que recebe os nomes dos municípios, limpa os acentos, torna todas as letras maiúsculas
// e retorna quantas vezes cada letra aparece no conjunto
void Exercicio_2(vector<string> Municipios, ContagemDeLetras *&Contagem);

// Função que recebe os nomes dos municípios
// e retorna quantas vezes cada letra aparece no conjunto
void Exercicio_4(vector<string> Municipios, ContagemDeLetras *&Contagem);

void inserirLetra(ContagemDeLetras *&head, unsigned char letra, int contagem);
void imprimirContagens(ContagemDeLetras *&head);
void OrdenarContagens(ContagemDeLetras *&head);


// ------------ //
// Função Main: //
// ------------ //
int main()
{
    vector<string> Municipios;

    Municipios = OpenFile("./APS_2/Lista_Municípios_com_IBGE_Brasil.txt");

    // Exercício 2:
    ContagemDeLetras *letrasSemAcento{nullptr};

    Exercicio_2(Municipios, letrasSemAcento);
    
    imprimirContagens(letrasSemAcento);


    // Exercício 3:
    OrdenarContagens(letrasSemAcento);

    imprimirContagens(letrasSemAcento);


    // Exercício 4:
    ContagemDeLetras *letrasComAcento{nullptr};

    Exercicio_4(Municipios, letrasComAcento);

    imprimirContagens(letrasComAcento);

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

void Exercicio_2(vector<string> Municipios, ContagemDeLetras *&Contagem)
{

    vector<unsigned char> letrasNoDocumento;
    vector<int> contagem;

    for (int i{0}; i < Municipios.size(); ++i)
    {
        string municipio{Municipios.at(i)};

        for (unsigned char letra : municipio)
        {
            unsigned char letraLimpa{toupper(LimpaAcento(letra))};

            bool ExisteNaContagem{false};
            int Index{0};
            for (; Index < letrasNoDocumento.size(); ++Index)
            {
                if (letraLimpa == letrasNoDocumento.at(Index))
                {
                    ExisteNaContagem = true;
                    break;
                }
            }
            if (!ExisteNaContagem)
            {
                letrasNoDocumento.push_back(letraLimpa);
                contagem.push_back(1);
            }
            else
            {
                contagem.at(Index) += 1;
            }
        }
    }
    for (int i = 0; i < letrasNoDocumento.size(); i++)
    {
        inserirLetra(Contagem, letrasNoDocumento[i], contagem[i]);
    }
}

void Exercicio_4(vector<string> Municipios, ContagemDeLetras *&Contagem)
{

    vector<unsigned char> letrasNoDocumento;
    vector<int> contagem;

    for (int i{0}; i < Municipios.size(); ++i)
    {
        string municipio{Municipios.at(i)};

        for (unsigned char letra : municipio)
        {

            bool ExisteNaContagem{false};
            int Index{0};
            for (; Index < letrasNoDocumento.size(); ++Index)
            {
                if (letra == letrasNoDocumento.at(Index))
                {
                    ExisteNaContagem = true;
                    break;
                }
            }
            if (!ExisteNaContagem)
            {
                letrasNoDocumento.push_back(letra);
                contagem.push_back(1);
            }
            else
            {
                contagem.at(Index) += 1;
            }
        }
    }
    for (int i = 0; i < letrasNoDocumento.size(); i++)
    {
        inserirLetra(Contagem, letrasNoDocumento[i], contagem[i]);
    }
}

void inserirLetra(ContagemDeLetras *&head, unsigned char letra, int contagem)
{

    ContagemDeLetras *novo;
    novo = new ContagemDeLetras;
    novo->letra = letra;
    novo->contagem = contagem;
    novo->prox = nullptr;

    if (head == nullptr)
    {
        head = novo;
    }
    else
    {
        ContagemDeLetras *m{head};
        while (m->prox != nullptr)
        {
            m = m->prox;
        }
        m->prox = novo;
    }
}

void imprimirContagens(ContagemDeLetras *&head)
{
    ContagemDeLetras *m{head};
    while (m != nullptr)
    { // Também funciona while(! m)
        cout << iso_8859_1_to_utf8(m->letra) << ": " << m->contagem << endl;
        m = m->prox;
    }
}

void OrdenarContagens(ContagemDeLetras *&head)
{
    int sizeOfHead {0};

    ContagemDeLetras *teste{head};
    while (teste != nullptr)
    {
        sizeOfHead+=1;
        teste = teste->prox;
    }


    for (int i{0}; i < sizeOfHead;++i)
    {
        ContagemDeLetras *m{head};
        while (m->prox != nullptr)
        {
            if (m->contagem < m->prox->contagem)
            {
                ContagemDeLetras temp{*m};
                m->contagem = m->prox->contagem;
                m->letra = m->prox->letra;

                m->prox->contagem = temp.contagem;
                m->prox->letra = temp.letra;
            }
            m = m->prox;
        }
    }
}