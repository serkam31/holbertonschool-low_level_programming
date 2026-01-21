# 📚 Cours Complet - Programmation en C (Première Année)

## 📖 Table des matières

1. [Introduction au langage C](#1-introduction-au-langage-c)
2. [Variables et types de données](#2-variables-et-types-de-données)
3. [Structures de contrôle](#3-structures-de-contrôle)
4. [Fonctions](#4-fonctions)
5. [Pointeurs](#5-pointeurs)
6. [Tableaux et chaînes de caractères](#6-tableaux-et-chaînes-de-caractères)
7. [Récursivité](#7-récursivité)
8. [Gestion de la mémoire dynamique](#8-gestion-de-la-mémoire-dynamique)
9. [Structures et typedef](#9-structures-et-typedef)
10. [Pointeurs de fonctions](#10-pointeurs-de-fonctions)
11. [Fonctions variadiques](#11-fonctions-variadiques)
12. [Listes chaînées](#12-listes-chaînées)
13. [Arguments de ligne de commande](#13-arguments-de-ligne-de-commande)
14. [Entrées/Sorties fichiers](#14-entrées-sorties-fichiers)
15. [Récapitulatif et bonnes pratiques](#15-récapitulatif-et-bonnes-pratiques)

---

## 1. Introduction au langage C

### 1.1 Qu'est-ce que le C ?

Le **C** est un langage de programmation créé en 1972 par Dennis Ritchie. C'est un langage :
- **Compilé** : ton code est transformé en langage machine avant l'exécution
- **Bas niveau** : proche du fonctionnement réel de l'ordinateur
- **Portable** : un programme C peut tourner sur différents systèmes
- **Puissant** : utilisé pour les systèmes d'exploitation (Linux, Windows), les jeux, les drivers, etc.

### 1.2 Le processus de compilation

Quand tu écris un programme C, il passe par **4 étapes** avant de devenir exécutable :

```
Code source (.c)
      ↓
1. PRÉPROCESSEUR : Traite les directives #include, #define
      ↓
Code préprocessé (.i)
      ↓
2. COMPILATEUR : Transforme le code C en assembleur
      ↓
Code assembleur (.s)
      ↓
3. ASSEMBLEUR : Transforme l'assembleur en code machine
      ↓
Code objet (.o)
      ↓
4. LINKER : Lie les fichiers objets et bibliothèques
      ↓
Exécutable (a.out ou nom personnalisé)
```

**Commandes importantes :**

```bash
# Compilation complète en un seul coup
gcc fichier.c -o programme

# Étape par étape :
gcc -E fichier.c -o fichier.i    # Préprocesseur seulement
gcc -S fichier.c                 # Génère l'assembleur
gcc -c fichier.c                 # Crée le fichier objet
gcc fichier.o -o programme       # Linkage final

# Compilation avec tous les warnings (RECOMMANDÉ)
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 fichier.c -o programme
```

### 1.3 Structure d'un programme C

Tout programme C a cette structure de base :

```c
#include <stdio.h>  /* 1. Inclusion de bibliothèques */

/* 2. Déclarations de fonctions (prototypes) */
int addition(int a, int b);

/* 3. Fonction principale (point d'entrée) */
int main(void)
{
    /* 4. Déclaration des variables */
    int resultat;

    /* 5. Corps du programme */
    resultat = addition(5, 3);
    printf("Résultat: %d\n", resultat);

    /* 6. Valeur de retour */
    return (0);  /* 0 = succès, autre valeur = erreur */
}

/* 7. Définition des fonctions */
int addition(int a, int b)
{
    return (a + b);
}
```

**Points clés :**
- `#include` : importe des bibliothèques (comme `stdio.h` pour printf)
- `main()` : fonction obligatoire, point d'entrée du programme
- `return (0)` : indique que le programme s'est bien terminé
- `;` : chaque instruction se termine par un point-virgule
- `{ }` : délimitent un bloc de code

---

## 2. Variables et types de données

### 2.1 Qu'est-ce qu'une variable ?

Une **variable** est un espace en mémoire qui :
- A un **nom** (identificateur)
- A un **type** (entier, caractère, etc.)
- Contient une **valeur**

```c
int age = 25;  /* Variable 'age' de type 'int' valant 25 */
```

### 2.2 Types de données fondamentaux

| Type | Taille | Description | Plage de valeurs | Exemple |
|------|--------|-------------|------------------|---------|
| `char` | 1 octet | Caractère ou petit entier | -128 à 127 | `'A'`, `'z'`, `65` |
| `int` | 4 octets | Nombre entier | -2,147,483,648 à 2,147,483,647 | `42`, `-100` |
| `float` | 4 octets | Nombre décimal | ~7 chiffres de précision | `3.14f`, `-0.5f` |
| `double` | 8 octets | Nombre décimal (précis) | ~15 chiffres de précision | `3.14159265` |
| `long` | 8 octets | Entier long | Très grand entier | `123456789L` |
| `unsigned int` | 4 octets | Entier positif uniquement | 0 à 4,294,967,295 | `42u` |

### 2.3 Déclaration et initialisation

```c
/* Déclaration simple */
int nombre;

/* Déclaration avec initialisation */
int age = 25;

/* Déclarations multiples */
int a, b, c;
int x = 10, y = 20, z = 30;

/* IMPORTANT en C89 : déclarer toutes les variables AU DÉBUT du bloc */
int main(void)
{
    int a;  /* ✅ Déclarations en premier */
    int b;
    char c;

    a = 10;  /* Puis les instructions */
    b = 20;
    c = 'A';

    /* int d;  ❌ ERREUR en C89 : déclaration après une instruction */

    return (0);
}
```

### 2.4 Opérateurs arithmétiques

```c
int a = 10, b = 3;

a + b   /* Addition : 13 */
a - b   /* Soustraction : 7 */
a * b   /* Multiplication : 30 */
a / b   /* Division entière : 3 (pas 3.33 !) */
a % b   /* Modulo (reste) : 1 */

/* Opérateurs d'affectation combinés */
a += 5;  /* Équivalent à : a = a + 5 */
a -= 3;  /* Équivalent à : a = a - 3 */
a *= 2;  /* Équivalent à : a = a * 2 */
a /= 4;  /* Équivalent à : a = a / 4 */
a++;     /* Équivalent à : a = a + 1 */
a--;     /* Équivalent à : a = a - 1 */
```

**⚠️ Attention :**
- La division entre entiers donne un entier : `7 / 2 = 3` (pas 3.5)
- Pour avoir un résultat décimal : `7.0 / 2 = 3.5`
- Le modulo `%` ne fonctionne qu'avec des entiers

### 2.5 Code ASCII

Les caractères sont stockés sous forme de **nombres** (code ASCII) :

```c
char lettre = 'A';  /* En mémoire : 65 */
char chiffre = '0'; /* En mémoire : 48 */

/* Table ASCII importante : */
'0' à '9'  → 48 à 57
'A' à 'Z'  → 65 à 90
'a' à 'z'  → 97 à 122

/* Conversions utiles */
char majuscule = 'A';
char minuscule = majuscule + 32;  /* 'a' = 97 */

int nombre = 5;
char chiffre = '0' + nombre;  /* '5' = 53 */
```

---

## 3. Structures de contrôle

### 3.1 Conditions : if, else if, else

Les conditions permettent d'exécuter du code selon des critères :

```c
int age = 20;

/* if simple */
if (age >= 18)
{
    printf("Majeur\n");
}

/* if-else */
if (age >= 18)
{
    printf("Majeur\n");
}
else
{
    printf("Mineur\n");
}

/* if-else if-else */
if (age < 13)
{
    printf("Enfant\n");
}
else if (age < 18)
{
    printf("Adolescent\n");
}
else if (age < 65)
{
    printf("Adulte\n");
}
else
{
    printf("Senior\n");
}
```

### 3.2 Opérateurs de comparaison

```c
==  /* Égal à */
!=  /* Différent de */
<   /* Inférieur à */
>   /* Supérieur à */
<=  /* Inférieur ou égal à */
>=  /* Supérieur ou égal à */
```

**⚠️ Erreur fréquente :**
```c
if (x = 5)   /* ❌ ERREUR : affectation, pas comparaison */
if (x == 5)  /* ✅ CORRECT : comparaison */
```

### 3.3 Opérateurs logiques

```c
/* && : ET logique (les deux conditions doivent être vraies) */
if (age >= 18 && permis == 1)
{
    printf("Peut conduire\n");
}

/* || : OU logique (au moins une condition doit être vraie) */
if (jour == 0 || jour == 6)
{
    printf("Week-end\n");
}

/* ! : NON logique (inverse la condition) */
if (!erreur)
{
    printf("Pas d'erreur\n");
}
```

### 3.4 Boucle while

Répète un bloc **tant qu'une condition est vraie** :

```c
int i = 0;

while (i < 10)
{
    printf("%d\n", i);
    i++;  /* ⚠️ IMPORTANT : ne pas oublier d'incrémenter ! */
}
/* Affiche : 0 1 2 3 4 5 6 7 8 9 */

/* Boucle infinie (à éviter) */
while (1)  /* Ou while (true) */
{
    printf("Infini\n");
    /* Sans 'break', cette boucle ne s'arrête jamais */
}
```

### 3.5 Boucle do-while

Exécute le bloc **au moins une fois**, puis répète si la condition est vraie :

```c
int i = 0;

do
{
    printf("%d\n", i);
    i++;
} while (i < 10);

/* Différence avec while : le code s'exécute AU MOINS UNE FOIS */
int x = 10;
do
{
    printf("Exécuté\n");  /* S'affiche malgré x >= 10 */
} while (x < 10);
```

### 3.6 Boucle for

Boucle avec **compteur intégré** :

```c
int i;

for (i = 0; i < 10; i++)
{
    printf("%d\n", i);
}

/* Structure du for : */
for (initialisation; condition; incrémentation)
{
    /* Corps de la boucle */
}

/* Exemples */
for (i = 0; i < 10; i++)      /* 0 à 9 */
for (i = 1; i <= 10; i++)     /* 1 à 10 */
for (i = 10; i > 0; i--)      /* 10 à 1 (décroissant) */
for (i = 0; i < 10; i += 2)   /* 0, 2, 4, 6, 8 (pairs) */
```

### 3.7 Break et continue

```c
/* break : sort immédiatement de la boucle */
int i;
for (i = 0; i < 10; i++)
{
    if (i == 5)
        break;  /* Sort de la boucle quand i = 5 */
    printf("%d\n", i);
}
/* Affiche : 0 1 2 3 4 */

/* continue : passe à l'itération suivante */
for (i = 0; i < 10; i++)
{
    if (i % 2 == 0)
        continue;  /* Saute les nombres pairs */
    printf("%d\n", i);
}
/* Affiche : 1 3 5 7 9 */
```

---

## 4. Fonctions

### 4.1 Qu'est-ce qu'une fonction ?

Une **fonction** est un bloc de code réutilisable qui :
- A un **nom**
- Peut recevoir des **paramètres** (entrées)
- Peut **retourner** une valeur (sortie)
- Évite la duplication de code

```c
/* Syntaxe générale */
type_retour nom_fonction(type_param1 param1, type_param2 param2)
{
    /* Corps de la fonction */
    return valeur;
}
```

### 4.2 Déclaration et définition

```c
/* 1. PROTOTYPE (déclaration) - en haut du fichier ou dans .h */
int addition(int a, int b);

/* 2. UTILISATION - dans main() ou autre fonction */
int main(void)
{
    int resultat;

    resultat = addition(5, 3);  /* Appel de la fonction */
    printf("Résultat : %d\n", resultat);

    return (0);
}

/* 3. DÉFINITION - après main() */
int addition(int a, int b)
{
    return (a + b);
}
```

### 4.3 Types de fonctions

#### Fonction qui retourne une valeur

```c
int carre(int n)
{
    return (n * n);
}

int x = carre(5);  /* x = 25 */
```

#### Fonction sans retour (void)

```c
void afficher_message(void)
{
    printf("Bonjour\n");
}

afficher_message();  /* Pas d'affectation, juste un appel */
```

#### Fonction sans paramètre

```c
int lire_nombre(void)
{
    int n;
    scanf("%d", &n);
    return (n);
}
```

### 4.4 Passage par valeur vs passage par référence

#### Passage par valeur (copie)

```c
void modifier(int x)
{
    x = 100;  /* Modifie la copie locale */
}

int main(void)
{
    int nombre = 10;
    modifier(nombre);
    printf("%d\n", nombre);  /* Affiche : 10 (inchangé) */
    return (0);
}
```

#### Passage par référence (pointeur)

```c
void modifier(int *x)
{
    *x = 100;  /* Modifie la variable originale */
}

int main(void)
{
    int nombre = 10;
    modifier(&nombre);
    printf("%d\n", nombre);  /* Affiche : 100 (modifié) */
    return (0);
}
```

### 4.5 Fonctions importantes de la bibliothèque standard

#### stdio.h (Entrées/Sorties)

```c
#include <stdio.h>

printf("Format", variables);     /* Affichage formaté */
puts("Texte");                   /* Affiche avec \n automatique */
putchar('A');                    /* Affiche un caractère */
scanf("%d", &variable);          /* Lecture clavier */
```

#### string.h (Manipulation de chaînes)

```c
#include <string.h>

strlen(str);                     /* Longueur d'une chaîne */
strcpy(dest, src);               /* Copie une chaîne */
strcat(dest, src);               /* Concatène deux chaînes */
strcmp(str1, str2);              /* Compare deux chaînes */
```

#### stdlib.h (Utilitaires)

```c
#include <stdlib.h>

malloc(taille);                  /* Allocation mémoire */
free(ptr);                       /* Libération mémoire */
atoi(str);                       /* Convertit string → int */
exit(code);                      /* Termine le programme */
```

---

## 5. Pointeurs

### 5.1 Qu'est-ce qu'un pointeur ?

Un **pointeur** est une variable qui contient l'**adresse mémoire** d'une autre variable.

```c
int nombre = 42;       /* Variable normale */
int *ptr = &nombre;    /* Pointeur vers 'nombre' */

/* Opérateurs importants : */
&  /* Opérateur d'adresse : donne l'adresse d'une variable */
*  /* Opérateur de déréférencement : accède à la valeur pointée */
```

**Visualisation :**

```
Mémoire :
┌──────────┬──────────┐
│  0x1000  │    42    │  ← nombre (contient la valeur 42)
├──────────┼──────────┤
│  0x2000  │  0x1000  │  ← ptr (contient l'adresse de nombre)
└──────────┴──────────┘

int nombre = 42;      /* Crée une variable à l'adresse 0x1000 */
int *ptr = &nombre;   /* ptr contient 0x1000 */

printf("%d\n", nombre);   /* Affiche : 42 */
printf("%p\n", &nombre);  /* Affiche : 0x1000 (adresse) */
printf("%p\n", ptr);      /* Affiche : 0x1000 (même adresse) */
printf("%d\n", *ptr);     /* Affiche : 42 (déréférence) */
```

### 5.2 Déclaration et utilisation

```c
int nombre = 10;
int *ptr;           /* Déclare un pointeur vers int */

ptr = &nombre;      /* ptr pointe maintenant vers nombre */

/* Accès et modification */
printf("%d\n", *ptr);    /* Affiche : 10 */
*ptr = 20;               /* Modifie nombre via le pointeur */
printf("%d\n", nombre);  /* Affiche : 20 */
```

### 5.3 Pointeur NULL

```c
int *ptr = NULL;    /* Pointeur qui ne pointe vers rien */

/* Toujours vérifier avant de déréférencer ! */
if (ptr != NULL)
{
    *ptr = 10;  /* Sûr */
}
else
{
    printf("Pointeur NULL\n");
}
```

### 5.4 Pointeurs et fonctions

Les pointeurs permettent aux fonctions de **modifier** les variables passées en paramètre :

```c
void echanger(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int x = 5, y = 10;

    printf("Avant : x=%d, y=%d\n", x, y);
    echanger(&x, &y);
    printf("Après : x=%d, y=%d\n", x, y);

    /* Affiche :
     * Avant : x=5, y=10
     * Après : x=10, y=5
     */

    return (0);
}
```

### 5.5 Arithmétique des pointeurs

```c
int tab[5] = {10, 20, 30, 40, 50};
int *ptr = tab;  /* Pointe vers tab[0] */

printf("%d\n", *ptr);      /* 10 */
printf("%d\n", *(ptr+1));  /* 20 */
printf("%d\n", *(ptr+2));  /* 30 */

ptr++;  /* Avance d'un élément */
printf("%d\n", *ptr);      /* 20 */

/* Équivalences : */
tab[i]     ≡  *(tab + i)
&tab[i]    ≡  (tab + i)
```

---

## 6. Tableaux et chaînes de caractères

### 6.1 Tableaux

Un **tableau** est une collection d'éléments du **même type**, stockés en mémoire **contiguë**.

```c
/* Déclaration */
int nombres[5];  /* Tableau de 5 entiers */

/* Déclaration avec initialisation */
int nombres[5] = {10, 20, 30, 40, 50};

/* Taille déduite automatiquement */
int nombres[] = {10, 20, 30, 40, 50};  /* Taille = 5 */

/* Accès aux éléments (indices de 0 à n-1) */
nombres[0] = 10;  /* Premier élément */
nombres[4] = 50;  /* Dernier élément */

/* ⚠️ Attention : pas de vérification des bornes ! */
nombres[10] = 100;  /* ERREUR : hors limites (comportement indéfini) */
```

### 6.2 Parcours d'un tableau

```c
int tab[5] = {10, 20, 30, 40, 50};
int i;

/* Méthode 1 : avec indice */
for (i = 0; i < 5; i++)
{
    printf("%d ", tab[i]);
}

/* Méthode 2 : avec pointeur */
int *ptr;
for (ptr = tab; ptr < tab + 5; ptr++)
{
    printf("%d ", *ptr);
}
```

### 6.3 Tableaux multidimensionnels

```c
/* Tableau 2D (matrice) */
int matrice[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

/* Accès */
matrice[0][0] = 1;   /* Première ligne, première colonne */
matrice[2][3] = 12;  /* Dernière ligne, dernière colonne */

/* Parcours */
int i, j;
for (i = 0; i < 3; i++)
{
    for (j = 0; j < 4; j++)
    {
        printf("%d ", matrice[i][j]);
    }
    printf("\n");
}
```

### 6.4 Chaînes de caractères

En C, une **chaîne de caractères** est un **tableau de char** terminé par `\0` (caractère nul).

```c
/* Déclaration */
char nom[10] = "Alice";

/* En mémoire : */
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
│ A │ l │ i │ c │ e │ \0│   │   │   │   │
└───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
  0   1   2   3   4   5   6   7   8   9

/* Pointeur vers une chaîne constante */
char *message = "Bonjour";  /* ⚠️ Non modifiable ! */

/* Tableau modifiable */
char message[] = "Bonjour";  /* ✅ Modifiable */
message[0] = 'b';  /* "bonjour" */
```

### 6.5 Fonctions de manipulation de chaînes

```c
/* Longueur d'une chaîne */
int _strlen(char *s)
{
    int i = 0;

    while (s[i] != '\0')
        i++;

    return (i);
}

/* Copie d'une chaîne */
char *_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  /* ⚠️ Ne pas oublier ! */

    return (dest);
}

/* Comparaison de chaînes */
int _strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }

    return (s1[i] - s2[i]);
}

/* Concaténation */
char *_strcat(char *dest, char *src)
{
    int i = 0, j = 0;

    while (dest[i] != '\0')
        i++;

    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';

    return (dest);
}
```

### 6.6 Conversion de chaînes

```c
/* String → Int (atoi) */
int _atoi(char *s)
{
    int resultat = 0;
    int signe = 1;
    int i = 0;

    /* Gérer le signe */
    if (s[i] == '-')
    {
        signe = -1;
        i++;
    }
    else if (s[i] == '+')
    {
        i++;
    }

    /* Conversion */
    while (s[i] >= '0' && s[i] <= '9')
    {
        resultat = resultat * 10 + (s[i] - '0');
        i++;
    }

    return (resultat * signe);
}

/* Utilisation */
int nombre = _atoi("123");   /* nombre = 123 */
int negatif = _atoi("-456"); /* negatif = -456 */
```

---

## 7. Récursivité

### 7.1 Qu'est-ce que la récursivité ?

La **récursivité** est une technique où une fonction **s'appelle elle-même**.

**Composants essentiels :**
1. **Cas de base** : condition d'arrêt (sinon boucle infinie)
2. **Appel récursif** : la fonction s'appelle avec un problème plus petit

### 7.2 Exemple : Factorielle

```c
/* Définition mathématique :
 * 0! = 1 (cas de base)
 * n! = n × (n-1)! (cas récursif)
 */

int factorielle(int n)
{
    /* Cas de base */
    if (n == 0 || n == 1)
        return (1);

    /* Appel récursif */
    return (n * factorielle(n - 1));
}

/* Déroulement pour factorielle(5) :
 * factorielle(5) = 5 * factorielle(4)
 *                = 5 * (4 * factorielle(3))
 *                = 5 * (4 * (3 * factorielle(2)))
 *                = 5 * (4 * (3 * (2 * factorielle(1))))
 *                = 5 * (4 * (3 * (2 * 1)))
 *                = 120
 */
```

### 7.3 Pile d'appels

```
Pile d'appels pour factorielle(5) :

┌─────────────────┐
│ factorielle(1)  │ → retourne 1
├─────────────────┤
│ factorielle(2)  │ → retourne 2 × 1 = 2
├─────────────────┤
│ factorielle(3)  │ → retourne 3 × 2 = 6
├─────────────────┤
│ factorielle(4)  │ → retourne 4 × 6 = 24
├─────────────────┤
│ factorielle(5)  │ → retourne 5 × 24 = 120
└─────────────────┘
```

### 7.4 Exemples classiques

#### Puissance

```c
/* n^p = n × n^(p-1) */
int puissance(int n, int p)
{
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);  /* Ou gestion d'erreur */

    return (n * puissance(n, p - 1));
}
```

#### Suite de Fibonacci

```c
/* F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2) */
int fibonacci(int n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);

    return (fibonacci(n - 1) + fibonacci(n - 2));
}

/* Fibonacci(6) :
 * 0, 1, 1, 2, 3, 5, 8, 13, 21, 34...
 */
```

#### Nombre premier

```c
int est_premier_recursif(int n, int diviseur)
{
    /* Cas de base : n <= 1 n'est pas premier */
    if (n <= 1)
        return (0);

    /* Cas de base : diviseur² > n, n est premier */
    if (diviseur * diviseur > n)
        return (1);

    /* Si n est divisible par diviseur, pas premier */
    if (n % diviseur == 0)
        return (0);

    /* Tester le diviseur suivant */
    return (est_premier_recursif(n, diviseur + 1));
}

int est_premier(int n)
{
    return (est_premier_recursif(n, 2));
}
```

### 7.5 Récursivité vs Itération

| Critère | Récursivité | Itération (boucle) |
|---------|-------------|---------------------|
| **Lisibilité** | Code souvent plus clair | Peut être verbeux |
| **Performance** | Plus lente (pile d'appels) | Plus rapide |
| **Mémoire** | Consomme la pile | Consomme peu |
| **Risque** | Stack overflow possible | Boucle infinie possible |

**⚠️ Quand utiliser la récursivité ?**
- Problèmes naturellement récursifs (arbre, graphe)
- Code plus lisible et concis
- Profondeur limitée (< 1000 appels environ)

---

## 8. Gestion de la mémoire dynamique

### 8.1 Stack vs Heap

En C, la mémoire est divisée en deux zones principales :

```
┌─────────────────────┐ Adresses hautes
│       STACK         │ → Variables locales, paramètres
│   (Pile - auto)     │ → Taille fixe, gestion automatique
│         ↓           │ → Libérée automatiquement
├─────────────────────┤
│         ↑           │
│    HEAP (Tas)       │ → Allocation dynamique (malloc)
│  (Manuel - toi!)    │ → Taille flexible
│                     │ → DOIT être libéré avec free()
└─────────────────────┘ Adresses basses
```

### 8.2 malloc() - Allocation mémoire

```c
#include <stdlib.h>

/* Syntaxe */
void *malloc(size_t taille);

/* Alloue 'taille' octets et retourne un pointeur */
/* Retourne NULL en cas d'échec */

/* Exemples */
int *ptr;
char *str;
int *tableau;

/* Allouer un entier */
ptr = malloc(sizeof(int));
if (ptr == NULL)
{
    printf("Erreur d'allocation\n");
    return (1);
}
*ptr = 42;

/* Allouer une chaîne de 100 caractères */
str = malloc(100 * sizeof(char));
if (str == NULL)
{
    printf("Erreur\n");
    return (1);
}
strcpy(str, "Bonjour");

/* Allouer un tableau de 10 entiers */
tableau = malloc(10 * sizeof(int));
if (tableau == NULL)
{
    printf("Erreur\n");
    return (1);
}

/* Utilisation comme un tableau normal */
tableau[0] = 1;
tableau[5] = 42;
```

### 8.3 free() - Libération mémoire

```c
/* OBLIGATOIRE : libérer toute mémoire allouée ! */
free(ptr);
free(str);
free(tableau);

/* ⚠️ Erreurs courantes : */

/* 1. Oublier de free → fuite mémoire (memory leak) */
int *p = malloc(sizeof(int));
/* ... utilisation ... */
/* Oubli de free(p); ❌ */

/* 2. Double free → crash */
int *p = malloc(sizeof(int));
free(p);
free(p);  /* ❌ ERREUR : déjà libéré */

/* 3. Utiliser après free → comportement indéfini */
int *p = malloc(sizeof(int));
*p = 42;
free(p);
printf("%d\n", *p);  /* ❌ ERREUR : mémoire libérée */

/* 4. Free d'une variable stack → crash */
int x = 10;
free(&x);  /* ❌ ERREUR : x est sur la stack, pas le heap */
```

### 8.4 Bonnes pratiques

```c
/* 1. Toujours vérifier le retour de malloc */
int *ptr = malloc(sizeof(int));
if (ptr == NULL)
{
    fprintf(stderr, "Erreur d'allocation\n");
    return (1);
}

/* 2. Initialiser le pointeur après free */
free(ptr);
ptr = NULL;  /* Évite les "dangling pointers" */

/* 3. Utiliser sizeof pour la portabilité */
int *tab = malloc(n * sizeof(*tab));  /* ✅ */
/* au lieu de : */
int *tab = malloc(n * 4);  /* ❌ (4 n'est pas toujours la taille d'un int) */

/* 4. Libérer dans l'ordre inverse de l'allocation */
char *s1 = malloc(10);
char *s2 = malloc(20);
/* ... */
free(s2);
free(s1);
```

### 8.5 calloc() - Allocation avec initialisation

```c
/* calloc initialise la mémoire à 0 */
void *calloc(size_t nmemb, size_t size);

/* malloc vs calloc */
int *tab1 = malloc(10 * sizeof(int));  /* Contenu aléatoire */
int *tab2 = calloc(10, sizeof(int));   /* Tous les éléments = 0 */

/* Équivalent à : */
int *tab = malloc(10 * sizeof(int));
memset(tab, 0, 10 * sizeof(int));
```

### 8.6 realloc() - Redimensionner une allocation

```c
/* Change la taille d'un bloc déjà alloué */
void *realloc(void *ptr, size_t nouvelle_taille);

int *tab = malloc(5 * sizeof(int));
/* ... remplir le tableau ... */

/* Besoin de plus d'espace */
tab = realloc(tab, 10 * sizeof(int));
if (tab == NULL)
{
    printf("Erreur de realloc\n");
    return (1);
}

/* ⚠️ realloc peut déplacer le bloc en mémoire ! */
/* Les pointeurs vers l'ancien bloc deviennent invalides */
```

### 8.7 Détecter les fuites mémoire avec Valgrind

```bash
# Compiler avec -g pour les infos de débogage
gcc -g -Wall -Werror fichier.c -o prog

# Exécuter avec valgrind
valgrind ./prog

# Rapport détaillé
valgrind --leak-check=full --show-leak-kinds=all ./prog

# Résultat attendu (aucune fuite) :
# ==12345== All heap blocks were freed -- no leaks are possible
```

---

## 9. Structures et typedef

### 9.1 Qu'est-ce qu'une structure ?

Une **structure** est un type de données personnalisé qui regroupe plusieurs variables (appelées **membres** ou **champs**).

```c
/* Déclaration d'une structure */
struct Personne
{
    char nom[50];
    int age;
    float taille;
};

/* Utilisation */
struct Personne p1;

/* Accès aux membres avec . (point) */
strcpy(p1.nom, "Alice");
p1.age = 25;
p1.taille = 1.70;

printf("Nom: %s, Age: %d, Taille: %.2f\n", p1.nom, p1.age, p1.taille);
```

### 9.2 typedef - Créer un alias

```c
/* Sans typedef : */
struct Personne p1;  /* Il faut écrire "struct" à chaque fois */

/* Avec typedef : */
typedef struct Personne
{
    char nom[50];
    int age;
    float taille;
} Personne;

/* Maintenant on peut écrire simplement : */
Personne p1;  /* Plus besoin de "struct" */

/* Ou encore plus court : */
typedef struct
{
    char nom[50];
    int age;
    float taille;
} Personne;
```

### 9.3 Structures et pointeurs

```c
typedef struct
{
    char nom[50];
    int age;
} Personne;

/* Pointeur vers une structure */
Personne *ptr;
Personne p1;

ptr = &p1;

/* Deux façons d'accéder aux membres : */

/* Méthode 1 : déréférencer puis accéder */
(*ptr).age = 25;

/* Méthode 2 : opérateur -> (préférée) */
ptr->age = 25;
strcpy(ptr->nom, "Alice");

/* Équivalence : */
ptr->age     ≡  (*ptr).age
ptr->nom     ≡  (*ptr).nom
```

### 9.4 Structures imbriquées

```c
typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;

typedef struct
{
    char nom[50];
    Date naissance;  /* Structure dans une structure */
} Personne;

/* Utilisation */
Personne p;
strcpy(p.nom, "Bob");
p.naissance.jour = 15;
p.naissance.mois = 3;
p.naissance.annee = 1998;

printf("%s est né le %d/%d/%d\n",
       p.nom, p.naissance.jour, p.naissance.mois, p.naissance.annee);
```

### 9.5 Allocation dynamique de structures

```c
typedef struct
{
    char nom[50];
    int age;
} Personne;

/* Allouer une structure */
Personne *p = malloc(sizeof(Personne));
if (p == NULL)
    return (1);

/* Utiliser avec -> */
strcpy(p->nom, "Charlie");
p->age = 30;

/* Libérer */
free(p);

/* Allouer un tableau de structures */
Personne *groupe = malloc(10 * sizeof(Personne));
if (groupe == NULL)
    return (1);

/* Accès : */
groupe[0].age = 20;
strcpy(groupe[1].nom, "David");

free(groupe);
```

### 9.6 Exemple complet : Chien

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *nom;
    float age;
    char *proprietaire;
} dog_t;

/* Créer un nouveau chien */
dog_t *new_dog(char *nom, float age, char *proprietaire)
{
    dog_t *chien;

    chien = malloc(sizeof(dog_t));
    if (chien == NULL)
        return (NULL);

    chien->nom = malloc(strlen(nom) + 1);
    if (chien->nom == NULL)
    {
        free(chien);
        return (NULL);
    }
    strcpy(chien->nom, nom);

    chien->age = age;

    chien->proprietaire = malloc(strlen(proprietaire) + 1);
    if (chien->proprietaire == NULL)
    {
        free(chien->nom);
        free(chien);
        return (NULL);
    }
    strcpy(chien->proprietaire, proprietaire);

    return (chien);
}

/* Libérer un chien */
void free_dog(dog_t *d)
{
    if (d == NULL)
        return;

    free(d->nom);
    free(d->proprietaire);
    free(d);
}

/* Afficher un chien */
void print_dog(dog_t *d)
{
    if (d == NULL)
        return;

    printf("Nom: %s\n", d->nom ? d->nom : "(nil)");
    printf("Age: %.1f\n", d->age);
    printf("Propriétaire: %s\n", d->proprietaire ? d->proprietaire : "(nil)");
}

int main(void)
{
    dog_t *rex = new_dog("Rex", 3.5, "Alice");

    if (rex != NULL)
    {
        print_dog(rex);
        free_dog(rex);
    }

    return (0);
}
```

---

## 10. Pointeurs de fonctions

### 10.1 Qu'est-ce qu'un pointeur de fonction ?

Un **pointeur de fonction** est une variable qui contient l'**adresse d'une fonction**.

```c
/* Déclaration d'une fonction normale */
int addition(int a, int b)
{
    return (a + b);
}

/* Déclaration d'un pointeur de fonction */
int (*ptr_func)(int, int);

/* Assigner l'adresse de la fonction */
ptr_func = &addition;  /* ou simplement: ptr_func = addition; */

/* Appeler la fonction via le pointeur */
int resultat = ptr_func(5, 3);  /* Équivalent à : addition(5, 3) */
printf("%d\n", resultat);  /* Affiche : 8 */
```

### 10.2 Syntaxe

```c
/* Syntaxe générale : */
type_retour (*nom_pointeur)(type_param1, type_param2, ...);

/* Exemples : */
int (*func_ptr)(int, int);           /* Pointeur vers fonction (int, int) → int */
void (*action)(void);                /* Pointeur vers fonction (void) → void */
char *(*get_str)(int);               /* Pointeur vers fonction (int) → char* */
```

### 10.3 Utilité : Callbacks

Les pointeurs de fonctions permettent de passer des fonctions en **paramètre** :

```c
/* Fonction qui applique une opération à deux nombres */
int calculer(int a, int b, int (*operation)(int, int))
{
    return (operation(a, b));
}

/* Différentes opérations */
int addition(int a, int b) { return (a + b); }
int soustraction(int a, int b) { return (a - b); }
int multiplication(int a, int b) { return (a * b); }

int main(void)
{
    printf("%d\n", calculer(10, 5, addition));        /* 15 */
    printf("%d\n", calculer(10, 5, soustraction));    /* 5 */
    printf("%d\n", calculer(10, 5, multiplication));  /* 50 */

    return (0);
}
```

### 10.4 Tableau de pointeurs de fonctions

```c
/* Calculatrice simple */
int addition(int a, int b) { return (a + b); }
int soustraction(int a, int b) { return (a - b); }
int multiplication(int a, int b) { return (a * b); }
int division(int a, int b) { return (a / b); }

int main(void)
{
    /* Tableau de pointeurs de fonctions */
    int (*operations[4])(int, int) = {
        addition,
        soustraction,
        multiplication,
        division
    };

    int a = 20, b = 5;
    int i;
    char ops[] = {'+', '-', '*', '/'};

    for (i = 0; i < 4; i++)
    {
        printf("%d %c %d = %d\n", a, ops[i], b, operations[i](a, b));
    }

    /* Affiche :
     * 20 + 5 = 25
     * 20 - 5 = 15
     * 20 * 5 = 100
     * 20 / 5 = 4
     */

    return (0);
}
```

### 10.5 Exemple : Fonction de comparaison

```c
/* Fonction de tri avec comparateur personnalisé */
void tri_bulle(int *tab, int taille, int (*compare)(int, int))
{
    int i, j, temp;

    for (i = 0; i < taille - 1; i++)
    {
        for (j = 0; j < taille - i - 1; j++)
        {
            if (compare(tab[j], tab[j + 1]) > 0)
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

/* Comparateurs */
int croissant(int a, int b) { return (a - b); }
int decroissant(int a, int b) { return (b - a); }

int main(void)
{
    int tab[] = {5, 2, 8, 1, 9};
    int i;

    tri_bulle(tab, 5, croissant);
    for (i = 0; i < 5; i++)
        printf("%d ", tab[i]);  /* 1 2 5 8 9 */
    printf("\n");

    tri_bulle(tab, 5, decroissant);
    for (i = 0; i < 5; i++)
        printf("%d ", tab[i]);  /* 9 8 5 2 1 */
    printf("\n");

    return (0);
}
```

---

## 11. Fonctions variadiques

### 11.1 Qu'est-ce qu'une fonction variadique ?

Une **fonction variadique** peut accepter un **nombre variable d'arguments**.

Exemples : `printf()`, `scanf()`, `sum()`, etc.

```c
printf("%d", 42);                    /* 1 argument */
printf("%d %s", 42, "test");         /* 2 arguments */
printf("%d %s %f", 42, "test", 3.14); /* 3 arguments */
```

### 11.2 Macros nécessaires

```c
#include <stdarg.h>

/* Macros importantes : */
va_list ap;           /* Déclare une liste d'arguments variables */
va_start(ap, dernier);/* Initialise la liste (dernier = dernier param fixe) */
va_arg(ap, type);     /* Récupère le prochain argument du type spécifié */
va_end(ap);           /* Termine l'utilisation de la liste */
```

### 11.3 Syntaxe

```c
type_retour fonction(type param1, ...)
{
    va_list ap;

    va_start(ap, param1);  /* param1 = dernier paramètre fixe */

    /* Récupérer les arguments */
    int arg1 = va_arg(ap, int);
    char *arg2 = va_arg(ap, char*);

    va_end(ap);
}
```

### 11.4 Exemple : Somme de n nombres

```c
#include <stdarg.h>

/* Somme de n entiers */
int somme(int count, ...)
{
    va_list ap;
    int total = 0;
    int i;

    va_start(ap, count);  /* count = dernier param fixe */

    for (i = 0; i < count; i++)
    {
        total += va_arg(ap, int);  /* Récupère un int */
    }

    va_end(ap);

    return (total);
}

int main(void)
{
    printf("%d\n", somme(3, 10, 20, 30));        /* 60 */
    printf("%d\n", somme(5, 1, 2, 3, 4, 5));     /* 15 */
    printf("%d\n", somme(2, 100, 200));          /* 300 */

    return (0);
}
```

### 11.5 Exemple : Affichage formaté personnalisé

```c
#include <stdarg.h>
#include <stdio.h>

/* Affiche différents types selon le format */
void print_all(const char *format, ...)
{
    va_list ap;
    int i = 0;
    char *separateur = "";

    va_start(ap, format);

    while (format[i] != '\0')
    {
        printf("%s", separateur);

        switch (format[i])
        {
            case 'c':  /* Caractère */
                printf("%c", va_arg(ap, int));  /* char promu en int */
                break;
            case 'i':  /* Entier */
                printf("%d", va_arg(ap, int));
                break;
            case 'f':  /* Float */
                printf("%f", va_arg(ap, double));  /* float promu en double */
                break;
            case 's':  /* String */
                printf("%s", va_arg(ap, char*));
                break;
        }

        separateur = ", ";
        i++;
    }

    va_end(ap);
    printf("\n");
}

int main(void)
{
    print_all("cifs", 'H', 42, 3.14, "Holberton");
    /* Affiche : H, 42, 3.140000, Holberton */

    return (0);
}
```

### 11.6 Promotions automatiques

⚠️ **Important :** Les petits types sont automatiquement promus :

```c
char  → int      /* Utiliser va_arg(ap, int) pour récupérer un char */
short → int      /* Utiliser va_arg(ap, int) pour récupérer un short */
float → double   /* Utiliser va_arg(ap, double) pour récupérer un float */
```

### 11.7 Points d'attention

```c
/* ❌ ERREUR : impossible de savoir le nombre d'arguments */
void fonction_incorrecte(...)  /* Pas de paramètre fixe ! */
{
    /* Comment initialiser va_start ? */
}

/* ✅ CORRECT : au moins un paramètre fixe */
void fonction_correcte(int count, ...)
{
    va_list ap;
    va_start(ap, count);  /* count indique le nombre d'args */
    /* ... */
    va_end(ap);
}

/* ⚠️ Attention : pas de vérification de type ! */
int x = va_arg(ap, int);      /* Si l'arg n'est pas un int → comportement indéfini */
char *s = va_arg(ap, char*);  /* Si l'arg n'est pas un char* → crash possible */
```

---

## 12. Listes chaînées

### 12.1 Qu'est-ce qu'une liste chaînée ?

Une **liste chaînée** est une structure de données où chaque élément (appelé **nœud**) contient :
1. Une **donnée**
2. Un **pointeur** vers le nœud suivant

```
┌──────┬──────┐    ┌──────┬──────┐    ┌──────┬──────┐
│  10  │  ────┼───→│  20  │  ────┼───→│  30  │ NULL │
└──────┴──────┘    └──────┴──────┘    └──────┴──────┘
  Nœud 1             Nœud 2             Nœud 3
```

### 12.2 Structure d'un nœud

```c
typedef struct node
{
    int donnee;
    struct node *next;  /* Pointeur vers le nœud suivant */
} node_t;
```

### 12.3 Opérations de base

#### Créer une liste

```c
/* Créer un nouveau nœud */
node_t *creer_noeud(int valeur)
{
    node_t *nouveau = malloc(sizeof(node_t));

    if (nouveau == NULL)
        return (NULL);

    nouveau->donnee = valeur;
    nouveau->next = NULL;

    return (nouveau);
}

/* Créer une liste : 10 → 20 → 30 → NULL */
node_t *tete = creer_noeud(10);
tete->next = creer_noeud(20);
tete->next->next = creer_noeud(30);
```

#### Parcourir une liste

```c
void afficher_liste(node_t *tete)
{
    node_t *courant = tete;

    while (courant != NULL)
    {
        printf("%d -> ", courant->donnee);
        courant = courant->next;
    }
    printf("NULL\n");
}
```

#### Ajouter au début

```c
node_t *ajouter_debut(node_t *tete, int valeur)
{
    node_t *nouveau = creer_noeud(valeur);

    if (nouveau == NULL)
        return (tete);

    nouveau->next = tete;  /* Le nouveau pointe vers l'ancienne tête */

    return (nouveau);  /* Le nouveau devient la tête */
}

/* Utilisation */
tete = ajouter_debut(tete, 5);
/* Liste : 5 → 10 → 20 → 30 → NULL */
```

#### Ajouter à la fin

```c
node_t *ajouter_fin(node_t *tete, int valeur)
{
    node_t *nouveau = creer_noeud(valeur);
    node_t *courant;

    if (nouveau == NULL)
        return (tete);

    /* Si la liste est vide */
    if (tete == NULL)
        return (nouveau);

    /* Parcourir jusqu'au dernier nœud */
    courant = tete;
    while (courant->next != NULL)
        courant = courant->next;

    courant->next = nouveau;

    return (tete);
}
```

#### Supprimer un nœud

```c
node_t *supprimer(node_t *tete, int valeur)
{
    node_t *courant = tete;
    node_t *precedent = NULL;

    /* Si le nœud à supprimer est la tête */
    if (tete != NULL && tete->donnee == valeur)
    {
        node_t *temp = tete;
        tete = tete->next;
        free(temp);
        return (tete);
    }

    /* Chercher le nœud */
    while (courant != NULL && courant->donnee != valeur)
    {
        precedent = courant;
        courant = courant->next;
    }

    /* Si trouvé */
    if (courant != NULL)
    {
        precedent->next = courant->next;
        free(courant);
    }

    return (tete);
}
```

#### Libérer toute la liste

```c
void liberer_liste(node_t *tete)
{
    node_t *courant = tete;
    node_t *temp;

    while (courant != NULL)
    {
        temp = courant;
        courant = courant->next;
        free(temp);
    }
}
```

### 12.4 Liste doublement chaînée

Chaque nœud a **deux pointeurs** : vers le suivant ET le précédent.

```c
typedef struct dnode
{
    int donnee;
    struct dnode *next;  /* Nœud suivant */
    struct dnode *prev;  /* Nœud précédent */
} dnode_t;
```

```
        ┌──────┬──────┬──────┐
 NULL ←─┤ prev │  10  │ next ├─→
        └──────┴──────┴──────┘
                  ↓
        ┌──────┬──────┬──────┐
     ←─┤ prev │  20  │ next ├─→
        └──────┴──────┴──────┘
                  ↓
        ┌──────┬──────┬──────┐
     ←─┤ prev │  30  │ next ├─→ NULL
        └──────┴──────┴──────┘
```

**Avantages :**
- Parcours bidirectionnel (avant ↔ arrière)
- Suppression plus facile (accès direct au précédent)

**Inconvénients :**
- Plus de mémoire (deux pointeurs)
- Gestion plus complexe

### 12.5 Liste vs Tableau

| Critère | Tableau | Liste chaînée |
|---------|---------|---------------|
| **Accès** | O(1) direct | O(n) séquentiel |
| **Insertion début** | O(n) (décalage) | O(1) |
| **Insertion fin** | O(1) | O(n) ou O(1) si ptr fin |
| **Suppression** | O(n) (décalage) | O(1) si pointeur connu |
| **Mémoire** | Contiguë, fixe | Dispersée, dynamique |
| **Taille** | Fixe | Dynamique |

---

## 13. Arguments de ligne de commande

### 13.1 argc et argv

Quand tu exécutes un programme, tu peux lui passer des **arguments** :

```bash
./programme arg1 arg2 arg3
```

Ces arguments sont accessibles via :

```c
int main(int argc, char *argv[])
{
    /* argc = nombre d'arguments (y compris le nom du programme) */
    /* argv = tableau de chaînes contenant les arguments */
}
```

### 13.2 Structure de argv

```bash
./programme hello world 123
```

```c
argc = 4

argv[0] = "./programme"  /* Nom du programme */
argv[1] = "hello"        /* Premier argument */
argv[2] = "world"        /* Deuxième argument */
argv[3] = "123"          /* Troisième argument */
argv[4] = NULL           /* Marqueur de fin */
```

### 13.3 Exemple : Afficher tous les arguments

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    printf("Nombre d'arguments : %d\n", argc);

    for (i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    return (0);
}
```

```bash
$ ./prog Hello World
Nombre d'arguments : 3
argv[0] = ./prog
argv[1] = Hello
argv[2] = World
```

### 13.4 Exemple : Addition de deux nombres

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a, b, somme;

    /* Vérifier le nombre d'arguments */
    if (argc != 3)
    {
        printf("Usage: %s nombre1 nombre2\n", argv[0]);
        return (1);
    }

    /* Convertir les chaînes en entiers */
    a = atoi(argv[1]);
    b = atoi(argv[2]);

    somme = a + b;

    printf("%d\n", somme);

    return (0);
}
```

```bash
$ ./add 5 3
8
$ ./add 100 200
300
$ ./add
Usage: ./add nombre1 nombre2
```

### 13.5 Exemple : Multiplication de nombres

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    int produit = 1;

    /* Si aucun argument, afficher 0 */
    if (argc == 1)
    {
        printf("0\n");
        return (0);
    }

    /* Multiplier tous les arguments */
    for (i = 1; i < argc; i++)
    {
        produit *= atoi(argv[i]);
    }

    printf("%d\n", produit);

    return (0);
}
```

```bash
$ ./mul 2 3 4
24
$ ./mul 5 5
25
$ ./mul
0
```

### 13.6 Points importants

```c
/* ⚠️ argv[] contient des CHAÎNES, pas des nombres */
int main(int argc, char *argv[])
{
    /* ❌ ERREUR : */
    int x = argv[1];  /* argv[1] est un char*, pas un int */

    /* ✅ CORRECT : */
    int x = atoi(argv[1]);  /* Convertir avec atoi() */
}

/* ⚠️ Toujours vérifier argc avant d'accéder à argv */
if (argc > 1)
{
    printf("%s\n", argv[1]);  /* ✅ Sûr */
}

/* ❌ Pas de vérification : */
printf("%s\n", argv[1]);  /* CRASH si argc == 1 */

/* ⚠️ Les espaces séparent les arguments */
$ ./prog hello world      # argc=3 : "./prog", "hello", "world"
$ ./prog "hello world"    # argc=2 : "./prog", "hello world"

/* ⚠️ Caractères spéciaux doivent être échappés */
$ ./prog test*            # * est expansé par le shell
$ ./prog 'test*'          # Correct : test* littéral
```

---

## 14. Entrées/Sorties fichiers

### 14.1 Descripteurs de fichiers

En C, un fichier est identifié par un **descripteur de fichier** (file descriptor), un simple entier.

**Descripteurs standards :**

```c
0 = STDIN_FILENO   /* Entrée standard (clavier) */
1 = STDOUT_FILENO  /* Sortie standard (écran) */
2 = STDERR_FILENO  /* Sortie d'erreur */
```

### 14.2 Fonctions principales

```c
#include <fcntl.h>   /* Flags O_RDONLY, O_WRONLY, etc. */
#include <unistd.h>  /* read, write, close */

int open(const char *pathname, int flags, mode_t mode);
ssize_t read(int fd, void *buf, size_t count);
ssize_t write(int fd, const void *buf, size_t count);
int close(int fd);
```

### 14.3 Ouvrir un fichier : open()

```c
int fd;

/* Ouvrir en lecture seule */
fd = open("fichier.txt", O_RDONLY);

/* Ouvrir en écriture (créer si n'existe pas) */
fd = open("fichier.txt", O_WRONLY | O_CREAT, 0644);

/* Ouvrir en écriture (ajouter à la fin) */
fd = open("fichier.txt", O_WRONLY | O_APPEND);

/* Vérifier si l'ouverture a réussi */
if (fd == -1)
{
    perror("Erreur ouverture");  /* Affiche le message d'erreur */
    return (1);
}
```

**Flags importants :**

| Flag | Description |
|------|-------------|
| `O_RDONLY` | Lecture seule |
| `O_WRONLY` | Écriture seule |
| `O_RDWR` | Lecture et écriture |
| `O_CREAT` | Créer le fichier s'il n'existe pas |
| `O_TRUNC` | Tronquer (vider) le fichier existant |
| `O_APPEND` | Ajouter à la fin du fichier |

**Permissions (mode) :**

```c
0644  /* rw-r--r-- : propriétaire=lecture/écriture, autres=lecture */
0755  /* rwxr-xr-x : propriétaire=tout, autres=lecture/exécution */
0600  /* rw------- : propriétaire=lecture/écriture, autres=rien */
```

### 14.4 Lire un fichier : read()

```c
ssize_t read(int fd, void *buffer, size_t count);
/* Lit 'count' octets depuis fd vers buffer */
/* Retourne : nombre d'octets lus, 0 si fin de fichier, -1 si erreur */

/* Exemple */
char buffer[1024];
ssize_t bytes_read;
int fd;

fd = open("fichier.txt", O_RDONLY);
if (fd == -1)
{
    perror("open");
    return (1);
}

bytes_read = read(fd, buffer, 1024);
if (bytes_read == -1)
{
    perror("read");
    close(fd);
    return (1);
}

printf("Lu %ld octets\n", bytes_read);

close(fd);
```

### 14.5 Écrire dans un fichier : write()

```c
ssize_t write(int fd, const void *buffer, size_t count);
/* Écrit 'count' octets depuis buffer vers fd */
/* Retourne : nombre d'octets écrits, -1 si erreur */

/* Exemple */
int fd;
char *texte = "Bonjour le monde\n";

fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (fd == -1)
{
    perror("open");
    return (1);
}

if (write(fd, texte, strlen(texte)) == -1)
{
    perror("write");
    close(fd);
    return (1);
}

close(fd);
```

### 14.6 Fermer un fichier : close()

```c
int close(int fd);
/* Ferme le descripteur de fichier */
/* Retourne : 0 si succès, -1 si erreur */

/* ⚠️ TOUJOURS fermer les fichiers après usage ! */
int fd = open("fichier.txt", O_RDONLY);
/* ... utilisation ... */
close(fd);
```

### 14.7 Exemple complet : Copie de fichier

```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

int copier_fichier(char *src, char *dest)
{
    int fd_src, fd_dest;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    /* Ouvrir le fichier source */
    fd_src = open(src, O_RDONLY);
    if (fd_src == -1)
    {
        perror("Erreur lecture fichier source");
        return (-1);
    }

    /* Créer le fichier destination */
    fd_dest = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_dest == -1)
    {
        perror("Erreur création fichier destination");
        close(fd_src);
        return (-1);
    }

    /* Copier par blocs */
    while ((bytes_read = read(fd_src, buffer, BUFFER_SIZE)) > 0)
    {
        bytes_written = write(fd_dest, buffer, bytes_read);
        if (bytes_written != bytes_read)
        {
            perror("Erreur écriture");
            close(fd_src);
            close(fd_dest);
            return (-1);
        }
    }

    if (bytes_read == -1)
    {
        perror("Erreur lecture");
        close(fd_src);
        close(fd_dest);
        return (-1);
    }

    /* Fermer les fichiers */
    close(fd_src);
    close(fd_dest);

    return (0);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s fichier_source fichier_dest\n", argv[0]);
        return (1);
    }

    if (copier_fichier(argv[1], argv[2]) == -1)
        return (1);

    printf("Copie réussie\n");
    return (0);
}
```

### 14.8 Gestion des erreurs

```c
/* perror() : affiche un message d'erreur descriptif */
if (open("fichier.txt", O_RDONLY) == -1)
{
    perror("open");  /* Affiche : "open: No such file or directory" */
    return (1);
}

/* dprintf() : écrire sur un descripteur de fichier */
dprintf(STDERR_FILENO, "Erreur : %s\n", "fichier introuvable");

/* fprintf() : version avec FILE* */
fprintf(stderr, "Erreur : %s\n", "fichier introuvable");
```

### 14.9 open() vs fopen()

| Fonction | Niveau | Retour | Buffer | Usage |
|----------|--------|--------|--------|-------|
| `open()` | Bas niveau (système) | File descriptor (int) | Non bufferisé | Plus rapide, contrôle fin |
| `fopen()` | Haut niveau (stdio) | FILE* | Bufferisé | Plus simple, portable |

```c
/* open() (bas niveau) */
int fd = open("file.txt", O_RDONLY);
char buf[100];
read(fd, buf, 100);
close(fd);

/* fopen() (haut niveau) */
FILE *fp = fopen("file.txt", "r");
char buf[100];
fgets(buf, 100, fp);
fclose(fp);
```

---

## 15. Récapitulatif et bonnes pratiques

### 15.1 Progression d'apprentissage

Voici le parcours que tu as suivi :

```
1. Hello World
   ↓ Compilation, structure de base
2. Variables, if/else, while
   ↓ Types, conditions, boucles
3. Fonctions
   ↓ Réutilisation de code, modularité
4. Pointeurs
   ↓ Adresses mémoire, passage par référence
5. Tableaux et chaînes
   ↓ Collections de données
6. Récursivité
   ↓ Fonctions qui s'appellent elles-mêmes
7. Allocation dynamique
   ↓ malloc/free, gestion manuelle de la mémoire
8. Structures
   ↓ Types personnalisés
9. Pointeurs de fonctions
   ↓ Callbacks, flexibilité
10. Fonctions variadiques
    ↓ Nombre variable d'arguments
11. Listes chaînées
    ↓ Structures de données dynamiques
12. argc/argv
    ↓ Arguments de ligne de commande
13. File I/O
    ↓ Lecture/écriture de fichiers
```

### 15.2 Règles d'or en C

#### Compilation

```bash
# Toujours compiler avec tous les warnings :
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 fichier.c -o prog

# Vérifier les fuites mémoire :
valgrind --leak-check=full ./prog
```

#### Style de code (Betty)

```c
/* ✅ BON STYLE */

/**
 * addition - Additionne deux nombres
 * @a: Premier nombre
 * @b: Deuxième nombre
 *
 * Return: La somme de a et b
 */
int addition(int a, int b)
{
    int resultat;

    resultat = a + b;
    return (resultat);
}

/* ❌ MAUVAIS STYLE */
int addition(int a,int b){return a+b;}  /* Illisible */
```

#### Gestion de la mémoire

```c
/* ✅ Toujours libérer ce que tu alloues */
char *str = malloc(100);
if (str != NULL)
{
    /* ... utilisation ... */
    free(str);
    str = NULL;  /* Bonne pratique */
}

/* ❌ Fuite mémoire */
char *str = malloc(100);
/* Oubli de free(str) */
```

#### Vérification des erreurs

```c
/* ✅ Vérifier tous les retours de fonction */
int fd = open("file.txt", O_RDONLY);
if (fd == -1)
{
    perror("open");
    return (1);
}

char *ptr = malloc(100);
if (ptr == NULL)
{
    fprintf(stderr, "Erreur allocation\n");
    return (1);
}
```

#### Pointeurs

```c
/* ✅ Initialiser les pointeurs */
int *ptr = NULL;

/* ✅ Vérifier avant de déréférencer */
if (ptr != NULL)
    *ptr = 10;

/* ❌ Déréférencement dangereux */
int *ptr;  /* Non initialisé */
*ptr = 10;  /* CRASH probable */
```

### 15.3 Erreurs courantes à éviter

```c
/* 1. Oublier \0 dans les chaînes */
char str[5] = {'H', 'e', 'l', 'l', 'o'};  /* ❌ Pas de \0 */
char str[6] = {'H', 'e', 'l', 'l', 'o', '\0'};  /* ✅ */

/* 2. Confondre = et == */
if (x = 5)  /* ❌ Affectation, pas comparaison */
if (x == 5)  /* ✅ Comparaison */

/* 3. Débordement de tableau */
int tab[10];
tab[10] = 5;  /* ❌ Hors limites (indices 0-9) */
tab[9] = 5;   /* ✅ */

/* 4. Division entière */
int a = 7, b = 2;
float resultat = a / b;  /* ❌ resultat = 3.0 (division entière) */
float resultat = (float)a / b;  /* ✅ resultat = 3.5 */

/* 5. Utiliser une variable non initialisée */
int x;
printf("%d\n", x);  /* ❌ Valeur aléatoire */

int x = 0;
printf("%d\n", x);  /* ✅ */
```

### 15.4 Outils indispensables

```bash
# Compilateur
gcc -Wall -Wextra -Werror -pedantic -std=gnu89

# Vérification de style (Betty)
betty fichier.c

# Détection de fuites mémoire
valgrind --leak-check=full ./programme

# Débogueur
gdb ./programme

# Analyse statique
cppcheck fichier.c

# Formatage automatique
indent -linux fichier.c
```

### 15.5 Ressources pour continuer

#### Documentation

```bash
man fonction  # Manuel des fonctions (ex: man malloc)
man 2 open    # Section 2 : appels système
man 3 printf  # Section 3 : bibliothèques C
```

#### Livres recommandés

- **"The C Programming Language"** (K&R) - Dennis Ritchie & Brian Kernighan
- **"C Programming: A Modern Approach"** - K. N. King
- **"Beej's Guide to C Programming"** (gratuit en ligne)

#### Sites web

- [Learn-C.org](https://www.learn-c.org/)
- [C Reference](https://en.cppreference.com/w/c)
- [GeeksforGeeks C Programming](https://www.geeksforgeeks.org/c-programming-language/)

### 15.6 Prochaines étapes

Maintenant que tu maîtrises les bases du C, tu peux explorer :

1. **Structures de données avancées**
   - Arbres binaires
   - Tables de hachage
   - Graphes

2. **Algorithmes**
   - Tri (quicksort, mergesort)
   - Recherche (binaire, profondeur/largeur)
   - Algorithmes de graphes

3. **Programmation système**
   - Processus (fork, exec)
   - Signaux
   - Threads

4. **Réseaux**
   - Sockets
   - Protocoles TCP/IP

5. **Projet personnel**
   - Shell simple
   - Éditeur de texte
   - Jeu en terminal

---

## 🎓 Félicitations !

Tu as maintenant une base solide en programmation C. Continue à pratiquer, à lire du code, et surtout à **coder** ! La maîtrise vient avec la pratique régulière.

**Remember :**
- Le C est un langage puissant mais exigeant
- Toujours compiler avec `-Wall -Wextra -Werror`
- Toujours vérifier les erreurs et libérer la mémoire
- Le débogage fait partie de l'apprentissage

**Good luck et bon code ! 🚀**

---

*Document créé pour les étudiants de première année - Holberton School*
*Mis à jour : 2026*
