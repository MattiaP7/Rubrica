# 📒 Rubrica Contatti in C++

Una semplice rubrica contatti in C++ che utilizza una **lista concatenata** per memorizzare e gestire i contatti.  
Supporta operazioni come **aggiunta, rimozione, modifica, ricerca, ordinamento, esportazione e importazione** dei contatti in un file CSV.

## ✨ Funzionalità

- 📌 **Aggiunta di contatti** con nome, numero di telefono ed email.
- 🔎 **Ricerca contatti**
- 🗑 **Eliminazione e modifica** di un contatto.
- 🔄 **Ordinamento altamente performante** per visualizzare i contatti in ordine alfabetico.
<!-- 📁 **Importazione ed esportazione CSV**, con filtri personalizzati.)-->
- 📊 **Visualizzazione dei contatti in tabella**

## 🚀 Installazione e utilizzo

1️⃣ **Clona la repository**

```sh
git clone https://github.com/tuo-username/rubrica-cpp.git
cd rubrica-cpp
```

2️⃣ **Compila e esegui il progetto**
Consiglio di installarsi make, e poi eseguire

```sh
make
.\main
```

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
├── 📜 main.cpp
├── 📜 Makefile
├── 📜 rubrica.csv
```

# Todo

# ✅ TODO: Miglioramenti e funzionalità future

## 🔹 Funzionalità principali da implementare:

- [ ] **Interfaccia grafica** con una semplice GUI (Qt, ImGui, o Ncurses)
- [ ] **Supporto alla ricerca fuzzy** (trova contatti anche se il nome non è esatto)
- [ ] **Esportazione in formato JSON** oltre a CSV
- [ ] **Caricamento e salvataggio automatico** senza bisogno di conferma
- [ ] **Possibilità di aggiungere note e tag** ai contatti

## 🔹 Extra (sperimentali)

- [ ] **Implementare un AVL Tree** al posto della lista concatenata per velocizzare ricerca e ordinamento
- [ ] **Ridurre il consumo di memoria** con un'allocazione più efficiente dei nodi
- [ ] **Supportare multi-threading** per operazioni lunghe come import/export
- [ ] **Versione Web con backend in C++** (CGI, FastCGI o WebSockets)
- [ ] **Integrazione con Telegram bot** per aggiungere contatti direttamente via chat
- [ ] **Modalità "CLI avanzata"** con autocomplete e comandi rapidi
- [ ] **Sincronizzazione con Google Contacts** via API

💡 Se hai idee o vuoi contribuire, apri una issue nella repo GitHub! 🚀
