#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
   /* Type your code here */
   cout<<playlistTitle<<" PLAYLIST MENU"<<endl;
   cout<<"a - Add song"<<endl;
   cout<<"d - Remove song"<<endl;
   cout<<"c - Change position of song"<<endl;
   cout<<"s - Output songs by specific artist"<<endl;
   cout<<"t - Output total time of playlist (in seconds)"<<endl;
   cout<<"o - Output full playlist"<<endl;
   cout<<"q - Quit"<<endl;
   
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   /* Type your code here */
   switch(option){
      case 'a':
         string id, name, artist;
         int length;
         cout<<"ADD SONG"<<endl;
         cout<<"Enter song's unique ID:"<<endl;
         cin.ignore(); // Clear the newline character from the input buffer
         getline(cin, id);
         cout<<"Enter song's name:"<<endl;
         getline(cin, name);
         cout<<"Enter artist's name:"<<endl;
         getline(cin, artist);
         cout<<"Enter song's length (in seconds):"<<endl;
         cin>>length;
         PlaylistNode* temp = new PlaylistNode(id, name, artist, length);
         if (!headNode) {
             headNode = temp;
         } 
         else {
             headNode->InsertAfter(temp);
         }
         break;
      case 'd':
       // Remove song logic
         cout << "REMOVE SONG" << endl;
         if (!headNode) {
             cout << "Playlist is empty" << endl;
         } 
         else {
             string targetID;
             cout << "Enter song's unique ID:" << endl;
             cin.ignore(); // Clear the newline character from the input buffer
             getline(cin, targetID);

             PlaylistNode* current = headNode;
             PlaylistNode* prev = nullptr;

             while (current && current->GetID() != targetID) {
                 prev = current;
                 current = current->GetNext();
             }

             if (!current) {
                 cout << "Song not found." << endl;
             } 
             else {
                 if (prev) {
                     prev->SetNext(current->GetNext());
                     delete current;
                 } 
                 else {
                     PlaylistNode* temp = headNode;
                     headNode = headNode->GetNext();
                     delete temp;
                 }
                 cout << "\"" << current->GetSongName() << "\" removed." << endl;
             }
         }
         break;
      case 'c': 
         // Change position of song logic
         cout << "CHANGE POSITION OF SONG" << endl;

         if (!headNode) {
             cout << "Playlist is empty" << endl;
         } else {
             int currentPos, newPos;
             cout << "Enter song's current position:" << endl;
             cin >> currentPos;

             cout << "Enter new position for song:" << endl;
             cin >> newPos;

             int playlistLength = 0;
             PlaylistNode* current = headNode;
             while (current) {
                 playlistLength++;
                 current = current->GetNext();
             }

             current = headNode;
             PlaylistNode* prev = nullptr;
             int currentPosition = 1;

             while (currentPosition < currentPos && current) {
                 prev = current;
                 current = current->GetNext();
                 currentPosition++;
             }

             if (!current) {
                 cout << "Invalid current position." << endl;
             } else {
                 // Remove the current node from its current position
                 if (prev) {
                     prev->SetNext(current->GetNext());
                 } else {
                     headNode = current->GetNext();
                 }

                 // Insert the current node to its new position
                 if (newPos <= 1) {
                     current->SetNext(headNode);
                     headNode = current;
                 } else if (newPos > playlistLength) {
                     PlaylistNode* temp = headNode;
                     while (temp->GetNext()) {
                         temp = temp->GetNext();
                     }
                     temp->SetNext(current);
                     current->SetNext(nullptr);
                 } else {
                     PlaylistNode* temp = headNode;
                     int newPosition = 1;
                     while (newPosition < newPos - 1) {
                         temp = temp->GetNext();
                         newPosition++;
                     }
                     current->SetNext(temp->GetNext());
                     temp->SetNext(current);
                 }

                 cout << "\"" << current->GetSongName() << "\" moved to position " << newPos << endl;
             }
         }
         break;
      case 's': 
         // Output songs by specific artist logic
         cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;

         if (!headNode) {
             cout << "Playlist is empty" << endl;
         } 
         else {
             string artistName;
             cout << "Enter artist's name:" << endl;
             cin.ignore(); // Clear the newline character from the input buffer
             getline(cin, artistName);

             PlaylistNode* current = headNode;
             int position = 1;

             while (current) {
                 if (current->GetArtistName() == artistName) {
                     cout << position << "." << endl;
                     current->PrintPlaylistNode();
                 }
                 current = current->GetNext();
                 position++;
             }
         }
         break;
     case 't': 
         // Output total time of playlist logic
         cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;

         int totalTime = 0;
         PlaylistNode* current = headNode;

         while (current) {
             totalTime += current->GetSongLength();
             current = current->GetNext();
         }

         cout << "Total time: " << totalTime << " seconds" << endl;
         break;
      case 'o':
         if(headNode==nullptr){
            cout<<"Playlist is empty"<<endl;
         }
         else{
            cout<<playlistTitle<<" - OUTPUT FULL PLAYLIST"<<endl;
            PlaylistNode* temp = headNode;
            int count = 0;
            while(temp!=nullptr){
               count++;
               cout<<count<<"."<<endl;
               temp->PrintPlaylistNode();
               cout<<endl;
            }  
         }
         break;
      case 'q':
         break;
      default:
            cout << "Invalid option. Please try again." << endl;
   }
   return headNode;
}

int main() {
   /* Type your code here */
   string playlistTitle;
   char option;
   PlaylistNode* head = nullptr;
   
   cout<<"Enter playlist's title:"<<endl;
   getline(cin, playlistTitle);
   // cout<<endl;
   

   cout<<endl;
   
   char choice;
    do {
        PrintMenu(playlistTitle);
        cout << "\nChoose an option:" << endl;
        cin >> choice;
        cin.ignore();  // Consume the newline character left in the buffer

        headNode = ExecuteMenu(choice, playlistTitle, headNode);

    } while (choice != 'q');

    return 0;
   return 0;
}

