//#include <rp6502.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>





// Functions
int start();  // starts game
void playerTurn();  // Player's turn
void look();  // initial statements when you enter a new location
void talk();  // function for interacting with people
void travel();  // function for changing the area number
void order(); // function for ordering food or drinks
void approach();  // function for approaching an area in an environment
void newIndividuals(); // Function for changing the people you can interact with based on your location
void help(); // describes how user can interact with the game

//Global Variables
int environment = 1;  // number of each environment the player can travel too
int counter = 0;  // After 1000 turns the night ends and the game ends.
int individual = 0; // Determines which individuals are in the environment


int main()
{

    if (start() == 0)
    {
        printf("\nL");
    }

    help();
    printf("\nIt's a Friday Night at Notre Dame\n");
    look();

    do
    {
        playerTurn();
        counter++;
    } while (counter < 1000);

    printf("After a long night, you went back to bed.");

    return 0;
}




// Start Function

int start()
{
    char yesNo;
    printf("Welcome to Notre Dame Night Life\n");
    printf("Would you like to play?\n\n");
    printf("Enter Y/N: ");
    scanf("%c", &yesNo);


    if (yesNo == 'N')
    {
        return 0;
    }
    return 1;

}


// Look function
// 1 = Dorm Room
// 2 = Hallway
// 3 = Cool Runnings
// 4 = Barcade
// 5 = Library
// 6 = Dorm Event
// 7 = Food Run
// 8 = Stay In

void look()
{
    switch (environment)
    {
        case 1:
            printf("\nYou just got back from showering, ready to take on what the night brings.\n");
            printf("You're in your dorm with your roommate.\n");
            printf("You can travel into the hallway or talk to your roommate\n\n");
            break;
        case 2:
            printf("\nYou're in the hallway.\nA couple juniors talking are on your left.\nYour RA is talking to some freshmen on the right.\n\n");
            break;
        case 3:
            printf("\nYou hop out of your uber and enter into Cool Runnings Jamaican Bar.\n");
            printf("Go ahead and order a drink or approach the dance floor\n\n");
            break;
        case 4:
            printf("\nYou hop out of your uber and enter into Barcade.\n");
            printf("You see some friends at the other side of the bar\n");
            printf("Go ahead and order a drink or talk to your friends\n\n");
            break;
        case 5:
            printf("\nYou unpack your bags and sit down at a table.\n");
            printf("Your calc TA is seated across the room. On the other side of the room is the weird kid in your class.\n\n");
            break;
        case 6:
            printf("\nYou follow you the other freshmen into the duncan event.\n");
            printf("You see a group of girls to your left and a line leading to a stage\n\n");
            break;
        case 7:
            printf("\nYou enter into Five Guys.\n");
            printf("You can go order food.\n\n");
            break;
        case 8:
            printf("\nYou walk back into your dorm room.\n\n");
            break;
        case 9:
            printf("\nYou pull up to the football stadium and see Owen.\n\n");
            break;
    }
}



void playerTurn()
{
    char answer[10];
    scanf("%s", answer);

    if (strcmp(answer,"look")==0)
    {
        look();
    }
    else if (strcmp(answer,"travel")==0)
    {
        travel();
    }
    else if (strcmp(answer,"talk")==0)
    {
        talk();
    }
    else if (strcmp(answer,"order")==0)
    {
        order();
    }
    else if (strcmp(answer,"approach")==0)
    {
        approach();
    }
    else if (strcmp(answer,"help")==0)
    {
        help();
    }
    else
    {
        printf("S\norry I don't know that command. Try Again\n\n");
    }
}

void travel()
{
    char object[10];
    scanf("%s", object);

    if (strcmp(object,"hallway") == 0)
    {
        environment = 2;
        newIndividuals();
        look();
    }
    else if (strcmp(object,"dorm") == 0 || strcmp(object,"room") == 0)
    {
        environment = 8;
        newIndividuals();
        look();
    }
    else if (strcmp(object,"CoolRunnings") == 0 || strcmp(object,"cool") == 0)
    {
        environment = 3;
        newIndividuals();
        look();
    }
    else if (strcmp(object,"barcade") == 0)
    {
        environment = 4;
        newIndividuals();
        look();
    }
    else if (strcmp(object,"library") == 0)
    {
        environment = 5;
        newIndividuals();
        look();
    }
    else if (strcmp(object,"event") == 0 || strcmp(object,"duncan") == 0)
    {
        environment = 6;
        newIndividuals();
        look();
    }
    else if (strcmp(object,"five") == 0 || strcmp(object,"food") == 0)
    {
        environment = 7;
        newIndividuals();
        look();
    }
    else if (strcmp(object,"hockey") == 0 || strcmp(object,"game") == 0)
    {
        printf("\nYou didn't get tickets for this event.\n\n");
    }
    else if (strcmp(object,"football") == 0 || strcmp(object,"stadium") == 0)
    {
        environment = 9;
        newIndividuals();
        look();
    }
    else
    {
        printf("\nSorry I didn't understand that command. Try Again\n");
    }
}


// Function changes the individuals someone can talk to based on their location
// 0 = no people to talk to in this area
// 1 = roommate
// 2 = RA
// 3 = friends at Barcade
// 4 = TA

void newIndividuals()
{
    if (environment == 1)
    {
        individual = 1;
    }
    else if (environment == 2)
    {
        individual = 2;
    }
    else if (environment == 3)
    {
        individual = 0;
    }
    else if (environment == 4)
    {
        individual = 3;
    }
    else if (environment == 5)
    {
        individual = 4;
    }
    else if (environment == 6)
    {
        individual = 0;
    }
    else if (environment == 7)
    {
        individual = 0;
    }
    else if (environment == 8)
    {
        individual = 0;
    }
}

// Function for talking with people

void talk()
{
    char object[10];
    scanf("%s", object);

    if (strcmp(object,"roommate") == 0)
    {
        printf("\nDavid: \"Man, I just cannot go out tonight I'm beat. I think I might just head to bed\"\n\n");
    }
    else if (strcmp(object,"juniors") == 0)
    {
        printf("\nTony: \"Did you guys grab hockey tickets for tonight?\"\nJames: \"Nah I didn't get any. I might just head to my girlfriend's tonight.\"\nTony: \"Sounds good, I'll hit up some of my other friends.\"\n\n");
    }
    else if (strcmp(object,"RA") == 0)
    {
        printf("\nDom: \"I heard there was some event going on in Duncan tonight you guys can go to\"\n");
        printf("Rory: \"I think we might head to CoolRunnings or barcade tonight.\"\n");
        printf("Alex: \"Yeah, I heard it might be packed tonight\"\n");
        printf("Dom: \"Suit yourselves...\"\n\n");
    }
    else if (strcmp(object,"friends") == 0)
    {
        printf("\nAndy: \"Hey! What's up, glad you made it out tonight.\"\n");
        printf("Jake: \"Yeah now this place is packed\"\n");
        printf("Jake: \"Oh hey I see some guys from my class. Here follow me.\"\n");
        printf("Jake: \"Hey guys this is my friend.\"\n");
        printf("*You guys walk across the bar*\n");
        printf("Owen: \"What's up nice to meet you. Dude, me and my buddies have been brewing up this idea. We're goig to break into the football stadium. If you're in come to the football field later tonight.\"\n");
        printf("Jake: \"Dude that's kinda nuts are you sure about that. We might just go grab some Five Guys later.\"\n");
        printf("Owen: \"Suit yourself, man. But you know where to find us.\"\n");
        printf("*Owen walks away*\n");
        printf("Jake: \"Sorry that was really weird. I'm gonna go get a drink\"\n\n");
    }
    else if (strcmp(object,"TA") == 0)
    {
        printf("\nMelissa: \"Oh hey. If you need anything you know where to find me.\"\n\n");
    }
    else if (strcmp(object,"kid") == 0)
    {
        printf("\nJohnny: \"Hello there. It's good to see you. I was just looking at your house on Zillow.\"\n\n");
    }
    else if (strcmp(object,"girls") == 0)
    {
        printf("\nGirl 1: \"Oh hey. What's your name?\"\n\n");
        char object2[10];
        scanf("%s",object2);
        if (strcmp(object2,"Nico")==0)
        {
            printf("\nGirl 1: \"You know what. Let me get your snap.\"\n\n");
        }
        else
        {
            printf("\nGirl 1: \"Hey sorry I have a boyfriend.\"\n\n");
        }
    }
    else if (strcmp(object,"Owen") == 0)
    {
        printf("\nOwen: \"What's up. I'm glad you decided to come. This gonna be awesome. Are you in? (Y/N): ");
        char yesNo;
        scanf("%c", &yesNo);
        if (yesNo == 'Y')
        {
            printf("\nOwen: \"Ok here's the plan. I'm gonna take this wedge and warp the gate. Then you're gonna slip in and try to open the stadium from the inside.\"\n");
            printf("*You manage to just barely shimmy your way past the gate*");
        }
        else
        {
            printf("\nOwen: \"Hey your loss.\"\n\n");
        }
    }
    else
    {
        printf("\nSorry I didn't understand that command. Try Again\n\n");
    }
}

void order()
{
    char object[10];
    scanf("%s", object);

    printf("\nYou ordered a %s.\n\n", object);
}

void approach()
{
    char object[10];
    scanf("%s", object);

    if (strcmp(object, "dance"))
    {
        char object1[10];
        scanf("%s", object1);

        if(strcmp(object1, "floor"))
        {
            printf("\nYou are now on the dance floor. It's kinda crowded and sweaty here.\n\n");
        }
        
        else
        {
            printf("Sorry I don't understand that command");
        }
    }
    else if (strcmp(object, "line"))
    {
        printf("\nYou enter the line. You're not too sure what the lines for. Looks like they're giving out T-shirts at the front.\n\n");
    }
    else
    {
        printf("\nSorry I don't know that command.\n\n");
    }
}

void help()
{
    printf("\nWelcome to the Help Menu!\n");
    printf("There are 5 basic commands: \n1. look\n2. travel\n3. talk\n4. order\n5. approach");
    printf("\nLook: type this command for the game to redescribe the area around you.");
    printf("\nTravel: type this command + the location to travel to that area. *Only type travel + *location*.");
    printf("\nTalk: type this command + a person to talk with them. Only type look + *person*.");
    printf("\nOrder: type this command to order food or drinks at certain locations.");
    printf("\nType *help* again if you ever want this menu again.\n\n");
}




