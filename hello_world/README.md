# Hello World - Premier programme en C

## 📖 Description

Ce dossier contient les premiers exercices en langage C. C'est ici que tout commence ! Tu vas apprendre comment fonctionne le processus de compilation et écrire tes premiers programmes.

## 🎯 Objectifs d'apprentissage

À la fin de ce module, tu dois comprendre :

- **Qu'est-ce que le langage C** et pourquoi il est important
- **Le processus de compilation** (préprocesseur, compilateur, assembleur, linker)
- Comment utiliser **gcc** (le compilateur C)
- Les différentes étapes de transformation du code source en exécutable
- Comment afficher du texte avec `printf()` et `puts()`
- La structure de base d'un programme C

## 📚 Concepts clés

### Le processus de compilation

Quand tu écris un programme en C, il passe par 4 étapes avant de devenir exécutable :

1. **Préprocesseur** : Traite les directives `#include`, `#define`, etc.
2. **Compilateur** : Transforme le code C en langage assembleur
3. **Assembleur** : Transforme l'assembleur en code machine (fichier objet `.o`)
4. **Linker (éditeur de liens)** : Lie tous les fichiers objets pour créer l'exécutable final

### Structure d'un programme C

```c
#include <stdio.h>  /* Inclusion de bibliothèques */

int main(void)      /* Fonction principale (point d'entrée) */
{
    printf("Hello, World!\n");  /* Instruction */
    return (0);                  /* Valeur de retour */
}
```

## 📝 Fichiers du projet

- `0-preprocessor` - Script qui exécute uniquement le préprocesseur sur un fichier C
- `1-compiler` - Script qui compile un fichier C sans le linker
- `2-assembler` - Script qui génère le code assembleur d'un programme C
- `3-name` - Script qui compile un fichier C et crée un exécutable nommé `cisfun`
- `4-puts.c` - Programme qui affiche une phrase avec la fonction `puts()`
- `5-printf.c` - Programme qui affiche une phrase avec la fonction `printf()`
- `6-size.c` - Programme qui affiche la taille de différents types de données

## 🔧 Commandes importantes

### Compiler un programme
```bash
gcc nom_fichier.c -o nom_executable
```

### Compiler avec tous les warnings
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 fichier.c -o executable
```

### Exécuter le préprocesseur seulement
```bash
gcc -E fichier.c -o fichier.i
```

### Compiler sans linker (créer un fichier objet)
```bash
gcc -c fichier.c -o fichier.o
```

### Générer le code assembleur
```bash
gcc -S fichier.c -o fichier.s
```

## 💡 Fonctions importantes

### `printf()`
- **Bibliothèque** : `#include <stdio.h>`
- **Utilisation** : Affiche du texte formaté
- **Exemple** : `printf("Bonjour %s\n", nom);`

### `puts()`
- **Bibliothèque** : `#include <stdio.h>`
- **Utilisation** : Affiche une chaîne de caractères suivie d'un retour à la ligne
- **Exemple** : `puts("Bonjour");`

## ⚠️ Points importants

- Tout programme C commence par la fonction `main()`
- La fonction `main()` doit retourner un `int` (généralement 0 pour succès)
- N'oublie pas le `\n` pour aller à la ligne
- Les chaînes de caractères sont entre guillemets doubles `"texte"`
- Chaque instruction se termine par un point-virgule `;`

## 📖 Ressources

- [Documentation GCC](https://gcc.gnu.org/onlinedocs/)
- Commande `man gcc` dans le terminal
- [Tutoriel C](https://www.learn-c.org/)

## ✅ Compilation et tests

Pour compiler et tester les programmes :

```bash
# Exemple avec 4-puts.c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 4-puts.c -o puts_program
./puts_program
```

---

**Retour au [README principal](../README.md)**
