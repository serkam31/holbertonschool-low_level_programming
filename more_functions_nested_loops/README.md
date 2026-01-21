# More Functions and Nested Loops - Encore plus de fonctions

## 📖 Description

Ce module approfondit les concepts de fonctions vus précédemment. Tu vas créer plus de fonctions utiles et travailler davantage avec les boucles imbriquées pour dessiner des formes.

## 🎯 Objectifs d'apprentissage

À la fin de ce module, tu dois maîtriser :

- La création de fonctions plus complexes
- Les boucles imbriquées pour créer des motifs
- La vérification de types de caractères (chiffre, majuscule, etc.)
- L'impression de formes géométriques avec des boucles
- La manipulation de nombres (multiplication, division)

## 📚 Concepts clés

### Vérification de caractères

```c
/* Vérifier si c'est un chiffre (0-9) */
int _isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

/* Vérifier si c'est une majuscule (A-Z) */
int _isupper(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}
```

### Dessiner des formes

Les boucles imbriquées sont parfaites pour dessiner :

```c
/* Dessiner une ligne */
void print_line(int n)
{
    int i;
    
    for (i = 0; i < n; i++)
        _putchar('_');
    _putchar('\n');
}

/* Dessiner un triangle */
void print_triangle(int size)
{
    int ligne, espace, diese;
    
    for (ligne = 1; ligne <= size; ligne++)
    {
        for (espace = 0; espace < size - ligne; espace++)
            _putchar(' ');
        for (diese = 0; diese < ligne; diese++)
            _putchar('#');
        _putchar('\n');
    }
}
```

## 📝 Fonctions typiques de ce module

### Fonctions de vérification
- `_isupper(int c)` - Vérifie si un caractère est majuscule
- `_isdigit(int c)` - Vérifie si un caractère est un chiffre

### Fonctions mathématiques
- `mul(int a, int b)` - Multiplie deux nombres
- `print_numbers(void)` - Affiche les chiffres de 0 à 9
- `print_most_numbers(void)` - Affiche les chiffres sauf 2 et 4

### Fonctions de dessin
- `print_line(int n)` - Dessine une ligne de longueur n
- `print_diagonal(int n)` - Dessine une diagonale
- `print_square(int size)` - Dessine un carré
- `print_triangle(int size)` - Dessine un triangle

## 💡 Exemples pratiques

### Table de multiplication

```c
void print_times_table(int n)
{
    int i, j, produit;
    
    if (n >= 0 && n <= 15)
    {
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= n; j++)
            {
                produit = i * j;
                
                if (j == 0)
                    printf("%d", produit);
                else
                    printf(", %3d", produit);
            }
            printf("\n");
        }
    }
}
```

### Dessiner un carré

```c
void print_square(int size)
{
    int i, j;
    
    if (size <= 0)
    {
        _putchar('\n');
        return;
    }
    
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            _putchar('#');
        }
        _putchar('\n');
    }
}
/* print_square(5) affiche :
#####
#####
#####
#####
#####
*/
```

## ⚠️ Points importants

- Utilise les valeurs ASCII pour comparer des caractères
  - `'0'` à `'9'` : codes ASCII 48 à 57
  - `'A'` à `'Z'` : codes ASCII 65 à 90
  - `'a'` à `'z'` : codes ASCII 97 à 122

- Pour les formes complexes, dessine d'abord sur papier pour comprendre la logique

- Dans les boucles imbriquées, le compteur interne fait tout son cycle pour chaque itération du compteur externe

## 🎨 Logique des motifs

Pour dessiner un triangle :
```
    #      (3 espaces, 1 #)
   ##      (2 espaces, 2 #)
  ###      (1 espace,  3 #)
 ####      (0 espace,  4 #)
```

Logique : 
- Ligne i : `(taille - i)` espaces, puis `i` dièses

## 📖 Code ASCII - Rappel

```
'0' = 48    'A' = 65    'a' = 97
'1' = 49    'B' = 66    'b' = 98
'9' = 57    'Z' = 90    'z' = 122
```

Pour vérifier un intervalle :
```c
if (c >= 'A' && c <= 'Z')  /* C'est une majuscule */
```

## ✅ Compilation et tests

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c main.c fonction.c -o test
./test
```

---

**Retour au [README principal](../README.md)**
