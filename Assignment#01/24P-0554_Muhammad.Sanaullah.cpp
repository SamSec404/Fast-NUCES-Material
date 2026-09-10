#include <iostream>
using namespace std;

class Node
{
	public:
		char data;
		Node *prev;
		Node *next;
		
		Node(char d):data(d),prev(NULL),next(NULL){}
};

class Nodeline
{
	public:
		Node* head;
    	Node* tail;
    	Nodeline* prev;
    	Nodeline* next;
    	int charCount;
    
    	Nodeline():head(NULL), tail(NULL), prev(NULL), next(NULL), charCount(0) {}
    	
    	Node* getcharat(int index)
		{
        	if(index<0 || index>=charCount)
			{
				return NULL;
			}
			
        	Node* current=head;
        	
        	for(int i=0; i<index; i++)
			{
            	current=current->next;
        	}
        	
        	return current;
        }
};

class TextEditor
{
	private:
    	Nodeline* first;
    	Nodeline* current;
    	Node* cursor;
    	
    	int cursorPosition;
    	
    	int countLines()
		{
        	int count=0;
        	Nodeline* line=first;
        	
        	while(line!=NULL)
			{
            	count++;
            	line=line->next;
        	}
        	return count;
    	}
    
	public:
    	TextEditor()
		{
        	first=new Nodeline();
        	current=first;
        	cursor=NULL;
        	cursorPosition=0;
    	}
    	
    	void moveCursorLeft()
		{
        	if(cursor!=NULL)
			{
            	cursor=cursor->prev;
            	cursorPosition--;
       		}
       		else if(cursor==NULL && current->prev!=NULL)
			{
            	current=current->prev;
            	cursor=current->tail;
            	cursorPosition=current->charCount;
        	}
    	}
    
    	void moveCursorRight()
		{
        	if(cursor==NULL && current->head!=NULL)
			{
            	cursor=current->head;
            	cursorPosition=1;
        	}
        	else if(cursor!=NULL && cursor->next!=NULL)
			{
            	cursor=cursor->next;
            	cursorPosition++;
        	}
        	else if(cursor==current->tail && current->next!=NULL) 
			{
            	current=current->next;
            	cursor=NULL;
            	cursorPosition=0;
        	}
    	}
    
    	void moveCursorUp()
		{
        	if(current->prev!=NULL)
			{
            	int savedPosition=cursorPosition;
            	current=current->prev;
            	
            	if(savedPosition<=current->charCount)
				{
                	cursorPosition=savedPosition;
                	if(cursorPosition==0)
					{
                    	cursor=NULL;
                	}
					else
					{
                    	cursor=current->getcharat(cursorPosition-1);
                	}
            	}
				else
				{
                	cursor=current->tail;
                	cursorPosition=current->charCount;
            	}
        	}
    	}
    
    	void moveCursorDown()
		{
        	if(current->next!=NULL)
			{
            	int savedPosition=cursorPosition;
            	current=current->next;
            	
            	if(savedPosition<=current->charCount)
				{
                	cursorPosition=savedPosition;
                	if(cursorPosition==0)
					{
                    	cursor=NULL;
                	}
					else
					{
                    	cursor=current->getcharat(cursorPosition-1);
                	}
            	}
				else
				{
                	cursor=current->tail;
                	cursorPosition=current->charCount;
            	}
        	}
    	}
    
    	void insertChar(char c)
		{
        	if(c=='\n')
			{
            	Nodeline* newline=new Nodeline();
            	
            	if(cursor!=NULL)
				{
                	Node* splitpoint=cursor->next;
                	
                	if(splitpoint!=NULL)
					{
                    	cursor->next=NULL;
                    	current->tail=cursor;
                    	newline->head=splitpoint;
                    	splitpoint->prev=NULL;
                    	
                    	Node* temp=splitpoint;
                    	int movedCount=0;
                    	
                    	while(temp)
						{
                        	movedCount++;
                        	if(temp->next==NULL)
							{
                            	newline->tail=temp;
                        	}
                        	temp=temp->next;
                    	}
                    	newline->charCount=movedCount;
                    	current->charCount-=movedCount;
                	}
            	}
            	else
				{
                	if(current->head!=NULL)
					{
                    	newline->head=current->head;
                    	newline->tail=current->tail;
                    	newline->charCount=current->charCount;
                    	current->head=NULL;
                    	current->tail=NULL;
                    	current->charCount=0;
                	}
            	}
            	newline->prev=current;
            	newline->next=current->next;
            	if(current->next!=NULL)
				{
                	current->next->prev=newline;
            	}
            	current->next=newline;
            	current=newline;
            	cursor=NULL;
            	cursorPosition=0;
            	return;
        	}
        
        	Node* newchar=new Node(c);
        	
        	if(cursor==NULL)
			{
            	newchar->next=current->head;
            	if(current->head!=NULL)
				{
                	current->head->prev=newchar;
            	}
            	else
				{
                	current->tail=newchar;
            	}
            	current->head=newchar;
            	cursor=newchar;
            	cursorPosition=1;
        	}
        	else
			{
            	newchar->prev=cursor;
            	newchar->next=cursor->next;
            	if(cursor->next!=NULL)
				{
                	cursor->next->prev=newchar;
            	}
            	else
				{
                	current->tail=newchar;
            	}
            	cursor->next=newchar;
            	cursor=newchar;
            	cursorPosition++;
        	}
        	
        	current->charCount++;
    	}
    
    	void backspace()
		{
        	if(cursor!=NULL)
			{
            	Node* todel=cursor;
            	cursor=cursor->prev;
            	
            	if(todel->prev!=NULL)
				{
                	todel->prev->next=todel->next;
            	}
            	else
				{
                	current->head=todel->next;
            	}
            	
            	if(todel->next!=NULL)
				{
                	todel->next->prev=todel->prev;
            	}
            	else
				{
                	current->tail=todel->prev;
            	}
            	
            	current->charCount--;
            	cursorPosition--;
            	delete todel;
        	}
        	else if(cursor==NULL && current->prev!=NULL)
			{
            	Nodeline* prevline=current->prev;
            	cursor=prevline->tail;
            	cursorPosition=prevline->charCount;
            	
            	if(current->head!=NULL)
				{
                	if(prevline->tail!=NULL)
					{
                    	prevline->tail->next=current->head;
                    	current->head->prev=prevline->tail;
                	}
                	else
					{
                    	prevline->head=current->head;
                	}
                	prevline->tail=current->tail;
                	prevline->charCount+=current->charCount;
            	}
            	prevline->next=current->next;
            	if(current->next!=NULL)
				{
                	current->next->prev=prevline;
            	}
            	Nodeline* todel=current;
            	current=prevline;
            	delete todel;
        	}
    	}
    
    	void deleteChar()
		{
        	if(cursor!=NULL && cursor->next!=NULL)
			{
            	Node* todel=cursor->next;
            	cursor->next=todel->next;
            	if(todel->next!=NULL)
				{
                	todel->next->prev=cursor;
            	}
            	else
				{
                	current->tail=cursor;
            	}
            	current->charCount--;
            	delete todel;
        	}
        	else if(cursor==NULL && current->head!=NULL)
			{
            	Node* todel=current->head;
            	current->head=todel->next;
            	if(todel->next!=NULL)
				{
                	todel->next->prev=NULL;
            	}
            	else
				{
                	current->tail=NULL;
            	}
            	current->charCount--;
            	delete todel;
        	}
        	else if((cursor==current->tail || (cursor==NULL && current->head==NULL)) && current->next!=NULL)
			{
            	Nodeline* nextline=current->next;
            	if(nextline->head!=NULL)
				{
                	if(current->tail!=NULL)
					{
                    	current->tail->next=nextline->head;
                    	nextline->head->prev=current->tail;
                	}
                	else
					{
                    	current->head=nextline->head;
                	}	
                	current->tail=nextline->tail;
                	current->charCount+=nextline->charCount;
            	}
            	current->next=nextline->next;
            	if(nextline->next!=NULL)
				{
                	nextline->next->prev=current;
            	}
            	delete nextline;
        	}
    	}
    
    	int searchChar(char c)
		{
        	int totrep=0;
        	Nodeline* line=first;
        	while(line!=NULL)
			{
            	Node* ch=line->head;
            	while(ch!=NULL)
				{
                	if(ch->data==c)
					{
                    	totrep++;
                	}
                	ch=ch->next;
            	}
            	line=line->next;
        	}
        	return totrep;
    	}
    
    	void displayDocument()
		{
        	cout<<"\n\t\tDocument Details\n\n";
        	Nodeline* line=first;
        	int linenum=0;
        
       		while(line!=NULL)
			{
            	cout<<"Line "<<linenum<<": ";
            	if(line==current && cursor==NULL)
				{
                	cout<<"|";
            	}
            	Node* ch=line->head;
            	while(ch!=NULL)
				{
                	cout<<ch->data;
                	if(line==current && ch==cursor)
					{
                    	cout<<"|";
                	}
                	ch=ch->next;
            	}
            	cout<<"  [chars: "<<line->charCount<<"]"<<endl;
            	line=line->next;
            	linenum++;
        	}
        
        	cout<<"Cursor at position: "<<cursorPosition;
        	cout<<" in line "<<getCurrentLineNumber()<<endl;
        	cout<<"Total lines: "<<countLines()<<endl;
        	cout<<"\n\n\n\n\n";
    	}
    
    	int getCurrentLineNumber()
		{
        	int linenum=0;
        	Nodeline* line=first;
        	while(line!=NULL && line!=current)
			{
            	linenum++;
            	line=line->next;
        	}
        	return linenum;
    	}
    
    	~TextEditor()
		{
        	Nodeline* line=first;
       		while(line!=NULL)
			{
            	Node* ch=line->head;
            	while(ch!=NULL)
				{
                	Node* tempchar=ch;
                	ch=ch->next;
                	delete tempchar;
            	}
            	Nodeline* templine=line;
            	line=line->next;
            	delete templine;
        	}
    	}
};

int main()
{
    TextEditor editor;
    
    cout<<"FAST linked list text editor\n\\n";
    cout<<"Testing all required functionality\n\n";
    
    const char* test1="HELLO WORLD";
    
    for(int i=0; test1[i]; i++)
	{
        editor.insertChar(test1[i]);
    }
    
    editor.displayDocument();
    
    cout<<"Move cursor left 5 times\n";
    
    for(int i=0; i<5; i++)
	{
        editor.moveCursorLeft();
    }
    
    editor.displayDocument();
    
    cout<<"Insert 'FAST ' at cursor\n";
    const char* test3="FAST ";
    
    for(int i=0; test3[i]; i++)
	{
        editor.insertChar(test3[i]);
    }
    
    editor.displayDocument();
    
    cout<<"Backspace 3 times\n";
    
    editor.backspace();
    editor.backspace();
    editor.backspace();
    editor.displayDocument();
    
    cout<<"Delete character to the right\n";
    
    editor.deleteChar();
    editor.displayDocument();
    
    cout<<"Move to beginning, add newline\n";
    for(int i=0; i<20; i++)
	{
        editor.moveCursorLeft();
    }
    editor.insertChar('\n');
    editor.displayDocument();
    
    cout<<"Add 'NUCES' to new line\n";
    const char* test7="NUCES";
    
    for(int i=0; test7[i]; i++)
	{
        editor.insertChar(test7[i]);
    }
    editor.displayDocument();
    
    cout<<"Move cursor up\n";
    
    editor.moveCursorUp();
    editor.displayDocument();
    
    cout<<"Move cursor down\n";
    editor.moveCursorDown();
    editor.displayDocument();
    
    cout<<"Move to end, add new line with 'PESHAWAR'\n";
    
    for(int i=0; i<10; i++)
	{
        editor.moveCursorRight();
    }
    
    editor.insertChar('\n');
    const char* test10="PESHAWAR";
    
    for(int i=0; test10[i]; i++)
	{
        editor.insertChar(test10[i]);
    }
    editor.displayDocument();
    
    cout<<"Search for characters\n";
    
    cout<<"Occurrences of 'E'\t"<<editor.searchChar('E')<<endl;
    cout<<"Occurrences of 'A'\t"<<editor.searchChar('A')<<endl;
    cout<<"Occurrences of 'S'\t"<<editor.searchChar('S')<<endl;
    cout<<"Occurrences of 'Z'\t"<<editor.searchChar('Z')<<endl;
    
    cout<<"\nComplex navigation test\n";
    editor.moveCursorUp();
    editor.moveCursorUp();
    for(int i=0; i<3; i++)
	{
        editor.moveCursorRight();
    }
    editor.insertChar('!');
    editor.displayDocument();
    
    cout<<"Move to beginning of line 2 and backspace (merge lines)\n";
    editor.moveCursorDown();
    
    for(int i=0; i<10; i++)
	{
        editor.moveCursorLeft();
    }
    editor.backspace();
    editor.displayDocument();
    
    cout<<"Move to end of first line and delete (merge lines)\n";
    for(int i=0; i<20; i++)
	{
        editor.moveCursorRight();
    }
    editor.moveCursorUp();
    
    for(int i=0; i<30; i++)
	{
        editor.moveCursorRight();
    }
    editor.deleteChar();
    editor.displayDocument();
    
    cout<<"\n\n\nSearch all characters\n\n\n";
    
    cout<<"Total 'E's in document\t"<<editor.searchChar('E')<<endl;
    cout<<"Total 'A's in document\t"<<editor.searchChar('A')<<endl;
    
    cout<<"\n\n\nALL TESTS COMPLETED\n\n\n";
    cout<<"Program terminating, memory will be freed by destructor.\n";
    
    return 0;
}
