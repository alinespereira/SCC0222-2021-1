#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STOP -1

typedef struct _student
{
    int id;
    char *name;
    char *course;
    int age;
} student_t;

typedef enum _operation
{
    FIND_BY_ID = 1,
    FIND_BY_COURSE = 2,
    SHOW_ALL = 3
} operation_t;

char *read_line();
int string_length(char *str);
bool is_equal(char *str1, char *str2);
student_t read_student();
student_t *append_student(student_t *students, int *n_students, student_t student);
void find_student_by_id(int id, student_t *students, int n_students);
void find_students_by_course(char *course, student_t *students, int n_students);
void show_student(student_t student);
void show_students(student_t *students, int n_students);

int main()
{
    student_t *students = NULL;
    int n_students = 0;
    int operation;

    scanf("%d\n", &operation);
    while (operation != STOP)
    {
        student_t student = read_student();
        // Quando o número lido for != -1, ele representa o id do estudante
        student.id = operation;
        students = append_student(students, &n_students, student);
        scanf("%d\n", &operation);
    }

    do
    {
        scanf("%d", &operation);
        int id;
        char *course;
        switch (operation)
        {
        case FIND_BY_ID:
            scanf("%d", &id);
            find_student_by_id(id, students, n_students);
            break;

        case FIND_BY_COURSE:
            course = read_line();
            find_students_by_course(course, students, n_students);
            free(course);
            break;

        case SHOW_ALL:
            show_students(students, n_students);
            break;
        }
    } while (operation != STOP);

    for (int i = 0; i < n_students; i++)
    {
        free(students[i].name);
        free(students[i].course);
    }
    free(students);

    return EXIT_SUCCESS;
}

/*
 * A função read_line lê uma sequência de caracteres até encontrar o caracter '\n'
 * e retorna a sequência lida, substituindo o caracter final pelo '\0', indicando
 * o fim da string.
 */
char *read_line()
{
    char current;
    char *line = NULL;
    int length = 0;

    do
    {
        current = getchar();
        length++;
        line = (char *)realloc(line, length * sizeof(char));
        line[length - 1] = current;
    } while (current != '\n');

    line[length - 1] = '\0';

    return line;
}

/*
 * A função abaixo calcula o tamanho de uma string, assumindo que ela é terminada
 * no caracter '\0'.
 */
int string_length(char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;

    return len;
}

/*
 * A função abaixo compara duas strings, retornando true se iguais, false caso contrário.
 */
bool is_equal(char *str1, char *str2)
{
    if (string_length(str1) != string_length(str2))
        return false;

    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
        if (str1[i] != str2[i])
            return false;

    return true;
}

/*
 * A função abaixo lê os dados de um estudante da entrada padrão e retorna
 * um student_t, que organiza os dados lidos da tela numa struct.
 */
student_t read_student()
{
    student_t student;
    student.name = read_line();
    student.course = read_line();
    scanf("%d", &student.age);

    return student;
}

/*
 * A função abaixo recebe uma lista de estudantes, o tamanho dessa lista (por referência)
 * e um estudante. O tamanho da lista é incrementado, a lista é realocada para comportar
 * o novo estudante e então o novo estudante é adicionado. A função retorna um ponteiro
 * para a lista de estudantes após a realocação.
 */
student_t *append_student(student_t *students, int *length, student_t student)
{
    (*length)++;
    students = (student_t *)realloc(students, (*length) * sizeof(student_t));
    students[(*length) - 1] = student;

    return students;
}

/*
 * A função abaixo busca um estudante na lista de estudantes pelo seu identificador
 * e exibe o estudante na saída padrão.
 */
void find_student_by_id(int id, student_t *students, int length)
{
    bool found = false;
    for (int i = 0; i < length; i++)
        if (students[i].id == id)
        {
            show_student(students[i]);
            found = true;
            break;
        }

    if (!found)
        printf("Aluno nao cadastrado\n");
}

/*
 * A função abaixo procura estudantes pelo nome do curso e mostra os estudantes
 * encontrados na saída padrão.
 */
void find_students_by_course(char *course, student_t *students, int length)
{
    for (int i = 0; i < length; i++)
        if (is_equal(students[i].course, course))
            show_student(students[i]);
}

/*
 * A função abaixo mostra um estudante na saída padrão.
 */
void show_student(student_t student)
{
    printf("Nome: %s\n", student.name);
    printf("Curso: %s\n", student.course);
    printf("N USP: %d\n", student.id);
    printf("IDADE: %d\n\n", student.age);
}

/*
 * A função abaixo mostra todos os estudantes da lista dada na saída padrão.
 */
void show_students(student_t *students, int length)
{
    for (int i = 0; i < length; i++)
        show_student(students[i]);
}
