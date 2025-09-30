void exibir_menu() {

  printf("\n========================================\n");
  printf("          QUIZ CONHECIMENTOS GERAIS\n");
  printf("========================================\n");
  printf("1 - Iniciar Quiz\n");
  printf("2 - Ver Regras\n");
  printf("3 - Sair\n");
  printf("========================================\n");
}

void exibir_regras() {

  printf("\n========================================\n");
  printf("           REGRAS DO QUIZ\n");
  printf("========================================\n");
  printf("• O quiz possui 5 perguntas\n");
  printf("• Cada pergunta tem 3 alternativas (a, b, c)\n");
  printf("• Cada resposta correta vale 2 pontos\n");
  printf("• A pontuação máxima é 10 pontos\n");
  printf("• Ao final, você receberá um comentário\n");
  printf("  sobre seu desempenho\n");
  printf("========================================\n");
  printf("\nPressione Enter para voltar ao menu...");
  getchar();
  while (getchar() != '\n')
    ;
}

int executar_quiz() {

  char *perguntas[] = {"Qual é a capital do Brasil?",
                       "Quantos planetas existem no sistema solar?",
                       "Quem escreveu 'Dom Casmurro'?",
                       "Qual é o maior oceano do mundo?",
                       "Em que ano o homem pisou na Lua pela primeira vez?"};

  char *alternativas[][3] = {
      {"Rio de Janeiro", "Brasília", "São Paulo"},
      {"7", "8", "9"},
      {"Machado de Assis", "José de Alencar", "Lima Barreto"},
      {"Atlântico", "Índico", "Pacífico"},
      {"1965", "1969", "1972"}};

  char respostas_corretas[] = {'b', 'b', 'a', 'c', 'b'};

  int pontuacao = 0;
  char resposta;
  int i;

  printf("\n========================================\n");
  printf("          INICIANDO QUIZ\n");
  printf("========================================\n");

  for (i = 0; i < 5; i++) {
    printf("\nPergunta %d: %s\n", i + 1, perguntas[i]);
    printf("Alternativas:\n");
    printf("  a) %s\n", alternativas[i][0]);
    printf("  b) %s\n", alternativas[i][1]);
    printf("  c) %s\n", alternativas[i][2]);

    while (1) {
      printf("\nSua resposta (a/b/c): ");
      scanf(" %c", &resposta);

      resposta = tolower(resposta);

      if (resposta == 'a' || resposta == 'b' || resposta == 'c') {
        break;
      } else {
        printf("Por favor, digite apenas 'a', 'b' ou 'c'\n");
        while (getchar() != '\n')
          ;
      }
    }

    if (resposta == respostas_corretas[i]) {
      printf("✓ Resposta correta! +2 pontos\n");
      pontuacao += 2;
    } else {
      printf("✗ Resposta incorreta! A correta era: %c\n",
             respostas_corretas[i]);
    }
  }

  return pontuacao;
}

void exibir_resultado(int pontuacao) {

  printf("\n========================================\n");
  printf("          RESULTADO FINAL\n");
  printf("========================================\n");
  printf("Sua pontuação: %d/10 pontos\n", pontuacao);

  if (pontuacao <= 4) {
    printf("💡 Precisa estudar mais!\n")
  } else if (pontuacao <= 8) {
    printf("👍 Muito bem!\n")
  } else {
    printf("🎉 Excelente, parabéns!\n")
  }
  printf("========================================\n");
}

int main() {

  int pontuacao;
  char opcao[2];
  char jogar_novamente[2];

  printf("Bem-vindo ao Quiz de Conhecimentos Gerais!\n");

  while (1) {
    exibir_menu();

    printf("\nEscolha uma opção (1-3): ");
    scanf("%1s", opcao);
    while (getchar() != '\n')
      ;

    if (strcmp(opcao, "1") == 0) {

      pontuacao = executar_quiz();
      exibir_resultado(pontuacao);

      while (1) {
        printf("\nDeseja jogar novamente? (s/n): ");
        scanf("%1s", jogar_novamente);
        while (getchar() != '\n')
          ;

        if (strcmp(jogar_novamente, "s") == 0 ||
            strcmp(jogar_novamente, "n") == 0) {
          break;
        } else {
          printf("Por favor, digite 's' para sim ou 'n' para não\n");
        }
      }

      if (strcmp(jogar_novamente, "n") == 0) {
        printf("\nObrigado por jogar! Até a próxima!\n");
        break;
      }
    } else if (strcmp(opcao, "2") == 0) {

      exibir_regras();
    } else if (strcmp(opcao, "3") == 0) {

      printf("\nObrigado por jogar! Até a próxima!\n");
      break;
    } else {
      printf("\nOpção inválida! Por favor, escolha 1, 2 ou 3.\n");
    }
  }

  return 0;
}
