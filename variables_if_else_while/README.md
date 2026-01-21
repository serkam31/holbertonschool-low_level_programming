# Variables, if, else, while - Structures de contrôle

## 📖 Description

Ce module introduit les concepts fondamentaux de la programmation : les variables, les conditions et les boucles. Tu vas apprendre à stocker des données, prendre des décisions dans ton code et répéter des actions.

## 🎯 Objectifs d'apprentissage

À la fin de ce module, tu dois savoir :

- Déclarer et utiliser des **variables** en C
- Comprendre les différents **types de données** (`int`, `char`, `float`, etc.)
- Utiliser les structures **if/else** pour prendre des décisions
- Créer des **boucles while** et **for**
- Manipuler les **opérateurs arithmétiques** et **de comparaison**
- Afficher des caractères avec `putchar()`

## 📚 Concepts clés

### Les variables

Une variable est un espace mémoire nommé qui stocke une valeur.

```c
int age = 25;           /* Variable entière */
char lettre = 'A';      /* Variable caractère */
float prix = 19.99;     /* Variable à virgule flottante */
```

### Types de données de base

| Type | Description | Exemple |
|------|-------------|---------|
| `int` | Nombre entier | `42`, `-10` |
| `char` | Caractère | `'a'`, `'Z'` |
| `float` | Nombre décimal | `3.14`, `-0.5` |
| `double` | Nombre décimal (plus précis) | `3.14159265` |

### Structure if/else

Permet d'exécuter du code selon une condition :

```c
if (age >= 18)
{
    printf("Majeur\n");
}
else
{
    printf("Mineur\n");
}
```

### Boucle while

Répète un bloc de code tant qu'une condition est vraie :

```c
int i = 0;
while (i < 10)
{
    printf("%d\n", i);
    i++;
}
```

### Boucle for

Boucle avec un compteur intégré :

```c
int i;
for (i = 0; i < 10; i++)
{
    printf("%d\n", i);
}
```

## 📝 Fichiers du projet

- `0-positive_or_negative.c` - Détermine si un nombre est positif, négatif ou zéro
- `1-last_digit.c` - Affiche le dernier chiffre d'un nombre
- `2-print_alphabet.c` - Affiche l'alphabet en minuscules
- `3-print_alphabets.c` - Affiche l'alphabet en minuscules puis majuscules
- `4-print_alphabt.c` - Affiche l'alphabet sauf 'q' et 'e'
- `5-print_numbers.c` - Affiche les chiffres de 0 à 9
- `6-print_numberz.c` - Affiche les chiffres avec `putchar()`
- `7-print_tebahpla.c` - Affiche l'alphabet à l'envers
- `8-print_base16.c` - Affiche les chiffres hexadécimaux
- `9-print_comb.c` - Affiche toutes les combinaisons de chiffres

## 🔧 Opérateurs importants

### Opérateurs arithmétiques
```c
+ (addition)
- (soustraction)
* (multiplication)
/ (division)
% (modulo - reste de la division)
```

### Opérateurs de comparaison
```c
== (égal à)
!= (différent de)
< (inférieur à)
> (supérieur à)
<= (inférieur ou égal)
>= (supérieur ou égal)
```

### Opérateurs logiques
```c
&& (ET logique)
|| (OU logique)
! (NON logique)
```

### Opérateurs d'incrémentation/décrémentation
```c
i++ (incrémente après utilisation)
++i (incrémente avant utilisation)
i-- (décrémente après)
--i (décrémente avant)
```

## 💡 Fonctions importantes

### `putchar()`
- **Bibliothèque** : `#include <unistd.h>` ou `#include <stdio.h>`
- **Utilisation** : Affiche un seul caractère
- **Exemple** : `putchar('A');`

### Code ASCII
Les caractères sont stockés sous forme de nombres (code ASCII) :
- `'0'` = 48
- `'A'` = 65
- `'a'` = 97

Pour afficher un chiffre avec `putchar()` :
```c
putchar('0' + nombre);  /* Si nombre = 5, affiche '5' */
```

## ⚠️ Points importants

- Les variables doivent être **déclarées au début** d'un bloc (norme C89)
- Une variable `char` peut contenir un caractère **OU** un petit nombre
- Le modulo `%` donne le reste d'une division : `10 % 3 = 1`
- Attention à la différence entre `=` (affectation) et `==` (comparaison)
- Dans une boucle `while`, n'oublie pas d'incrémenter ton compteur (sinon boucle infinie !)

## 📖 Exemples pratiques

### Afficher les nombres de 0 à 9
```c
int i;
for (i = 0; i < 10; i++)
{
    printf("%d", i);
}
```

### Vérifier si un nombre est pair
```c
if (nombre % 2 == 0)
{
    printf("Pair\n");
}
else
{
    printf("Impair\n");
}
```

## ✅ Compilation et tests

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-positive_or_negative.c -o test
./test
```

---

**Retour au [README principal](../README.md)**
