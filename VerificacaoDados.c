#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  char nome[50];
  char endereco[100];
  char dataNascimento[11];
  char cidade[50];
  char cep[10];
  char email[50];
} dados;

void obterDados(dados *dadosPessoais);

bool verificarDataNascimento(dados *dadosPessoais);

bool verificarCep(dados *dadosPessoais);

bool verificarEmail(dados *dadosPessoais);

void verificarGeral(dados *dadosPessoais);

int main(void) {

  dados dadosPessoais;
  obterDados(&dadosPessoais);
  verificarGeral(&dadosPessoais);
    
  
 return 0;
}

void obterDados(dados *dadosPessoais){
  printf("Nome: ");
  scanf(" %[^\n]", dadosPessoais->nome);
  printf("Endereço: ");
  scanf(" %[^\n]", dadosPessoais->endereco);
  printf("Data de nascimento (DD/MM/AAAA): ");
  scanf(" %[^\n]", dadosPessoais->dataNascimento);
  printf("Cidade: ");
  scanf(" %[^\n]", dadosPessoais->cidade);
  printf("CEP(xxxxx-yyy): ");
  scanf(" %[^\n]", dadosPessoais->cep);
  printf("Email: ");
  scanf(" %[^\n]", dadosPessoais->email);
};

bool verificarDataNascimento(dados *dadosPessoais){
  int dia, mes, ano;
  sscanf(dadosPessoais->dataNascimento, "%d/%d/%d", &dia,&mes,&ano);
  if(dia > 0 && dia <= 31 && mes > 0 && mes <= 12 && ano > 0){
    return true;
  } else {
    return false;
  }
}

bool verificarCep(dados *dadosPessoais){
  char cepDigitosPrincipais[6], cepSufixo[4];
  sscanf(dadosPessoais->cep, "%[^-]-%[^\n]", cepDigitosPrincipais, cepSufixo);

  int tamanhoDigitosPrincipais = strlen(cepDigitosPrincipais);
  int tamanhoSufixo = strlen(cepSufixo);

  if(tamanhoDigitosPrincipais == 5 && tamanhoSufixo == 3){
    return true;
  } else {
    return false;
  }
}

bool verificarEmail(dados *dadosPessoais){
  char emailVerificacao[50];
  char emailVerificacaoDominio[50];
  sscanf(dadosPessoais->email, " %[^@]@%[^\n]", emailVerificacao, emailVerificacaoDominio);

  if(strcmp(emailVerificacaoDominio, "xxxxx.com") == 0 || strcmp(emailVerificacaoDominio, "xxxxxxx.com") == 0){
    return true;
  } else {
    return false;
  }
}

void verificarGeral(dados *dadosPessoais){
  bool verDN = verificarDataNascimento(dadosPessoais);
  bool verCEP = verificarCep(dadosPessoais);
  bool verEmail = verificarEmail(dadosPessoais);

  if(verDN == true && verCEP == true && verEmail == true){
    printf("\n*Dados verificados com sucesso!*\n");
    printf("Nome: %s\n", dadosPessoais->nome);
    printf("Endereço: %s\n", dadosPessoais->endereco);
    printf("Data de nascimento: %s\n", dadosPessoais->dataNascimento);
    printf("Cidade: %s\n", dadosPessoais->cidade);
    printf("CEP: %s\n", dadosPessoais->cep);
    printf("Email: %s\n", dadosPessoais->email);
  } else {
    printf("\nErro na verificação do(s) dado(s):\n");
     if(verDN == false){
       printf("*Data de nascimento*\n");
     } else if(verCEP == false){
       printf("*CEP*\n");
     } else if(verEmail == false){
       printf("*Email*\n");
     }
  }
}
