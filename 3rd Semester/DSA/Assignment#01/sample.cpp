#include <iostream>
using namespace std;

class CharNode {
	public:
		
    char data;
    CharNode* prev;
    CharNode* next;
    
    CharNode(char c) : data(c), prev(nullptr), next(nullptr) {}
};

class LineNode {
	public:
		
    CharNode* head;
    CharNode* tail;
    LineNode* prev;
    LineNode* next;
    int charCount;
    
    LineNode() : head(nullptr), tail(nullptr), prev(nullptr), next(nullptr), charCount(0) {}
    
    void appendChar(char c) {
        CharNode* newNode = new CharNode(c);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        charCount++;
    }
    
    CharNode* getCharAt(int pos) {
        if (pos < 0 || pos >= charCount) return nullptr;
        CharNode* curr = head;
        for (int i = 0; i < pos && curr; i++) {
            curr = curr->next;
        }
        return curr;
    }
};

class TextEditor {
private:
    LineNode* firstLine;
    LineNode* currentLine;
    CharNode* cursor;
    int cursorLineIndex;
    int cursorCharIndex;
    
public:
    TextEditor() {
        firstLine = new LineNode();
        currentLine = firstLine;
        cursor = nullptr;
        cursorLineIndex = 0;
        cursorCharIndex = 0;
    }
    
    void moveCursorLeft() {
        if (cursor && cursor->prev) {
            cursor = cursor->prev;
            cursorCharIndex--;
        } else if (!cursor && currentLine->tail) {
            if (cursorCharIndex > 0 && currentLine->head) {
                cursor = currentLine->getCharAt(cursorCharIndex - 1);
                cursorCharIndex--;
            } else if (currentLine->prev) {
                currentLine = currentLine->prev;
                cursor = currentLine->tail;
                cursorLineIndex--;
                cursorCharIndex = currentLine->charCount - 1;
                if (cursorCharIndex < 0) cursorCharIndex = 0;
            }
        } else if (cursor == currentLine->head && currentLine->prev) {
            currentLine = currentLine->prev;
            cursor = currentLine->tail;
            cursorLineIndex--;
            cursorCharIndex = currentLine->charCount - 1;
            if (cursorCharIndex < 0) cursorCharIndex = 0;
        }
    }
    
    void moveCursorRight() {
        if (cursor && cursor->next) {
            cursor = cursor->next;
            cursorCharIndex++;
        } else if (cursor == currentLine->tail || (!cursor && cursorCharIndex == currentLine->charCount)) {
            if (currentLine->next) {
                currentLine = currentLine->next;
                cursor = currentLine->head;
                cursorLineIndex++;
                cursorCharIndex = 0;
                if (!cursor) cursorCharIndex = 0;
            }
        } else if (!cursor && cursorCharIndex < currentLine->charCount) {
            cursor = currentLine->getCharAt(cursorCharIndex);
            if (cursor) cursorCharIndex++;
        }
    }
    
    void moveCursorUp() {
        if (currentLine->prev) {
            currentLine = currentLine->prev;
            cursorLineIndex--;
            if (cursorCharIndex <= currentLine->charCount) {
                cursor = currentLine->getCharAt(cursorCharIndex);
            } else {
                cursor = currentLine->tail;
                cursorCharIndex = currentLine->charCount - 1;
                if (cursorCharIndex < 0) cursorCharIndex = 0;
            }
        }
    }
    
    void moveCursorDown() {
        if (currentLine->next) {
            currentLine = currentLine->next;
            cursorLineIndex++;
            if (cursorCharIndex <= currentLine->charCount) {
                cursor = currentLine->getCharAt(cursorCharIndex);
            } else {
                cursor = currentLine->tail;
                cursorCharIndex = currentLine->charCount - 1;
                if (cursorCharIndex < 0) cursorCharIndex = 0;
            }
        }
    }
    
    void insertChar(char c) {
        CharNode* newNode = new CharNode(c);
        
        if (c == '\n') {
            LineNode* newLine = new LineNode();
            
            if (cursor) {
                CharNode* moveStart = cursor->next;
                if (moveStart) {
                    cursor->next = nullptr;
                    if (currentLine->tail == cursor) {
                        currentLine->tail = cursor;
                    }
                    
                    CharNode* curr = moveStart;
                    while (curr) {
                        currentLine->charCount--;
                        newLine->charCount++;
                        if (!newLine->head) {
                            newLine->head = curr;
                        }
                        if (!curr->next) {
                            newLine->tail = curr;
                        }
                        curr->prev = nullptr;
                        curr = curr->next;
                    }
                }
            } else if (currentLine->head) {
                newLine->head = currentLine->head;
                newLine->tail = currentLine->tail;
                newLine->charCount = currentLine->charCount;
                currentLine->head = currentLine->tail = nullptr;
                currentLine->charCount = 0;
            }
            
            newLine->next = currentLine->next;
            newLine->prev = currentLine;
            if (currentLine->next) {
                currentLine->next->prev = newLine;
            }
            currentLine->next = newLine;
            
            currentLine = newLine;
            cursor = nullptr;
            cursorLineIndex++;
            cursorCharIndex = 0;
            
            delete newNode;
            return;
        }
        
        if (!currentLine->head) {
            currentLine->head = currentLine->tail = newNode;
            cursor = newNode;
            cursorCharIndex = 0;
        } else if (!cursor) {
            newNode->next = currentLine->head;
            currentLine->head->prev = newNode;
            currentLine->head = newNode;
            cursor = newNode;
            cursorCharIndex = 0;
        } else if (cursor == currentLine->tail) {
            cursor->next = newNode;
            newNode->prev = cursor;
            currentLine->tail = newNode;
            cursor = newNode;
            cursorCharIndex++;
        } else {
            newNode->next = cursor->next;
            newNode->prev = cursor;
            if (cursor->next) {
                cursor->next->prev = newNode;
            }
            cursor->next = newNode;
            cursor = newNode;
            cursorCharIndex++;
        }
        currentLine->charCount++;
    }
    
    void backspace() {
        if (cursor) {
            CharNode* toDelete = cursor;
            
            if (cursor->prev) {
                cursor->prev->next = cursor->next;
                cursor = cursor->prev;
                cursorCharIndex--;
            } else {
                currentLine->head = cursor->next;
                cursor = nullptr;
                cursorCharIndex = 0;
            }
            
            if (toDelete->next) {
                toDelete->next->prev = toDelete->prev;
            } else {
                currentLine->tail = toDelete->prev;
            }
            
            currentLine->charCount--;
            delete toDelete;
            
        } else if (cursorCharIndex == 0 && currentLine->prev) {
            LineNode* prevLine = currentLine->prev;
            
            cursor = prevLine->tail;
            cursorCharIndex = prevLine->charCount - 1;
            if (cursorCharIndex < 0) cursorCharIndex = 0;
            
            if (currentLine->head) {
                if (prevLine->tail) {
                    prevLine->tail->next = currentLine->head;
                    currentLine->head->prev = prevLine->tail;
                } else {
                    prevLine->head = currentLine->head;
                }
                prevLine->tail = currentLine->tail;
                prevLine->charCount += currentLine->charCount;
            }
            
            LineNode* toDelete = currentLine;
            prevLine->next = currentLine->next;
            if (currentLine->next) {
                currentLine->next->prev = prevLine;
            }
            currentLine = prevLine;
            cursorLineIndex--;
            delete toDelete;
        }
    }
    
    void deleteChar() {
        if (cursor && cursor->next) {
            CharNode* toDelete = cursor->next;
            
            cursor->next = toDelete->next;
            if (toDelete->next) {
                toDelete->next->prev = cursor;
            } else {
                currentLine->tail = cursor;
            }
            
            currentLine->charCount--;
            delete toDelete;
            
        } else if (!cursor && currentLine->head) {
            CharNode* toDelete = currentLine->head;
            currentLine->head = toDelete->next;
            if (toDelete->next) {
                toDelete->next->prev = nullptr;
            } else {
                currentLine->tail = nullptr;
            }
            currentLine->charCount--;
            delete toDelete;
            
        } else if ((cursor == currentLine->tail || (!cursor && currentLine->charCount == 0)) 
                   && currentLine->next) {
            LineNode* nextLine = currentLine->next;
            
            if (nextLine->head) {
                if (currentLine->tail) {
                    currentLine->tail->next = nextLine->head;
                    nextLine->head->prev = currentLine->tail;
                } else {
                    currentLine->head = nextLine->head;
                }
                currentLine->tail = nextLine->tail;
                currentLine->charCount += nextLine->charCount;
            }
            
            currentLine->next = nextLine->next;
            if (nextLine->next) {
                nextLine->next->prev = currentLine;
            }
            delete nextLine;
        }
    }
    
    int searchChar(char c) {
        int count = 0;
        LineNode* line = firstLine;
        
        while (line) {
            CharNode* ch = line->head;
            while (ch) {
                if (ch->data == c) {
                    count++;
                }
                ch = ch->next;
            }
            line = line->next;
        }
        
        return count;
    }
    
    void display() {
        cout << "=== Document Content ===" << endl;
        LineNode* line = firstLine;
        int lineNum = 0;
        
        while (line) {
            cout << "Line " << lineNum << ": ";
            CharNode* ch = line->head;
            
            if (line == currentLine && !cursor && cursorCharIndex == 0) {
                cout << "|";
            }
            
            int charPos = 0;
            while (ch) {
                cout << ch->data;
                if (line == currentLine && ch == cursor) {
                    cout << "|";
                }
                ch = ch->next;
                charPos++;
            }
            
            if (line == currentLine && cursor == line->tail && cursorCharIndex == line->charCount) {
                cout << "|";
            }
            
            cout << endl;
            line = line->next;
            lineNum++;
        }
        cout << "Cursor at Line: " << cursorLineIndex << ", Char: " << cursorCharIndex << endl;
        cout << "======================" << endl;
    }
    
    ~TextEditor() {
        LineNode* line = firstLine;
        while (line) {
            CharNode* ch = line->head;
            while (ch) {
                CharNode* temp = ch;
                ch = ch->next;
                delete temp;
            }
            LineNode* temp = line;
            line = line->next;
            delete temp;
        }
    }
};

int main() {
    TextEditor editor;
    
    cout << "Testing Linked List Text Editor" << endl;
    cout << "===============================" << endl << endl;
    
    cout << "Test 1: Inserting 'FAST'" << endl;
    editor.insertChar('F');
    editor.insertChar('A');
    editor.insertChar('S');
    editor.insertChar('T');
    editor.display();
    
    cout << "\nTest 2: Move left twice and insert 'E'" << endl;
    editor.moveCursorLeft();
    editor.moveCursorLeft();
    editor.insertChar('E');
    editor.display();
    
    cout << "\nTest 3: Move to end and add new line with 'NUCES'" << endl;
    editor.moveCursorRight();
    editor.moveCursorRight();
    editor.insertChar('\n');
    editor.insertChar('N');
    editor.insertChar('U');
    editor.insertChar('C');
    editor.insertChar('E');
    editor.insertChar('S');
    editor.display();
    
    cout << "\nTest 4: Backspace to remove 'S'" << endl;
    editor.backspace();
    editor.display();
    
    cout << "\nTest 5: Move left and delete 'E'" << endl;
    editor.moveCursorLeft();
    editor.moveCursorLeft();
    editor.deleteChar();
    editor.display();
    
    cout << "\nTest 6: Search for character 'E'" << endl;
    int count = editor.searchChar('E');
    cout << "Character 'E' appears " << count << " times in the document" << endl;
    editor.display();
    
    cout << "\nTest 7: Move up to first line" << endl;
    editor.moveCursorUp();
    editor.display();
    
    cout << "\nTest 8: Move down to second line" << endl;
    editor.moveCursorDown();
    editor.display();
    
    cout << "\nTest 9: Add more text" << endl;
    editor.moveCursorUp();
    for (int i = 0; i < 4; i++) {
        editor.moveCursorRight();
    }
    editor.insertChar(' ');
    editor.insertChar('E');
    editor.insertChar('d');
    editor.insertChar('i');
    editor.insertChar('t');
    editor.insertChar('o');
    editor.insertChar('r');
    editor.display();
    
    cout << "\nFinal search for 'E': " << editor.searchChar('E') << " occurrences" << endl;
    
    return 0;
}
