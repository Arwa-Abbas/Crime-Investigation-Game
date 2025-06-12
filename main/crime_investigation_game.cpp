#include <iostream>
#include <fstream>
#include<ctime>
#include<algorithm>
using namespace std;

class VictimProfile 
{
    private:
    string name;
    int age;
    string occupation;
    string education;
    string family_background;
    public:
    VictimProfile(string n = "",int a=0, string occ= "", string edu="", string fam="") : name(n),age(a),occupation(occ),education(edu),family_background(fam) {}
    void displayprofile() 
    {
        cout << "\n\nVICTIM PROFILE\n";
        cout << "---------------------------------------------------------------------------------------------\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Occupation: " << occupation << endl;
        cout << "Education: " << education << endl;
        cout << "Family Background: " << family_background << endl;
        cout << "---------------------------------------------------------------------------------------------\n";
    }
};

class Suspect 
{
    protected:
    string name;
    int age;
    string occupation;
    string education;
    string family_background;
    string hint;
    public:
    Suspect(string n="",int a=0,string occ="",string edu="",string fam="",string hint=""):name(n),age(a),occupation(occ),education(edu),family_background(fam),hint(hint) {}
    void display_suspect_profile() 
	{
         cout << "\n\nSUSPECT PROFILE\n";
        cout << "\n---------------------------------------------------------------------------------------------\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Occupation: " << occupation << endl;
        cout << "Education: " << education << endl;
        cout << "Family Background: " << family_background << endl;
        cout << "\n----------------------------------------------------------------------------------------------\n";
    }
    void initiate_conversation() 
	{
        cout << "\nYou approach " << name << ", a " << occupation << "." << endl;
        cout << name << " seems tense and guarded." << endl;
        cout << "HINT: " << hint << endl;
    }
    // Virtual method to ask questions
    virtual void questions_set1()=0;
    virtual void questions_set2()=0;
    virtual void questions_set3()=0;
    // Virtual method to answer questions
    virtual void answers_set1(int questionNumber)=0;
    virtual void answers_set2(int questionNumber)=0;
    virtual void answers_set3(int questionNumber)=0;
};

//derived classes for each level suspects
class SophiaDuval:public Suspect 
{
    private:
    const char* answersFile;
    string readAnswers(int questionNumber) const 
	{
        ifstream inFile(answersFile);
        if (!inFile) 
		{
            cerr << "Error opening the answers file" << endl;
            return "Error";
        }
        string answer;
        for (int i=0;i<questionNumber;i++) 
		{
            getline(inFile,answer);
        }
        inFile.close();
        return answer;
    }
   public:
    SophiaDuval(const char* file):Suspect("Sophia Duval", 38, "Art Dealer", "Masters in Art History", "Married with no children, close relationship with siblings",
                  "Known for her cutthroat tactics in the art world."), answersFile(file) {}
     void questions_set1() override 
	{
		cout << "\n-------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 1:" << endl;
        cout << "1. Where were you during the murder?" << endl;
        cout << "2. Can you describe your interaction with Victor Monet on the night of the gala?" << endl;
    }
    void questions_set2() override 
	{
		cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 2:" << endl;
        cout << "3. What was your relationship with Victor Monet?" << endl;
        cout << "4. Did you have any prior conflicts with Victor Monet?" << endl;
    }
    void questions_set3() override 
	{
		cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 3:" << endl;
        cout << "5. Did you see anyone suspicious around Victor's studio that evening?" << endl;
        cout << "6. Have you had any financial difficulties lately?" << endl;
    }
    void answers_set1(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 3); //Offset by 3 because of headings
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    void answers_set2(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 5); // Offset by 5 because there are 2 questions in set 1
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    void answers_set3(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 7); // Offset by 7 because there are 4 questions in set 1 and set 2 combined
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
};

class MarcusGreene:public Suspect 
{
    private:
    const char* answersFile;
    string readAnswers(int questionNumber) const 
	{
        ifstream inFile(answersFile);
        if (!inFile) 
		{
            cerr << "Error opening the answers file" << endl;
            return "Error";
        }
        string answer;
        for (int i=0;i<questionNumber;i++) 
		{
            getline(inFile,answer);
        }
        inFile.close();
        return answer;
    }
   public:
    MarcusGreene(const char* file):Suspect("Marcus Greene", 30, "Aspiring Artist", "Self-taught prodigy", "Single, distant relationship with family",
	 "Envious of Victor's success and felt overshadowed by him."), answersFile(file) {}
     void questions_set1() override 
	{
		cout << "\n-------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 1:" << endl;
        cout << "1. Where were you during the murder?" << endl;
        cout << "2. Can you describe your interaction with Victor Monet on the night of the gala?" << endl;
    }
    void questions_set2() override 
	{
		cout << "\n-------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 2:" << endl;
        cout << "3. What was your relationship with Victor Monet?" << endl;
        cout << "4. Did you have any prior conflicts with Victor Monet?" << endl;
    }
    void questions_set3() override 
	{
		cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 3:" << endl;
        cout << "5. Did you see anyone suspicious around Victor's studio that evening?" << endl;
        cout << "6. Have you ever felt envious of Victor's success?" << endl;
    }
    void answers_set1(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 17); //Offset by 17 due to suspect 1 answers
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    void answers_set2(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 19); // Offset by 19 because there are 2 questions in set 1
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    void answers_set3(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 21); // Offset by 21 because there are 4 questions in set 1 and set 2 combined
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
};

class ElenaVasquez:public Suspect 
{
    private:
    const char* answersFile;
    string readAnswers(int questionNumber) const 
	{
        ifstream inFile(answersFile);
        if (!inFile) 
		{
            cerr << "Error opening the answers file" << endl;
            return "Error";
        }
        string answer;
        for (int i=0;i<questionNumber;i++) 
		{
            getline(inFile,answer);
        }
        inFile.close();
        return answer;
    }
   public:
    ElenaVasquez(const char* file):Suspect("Elena Vasquez", 50, "Art Collector", "Bachelor's in Fine Arts", "Widowed with grown-up children",
	 "Obsessed with Victor's latest painting and frustrated over not being able to acquire it."), answersFile(file) {}
    void questions_set1() override 
	{
		cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 1:" << endl;
        cout << "1. Where were you during the murder?" << endl;
        cout << "2. Can you describe your interaction with Victor Monet on the night of the gala?" << endl;
    }
    void questions_set2() override 
	{
		cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 2:" << endl;
        cout << "3. What was your relationship with Victor Monet?" << endl;
        cout << "4. Did you have any prior conflicts with Victor Monet?" << endl;
    }
    void questions_set3() override 
	{
		cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 3:" << endl;
        cout << "5. Did you see anyone suspicious around Victor's studio that evening?" << endl;
        cout << "6. Have you ever expressed frustration over not being able to acquire Victor's paintings?" << endl;
    }
    void answers_set1(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 31); //Offset by 31 because of suspect 1 and suspect 2 answers
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    void answers_set2(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 33); // Offset by 33 because there are 2 questions in set 1
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    void answers_set3(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 35); // Offset by 35 because there are 4 questions in set 1 and set 2 combined
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
};

//derived classes for medium level suspects
class DavidMiller:public Suspect 
{
    private:
    const char* answersFile;
    string readAnswers(int questionNumber) const 
	{
        ifstream inFile(answersFile);
        if (!inFile) 
		{
            cerr << "Error opening the answers file" << endl;
            return "Error";
        }
        string answer;
        for (int i=0;i<questionNumber;i++) 
		{
            getline(inFile,answer);
        }
        inFile.close();
        return answer;
    }
   public:
    DavidMiller(const char* file):Suspect("David Miller",45, "Construction Worker", "High School Graduate"," Divorced, estranged from his children",
                  "Known for his temper, particularly when his innocence is questioned."), answersFile(file) {}
     void questions_set1() override 
	{
		cout << "\n-------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 1:" << endl;
        cout << "1. Where were you during the time of Detective Inspector Thompson's death?" << endl;
        cout << "2. Can you describe any interactions you had with Detective Inspector Thompson recently?" << endl;
    }
    void questions_set2() override 
	{
		cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 2:" << endl;
        cout << "3. What was your relationship with Detective Inspector Thompson? " << endl;
        cout << "4.  Did you have any prior conflicts with Detective Inspector Thompson?" << endl;
    }
    void questions_set3() override 
	{
		cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 3:" << endl;
        cout << "5. Did you see anyone suspicious around the precinct or Detective Inspector Thompson's office that evening?" << endl;
        cout << "6. Have you had any run-ins with the law since your release?" << endl;
    }
    void answers_set1(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 3); //Offset by 3 because of headings
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    void answers_set2(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 5); // Offset by 5 because there are 2 questions in set 1
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    void answers_set3(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 7); // Offset by 7 because there are 4 questions in set 1 and set 2 combined
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
};

class SarahThompson:public Suspect 
{
    private:
    const char* answersFile;
    string readAnswers(int questionNumber) const 
	{
        ifstream inFile(answersFile);
        if (!inFile) 
		{
            cerr << "Error opening the answers file" << endl;
            return "Error";
        }
        string answer;
        for (int i=0;i<questionNumber;i++) 
		{
            getline(inFile,answer);
        }
        inFile.close();
        return answer;
    }
   public:
    SarahThompson(const char* file):Suspect("Sarah Thompson",40, "Former Police Officer (now unemployed)", "Bachelor's Degree in Criminal Justice","Married to Detective Inspector Mark Thompson",
                  "Known for her manipulative tendencies, especially when it comes to protecting her own interests."), answersFile(file) {}
     void questions_set1() override 
	{
		cout << "\n-------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 1:" << endl;
        cout << "1. Where were you at the time of your husband's death?" << endl;
        cout << "2. Can you describe any interactions you had with Detective Inspector Thompson recently?" << endl;
    }
    void questions_set2() override 
	{
		cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 2:" << endl;
        cout << "3. How was your relationship with Detective Inspector Thompson? " << endl;
        cout << "4.  Did you have any prior conflicts with Detective Inspector Thompson?" << endl;
    }
    void questions_set3() override 
	{
		cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 3:" << endl;
        cout << "5. Did you see anyone suspicious around the precinct or Detective Inspector Thompson's office that evening?" << endl;
        cout << "6. Have you and your husband been having any marital problems recently?" << endl;
    }
    void answers_set1(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 17); //Offset by 17 due to suspect 1
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    void answers_set2(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 19); // Offset by 19 because there are 2 questions in set 1
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    void answers_set3(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 21); // Offset by 21 because there are 4 questions in set 1 and set 2 combined
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
};

class FrankLawson:public Suspect 
{
    private:
    const char* answersFile;
    string readAnswers(int questionNumber) const 
	{
        ifstream inFile(answersFile);
        if (!inFile) 
		{
            cerr << "Error opening the answers file" << endl;
            return "Error";
        }
        string answer;
        for (int i=0;i<questionNumber;i++) 
		{
            getline(inFile,answer);
        }
        inFile.close();
        return answer;
    }
   public:
    FrankLawson(const char* file):Suspect("Frank Lawson",65, "Retired Detective","Associate's Degree in Criminal Justice","Widower, with one adult son",
        " Known for his stubbornness and refusal to accept criticism, especially regarding his past investigations."), answersFile(file) {}
     void questions_set1() override 
	{
		cout << "\n-------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 1:" << endl;
        cout << "1. Where were you during the time of Detective Inspector Thompson's death?" << endl;
        cout << "2. Can you describe any interactions you had with Detective Inspector Thompson recently?" << endl;
    }
    void questions_set2() override 
	{
		cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 2:" << endl;
        cout << "3. What was your relationship with Detective Inspector Thompson? " << endl;
        cout << "4.  Did you have any prior conflicts with Detective Inspector Thompson?" << endl;
    }
    void questions_set3() override 
	{
		cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 3:" << endl;
        cout << "5. Did you see anyone suspicious around the precinct or Detective Inspector Thompson's office that evening?" << endl;
        cout << "6. Do you have any reason to want Detective Inspector Thompson dead?" << endl;
    }
    void answers_set1(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 31); //Offset by 31 because of suspect 1 and suspect 2 answers
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    void answers_set2(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 33); // Offset by 33 because there are 2 questions in set 1
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    void answers_set3(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 35); // Offset by 35 because there are 4 questions in set 1 and set 2 combined
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
};

//derived classes for hard level suspects
class EmilyHartley:public Suspect 
{
    private:
    const char* answersFile;
    string readAnswers(int questionNumber) const 
	{
        ifstream inFile(answersFile);
        if (!inFile) 
		{
            cerr << "Error opening the answers file" << endl;
            return "Error";
        }
        string answer;
        for (int i=0;i<questionNumber;i++) 
		{
            getline(inFile,answer);
        }
        inFile.close();
        return answer;
    }
   public:
    EmilyHartley(const char* file):Suspect("Dr. Emily Hartley",47, "Chief Physician","Doctor of Medicine (M.D.),specializing in Pediatrics","Married with two children, comes from a long line of doctors",
                  "Known for her compassionate bedside manner and dedication to her patients."), answersFile(file) {}
     void questions_set1() override 
	{
		cout << "\n-------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 1:" << endl;
        cout << "1. Where were you during the time of Tyler's murder?" << endl;
        cout << "2. Can you describe your interaction with Tyler on the night of his murder?" << endl;
    }
    void questions_set2() override 
	{
		cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 2:" << endl;
        cout << "3. What was your relationship with Tyler Bennett?" << endl;
        cout << "4. Did you have any conflicts with Tyler or his family prior to his death?" << endl;
    }
    void questions_set3() override 
	{
		cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 3:" << endl;
        cout << "5. Did you notice anything unusual or suspicious in Tyler's room before his death?" << endl;
        cout << "6. Have you ever administered any medication to Tyler that wasn't part of his prescribed treatment plan?" << endl;
    }
    void answers_set1(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 3); //Offset by 3 because of headings
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    void answers_set2(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 5); // Offset by 5 because there are 2 questions in set 1
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    void answers_set3(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 7); // Offset by 7 because there are 4 questions in set 1 and set 2 combined
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
};

class MeganBenett:public Suspect 
{
    private:
    const char* answersFile;
    string readAnswers(int questionNumber) const 
	{
        ifstream inFile(answersFile);
        if (!inFile) 
		{
            cerr << "Error opening the answers file" << endl;
            return "Error";
        }
        string answer;
        for (int i=0;i<questionNumber;i++) 
		{
            getline(inFile,answer);
        }
        inFile.close();
        return answer;
    }
   public:
    MeganBenett(const char* file):Suspect("Megan Benett",19, "College Student"," Pursuing a degree in Psychology at the local university","Younger sister of Tyler Bennett, close-knit family",
                  "Known for her strong sense of loyalty and protective nature towards her brother."), answersFile(file) {}
     void questions_set1() override 
	{
		cout << "\n-------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 1:" << endl;
        cout << "1. Where were you during the time of Tyler's murder?" << endl;
        cout << "2. Can you describe your interaction with Tyler on the night of his murder?" << endl;
    }
    void questions_set2() override 
	{
		cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 2:" << endl;
        cout << "3. What was your relationship with Tyler Bennett?" << endl;
        cout << "4. Did you have any conflicts with Tyler or his family prior to his death?" << endl;
    }
    void questions_set3() override 
	{
		cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 3:" << endl;
        cout << "5. Did you notice anything unusual or suspicious in Tyler's room before his death?" << endl;
        cout << "6. Have you ever had disagreements with the hospital staff regarding Tyler's treatment?" << endl;
    }
    void answers_set1(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 17); //Offset by 3 because of suspect 1 answers
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    void answers_set2(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 19); // Offset by 19 because there are 2 questions in set 1
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    void answers_set3(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 21); // Offset by 21 because there are 4 questions in set 1 and set 2 combined
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
};

class JakeEvans:public Suspect 
{
    private:
    const char* answersFile;
    string readAnswers(int questionNumber) const 
	{
        ifstream inFile(answersFile);
        if (!inFile) 
		{
            cerr << "Error opening the answers file" << endl;
            return "Error";
        }
        string answer;
        for (int i=0;i<questionNumber;i++) 
		{
            getline(inFile,answer);
        }
        inFile.close();
        return answer;
    }
   public:
    JakeEvans(const char* file):Suspect("Nurse Jake Evans",28, "Registered Nurse","Bachelor of Science in Nursing (B.S.N.)","Single, comes from a working-class background",
                  "Known for his amiable personality but also harbors a sense of resentment towards the Bennett family due to past conflicts."), answersFile(file) {}
     void questions_set1() override 
	{
		cout << "\n-------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 1:" << endl;
        cout << "1. Where were you during the time of Tyler's murder?" << endl;
        cout << "2. Can you describe your interaction with Tyler on the night of his murder?" << endl;
    }
    void questions_set2() override 
	{
		cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 2:" << endl;
        cout << "3. What was your relationship with Tyler Bennett?" << endl;
        cout << "4. Did you have any conflicts with Tyler or his family prior to his death?" << endl;
    }
    void questions_set3() override 
	{
		cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Set 3:" << endl;
        cout << "5. Did you notice anything unusual or suspicious in Tyler's room before his death?" << endl;
        cout << "6. Have you ever had disagreements with the hospital staff regarding patient care or hospital policies?" << endl;
    }
    void answers_set1(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 31); //Offset by 31 because of suspect 1 and 2 answers
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    void answers_set2(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 33); // Offset by 33 because there are 2 questions in set 1
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    void answers_set3(int questionNumber) override 
	{
        cout << "\nAnswer: ";
        string answer = readAnswers(questionNumber + 35); // Offset by 35 because there are 4 questions in set 1 and set 2 combined
        cout << answer;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    }
};

template<class T>
class Clue {
    private:
    T description;
    bool is_correct_clue;    //to check whether is correct clue related to case or not 
    public:
    Clue(T desc,bool clue):description(desc),is_correct_clue(clue) {}
    T getdescription() const { return description; }
    bool getclue() const { return is_correct_clue; }
};
// for inventory
template <class T>
class Weapon {
    private:
    T name;
    bool is_correct_weapon;    //to check whether is correct weapon related to case or not 
    public:
    Weapon(T n,bool weapon):name(n),is_correct_weapon(weapon) {}
    T getname() const { return name; } 
    bool getweapon() const { return is_correct_weapon; }
};
// inventory for weapons
class PlayerInventory {
    private:
    Clue<string>* clues[5]; // Maximum 5 clues
    Weapon<string>* weapons[5]; // Maximum 5 weapons
    int numClues;
    int numWeapons;
    public:
    PlayerInventory():numClues(0),numWeapons(0) {}
    void addclue(Clue<string>* clue){
        if (numClues<5) {
            clues[numClues]=clue;
			numClues++;}
        else{
            throw overflow_error("Inventory full! Cannot add more items.");}
        
    }
    void addweapon(Weapon<string>* weapon) {
        if (numWeapons<5) {
            weapons[numWeapons]=weapon;
			numWeapons++;}
        else{
            throw overflow_error("Inventory full! Cannot add more items.");}
        
    }
    void printinventory() const 
	{
        cout << "\n----------------------Inventory Clues------------------------\n";
        for (int i=0;i<numClues;i++) 
		{
            cout << clues[i]->getdescription() << endl;
        }
        cout << "\n--------------------Inventory Weapons-------------------------\n";
        for (int i=0;i<numWeapons;i++) 
		{
            cout << weapons[i]->getname() << endl;
        }
    }
    int calculatepoints() const 
	{
    int points=0;
    for (int i=0;i<numClues;i++) 
	{
        if (clues[i]->getclue()) 
		{
            points+=4;       //correct clue add 4 points each
        }
    }
    for (int i=0;i<numWeapons;i++) 
	{
        if (weapons[i]->getweapon()) 
		{
            points+=4; // correct weapon adds 4 points each
        }
    }
    return points;
    }
    void additems(Clue<string>* allclues[],Weapon<string>* allweapons[]) 
	{
		cout << "\n-------------------------------INVENTORY---------------------------------------\n";
        cout << "\nChoose total 5 out of all clues and weapons to add to your Inventory\n";
        cout << "INSTRUCTION:write the respected number of that clue or weapon\n" << endl;
        for (int i=0; i<10;i++) 
		{
            cout << i+1 << ". ";
            if (i<5) 
                cout << allclues[i]->getdescription() << " (Clue)" << endl;
            else 
                cout << allweapons[i-5]->getname() << " (Weapon)" << endl;
        }
        int choice;
        cout << "\nEnter the respected number of the item you want to add (separated by spaces): ";
        for (int i=0; i<5;i++) 
		{
            cin >> choice;
            if (choice>=1 && choice<=10) 
			{
                if (choice <= 5 && numClues<5) 
                    addclue(allclues[choice-1]);
                else if (choice>5 && numWeapons<5)
                    addweapon(allweapons[choice-6]);
            }
        }
    }
};

const int SIZE = 9; // Size of the crossword puzzle grid
const int POINTS_PER_WORD = 10; // Points earned for each correct word
const int MAX_TURNS_CROSSWORD = 3; // Maximum number of turns allowed for crossword game

class PointsHandler {
private:
    int points;

public:
    PointsHandler() : points(0) {}

    void addPoints(int newPoints) {
        points += newPoints;
    }

    int getPoints() const {
        return points;
    }
};

class Game {
protected:
    PointsHandler pointsHandler;

public:
    virtual void playGame() = 0;

    PointsHandler& getPointsHandler() {
        return pointsHandler;
    }
};

class CrosswordGame :public Game {
private:
    char grid[SIZE][SIZE] = {
        {'Z', 'W', 'F', 'R', 'Q','A','D','M','I'},
        {'E', 'V', 'I', 'D', 'E','N','C','E','M'},
        {'N', 'C', 'E', 'D', 'A','O','P','Q','I'},
        {'M', 'Q', 'A', 'F', 'M','N','L','F','S'},
        {'N', 'G', 'N', 'O', 'U','Y','A','E','S'},
        {'F', 'V', 'L', 'S', 'E','M','R','W','I'},
        {'C', 'R', 'Y', 'T', 'P','O','G','Q','N'},
        {'Z', 'X', 'U', 'Q', 'B','U','T','P','G'},
        {'U', 'P', 'Z', 'N', 'P','S','Z','I','F'},
    };

    char words[10][200] = {"ANONYMOUS","EVIDENCE", "MISSING"}; // Words to be guessed
    char clues[MAX_TURNS_CROSSWORD][2000] = {
        "Gunshot Residue: Analysis of gunshot residue on Mark's hands and clothing reveals inconsistencies with the suicide theory, suggesting that the gunshot wound was not self-inflicted.",
        "Case Files: Mark's case files pertaining to the reopened cold case are missing from his office, suggesting that someone may have tampered with or removed them to obstruct the investigation's progress.",
        "Threatening Messages: Investigators receive anonymous messages warning them to back off the investigation, suggesting that someone may be trying to intimidate or obstruct their progress."
    };
    bool usedWords[MAX_TURNS_CROSSWORD*2] = {false}; // Used words

    // Function to check if a word is one of the specified words
    bool isWordInList(const char* word) {
        for (int i = 0; i < MAX_TURNS_CROSSWORD; ++i) {
            if (strcmp(words[i], word) == 0 && !usedWords[i]) {
                usedWords[i] = true; // Mark the word as used
                return true;
            }
        }
        return false;
    }

public:
    void playGame() {
        PointsHandler pointsHandler; // PointsHandler for this game
        cout << "---------------CROSSWORD GAME-------------" << endl;
        cout << "Crossword Puzzle:" << endl;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cout << grid[i][j] << "  ";
            }
            cout << endl;
        }
        cout<<"\nIMPORTANT NOTE : Enter your guess in capital letters.\n";
        for (int turn = 1; turn <= MAX_TURNS_CROSSWORD; ++turn) {
            cout << "\nTurn " << turn << " - Enter a word from the crossword puzzle: ";
            char word[20];
            cin >> word;

            if (isWordInList(word)) {
                pointsHandler.addPoints(POINTS_PER_WORD);
                cout << "Correct! You earned " << POINTS_PER_WORD << " points." << endl;
                // Display clue for the correct word
                for (int i = 0; i < MAX_TURNS_CROSSWORD; ++i) {
                    if (strcmp(words[i], word) == 0) {
                        cout << "Clue: " << clues[i] << endl;
                        break;
                    }
                }
            } else {
                cout << "Incorrect! Please enter a different word." << endl;
            }
        }
        cout << "Crossword Game Over! Total Points: " << pointsHandler.getPoints() << "/" << (MAX_TURNS_CROSSWORD * POINTS_PER_WORD) << endl;
        getPointsHandler().addPoints(pointsHandler.getPoints()); // Accumulate points for this game
    }
};

class UnscrambleGame : public Game {
private:
    string item1[1];
    string item2[1];
    string clue1;
    string clue2;
    string clue3;

    string jumbleWord(const string& word) {
        string jumbled = word;
        random_shuffle(jumbled.begin(), jumbled.end());
        return jumbled;
    }

public:
    UnscrambleGame(const string& word1, const string& word2, const string& clue1="", const string& clue2="",const string& clue3="")
        : clue1(clue1), clue2(clue2),clue3(clue3) {
        item1[0] = word1;
        item2[0] = word2;
    }

    void playGame() override {
        PointsHandler pointsHandler; // PointsHandler for this game
        string cluesArr[] = {clue1, clue2, clue3};
        random_shuffle(cluesArr, cluesArr + 3); // Shuffle the array of clues
        
        for (int turn = 1; turn <= 2; ++turn) { // Adjust the number of turns
            string word;
            string clue;
            int attempts = 3;
            int pointsForTurn =  10 ;
            int currentPoints = pointsHandler.getPoints();
            if (turn == 1) {
                word = item1[0];
                if (!clue1.empty()) clue = cluesArr[0];
            } else if (turn == 2) {
                word = item2[0];
                if (!clue2.empty()) clue = cluesArr[1];
            } 

            string jumbledWord = jumbleWord(word);
            cout << "Unscramble the letters to reveal the word: " << jumbledWord << endl;

            string guess;
            while (attempts > 0) {
                cout << "Your guess (Attempts remaining: " << attempts << "): ";
                cin >> guess;

                if (guess == word) {
                    pointsHandler.addPoints(pointsForTurn);
                    break;
                } else {
                    cout << "Incorrect. Try again!\n";
                    --attempts;
                }
            }
            if (attempts == 0) {
                cout << "Out of attempts. The correct word was: " << word << endl;
            }
            if (!clue.empty()) {
                cout << "Clue: " << clue << endl; // Display clue for the current word
            }
            cout << "Current Score: " << (pointsHandler.getPoints() - currentPoints) << endl<<endl; // Show score after each turn
            
        }
        cout << "Total Score: " << pointsHandler.getPoints() << endl << endl; // Show total score 
        getPointsHandler().addPoints(pointsHandler.getPoints()); // Accumulate points for this game
    }
};

class WordAssociationGame : public Game {
private:
    string associations[2][2] = {
        {"art", "gallery"},
        {"paint", "brush"}
    };
    string hints[2] = {
        "a place where art work is present",
        "a tool used to apply paint"
    };

public:
    void playGame() override {
        int points = 0;
        for (int i = 0; i < 2; ++i) {
            const string& firstWord = associations[i][0];
            const string& secondWord = associations[i][1];
            const string& hint = hints[i];
            cout << "Hint: " << hint << endl;
            cout << "First Word: " << firstWord << endl;

            bool correctGuess = false;
            for (int attempt = 1; attempt <= 3; ++attempt) {
                cout << "Your guess (Attempts remaining: " << (4 - attempt) << "): ";
                string response;
                cin >> response;

                if (response == secondWord) {
                    cout << "Correct!\n";
                    correctGuess = true;
                        points += 15;

                    break;
                } else {
                    cout << "Incorrect!\n";
                }
            }

            if (!correctGuess) {
                cout << "Out of attempts. The correct answer was: " << secondWord << endl;
            }

            cout << "Your current score: " << points << "\n";
        }

        cout << "Game Over!";
        pointsHandler.addPoints(points);
    }
};

class HangmanGame : public Game {
private:
    string words[2] = {"forensic", "weapon"};
    string hints[2] = {
        "Presence of sedative in Tyler's blood. What kind of evidence this is called?",
        "Lethal injection administered with a syringe containing a potent sedative. What tool used to killed is called?"
    };

    string clues[3][2] = {
        {"Disarray in Tyler's room inconsistent with hospital protocol", "Unexplained scratches on Tyler's arm"},
        {"Gaps in security camera recordings during the time of the murder", ""},
        {"Unidentified cloth fibers found on Tyler's bed", "Mysterious substance in Tyler's water bottle"}
    };

    int currentWordIndex;
    string currentWord;
    string maskedWord;
    string guessedLetters;
    int attemptsLeft;

public:
    HangmanGame() {
        srand(static_cast<unsigned int>(time(0)));
        currentWordIndex = rand() % 2;
        currentWord = words[currentWordIndex];
        maskedWord = string(currentWord.length(), '_');
        guessedLetters = "";
        attemptsLeft = 6;
    }

    void displayClues(int wordIndex) {
        cout << "CLUES:" << endl;
        for (int i = 0; i < 2; ++i) {
            if (!clues[wordIndex][i].empty()) {
                cout << "- " << clues[wordIndex][i] << endl;
            }
        }
    }

    // Overloading + operator to add points to the game's PointsHandler
    HangmanGame operator+(const HangmanGame& other) const {
        HangmanGame result = *this; // Copy the current object
        result.pointsHandler.addPoints(other.pointsHandler.getPoints());
        return result;
    }

    void playGame() override {
        cout << "Welcome to Hangman!\n";

        for (int turn = 1; turn <= 2; ++turn) {
            cout << "Turn " << turn << endl;
            cout << "Guess the word letter by letter. You have " << attemptsLeft << " attempts for each letter.\n";
            cout << "Hint: " << hints[currentWordIndex] << endl;
            cout << "The word has " << currentWord.length() << " letters.\n";

            bool gameWon = false;

            for (int i = 0; i < currentWord.length(); ++i) {
                if (guessedLetters.find(tolower(currentWord[i])) != string::npos) {
                    maskedWord[i] = currentWord[i];
                }
            }

            while (attemptsLeft > 0 && maskedWord != currentWord) {
                cout << "Current word: " << maskedWord << endl;
                cout << "Guessed letters: " << guessedLetters << endl;

                char guess;
                cout << "Enter your guess: ";
                cin >> guess;
                cin.ignore(); // Ignore the newline character

                if (guessedLetters.find(tolower(guess)) != string::npos) {
                    cout << "You've already guessed that letter. Try again.\n";
                    continue;
                }

                guessedLetters += tolower(guess);

                if (currentWord.find(tolower(guess)) != string::npos) {
                    cout << "Correct guess!\n";
                    for (int i = 0; i < currentWord.length(); ++i) {
                        if (tolower(currentWord[i]) == tolower(guess)) {
                            maskedWord[i] = currentWord[i];
                        }
                    }
                } else {
                    cout << "Incorrect guess.\n";
                    --attemptsLeft;
                    cout << "Attempts left: " << attemptsLeft << endl;
                }
            }

            if (maskedWord == currentWord) {
                gameWon = true;
            }

            if (gameWon) {
                cout << "Congratulations! You've guessed the word: " << currentWord << endl;
                displayClues(currentWordIndex);
                pointsHandler.addPoints(15);
            } else {
                cout << "You've run out of attempts. The word was: " << currentWord << endl;
            }

            // Reset for next turn
            currentWordIndex = (currentWordIndex + 1) % 2;
            currentWord = words[currentWordIndex];
            maskedWord = string(currentWord.length(), '_');
            guessedLetters = "";
            attemptsLeft = 6;
            cout<<endl<<endl;
        }

        cout << "Hangman Game Points: " << pointsHandler.getPoints() << endl;
    }
};

struct DetectiveProfile 
{
    string name;
    int age;
    string agency;
    void startGame(DetectiveProfile& profile) 
    {
        cout << "Enter your Name: ";
        getline(cin, profile.name);
        cout << "Enter your Age: ";
        cin >> profile.age;
        cin.ignore(); // Clear the input buffer
        cout << "Enter your Agency: ";
        getline(cin, profile.agency);
        cout << "Welcome, Detective " << profile.name << " from " << profile.agency << "!" << endl;
        cout << "You are " << profile.age << " years old." << endl;
        cout << "Let's solve some crimes!" << endl;
    }
};

void endGame() 
{
    cout << "Ending the game......Goodbye!" << endl;
    exit(0);
}

void showHelp() 
{
    cout << "Help:\n"
         << "- You are a detective who has been appointed to solve crimes\n"
         << "- Choose a level mode to solve a crime according to difficulty level\n"
        << "- Investigate the suspects to find the murderer, play games to earn points and find clues for additional points\n"
         << "- Good luck!\n" << endl;
}

int main()
{

    DetectiveProfile detective;
    cout << "\t\t-----------------------------------------------------------------------\n" << endl;
    cout << "\t\t\t\tWELCOME TO CRIME INVESTIGATION GAME!\n" << endl;
    cout << "\t\t-----------------------------------------------------------------------" << endl;
    int ch;
    int mode;
    do 
	{
		cout << "\n1. START\n2. END\n3. HELP\n" << endl;
        cout << "\nEnter your choice:";
        cin >> ch;
        switch (ch) 
		{
        case 1:
            {
                cout << "\nLET'S PLAY THE GAME!\n\n";
                cout << "Would you like to customize your detective profile? (yes/no): ";
                string dd;
                cin.ignore(); // Clear the input buffer
                getline(cin,dd);
                if (dd == "yes")
                    detective.startGame(detective);
                else {
                    detective.name = "Unknown Detective";
                    detective.age = 0;
                    detective.agency = "Unknown Agency"; }
                cout << "\n-------------------GAME MODE---------------\n";
                cout << "1. EASY\n2. MEDIUM\n3. HARD" << endl;
                cout << "--------------------------------------------\n";
                cout << "\nEnter the game mode: ";
                cin >> mode;
                switch (mode) 
				{
                case 1:
                    {    Clue<string>* allClues[5];
    allClues[0] = new Clue<string>("Acrylic Paints",true);
    allClues[1] = new Clue<string>("Torn Canvas Scrap",false);
    allClues[2] = new Clue<string>("Paintings",true);
    allClues[3] = new Clue<string>("Cryptic Note",false);
    allClues[4] = new Clue<string>("Broken Glasses",true );
    Weapon<string>* allWeapons[5];
    allWeapons[0] = new Weapon<string>("Sharp Palette Knife",true);
    allWeapons[1] = new Weapon<string>("Candlestick",true);
    allWeapons[2] = new Weapon<string>("HandGun", false);
    allWeapons[3] = new Weapon<string>("Pipe",false);
    allWeapons[4] = new Weapon<string>("Rope",false);
    PlayerInventory inventory;
    int points;
    int cul_points=0;
    PointsHandler totalPoints;
    WordAssociationGame wordAssociationGame;
                    	ifstream file("easy_scenerio.txt");
                        cout << "\nCase Study 1: The Gallery Tragedy: The Murder of Victor Monet\n";
                        cout << "\nWould like to investigate this case study?\npress Y (yes) to continue:";
                        char case_study_answer;
                        cin >> case_study_answer;
                        if (case_study_answer == 'Y' || case_study_answer == 'y') {
                            cout << "\n\npresenting scenerio.....\n\n";
                            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                            string line;
							while(getline(file,line))
                            {
                            cout << line << endl;
							}
							file.close();
                            cout << "\n\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
                            cout << "\n\nSCENARIO HAS BEEN COMPLETED. LET'S INVESTIGATE THE CASE!"; }
                    cout << "\n\nDo you want to open the victim profile? (Y/N): ";
                    char v;
                    cin>>v;
                    if (v=='Y' || v=='y')
                    {
                    VictimProfile victim1("Victor Monet",45,"Renowned Artist","Self-taught prodigy","Married with two children; close-knit family residing in Paris, France");
                    victim1.displayprofile();
                    }
                    cout << "\nLet's Start Investigating!" << endl;
                    int menu;
                        do {
                          cout << "\n------------------------CASE STUDY MENU------------------------\n";
                    cout << "\n1) INVESTIGATE SUSPECTS";
                    cout << "\n2) PLAY GAMES TO FIND CLUES";
                    cout << "\n3) SEARCH CLUES AND WEAPONS";
                    cout << "\n4) MY INVENTORY";
                    cout << "\n5) ARREST THE CULPRIT";
                    cout << "\n6) EXIT TO FIND THE ENDING";
                    cout << "\n----------------------------------------------------------------\n";
                        cout << "\nChoose a case study menu option: ";
                        cin>>menu;
                        switch(menu) {
                        case 1:{
                            SophiaDuval sophia("easy_suspects_answers.txt");
                            MarcusGreene marcus("easy_suspects_answers.txt");
                            ElenaVasquez elena("easy_suspects_answers.txt");
                            int choice1;
                            Suspect* currentSuspect;
                            cout << "\nSuspects\n";
                            cout << "1. Sophia Duval\n";
                            cout << "2. Marcus Greene\n";
                            cout << "3. Elena Vasquez\n";
                            cout << "Press 0 to stop investigating suspects\n";
                            do {
                            cout << "\nChoose a suspect to investigate (1-3, or 0 to stop): ";
                            cin >> choice1;
                            switch (choice1) {
                            case 1:
                            currentSuspect = &sophia;
                            break;
                            case 2:
                            currentSuspect = &marcus;
                            break;
                            case 3:
                            currentSuspect = &elena;
                            break;
                            case 0:
                            cout << "Exiting investigation.\n";
                            continue;
                            default:
                            cout << "\nInvalid choice";
                            continue; }
                            currentSuspect->display_suspect_profile();
                            currentSuspect->initiate_conversation();
                            currentSuspect->questions_set1();
                            int questionNumber;
                            cout << "Enter the question number you want to ask from set 1: ";
                            cin >> questionNumber;
                            currentSuspect->answers_set1(questionNumber);
                            currentSuspect->questions_set2();
                            cout << "Enter the question number you want to ask from set 2: ";
                            cin >> questionNumber;
                            currentSuspect->answers_set2(questionNumber);
                            currentSuspect->questions_set3();
                            cout << "Enter the question number you want to ask from set 3: ";
                            cin >> questionNumber;
                            currentSuspect->answers_set3(questionNumber);
                            } while (choice1!=0); 
							break; }
							
							case 2:{
								 srand(static_cast<unsigned int>(time(0)));


    cout << "---------------WELCOME TO GAME 01: JUMBLE WORDS PUZZLE-------------" << endl;
    string clue1="Bloodstained Palette Knife : Found near the victim's body, with traces of the victim's blood. It's the murder weapon.";
    string clue2 ="Candlestick : A candlestick found in Victor's studio could have been wielded by Marcus as an alternate murder weapon, left behind with the intention of framing someone else or creating confusion.";
    string clue3="Cryptic Note : Found hidden in Victor's sketchbook. It reads: 'The true masterpiece lies within.'";
    UnscrambleGame unscrambleGame("candlestick", "painting", clue1, clue2, clue3); // Pass words "files" and "gunshot" along with their clues to the constructor
    unscrambleGame.playGame();
    totalPoints.addPoints(unscrambleGame.getPointsHandler().getPoints()); 
    cout<<endl<<endl;
    cout << "---------------WELCOME TO THE GAME 02 : WORD ASSOCIATION GAME-------------" << endl;

    wordAssociationGame.playGame();
    cout<<"\n\n----------------------------------------------------------------------------"<<endl;
    int finalgamespoints =unscrambleGame.getPointsHandler().getPoints() + wordAssociationGame.getPointsHandler().getPoints();
    cout << "Your final score: " << finalgamespoints << "/" << 50 << "\n";
								break;
							}
							
							case 3:{
								cout << "\n------------------------Available Clues and Weapons at the Scene---------------\n\n";
                for (int i=0;i<5;i++) 
				{
                    cout << i+1 << ". " << allClues[i]->getdescription() << " (Clue)" << endl;
                }
                for (int i=0;i<5;i++) 
				{
                    cout << i+6 << ". " << allWeapons[i]->getname() << " (Weapon)" << endl;
                }
                cout << "\nSCENERIO: In Victor's art studio, after a fight, some clues and weapons hinted at what happened....\n ";
                cout << "\nONE: was the tubes of bright colors splashed by the foot of culprit....";
                cout << "\nTWO: was the sharp flat blade used to spread and mix colors....";
                cout << "\nTHREE: was the artistic creations of Victor which are displayed in his gallery....";
                cout << "\nFOUR: was the wax stick standing with its dim light....";
                cout << "\nFIVE: was the pieces of glasses scattered by culprit when he tried to kill Victor....";
								break;
							}
							case 4:{
						      inventory.additems(allClues, allWeapons);
                             cout << "\n-------------------------------Player's Inventory-------------------------------\n";
                            inventory.printinventory();
                             points = inventory.calculatepoints();
                             cout << "\nPoints Earned: " << points << endl;
								break;
							}
							
							case 5: {
								cout << "\n-------------------GUESS THE CULPRIT!!---------------------\n";
								cout << "\nSuspects\n";
                                cout << "1. Sophia Duval\n";
                                cout << "2. Marcus Greene\n";
                                cout << "3. Elena Vasquez\n";
                                int cul;
                                cout << "\nEnter the suspect (number from 1-3) which you think is the culprit: ";
                                cin>>cul;
                                if (cul==2)
                                {
                                	cul_points+=30;
                                	cout << "\nCULPRIT GUESSED: MARCUS GREENE\n";
                                	cout << "\nCongrats! you have successfully arrested the right suspect!";
                                	cout << "\nMarcus Greene murdered Victor!";
								}
								else if (cul==1)
								{
									cout << "\nCULPRIT GUESSED: SOPHIA DUVAL\n";
									cout << "\nSophia is innocent! you have arrested the wrong suspect!";
								}
								else if (cul==3)
								{
									cout << "\nCULPRIT GUESSED: ELENA VASQUEZ\n";
									cout << "\nElena is innocent! you have arrested the wrong suspect!";
								}
								else
								{
									cout << "\nInvalid Option";
								}
								cout << "\n\nPoints Earned: " << cul_points;
								break; }
								
								case 6: {
									cout << "\n--------------------------------------------------------------------------------\n";
									cout << "\n-----------------------SHOWING THE ENDING----------------------------------------\n";
									int totalpoints;
									totalpoints+=(points+cul_points+totalPoints.getPoints()+wordAssociationGame.getPointsHandler().getPoints());
									if (totalpoints>=50)
									{
										cout << "\n------------GOOD ENDING----------\n";
										cout << "\nYOU HAVE SUCCESFULLY SOLVE THE CASE!\n";
									}
									else
									{
									    cout << "\n------------BAD ENDING----------\n";
										cout << "\nYOU HAVE FAILED TO SOLVE THE CASE!\n";
									}
									cout << "\nTOTAL POINTS EARNED: " << totalpoints << endl;
									break;}
					    }} while (menu!=6);
                    continue; }
                    
//medium level game
                case 2:
                	{
                		 Clue<string>* allClues[5];
    allClues[0] = new Clue<string>("Broken Mirror",true);
    allClues[1] = new Clue<string>("Suicide Note",true);
    allClues[2] = new Clue<string>("Blooded Shirt",false);
    allClues[3] = new Clue<string>("gun residue",false);
    allClues[4] = new Clue<string>("Lost files",true );
    Weapon<string>* allWeapons[5];
    allWeapons[0] = new Weapon<string>("Kitchen Knife",false);
    allWeapons[1] = new Weapon<string>("Mirror Pieces",true);
    allWeapons[2] = new Weapon<string>("Revolver", false);
    allWeapons[3] = new Weapon<string>("Vase",false);
    allWeapons[4] = new Weapon<string>("bullet",true);
    PlayerInventory inventory;
    int points;
    int cul_points;
    CrosswordGame crosswordGame;
    UnscrambleGame unscrambleGame("files", "gunshot"); // Pass words "files" and "gunshot" along with their clues to the constructor
    
                	ifstream file("medium_scenerio.txt");
                        cout << "\nCase Study 2: The Cold Case Reopened\n";
                        cout << "\nWould like to investigate this case study?\npress Y (yes) to continue:";
                        char case_study_answer;
                        cin >> case_study_answer;
                        if (case_study_answer == 'Y' || case_study_answer == 'y') {
                            cout << "\n\npresenting scenerio.....\n\n";
                            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                            string line;
							while(getline(file,line))
                            {
                            cout << line << endl;
							}
							file.close();
                            cout << "\n\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
                            cout << "\n\nSCENARIO HAS BEEN COMPLETED. LET'S INVESTIGATE THE CASE!"; }
                    cout << "\n\nDo you want to open the victim profile? (Y/N): ";
                    char v;
                    cin>>v;
                    if (v=='Y' || v=='y')
                    {
                    VictimProfile victim2("Mark Thompson",47,"Detective Inspector","Bachelor's degree in Criminal Justice from University of London","Married for 15 years with no children");
                    victim2.displayprofile();
                    }
                     int menu;
                    cout << "\nLet's Start Investigating!" << endl;
                        do {
                    cout << "\n------------------------CASE STUDY MENU------------------------\n";
                    cout << "\n1) INVESTIGATE SUSPECTS";
                    cout << "\n2) PLAY GAMES TO FIND CLUES";
                    cout << "\n3) SEARCH CLUES AND WEAPONS";
                    cout << "\n4) MY INVENTORY";
                    cout << "\n5) ARREST THE CULPRIT";
                    cout << "\n6) EXIT TO FIND THE ENDING";
                    cout << "\n----------------------------------------------------------------\n";
                        cout << "\nChoose a case study menu option: ";
                        cin>>menu;
                        switch(menu) {
                        case 1:{
                            DavidMiller david("medium_suspects_answers.txt");
                            SarahThompson sarah("medium_suspects_answers.txt");
                            FrankLawson frank("medium_suspects_answers.txt");
                            int choice2;
                            Suspect* currentSuspect;
                             cout << "\nSuspects\n";
                             cout << "1. David Miller\n";
                             cout << "2. Sarah Thompson\n";
                             cout << "3. Frank Lawson\n";
                            cout << "Press 0 to stop investigating suspects\n";
                            do {
                            cout << "\nChoose a suspect to investigate (1-3, or 0 to stop): ";
                            cin >> choice2;
                            switch (choice2) {
                            case 1:
                            currentSuspect = &david;
                            break;
                            case 2:
                            currentSuspect = &sarah;
                            break;
                            case 3:
                            currentSuspect = &frank;
                            break;
                            case 0:
                            cout << "Exiting investigation.\n";
                            continue;
                            default:
                            cout << "Invalid choice.\n";
                            continue; }
                            currentSuspect->display_suspect_profile();
                            currentSuspect->initiate_conversation();
                            currentSuspect->questions_set1();
                            int questionNumber;
                            cout << "Enter the question number you want to ask from set 1: ";
                            cin >> questionNumber;
                            currentSuspect->answers_set1(questionNumber);
                            currentSuspect->questions_set2();
                            cout << "Enter the question number you want to ask from set 2: ";
                            cin >> questionNumber;
                            currentSuspect->answers_set2(questionNumber);
                            currentSuspect->questions_set3();
                            cout << "Enter the question number you want to ask from set 3: ";
                            cin >> questionNumber;
                            currentSuspect->answers_set3(questionNumber);
                            } while (choice2!=0); 
							break; }
							
							case 2:{
								srand(static_cast<unsigned int>(time(0)));
                               PointsHandler totalPoints;
                                cout << "---------------WELCOME TO GAME 01: CROSSWORD GAME-------------" << endl;
                                crosswordGame.playGame();
                                totalPoints.addPoints(crosswordGame.getPointsHandler().getPoints()); // Accumulate points from the crossword game
                                cout<<endl<<endl;
								
                                cout << "---------------WELCOME TO GAME 02: UNSCRAMBLE WORDS GAME-------------" << endl;
   
                                unscrambleGame.playGame();
                                totalPoints.addPoints(unscrambleGame.getPointsHandler().getPoints()); // Accumulate points from the unscramble game
                                cout << "Total Points: " << totalPoints.getPoints() << endl;
                           
							break;}
							case 3:{
							cout << "\n------------------------Available Clues and Weapons at the Scene---------------\n\n";
                for (int i=0;i<5;i++) 
				{
                    cout << i+1 << ". " << allClues[i]->getdescription() << " (Clue)" << endl;
                }
                for (int i=0;i<5;i++) 
				{
                    cout << i+6 << ". " << allWeapons[i]->getname() << " (Weapon)" << endl;
                }
                cout << "\nSCENERIO: In Mark Thompson's apartmenet some clues have been found!!'\n ";
                cout << "\nONE:Through twists and turns, the bullet flew, but not as expected, not as true. Its trajectory tells a tale, diverging from a story frail....'";
                cout << "\nTWO: A note left behind, a message bleak, but its origins, truth seeks. Handwriting analyzed, linguistic patterns reviewed, revealing doubts, in lines construed";
                cout << "\nTHREE: A mystery brews, where files once present, now refuse. Deleted or encrypted, the story unfolds, revealing schemes, in digital codes....";
                cout << "\nFOUR:The shiny pieces spread around, hints towards a mystery that we must seek....";
                cout << "\nFIVE: Found amidst the chaos, a weapon lies, but its role in the tale, a guise.....";
								break;
							}
							case 4:{
								try{
				
                inventory.additems(allClues, allWeapons);
                cout << "\n-------------------------------Player's Inventory-------------------------------\n";
                inventory.printinventory();
                points = inventory.calculatepoints();
                cout << "\nPoints Earned: " << points << endl;}
                 catch (const exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
								break;
							}
						case 5: {
								cout << "\n-------------------GUESS THE CULPRIT!!---------------------\n";
								cout << "\nSuspects\n";
                                cout << "1. David Miller\n";
                                cout << "2. Sarah Thompson\n";
                                cout << "3. Frank Lawson\n";
                                int cul;
                                cout << "\nEnter the suspect (number from 1-3) which you think is the culprit: ";
                                cin>>cul;
                                if (cul==2)
                                {
                                	cul_points+=30;
                                	cout << "\nCULPRIT GUESSED: SARAH THOMPSON\n";
                                	cout << "\nCongrats! you have successfully arrested the right suspect!";
                                	cout << "\nSarah Thompson murdered Mark Thompson...his own husband!";
								}
								else if (cul==1)
								{
									cout << "\nCULPRIT GUESSED: DAVID MILLER\n";
									cout << "\nDavid is innocent! you have arrested the wrong suspect!";
								}
								else if (cul==3)
								{
									cout << "\nCULPRIT GUESSED: FRANK LAWSON\n";
									cout << "\nFrank is innocent! you have arrested the wrong suspect!";
								}
								else
								{
									cout << "\nInvalid Option";
								}
								cout << "\n\nPoints Earned: " << cul_points;
								break; }
								case 6: {
									cout << "\n--------------------------------------------------------------------------------\n";
									cout << "\n-----------------------SHOWING THE ENDING----------------------------------------\n";
									int totalpoints;
									totalpoints+=(points+cul_points+crosswordGame.getPointsHandler().getPoints()+unscrambleGame.getPointsHandler().getPoints());
									if (totalpoints>=60)
									{
										cout << "\n------------GOOD ENDING----------\n";
										cout << "\nYOU HAVE SUCCESFULLY SOLVE THE CASE!\n";
									}
									else
									{
									    cout << "\n------------BAD ENDING----------\n";
										cout << "\nYOU HAVE FAILED TO SOLVE THE CASE!\n";
									}
									cout << "\nTOTAL POINTS EARNED: " << totalpoints << endl;
									break;}
					    }} while (menu!=6);
                	continue; }
                    
                case 3:
                {
                	 Clue<string>* allClues[5];
           allClues[0] = new Clue<string>("Scratches on arm",false);
           allClues[1] = new Clue<string>("CCTV Camera footage",true);
          allClues[2] = new Clue<string>("Unknown cloth",false);
          allClues[3] = new Clue<string>("Faulty machines",true);
          allClues[4] = new Clue<string>("Lost Medical Records",true );
         Weapon<string>* allWeapons[5];
         allWeapons[0] = new Weapon<string>("Scalapel",false);
         allWeapons[1] = new Weapon<string>("Sedatives",true);
         allWeapons[2] = new Weapon<string>("rope", false);
        allWeapons[3] = new Weapon<string>("Poisned needle",false);
        allWeapons[4] = new Weapon<string>("Syringe",true);
        PlayerInventory inventory;
         int points; 
         int cul_points=0;
         HangmanGame hangmanGame;
         UnscrambleGame unscrambleGame("Surveillance", "Evidence"); 
                    	ifstream file("hard_scenerio.txt");
                        cout << "\nCase Study 3: The Hospital Tragedy\n";
                        cout << "\nWould like to investigate this case study?\npress Y (yes) to continue:";
                        char case_study_answer;
                        cin >> case_study_answer;
                        if (case_study_answer == 'Y' || case_study_answer == 'y') {
                            cout << "\n\npresenting scenerio.....\n\n";
                            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                            string line;
							while(getline(file,line))
                            {
                            cout << line << endl;
							}
							file.close();
                            cout << "\n\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
                            cout << "\n\nSCENARIO HAS BEEN COMPLETED. LET'S INVESTIGATE THE CASE!"; }
                    cout << "\n\nDo you want to open the victim profile? (Y/N): ";
                    char v;
                    cin>>v;
                    if (v=='Y' || v=='y') {
                    VictimProfile victim3("Tyler Benett",16,"High School Student","Secondary Education (Homeschooled)","Comes from a close knit family,has an older sister");
                    victim3.displayprofile(); }
                     cout << "\nLet's Start Investigating!" << endl;
                    int menu;
                        do {
                         cout << "\n------------------------CASE STUDY MENU------------------------\n";
                    cout << "\n1) INVESTIGATE SUSPECTS";
                    cout << "\n2) PLAY GAMES TO FIND CLUES";
                    cout << "\n3) SEARCH CLUES AND WEAPONS";
                    cout << "\n4) MY INVENTORY";
                    cout << "\n5) ARREST THE CULPRIT";
                    cout << "\n6) EXIT TO FIND THE ENDING";
                    cout << "\n----------------------------------------------------------------\n";
                        cout << "\nChoose a case study menu option: ";
                        cin>>menu;
                        switch(menu) {
                        case 1:{
                            EmilyHartley emily("hard_suspects_answers.txt");
                            MeganBenett megan("hard_suspects_answers.txt");
                            JakeEvans jake("hard_suspects_answers.txt");
                            int choice3;
                            Suspect* currentSuspect;
                            cout << "\nSuspects\n";
                            cout << "1. Dr. Emily Hartley\n";
                            cout << "2. Megan Benett\n";
                            cout << "3. Nurse Jake Evans\n";
                            cout << "Press 0 to stop investigating suspects\n";
                            do {
                            cout << "\nChoose a suspect to investigate (1-3, or 0 to stop): ";
                            cin >> choice3;
                            switch (choice3) {
                            case 1:
                            currentSuspect = &emily;
                            break;
                            case 2:
                            currentSuspect = &megan;
                            break;
                            case 3:
                            currentSuspect = &jake;
                            break;
                            case 0:
                            cout << "Exiting investigation.\n";
                            continue;
                            default:
                            cout << "Invalid choice.\n";
                            continue; }
                            currentSuspect->display_suspect_profile();
                            currentSuspect->initiate_conversation();
                            currentSuspect->questions_set1();
                            int questionNumber;
                            cout << "Enter the question number you want to ask from set 1: ";
                            cin >> questionNumber;
                            currentSuspect->answers_set1(questionNumber);
                            currentSuspect->questions_set2();
                            cout << "Enter the question number you want to ask from set 2: ";
                            cin >> questionNumber;
                            currentSuspect->answers_set2(questionNumber);
                            currentSuspect->questions_set3();
                            cout << "Enter the question number you want to ask from set 3: ";
                            cin >> questionNumber;
                            currentSuspect->answers_set3(questionNumber);
                            } while (choice3!=0); 
							break; }
							case 2:{
							PointsHandler totalPoints;
    cout << "---------------WELCOME TO GAME 01: HANGMAN GAME-------------" << endl;
    cout<<endl<<"IMPORTANT NOTE : Enter the word letter by letter(starting from the first letter)"<<endl;
    hangmanGame.playGame();
    cout << "---------------------------------------------------" << endl;
    
    cout << "---------------WELCOME TO GAME 02: UNSCRAMBLE WORDS GAME-------------" << endl;
   
    unscrambleGame.playGame();
    totalPoints.addPoints(hangmanGame.getPointsHandler().getPoints() + unscrambleGame.getPointsHandler().getPoints());
    cout << "Total Game Points: " << totalPoints.getPoints() << endl;	
								break;
							}
							case 3:{
								 cout << "\n------------------------Available Clues and Weapons at the Scene---------------\n\n";
                for (int i=0;i<5;i++) 
				{
                    cout << i+1 << ". " << allClues[i]->getdescription() << " (Clue)" << endl;
                }
                for (int i=0;i<5;i++) 
				{
                    cout << i+6 << ". " << allWeapons[i]->getname() << " (Weapon)" << endl;
                }
                cout << "\nSCENERIO: In the hospital traces of Tyler's murder is found:\n";
                cout << "\nONE:What absence lingers, what cryptic chase, in Tyler's past, a vanished trace?";
                cout << "\nTWO: What mechanism falters, what enigmatic scheme, in Tyler's room, a silent stream?";
                cout << "\nTHREE:In the time's gaps, where secrets creep, what hidden force keeps it gaze? ....";
                cout << "\nFOUR:In Tyler's veins,what murky fluid, in shadows to dwell,cast its spell, his story to tell?....";
                cout << "\nFIVE: What tool of destiny, what venom's cling, sealed Tyler's fate on silent wing?.....";
								break;
							}
							case 4:{
										try{
				
                inventory.additems(allClues, allWeapons);
                cout << "\n-------------------------------Player's Inventory-------------------------------\n";
                inventory.printinventory();
                points = inventory.calculatepoints();
                cout << "\nPoints Earned: " << points << endl;}
                 catch (const exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
								break;
							}
							
								case 5: {
								cout << "\n-------------------GUESS THE CULPRIT!!---------------------\n";
							    cout << "\nSuspects\n";
                                cout << "1. Dr. Emily Hartley\n";
                                cout << "2. Megan Benett\n";
                                cout << "3. Nurse Jake Evans\n";
                                int cul;
                                cout << "\nEnter the suspect (number from 1-3) which you think is the culprit: ";
                                cin>>cul;
                                if (cul==3)
                                {
                                	cul_points+=30;
                                	cout << "\nCULPRIT GUESSED: NURSE JAKE EVANS\n";
                                	cout << "\nCongrats! you have successfully arrested the right suspect!";
                                	cout << "\nNurse Jake Evans murdered Tyler Benett...due to resentment from his father death who died due to stress from clash with Tyler's family.";
								}
								else if (cul==1)
								{
									cout << "\nCULPRIT GUESSED: DR. EMILY HARTLEY\n";
									cout << "\Emily is innocent! you have arrested the wrong suspect!";
								}
								else if (cul==2)
								{
									cout << "\nCULPRIT GUESSED: MEGAN BENETT\n";
									cout << "\nMegan is innocent! you have arrested the wrong suspect!";
								}
								else
								{
									cout << "\nInvalid Option";
								}
								cout << "\n\nPoints Earned: " << cul_points;
								break; }
								
								case 6: {
									cout << "\n--------------------------------------------------------------------------------\n";
									cout << "\n-----------------------SHOWING THE ENDING----------------------------------------\n";
									int totalpoints;
									totalpoints+=(points+cul_points+hangmanGame.getPointsHandler().getPoints()+unscrambleGame.getPointsHandler().getPoints());
									if (totalpoints>=70)
									{
										cout << "\n------------GOOD ENDING----------\n";
										cout << "\nYOU HAVE SUCCESFULLY SOLVE THE CASE!\n";
									}
									else
									{
									    cout << "\n------------BAD ENDING----------\n";
										cout << "\nYOU HAVE FAILED TO SOLVE THE CASE!\n";
									}
									cout << "\nTOTAL POINTS EARNED: " << totalpoints << endl;
									break;}
					    }} while (menu!=6);
                    continue; }
                }
        }      
        case 2:
        {
            endGame();
            break;
        }
        case 3:
        {
            showHelp();
            break;
        }
        default:
        {
            cout << "Invalid choice. Please enter a valid option (1, 2, or 3)." << endl;
            continue;
        }
        }
		}while (ch!=2);
    return 0;
}

