/* Type your code here */
// string uniqueID - Initialized to "none" in default constructor
// string songName - Initialized to "none" in default constructor
// string artistName - Initialized to "none" in default constructor
// int songLength - Initialized to 0 in default constructor
// PlaylistNode* nextNodePtr - Initialized to 0 in default constructor

// GetID() - Accessor
// GetSongName() - Accessor
// GetArtistName() - Accessor
// GetSongLength() - Accessor
// GetNext() - Accessor
// InsertAfter(PlaylistNode* nodePtr) - Mutator (1 pt)
// SetNext(PlaylistNode* nodePtr) - Mutator (1 pt)
// PrintPlaylistNode() - Outputs uniqueID, songname, artistName, and songLength based on the format example below.
#include <iostream>
#include "PlaylistNode.h"
using namespace std;

PlaylistNode::PlaylistNode(){
   uniqueID="none";
   songName="none";
   artistName="none";
   songLength=0;
   nextNodePtr=nullptr;
}
PlaylistNode::PlaylistNode(string ID, string name, string artist, int length, PlaylistNode* next){
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
