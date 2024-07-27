//
//  main.c
//  Flashcard App
//
//  Created by Vadym on 7/27/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char word[64];
    char definition[1024];
    
} Flashcard;

typedef struct
{
    Flashcard collection[1024];
    int size_collection;
    
} Vocabulary;

// Essential functions
void run_program(Vocabulary *vocabulary);
void add_flashcard(Vocabulary *vocabulary);
void display_vocabulary(void);

// Supplementary functions
void display_menu(void);
void input_validation(int user_input, bool *is_finish, Vocabulary *vocabulary);
void take_user_input(char word[], char definition[]);   // takes word and definition from the user to create a new flashcard

void clear_input_buffer(void);


int main(int argc, const char * argv[]) 
{
    Vocabulary vocabulary;
    vocabulary.size_collection = 0;
    
    run_program(&vocabulary);
    
    return 0;
}

void run_program(Vocabulary *vocabulary)
{
    int user_input;
    
    bool is_finish = false;
    while(!is_finish)
    {
        display_menu();
        scanf("%d", &user_input);
        clear_input_buffer();
        
        input_validation(user_input, &is_finish, vocabulary);
    }
}

void display_menu(void)
{
    printf("Greetings! You're in the main menu of vocabulary app!!!\n");
    printf("To see all flashcards type 1\n");
    printf("To add a new flashcard type 2\n");
    printf("To remove an existing flashcard type 3\n");
    printf("To test your knowledge type 4\n");
    printf("To exit the program type 5\n");
    printf("Type input: ");
}

void input_validation(int user_input, bool *is_finish, Vocabulary *vocabulary)
{
    switch(user_input)
    {
        case 1:
            printf("You see all existing flashcards\n");
            break;
        case 2:
            add_flashcard(vocabulary);
            printf("You add a new flashcard\n");
            break;
        case 3:
            printf("You remove an existing flashcard\n");
            break;
        case 4:
            printf("You test your knowledge\n");
            break;
        case 5:
            printf("You exit the program\n");
            *is_finish = true;
            break;
        default:
            printf("Type correct input\n");
            break;
    }
}

void take_user_input(char word[], char definition[])
{
    printf("Enter word: ");
    fgets(word, 64,stdin);
    // removing trailing new line
    long word_length = word_length = strlen(word);;
    word[word_length-1] = '\0';
    
    printf("Enter definition: ");
    fgets(definition, 1024, stdin);
    // removing trailing new line
    long definition_length = strlen(definition);
    definition[definition_length - 1] = '\0';
}

void clear_input_buffer(void)
{
    int c = 0;
    while((c = getchar()) != '\n');
}

void add_flashcard(Vocabulary *vocabulary)
{
    Flashcard new_flashcard;
    char word[64];
    char definition[1024];
    
    take_user_input(word, definition);
    
    strcpy(new_flashcard.word, word);
    strcpy(new_flashcard.definition, definition);
    
    vocabulary->collection[vocabulary->size_collection] = new_flashcard;
    vocabulary->size_collection ++;
}
