# Singly Linked Lists - Listes chaînées simples

## 📖 Description

Les listes chaînées sont des structures de données dynamiques où chaque élément (nœud) contient une valeur et un pointeur vers le nœud suivant. C'est ta première vraie structure de données !

## 🎯 Objectifs d'apprentissage

- Comprendre ce qu'est une **liste chaînée**
- Créer et manipuler des **nœuds**
- Parcourir une liste chaînée
- Ajouter et supprimer des éléments
- Comprendre la différence entre tableau et liste chaînée

## 📚 Concepts clés

### Qu'est-ce qu'une liste chaînée ?

Une liste chaînée est une suite de nœuds liés entre eux par des pointeurs.

```
┌─────┬────┐    ┌─────┬────┐    ┌─────┬────┐
│  1  │  ●─┼───>│  2  │  ●─┼───>│  3  │ NULL│
└─────┴────┘    └─────┴────┘    └─────┴────┘
 head                              last
```

### Structure d'un nœud

```c
typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;
```

Chaque nœud contient :
- **Des données** (ici str et len)
- **Un pointeur** vers le nœud suivant

### Créer une liste vide

```c
list_t *head = NULL;  /* Liste vide */
```

## 📝 Opérations de base

### 1. Compter les éléments

```c
size_t list_len(const list_t *h)
{
    size_t count = 0;
    
    while (h != NULL)
    {
        count++;
        h = h->next;  /* Passe au nœud suivant */
    }
    
    return (count);
}
```

### 2. Afficher tous les éléments

```c
size_t print_list(const list_t *h)
{
    size_t count = 0;
    
    while (h != NULL)
    {
        if (h->str == NULL)
            printf("[0] (nil)\n");
        else
            printf("[%u] %s\n", h->len, h->str);
        
        h = h->next;
        count++;
    }
    
    return (count);
}
```

### 3. Ajouter en début de liste

```c
list_t *add_node(list_t **head, const char *str)
{
    list_t *new_node;
    char *dup_str;
    unsigned int len = 0;
    
    /* Allouer le nouveau nœud */
    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return (NULL);
    
    /* Dupliquer la chaîne */
    dup_str = strdup(str);
    if (dup_str == NULL)
    {
        free(new_node);
        return (NULL);
    }
    
    /* Calculer la longueur */
    while (str[len])
        len++;
    
    /* Remplir le nœud */
    new_node->str = dup_str;
    new_node->len = len;
    new_node->next = *head;  /* Pointe vers l'ancien premier */
    
    /* Mettre à jour head */
    *head = new_node;
    
    return (new_node);
}
```

### 4. Ajouter en fin de liste

```c
list_t *add_node_end(list_t **head, const char *str)
{
    list_t *new_node, *temp;
    char *dup_str;
    unsigned int len = 0;
    
    /* Créer le nouveau nœud */
    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return (NULL);
    
    dup_str = strdup(str);
    if (dup_str == NULL)
    {
        free(new_node);
        return (NULL);
    }
    
    while (str[len])
        len++;
    
    new_node->str = dup_str;
    new_node->len = len;
    new_node->next = NULL;
    
    /* Si liste vide */
    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }
    
    /* Parcourir jusqu'à la fin */
    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    
    /* Ajouter à la fin */
    temp->next = new_node;
    
    return (new_node);
}
```

### 5. Libérer toute la liste

```c
void free_list(list_t *head)
{
    list_t *temp;
    
    while (head != NULL)
    {
        temp = head->next;  /* Sauvegarder le suivant */
        free(head->str);    /* Libérer la chaîne */
        free(head);         /* Libérer le nœud */
        head = temp;        /* Passer au suivant */
    }
}
```

## 💡 Exemples d'utilisation

```c
int main(void)
{
    list_t *head = NULL;
    
    /* Ajouter des éléments */
    add_node(&head, "Alice");
    add_node(&head, "Bob");
    add_node_end(&head, "Charlie");
    
    /* Liste : Bob -> Alice -> Charlie */
    
    /* Afficher */
    print_list(head);
    
    /* Compter */
    printf("Elements: %lu\n", list_len(head));
    
    /* Libérer */
    free_list(head);
    
    return (0);
}
```

## ⚠️ Points TRÈS importants

### 1. Toujours vérifier NULL

```c
if (head == NULL)
    return;  /* Liste vide */

while (node != NULL)
    node = node->next;
```

### 2. Ne pas perdre la référence

```c
/* MAUVAIS - On perd la liste ! */
head = head->next;

/* BON - Utiliser un pointeur temporaire */
list_t *current = head;
while (current != NULL)
{
    current = current->next;
}
```

### 3. Libérer dans le bon ordre

```c
/* MAUVAIS */
free(node);
node = node->next;  /* node est déjà libéré ! */

/* BON */
temp = node->next;
free(node->str);
free(node);
node = temp;
```

### 4. Modifier head avec **

```c
/* Pour modifier head, il faut un pointeur de pointeur */
void add_node(list_t **head, const char *str)
{
    /* ... */
    new_node->next = *head;
    *head = new_node;  /* Modifie head */
}
```

## 🧠 Liste vs Tableau

| Aspect | Tableau | Liste chaînée |
|--------|---------|---------------|
| Taille | Fixe | Dynamique |
| Accès | O(1) direct | O(n) séquentiel |
| Insertion début | O(n) | O(1) |
| Insertion fin | O(1) | O(n) |
| Mémoire | Contiguë | Dispersée |

## 📖 Cas d'usage

Les listes chaînées sont utilisées pour :
- Taille inconnue ou variable
- Insertions/suppressions fréquentes en début
- Parcours séquentiel
- Implémentation de piles, files, etc.

## 🎯 Visualisation des opérations

### Ajout en début

```
Avant : head -> [1] -> [2] -> NULL
Après : head -> [0] -> [1] -> [2] -> NULL
```

### Ajout en fin

```
Avant : head -> [1] -> [2] -> NULL
Après : head -> [1] -> [2] -> [3] -> NULL
```

### Suppression

```
Avant : head -> [1] -> [2] -> [3] -> NULL
Supprimer [2] :
Après : head -> [1] -> [3] -> NULL
```

## 💻 Fonctions avancées

### Insérer à une position

```c
list_t *insert_node_at_index(list_t **head, unsigned int idx, int n)
{
    list_t *new, *current;
    unsigned int i;
    
    new = malloc(sizeof(list_t));
    if (new == NULL)
        return (NULL);
    new->n = n;
    
    if (idx == 0)
    {
        new->next = *head;
        *head = new;
        return (new);
    }
    
    current = *head;
    for (i = 0; current != NULL && i < idx - 1; i++)
        current = current->next;
    
    if (current == NULL)
    {
        free(new);
        return (NULL);
    }
    
    new->next = current->next;
    current->next = new;
    return (new);
}
```

## ✅ Compilation et tests

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o test
./test
```

---

**Retour au [README principal](../README.md)**
