#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <stdio.h>

//Função que define o comportamento da janela - sua aparencia, como interage com o usuário, etc
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


/*
*   Função Windows Main da API
    Substitui a função Main padrão

    HINSTANCE hInstance: handle para a instância da aplicação
*/
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    //Variável do tipo wchar_t (16 bits utilizado para caracteres Unicode UTF-16LE)
    const wchar_t CLASS_NAME[] = L"First Window Class";

    //Criação da classe Window
    WNDCLASS windowClass = {};
    //Ponteiro para uma função "window procedure" que realiza o comportament da janela
    windowClass.lpfnWndProc = WindowProc;
    //handle para a instância da aplicação
    windowClass.hInstance = hInstance;
    //String que identifica o nome da classe
    windowClass.lpszClassName = CLASS_NAME;
    /*  Define elementos adicionais para a classe da janela
    *   Ver: https://docs.microsoft.com/en-us/windows/win32/winmsg/window-class-styles
    */
    windowClass.style = 0x0020;

    //Registra a clase
    RegisterClass(&windowClass);

    /*
        Cria uma nova janela
        Ver: https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowexa
    */
    HWND handleWindow = CreateWindowEx(
        0,                          //Define elementos adicionais para a janela 
        CLASS_NAME,                 //Nome da classe de uma janela previamente registrada a partir de "RegisterClass"
        L"First Window Created",    //Nome da janela (Nome da barra de titulo, caso especificado no estilo)
        WS_EX_CLIENTEDGE,           //Define elementos adicionais para a janela

        CW_USEDEFAULT,              //Posição horizontal inicial
        CW_USEDEFAULT,              //Posição vertical inicial
        CW_USEDEFAULT,              //Comprimento da janela
        CW_USEDEFAULT,              //Altura da janela

        NULL,                       //Handle para a janela pai ou dona da janela sendo criada.
        NULL,                       //Handle para um menu ou para o identificador de uma janela filha
        hInstance,                  //Handle para instância do modulo sendo associado à janela
        NULL                        //Ponteiro para um valor à ser passado para a janela
    );


    if (handleWindow == NULL)
        return 0;

    /* 
        Torna a janela visível 
        
        handleWindow - o handle da janela criada em CreateWindowEx
        nCmdShow - usado para minimizar ou maximizar a janela
    */
    ShowWindow(handleWindow, nCmdShow);

    return 1;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    return 1;
}