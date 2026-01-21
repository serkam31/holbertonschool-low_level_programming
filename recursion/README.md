# Recursion - La récursivité

## 📖 Description

La récursivité est une technique où une fonction s'appelle elle-même. C'est un concept puissant mais qui peut sembler étrange au début. Ce module va t'apprendre à penser de manière récursive.

## 🎯 Objectifs d'apprentissage

À la fin de ce module, tu dois comprendre :

- **Qu'est-ce que la récursivité** et quand l'utiliser
- La différence entre **récursion** et **itération** (boucles)
- Le concept de **cas de base** (condition d'arrêt)
- Comment fonctionne la **pile d'appels** (call stack)
- Les avantages et inconvénients de la récursivité

## 📚 Concepts clés

### Qu'est-ce qu'une fonction récursive ?

Une fonction récursive est une fonction qui s'appelle elle-même.

```c
void countdown(int n)
{
    if (n == 0)              /* Cas de base */
    {
        printf("Décollage !\n");
        return;
    }
    printf("%d\n", n);
    countdown(n - 1);        /* Appel récursif */
}

/* countdown(3) affiche :
3
2
1
Décollage !
*/
```

### Structure d'une fonction récursive

Toute fonction récursive doit avoir :

1. **Un cas de base** : condition qui arrête la récursion
2. **Un cas récursif** : la fonction s'appelle avec un paramètre modifié

```c
int fonction_recursive(int n)
{
    /* 1. CAS DE BASE - OBLIGATOIRE ! */
    if (condition_arret)
        return valeur_simple;
    
    /* 2. CAS RÉCURSIF */
    return fonction_recursive(n_modifie);
}
```

### La pile d'appels (Call Stack)

Quand une fonction s'appelle, l'ordinateur empile les appels en mémoire.

```c
int factorielle(int n)
{
    if (n <= 1)
        return 1;
    return n * factorielle(n - 1);
}

/* factorielle(4) :
factorielle(4) = 4 * factorielle(3)
                    factorielle(3) = 3 * factorielle(2)
                                        factorielle(2) = 2 * factorielle(1)
                                                            factorielle(1) = 1
                                        factorielle(2) = 2 * 1 = 2
                    factorielle(3) = 3 * 2 = 6
factorielle(4) = 4 * 6 = 24
*/
```

## 📝 Fonctions récursives classiques

### Factorielle

```c
int factorial(int n)
{
    if (n <= 1)
        return (1);
    return (n * factorial(n - 1));
}
/* factorial(5) = 5! = 5*4*3*2*1 = 120 */
```

### Puissance

```c
int _pow_recursion(int x, int y)
{
    if (y < 0)
        return (-1);
    if (y == 0)
        return (1);
    return (x * _pow_recursion(x, y - 1));
}
/* _pow_recursion(2, 3) = 2³ = 8 */
```

### Longueur d'une chaîne

```c
int _strlen_recursion(char *s)
{
    if (*s == '\0')
        return (0);
    return (1 + _strlen_recursion(s + 1));
}
```

### Nombre de Fibonacci

```c
int fibonacci(int n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    return (fibonacci(n - 1) + fibonacci(n - 2));
}
/* fibonacci(6) = 8
Suite : 0, 1, 1, 2, 3, 5, 8, 13... */
```

### Vérifier si un nombre est premier

```c
int is_prime_helper(int n, int diviseur)
{
    if (diviseur * diviseur > n)
        return (1);  /* Premier */
    if (n % diviseur == 0)
        return (0);  /* Pas premier */
    return (is_prime_helper(n, diviseur + 1));
}

int is_prime_number(int n)
{
    if (n <= 1)
        return (0);
    return (is_prime_helper(n, 2));
}
```

### Racine carrée (entière)

```c
int sqrt_helper(int n, int essai)
{
    if (essai * essai == n)
        return (essai);
    if (essai * essai > n)
        return (-1);
    return (sqrt_helper(n, essai + 1));
}

int _sqrt_recursion(int n)
{
    if (n < 0)
        return (-1);
    return (sqrt_helper(n, 0));
}
```

## 💡 Récursion vs Itération

### Avec boucle (itération)
```c
int factorielle_iterative(int n)
{
    int resultat = 1;
    int i;
    
    for (i = 1; i <= n; i++)
        resultat *= i;
    return (resultat);
}
```

### Avec récursion
```c
int factorielle_recursive(int n)
{
    if (n <= 1)
        return (1);
    return (n * factorielle_recursive(n - 1));
}
```

## ⚠️ Points TRÈS importants

### 1. Toujours avoir un cas de base !

```c
/* MAUVAIS - Boucle infinie ! */
int mauvais(int n)
{
    return (mauvais(n - 1));  /* Pas de cas de base */
}

/* BON */
int bon(int n)
{
    if (n == 0)               /* Cas de base */
        return (0);
    return (bon(n - 1));
}
```

### 2. Le paramètre doit changer

```c
/* MAUVAIS - Boucle infinie ! */
int mauvais(int n)
{
    if (n == 0)
        return (0);
    return (mauvais(n));  /* n ne change pas ! */
}

/* BON */
int bon(int n)
{
    if (n == 0)
        return (0);
    return (bon(n - 1));  /* n diminue */
}
```

### 3. Attention à la pile (Stack Overflow)

Trop d'appels récursifs peuvent saturer la mémoire :

```c
/* Dangereux pour de grandes valeurs */
factorielle(1000000);  /* Stack overflow ! */
```

## 🧠 Comment penser récursivement ?

### Méthode en 3 étapes

1. **Identifier le cas de base** : Quand s'arrête-t-on ?
2. **Définir le cas récursif** : Comment réduire le problème ?
3. **Vérifier que chaque appel se rapproche du cas de base**

### Exemple : Afficher les chiffres d'un nombre

```c
/* Je veux afficher 1234 → 1 2 3 4 */

void print_digits(int n)
{
    /* Cas de base : un seul chiffre */
    if (n < 10)
    {
        _putchar('0' + n);
        return;
    }
    
    /* Cas récursif : traiter les chiffres précédents */
    print_digits(n / 10);  /* 1234 → 123 */
    _putchar('0' + n % 10); /* Affiche 4 */
}
```

## 🎯 Avantages et inconvénients

### Avantages
- Code plus élégant et lisible
- Naturel pour certains problèmes (arbres, fractales)
- Moins de code

### Inconvénients
- Utilise plus de mémoire (pile d'appels)
- Peut être plus lent qu'une boucle
- Risque de stack overflow

## 📖 Exemples avancés

### Palindrome

```c
int is_palindrome_helper(char *s, int debut, int fin)
{
    if (debut >= fin)
        return (1);
    if (s[debut] != s[fin])
        return (0);
    return (is_palindrome_helper(s, debut + 1, fin - 1));
}

int is_palindrome(char *s)
{
    int len = _strlen(s);
    return (is_palindrome_helper(s, 0, len - 1));
}
```

## ✅ Compilation et tests

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c fonction.c -o test
./test
```

---

**Retour au [README principal](../README.md)**
