# Pointers, Arrays and Strings - Part 2

## 📖 Description

Ce module continue l'apprentissage des pointeurs avec des concepts plus avancés. Tu vas approfondir la manipulation de chaînes de caractères et découvrir les pointeurs de pointeurs.

## 🎯 Objectifs d'apprentissage

À la fin de ce module, tu dois savoir :

- Manipuler des **chaînes de caractères** de façon avancée
- Utiliser des **pointeurs de pointeurs** (double pointeurs)
- Comprendre les **tableaux multidimensionnels**
- Travailler avec l'**arithmétique des pointeurs**
- Créer et manipuler des **tableaux de chaînes**

## 📚 Concepts clés

### Pointeurs de pointeurs

Un pointeur de pointeur est une variable qui contient l'adresse d'un pointeur.

```c
int x = 42;
int *ptr = &x;      /* ptr pointe vers x */
int **pptr = &ptr;  /* pptr pointe vers ptr */

printf("%d\n", x);      /* Affiche : 42 */
printf("%d\n", *ptr);   /* Affiche : 42 */
printf("%d\n", **pptr); /* Affiche : 42 */
```

### Tableaux multidimensionnels

Un tableau 2D est un tableau de tableaux :

```c
int matrice[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

printf("%d\n", matrice[0][0]);  /* Affiche : 1 */
printf("%d\n", matrice[1][2]);  /* Affiche : 7 */
```

### Tableau de chaînes

```c
char *jours[] = {
    "Lundi",
    "Mardi",
    "Mercredi",
    "Jeudi",
    "Vendredi"
};

printf("%s\n", jours[0]);  /* Affiche : Lundi */
printf("%c\n", jours[1][0]); /* Affiche : M */
```

## 📝 Fonctions avancées de ce module

### Manipulation de chaînes
- `_strcat(char *dest, char *src)` - Concatène deux chaînes
- `_strncat(char *dest, char *src, int n)` - Concatène n caractères
- `_strncpy(char *dest, char *src, int n)` - Copie n caractères
- `_strcmp(char *s1, char *s2)` - Compare deux chaînes
- `_strrev(char *s)` - Inverse une chaîne

### Manipulation de mémoire
- `_memset(char *s, char b, unsigned int n)` - Remplit la mémoire
- `_memcpy(char *dest, char *src, unsigned int n)` - Copie la mémoire

### Autres fonctions
- `_atoi(char *s)` - Convertit une chaîne en entier
- `print_number(int n)` - Affiche un nombre avec `_putchar`

## 💡 Exemples pratiques

### Comparer deux chaînes

```c
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
```

### Inverser une chaîne

```c
char *_strrev(char *s)
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
    return (s);
}
```

### Convertir une chaîne en entier

```c
int _atoi(char *s)
{
    int signe = 1;
    int resultat = 0;
    int i = 0;
    
    /* Gérer le signe */
    if (s[0] == '-')
    {
        signe = -1;
        i++;
    }
    
    /* Convertir les chiffres */
    while (s[i] >= '0' && s[i] <= '9')
    {
        resultat = resultat * 10 + (s[i] - '0');
        i++;
    }
    
    return (resultat * signe);
}
```

### Manipuler un tableau 2D

```c
void print_diagsums(int *a, int size)
{
    int i;
    int somme1 = 0, somme2 = 0;
    
    for (i = 0; i < size; i++)
    {
        somme1 += a[i * size + i];           /* Diagonale principale */
        somme2 += a[i * size + (size - 1 - i)]; /* Diagonale secondaire */
    }
    
    printf("%d, %d\n", somme1, somme2);
}
```

## ⚠️ Points importants

### Arithmétique des pointeurs

```c
int tab[] = {10, 20, 30, 40};
int *ptr = tab;

ptr++;        /* ptr pointe maintenant vers tab[1] */
ptr += 2;     /* ptr pointe maintenant vers tab[3] */
ptr--;        /* ptr pointe vers tab[2] */
```

### Différence entre pointeurs

```c
int tab[] = {1, 2, 3, 4, 5};
int *debut = &tab[0];
int *fin = &tab[4];

int distance = fin - debut;  /* distance = 4 */
```

### Tableaux multidimensionnels en mémoire

```c
int matrice[2][3] = {{1,2,3}, {4,5,6}};
/* En mémoire : [1][2][3][4][5][6] */
/* matrice[1][2] = *(matrice + 1*3 + 2) */
```

## 🧠 Visualisation des pointeurs de pointeurs

```
int x = 42;
int *ptr = &x;
int **pptr = &ptr;

Mémoire :
┌──────────┬───────┬──────────┐
│ Variable │ Valeur│  Adresse │
├──────────┼───────┼──────────┤
│    x     │   42  │  0x1000  │
│   ptr    │ 0x1000│  0x2000  │
│  pptr    │ 0x2000│  0x3000  │
└──────────┴───────┴──────────┘

*ptr = 42     (valeur de x)
**pptr = 42   (valeur de x via ptr)
```

## 📖 Conversions importantes

### De char à int
```c
char c = '5';
int nombre = c - '0';  /* nombre = 5 */
```

### De int à char
```c
int n = 7;
char c = '0' + n;  /* c = '7' */
```

### Chaîne vers nombre
```c
"123" → 1*100 + 2*10 + 3*1 = 123
```

## 🎯 Cas d'usage

### Parcourir un tableau de chaînes

```c
char *fruits[] = {"Pomme", "Banane", "Orange", NULL};
int i = 0;

while (fruits[i] != NULL)
{
    printf("%s\n", fruits[i]);
    i++;
}
```

### Remplir une matrice

```c
void fill_matrix(int rows, int cols, int matrix[rows][cols])
{
    int i, j, valeur = 1;
    
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            matrix[i][j] = valeur++;
        }
    }
}
```

## ✅ Compilation et tests

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c fonction.c -o test
./test
```

---

**Retour au [README principal](../README.md)**
