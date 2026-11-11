#include <iostream>
#include <ctime>   // 3shan time(0)
#include <cstdlib> // 3shan rand() w srand()
#include <string>
using namespace std;

// 3shan a3rf el data ll song
struct Node
{
    string songName;
    Node *next;
};

class playlist
{
private:
    Node *head; // el pointer elly mask el playlist

public:
    playlist()
    {
        head = nullptr; // 3shan admn enha msh btshawr 3la mkan 3sha2y
    }

    void AddSong(string name)
    {
        Node *temp = head; // pointer e check
        while (temp != nullptr)
        { // lw el temp msh fadt
            // check le el song mwgoda
            if (temp->songName == name)
            {
                cout << "Song already exist\n";
                return;
            }
            // update el temp
            temp = temp->next;
        }

        // lw msh mawgoda
        Node *newnode = new Node; // h3ml pointer gded y7gz mkan el song
        newnode->songName = name;
        newnode->next = nullptr; // el node ell b3dha tb2a fadya

        // lw el playlist fadya aslan
        if (head == nullptr)
        {
            head = newnode;
            cout << "Song is Added\n";
        }
        // le mlyan
        else
        {
            Node *temp = head; // erg3 ll2wl

            while (temp->next != nullptr)
            {                      // lw ell b3dha msh fadya
                temp = temp->next; // update el temp
            }

            temp->next = newnode;
            cout << "Song is Added\n";
        }
    }
    // remove song
    void removesong(string name)
    {
        // le el playlist fadya
        if (head == nullptr)
        {
            cout << "Playlist is empty\n";
            return;
        }

        // lw el song 2wl wa7da
        if (head->songName == name)
        {
            // h3ml pointer gded ymsk el 2dem
            Node *temp = head;
            head = head->next; // bn7rk el head ll node ell b3dha
            delete temp;
            cout << "Song is removed\n";
            return;
        }

        // lw f el a5r aw el ns
        Node *crr = head->next; // pointer eshawer 3l song ell h remove it
        Node *prev = head;      // el song ell 2blha
        // lw el crr msh fady
        while (crr != nullptr)
        {
            // lw l2et el song
            if (crr->songName == name)
            {
                prev->next = crr->next; // 3shan afslha
                delete crr;
                cout << "Song is removed\n";
                return;
            }
            // lw ml2thash
            else
            {
                // h7rk ell ptr l 2odam
                prev = crr;
                crr = crr->next;
            }
        }
        // le el loop 5lst w ml2tsh el song
        if (crr == nullptr)
        {
            cout << "Song not found\n";
        }
    }

    // show play list
    void Showplaylist()
    {
        // lw fadya
        if (head == nullptr)
        {
            cout << "Playlist is empty\n";
            return;
        }
        // lw mlyana
        // pionter ll7rka
        Node *temp = head;
        int count = 1;
        // lw el temp msh fadya
        while (temp != nullptr)
        {
            cout << count << ". " << temp->songName << endl;
            count++;
            temp = temp->next;
        }
    }

    // Repeat song
    void Playrepeat(string Name, int time)
    {
        // check lw fadya
        if (head == nullptr)
        {
            cout << "Playlist is empty\n";
            return;
        }
        // lw mlyan
        Node *temp = head;
        while (temp != nullptr)
        {
            // check lw mawgwda
            if (temp->songName == Name)
            {
                for (int i = 1; i <= time; i++)
                {
                    cout << Name << endl;
                    cout << "Repeat:" << time << endl;
                }
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
        // lw el loop 5lst w msh mawgoda
        cout << "Song not found\n";
    }

    // Shuffle play
    void Shuffle()
    {
        // check lw fady
        if (head == nullptr)
        {
            cout << "Play list is empty\n";
            return;
        }
        // lw magod
        int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        // a5tar rqm 3shwa2y
        int randomIndex = rand() % count;
        temp = head;
        for (int i = 0; i < randomIndex; i++)
        {
            temp = temp->next;
        }
        cout << "Playing (Shuffle): " << temp->songName << endl;
    }
};

int main()
{
    srand(time(0)); // 3shan n-reset el random seed m3 kl tshghel

    playlist myPlaylist; // object mn class
    int choice;
    string songName;
    int times;

    do
    {
        cout << "\n--- Playlist Menu ---\n";
        cout << "1. Add Song\n";
        cout << "2. Remove Song\n";
        cout << "3. Show Playlist\n";
        cout << "4. Play Repeat\n";
        cout << "5. Shuffle Play\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // 3shan nms7 el newline character b3d cin >> choice

        switch (choice)
        {
        case 1:
            cout << "Enter song name to add: ";
            getline(cin, songName);
            myPlaylist.AddSong(songName);
            break;
        case 2:
            cout << "Enter song name to remove: ";
            getline(cin, songName);
            myPlaylist.removesong(songName);
            break;
        case 3:
            myPlaylist.Showplaylist();
            break;
        case 4:
            cout << "Enter song name: ";
            getline(cin, songName);
            cout << "Enter number of repeats: ";
            cin >> times;
            myPlaylist.Playrepeat(songName, times);
            break;
        case 5:
            myPlaylist.Shuffle();
            break;
        case 6:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}