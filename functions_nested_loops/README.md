# Functions and Nested Loops - Fonctions et boucles imbriquées

## 📖 Description

Ce module t'apprend à créer et utiliser des fonctions en C. Les fonctions permettent de découper ton code en blocs réutilisables, rendant ton programme plus organisé et facile à maintenir.

## 🎯 Objectifs d'apprentissage

À la fin de ce module, tu dois savoir :

- **Créer des fonctions** personnalisées
- Comprendre les **prototypes de fonctions**
- Utiliser les **fichiers d'en-tête** (`.h`)
- Passer des **paramètres** à une fonction
- **Retourner des valeurs** depuis une fonction
- Créer des **boucles imbriquées** (boucle dans une boucle)
- Utiliser la fonction `_putchar()`

## 📚 Concepts clés

### Qu'est-ce qu'une fonction ?

Une fonction est un bloc de code réutilisable qui effectue une tâche spécifique.

```c
/* Prototype (déclaration) */
int addition(int a, int b);

/* Définition de la fonction */
int addition(int a, int b)
{
    return (a + b);
}

/* Utilisation */
int resultat = addition(5, 3);  /* resultat vaut 8 */
```

### Structure d'une fonction

```c
type_de_retour nom_fonction(type_parametre parametre)
{
    /* Code de la fonction */
    return (valeur);
}
```

- **type_de_retour** : `int`, `char`, `void` (rien), etc.
- **nom_fonction** : nom que tu donnes à ta fonction
- **paramètres** : valeurs que tu passes à la fonction
- **return** : valeur renvoyée par la fonction

### Fichiers d'en-tête (.h)

Les fichiers `.h` contiennent les **prototypes** des fonctions :

```c
/* main.h */
#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
void print_alphabet(void);
int _abs(int n);

#endif
```

### Boucles imbriquées

Une boucle à l'intérieur d'une autre boucle :

```c
int i, j;
for (i = 0; i < 3; i++)
{
    for (j = 0; j < 3; j++)
    {
        printf("%d,%d ", i, j);
    }
    printf("\n");
}
/* Affiche :
0,0 0,1 0,2
1,0 1,1 1,2
2,0 2,1 2,2
*/
```

## 📝 Notions importantes

### La fonction `_putchar()`

C'est une fonction personnalisée fournie par Holberton qui affiche un caractère :

```c
_putchar('H');
_putchar('i');
_putchar('\n');
/* Affiche : Hi */
```

### Type `void`

- Comme **type de retour** : la fonction ne retourne rien
- Comme **paramètre** : la fonction ne prend aucun paramètre

```c
void afficher_message(void)
{
    printf("Bonjour\n");
    /* Pas de return nécessaire */
}
```

### Portée des variables

```c
int global = 10;  /* Variable globale (à éviter !) */

int fonction(void)
{
    int locale = 5;  /* Variable locale (accessible uniquement ici) */
    return (locale);
}
```

## 💡 Exemples pratiques

### Fonction qui vérifie si un nombre est positif

```c
int is_positive(int n)
{
    if (n > 0)
        return (1);  /* Vrai */
    else
        return (0);  /* Faux */
}
```

### Afficher un carré avec des boucles imbriquées

```c
void print_square(int size)
{
    int i, j;
    
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            _putchar('#');
        }
        _putchar('\n');
    }
}
/* print_square(3) affiche :
###
###
###
*/
```

## ⚠️ Points importants

- Le **prototype** doit être déclaré **avant** d'utiliser la fonction
- N'oublie pas le **point-virgule** après un prototype
- Une fonction `void` ne doit pas retourner de valeur
- Une fonction non-`void` **doit** retourner une valeur
- Les variables locales n'existent que dans leur fonction
- Évite les variables globales (mauvaise pratique)

## 🔧 Organisation du code

### Structure typique d'un projet

```
projet/
├── main.h          # Prototypes des fonctions
├── _putchar.c      # Implémentation de _putchar
├── 0-holberton.c   # Ton code
└── main.c          # Fichier de test (fourni)
```

### Compilation avec plusieurs fichiers

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c 0-holberton.c -o programme
```

## 📖 Fonctions courantes de ce module

- `_putchar()` - Affiche un caractère
- `print_alphabet()` - Affiche l'alphabet
- `_islower()` - Vérifie si un caractère est minuscule
- `_isalpha()` - Vérifie si un caractère est une lettre
- `print_sign()` - Affiche le signe d'un nombre
- `_abs()` - Valeur absolue d'un nombre
- `print_last_digit()` - Affiche le dernier chiffre

## ✅ Compilation et tests

```bash
# Compiler avec plusieurs fichiers
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c main.c 0-holberton.c -o test
./test
```

---

**Retour au [README principal](../README.md)**
