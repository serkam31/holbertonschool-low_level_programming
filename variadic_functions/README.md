# Variadic Functions - Fonctions à arguments variables

## 📖 Description

Les fonctions variadiques acceptent un nombre variable d'arguments. Tu connais déjà `printf()` qui est une fonction variadique : `printf("%d %s", 42, "test")`.

## 🎯 Objectifs d'apprentissage

- Comprendre les **fonctions variadiques**
- Utiliser les macros **va_start**, **va_arg**, **va_end**
- Créer tes propres fonctions avec nombre d'arguments variable
- Comprendre `stdarg.h`

## 📚 Concepts clés

### Qu'est-ce qu'une fonction variadique ?

Une fonction qui accepte un nombre variable d'arguments :

```c
printf("%d", 42);                    /* 1 argument en plus du format */
printf("%d %s", 42, "hello");        /* 2 arguments */
printf("%d %s %f", 42, "hi", 3.14);  /* 3 arguments */
```

### Syntaxe de base

```c
#include <stdarg.h>

type fonction(type premier_arg, ...)
{
    va_list args;              /* Déclare la liste d'arguments */
    
    va_start(args, premier_arg); /* Initialise */
    
    /* Récupérer les arguments avec va_arg */
    type val = va_arg(args, type);
    
    va_end(args);              /* Nettoie */
}
```

### Les trois macros essentielles

```c
va_list ap;          /* Déclare une liste d'arguments */
va_start(ap, last);  /* Initialise ap après le dernier argument fixe */
va_arg(ap, type);    /* Récupère le prochain argument du type spécifié */
va_end(ap);          /* Nettoie la liste */
```

## 📝 Exemples pratiques

### Somme de n nombres

```c
#include <stdarg.h>

int sum_them_all(const unsigned int n, ...)
{
    va_list args;
    unsigned int i;
    int somme = 0;
    
    if (n == 0)
        return (0);
    
    va_start(args, n);  /* Initialise après le paramètre 'n' */
    
    for (i = 0; i < n; i++)
    {
        somme += va_arg(args, int);  /* Récupère chaque int */
    }
    
    va_end(args);
    return (somme);
}

/* Utilisation */
int total = sum_them_all(4, 10, 20, 30, 40);  /* total = 100 */
```

### Afficher des nombres avec séparateur

```c
void print_numbers(const char *separator, const unsigned int n, ...)
{
    va_list args;
    unsigned int i;
    
    va_start(args, n);
    
    for (i = 0; i < n; i++)
    {
        printf("%d", va_arg(args, int));
        
        if (separator != NULL && i < n - 1)
            printf("%s", separator);
    }
    
    printf("\n");
    va_end(args);
}

/* Utilisation */
print_numbers(", ", 4, 0, 98, -402, 1024);
/* Affiche : 0, 98, -402, 1024 */
```

### Afficher des chaînes avec séparateur

```c
void print_strings(const char *separator, const unsigned int n, ...)
{
    va_list args;
    unsigned int i;
    char *str;
    
    va_start(args, n);
    
    for (i = 0; i < n; i++)
    {
        str = va_arg(args, char *);
        
        if (str == NULL)
            printf("(nil)");
        else
            printf("%s", str);
        
        if (separator != NULL && i < n - 1)
            printf("%s", separator);
    }
    
    printf("\n");
    va_end(args);
}

/* Utilisation */
print_strings(" | ", 3, "Alice", "Bob", "Charlie");
/* Affiche : Alice | Bob | Charlie */
```

### Afficher tout type avec format

```c
void print_all(const char * const format, ...)
{
    va_list args;
    int i = 0;
    char *str;
    char *sep = "";
    
    va_start(args, format);
    
    while (format && format[i])
    {
        switch (format[i])
        {
            case 'c':
                printf("%s%c", sep, va_arg(args, int));
                break;
            case 'i':
                printf("%s%d", sep, va_arg(args, int));
                break;
            case 'f':
                printf("%s%f", sep, va_arg(args, double));
                break;
            case 's':
                str = va_arg(args, char *);
                if (str == NULL)
                    str = "(nil)";
                printf("%s%s", sep, str);
                break;
            default:
                i++;
                continue;
        }
        sep = ", ";
        i++;
    }
    
    printf("\n");
    va_end(args);
}

/* Utilisation */
print_all("cifs", 'H', 42, 3.14, "World");
/* Affiche : H, 42, 3.140000, World */
```

## ⚠️ Points TRÈS importants

### 1. Il faut au moins un paramètre fixe

```c
/* MAUVAIS - Ne compile pas */
int func(...);

/* BON - Au moins un paramètre fixe */
int func(int n, ...);
```

### 2. Tu dois savoir combien d'arguments

La fonction doit avoir un moyen de savoir combien d'arguments elle reçoit :

```c
/* Option 1 : Passer le nombre */
sum_them_all(3, 10, 20, 30);

/* Option 2 : Format string */
print_all("cis", 'A', 42, "test");

/* Option 3 : Sentinelle (dernier arg spécial) */
concat_strings("Hello", "World", NULL);
```

### 3. Tu dois connaître le type

```c
va_arg(args, int);     /* Pour récupérer un int */
va_arg(args, double);  /* Pour récupérer un double */
va_arg(args, char *);  /* Pour récupérer une chaîne */
```

### 4. Promotions automatiques

```c
/* char et short sont promus en int */
va_arg(args, int);  /* Même pour récupérer un char */

/* float est promu en double */
va_arg(args, double);  /* Même pour récupérer un float */
```

### 5. Toujours appeler va_end

```c
va_list args;
va_start(args, n);

/* ... utilisation ... */

va_end(args);  /* OBLIGATOIRE ! */
```

## 🧠 Comment ça marche ?

```
Appel : func(3, 10, 20, 30)

Pile (stack) :
┌─────────┐
│   30    │  ← va_arg récupère ici
├─────────┤
│   20    │  ← puis ici
├─────────┤
│   10    │  ← puis ici
├─────────┤
│    3    │  ← dernier paramètre fixe
└─────────┘
  
va_start positionne le pointeur après '3'
va_arg avance le pointeur à chaque appel
```

## 💡 Exemples de fonctions variadiques standard

```c
printf(format, ...)      /* Affichage formaté */
scanf(format, ...)       /* Lecture formatée */
sprintf(str, format, ...) /* Écrire dans une chaîne */
fprintf(file, format, ...) /* Écrire dans un fichier */
```

## 📖 Cas d'usage

Les fonctions variadiques sont utiles pour :
- **Formatage** : printf, sprintf
- **Logging** : fonctions de log avec messages variables
- **Agrégation** : somme, moyenne, min, max
- **Construction** : créer des structures avec paramètres variables

## ⚙️ Macros stdarg.h

```c
va_list    /* Type pour la liste d'arguments */
va_start   /* Initialise la liste */
va_arg     /* Récupère le prochain argument */
va_end     /* Nettoie la liste */
va_copy    /* Copie une liste (C99) */
```

## ✅ Compilation et tests

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o test
./test
```

---

**Retour au [README principal](../README.md)**
