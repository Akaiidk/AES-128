# AES-128 Implementation in C

![Language](https://img.shields.io/badge/language-C-blue.svg)

Une implémentation légère et pédagogique de l'algorithme de chiffrement symétrique **AES-128** (Advanced Encryption Standard) en langage C.

## 📌 À propos

Ce projet implémente le standard AES avec une clé de 128 bits. L'objectif est de fournir une base de code compréhensible illustrant les différentes étapes mathématiques du processus de chiffrement et de déchiffrement par blocs.

L'algorithme AES-128 transforme un bloc de 16 octets (128 bits) à travers 10 itérations (*rounds*) successives.

## 🚀 Fonctionnalités

* **Chiffrement et Déchiffrement** de blocs de 128 bits.
* **Expansion de clé** (Key Expansion).
* **Implémentation complète des étapes :**
    * `SubBytes` : Substitution non-linéaire via S-Box.
    * `ShiftRows` : Transposition cyclique.
    * `MixColumns` : Mixage linéaire des colonnes.
    * `AddRoundKey` : Application de la clé de round par XOR.

## 🛠️ Compilation
 ```bash
   ./main.exe mode(ECB,CBC,...) clé entrée sortie -c ou -d(pour dechiffrer)
