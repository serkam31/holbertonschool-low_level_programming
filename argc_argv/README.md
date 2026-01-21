# argc, argv - Arguments de la ligne de commande

## 📖 Description

Lorsque tu lances un programme depuis le terminal, tu peux lui passer des **arguments**. C'est ce que font des commandes comme `ls -la` ou `gcc fichier.c -o programme`. Dans ce module, tu vas apprendre à récupérer ces arguments dans ton programme C.

## 🎯 Objectifs d'apprentissage

À la fin de ce module, tu dois comprendre :

- Ce que sont **argc** et **argv**
- Comment récupérer les **arguments de ligne de commande**
- Comment utiliser ces arguments dans ton programme
- Convertir des arguments en nombres
- Gérer les erreurs d'arguments

## 📚 Concepts clés

### La fonction main avec arguments

Jusqu'ici, tu écrivais :
```c
int main(void)
{
    return (0);
}
```

Maintenant, tu vas écrire :
```c
int main(int argc, char *argv[])
{
    return (0);
}
```

### Que sont argc et argv ?

- **argc** : **Arg**ument **C**ount (nombre d'arguments)
- **argv** : **Arg**ument **V**ector (tableau des arguments)

```c
int argc;        /* Nombre d'arguments */
char *argv[];    /* Tableau de chaînes de caractères */
```

### Exemple concret

Si tu exécutes :
```bash
./programme hello world 42
```

Alors dans ton programme :
```c
argc = 4

argv[0] = "./programme"
argv[1] = "hello"
argv[2] = "world"
argv[3] = "42"
argv[4] = NULL
```

**Important** : `argv[0]` est TOUJOURS le nom du programme !

## 📝 Exemples pratiques

### 1. Afficher le nom du programme

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("%s\n", argv[0]);
    return (0);
}
```

**Exécution** :
```bash
./programme
# Affiche : ./programme
```

### 2. Compter les arguments

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("%d\n", argc);
    return (0);
}
```

**Exécution** :
```bash
./programme un deux trois
# Affiche : 4 (programme + 3 arguments)
```

### 3. Afficher tous les arguments

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    for (i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    return (0);
}
```

**Exécution** :
```bash
./programme Hello World
# Affiche :
# ./programme
# Hello
# World
```

### 4. Additionner des nombres

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, somme = 0;

    /* On commence à 1 pour ignorer argv[0] */
    for (i = 1; i < argc; i++)
    {
        somme += atoi(argv[i]);  /* Convertir string en int */
    }

    printf("%d\n", somme);
    return (0);
}
```

**Exécution** :
```bash
./add 1 2 3 4
# Affiche : 10
```

### 5. Multiplier deux nombres

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int resultat;

    if (argc != 3)
    {
        printf("Erreur\n");
        return (1);
    }

    resultat = atoi(argv[1]) * atoi(argv[2]);
    printf("%d\n", resultat);

    return (0);
}
```

**Exécution** :
```bash
./mul 5 7
# Affiche : 35

./mul 5
# Affiche : Erreur
```

### 6. Calculatrice simple

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int num1, num2, result;

    if (argc != 4)
    {
        printf("Usage: %s num1 operator num2\n", argv[0]);
        return (1);
    }

    num1 = atoi(argv[1]);
    num2 = atoi(argv[3]);

    if (argv[2][0] == '+')
        result = num1 + num2;
    else if (argv[2][0] == '-')
        result = num1 - num2;
    else if (argv[2][0] == '*')
        result = num1 * num2;
    else if (argv[2][0] == '/')
    {
        if (num2 == 0)
        {
            printf("Erreur : division par zéro\n");
            return (1);
        }
        result = num1 / num2;
    }
    else
    {
        printf("Opérateur inconnu\n");
        return (1);
    }

    printf("%d\n", result);
    return (0);
}
```

**Exécution** :
```bash
./calc 10 + 5
# Affiche : 15

./calc 20 - 8
# Affiche : 12
```

### 7. Compter les pièces de monnaie

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int cents, count = 0;
    int pieces[] = {25, 10, 5, 2, 1};
    int i;

    if (argc != 2)
    {
        printf("Erreur\n");
        return (1);
    }

    cents = atoi(argv[1]);

    if (cents < 0)
    {
        printf("0\n");
        return (0);
    }

    for (i = 0; i < 5; i++)
    {
        while (cents >= pieces[i])
        {
            cents -= pieces[i];
            count++;
        }
    }

    printf("%d\n", count);
    return (0);
}
```

**Exécution** :
```bash
./change 41
# Affiche : 4 (25 + 10 + 5 + 1)
```

## ⚠️ Points TRÈS importants

### 1. argv[0] est le nom du programme

```c
/* argv[0] = nom du programme */
/* Les vrais arguments commencent à argv[1] */

for (i = 1; i < argc; i++)  /* Commence à 1, pas 0 ! */
    printf("%s\n", argv[i]);
```

### 2. Les arguments sont des chaînes !

```c
/* FAUX - argv[1] n'est PAS un int ! */
int n = argv[1];

/* VRAI - Il faut convertir */
int n = atoi(argv[1]);
```

### 3. Toujours vérifier argc

```c
/* Vérifier qu'on a le bon nombre d'arguments */
if (argc != 3)
{
    printf("Usage: %s arg1 arg2\n", argv[0]);
    return (1);
}
```

### 4. argv[argc] est NULL

```c
/* argv se termine par NULL */
argv[argc] == NULL  /* Toujours vrai */
```

### 5. Les espaces séparent les arguments

```bash
./programme Hello World  # 3 arguments : programme, Hello, World
./programme "Hello World"  # 2 arguments : programme, Hello World
```

### 6. Attention aux caractères spéciaux

```bash
./programme *     # Le shell remplace * par tous les fichiers !
./programme '*'   # Passe * comme argument
./programme \*    # Alternative avec backslash
```

## 💡 Fonctions de conversion utiles

### atoi() - ASCII to Integer

```c
#include <stdlib.h>

int atoi(const char *str);

/* Exemples */
atoi("42")    /* retourne 42 */
atoi("-10")   /* retourne -10 */
atoi("abc")   /* retourne 0 */
```

**Limitation** : atoi ne détecte pas les erreurs !

### Vérifier si c'est un nombre

```c
#include <ctype.h>

int is_number(char *str)
{
    int i = 0;

    /* Gérer le signe */
    if (str[0] == '-' || str[0] == '+')
        i = 1;

    /* Vérifier que tous les caractères sont des chiffres */
    while (str[i])
    {
        if (!isdigit(str[i]))
            return (0);
        i++;
    }

    return (1);
}
```

## 🧠 Visualisation

```bash
./programme arg1 arg2 arg3
```

En mémoire :
```
argc = 4

argv[0] ──> "./programme\0"
argv[1] ──> "arg1\0"
argv[2] ──> "arg2\0"
argv[3] ──> "arg3\0"
argv[4] = NULL
```

## 📖 Cas d'usage réels

### Usage message

```c
if (argc != 2)
{
    printf("Usage: %s filename\n", argv[0]);
    return (1);
}
```

### Flags et options

```c
int verbose = 0;

for (i = 1; i < argc; i++)
{
    if (strcmp(argv[i], "-v") == 0)
        verbose = 1;
    else if (strcmp(argv[i], "-h") == 0)
        print_help();
}
```

### Traiter des fichiers

```c
int main(int argc, char *argv[])
{
    int i;

    if (argc < 2)
    {
        printf("Usage: %s file1 file2 ...\n", argv[0]);
        return (1);
    }

    for (i = 1; i < argc; i++)
    {
        process_file(argv[i]);
    }

    return (0);
}
```

## 🎯 Exemples de projets

### 1. Programme qui affiche son nom

```c
int main(int argc, char *argv[])
{
    (void)argc;  /* Indique qu'on n'utilise pas argc */
    printf("%s\n", argv[0]);
    return (0);
}
```

### 2. Programme qui compte les arguments

```c
int main(int argc, char *argv[])
{
    (void)argv;
    printf("%d\n", argc - 1);  /* -1 pour exclure le nom du programme */
    return (0);
}
```

### 3. Programme qui affiche tous les arguments

```c
int main(int argc, char *argv[])
{
    int i;

    for (i = 0; i < argc; i++)
        printf("%s\n", argv[i]);
    return (0);
}
```

### 4. Programme d'addition

```c
int main(int argc, char *argv[])
{
    int i, sum = 0;

    for (i = 1; i < argc; i++)
        sum += atoi(argv[i]);

    printf("%d\n", sum);
    return (0);
}
```

### 5. Programme de multiplication

```c
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error\n");
        return (1);
    }

    printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
    return (0);
}
```

## 🔍 Débogage

### Afficher argc et argv pour déboguer

```c
int main(int argc, char *argv[])
{
    int i;

    printf("argc = %d\n", argc);

    for (i = 0; i < argc; i++)
        printf("argv[%d] = \"%s\"\n", i, argv[i]);

    return (0);
}
```

### Gérer les erreurs proprement

```c
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Erreur : pas assez d'arguments\n");
        fprintf(stderr, "Usage: %s <arguments>\n", argv[0]);
        return (1);
    }

    /* ... */
    return (0);
}
```

## ✅ Compilation et tests

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 fichier.c -o programme
./programme arg1 arg2 arg3
```

## 📋 Fonctions utiles

- `atoi(str)` - Convertit une chaîne en entier
- `strcmp(s1, s2)` - Compare deux chaînes
- `isdigit(c)` - Vérifie si c'est un chiffre

## 🎓 Points clés à retenir

1. **argc** = nombre d'arguments (incluant le nom du programme)
2. **argv[0]** = nom du programme
3. **argv[1]** à **argv[argc-1]** = arguments
4. **argv[argc]** = NULL
5. Les arguments sont des **chaînes**, il faut les convertir
6. Toujours **vérifier argc** avant d'accéder à argv

---

**Retour au [README principal](../README.md)**
