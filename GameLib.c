
#include "GameLib.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void StartGame(char ChosenPhrase[MAX_INPUT])
{
    #include "PhraseBank.txt"
    char DashPhrase[MAX_INPUT] = {};
	int i = 0;
	int Choice = 0;



	printf("\n\nWelcome to %d STRIKES - YOU'RE OUT - the CSE version\n\n", STRIKES);

	printf("Please pick a phrase from the following menu\n\n");

	while (PhraseBank[i] != "")
	{
		CheckPhrase(PhraseBank[i]);
		DashIt(PhraseBank[i], DashPhrase);
		printf("%d.\t%s\n", i+1, DashPhrase);
		i++;
	}

	printf("\nEnter choice : ");
	scanf("%d", &Choice);
	getchar();

	while(Choice < 1 || Choice > i)
	{
		printf("You entered an invalid choice.\nPlease reenter ");
		scanf("%d", &Choice);
	}

	strcpy(ChosenPhrase, PhraseBank[Choice]);

}

void CheckPhrase(char *Phrase)
{
	/* Declare a char pointer named FindDash and initialize it to NULL */
	char *FindDash = NULL;
	char c = '-';

	/* call strchr() with Phrase and a dash and store the result in FindDash.  If that */
	/* value is not NULL, then you found a dash                                        */

	FindDash = strchr(Phrase, c);
	if(FindDash != NULL)
	{
		printf("\n\"%s\" contains a dash in position %d!!\n", Phrase, abs(Phrase-FindDash)+1);
		printf("\nYou broke the rules.  We can't play.  BYE!!\n\n");
		exit(0);
	}
}

int GuessALetter(char Phrase[], char PhraseCopy[], char UpperPhrase[])
{
	char Guess;
	char *FindGuess = NULL;
	char UpperPhraseCopy[MAX_INPUT];
	int FoundALetter = 0;
	char DashedPhrase[MAX_INPUT];
	/* copy UpperPhrase into UpperPhraseCopy */
	strcpy(UpperPhraseCopy, UpperPhrase);

	printf("\n\n%s", DashedPhrase);
	printf("\n\nGuess a letter : ");
	scanf(" %c", &Guess);
	getchar();
	/* uppercase Guess */
	Guess = toupper(Guess);
	/* Use strchr() to look for Guess in UpperPhraseCopy.  Store the result of strchr() */
	/* in FindGuess                                                                     */
	FindGuess = strchr(UpperPhraseCopy, Guess);
	/* while FindGuess is not NULL */
	while(FindGuess != NULL)
	{
		FoundALetter = 1;
		DashedPhrase[FindGuess - UpperPhraseCopy] = Phrase[FindGuess - UpperPhraseCopy];
		/* Dereference FindGuess and set it to a dash */
		*FindGuess = '-';
		/* Call strchr() again */
		FindGuess = strchr(UpperPhraseCopy, Guess);
	}

	return FoundALetter;
}

void DashIt(char *Phrase, char DashPhrase[MAX_INPUT])
{
	char *ReplaceIt;
	char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i = 0;

	/* uppercase Phrase */
    for(i=0; i<strlen(Phrase); i++)
	{
		DashPhrase[i] = toupper(Phrase[i]);
	}


	/* Call strpbrk() with DashPhrase and Alphabet and save the result in ReplaceIt */
	ReplaceIt = strpbrk(DashPhrase, Alphabet);
	/* while ReplaceIt is not NULL */
	while(ReplaceIt != NULL)
	{
		/* Dereference ReplaceIt and set it to a dash */
		*ReplaceIt = '-';
		/* Call strpbrk() again */
		ReplaceIt = strpbrk(DashPhrase, Alphabet);
	}
}
