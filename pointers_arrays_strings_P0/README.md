# Pointers, Arrays and Strings - Introduction

## 📖 Description

Bienvenue dans l'un des modules les plus importants de la programmation C : les pointeurs ! Ce concept peut sembler complexe au début, mais c'est la clé pour comprendre comment fonctionne vraiment la mémoire d'un ordinateur.

## 🎯 Objectifs d'apprentissage

À la fin de ce module, tu dois comprendre :

- **Qu'est-ce qu'un pointeur** et comment ça fonctionne
- La différence entre une **variable** et son **adresse mémoire**
- Comment **déréférencer** un pointeur
- Qu'est-ce qu'un **tableau (array)** en C
- La relation entre **pointeurs et tableaux**
- Qu'est-ce qu'une **chaîne de caractères (string)**
- Comment manipuler des chaînes avec des pointeurs

## 📚 Concepts clés

### Qu'est-ce qu'un pointeur ?

Un pointeur est une variable qui contient l'**adresse mémoire** d'une autre variable.

```c
int nombre = 42;          /* Une variable normale */
int *ptr = &nombre;       /* Un pointeur vers nombre */

printf("%d\n", nombre);   /* Affiche : 42 */
printf("%p\n", &nombre);  /* Affiche l'adresse de nombre */
printf("%p\n", ptr);      /* Affiche la même adresse */
printf("%d\n", *ptr);     /* Affiche : 42 (déréférencement) */
```

### Opérateurs importants

- `&` : **Opérateur d'adresse** - donne l'adresse d'une variable
- `*` : **Opérateur de déréférencement** - accède à la valeur pointée

```c
int x = 10;
int *p = &x;   /* p contient l'adresse de x */

*p = 20;       /* Change la valeur de x via le pointeur */
/* Maintenant x vaut 20 */
```

### Les tableaux (arrays)

Un tableau est une collection d'éléments du même type stockés en mémoire de façon contiguë.

```c
int nombres[5] = {10, 20, 30, 40, 50};

printf("%d\n", nombres[0]);  /* Affiche : 10 */
printf("%d\n", nombres[4]);  /* Affiche : 50 */
```

**Important** : Le nom d'un tableau est un pointeur vers son premier élément !

```c
int tab[5] = {1, 2, 3, 4, 5};
int *ptr = tab;  /* équivalent à &tab[0] */

printf("%d\n", *ptr);      /* Affiche : 1 */
printf("%d\n", *(ptr+1));  /* Affiche : 2 */
printf("%d\n", tab[2]);    /* Affiche : 3 */
printf("%d\n", *(tab+2));  /* Affiche : 3 (même chose !) */
```

### Les chaînes de caractères (strings)

En C, une chaîne est un **tableau de caractères** terminé par `'\0'` (caractère nul).

```c
char nom[] = "Alice";
/* Équivalent à : */
char nom[] = {'A', 'l', 'i', 'c', 'e', '\0'};

char *prenom = "Bob";  /* Pointeur vers une chaîne constante */
```

## 📝 Fonctions importantes de ce module

### Fonctions de manipulation de mémoire

- `_memset(char *s, char b, unsigned int n)` - Remplit n octets de s avec le caractère b
- `_memcpy(char *dest, char *src, unsigned int n)` - Copie n octets de src vers dest

### Fonctions de manipulation de chaînes

- `_strcpy(char *dest, char *src)` - Copie une chaîne
- `_strlen(char *s)` - Retourne la longueur d'une chaîne
- `_strcat(char *dest, char *src)` - Concatène deux chaînes
- `_strcmp(char *s1, char *s2)` - Compare deux chaînes
- `_strchr(char *s, char c)` - Localise un caractère dans une chaîne
- `_strstr(char *haystack, char *needle)` - Localise une sous-chaîne
- `_strspn(char *s, char *accept)` - Longueur du préfixe
- `_strpbrk(char *s, char *accept)` - Recherche de caractères

## 💡 Exemples pratiques

### Changer une valeur via un pointeur

```c
void change_value(int *ptr)
{
    *ptr = 100;  /* Modifie la valeur pointée */
}

int main(void)
{
    int x = 5;
    change_value(&x);  /* Passe l'adresse de x */
    printf("%d\n", x);  /* Affiche : 100 */
    return (0);
}
```

### Calculer la longueur d'une chaîne

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

/* Ou avec un pointeur : */
int _strlen(char *s)
{
    int longueur = 0;
    
    while (*s != '\0')
    {
        longueur++;
        s++;  /* Avance le pointeur */
    }
    return (longueur);
}
```

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
    dest[i] = '\0';  /* N'oublie pas le caractère nul ! */
    return (dest);
}
```

## ⚠️ Points TRÈS importants

1. **Toujours initialiser un pointeur** avant de l'utiliser
   ```c
   int *ptr = NULL;  /* Bon */
   int *ptr;         /* Dangereux ! */
   ```

2. **Ne jamais déréférencer un pointeur NULL**
   ```c
   if (ptr != NULL)
       *ptr = 10;  /* Sécurisé */
   ```

3. **Le caractère nul '\0' termine les chaînes**
   ```c
   char str[6] = "Hello";  /* "Hello\0" */
   ```

4. **Attention aux dépassements de tableau**
   ```c
   int tab[5];
   tab[10] = 42;  /* ERREUR ! Segmentation fault */
   ```

5. **Un pointeur prend 8 octets (sur système 64 bits)**

## 🧠 Visualisation de la mémoire

```
Variable : int x = 42;
Adresse  : 0x7fff5fbff8ac

Mémoire :
┌─────────────┬─────────────┬─────────────┐
│   Adresse   │   Nom var   │   Valeur    │
├─────────────┼─────────────┼─────────────┤
│ 0x...ff8ac  │      x      │     42      │
│ 0x...ff8b0  │     ptr     │  0x...ff8ac │
└─────────────┴─────────────┴─────────────┘

ptr pointe vers x : ptr contient l'adresse de x
*ptr accède à la valeur de x (42)
```

## 📖 Notation des pointeurs

```c
int *ptr;     /* ptr est un pointeur vers un int */
char *str;    /* str est un pointeur vers un char */
*ptr = 5;     /* Déréférence : modifie la valeur pointée */
ptr = &x;     /* Affectation : ptr contient l'adresse de x */
```

## ✅ Compilation et tests

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c fonction.c -o test
./test
```

---

**Retour au [README principal](../README.md)**
