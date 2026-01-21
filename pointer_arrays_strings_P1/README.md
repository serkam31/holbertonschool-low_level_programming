# Pointers, Arrays and Strings - Part 1

## 📖 Description

Ce module continue l'apprentissage des pointeurs en approfondissant la manipulation de chaînes de caractères. Tu vas créer tes propres versions des fonctions de la bibliothèque standard C.

## 🎯 Objectifs d'apprentissage

À la fin de ce module, tu dois savoir :

- Manipuler des **chaînes de caractères** avec des pointeurs
- Implémenter des fonctions de **manipulation de chaînes**
- Comprendre comment fonctionnent les fonctions standard
- Utiliser l'**arithmétique des pointeurs** efficacement
- Convertir des chaînes en nombres

## 📚 Concepts clés

### Rappel : Qu'est-ce qu'une chaîne en C ?

Une chaîne est un **tableau de caractères** terminé par `'\0'`.

```c
char str[] = "Hello";
/* Équivalent à : */
char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};

printf("%s\n", str);  /* Affiche : Hello */
```

### Parcourir une chaîne avec un pointeur

```c
char *str = "Hello";
while (*str != '\0')
{
    _putchar(*str);
    str++;  /* Avance le pointeur */
}
```

### Notation tableau vs pointeur

```c
char str[] = "Hello";

/* Notation tableau */
str[0] = 'H';
str[1] = 'e';

/* Notation pointeur (équivalent) */
*str = 'H';
*(str + 1) = 'e';
```

## 📝 Fonctions à implémenter

### Réinitialiser un entier à 98

```c
void reset_to_98(int *n)
{
    *n = 98;
}
```

**Explication** : Modifie la valeur pointée par `n` pour qu'elle vaille 98.

### Échanger deux entiers

```c
void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

**Explication** : Échange les valeurs de deux variables via leurs pointeurs.

### Longueur d'une chaîne

```c
int _strlen(char *s)
{
    int longueur = 0;

    while (s[longueur] != '\0')
    {
        longueur++;
    }
    return (longueur);
}
```

**Explication** : Compte le nombre de caractères jusqu'au `'\0'`.

### Afficher une chaîne

```c
void _puts(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        _putchar(str[i]);
        i++;
    }
    _putchar('\n');
}
```

**Explication** : Affiche chaque caractère de la chaîne puis un retour à la ligne.

### Afficher une chaîne à l'envers

```c
void print_rev(char *s)
{
    int longueur = 0;
    int i;

    /* Trouver la longueur */
    while (s[longueur] != '\0')
        longueur++;

    /* Afficher à l'envers */
    for (i = longueur - 1; i >= 0; i--)
        _putchar(s[i]);

    _putchar('\n');
}
```

**Explication** : Parcourt la chaîne de la fin vers le début.

### Inverser une chaîne

```c
void rev_string(char *s)
{
    int debut = 0;
    int fin = 0;
    char temp;

    /* Trouver la longueur */
    while (s[fin] != '\0')
        fin++;
    fin--;

    /* Échanger les caractères */
    while (debut < fin)
    {
        temp = s[debut];
        s[debut] = s[fin];
        s[fin] = temp;
        debut++;
        fin--;
    }
}
```

**Explication** : Modifie la chaîne en place en échangeant les caractères.

### Afficher un caractère sur deux

```c
void puts2(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (i % 2 == 0)
            _putchar(str[i]);
        i++;
    }
    _putchar('\n');
}
```

**Explication** : Affiche les caractères aux indices pairs (0, 2, 4...).

### Afficher la deuxième moitié

```c
void puts_half(char *str)
{
    int longueur = 0;
    int debut;
    int i;

    /* Calculer la longueur */
    while (str[longueur] != '\0')
        longueur++;

    /* Calculer le point de départ */
    if (longueur % 2 == 0)
        debut = longueur / 2;
    else
        debut = (longueur + 1) / 2;

    /* Afficher la deuxième moitié */
    for (i = debut; i < longueur; i++)
        _putchar(str[i]);

    _putchar('\n');
}
```

**Explication** : Affiche la moitié droite de la chaîne.

### Afficher un tableau d'entiers

```c
void print_array(int *a, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);

        if (i < n - 1)
            printf(", ");
    }
    printf("\n");
}
```

**Explication** : Affiche les `n` premiers éléments séparés par des virgules.

### Copier une chaîne

```c
char *_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  /* Ne pas oublier le caractère nul ! */

    return (dest);
}
```

**Explication** : Copie le contenu de `src` dans `dest` caractère par caractère.

### Convertir une chaîne en entier (atoi)

```c
int _atoi(char *s)
{
    int signe = 1;
    int resultat = 0;
    int i = 0;
    int commence = 0;

    while (s[i] != '\0')
    {
        /* Gérer les signes */
        if (s[i] == '-')
            signe *= -1;

        /* Si on trouve un chiffre */
        if (s[i] >= '0' && s[i] <= '9')
        {
            commence = 1;
            resultat = resultat * 10 + (s[i] - '0');

            /* Si le prochain n'est pas un chiffre, on arrête */
            if (s[i + 1] < '0' || s[i + 1] > '9')
                break;
        }
        /* Si on a déjà commencé et qu'on trouve autre chose, on arrête */
        else if (commence)
            break;

        i++;
    }

    return (resultat * signe);
}
```

**Explication** : Convertit une chaîne comme "-123" en nombre -123.

## ⚠️ Points TRÈS importants

### 1. Le caractère nul '\0'

**TOUJOURS** terminer une chaîne par `'\0'` !

```c
char str[6];
str[0] = 'H';
str[1] = 'e';
str[2] = 'l';
str[3] = 'l';
str[4] = 'o';
str[5] = '\0';  /* OBLIGATOIRE ! */
```

### 2. Vérifier la taille du buffer

```c
/* DANGEREUX - Pas assez de place ! */
char dest[5];
_strcpy(dest, "Hello World");  /* Overflow ! */

/* BON - Buffer suffisamment grand */
char dest[20];
_strcpy(dest, "Hello World");  /* OK */
```

### 3. Différence entre indices et longueur

```c
char str[] = "Hello";  /* 5 caractères */
/* Indices : 0, 1, 2, 3, 4 */
/* str[5] = '\0' */
/* Longueur = 5 */
```

### 4. Arithmétique des pointeurs

```c
char str[] = "Hello";
char *ptr = str;

printf("%c\n", *ptr);      /* H */
printf("%c\n", *(ptr+1));  /* e */
printf("%c\n", ptr[2]);    /* l (équivalent) */
```

## 💡 Exemples pratiques

### Compter les voyelles

```c
int count_vowels(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        char c = str[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            count++;
        i++;
    }
    return (count);
}
```

### Mettre en majuscules

```c
void str_to_upper(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;  /* a->A, b->B, etc. */
        i++;
    }
}
```

### Vérifier si palindrome

```c
int is_palindrome(char *str)
{
    int debut = 0;
    int fin = 0;

    /* Trouver la fin */
    while (str[fin] != '\0')
        fin++;
    fin--;

    /* Comparer */
    while (debut < fin)
    {
        if (str[debut] != str[fin])
            return (0);  /* Pas un palindrome */
        debut++;
        fin--;
    }
    return (1);  /* C'est un palindrome */
}
```

## 🧠 Visualisation mémoire

```
char str[] = "Hi";

Mémoire :
┌───┬───┬───┐
│ H │ i │\0 │
└───┴───┴───┘
  0   1   2

str[0] = 'H'
str[1] = 'i'
str[2] = '\0'
_strlen(str) = 2
```

## 📖 Conversions ASCII

```c
/* Caractère vers entier */
char c = '5';
int n = c - '0';  /* n = 5 */

/* Entier vers caractère */
int n = 7;
char c = '0' + n;  /* c = '7' */

/* Majuscule <-> Minuscule */
'a' - 32 = 'A'  /* minuscule vers majuscule */
'A' + 32 = 'a'  /* majuscule vers minuscule */
```

## 🎯 Astuces

### Parcourir avec un pointeur

```c
/* Méthode 1 : avec indice */
int i = 0;
while (str[i] != '\0')
{
    _putchar(str[i]);
    i++;
}

/* Méthode 2 : avec pointeur */
while (*str != '\0')
{
    _putchar(*str);
    str++;
}
```

### Copie efficace

```c
char *_strcpy(char *dest, char *src)
{
    int i = 0;

    while ((dest[i] = src[i]) != '\0')
        i++;

    return (dest);
}
```

## ✅ Compilation et tests

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c main.c fonction.c -o test
./test
```

## 📋 Liste des fonctions de ce module

- `reset_to_98()` - Modifie un entier via pointeur
- `swap_int()` - Échange deux entiers
- `_strlen()` - Longueur d'une chaîne
- `_puts()` - Affiche une chaîne
- `print_rev()` - Affiche à l'envers
- `rev_string()` - Inverse une chaîne
- `puts2()` - Affiche un caractère sur deux
- `puts_half()` - Affiche la deuxième moitié
- `print_array()` - Affiche un tableau d'entiers
- `_strcpy()` - Copie une chaîne
- `_atoi()` - Convertit une chaîne en entier

---

**Retour au [README principal](../README.md)**
