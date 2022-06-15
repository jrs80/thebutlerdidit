#include <iostream>
//#include <conio>
//#include <string>

using namespace std;

#define FOYER 0
#define CLOSET 1
#define BATHROOM 2
#define LIVING_ROOM 3
#define KITCHEN 4
#define HALLWAY 5
#define MASTER_BR 6
#define GUEST_BR 7

#define FORK 0
#define DNA 1
#define STATEMENT 2
#define CONFESSION 3

int currentRoom = -1;

class Inventory
{
public:
	bool hasFork;
	bool hasDNA;
	bool hasStatement;
	bool hasConfession;
	int numItems = 0;

	Inventory()
		:hasFork(false), hasDNA(false),
		hasStatement(false), hasConfession(false),
		numItems(0)
	{}

	int DisplayInventoryStatus() {
		if (numItems == 4)
			cout << "\nYou have enough evidence to make an arrest!";
		else
			cout << "\n\nYou have obtained " << numItems << " pieces of evidence so far.  Keep working, Detective!";
		return numItems;
	}

	int AddItem(int item) {
		switch (item) {
		case FORK:
			hasFork = true;
			cout << "\nThe fork has been added to your evidence list.";
			break;
		case DNA:
			hasDNA = true;
			cout << "\nThe DNA has been added to your evidence list.";
			break;
		case STATEMENT:
			hasStatement = true;
			cout << "\nThe witness statement has been added to your evidence list.";
			break;
		case CONFESSION:
			hasConfession = true;
			cout << "\nThe confession has been added to your evidence list.";
			break;
		default: cout << "\nInventory Error!"; return -1;
		}
		numItems++;
		return numItems;
	}
};

int DisplayRoomMsg(int, Inventory);
void ErrorMsg(int);
void Pause(void);
void MoveRoom(char);

int main(void)
{
	char c;
	char c2;

	cout << "Good morning, Detective.";
	Pause();

	cout << "\nYou have arrived at the scene of a murder.  It is a small house.";
	Pause();

	cout << "\nYour job is to determine who killed the victim, John Doe.";
	Pause();

	cout << "\nYou have very little information at this point--you will need to speak with witnesses in the house to gather more information.";
	Pause();

	cout << "\nYou will also need to gather physical evidence against the perpetrator.";
	Pause();

	cout << "\nGood luck!";
	Pause();

	currentRoom = FOYER;
	bool playing = true;
	Inventory evidence;

	while (playing = true) {
		system("cls");
		DisplayRoomMsg(currentRoom, evidence);
		if (evidence.DisplayInventoryStatus() == 4) {
			cout << "\nAre you ready to make an arrest?";
			cin >> c;
			if (c == 'n' || c == 'N') { cout << "\nOkay, you decide to keep looking around the house."; continue; }
			else if (c == 'y' || c == 'Y') {
				cout << "\nYou go to the kitchen.  Boris the Butler is standing with his back against the kitchen counter.";
				Pause();
				cout << "\n\"Well, well, well.  Who would have thought...\"";
				Pause();
				cout << "\n\"The butler did it!\"";
				Pause();
				cout << "\n\"Boris, you are under arrest!\"";
				Pause();
				cout << "\nBoris brings his hand out from behind his back, and you realize he is holding a large kitchen knife.  Uh-oh!";
				Pause();
				cout << "\nYou take a step backward.  \"Boris, you don't want to do this.\"";
				Pause();
				cout << "\nBut before you say anything else, Boris lunges at you with the knife.";
				Pause();
				cout << "\nBANG!";
				Pause();
				cout << "\nWhat the...";
				Pause();
				cout << "\nYou see Mrs. Doe standing in the doorway, a smoking revolver in her hand.";
				Pause();
				cout << "\nBoris lies bleeding on the floor.";
				Pause();
				cout << "\nWell, this has been quite the day.";
				Pause();
				cout << "\nAt least you solved the murder of John Doe!";
				Pause();
				cout << "\n\nThank you for playing!";
				Pause();
				return 0;
			}
			else {
				ErrorMsg(1);
				continue;
			}

		}

		cout << "\n\nWhat would you like to do?";
		cout << "\nOptions: [m]ove, [t]alk, [p]ick up or use an object.";
		cin >> c;

		switch (c) {
		case 'm':
			cout << "\nWhich direction do you want to move?";
			cout << "\nOptions: [f]orward, [b]ackward, [l]eft, [r]ight.";
			cin >> c2;
			MoveRoom(c2);
			break;

		case 't':
			if (currentRoom==KITCHEN && !evidence.hasStatement) {
				cout << "\nBoris says he just arrived to work for the day and doesn't know anything about the murder.";
				Pause();
				cout << "\nHe doesn't seem very sad about it, though.";
				Pause();
			}
			else if (currentRoom==KITCHEN && evidence.hasStatement && !evidence.hasDNA) {
				cout << "\nYou tell Boris that you are aware that he had an argument with the victim over the Tupperware theft.";
				Pause();
				cout << "\nHe denies having had an argument with John.";
				Pause();
				cout << "\nHe seems very nervous talking with you.  Hmm...";
				Pause();
			}
			else if (currentRoom==KITCHEN && evidence.hasStatement && evidence.hasDNA) {
				cout << "\nYou confront Boris with the fork.";
				Pause();
				cout << "\n\"Big deal,\" he says.";
				Pause();
				cout << "\nThen you tell him about Mrs. Doe's statement.";
				Pause();
				cout << "\nBoris just shrugs.";
				Pause();
				cout << "\nFinally, you show him the DNA evidence.";
				Pause();
				cout << "\nBoris tries to run!";
				Pause();
				cout << "\nYou stop him before he can get out of the house.";
				Pause();
				cout << "\n\"Okay, okay!\" he says.  \"I did it!  I killed John Doe!\"";
				Pause();
				evidence.AddItem(CONFESSION);
			}
			
			if (currentRoom == LIVING_ROOM && !evidence.hasStatement) {
				cout << "\nYou approach Mrs. Doe and introduce yourself.";
				Pause();
				cout << "\nYou give her your condolences on the loss of her husband.";
				Pause();
				cout << "\nYou ask her if she has any information for you.";
				Pause();
				cout << "\n\"Why, yes, Detective.  There are a few things I think you should know.";
				Pause();
				cout << "\n\"First of all, I know this looks bad, but I did not kill my husband.";
				Pause();
				cout << "\n\"I did yell at him yesterday, but that was over a minor Tupperware-related incident.  I love him--er, loved him!\"";
				Pause();
				cout << "\nYou think for a moment, then ask about the Tupperware-related incident.";
				Pause();
				cout << "\n\"Oh, well, what happened was that John accused Boris--that's our butler--of stealing some Tupperware.  Boris denied it, and I believed him.  John and I got into an argument about it.  In the end, John told Boris he was sorry for accusing him.  It was no big deal...";
				Pause();
				cout << "\n\"Although now that I think about it, Boris seemed really angry about the whole thing.\"";
				Pause();
				cout << "\nHmm.  Sounds like you should talk to Boris!";
				evidence.AddItem(STATEMENT);
			}
			break;

		case 'p':
			if (currentRoom == BATHROOM && !evidence.hasFork) {
				system("cls");
				cout << "\nYou look behind the toilet.  The object is, indeed, a fork!  That's strange.  You decide to take the fork.  When you pick it up, you see that it is covered in a brown crusty substance...blood!?";
				Pause();
				evidence.AddItem(FORK);
				Pause();
			}
			else if (currentRoom == GUEST_BR && !evidence.hasDNA) {
				cout << "\nYou run the fork through the DNA analyzer.";
				cout << "\nIt says the blood belongs to John Doe.  No surprise there!";
				Pause();
				cout << "\nBut wait, there's more...";
				Pause();
				cout << "\nIt also says there was DNA on the other end of the fork, and it belongs to...";
				Pause();
				cout << "\n...";
				Pause();
				cout << "\nBoris the Butler!";
				Pause();
				cout << "\nWell, well, well...";
				Pause();
				evidence.AddItem(DNA);
			}
			else { cout << "\nThere is nothing useful here."; Pause(); }
			break;

		default: ErrorMsg(1);
		}

		Pause();

	}

	cout << "\n\nThank you for playing!";
	Pause();
	return 0;
}

int DisplayRoomMsg(int room, Inventory evidence) {
	switch (room) {
		case FOYER:
			cout << "\nYou are standing in the foyer of the house.\nTo your left is a coat closet.\nTo your right is the bathroom.\nStraight ahead is the living room.";
			break;

		case LIVING_ROOM:
			cout << "\nYou are standing in the living room.  Behind you is the foyer.  To your left is the kitchen.  To your right is a hallway.";
			if (!evidence.hasStatement)
				cout << "\nYou see Mrs. Doe sitting on a sofa.";
			else cout << "\nThere is nobody here now.";
			break;

		case BATHROOM:
			cout << "\nYou are in the bathroom.  It smells like bleach.  Behind you is the foyer.";
			Pause();
			if (!evidence.hasFork) {
				cout << "\nYou see something odd sticking out from behind the toilet. Is it...a fork!?";
				break;
			}
			else { cout << "\nYou see nothing of interest here."; break; }

	case CLOSET:
		cout << "\nYou find yourself in the closet.  It is filled with coats.";
		cout << "\nBehind you is the foyer.";
		break;

	case HALLWAY:
		cout << "\nYou are standing in a short hallway.  Behind you is the living room.  To your left is the main bedroom.  To your right is the guest bedroom.";
		cout << "\nThere is nothing of interest in the hallway--just a few potted plants and some framed photos on the wall.";
		break;

	case MASTER_BR:
		cout << "\nYou are now in the main bedroom.  John Doe lies dead on the floor.";
		Pause();
		cout << "\nYou inspect his body.  There is a stab wound in his chest.";
		Pause();
		cout << "\nThe wound looks odd--almost like four small gashes.";
		Pause();
		if (evidence.hasFork) cout << "\nYou look at the fork you found in the bathroom.  Hmmm...";
		else cout << "\nYou'd better look around the house and see if you can find the murder weapon.";
		Pause();
		break;

	case GUEST_BR:
		cout << "\nYou are in a small guest bedroom.  It looks like it's being used as a home office.  There is a strange-looking device on a desk.";
		Pause();
		cout << "\nYou take a closer look at the machine. You realize it is a DNA analyzer.  How convenient!";
		Pause();
		if (!evidence.hasFork) { cout << "\nIf you find the murder weapon, then you could run it through the DNA analyzer."; Pause(); }
		else cout << "\nSince you have the murder weapon, you should use the DNA analyzer!";
		break;

	case KITCHEN:
		cout << "\nYou are now in the spacious kitchen and dining area.  A well-dressed man stands near the island.  This must be Boris the Butler.";
		Pause();
		break;
	default: cout << "\nError in DisplayRoomMsg! :("; return -1;
	}

	return 0;
}

void ErrorMsg(int m) {
	switch (m) {
	case 0: cout << "\nYou cannot go that way.  Try again."; break;
	case 1: cout << "\nInvalid input.  Try again."; break;
	default: cout << "\nUnknown error."; break;
	}
	Pause();
}

void Pause() {
	cin.get();
}

void MoveRoom (char direction) {
	switch (direction) {
	case 'f':
		if (currentRoom == FOYER) { currentRoom = LIVING_ROOM; break; }
		else { ErrorMsg(0); break; }
	case 'l':
		if (currentRoom == FOYER) { currentRoom = CLOSET; break; }
		else if (currentRoom == HALLWAY) { currentRoom = MASTER_BR; break; }
		else if (currentRoom == LIVING_ROOM) { currentRoom = KITCHEN; break; }
		else { ErrorMsg(0); break; }
	case 'b':
		switch (currentRoom) {
		case BATHROOM:
		case CLOSET:
		case LIVING_ROOM: currentRoom = FOYER; break;
		case KITCHEN:
		case HALLWAY: currentRoom = LIVING_ROOM; break;
		case MASTER_BR:
		case GUEST_BR: currentRoom = HALLWAY; break;
		default: ErrorMsg(0);
		}
		break;
	case 'r':
		if (currentRoom == FOYER) { currentRoom = BATHROOM; break; }
		else if (currentRoom == LIVING_ROOM) { currentRoom = HALLWAY; break; }
		else if (currentRoom == HALLWAY) { currentRoom = GUEST_BR; break; }
		else { ErrorMsg(0); break; }
	default: ErrorMsg(1);
	}
}