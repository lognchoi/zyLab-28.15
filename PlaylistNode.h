/* Type your code here */
#include <iostream>
using namespace std;

class PlaylistNode{
   private:
      string uniqueID;
      string songName;
      string artistName;
      int songLength;
      PlaylistNode* nextNodePtr;
   public:
      PlaylistNode();
      PlaylistNode(string ID, string name, string artist, int length, PlaylistNode* next);
      string GetID();
      string GetSongName();
      string GetArtistName();
      int GetSongLength();
      PlaylistNode* GetNext();
      void InsertAfter(PlaylistNode* nodePtr);
      void SetNext(PlaylistNode* nodePtr);
      void PrintPlaylistNode();
};
   
