# MiniMaths - Application éducative pour NumWorks (Omega)

**MiniMaths** est une mini application C++ pour les calculatrices NumWorks sous firmware **Omega**, destinée à proposer un menu pédagogique interactif autour de thèmes mathématiques comme :

- Les nombres complexes
- La dérivation
- Les pourcentages
- Les suites
- Le cercle trigonométrique

---

## 📦 Contenu

Cette application affiche un menu interactif accessible via les flèches de la calculatrice. Elle est conçue pour le modèle **N110** sous Omega, mais peut être adaptée pour d'autres modèles.

---

## 🔧 Installation

### Étapes d'intégration dans Omega :

1. Clone ou copie ce dossier dans `apps/mini_maths/`.

2. Ajoute ce qui suit à `apps/mini_maths/CMakeLists.txt` :
   ```cmake
   add_executable(mini_maths_app src/main.cpp)
