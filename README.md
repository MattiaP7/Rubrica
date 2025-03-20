# 📒 Rubrica Contatti in C++

Una semplice rubrica contatti in C++ che utilizza una **lista concatenata** per memorizzare e gestire i contatti.  
Supporta operazioni come **aggiunta, rimozione, modifica, ricerca, ordinamento**, i contatti vengono poi salvati in un file csv.

## ✨ Funzionalità

- 📌 **Aggiunta di contatti** con nome, numero di telefono ed email.
- 🔎 **Ricerca contatti**
- 🗑 **Eliminazione e modifica** di un contatto.
- 🔄 **Ordinamento altamente performante** per visualizzare i contatti in ordine alfabetico.
- 📊 **Visualizzazione dei contatti in tabella**
<!-- 📁 **Importazione ed esportazione CSV**, con filtri personalizzati.)-->

## 🚀 Installazione e utilizzo

1️⃣ **Clona la repository**

```sh
git clone https://github.com/MattiaP7/Rubrica.git
cd rubrica-cpp
```

2️⃣ **Compila e esegui il progetto**

```sh
make
.\main
```

Altrimenti visita la pagina [release](https://github.com/MattiaP7/Rubrica/releases).

### 📂 Struttura della repository

```
📂 rubrica-cpp
├── 📂 src
│ ├── contatto.cpp
│ ├── list.cpp
│ ├── rubrica.cpp
│ ├── utils.cpp
├── 📂 include
│ ├── contatto.hpp
│ ├── list.hpp
│ ├── rubrica.hpp
│ ├── utils.hpp
├──  main.cpp
├──  Makefile
├──  rubrica.csv
```

# ✅ TODO: Miglioramenti e funzionalità future

- [x] **Sistemare la funzione di ricerca**
- [ ] **Interfaccia grafica** con una semplice GUI (Qt, ImGui, o Ncurses)
- [ ] **Ridurre il consumo di memoria** con un'allocazione più efficiente dei nodi, tramite std::unique_ptr
  <!-- - [ ] **Esportazione in formato JSON** oltre a CSV -->
  <!-- - [ ] **Caricamento e salvataggio automatico** senza bisogno di conferma -->
  <!-- - [ ] **Possibilità di aggiungere note e tag** ai contatti -->
  <!-- - [ ] **Implementare un AVL Tree** al posto della lista concatenata per velocizzare ricerca e ordinamento -->
  <!-- - [ ] **Modalità "CLI avanzata"** con autocomplete e comandi rapidi -->
  <!-- - [ ] **Supportare multi-threading** per operazioni lunghe come import/export -->
  <!-- - [ ] **Versione Web con backend in C++** (CGI, FastCGI o WebSockets) -->
  <!-- - [ ] **Integrazione con Telegram bot** per aggiungere contatti direttamente via chat -->
  <!-- - [ ] **Sincronizzazione con Google Contacts** via API -->

💡 Se hai idee o vuoi contribuire, apri una issue nella repo GitHub! 🚀
