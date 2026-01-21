# Structures and Typedef - Créer tes propres types

## 📖 Description

Les structures permettent de regrouper plusieurs variables de types différents dans un seul type personnalisé. C'est essentiel pour organiser des données complexes.

## 🎯 Objectifs d'apprentissage

- Créer des **structures** pour regrouper des données
- Utiliser **typedef** pour créer des alias de types
- Initialiser et manipuler des structures
- Passer des structures à des fonctions
- Utiliser des pointeurs vers des structures

## 📚 Concepts clés

### Qu'est-ce qu'une structure ?

Une structure est un type personnalisé qui regroupe plusieurs variables :

```c
struct personne {
    char nom[50];
    int age;
    float taille;
};

struct personne p1;
p1.age = 25;
strcpy(p1.nom, "Alice");
p1.taille = 1.75;
```

### Utiliser typedef

**typedef** crée un alias pour un type :

```c
typedef struct personne {
    char nom[50];
    int age;
    float taille;
} personne_t;

/* Maintenant on peut écrire : */
personne_t p1;  /* au lieu de struct personne p1; */
```

### Notation pointeur

Pour accéder aux membres via un pointeur :

```c
personne_t p1;
personne_t *ptr = &p1;

/* Deux façons d'accéder aux membres : */
(*ptr).age = 25;  /* Notation avec () */
ptr->age = 25;    /* Notation fléchée (préférée) */
```

## 📝 Exemple complet : Type dog_t

```c
/* dog.h */
#ifndef DOG_H
#define DOG_H

typedef struct dog {
    char *name;
    float age;
    char *owner;
} dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
```

```c
/* init_dog.c */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
    if (d == NULL)
        return;
    
    d->name = name;
    d->age = age;
    d->owner = owner;
}
```

```c
/* print_dog.c */
#include <stdio.h>

void print_dog(struct dog *d)
{
    if (d == NULL)
        return;
    
    printf("Name: %s\n", d->name ? d->name : "(nil)");
    printf("Age: %f\n", d->age);
    printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
}
```

```c
/* new_dog.c */
#include <stdlib.h>
#include <string.h>

dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *dog;
    
    dog = malloc(sizeof(dog_t));
    if (dog == NULL)
        return (NULL);
    
    dog->name = malloc(strlen(name) + 1);
    if (dog->name == NULL)
    {
        free(dog);
        return (NULL);
    }
    strcpy(dog->name, name);
    
    dog->owner = malloc(strlen(owner) + 1);
    if (dog->owner == NULL)
    {
        free(dog->name);
        free(dog);
        return (NULL);
    }
    strcpy(dog->owner, owner);
    
    dog->age = age;
    return (dog);
}
```

```c
/* free_dog.c */
void free_dog(dog_t *d)
{
    if (d == NULL)
        return;
    
    free(d->name);
    free(d->owner);
    free(d);
}
```

## 💡 Exemples d'utilisation

### Créer et utiliser une structure

```c
int main(void)
{
    dog_t *mon_chien;
    
    mon_chien = new_dog("Rex", 3.5, "John");
    if (mon_chien == NULL)
        return (1);
    
    print_dog(mon_chien);
    free_dog(mon_chien);
    
    return (0);
}
```

### Tableau de structures

```c
dog_t chiens[3];

chiens[0] = (dog_t){"Max", 5.0, "Alice"};
chiens[1] = (dog_t){"Bella", 2.5, "Bob"};
chiens[2] = (dog_t){"Charlie", 7.0, "Carol"};
```

## ⚠️ Points importants

### . vs ->

```c
dog_t chien;
chien.age = 5;     /* Utilise . pour une variable */

dog_t *ptr = &chien;
ptr->age = 5;      /* Utilise -> pour un pointeur */
(*ptr).age = 5;    /* Équivalent mais moins lisible */
```

### Structures avec pointeurs

Si ta structure contient des pointeurs, tu dois :
1. Allouer la mémoire pour chaque pointeur
2. Libérer chaque pointeur avant de libérer la structure

```c
typedef struct {
    char *nom;
    int age;
} personne_t;

personne_t *p = malloc(sizeof(personne_t));
p->nom = malloc(50);  /* Allouer le nom */
strcpy(p->nom, "Alice");

/* Libération */
free(p->nom);  /* D'abord le contenu */
free(p);       /* Puis la structure */
```

## 📖 Cas d'usage

Les structures sont parfaites pour :
- Représenter des objets du monde réel (personne, voiture, etc.)
- Organiser des données complexes
- Créer des structures de données (listes, arbres, etc.)

## ✅ Compilation et tests

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o test
./test
```

---

**Retour au [README principal](../README.md)**
