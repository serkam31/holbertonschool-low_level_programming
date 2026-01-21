# Doubly Linked Lists - Listes doublement chaînées

## 📖 Description

Une liste doublement chaînée est une structure de données où chaque nœud contient un pointeur vers le nœud **suivant** ET vers le nœud **précédent**. Cela permet de parcourir la liste dans les deux sens.

## 🎯 Objectifs d'apprentissage

À la fin de ce module, tu dois comprendre :

- La différence entre liste **simple** et **doublement** chaînée
- Comment créer et manipuler une liste doublement chaînée
- Les avantages et inconvénients par rapport à une liste simple
- Comment parcourir une liste dans les **deux sens**
- Insérer et supprimer des nœuds efficacement

## 📚 Concepts clés

### Structure d'un nœud doublement chaîné

```c
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;  /* Pointeur vers le précédent */
    struct dlistint_s *next;  /* Pointeur vers le suivant */
} dlistint_t;
```

### Visualisation

```
        ┌──────────┬───┬──────┐     ┌──────────┬───┬──────┐     ┌──────────┬───┬──────┐
NULL ←──┤   prev   │ 1 │ next ├────>┤   prev   │ 2 │ next ├────>┤   prev   │ 3 │ next ├───> NULL
        └──────────┴───┴──────┘     └──────────┴───┴──────┘     └──────────┴───┴──────┘
                                       <─────────────
```

Chaque nœud pointe vers :
- Son **suivant** (next)
- Son **précédent** (prev)

### Liste vide

```c
dlistint_t *head = NULL;
```

## 📝 Opérations de base

### 1. Compter les éléments

```c
size_t dlistint_len(const dlistint_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        count++;
        h = h->next;
    }

    return (count);
}
```

### 2. Afficher tous les éléments

```c
size_t print_dlistint(const dlistint_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        printf("%d\n", h->n);
        h = h->next;
        count++;
    }

    return (count);
}
```

### 3. Ajouter en début de liste

```c
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
    dlistint_t *new_node;

    /* Allouer le nouveau nœud */
    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    /* Initialiser le nœud */
    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *head;

    /* Si la liste n'est pas vide */
    if (*head != NULL)
        (*head)->prev = new_node;

    /* Mettre à jour head */
    *head = new_node;

    return (new_node);
}
```

**Important** : Ne pas oublier de mettre à jour le `prev` de l'ancien premier nœud !

### 4. Ajouter en fin de liste

```c
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new_node, *temp;

    /* Créer le nouveau nœud */
    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = NULL;

    /* Si la liste est vide */
    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return (new_node);
    }

    /* Parcourir jusqu'à la fin */
    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    /* Ajouter à la fin */
    temp->next = new_node;
    new_node->prev = temp;

    return (new_node);
}
```

### 5. Récupérer le nième nœud

```c
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    unsigned int i = 0;

    while (head != NULL)
    {
        if (i == index)
            return (head);
        head = head->next;
        i++;
    }

    return (NULL);  /* Index hors limites */
}
```

### 6. Calculer la somme de tous les éléments

```c
int sum_dlistint(dlistint_t *head)
{
    int sum = 0;

    while (head != NULL)
    {
        sum += head->n;
        head = head->next;
    }

    return (sum);
}
```

### 7. Insérer à un index donné

```c
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node, *temp;
    unsigned int i;

    /* Cas spécial : insérer au début */
    if (idx == 0)
        return (add_dnodeint(h, n));

    /* Parcourir jusqu'à l'index */
    temp = *h;
    for (i = 0; temp != NULL && i < idx - 1; i++)
        temp = temp->next;

    /* Si index hors limites */
    if (temp == NULL)
        return (NULL);

    /* Cas spécial : insérer à la fin */
    if (temp->next == NULL)
        return (add_dnodeint_end(h, n));

    /* Créer le nouveau nœud */
    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    /* Configurer le nouveau nœud */
    new_node->n = n;
    new_node->next = temp->next;
    new_node->prev = temp;

    /* Mettre à jour les liens */
    temp->next->prev = new_node;
    temp->next = new_node;

    return (new_node);
}
```

### 8. Supprimer à un index donné

```c
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *temp;
    unsigned int i;

    if (*head == NULL)
        return (-1);

    temp = *head;

    /* Supprimer le premier nœud */
    if (index == 0)
    {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return (1);
    }

    /* Parcourir jusqu'à l'index */
    for (i = 0; temp != NULL && i < index; i++)
        temp = temp->next;

    /* Index hors limites */
    if (temp == NULL)
        return (-1);

    /* Mettre à jour les liens */
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    return (1);
}
```

### 9. Libérer toute la liste

```c
void free_dlistint(dlistint_t *head)
{
    dlistint_t *temp;

    while (head != NULL)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
}
```

## 💡 Exemples d'utilisation

```c
int main(void)
{
    dlistint_t *head = NULL;

    /* Ajouter des éléments */
    add_dnodeint(&head, 1);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 5);

    /* Liste : 1 <-> 4 <-> 5 */

    /* Insérer au milieu */
    insert_dnodeint_at_index(&head, 1, 2);

    /* Liste : 1 <-> 2 <-> 4 <-> 5 */

    /* Afficher */
    print_dlistint(head);

    /* Calculer la somme */
    printf("Somme : %d\n", sum_dlistint(head));

    /* Libérer */
    free_dlistint(head);

    return (0);
}
```

## ⚠️ Points TRÈS importants

### 1. Toujours mettre à jour DEUX liens

Lors de l'insertion ou suppression, il faut mettre à jour :
- Le pointeur `next` du nœud précédent
- Le pointeur `prev` du nœud suivant

```c
/* INCOMPLET - Mauvais ! */
new_node->next = temp->next;
temp->next = new_node;

/* COMPLET - Bon ! */
new_node->next = temp->next;
new_node->prev = temp;
temp->next->prev = new_node;  /* Ne pas oublier ! */
temp->next = new_node;
```

### 2. Vérifier NULL avant d'accéder aux membres

```c
/* DANGEREUX */
temp->next->prev = new_node;

/* SÛR */
if (temp->next != NULL)
    temp->next->prev = new_node;
```

### 3. Cas spéciaux à gérer

- Liste vide
- Premier nœud
- Dernier nœud
- Un seul nœud dans la liste

### 4. Ordre d'exécution important

```c
/* MAUVAIS - On perd la référence ! */
temp->next = new_node;
new_node->next = temp->next;  /* temp->next pointe déjà vers new_node ! */

/* BON - Sauvegarder d'abord */
new_node->next = temp->next;
temp->next = new_node;
```

## 🧠 Liste simple vs doublement chaînée

| Aspect | Simple | Doublement chaînée |
|--------|--------|-------------------|
| Mémoire par nœud | 1 pointeur | 2 pointeurs |
| Parcours arrière | Impossible | Possible |
| Insertion | Simple | Plus complexe |
| Suppression | Nécessite le précédent | Direct |
| Utilisation mémoire | Moins | Plus |

## 📖 Avantages de la liste doublement chaînée

1. **Parcours bidirectionnel** : On peut aller dans les deux sens
2. **Suppression facilitée** : Pas besoin de chercher le nœud précédent
3. **Insertion avant un nœud** : Plus facile qu'avec une liste simple
4. **Navigation** : Retour en arrière possible

## 🎯 Cas d'usage

Les listes doublement chaînées sont parfaites pour :
- Navigateurs web (historique avant/arrière)
- Éditeurs de texte (undo/redo)
- Playlists musicales (suivant/précédent)
- Cache LRU (Least Recently Used)

## 💻 Parcourir dans les deux sens

### Vers l'avant

```c
dlistint_t *node = head;
while (node != NULL)
{
    printf("%d\n", node->n);
    node = node->next;
}
```

### Vers l'arrière

```c
/* Aller à la fin */
dlistint_t *node = head;
while (node->next != NULL)
    node = node->next;

/* Parcourir vers l'arrière */
while (node != NULL)
{
    printf("%d\n", node->n);
    node = node->prev;
}
```

## 📊 Visualisation des opérations

### Insertion au milieu

```
Avant :
[1] <-> [3] <-> [5]
         ^
      inserer 2

Après :
[1] <-> [2] <-> [3] <-> [5]
```

### Suppression

```
Avant :
[1] <-> [2] <-> [3] <-> [5]
         ^
    supprimer

Après :
[1] <-> [3] <-> [5]
```

## 🔍 Déboguer une liste doublement chaînée

### Vérifier l'intégrité

```c
void check_integrity(dlistint_t *head)
{
    dlistint_t *node = head;

    while (node != NULL)
    {
        /* Vérifier la cohérence */
        if (node->next != NULL && node->next->prev != node)
            printf("Erreur : lien cassé !\n");

        node = node->next;
    }
}
```

## ✅ Compilation et tests

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o test
./test
```

## 📋 Fonctions de ce module

- `dlistint_len()` - Compte les éléments
- `print_dlistint()` - Affiche la liste
- `add_dnodeint()` - Ajoute au début
- `add_dnodeint_end()` - Ajoute à la fin
- `get_dnodeint_at_index()` - Récupère un nœud
- `sum_dlistint()` - Somme des éléments
- `insert_dnodeint_at_index()` - Insère à un index
- `delete_dnodeint_at_index()` - Supprime à un index
- `free_dlistint()` - Libère la liste

---

**Retour au [README principal](../README.md)**
