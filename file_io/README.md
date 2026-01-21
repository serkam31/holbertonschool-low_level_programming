# File I/O - Entrées/Sorties de fichiers

## 📖 Description

Les entrées/sorties de fichiers (File Input/Output) permettent à tes programmes de lire et écrire des données dans des fichiers sur le disque dur. C'est essentiel pour sauvegarder des données, lire des configurations, traiter des documents, etc.

## 🎯 Objectifs d'apprentissage

À la fin de ce module, tu dois comprendre :

- Comment **ouvrir** et **fermer** des fichiers
- Les **descripteurs de fichiers** (file descriptors)
- Lire et écrire dans des fichiers avec les appels système
- La différence entre **fonctions standard** (`fopen`, `fread`) et **appels système** (`open`, `read`)
- Gérer les **permissions** de fichiers
- Utiliser les constantes `STDIN_FILENO`, `STDOUT_FILENO`, `STDERR_FILENO`

## 📚 Concepts clés

### Les trois flux standards

Chaque programme a trois flux d'entrée/sortie par défaut :

```c
STDIN_FILENO  = 0   /* Entrée standard (clavier) */
STDOUT_FILENO = 1   /* Sortie standard (écran) */
STDERR_FILENO = 2   /* Erreur standard (écran) */
```

### Descripteur de fichier (File Descriptor)

Un descripteur de fichier est un **entier** qui identifie un fichier ouvert.

```c
int fd;  /* File descriptor */

fd = open("fichier.txt", O_RDONLY);
/* fd = 3, 4, 5, etc. (0, 1, 2 sont réservés) */
```

### Fonctions principales

```c
#include <fcntl.h>   /* Pour open */
#include <unistd.h>  /* Pour read, write, close */

int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
ssize_t read(int fd, void *buf, size_t count);
ssize_t write(int fd, const void *buf, size_t count);
int close(int fd);
```

## 📝 Ouvrir un fichier avec open()

### Syntaxe

```c
int fd = open(const char *pathname, int flags, mode_t mode);
```

- **pathname** : chemin du fichier
- **flags** : mode d'ouverture
- **mode** : permissions (seulement si création)
- **Retour** : descripteur de fichier ou -1 si erreur

### Flags principaux

```c
O_RDONLY    /* Lecture seule */
O_WRONLY    /* Écriture seule */
O_RDWR      /* Lecture et écriture */
O_CREAT     /* Créer le fichier s'il n'existe pas */
O_TRUNC     /* Vider le fichier s'il existe */
O_APPEND    /* Ajouter à la fin */
```

### Permissions (mode)

```c
S_IRUSR     /* 0400 - Lecture propriétaire */
S_IWUSR     /* 0200 - Écriture propriétaire */
S_IXUSR     /* 0100 - Exécution propriétaire */
S_IRWXU     /* 0700 - RWX propriétaire */

/* Notation octale courante */
0644        /* rw-r--r-- */
0755        /* rwxr-xr-x */
```

### Exemples d'ouverture

```c
/* Ouvrir en lecture seule */
int fd = open("fichier.txt", O_RDONLY);

/* Créer ou écraser un fichier */
int fd = open("fichier.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

/* Ajouter à la fin */
int fd = open("fichier.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

/* Vérifier les erreurs */
if (fd == -1)
{
    perror("Erreur open");
    return (1);
}
```

## 📝 Lire un fichier avec read()

### Syntaxe

```c
ssize_t read(int fd, void *buf, size_t count);
```

- **fd** : descripteur de fichier
- **buf** : buffer où stocker les données
- **count** : nombre d'octets à lire
- **Retour** : nombre d'octets lus, 0 si EOF, -1 si erreur

### Exemple de lecture

```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char buffer[1024];
    ssize_t bytes_read;

    /* Ouvrir le fichier */
    fd = open("fichier.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Erreur open");
        return (1);
    }

    /* Lire le fichier */
    bytes_read = read(fd, buffer, 1024);
    if (bytes_read == -1)
    {
        perror("Erreur read");
        close(fd);
        return (1);
    }

    /* Afficher ce qui a été lu */
    write(STDOUT_FILENO, buffer, bytes_read);

    /* Fermer le fichier */
    close(fd);
    return (0);
}
```

### Lire un fichier complet

```c
char buffer[1024];
ssize_t bytes_read;

while ((bytes_read = read(fd, buffer, 1024)) > 0)
{
    write(STDOUT_FILENO, buffer, bytes_read);
}

if (bytes_read == -1)
    perror("Erreur read");
```

## 📝 Écrire dans un fichier avec write()

### Syntaxe

```c
ssize_t write(int fd, const void *buf, size_t count);
```

- **fd** : descripteur de fichier
- **buf** : données à écrire
- **count** : nombre d'octets à écrire
- **Retour** : nombre d'octets écrits, -1 si erreur

### Exemple d'écriture

```c
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int fd;
    char *text = "Hello, World!\n";
    ssize_t bytes_written;

    /* Créer ou écraser le fichier */
    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Erreur open");
        return (1);
    }

    /* Écrire dans le fichier */
    bytes_written = write(fd, text, strlen(text));
    if (bytes_written == -1)
    {
        perror("Erreur write");
        close(fd);
        return (1);
    }

    /* Fermer le fichier */
    close(fd);
    return (0);
}
```

## 📝 Fermer un fichier avec close()

### Syntaxe

```c
int close(int fd);
```

**TOUJOURS** fermer un fichier après usage !

```c
if (close(fd) == -1)
    perror("Erreur close");
```

## 💡 Fonctions typiques de ce module

### 1. Créer un fichier avec du texte

```c
int create_file(const char *filename, char *text_content)
{
    int fd;
    ssize_t bytes_written;
    size_t len = 0;

    if (filename == NULL)
        return (-1);

    /* Créer le fichier avec permissions 0600 (rw-------) */
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1)
        return (-1);

    /* Si text_content est NULL, créer un fichier vide */
    if (text_content == NULL)
    {
        close(fd);
        return (1);
    }

    /* Calculer la longueur */
    while (text_content[len])
        len++;

    /* Écrire le contenu */
    bytes_written = write(fd, text_content, len);
    if (bytes_written == -1)
    {
        close(fd);
        return (-1);
    }

    close(fd);
    return (1);
}
```

### 2. Ajouter du texte à la fin d'un fichier

```c
int append_text_to_file(const char *filename, char *text_content)
{
    int fd;
    ssize_t bytes_written;
    size_t len = 0;

    if (filename == NULL)
        return (-1);

    /* Ouvrir en mode ajout */
    fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1)
        return (-1);

    /* Si text_content est NULL, ne rien ajouter */
    if (text_content == NULL)
    {
        close(fd);
        return (1);
    }

    /* Calculer la longueur */
    while (text_content[len])
        len++;

    /* Écrire à la fin */
    bytes_written = write(fd, text_content, len);
    if (bytes_written == -1)
    {
        close(fd);
        return (-1);
    }

    close(fd);
    return (1);
}
```

### 3. Copier un fichier

```c
#define BUFFER_SIZE 1024

int copy_file(const char *file_from, const char *file_to)
{
    int fd_from, fd_to;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    /* Ouvrir le fichier source */
    fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
        return (1);
    }

    /* Créer le fichier destination */
    fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
        close(fd_from);
        return (1);
    }

    /* Copier par blocs */
    while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
    {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written != bytes_read)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
            close(fd_from);
            close(fd_to);
            return (1);
        }
    }

    if (bytes_read == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
        close(fd_from);
        close(fd_to);
        return (1);
    }

    /* Fermer les fichiers */
    if (close(fd_from) == -1 || close(fd_to) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd\n");
        return (1);
    }

    return (0);
}
```

### 4. Lire et afficher un fichier

```c
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    char *buffer;
    ssize_t bytes_read, bytes_written;

    if (filename == NULL)
        return (0);

    /* Allouer le buffer */
    buffer = malloc(letters);
    if (buffer == NULL)
        return (0);

    /* Ouvrir le fichier */
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        free(buffer);
        return (0);
    }

    /* Lire le fichier */
    bytes_read = read(fd, buffer, letters);
    if (bytes_read == -1)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    /* Écrire sur la sortie standard */
    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
    if (bytes_written == -1 || bytes_written != bytes_read)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    free(buffer);
    close(fd);
    return (bytes_written);
}
```

## ⚠️ Points TRÈS importants

### 1. Toujours vérifier les retours

```c
/* MAUVAIS */
int fd = open("file.txt", O_RDONLY);
read(fd, buffer, 100);

/* BON */
int fd = open("file.txt", O_RDONLY);
if (fd == -1)
{
    perror("Erreur open");
    return (1);
}

ssize_t bytes = read(fd, buffer, 100);
if (bytes == -1)
{
    perror("Erreur read");
    close(fd);
    return (1);
}
```

### 2. Toujours fermer les fichiers

```c
/* Ouvrir */
int fd = open("file.txt", O_RDONLY);

/* ... utilisation ... */

/* TOUJOURS fermer */
close(fd);
```

### 3. Permissions des fichiers

```c
/* 0600 : rw------- (propriétaire seulement) */
fd = open("secret.txt", O_CREAT | O_WRONLY, 0600);

/* 0644 : rw-r--r-- (lecture pour tous) */
fd = open("public.txt", O_CREAT | O_WRONLY, 0644);

/* 0755 : rwxr-xr-x (exécutable) */
fd = open("script.sh", O_CREAT | O_WRONLY, 0755);
```

### 4. Gestion du buffer

```c
/* read() ne termine PAS la chaîne par '\0' ! */
char buffer[100];
ssize_t bytes = read(fd, buffer, 100);
buffer[bytes] = '\0';  /* Ajouter '\0' si nécessaire */
```

### 5. EOF (End Of File)

```c
/* read() retourne 0 à la fin du fichier */
while ((bytes = read(fd, buffer, SIZE)) > 0)
{
    /* Traiter les données */
}

if (bytes == -1)
    perror("Erreur read");
```

## 🧠 Visualisation

```
Programme
    |
    | open("file.txt", O_RDONLY)
    |
    v
┌─────────────────┐
│ fd = 3          │
│ (descripteur)   │
└────────┬────────┘
         |
         | read(fd, buffer, size)
         |
         v
┌─────────────────┐
│   Fichier       │
│   file.txt      │
│   sur disque    │
└─────────────────┘
```

## 📖 Permissions Unix

```
Notation octale : 0rwx
r = 4 (read)
w = 2 (write)
x = 1 (execute)

0755 = rwxr-xr-x
  7 = 4+2+1 = rwx (propriétaire)
  5 = 4+0+1 = r-x (groupe)
  5 = 4+0+1 = r-x (autres)

0644 = rw-r--r--
  6 = 4+2+0 = rw- (propriétaire)
  4 = 4+0+0 = r-- (groupe)
  4 = 4+0+0 = r-- (autres)
```

## 💻 Fonctions utiles

### dprintf() - printf vers un fd

```c
dprintf(STDERR_FILENO, "Erreur: %s\n", message);
/* Équivalent à fprintf(stderr, ...) */
```

### perror() - Afficher l'erreur

```c
if (fd == -1)
{
    perror("Erreur open");  /* Affiche "Erreur open: <message>" */
    return (1);
}
```

## 🎯 Différences open/fopen

| Aspect | open (syscall) | fopen (standard) |
|--------|----------------|------------------|
| Type retour | int (fd) | FILE* |
| Buffer | Non | Oui (buffered) |
| Portable | Unix/Linux | Portable C |
| Performance | Plus rapide | Buffered |
| Usage | Bas niveau | Haut niveau |

```c
/* Appels système (ce module) */
int fd = open("file.txt", O_RDONLY);
read(fd, buffer, size);
close(fd);

/* Bibliothèque standard (autre module) */
FILE *fp = fopen("file.txt", "r");
fread(buffer, 1, size, fp);
fclose(fp);
```

## 🔍 Débogage

### Vérifier si un fichier existe

```c
#include <unistd.h>

if (access("fichier.txt", F_OK) == 0)
    printf("Le fichier existe\n");
else
    printf("Le fichier n'existe pas\n");
```

### Afficher la taille lue/écrite

```c
ssize_t bytes = write(fd, buffer, len);
if (bytes == -1)
    perror("Erreur write");
else
    printf("%ld octets écrits\n", bytes);
```

## ✅ Compilation et tests

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 fichier.c -o programme
./programme input.txt output.txt
```

## 📋 Headers nécessaires

```c
#include <fcntl.h>      /* open, O_RDONLY, O_WRONLY, O_CREAT, etc. */
#include <unistd.h>     /* read, write, close, STDOUT_FILENO, etc. */
#include <sys/types.h>  /* ssize_t */
#include <sys/stat.h>   /* permissions S_IRUSR, S_IWUSR, etc. */
```

## 🎓 Points clés à retenir

1. **Descripteur de fichier (fd)** = entier identifiant un fichier ouvert
2. **0, 1, 2** = stdin, stdout, stderr (réservés)
3. **Toujours vérifier** les valeurs de retour (-1 = erreur)
4. **Toujours fermer** les fichiers après usage
5. **read()** peut lire moins que demandé
6. **write()** peut écrire moins que demandé
7. Les **permissions** s'écrivent en octal (0644, 0755, etc.)

---

**Retour au [README principal](../README.md)**
