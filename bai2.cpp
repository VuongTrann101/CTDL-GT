typedef struct WordNode {
    char word[50];          // T? v?ng
    int count;              // S? l?n xu?t hi?n
    struct WordNode* next;  // Con tr? t?i node ti?p theo
} WordNode;

// Danh sách liên k?t
typedef struct {
    WordNode* head;
} WordList;

// Kh?i t?o danh sách
void initializeWordList(WordList* list) {
    list->head = NULL;
}

// tu xuat hien nhieu nhat
WordNode* findMostFrequentWord(WordList* list) {
    WordNode* mostFrequent = NULL;
    WordNode* current = list->head;
    while (current != NULL) {
        if (mostFrequent == NULL || current->count > mostFrequent->count) {
            mostFrequent = current;
        }
        current = current->next;
    }
    return mostFrequent;
}

//bo tu lay
void removeRepeatingWords(WordList* list) {
    WordNode* current = list->head;
    WordNode* prev = NULL;

    while (current != NULL) {
        if (strstr(current->word, current->word) != NULL) { 
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            WordNode* temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}

//dem tu vung
int countUniqueWords(WordList* list) {
    int count = 0;
    WordNode* current = list->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

