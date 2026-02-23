🌳 Binary Search Tree (BST) — Interactive Menu in C
.

🌳 Binary Search Tree (BST) — Interactive Menu in C
📖 Project Overview

This project implements a Binary Search Tree (BST) in C using dynamic memory allocation.
The program provides an interactive console menu that allows users to insert nodes, display the tree, search for keys, compute depth/height metrics, list leaf nodes, and clear the entire tree safely.

It is designed as an educational project for practicing recursion and classic BST operations.

✅ Features

✅ Insert nodes into a BST (inserare)
✅ Display tree in inorder traversal (sorted order)
✅ Compute tree depth / height (longest path root → leaf)
✅ Search for a node by key
✅ Compute node depth (level from root)
✅ Compute node height (longest path node → leaf)
✅ Print all leaf nodes
✅ Clear/free entire tree (no memory leaks)

🏗️ Data Structure
struct Nod

Each BST node stores:

cheie (integer key)

stang (left child)

drept (right child)

BST ordering rule:

keys smaller than current node go left

keys greater than current node go right

🧠 Implemented Operations
1️⃣ Insert (inserare)

Recursively inserts a new key into the correct position.

2️⃣ Inorder Display (afisareInordine)

Prints keys in sorted order: left → root → right

3️⃣ Tree Depth (adancimeArbore)

Computes maximum depth (height in nodes):
1 + max(left_depth, right_depth)

4️⃣ Search (cautare)

Standard BST search in O(h) where h is tree height.

5️⃣ Node Depth (adancimeNod)

Returns the level (distance from root), starting at 0.
Returns -1 if the key doesn’t exist.

6️⃣ Node Height (inaltimeNod)

Computes height of the subtree rooted at that node.
In the menu output, the code prints inaltimeNod(nod) - 1 to represent height in edges.

7️⃣ Leaf Nodes (afisareFrunze)

Prints nodes with no children.

8️⃣ Clear Tree (curatare)

Postorder free (left → right → node), sets root to NULL.

🖥️ Menu Options
1. Inserare nod
2. Afisare arbore (inordine)
3. Calcul adancime arbore
4. Cautare nod
5. Calcul adancime nod
6. Calcul inaltime nod
7. Afisare frunze
8. Curatare arbore
9. Iesire
-	Scopul lucrării: 
-	Scopul lucrării este de a familiariza studentul cu mecanismul de creare a arborelui binar și operații elementare asupra acestuia, utilizînd pentru aceasta limbajul C.
-	Problema
-	Să se elaboreze un program ce va aloca dinamic un arbore binar de structuri și va realiza următoarele funcții, unde funcțiile date reprezintă opțiuni organizate într-un meniu în cadrul programului:
-	citirea de la tastatură a elementelor arborelui;
-	afișarea la consolă a elementelor arborelui;
-	calcularea adîncimii arborelui;
-	căutarea unui nod în baza unei chei de căutare;
-	calcularea adîncimii unui nod (nodul va fi selectat în baza unei chei de căutare);
-	calcularea înălțimii unui nod (nodul va fi selectat în baza unei chei de căutare);
-	afișarea tuturor frunzelor arborelui;
-	curățirea elementelor arborelui;
-	eliberarea memoriei arborelui.
  
[Chiochiu Vladislav TI-244 Lab 3 SDA.docx](https://github.com/user-attachments/files/25425358/Chiochiu.Vladislav.TI-244.Lab.3.SDA.docx)
