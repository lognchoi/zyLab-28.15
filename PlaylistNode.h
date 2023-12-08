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
      PlaylistNode(string ID="none", string name="none", string artist="none", int length=0, PlaylistNode* next=nullptr);
      string GetID();
      string GetSongName();
      string GetArtistName();
      int GetSongLength();
      PlaylistNode* GetNext();
      void InsertAfter(PlaylistNode* nodePtr);
      void SetNext(PlaylistNode* nodePtr);
      void PrintPlaylistNode();
};
   
