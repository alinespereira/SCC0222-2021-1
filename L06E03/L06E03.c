#include <stdio.h>
#include <stdlib.h>

#define MEMSIZE 30000
#define INDENT_STRING "    "

typedef enum _operation
{
    INCREMENT_VALUE = '+',
    DECREMENT_VALUE = '-',
    INCREMENT_INDEX = '>',
    DECREMENT_INDEX = '<',
    PUT_CHAR = '.',
    BEGIN_WHILE = '[',
    END_WHILE = ']',
} operation_t;

void make_header(FILE *fp);
void indent(FILE *fp, int indent_level);
void make_operation(FILE *fp, operation_t op, int *indent_level);
void make_footer(FILE *fp);

int main()
{
    char instruction;
    int indent_level = 1;
    FILE *fp = fopen("jit-generated.c", "w");

    make_header(fp);

    while (scanf("%c", &instruction) != EOF)
    {
        make_operation(fp, (operation_t)instruction, &indent_level);
    }

    make_footer(fp);

    fclose(fp);
    system("gcc jit-generated.c -o jit-exe");
    system("./jit-exe");

    return EXIT_SUCCESS;
}

/*
 * Essa função foi utilizada para definir com mais liberdade
 * a indentação no código.
 */
void indent(FILE *fp, int indent_level)
{
    for (int i = 0; i < indent_level; i++)
        fprintf(fp, INDENT_STRING);
}

/*
 * Esta função imprime os cabeçalhos incluidos e a configuração inicial do
 * arquivo-fonte a ser gerado, ou seja, todo o código antes do código traduzido
 */
void make_header(FILE *fp)
{
    fprintf(fp, "#include <stdio.h>\n\n");
    fprintf(fp, "int main()\n");
    fprintf(fp, "{\n");
    indent(fp, 1);
    fprintf(fp, "char mem[%d];\n", MEMSIZE);
    indent(fp, 1);
    fprintf(fp, "int i = 0;\n");
    indent(fp, 1);
    fprintf(fp, "// Seta todos os lugares da memória para 0.\n");
    indent(fp, 1);
    fprintf(fp, "for (int j = 0; j < %d; j++)\n", MEMSIZE);
    indent(fp, 1);
    fprintf(fp, "{\n");
    indent(fp, 2);
    fprintf(fp, "mem[j] = 0;\n");
    indent(fp, 1);
    fprintf(fp, "}\n\n");
    indent(fp, 1);
    fprintf(fp, "/* Começo do código traduzido de BF */\n");
}

/*
 * Esta função converte uma operação BF em uma linha de código C e escreve
 * esta linha no arquivo.
 */
void make_operation(FILE *fp, operation_t op, int *indent_level)
{
    switch (op)
    {
    case INCREMENT_VALUE:
        indent(fp, *indent_level);
        fprintf(fp, "mem[i]++;\n");
        break;
    case DECREMENT_VALUE:
        indent(fp, *indent_level);
        fprintf(fp, "mem[i]--;\n");
        break;
    case INCREMENT_INDEX:
        indent(fp, *indent_level);
        fprintf(fp, "i++;\n");
        break;
    case DECREMENT_INDEX:
        indent(fp, *indent_level);
        fprintf(fp, "i--;\n");
        break;
    case PUT_CHAR:
        indent(fp, *indent_level);
        fprintf(fp, "putchar(mem[i]);\n");
        break;
    case BEGIN_WHILE:
        indent(fp, *indent_level);
        fprintf(fp, "while (mem[i])\n");
        indent(fp, *indent_level);
        fprintf(fp, "{\n");
        (*indent_level)++;
        break;
    case END_WHILE:
        (*indent_level)--;
        indent(fp, *indent_level);
        fprintf(fp, "}\n");
        break;
    }
}

/*
 * Esta função imprime os trechos finais do arquivo-fonte gerado,
 * incluido todas as linhas após o código traduzido
 */
void make_footer(FILE *fp)
{
    indent(fp, 1);
    fprintf(fp, "/* Fim do código traduzido de BF */\n\n");
    indent(fp, 1);
    fprintf(fp, "printf(\"\\n\");\n");
    indent(fp, 1);
    fprintf(fp, "for (int j = 0; j < %d; j++)\n", MEMSIZE);
    indent(fp, 1);
    fprintf(fp, "{\n");
    indent(fp, 2);
    fprintf(fp, "if (mem[j] != 0) {\n");
    indent(fp, 3);
    fprintf(fp, "printf(\"%%d \", mem[j]);\n");
    indent(fp, 2);
    fprintf(fp, "}\n");
    indent(fp, 1);
    fprintf(fp, "}\n");
    indent(fp, 1);
    fprintf(fp, "printf(\"\\n\");\n\n");
    indent(fp, 1);
    fprintf(fp, "return 0;\n");
    fprintf(fp, "}\n");
}
