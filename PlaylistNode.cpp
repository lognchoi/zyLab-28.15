#include <iostream>
#include "PlaylistNode.h"
using namespace std;

PlaylistNode::PlaylistNode(string ID, string name, string artist, int length,PlaylistNode* next){
   uniqueID=ID;
   songName=name;
   artistName=artist;
   songLength=length;
   nextNodePtr=next;
}
void PlaylistNode::InsertAfter(PlaylistNode* nodePtr){
   PlaylistNode* temp = this->nextNodePtr;
   this->nextNodePtr = nodePtr;
   nodePtr->nextNodePtr = temp;
}
void PlaylistNode::SetNext(PlaylistNode* nodePtr){
   this->nextNodePtr = nodePtr;
}
void PlaylistNode::PrintPlaylistNode(){
   cout<<"Unique ID: "<<uniqueID<<endl;
   cout<<"Song Name: "<<songName<<endl;
   cout<<"Artist Name: "<<artistName<<endl;
   cout<<"Song Length (in seconds): "<<songLength<<endl;
}

string PlaylistNode::GetID(){
   return uniqueID;
}
string PlaylistNode::GetSongName(){
   return songName;
}
string PlaylistNode::GetArtistName(){
   return artistName;
}
int PlaylistNode::GetSongLength(){
   return songLength;
}
PlaylistNode* PlaylistNode::GetNext(){
   return nextNodePtr;
}
