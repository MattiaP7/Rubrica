#include "include/list.hpp"

/**
 * @brief questo namespace omonimo contiene funzioni utility per QUESTO file, motivo per cui sono definiti qua e non nel file utils.hpp
 * 
 */
namespace {
    /**
     * @brief Unisce due liste ordinate in una singola lista ordinata.
     * 
     * @param left Puntatore alla testa della prima lista ordinata.
     * @param right Puntatore alla testa della seconda lista ordinata.
     * @return `Nodo*` Puntatore alla testa della lista risultante ordinata.
     */
    Nodo* merge(Nodo* left, Nodo* right) {
        if (!left) return right;
        if (!right) return left;


        if (left->contatto.get_nome() < right->contatto.get_nome()) {
            left->next = merge(left->next, right);
            return left;
        } else {
            right->next = merge(left, right->next);
            return right;
        }
    }

    /**
     * @brief Divide una lista in due sottoliste di dimensione simile.
     * 
     * @param head Puntatore alla testa della lista da dividere.
     * @param left Puntatore al puntatore che riceverà la testa della prima metà.
     * @param right Puntatore al puntatore che riceverà la testa della seconda metà.
     */
    void split(Nodo* head, Nodo** left, Nodo** right) {
        if (!head || !head->next) {
            *left = head;
            *right = nullptr;
            return;
        }

        Nodo* slow = head;
        Nodo* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        *left = head;
        *right = slow->next;
        slow->next = nullptr;
    }

    /**
     * @brief Ordina una lista collegata utilizzando Merge Sort.
     * 
     * @param head Puntatore alla testa della lista da ordinare.
     * @return `Nodo*` Puntatore alla testa della lista ordinata.
     */
    Nodo* merge_sort(Nodo* head) {
        if (!head || !head->next) return head;

        Nodo* left;
        Nodo* right;
        split(head, &left, &right);

        left = merge_sort(left);
        right = merge_sort(right);

        return merge(left, right);
    }


    /**
     * @brief funzione che verifica se una stringa inizia con un'altra stringa 
     * 
     * @param str stringa su cui fare il controllo
     * @param prefix stringa per fare il controllo
     * @return `true` 
     * @return `false`
     */
    bool starts_with(const std::string& str, const std::string& prefix) {
        if (str.size() < prefix.size()) return false;

        for (size_t i = 0; i < prefix.size(); ++i) {
            if (std::tolower(str[i]) != std::tolower(prefix[i])) {
                return false;
            }
        }

        return true;
    }
}

Nodo::Nodo() : next(nullptr) {}

List::List() : head(nullptr), M_size(0) { carica_da_file(); }

List::~List() {
    Nodo* tmp;
    while (head) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    M_size = 0;
}


void List::push() {
    Nodo* new_node = new Nodo();
    if (!new_node) {
        std::cerr << "ERRORE: memoria insufficiente!\n";
        return;
    }
    


    new_node->contatto.inserisci();

    // Controlliamo per evitare di inserire duplicati
    Nodo* tmp = head;
    while (tmp) {
        if (
            tmp->contatto.get_nome() == new_node->contatto.get_nome() &&
            tmp->contatto.get_telefono() == new_node->contatto.get_telefono() &&
            tmp->contatto.get_email() == new_node->contatto.get_email()
        ) {
            delete new_node;
            return;
        }
        tmp = tmp->next;
    }


    new_node->next = head;
    head = new_node;

    M_size++;
    salva_su_file();

    if (M_size > 1) {
        this->unique();
    }

    const_cast<List*>(this)->sort();
}

void List::mostra() const {
    if (!head) {
        std::cout << "La rubrica è vuota.\n";
        return;
    }

    const_cast<List*>(this)->sort();

    std::vector<std::vector<std::string>> dati;
    dati.push_back({ "Nome", "Telefono", "Email" }); // Intestazione della tabella

    Nodo* temp = head;
    //char letteraCorrente = '\0'; // Iniziale attuale

    while (temp) {
        //char primaLettera = std::toupper(temp->contatto.get_nome()[0]);

        /*if (primaLettera != letteraCorrente) {
            if (letteraCorrente != '\0') dati.push_back({ "", "", "" });
            dati.push_back({ std::string(1, primaLettera), "", "" });
            letteraCorrente = primaLettera;
        }*/

        dati.push_back({ temp->contatto.get_nome(), temp->contatto.get_telefono(), temp->contatto.get_email() });

        temp = temp->next;
    }

    stampaTabella(dati);
}


std::vector<Nodo*> List::find() const {
    if (!head) {
        std::cerr << "La rubrica è vuota.\n";
        return std::vector<Nodo*>();
    }

    const_cast<List*>(this)->sort();

    std::string element;
    std::cout << "Cerca: ";
    std::getline(std::cin, element);
    
    bool found = false;
    Nodo* curr = head;
    std::vector<Nodo*> contatti_trovati;
    int index = 1;

    while (curr) {
        std::istringstream stream(curr->contatto.get_nome());
        std::string word;

        // Verifica se una parola inizia con la stringa cercata (case-insensitive)
        while (stream >> word) {
            if (starts_with(word, element)) {
                contatti_trovati.push_back(curr);
                std::cout << index++ << ". ";
                curr->contatto.print();
                found = true;
                break; 
            }
        }

        curr = curr->next;
    }
    

    if(!found){
        std::cout << "Nessun contatto trovato";
    }
    return contatti_trovati;
}

void List::sort() {
    head = merge_sort(head);
}

void List::erase() {
    if (!head) return;

    std::vector<Nodo*> lista = List::find();

    int scelta;
    std::cout << "Scegli il numero del contatto da eliminare (0 per annullare): ";
    std::cin >> scelta;

    if(scelta == 0){
        std::cout << "Operazione annulata\n";
        return;
    }else if(scelta < 1 || scelta > (int)lista.size()){
        std::cout << "Numero del contatto inesistente\n";
        return;
    }

    Nodo* contatto_scelto = lista[scelta - 1];
    
    if(head == contatto_scelto){
        Nodo* tmp = head;
        head = head->next;
        std::cout << "contatto " << tmp->contatto.get_nome() << " eliminato\n";
        delete tmp;
        --M_size;
        salva_su_file();
        return;
    }

    Nodo* prev = nullptr;
    Nodo* curr = head;

    while(curr){
        if(curr == contatto_scelto){
            if(prev) prev->next = curr->next;
            std::cout << "contatto " << curr->contatto.get_nome() << " eliminato\n";
            delete curr;
            --M_size;
            salva_su_file();
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void List::unique() {
    if (!head) return;

    Nodo* curr = head;
    while (curr && curr->next) {
        if (
            curr->contatto.get_nome() == curr->next->contatto.get_nome() &&
            curr->contatto.get_telefono() == curr->next->contatto.get_telefono() &&
            curr->contatto.get_email() == curr->next->contatto.get_email()
            ) {
            Nodo* tmp = curr->next;
            curr->next = curr->next->next;
            delete tmp;
            --M_size;
        }
        else {
            curr = curr->next;
        }
    }
}

constexpr size_t List::get_size() { return M_size; }

constexpr bool List::empty(){ return this->head == nullptr; }

void List::modifica() {
    std::string nome;
    Nodo* tmp = nullptr;

    do {
        std::cout << "Nome del contatto da modificare (0 per annullare): ";
        std::getline(std::cin, nome);

        if (nome == "0") {
            std::cout << "Operazione annullata.\n";
            return;
        }

        tmp = head;
        while (tmp) {
            if (tmp->contatto.get_nome() == nome) {
                tmp->contatto.modifica();
                salva_su_file();
                std::cout << "Contatto modificato con successo e salvato su file.\n";
                return;
            }
            tmp = tmp->next;
        }

        std::cout << "Contatto non trovato. Riprova.\n";
    } while (true);
}



void List::salva_su_file() const {
    std::ofstream file("contatti.csv");
    Nodo* tmp = head;
    
    while (tmp) {
        file << tmp->contatto.to_csv() << "\n";
        tmp = tmp->next;
    }
}

void List::carica_da_file() {
    std::ifstream file("contatti.csv");
    std::string line;

    while (std::getline(file, line)) {
        Nodo* new_node = new Nodo();
        new_node->contatto.from_csv(line);
        new_node->next = head;
        head = new_node;
    }
}