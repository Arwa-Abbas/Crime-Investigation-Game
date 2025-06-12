#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	//EASY LEVEL CASE STUDY SCENERIO
	ofstream f1("easy_scenerio.txt");
	if (!f1.is_open()) 
	{
        cout << "Error opening the file" << endl;
        return 1; 
    }
    f1 << "EASY LEVEL CASE STUDY SCENERIO\n\n";
    f1 << "Scenerio: Inside the Monet Art Gallery, people walk around looking at beautiful paintings...";
    f1 << "\nThey talk quietly and say nice things about the art. Glasses make a gentle sound when people take sips of champagne....";
    f1 << "\nSoft music from a violin fills the room. Victor Monet, the famous artist everyone came to see, is talking to someone in a quiet corner......";
    f1 << "\nThey seem upset, like they're arguing about something. Even though they're speaking quietly, you can feel the tension between them.";
    f1 << "\nIt's clear that something isn't right.";
    f1 << "\n\nAll of a sudden, a really loud scream breaks the quietness.....";
    f1 << "\nIt's so loud that it stops everyone talking. People look around, surprised and curious, trying to figure out where the scream came from....";
    f1 << "\nThe calm and peaceful mood disappears, replaced by a feeling of worry and fear spreading through the crowd....";
    f1 << "\n\nIn all the noise and confusion, something terrible is found.";
    f1 << "\nVictor Monet is lying on the floor, not moving at all......";
    f1 << "\nThere's a knife next to him, and it's covered in blood. The gallery looks a mess, with paintings knocked over and art supplies scattered everywhere.";
    f1 << "\nIt seems like there was a fight just before. People are shocked and scared as they see what's happened.......";
    f1.close();
    
    //MEDIUM LEVEL CASE STUDY SCENERIO
	ofstream f2("medium_scenerio.txt");
	if (!f2.is_open()) 
	{
        cout << "Error opening the file" << endl;
        return 1; 
    }
    f2 << "MEDIUM LEVEL CASE STUDY SCENERIO\n\n";
    f2 << "Scenario: Detective Inspector Mark Thompson is found dead in his office, a single gunshot wound to the head....";
	f2 << "\nInitially ruled as suicide due to the presence of a gun and a suicide note, suspicions arise when inconsistencies in the evidence point towards foul play.....";
    f2 << "\nAs the investigation unfolds, it becomes clear that Detective Inspector Thompson was on the brink of solving a long-forgotten cold case.....";
	f2 << "\nIt had haunted him for years....";
	f2 << "\n\nMark's files has been missing from his desk in his home....";
	f2 << "\nBloodstains appear to wipe out out on the floor....";
	f2 << "\nThere are gunshot residue everywhere around him.......";
	f2.close();
	
	//HARD LEVEL CASE STUDY SCENERIO
	ofstream f3("hard_scenerio.txt");
	if (!f3.is_open()) 
	{
        cout << "Error opening the file" << endl;
        return 1; 
    }
	f3 << "HARD LEVEL CASE STUDY SCENERIO\n\n";
	f3 << "Scenerio: Edenbrook Hospital, a beacon of hope in the heart of the city, becomes the epicenter of a harrowing mystery....";
	f3 << "\nThe hospital was working just fine, doctors operating the patients....";
	f3 << "\nTyler Bennett, a resilient teenager battling a rare genetic disorder has been admitted to that hospital a while ago....";
	f3 << "\nBut a shocking news come....he is found murdered in his hospital room!";
	f3 << "\n\nThere were presence of wrong medication on Tyler's Blood...";
	f3 << "\nThe hospital surveillance footage has been removed.....";
	f3 << "\nSomething is suspcious, there was someone in tyler's room....mysterious hair is found..who could be?";
	f3.close();
	cout << "All levels case study scenerios has been written successfully";
	return 0;
}
