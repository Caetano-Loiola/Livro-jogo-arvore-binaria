#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "gamebook.h"
#include "abb.h"

typedef struct output
{
    int id;
    char *txt;
} Output;

typedef struct no
{

    Output dado;
    struct no *esq;
    struct no *dir;
} No;

void strmalloc(char **str, char txt[])
{
    *str = (char *)malloc((sizeof(char)) * (strlen(txt) + 1));
    if (*str == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    strcpy(*str, txt);
}

void gbprintf(const char *color, const char *str)
{
    printf("%s", color); // Inicia a cor
    for (int i = 0; i < strlen(str); i++)
    {
        printf("%c", str[i]);
        fflush(stdout);
        Sleep(10); // Atraso de 10 ms entre cada caractere
    }
    printf("%s", RESET); // Reseta a cor ao final
}

void gbquit(No **t)
{
    int id[] = {FINAL, MORTE7, CAP7, MORTE6, CAP6, MORTE5, CAP5, MORTE4, CAP4, MORTE3, CAP3, MORTE2, CAP2, MORTE1, CAP1, PROLOGO};

    system("cls");
    gbprintf(RED BOLD, "\tarvore de decisoes:\n\n");

    emOrdem(*t);

    for (int i = 15; i > 0; i++)
    {
        cut(&t, id[i]);
    }
    Sleep(20000);
}

void gbchapter(Output *data)
{
    switch (data->id)
    {
    case (PROLOGO):
        strmalloc(&data->txt, "Bem-vindo ao mundo de Faerun, uma terra rica em tesouros, monstros e magia antiga. eh uma vasta regiao repleta de florestas ancestrais, montanhas e desfiladeiros perigosos e cidades antigas. Nossa historia comeca na cidade de Ravenshire, um porto movimentado conhecido por seus mercados exoticos e guildas de aventureiros. Voce eh Adrian, um meio-elfo guerreiro de origem baixa, criado como um orfao nas ruas de Ravenshire. Treinado desde jovem nas artes da espada, Adrian ganhou sua reputacao como um mercenario habilidoso. Seu principal objetivo eh encontrar Casselmann, um mago renomado da cidade de Ravenshire. Tudo o que voce sabe eh que ele estava investigando uma antiga masmorra da cidade, cujo nome se perdeu com o tempo, mas que se encontra abaixo do cemiterio da cidade de Ravenshire.\n\n");
        break;

    case (CAP1):
        strmalloc(&data->txt, "Ao cair da noite, voce se prepara para a jornada. Carregando apenas a sua espada, voce parte rumo a masmorra. O caminho eh sombrio, mostrando marcas de uma batalha de outrora pelo caminho, mas voce continua o seu caminho. Depois de algumas horas andando, voce finalmente chega a entrada da masmorra, uma abertura escura cravada na rocha, adornada por runas antigas e luminescentes ao redor da entrada. Quando voce se aproxima da entrada ve dois caminhos a sua frente.\n\n");
        break;

    case (MORTE1):
        strmalloc(&data->txt, "Voce decide seguir pelo corredor iluminado. a medida que avanca, o chao comeca a tremer e o teto desaba sobre voce. Sem tempo para reagir, voce eh esmagado pelos escombros, encontrando seu fim tragico na escuridao da masmorra.\n\n");
        break;

    case (CAP2):
        strmalloc(&data->txt, "Voce decide seguir pelo caminho da esquerda, sentindo que a trilha menos usada pode revelar segredos que o caminho principal nao mostraria. O corredor eh apertado e sinuoso, as marcas de garras nas paredes sao um lembrete do perigo a espreita. O som da agua corrente se torna cada vez mais alto, e logo voce se depara com um pequeno riacho subterraneo que atravessa seu caminho.\n\nCom cautela, voce observa a correnteza. A agua parece cristalina, mas a travessia nao sera facil. Procurando alguma passagem, voce decide pular sobre as pedras lisas que emergem do riacho. Seu treinamento lhe serve bem, pois voce atravessa com sucesso para o outro lado.\n\nDo outro lado, voce nota uma pequena abertura na parede, quase escondida pelas sombras. Ao se aproximar, percebe que eh um alcapao bem camuflado. Com um pouco de esforco, voce o abre e desce por uma escada de pedra antiga. A sala em que voce entra eh iluminada por cristais magicos que emanam uma luz suave. No centro, ha um bau antigo, decorado com runas elficas.\n\nAo inspecionar o mapa, voce percebe que ele contem anotacoes feitas a mao, provavelmente pelo mago Casselmann. Uma dessas anotacoes menciona uma camara secreta onde ele acreditava haver pistas sobre um artefato poderoso capaz de controlar as energias das sombras, vindas diretas do Pendor das Sombras, um plano paralelo a este, porehm tomado por energia amaldicoada.\n\nAgora, com o mapa em maos, voce se depara com duas rotas principais que levam a camara secreta mencionada:\n\n");
        break;

    case (MORTE2):
        strmalloc(&data->txt, "Voce decide atravessar a ponte de cristal. No entanto, a ponte nao suporta seu peso e se quebra no meio do caminho. Voce cai no abismo e eh engolido pela escuridao, encontrando uma morte tragica e prematura.\n");
        break;

    case (CAP3):
        strmalloc(&data->txt, "Decidido a seguir pela rota dos tuneis subterraneos, voce guarda o mapa e se prepara para enfrentar o que vier pela frente. Os tuneis sao estreitos e a escuridao eh quase total, mas os cristais que iluminam suas paredes proporcionam uma luz fraca o suficiente para guiar os seus passos.\n\nVoce avanca com cautela, empunhando sua espada, preparado para qualquer ameaca. Nao demora muito para que voce se depare com aranhas gigantes. Elas sao criaturas grotescas, com olhos multiplos e presas afiadas, movendo-se rapidamente pelas paredes do tunel.\n\nCom destreza e coragem, voce enfrenta as criaturas. Sua espada corta o ar e encontra seu alvo repetidas vezes. As aranhas caem uma a uma, ate que finalmente o tunel fica silencioso novamente. Voce prossegue, atento a qualquer movimento ao seu redor.\n\nApos o que parece ser uma eternidade, voce encontra uma passagem oculta atras de uma parede de teias espessas. Cortando as teias, voce revela uma porta de pedra com inscricoes antigas. A porta se abre rangendo, revelando um salao vasto e iluminado.\n\nVoce entra na camara secreta mencionada no mapa. No centro do salao, sobre um pedestal de marmore, repousa um artefato brilhante: um amuleto adornado com uma gema negra que emana uma aura sinistra. como um fragmento do Pendor das Sombras. Proximo ao pedestal, voce encontra um diario que pertenceu ao Casselmann. Folheando as paginas, voce descobre que ele estava investigando o poder do amuleto e acreditava que ele poderia ser a chave para controlar as sombras da masmorra.\n\nCom o amuleto em maos, voce sente uma presenca maligna se aproximando. O ar ao seu redor parece vibrar com energia sombria. Voce tem duas opcoes:\n\n");
        break;

    case (MORTE3):
        strmalloc(&data->txt, "Voce tenta fugir pela passagem secreta, mas a presenca maligna eh rapida demais. Uma sombra gigantesca surge e o agarra, esmagando voce com uma forca implacavel. Seus gritos ecoam pela camara enquanto a escuridao consome sua alma, levando-o a uma morte horrivel.\n\n");
        break;

    case (CAP4):
        strmalloc(&data->txt, "Decidido a enfrentar a presenca maligna, voce segura o Amuleto Umbral com firmeza. Concentrando-se, voce sente a energia do artefato pulsar atraves de seu corpo. As sombras ao seu redor comecam a se mover, contorcendo-se como se tivessem vida propria.\n\nA presenca maligna se revela como uma sombra gigantesca, uma entidade feita de pura escuridao que emana uma aura de terror. Sem hesitar, voce usa o amuleto para controlar as sombras, formando uma barreira protetora ao seu redor. A entidade se lanca contra voce, mas eh repelida pela forca do amuleto. A batalha eh intensa, mas aos poucos, a presenca maligna comeca a enfraquecer, ate que finalmente desaparece.\n\nVoce respira aliviado, sabendo que venceu esse obstaculo. No entanto, o poder do amuleto eh claro: ele eh tanto uma ferramenta quanto um fardo. Usa-lo requer grande concentracao e forca de vontade.\n\nCom o caminho livre, voce continua sua exploracao, guiado pelas anotacoes no diario de Casselmann. O mapa agora parece ainda mais valioso, oferecendo orientacoes precisas para areas da masmorra ainda inexploradas. Voce segue por um corredor que leva a um salao maior, onde um enorme portao de ferro se ergue, bloqueando o caminho adiante.\n\nO portao de ferro eh pesado e macico. Voce insere a chave na fechadura e a gira, ouvindo o clique de mecanismos antigos se movendo. O portao comeca a se abrir lentamente, revelando dois caminhos:\n\n");
        break;

    case (MORTE4):
        strmalloc(&data->txt, "Voce avanca pelo corredor das almas perdidas, mas os espiritos drenam sua energia vital rapidamente. Sem a protecao adequada, voce sucumbe a escuridao, perdendo sua vida e sua alma nas profundezas da masmorra.\n");
        break;

    case (CAP5):
        strmalloc(&data->txt, "Determinando-se a enfrentar a criatura guardia, voce avanca com cautela em direcao a sala da besta guardia. O ar se torna mais pesado e o ambiente eh envolto em uma penumbra opressiva. a medida que voce se aproxima, ouve o som de respiracao pesada e passos pesados ecoando pelo salao.\n\nAo entrar na sala, voce se depara com a Besta Guardia. eh uma criatura imponente, corpo de leao, rosto humanoide, cauda de escorpiao, asas enormes, com olhos vermelhos brilhantes e uma pele grossa como couro. Armado com sua espada, voce se prepara para o confronto. A batalha eh feroz, mas voce luta com toda a sua habilidade e coragem. Apos um combate intenso, voce finalmente derrota a criatura, que cai ao chao com um rugido final.\n\nExplorando a sala apos a batalha, voce encontra um bau escondido em um canto. Ao abri-lo, descobre um frasco de pocao curativa e uma espada magica.\n\nCom novos itens em seu inventario e a certeza de que esta no caminho certo, voce consulta o mapa e o diario de Casselmann novamente. As anotacoes indicam duas areas que ainda precisam ser exploradas:\n\n");
        break;

    case (MORTE5):
        strmalloc(&data->txt, "Voce entra na camara do enigma e tenta resolver os quebra-cabecas, mas uma armadilha oculta eh acionada. Dardos venenosos sao lancados das paredes e, sem tempo para reagir, voce eh atingido mortalmente. Sua jornada termina aqui, nos confins da masmorra.\n\n");
        break;

    case (CAP6):
        strmalloc(&data->txt, "Com a nova espada magica em maos, voce decide explorar a Biblioteca Oculta. Consultando o mapa e as anotacoes no diario de Casselmann, voce segue pelos corredores da masmorra ate encontrar uma parede aparentemente solida. Lembrando das instrucoes, voce usa o Amuleto Umbral para revelar uma passagem secreta.\n\nA passagem se abre para uma sala ampla, repleta de estantes cheias de livros e pergaminhos antigos. A luz fraca dos cristais magicos ilumina o ambiente, criando um ar de misterio. Voce sente uma sensacao de reverencia ao entrar, sabendo que este lugar guarda segredos antigos e poderosos.\n\nVoce comeca a inspecionar os livros e pergaminhos, procurando por qualquer pista sobre Casselmann e o proposito da masmorra. Apos uma busca meticulosa, voce encontra um livro antigo, decorado com runas elficas. O titulo chama sua atencao: ' O Segredo das Sombras '. Folheando as paginas, voce remonta trechos da historia deste local. Esta masmorra ja foi um templo elfico devoto a uma antiga deusa chamada 'Senhora da Noite' ou 'Deusa da Perda' chamada Shar, que trouxe a escuridao de outro plano, o Pendor das Sombras, a esta realidade, culminando na ruina deste elfos.\n\nVoce encontra uma secao detalhando um artefato conhecido como o ' Coracao de Shar ', que parece ser a chave para controlar a masmorra e encontrar Casselmann. O livro revela que o Coracao de Shar esta escondido na camara mais profunda da masmorra, guardado por um antigo guardiao sombrio. Apenas aqueles que dominam o poder das sombras podem enfrentar o guardiao e reivindicar o artefato. Voce percebe que o Amuleto Umbral eh essencial para esta tarefa.\n\nAgora, com informacoes vitais em maos, voce tem duas opcoes para continuar sua busca por Casselmann e pelo Coracao de Shar:\n\n");
        break;

    case (MORTE6):
        strmalloc(&data->txt, "Voce tenta navegar pelo caminho dos espelhos, mas as ilusoes e armadilhas sao inumeras. Um erro ao decifrar os segredos dos portais resulta em voce ser aprisionado eternamente em um labirinto de espelhos, incapaz de continuar sua missao.\n\n");
        break;

    case (CAP7):
        strmalloc(&data->txt, "Decidido a seguir pelo caminho das catacumbas, voce deixa a biblioteca oculta e avanca pelos corredores da masmorra. O ar fica mais pesado e o ambiente mais claustrofobico a medida que voce desce para as profundezas. O caminho eh repleto de tumulos antigos e criptas, algumas das quais foram profanadas por saqueadores e criaturas malignas, e algumas das quais sao de inquisidores sombrios que morreram dentro da masmorra.\n\nAo prosseguir, voce enfrenta diversos perigos: mortos-vivos, armadilhas antigas e passagens colapsadas. Usando sua espada magica e o Amuleto Umbral, voce derrota os mortos-vivos e evita as armadilhas com agilidade. Em uma das criptas, voce encontra uma inscricao em elfico que fala sobre o Coracao de Shar e a necessidade de derrotar o guardiao para obte-lo.\n\nApos horas de exploracao e batalhas intensas, voce finalmente chega a camara mais profunda da masmorra. A sala eh vasta, com paredes cobertas de runas brilhantes que emanam uma energia sinistra. No centro, sobre um pedestal de pedra, esta o Coracao de Shar, uma gema negra pulsante com um brilho inquietante.\n\nAo se aproximar do pedestal, uma sombra gigantesca comeca a se formar. O guardiao sombrio, uma criatura de pura escuridao com olhos vermelhos ardentes, emerge, protegendo o artefato com uma furia ancestral. Sabendo que a batalha final esta prestes a comecar, voce se prepara para o confronto.\n\nA batalha contra o guardiao sombrio eh intensa. O monstro ataca com uma forca implacavel, usando sombras para tentar esmaga-lo e desorienta-lo. No entanto, com sua espada magica e o poder do Amuleto Umbral, voce consegue se defender e atacar com precisao. Apos uma luta exaustiva, voce finalmente desfere um golpe mortal, dissipando a criatura em uma nuvem de escuridao, e ela retorna ao Pendor das Sombras.\n\nCom o guardiao derrotado, voce se aproxima do pedestal e pega o Coracao de Shar. A gema emana um poder imenso e, ao segura-la, voce sente uma conexao com as sombras ao seu redor, ganhando a capacidade de controla-las completamente.\n\nCom o Coracao de Shar em maos, voce sente que esta proximo de encontrar Casselmann. O mapa e o diario indicam duas possiveis rotas seguintes a esta sala:\n\n");
        break;

    case (MORTE7):
        strmalloc(&data->txt, "Voce atravessa o Portao das Sombras, levando-o numa versao distorcida da masmorra, o frio e a escuridao comecam a tomar forma, voce sente o olhar de Shar sobre sua alma. As criaturas sombrias surgem numerosas, e acabam por superar voce, levando-o a uma morte tragica, se tornando mais uma marionete de Shar.\n\n");
        break;

    case (FINAL):
        strmalloc(&data->txt, "Decidindo enfrentar os desafios da sala do espelho negro, voce se encaminha determinadamente para a proxima etapa de sua jornada. A sala eh descrita por suas ilusoes e perigos, mas voce confia em suas habilidades.\n\nAo entrar na sala, voce eh imediatamente cercado por uma nevoa escura que distorce a visao. Espelhos negros adornam as paredes, refletindo imagens distorcidas de si mesmo. Voce avanca com cautela, sabendo que cada passo pode ser uma armadilha.\n\nAs ilusoes se intensificam a medida que voce avanca, desafiando sua percepcao e tentando confundi-lo. Imagens de entes queridos perdidos, paisagens familiares e visoes assombrosas dancam diante de seus olhos. Mas voce se mantehm firme, lembrando-se de sua missao e do objetivo final: encontrar Casselmann.\n\nApos uma serie de desafios e ilusoes, voce finalmente identifica o espelho verdadeiro, aquele que nao distorce a realidade, mas a revela. Ao se aproximar, voce ve a imagem de Casselmann, aprisionada em um reflexo sombrio. Determinado a liberta-la, voce invoca o poder do Coracao de Shar.\n\nCom uma explosao de luz, o espelho se desfaz, dissipando as ilusoes ao seu redor. Casselmann emerge do reflexo sombrio, seus olhos encontrando os seus com gratidao e alivio. Voce o alcanca, ajudando-a a se levantar, sentindo um peso sendo retirado de seus ombros.\n\nCasselmann explica o que aconteceu desde sua chegada a masmorra e como ele foi capturado por uma forca sombria enquanto investigava o Coracao de Shar. Agora, juntos, voces estao determinados a escapar da masmorra e derrotar a escuridao que a habita.\n\nCom Casselmann ao seu lado, voces se preparam para enfrentar os desafios finais da masmorra. Usando o poder do Coracao de Shar, a Senhora da Noite aparece em sua frente, na forma de um avatar. Ela levanta seus seis bracos, cada um segurando uma foice, e um combate mortal comeca. Casselmann pede que voce ganhe tempo pra que ele consiga conjurar um feitico de teleporte para o inicio da masmorra.\n\nApos uma jornada repleta de perigos, voces finalmente emergem das profundezas da masmorra, banhados pela luz do sol. Juntos, voces olham para o horizonte, questionando se um dia a Senhora da Noite retornara a este plano. Mas estes sao pensamentos lugubres, distantes, pois o que resta agora eh levar esta historia a taverna, acompanhada de bastante cerveja. Voces caminham rumo a Ravenshire, com valiosos itens magicos da masmorra, contentes por terem saido vivos.\n\n\tFim\n\nParabens, bravo aventureiro, voce completou sua missao e salvou o velho mago da escuridao. Sua coragem e determinacao foram fundamentais para o sucesso desta jornada pela antiga masmorra.\n\n");
        break;
    default:
        printf("\n\tFalha ao alocar texto.\n\n");
    }
}

int gbselect(int id, char **str1, char **str2)
{
    srand(time(NULL));
    int aux = (rand() % 2) + 1;
    if (aux == 1)
        gbbranch(id, &str1, &str2);
    else if (aux == 2)
        gbbranch(id, &str2, &str1);

    return aux;
}

void gbbranch(int id, char **str1, char **str2)
{
    switch (id)
    {
    case (CAP1):
        strmalloc(*str1, ". Caminho da Esquerda: Um corredor estreito que parece ser menos usado. Ha marcas de garras nas paredes e um leve som de agua corrente ao longe.\n");
        strmalloc(*str2, ". Caminho da Direita: Um corredor amplo e bem iluminado por tochas. O chao eh coberto por ossos e restos de armaduras enferrujadas.\n");
        break;

    case (CAP2):
        strmalloc(*str1, ". Rota dos Tuneis Subterraneos: Um caminho que passa por uma serie de tuneis subterraneos estreitos e escuros, conhecidos por estarem infestados de aranhas gigantes.\n");
        strmalloc(*str2, ". Rota da Ponte de Cristal: Um caminho mais direto que atravessa uma ponte de cristal sobre um abismo profundo. A ponte eh antiga e parece estar em estado precario.\n");
        break;

    case (CAP3):
        strmalloc(*str1, ". Usar o Amuleto Umbral: Tentar usar o poder do amuleto para se proteger e repelir a presenca maligna.\n");
        strmalloc(*str2, ". Fugir pela passagem secreta: Tentar sair da camara rapidamente, voltando pelos tuneis antes que a presenca maligna possa alcanca-lo.\n");
        break;

    case (CAP4):
        strmalloc(*str1, ". Sala da Besta Guardia: Um caminho que leva a uma sala onde, de acordo com o diario de Casselmann, reside uma criatura guardia, protegendo um item crucial para a missao.\n");
        strmalloc(*str2, ". Corredor das Almas Perdidas: Um caminho que, segundo o diario, esta repleto de espiritos errantes que podem drenar sua energia vital, mas tambehm pode conter artefatos e segredos importantes.\n");
        break;

    case (CAP5):
        strmalloc(*str1, ". Biblioteca Oculta: Uma sala escondida repleta de livros e pergaminhos antigos, onde Aria acreditava que poderia encontrar informacoes vitais sobre a masmorra e seu proposito.\n");
        strmalloc(*str2, ". Camara do Enigma: Uma sala cheia de armadilhas e quebra-cabecas, onde supostamente esta guardado um artefato poderoso que pode ajuda-lo a prosseguir.\n");
        break;

    case (CAP6):
        strmalloc(*str1, ". Caminho das Catacumbas: Um caminho subterraneo que passa por antigos tumulos e criptas. eh um caminho perigoso, mas pode levar diretamente a camara mais profunda.\n");
        strmalloc(*str2, ". Caminho dos Espelhos: Um caminho magico cheio de portais espelhados. eh repleto de ilusoes e armadilhas, mas pode oferecer uma rota mais rapida se voce conseguir decifrar seus segredos.\n");
        break;

    case (CAP7):
        strmalloc(*str1, ". Sala do Espelho Negro: Uma sala misteriosa onde Casselmann pode estar aprisionado. A sala eh conhecida por suas ilusoes e perigos, mas pode conter a chave para liberta-lo.\n");
        strmalloc(*str2, ". Portao das Sombras: Um portal antigo que leva ao nucleo da masmorra. eh um caminho direto, mas extremamente perigoso, passando diretamente pelo Pendor das Sombras, repleto de criaturas sombrias e armadilhas letais.\n");
        break;

    default:
        printf("Falha ao alocar texto.\n\n");
    }
}

void gbprogress(Output *data, int n)
{
    if (n == 0)
    {
        switch (data->id)
        {
        case (CAP1):
            data->id = MORTE1;
            break;
        case (CAP2):
            data->id = MORTE2;
            break;
        case (CAP3):
            data->id = MORTE3;
            break;
        case (CAP4):
            data->id = MORTE4;
            break;
        case (CAP5):
            data->id = MORTE5;
            break;
        case (CAP6):
            data->id = MORTE6;
            break;
        case (CAP7):
            data->id = MORTE7;
            break;
        }
    }
    else if (n == 1)
    {
        switch (data->id)
        {
        case (CAP1):
            data->id = CAP2;
            break;
        case (CAP2):
            data->id = CAP3;
            break;
        case (CAP3):
            data->id = CAP4;
            break;
        case (CAP4):
            data->id = CAP5;
            break;
        case (CAP5):
            data->id = CAP6;
            break;
        case (CAP6):
            data->id = CAP7;
            break;
        case (CAP7):
            data->id = FINAL;
            break;
        }
    }
    gbchapter(data);
}

void refresh()
{
    system("cls");
    printf("\n\t");
}

void gbscanf(No **t, Output *data, char *select)
{
    insert(t, *data);

    char *sel1, *sel2, aux;
    int succeed = gbselect(data->id, &sel1, &sel2);
    if (succeed == 1)
        aux = '1';
    else if (succeed == 2)
        aux = '2';

    gbprintf(RED BOLD, "1");
    gbprintf(RED BOLD, sel1);
    gbprintf(RED BOLD, "2");
    gbprintf(RED BOLD, sel2);
    gbprintf(RED BOLD, "0. Salvar e Sair\n\n");

    gbprintf(RED BOLD, "\tSua escolha: ");
    fflush(stdin);
    scanf("%c", select);
    if (*select != '1' && *select != '2' && *select != '0')
    {
        refresh();
        gbprintf(RED BOLD, "Erro -> Resposta invalida, digite outra opcao\n\n");
        fflush(stdin);
        system("Pause");
        return;
    }
    else if (*select == aux)
    {
        gbprogress(data, 1);
    }
    else if (*select != aux && *select != '0')
        gbprogress(data, 0);
}

int gbverifyBranch(int id)
{
    if ((id == CAP1) ||
        (id == CAP2) ||
        (id == CAP3) ||
        (id == CAP4) ||
        (id == CAP5) ||
        (id == CAP6) ||
        (id == CAP7))
        return 1;
    else
        return 0;
}

void gbsave(No **t)
{
    char filename[50] = "savefile.bin";
    FILE *f = fopen(filename, "wb");
    if (f == NULL)
    {
        printf("falha ao abrir arquivo.\n\n");
        exit(1);
    }

    No *aux = viewRightBranch(t);
    fwrite(&(aux->dado.id), sizeof(int), 1, f);

    free(aux);
    fclose(f);
}

int gbload(No **t, Output *data)
{
    int id = NULL;
    char filename[50] = "savefile.bin";
    FILE *f = fopen(filename, "rb");
    if (f == NULL)
        return id;

    fread(&id, sizeof(int), 1, f);

    fclose(f);

    switch (id)
    {
    case CAP1:
        data->id = CAP1;
        gbchapter(data);
        insert(t, *data);
        break;

    case CAP2:
        data->id = CAP1;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP2;
        gbchapter(data);
        insert(t, *data);
        break;

    case CAP3:
        data->id = CAP1;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP2;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP3;
        gbchapter(data);
        insert(t, *data);
        break;

    case CAP4:
        data->id = CAP1;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP2;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP3;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP4;
        gbchapter(data);
        insert(t, *data);
        break;

    case CAP5:
        data->id = CAP1;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP2;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP3;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP4;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP5;
        gbchapter(data);
        insert(t, *data);
        break;

    case CAP6:
        data->id = CAP1;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP2;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP3;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP4;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP5;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP6;
        gbchapter(data);
        insert(t, *data);
        break;

    case CAP7:
        data->id = CAP1;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP2;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP3;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP4;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP5;
        gbchapter(data);
        insert(t, *data);

        data->id = CAP7;
        gbchapter(data);
        insert(t, *data);
        break;

    default:
        break;
    }

    return id;
}