# Function Pointers - Pointeurs de fonctions

## 📖 Description

Les pointeurs de fonctions sont un concept avancé qui permet de stocker l'adresse d'une fonction et de l'appeler via un pointeur. C'est très puissant pour créer du code flexible.

## 🎯 Objectifs d'apprentissage

- Comprendre ce qu'est un **pointeur de fonction**
- Déclarer et utiliser des pointeurs de fonctions
- Passer des fonctions en **paramètres** d'autres fonctions
- Créer des **callbacks**
- Utiliser des tableaux de pointeurs de fonctions

## 📚 Concepts clés

### Qu'est-ce qu'un pointeur de fonction ?

Comme une variable a une adresse, une fonction aussi a une adresse en mémoire. Un pointeur de fonction stocke cette adresse.

```c
/* Fonction normale */
int addition(int a, int b)
{
    return (a + b);
}

/* Pointeur de fonction */
int (*operation)(int, int);  /* Déclare un pointeur de fonction */
operation = &addition;       /* Pointe vers addition */
/* ou simplement : */
operation = addition;

/* Appel via le pointeur */
int resultat = operation(5, 3);  /* resultat = 8 */
```

### Syntaxe de déclaration

```c
type_retour (*nom_pointeur)(types_parametres);

/* Exemples : */
int (*func_ptr)(int, int);           /* Retourne int, prend 2 int */
void (*action)(char *);              /* Retourne void, prend char* */
char *(*get_str)(void);              /* Retourne char*, pas de param */
```

## 📝 Exemples pratiques

### Passer une fonction en paramètre

```c
/* Fonction qui prend une fonction en paramètre */
void print_name(char *name, void (*f)(char *))
{
    if (name == NULL || f == NULL)
        return;
    
    f(name);  /* Appelle la fonction passée en paramètre */
}

/* Fonctions callback */
void print_upper(char *str)
{
    /* Affiche en majuscules */
}

void print_lower(char *str)
{
    /* Affiche en minuscules */
}

/* Utilisation */
print_name("Alice", print_upper);  /* Affiche ALICE */
print_name("Bob", print_lower);    /* Affiche bob */
```

### Appliquer une fonction à chaque élément

```c
void array_iterator(int *array, size_t size, void (*action)(int))
{
    size_t i;
    
    if (array == NULL || action == NULL)
        return;
    
    for (i = 0; i < size; i++)
        action(array[i]);
}

/* Fonctions à appliquer */
void print_elem(int elem)
{
    printf("%d\n", elem);
}

void print_double(int elem)
{
    printf("%d\n", elem * 2);
}

/* Utilisation */
int tab[] = {1, 2, 3, 4, 5};
array_iterator(tab, 5, print_elem);    /* Affiche chaque élément */
array_iterator(tab, 5, print_double);  /* Affiche le double */
```

### Fonction de recherche avec condition personnalisée

```c
int int_index(int *array, int size, int (*cmp)(int))
{
    int i;
    
    if (array == NULL || cmp == NULL || size <= 0)
        return (-1);
    
    for (i = 0; i < size; i++)
    {
        if (cmp(array[i]) != 0)
            return (i);
    }
    
    return (-1);
}

/* Fonctions de comparaison */
int is_positive(int n)
{
    return (n > 0);
}

int is_even(int n)
{
    return (n % 2 == 0);
}

/* Utilisation */
int tab[] = {-1, -2, 3, 4, 5};
int idx = int_index(tab, 5, is_positive);  /* idx = 2 (premier positif) */
```

## 💡 Tableau de pointeurs de fonctions

Créer une calculatrice :

```c
/* Fonctions d'opération */
int op_add(int a, int b) { return (a + b); }
int op_sub(int a, int b) { return (a - b); }
int op_mul(int a, int b) { return (a * b); }
int op_div(int a, int b) { return (a / b); }
int op_mod(int a, int b) { return (a % b); }

/* Structure pour associer opérateur et fonction */
typedef struct op {
    char *op;
    int (*f)(int, int);
} op_t;

int get_op_func(char *s)
{
    op_t ops[] = {
        {"+", op_add},
        {"-", op_sub},
        {"*", op_mul},
        {"/", op_div},
        {"%", op_mod},
        {NULL, NULL}
    };
    int i = 0;
    
    while (ops[i].op != NULL)
    {
        if (strcmp(ops[i].op, s) == 0)
            return (ops[i].f);
        i++;
    }
    
    return (NULL);
}

/* Utilisation */
int (*operation)(int, int);
operation = get_op_func("+");
if (operation != NULL)
    printf("%d\n", operation(10, 5));  /* Affiche 15 */
```

## ⚠️ Points TRÈS importants

### Syntaxe attention aux parenthèses !

```c
int *func(int a, int b);    /* Fonction qui retourne int* */
int (*func)(int a, int b);  /* Pointeur vers fonction qui retourne int */
```

### Toujours vérifier NULL

```c
void execute(void (*f)(void))
{
    if (f == NULL)  /* TOUJOURS vérifier ! */
        return;
    
    f();  /* Sinon segfault possible */
}
```

### Ne pas confondre

```c
int fonction(int x);        /* Prototype de fonction */
int (*ptr)(int);            /* Pointeur de fonction */

ptr = fonction;             /* Assigner l'adresse */
ptr = &fonction;            /* Équivalent */

int resultat = ptr(5);      /* Appeler via pointeur */
int resultat = (*ptr)(5);   /* Équivalent (plus explicite) */
```

## 🧠 Cas d'usage réels

### Callbacks (fonctions de rappel)

```c
/* Trier avec un comparateur personnalisé */
void sort(int *array, int size, int (*compare)(int, int))
{
    /* Utilise la fonction compare pour comparer les éléments */
}

int compare_ascending(int a, int b) { return (a - b); }
int compare_descending(int a, int b) { return (b - a); }

sort(tab, 10, compare_ascending);   /* Tri croissant */
sort(tab, 10, compare_descending);  /* Tri décroissant */
```

### Menu de commandes

```c
typedef struct {
    char *commande;
    void (*action)(void);
} menu_t;

void cmd_help(void) { printf("Aide\n"); }
void cmd_quit(void) { exit(0); }
void cmd_list(void) { printf("Liste\n"); }

menu_t menu[] = {
    {"help", cmd_help},
    {"quit", cmd_quit},
    {"list", cmd_list},
    {NULL, NULL}
};

void execute_command(char *cmd)
{
    int i = 0;
    
    while (menu[i].commande != NULL)
    {
        if (strcmp(menu[i].commande, cmd) == 0)
        {
            menu[i].action();
            return;
        }
        i++;
    }
    printf("Commande inconnue\n");
}
```

## 📖 Pourquoi utiliser des pointeurs de fonctions ?

- **Flexibilité** : Changer le comportement sans changer le code
- **Callbacks** : Passer des fonctions à d'autres fonctions
- **Polymorphisme** : Différents comportements avec la même interface
- **Jump tables** : Optimisation pour les switch/if multiples

## ✅ Compilation et tests

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o test
./test
```

---

**Retour au [README principal](../README.md)**
