#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
	//EASY LEVEL ALL 3 SUSPECTS INVESTIGATION ANSWERS
    ofstream f1("easy_suspects_answers.txt");
    if (!f1.is_open()) 
	{
        cout << "Error opening the file" << endl;
        return 1; 
    }
    f1 << "EASY MODE: SUSPECT 1- SOPHIA DUVAL INVESTIGATION ANSWERS\n\n";
    f1 << "Set 1:\n";
    f1 << "1. I was in my office, sorting out some paperwork. I had nothing to do with Victor's death.\n";
    f1 << "2. We had a heated argument about business matters. He accused me of trying to cheat him, but I had nothing to gain from his death.\n\n";
    f1 << "Set 2:\n";
    f1 << "3. Victor and I had a professional relationship, but it soured recently due to disagreements over commission rates.\n";
    f1 << "4. Yes, we had disagreements in the past, but nothing that would lead to murder.\n\n";
    f1 << "Set 3:\n";
    f1 << "5. No, I was too preoccupied with the gala. I didn't notice anything out of the ordinary.\n";
    f1 << "6. No, my business has been doing well. I have no reason to resort to such extreme measures.\n";
    cout << "EASY MODE: SUSPECT 1: Sophia Duval's answers have been written successfully." << endl;
    
    f1 << "\nEASY MODE: SUSPECT 2- MARCUS GREENE INVESTIGATION ANSWERS\n\n";
    f1 << "Set 1:\n";
    f1 << "1. I was at the gallery, admiring Victor's work. I didn't see anything unusual.\n";
    f1 << "2. I saw him arguing with Sophia Duval. It seemed intense. As for me, I was just observing, trying to find inspiration for my own art.\n\n";
    f1 << "Set 2:\n";
    f1 << "3. Victor was a talented artist, but he never acknowledged my potential. I felt overshadowed and ignored.\n";
    f1 << "4. Yes, plenty. He never appreciated my work, always dismissing it as amateurish.\n\n";
    f1 << "Set 3:\n";
    f1 << "5. I saw Elena Vasquez leaving the gala early. She seemed upset, maybe disappointed about something.\n";
    f1 << "6. Envious? Maybe. But who wouldn't be? He had everything, while I struggled to make ends meet.\n";
    cout << "EASY MODE: SUSPECT 2: Marcus Greene's answers have been written successfully." << endl;
    
    f1 << "\nEASY MODE: SUSPECT 3- ELENA VASQUEZ INVESTIGATION ANSWERS\n\n";
    f1 << "Set 1:\n";
    f1 << "1. I left the gala early. I wasn't feeling well and decided to go home.\n";
    f1 << "2. I approached him to compliment his latest painting, but he seemed distracted. We didn't have a proper conversation.\n\n";
    f1 << "Set 2:\n";
    f1 << "3. I admired his work, but I never had a personal relationship with him.\n";
    f1 << "4. No, none at all. I was simply a fan of his art.\n\n";
    f1 << "Set 3:\n";
    f1 << "5. I didn't notice anything unusual. I was too focused on the artwork at the gala.\n";
    f1 << "6. Well, his latest piece was truly remarkable. I admit I was disappointed when I couldn't add it to my collection.\n";
    f1.close();
    cout << "EASY MODE: SUSPECT 3: Elena Vasquez's answers have been written successfully." << endl;
    
    //MEDIUM LEVEL ALL 3 SUSPECTS INVESTIGATION ANSWERS
    ofstream f2("medium_suspects_answers.txt");
    if (!f2.is_open()) 
	{
        cout << "Error opening the file" << endl;
        return 1; 
    }
    f2 << "MEDIUM MODE: SUSPECT 1- DAVID MILLER INVESTIGATION ANSWERS\n\n";
    f2 << "Set 1:\n";
    f2 << "1. I was at my apartment, alone. I've been trying to keep my head down since getting out on parole. I swear, I had nothing to do with Thompson's death.\n";
    f2 << "2. We had a few run-ins. He kept digging into the old case, trying to prove I was involved. But I had nothing to hide.\n\n";
    f2 << "Set 2:\n";
    f2 << "3. He was convinced I was guilty of that cold case, but he was wrong. I served my time for a crime I didn't commit.\n";
    f2 << "4. Yeah, plenty. He ruined my life with his false accusations.So I'm trying to move on and start fresh.\n\n";
    f2 << "Set 3:\n";
    f2 << "5. No, as I said i was alone at home. I didn't see anything out of the ordinary.\n";
    f2 << "6. No, I've been staying clean. I just want to live a normal life now.\n";
    cout << "MEDIUM MODE: SUSPECT 1: David Miller's answers have been written successfully." << endl;
    
    f2 << "\nMEDIUM MODE: SUSPECT 2- SARAH THOMPSON INVESTIGATION ANSWERS\n\n";
    f2 << "Set 1:\n";
    f2 << "1. I was at home, alone. Mark was working late again, but I couldn't sleep knowing he was risking his life every night.\n";
    f2 << "2. We had a heated argument just the other day. He accused me of hiding something about the cold case, but I swear I didn't know anything.\n\n";
    f2 << "Set 2:\n";
    f2 << "3. It was strained, to say the least. His obsession with that cold case consumed him, and it drove a wedge between us.\n";
    f2 << "4. Yes, we fought often. He didn't trust me, especially after what happened with that case years ago.\n\n";
    f2 << "Set 3:\n";
    f2 << "5. No, I didn't see anything out of the ordinary. But maybe I wasn't paying enough attention.\n";
    f2 << "6. Yes, our marriage has been on shaky ground for a while now. Mark's constant suspicion and accusations didn't help. But killing him? That's absurd. I loved him, despite everything.\n";
    cout << "MEDIUM MODE: SUSPECT 2: Sarah Thompson's answers have been written successfully." << endl;
    
    f2 << "\nMEDIUM MODE: SUSPECT 3- FRANK LAWSON INVESTIGATION ANSWERS\n\n";
    f2 << "Set 1:\n";
    f2 << "1. I was at home, minding my own business. Retirement isn't as exciting as it sounds.\n";
    f2 << "2. He came to me asking about the old case. I didn't appreciate him digging up the past.\n\n";
    f2 << "Set 2:\n";
    f2 << "3. We had our differences like in terms of investigation, but nothing that would lead to murder.\n";
    f2 << "4. Not really, we never have disargue or fought.\n\n";
    f2 << "Set 3:\n";
    f2 << "5. No, I usually stay home these days to notice anything.\n";
    f2 << "6. No, why would I? I'm retired, I just want to enjoy my peace and quiet.\n";
    f2.close();
    cout << "MEDIUM MODE: SUSPECT 3: Frank Lawson's answers have been written successfully." << endl;
    
    //HARD LEVEL ALL 3 SUSPECTS INVESTIGATION ANSWERS
    ofstream f3("hard_suspects_answers.txt");
    if (!f3.is_open()) 
	{
        cout << "Error opening the file" << endl;
        return 1; 
    }
    f3 << "HARD MODE: SUSPECT 1- DR. EMILY HARTLEY INVESTIGATION ANSWERS\n\n";
    f3 << "Set 1:\n";
    f3 << "1. I was in the hospital's ICU, attending to another patient who required immediate attention.\n";
    f3 << "2. I visited Tyler's room to check on his condition and ensure that his treatment regimen was being followed. Eventhough he was being monitored by Nurse James, he seem a little unstable but nothing to be quite concerning.\n\n";
    f3 << "Set 2:\n";
    f3 << "3. As Tyler's primary physician, I was responsible for overseeing his treatment and care. I've always acted in his best interests.\n";
    f3 << "4. No, I've always maintained a professional relationship with Tyler and his family. Our interactions have been cordial and focused on his medical care.\n\n";
    f3 << "Set 3:\n";
    f3 << "5. No, everything appeared to be normal during my visit. There were no signs of distress or unusual activity.\n";
    f3 << "6. Absolutely not. I adhere strictly to medical protocols and would never jeopardize a patient's health by administering unauthorized medication.\n";
    cout << "HARD MODE: SUSPECT 1: Dr. Emily Hartley's answers have been written successfully." << endl;
    
    f3 << "\nHARD MODE: SUSPECT 2- MEGAN BENETT INVESTIGATION ANSWERS\n\n";
    f3 << "Set 1:\n";
    f3 << "1. I was in the hospital cafeteria, grabbing a quick snack. I didn't even know anything had happened until I was informed later.\n";
    f3 << "2. I spent some time with Tyler in his room before heading to the cafeteria. We chatted about our plans for the future and watched a movie together.\n\n";
    f3 << "Set 2:\n";
    f3 << "3. Tyler was my brother, my best friend. We shared everything and looked out for each other.\n";
    f3 << "4. No, Tyler was loved by everyone who knew him. We didn't have any enemies, and there were no conflicts that I'm aware of.\n\n";
    f3 << "Set 3:\n";
    f3 << "5. No, everything seemed normal when I was with Tyler. He was in good spirits, a little down, maybe it because of the medication Nurse James gave him.\n";
    f3 << "6. Not really. We've always trusted the doctors and nurses here. They've been doing everything they can to help Tyler.\n";
    cout << "HARD MODE: SUSPECT 2: Megan Benett's answers have been written successfully." << endl;
    
    f3 << "\nHARD MODE: SUSPECT 3- NURSE JAKE EVANS INVESTIGATION ANSWERS\n\n";
    f3 << "Set 1:\n";
    f3 << "1. I was on duty, making my rounds and attending to patients as usual.\n";
    f3 << "2. I checked in on Tyler regularly, ensuring he was comfortable and had everything he needed. That day i gave him medication so he can be stable and can rest peacefully.\n\n";
    f3 << "Set 2:\n";
    f3 << "3. Tyler was one of my patients. I've been involved in his care since he was admitted to the hospital as well as due to personal realtionship with his family.\n";
    f3 << "4. No, I've always tried to provide the best care possible to all my patients, including Tyler. But with his family we had our personal clashes since my father death.\n\n";
    f3 << "Set 3:\n";
    f3 << "5. I didn't see anything out of the ordinary during my rounds. Tyler's room was quiet, just like the rest of the ward.\n";
    f3 << "6. As a nurse, I follow the hospital's protocols and guidelines.I had disagreements which were typically resolved through open communication.\n";
    f3.close();
    cout << "HARD MODE: SUSPECT 3: Nurse Jake Evan's answers have been written successfully." << endl;
    return 0;
}
