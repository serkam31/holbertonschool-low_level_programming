# More Malloc and Free - Allocation avancée

## 📖 Description

Ce module approfondit la gestion dynamique de la mémoire avec des cas d'usage plus complexes. Tu vas apprendre à créer des fonctions d'allocation personnalisées.

## 🎯 Objectifs d'apprentissage

- Maîtriser **malloc**, **free** et **calloc**
- Créer des fonctions d'allocation personnalisées
- Gérer des tableaux de chaînes dynamiques
- Combiner allocation et manipulation de données
- Comprendre **realloc()**

## 📚 Fonctions importantes

### malloc_checked

Alloue de la mémoire et termine le programme si échec :

```c
void *malloc_checked(unsigned int b)
{
    void *ptr = malloc(b);
    
    if (ptr == NULL)
        exit(98);
    
    return (ptr);
}
```

### string_nconcat

Concatène n caractères d'une chaîne :

```c
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    char *concat;
    unsigned int len1 = 0, len2 = 0, i, j;
    
    if (s1 == NULL) s1 = "";
    if (s2 == NULL) s2 = "";
    
    while (s1[len1]) len1++;
    while (s2[len2] && len2 < n) len2++;
    
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

### calloc

Alloue et initialise à zéro :

```c
void *_calloc(unsigned int nmemb, unsigned int size)
{
    char *ptr;
    unsigned int i;
    
    if (nmemb == 0 || size == 0)
        return (NULL);
    
    ptr = malloc(nmemb * size);
    if (ptr == NULL)
        return (NULL);
    
    /* Initialiser à 0 */
    for (i = 0; i < nmemb * size; i++)
        ptr[i] = 0;
    
    return (ptr);
}
```

### array_range

Crée un tableau d'entiers de min à max :

```c
int *array_range(int min, int max)
{
    int *array;
    int i, size;
    
    if (min > max)
        return (NULL);
    
    size = max - min + 1;
    array = malloc(size * sizeof(int));
    
    if (array == NULL)
        return (NULL);
    
    for (i = 0; i < size; i++)
        array[i] = min + i;
    
    return (array);
}
```

### realloc

Redimensionne un bloc mémoire :

```c
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *new_ptr;
    char *old_ptr = ptr;
    unsigned int i;
    
    if (new_size == old_size)
        return (ptr);
    
    if (ptr == NULL)
        return (malloc(new_size));
    
    if (new_size == 0)
    {
        free(ptr);
        return (NULL);
    }
    
    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
        return (NULL);
    
    /* Copier les données */
    for (i = 0; i < old_size && i < new_size; i++)
        new_ptr[i] = old_ptr[i];
    
    free(ptr);
    return (new_ptr);
}
```

## ⚠️ Points importants

### calloc vs malloc

```c
/* malloc : mémoire non initialisée */
int *arr1 = malloc(5 * sizeof(int));
/* arr1 contient des valeurs aléatoires */

/* calloc : mémoire initialisée à 0 */
int *arr2 = calloc(5, sizeof(int));
/* arr2 = {0, 0, 0, 0, 0} */
```

### realloc

```c
int *arr = malloc(5 * sizeof(int));
/* ... utilisation ... */

/* Agrandir à 10 éléments */
arr = realloc(arr, 10 * sizeof(int));
```

## ✅ Compilation et tests

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c fonction.c -o test
./test
```

---

**Retour au [README principal](../README.md)**
