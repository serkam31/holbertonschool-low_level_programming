# Malloc and Free - Allocation dynamique de mémoire

## 📖 Description

C'est l'un des modules les plus importants ! Tu vas apprendre à gérer la mémoire manuellement. En C, contrairement à d'autres langages, tu es responsable d'allouer et de libérer la mémoire.

## 🎯 Objectifs d'apprentissage

À la fin de ce module, tu dois comprendre :

- La différence entre **mémoire statique** et **mémoire dynamique**
- Comment fonctionne **malloc()** pour allouer de la mémoire
- Pourquoi et comment utiliser **free()** pour libérer la mémoire
- Qu'est-ce qu'une **fuite mémoire** (memory leak)
- La différence entre la **pile (stack)** et le **tas (heap)**
- Comment créer des tableaux de taille variable

## 📚 Concepts clés

### Mémoire statique vs dynamique

```c
/* STATIQUE - Taille fixe, connue à la compilation */
int tableau[10];  /* Toujours 10 éléments */

/* DYNAMIQUE - Taille variable, décidée à l'exécution */
int n = 50;
int *tableau = malloc(n * sizeof(int));  /* n peut varier */
```

### La fonction malloc()

**malloc** = **M**emory **ALLOC**ation

```c
#include <stdlib.h>

void *malloc(size_t size);
```

- **Paramètre** : nombre d'octets à allouer
- **Retour** : pointeur vers la mémoire allouée, ou `NULL` si échec

```c
/* Allouer un entier */
int *ptr = malloc(sizeof(int));

/* Allouer un tableau de 10 entiers */
int *tab = malloc(10 * sizeof(int));

/* Allouer une chaîne de 50 caractères */
char *str = malloc(50 * sizeof(char));
```

### La fonction free()

**Libère** la mémoire allouée avec malloc.

```c
void free(void *ptr);
```

```c
int *ptr = malloc(sizeof(int));
*ptr = 42;
printf("%d\n", *ptr);
free(ptr);  /* OBLIGATOIRE ! */
ptr = NULL; /* Bonne pratique */
```

### Pile (Stack) vs Tas (Heap)

```
MÉMOIRE DE TON PROGRAMME

┌─────────────────────┐
│    PILE (Stack)     │  ← Variables locales, automatique
│  Taille limitée     │     Gérée automatiquement
│  Rapide             │
├─────────────────────┤
│                     │
│    TAS (Heap)       │  ← malloc() alloue ici
│  Grande taille      │     Tu dois gérer avec free()
│  Plus lent          │
└─────────────────────┘
```

## 📝 Fonctions à implémenter

### create_array

```c
char *create_array(unsigned int size, char c)
{
    char *array;
    unsigned int i;
    
    if (size == 0)
        return (NULL);
    
    array = malloc(size * sizeof(char));
    
    if (array == NULL)
        return (NULL);
    
    for (i = 0; i < size; i++)
        array[i] = c;
    
    return (array);
}
```

### str_concat (concaténer deux chaînes)

```c
char *str_concat(char *s1, char *s2)
{
    char *concat;
    int len1 = 0, len2 = 0, i, j;
    
    if (s1 == NULL) s1 = "";
    if (s2 == NULL) s2 = "";
    
    while (s1[len1]) len1++;
    while (s2[len2]) len2++;
    
    concat = malloc((len1 + len2 + 1) * sizeof(char));
    
    if (concat == NULL)
        return (NULL);
    
    for (i = 0; i < len1; i++)
        concat[i] = s1[i];
    for (j = 0; j < len2; j++)
        concat[i + j] = s2[j];
    concat[i + j] = '\0';
    
    return (concat);
}
```

### alloc_grid (tableau 2D)

```c
int **alloc_grid(int width, int height)
{
    int **grid;
    int i, j;
    
    if (width <= 0 || height <= 0)
        return (NULL);
    
    /* Allouer le tableau de pointeurs */
    grid = malloc(height * sizeof(int *));
    if (grid == NULL)
        return (NULL);
    
    /* Allouer chaque ligne */
    for (i = 0; i < height; i++)
    {
        grid[i] = malloc(width * sizeof(int));
        if (grid[i] == NULL)
        {
            /* Libérer ce qui a déjà été alloué */
            for (j = 0; j < i; j++)
                free(grid[j]);
            free(grid);
            return (NULL);
        }
        /* Initialiser à 0 */
        for (j = 0; j < width; j++)
            grid[i][j] = 0;
    }
    return (grid);
}
```

### free_grid (libérer un tableau 2D)

```c
void free_grid(int **grid, int height)
{
    int i;
    
    if (grid == NULL)
        return;
    
    /* Libérer chaque ligne */
    for (i = 0; i < height; i++)
        free(grid[i]);
    
    /* Libérer le tableau de pointeurs */
    free(grid);
}
```

## ⚠️ Erreurs courantes et comment les éviter

### 1. Oublier de vérifier si malloc a réussi

```c
/* MAUVAIS */
int *ptr = malloc(sizeof(int));
*ptr = 42;  /* Segfault si malloc a échoué ! */

/* BON */
int *ptr = malloc(sizeof(int));
if (ptr == NULL)
    return (NULL);
*ptr = 42;
```

### 2. Oublier de libérer la mémoire (Memory Leak)

```c
/* MAUVAIS - Fuite mémoire */
void fonction(void)
{
    int *ptr = malloc(100 * sizeof(int));
    /* ... utilisation ... */
    /* Oups, pas de free() ! */
}

/* BON */
void fonction(void)
{
    int *ptr = malloc(100 * sizeof(int));
    if (ptr == NULL)
        return;
    /* ... utilisation ... */
    free(ptr);
}
```

### 3. Utiliser la mémoire après free (Use After Free)

```c
/* MAUVAIS */
int *ptr = malloc(sizeof(int));
*ptr = 42;
free(ptr);
printf("%d\n", *ptr);  /* ERREUR ! */

/* BON */
int *ptr = malloc(sizeof(int));
*ptr = 42;
printf("%d\n", *ptr);
free(ptr);
ptr = NULL;
```

### 4. Libérer deux fois (Double Free)

```c
/* MAUVAIS */
free(ptr);
free(ptr);  /* ERREUR ! */

/* BON */
free(ptr);
ptr = NULL;  /* Évite le double free */
```

### 5. Oublier le +1 pour le '\0'

```c
/* MAUVAIS */
char *str = malloc(5);  /* Pour "Hello" */
strcpy(str, "Hello");   /* Overflow ! Il faut 6 octets */

/* BON */
char *str = malloc(6);  /* 5 + 1 pour '\0' */
strcpy(str, "Hello");
```

## 💡 Bonnes pratiques

### Toujours suivre ce pattern

```c
type *ptr = malloc(taille * sizeof(type));

/* 1. Vérifier si malloc a réussi */
if (ptr == NULL)
    return (NULL);

/* 2. Utiliser la mémoire */
/* ... */

/* 3. Libérer la mémoire */
free(ptr);

/* 4. Mettre le pointeur à NULL (optionnel mais recommandé) */
ptr = NULL;
```

### Pour les tableaux 2D

```c
/* Allocation */
int **grid = malloc(rows * sizeof(int *));
for (i = 0; i < rows; i++)
    grid[i] = malloc(cols * sizeof(int));

/* Libération (dans l'ordre inverse) */
for (i = 0; i < rows; i++)
    free(grid[i]);
free(grid);
```

## 🧠 sizeof est ton ami

```c
sizeof(char)    /* 1 octet */
sizeof(int)     /* 4 octets (généralement) */
sizeof(float)   /* 4 octets */
sizeof(double)  /* 8 octets */
sizeof(char *)  /* 8 octets (sur système 64 bits) */
```

## 🔍 Vérifier les fuites mémoire avec Valgrind

```bash
gcc -g fichier.c -o programme
valgrind --leak-check=full ./programme
```

## ✅ Compilation et tests

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c fonction.c -o test
./test
```

---

**Retour au [README principal](../README.md)**
