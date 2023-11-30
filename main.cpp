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
// ExecuteMenu() takes 3 parameters: a character representing the user's choice, a playlist title,
// and the pointer to the head node of a playlist. ExecuteMenu() performs the menu options (described below)
// according to the user's choice and returns the pointer to the head node of the playlist.
PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   /* Type your code here */
   PlaylistNode* temp = nullptr;
   string name;
   string song;
   string artist;
   int length;
   switch(option){
      case 'a':
         cout<<"ADD SONG"<<endl;
         cout<<"Enter song's unique ID:"<<endl;
         cin>>name;
         cout<<"Enter song's name:"<<endl;
         cin>>song;
         cout<<"Enter artist's name:"<<endl;
         cin>>artist;
         cout<<"Enter song's length (in seconds):"<<endl;
         cin>>length;
         temp = new PlaylistNode(name, song, artist, length, nullptr);
         headNode->InsertAfter(temp);
         break;
      case 'd':
      case 'c':
      case 's':
      case 't':
      case 'o':
         if(headNode==nullptr){
            cout<<"Playlist is empty"<<endl;
         }
         else{
            cout<<playlistTitle<<" - OUTPUT FULL PLAYLIST"<<endl;
            PlaylistNode* node = headNode;
            int num = 1;
            while(node!=nullptr){
               cout<<num<<"."<<endl;
               node->PrintPlaylistNode();
               cout<<endl;
               node=node->GetNext();
            }
         }
         break;
      case 'q':
         cout<<"quit";
         break;
   }
   return nullptr;

}

int main() {
   /* Type your code here */
   
   string title;
   char option;
   
   cout<<"Enter playlist's title: "<<endl;
   cin>>title;
   PrintMenu(title);
   cout<<"Option: "<<endl;
   cin>>option;
   PlaylistNode* head = new PlaylistNode();
   
   // char option, string playlistTitle, PlaylistNode* headNode
   ExecuteMenu(option, title, head);
   
   cin>>option;
   ExecuteMenu(option, title, head);



   return 0;
}

