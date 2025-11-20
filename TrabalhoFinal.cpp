// Arthur Drey Palma 

//Fluxo de urgencia de clinica


#include <iostream>
#include <algorithm>
#include <queue>



using namespace std;



struct Paciente {
    string nome;
    char prioridade;
    int hora;
    int minuto;
};





int tempomin(int h, int m){
    return h * 60 + m;
} // Função para calcular a espera em minutos






int main() {
  
   cout << " _______Menu de opções______ \n";
       
        cout << "Digite C para registrar a chegado do paciente " 
             << " Digite A para atender o proximo paciente " 
             << "Digite D para saber o estado atual das filas " 
             << "Digite Q para encerrar e receber o relatorio final " << "\n" ;
        
   
   
   
    queue<Paciente> V, A, D, B;

 
 int totalatendidos = 0;
 int atendP[4] = {0,0,0,0};
 int pico = 0;
 int esperamax = 0;

   
 
 
 char comandos; // painel de controle onde se seleciona a opção desejada
    while (true) {

     cin >> comandos ;

     switch (comandos) {  // separando com o switch case cada uma das opções 
       
        case 'C': {
        
        Paciente p;
         
         cin >> p.nome >> p.prioridade >> p.hora >> p.minuto ;

         switch (p.prioridade) {
            case 'V': V.push(p) ; break ;
            case 'A': A.push(p) ; break ;
            case 'D': D.push(p) ; break ;
            case 'B': B.push(p) ; break ;
         }

          
         
         int atual = V.size() + A.size() + D.size() + B.size() ;
            pico = max(pico, atual) ;
           
         break ;
        }

        
        
        
        
        case 'A': {
            
            int h, m ;
            
            cin >> h >> m ;

            if (V.empty() && A.empty() && D.empty() && B.empty()) {
                cout << h << " " << m << " Sem pacientes aguardando atendimento no momento\n" ; 
                
            break ; // Faz a vereficação das filas vazias, se tiverem retorna a msg
            }

            Paciente p ;
            
            int idx = 0 ;

            if (!V.empty()) { p = V.front(); V.pop() ; idx = 0 ; }
        
            else if (!A.empty()) { p = A.front() ; A.pop(); idx = 1 ; }
            
            else if (!D.empty()) { p = D.front() ; D.pop(); idx = 2 ; }
            
            else { p = B.front() ; B.pop() ; idx = 3 ; }

           
            
            int chegada = tempomin(p.hora, p.minuto) ;
            int agora = tempomin(h, m) ;
            int esperamax = agora - chegada ; // converte a hora em tempo de espera para minutos

            
            
            totalatendidos++ ;
            atendP[idx]++ ;
           
           
            break;
        }

        case 'D':
           
         cout << "V:" << V.size()
             << " A:" << A.size()
             << " D:" << D.size()
             << " B:" << B.size()
             << " | Atendidos:" << totalatendidos << "\n" ;
            
            
            break;

    
    
       case 'Q':
        cout << " RELATÓRIO FINAL \n";
        cout << "Total Atendidos: " << totalatendidos << "\n" ;
        cout << "Por Prioridade: V=" << atendP[0]
             << " A=" << atendP[1]
             << " D=" << atendP[2]
             << " B=" << atendP[3] << "\n" ;
        cout << "Pico de lotação: " << pico << "\n" ;
        cout << "Espera Maxima: " << esperamax << " min\n" ;
           
        return 0 ;

        }
    }

    return 0 ;
}