#include <stdio.h>

struct Candidato {
	
    char nome[100];
    char cpf[100];
    
};

int comparaNome(const Candidato &c1, const Candidato &c2) {
    int i = 0;
    while (c1.nome[i] && c2.nome[i]) {
        if (c1.nome[i] != c2.nome[i])
            return c1.nome[i] - c2.nome[i];
        i++;
    }
    return c1.nome[i] - c2.nome[i];
}

int comparaCPF(const Candidato &c1, const Candidato &c2) {
	
    int i = 0;
    while (c1.cpf[i] && c2.cpf[i]) {
        if (c1.cpf[i] != c2.cpf[i])
            return c1.cpf[i] - c2.cpf[i];
        i++;
    }
    return c1.cpf[i] - c2.cpf[i];
    
}

int main() {
	
    Candidato candidatos[100];
    int numCandidatos = 0;
    char opcao;

    do {
    	
        printf("Digite o nome do candidato: ");
        scanf("%s", candidatos[numCandidatos].nome);
        printf("Digite o CPF do candidato: ");
        scanf("%s", candidatos[numCandidatos].cpf);
        numCandidatos++;

        printf("Deseja adicionar outro candidato? (S/N): ");
        scanf(" %c", &opcao);
    } while (opcao == 'S' || opcao == 's');

    printf("Deseja classificar por nome (N) ou CPF (C)? ");
    scanf(" %c", &opcao);

    if (opcao == 'N' || opcao == 'n') {
    	
        printf("Ordem crescente (C) ou decrescente (D)? ");
        scanf(" %c", &opcao);

        if (opcao == 'C' || opcao == 'c') {
        	
            for (int i = 0; i < numCandidatos - 1; i++) {
                for (int j = i + 1; j < numCandidatos; j++) {
                    if (comparaNome(candidatos[j], candidatos[i]) < 0) {
                        Candidato temp = candidatos[i];
                        candidatos[i] = candidatos[j];
                        candidatos[j] = temp;
                    }
                }
            }
            
        } else {
        	
            for (int i = 0; i < numCandidatos - 1; i++) {
                for (int j = i + 1; j < numCandidatos; j++) {
                    if (comparaNome(candidatos[j], candidatos[i]) > 0) {
                        Candidato temp = candidatos[i];
                        candidatos[i] = candidatos[j];
                        candidatos[j] = temp;
                    }
                }
            }
        }
        
    } else {
    	
        printf("Ordem crescente (C) ou decrescente (D)? ");
        scanf(" %c", &opcao);

        if (opcao == 'C' || opcao == 'c') {
        	
            for (int i = 0; i < numCandidatos - 1; i++) {
                for (int j = i + 1; j < numCandidatos; j++) {
                    if (comparaCPF(candidatos[j], candidatos[i]) < 0) {
                        Candidato temp = candidatos[i];
                        candidatos[i] = candidatos[j];
                        candidatos[j] = temp;
                    }
                }
            }
        } else {
        	
            for (int i = 0; i < numCandidatos - 1; i++) {
                for (int j = i + 1; j < numCandidatos; j++) {
                    if (comparaCPF(candidatos[j], candidatos[i]) > 0) {
                        Candidato temp = candidatos[i];
                        candidatos[i] = candidatos[j];
                        candidatos[j] = temp;
                    }
                }
            }
            
        }
        
    }
    
    printf("Lista de candidatos:\n");
    
    for (int i = 0; i < numCandidatos; i++) {
    	
        printf("Nome: %s, CPF: %s\n", candidatos[i].nome, candidatos[i].cpf);
        
    }

    return 0;
    
}


