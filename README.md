# 📘 MiniMaths — Application éducative pour NumWorks (Upsilon)

**MiniMaths** est une application pédagogique interactive en C/C++ destinée aux calculatrices NumWorks utilisant le firmware **Upsilon**.  
Elle propose un menu simple avec des rappels de cours et des mini-calculs autour de notions mathématiques fondamentales :

- Les nombres complexes  
- La dérivation  
- Les pourcentages *(à venir)*  
- Les suites *(à venir)*  
- Le cercle trigonométrique *(à venir)*

---

## 🧱 Arborescence du projet

Place l’app dans ce dossier :

```
Upsilon/
└── apps/
    └── external/
        └── app/
            └── mini_maths/
                ├── Makefile
                └── src/
                    ├── main.cpp
                    ├── controller.h
                    ├── controller.cpp
                    ├── complex_page.h
                    ├── complex_page.cpp
                    ├── derivation_page.h
                    ├── derivation_page.cpp
                    └── maths_lib.c
```

---

## 🔧 Installation dans Upsilon

### 1. Copier le dossier

Place tout le dossier `mini_maths/` dans :
```
Upsilon/apps/external/app/
```

---

### 2. Créer le `Makefile` de l’app

Dans `apps/external/app/mini_maths/Makefile` :

```make
APP_OBJS += \
  $(BUILD_DIR)/apps/external/app/mini_maths/src/main.o \
  $(BUILD_DIR)/apps/external/app/mini_maths/src/controller.o \
  $(BUILD_DIR)/apps/external/app/mini_maths/src/complex_page.o \
  $(BUILD_DIR)/apps/external/app/mini_maths/src/derivation_page.o \
  $(BUILD_DIR)/apps/external/app/mini_maths/src/maths_lib.o
```

---

### 3. Déclarer l’app dans `apps_container.cpp`

Dans le fichier `Upsilon/apps/apps_container.cpp` :

#### ➤ En haut du fichier, ajoute :

```cpp
extern App * miniMathsAppCreator(Container * container);
```

#### ➤ Dans la section d’ajout des apps, ajoute :

```cpp
apps[i++] = miniMathsAppCreator(this);
```



### 🖥️ Pour tester sur simulateur Linux :

```bash
make clean
make PLATFORM=simulator MODEL=n110 -j$(nproc)
./output/release/simulator
```


## 🧪 Fonctionnement

- L’application apparaît dans le menu principal sous le nom **MiniMaths**.
- Elle affiche une liste de 5 thèmes mathématiques.
- Les deux premiers (`Nombres complexes` et `Dérivation`) sont interactifs et calculent des exemples simples.
- D'autres fonctionnalités (suites, trigonométrie...) peuvent être ajoutées par la suite.

---

## 👤 Auteur
swyftos


---

> Pour toute suggestion, bug ou extension, ouvrez une issue ou une PR dans le dépôt associé.
