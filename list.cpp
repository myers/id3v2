// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

#if defined HAVE_CONFIG_H
#include <config.h>
#endif

#include <iostream>
#include <cstring>
#include <id3/tag.h>
#include <getopt.h>
#include <cstdlib>
#include <cstdio>
#include <id3/misc_support.h>
#include "frametable.h"
#include "genre.h"

char *GetDescription(const ID3_FrameID eFrameID)
{
  for(int ii = 0; ii < frameTableCount; ii++ )
  {
    if (frameTable[ii].frameID == eFrameID)
      return frameTable[ii].frameLongName;
  }
  return NULL;
}

void PrintFrameHelp(char *sName)
{
    for(int ii = 0; ii < frameTableCount - 1; ii++ )
    {
      std::cout << "    --" << frameTable[ii].frameName << "    "
           << frameTable[ii].frameLongName << std::endl;
    }
    return;
}

void PrintGenreList()
{
  for (int ii = 0; ii < GetGenreCount(); ii++)
    printf("%3d: %s\n", ii, GetGenreFromNum(ii));
}

int PrintInformation(char *sFileName, const ID3_Tag &myTag, int rfc822)
{
  bool firstLine = true;
  const ID3_Frame * myFrame;
  ID3_Tag::ConstIterator *Iter=myTag.CreateIterator();
  for (size_t nFrames = 0; nFrames < myTag.NumFrames(); nFrames++)
  {
    myFrame = Iter->GetNext();

    if(firstLine) {
      if (rfc822)
        std::cout << "\nFilename: " << sFileName << std::endl;
      else
        std::cout << "id3v2 tag info for " << sFileName << ":" << std::endl;
      firstLine = false;
    }

    if (NULL != myFrame)
    {
      const char* desc = myFrame->GetDescription();
      if (!desc) desc = "";
      if (rfc822)
        std::cout << myFrame->GetTextID() << ": ";
      else
        std::cout << myFrame->GetTextID() << " (" << desc << "): ";
      ID3_FrameID eFrameID = myFrame->GetID();

      switch (eFrameID)
      {
        case ID3FID_ALBUM:
        case ID3FID_BPM:
        case ID3FID_COMPOSER:
        case ID3FID_COPYRIGHT:
        case ID3FID_DATE:
        case ID3FID_PLAYLISTDELAY:
        case ID3FID_ENCODEDBY:
        case ID3FID_LYRICIST:
        case ID3FID_FILETYPE:
        case ID3FID_TIME:
        case ID3FID_CONTENTGROUP:
        case ID3FID_TITLE:
        case ID3FID_SUBTITLE:
        case ID3FID_INITIALKEY:
        case ID3FID_LANGUAGE:
        case ID3FID_SONGLEN:
        case ID3FID_MEDIATYPE:
        case ID3FID_ORIGALBUM:
        case ID3FID_ORIGFILENAME:
        case ID3FID_ORIGLYRICIST:
        case ID3FID_ORIGARTIST:
        case ID3FID_ORIGYEAR:
        case ID3FID_FILEOWNER:
        case ID3FID_LEADARTIST:
        case ID3FID_BAND:
        case ID3FID_CONDUCTOR:
        case ID3FID_MIXARTIST:
        case ID3FID_PARTINSET:
        case ID3FID_PUBLISHER:
        case ID3FID_TRACKNUM:
        case ID3FID_RECORDINGDATES:
        case ID3FID_NETRADIOSTATION:
        case ID3FID_NETRADIOOWNER:
        case ID3FID_SIZE:
        case ID3FID_ISRC:
        case ID3FID_ENCODERSETTINGS:
        case ID3FID_YEAR:
        {
          char *sText = ID3_GetString(myFrame, ID3FN_TEXT);
          std::cout << sText << std::endl;
          delete [] sText;
          break;
        }
        case ID3FID_CONTENTTYPE:
        {
          const char* genre_str;
          int genre_id = 255;
          char *sText = ID3_GetString(myFrame, ID3FN_TEXT);
          sscanf(sText, "(%d)", &genre_id);
          if (genre_id == 255) {
            genre_str = sText;
            genre_id = GetNumFromGenre(sText);
          }
          else
            genre_str = GetGenreFromNum(genre_id);
          std::cout << genre_str << " (" << genre_id << ")" << std::endl;
          delete [] sText;
          break;
        }
        case ID3FID_USERTEXT:
        {
          char
            *sText = ID3_GetString(myFrame, ID3FN_TEXT),
            *sDesc = ID3_GetString(myFrame, ID3FN_DESCRIPTION);
          std::cout << "(" << sDesc << "): " << sText << std::endl;
          delete [] sText;
          delete [] sDesc;
          break;
        }
        case ID3FID_COMMENT:
        case ID3FID_UNSYNCEDLYRICS:
        {
          char
            *sText = ID3_GetString(myFrame, ID3FN_TEXT),
            *sDesc = ID3_GetString(myFrame, ID3FN_DESCRIPTION),
            *sLang = ID3_GetString(myFrame, ID3FN_LANGUAGE);
          std::cout << "(" << sDesc << ")[" << sLang << "]: "
               << sText << std::endl;
          delete [] sText;
          delete [] sDesc;
          delete [] sLang;
          break;
        }
        case ID3FID_WWWAUDIOFILE:
        case ID3FID_WWWARTIST:
        case ID3FID_WWWAUDIOSOURCE:
        case ID3FID_WWWCOMMERCIALINFO:
        case ID3FID_WWWCOPYRIGHT:
        case ID3FID_WWWPUBLISHER:
        case ID3FID_WWWPAYMENT:
        case ID3FID_WWWRADIOPAGE:
        {
          char *sURL = ID3_GetString(myFrame, ID3FN_URL);
          std::cout << sURL << std::endl;
          delete [] sURL;
          break;
        }
        case ID3FID_WWWUSER:
        {
          char
            *sURL = ID3_GetString(myFrame, ID3FN_URL),
            *sDesc = ID3_GetString(myFrame, ID3FN_DESCRIPTION);
          std::cout << "(" << sDesc << "): " << sURL << std::endl;
          delete [] sURL;
          delete [] sDesc;
          break;
        }
        case ID3FID_INVOLVEDPEOPLE:
        {
          // This isn't the right way to do it---will only get first person
          size_t nItems = myFrame->Field(ID3FN_TEXT).GetNumTextItems();
          for (size_t nIndex = 1; nIndex <= nItems; nIndex++)
          {
            char *sPeople = ID3_GetString(myFrame, ID3FN_TEXT, nIndex);
            std::cout << sPeople;
            delete [] sPeople;
            if (nIndex < nItems)
            {
              std::cout << ", ";
            }
          }
          std::cout << std::endl;
          break;
        }
        case ID3FID_PICTURE:
        {
          char
            *sMimeType = ID3_GetString(myFrame, ID3FN_MIMETYPE),
            *sDesc     = ID3_GetString(myFrame, ID3FN_DESCRIPTION),
            *sFormat   = ID3_GetString(myFrame, ID3FN_IMAGEFORMAT);
          size_t
            nPicType   = myFrame->Field(ID3FN_PICTURETYPE).Get(),
            nDataSize  = myFrame->Field(ID3FN_DATA).Size();
          std::cout << "(" << sDesc << ")[" << sFormat << ", "
               << nPicType << "]: " << sMimeType << ", " << nDataSize
               << " bytes" << std::endl;
          delete [] sMimeType;
          delete [] sDesc;
          delete [] sFormat;
          break;
        }
        case ID3FID_GENERALOBJECT:
        {
          char
          *sMimeType = ID3_GetString(myFrame, ID3FN_MIMETYPE),
          *sDesc = ID3_GetString(myFrame, ID3FN_DESCRIPTION),
          *sFileName = ID3_GetString(myFrame, ID3FN_FILENAME);
          size_t nDataSize = myFrame->GetField(ID3FN_DATA)->Size();
          std::cout << "(" << sDesc << ")["
               << sFileName << "]: " << sMimeType << ", " << nDataSize
               << " bytes" << std::endl;
          delete [] sMimeType;
          delete [] sDesc;
          delete [] sFileName;
          break;
        }
        case ID3FID_UNIQUEFILEID:
        {
          char *sOwner = ID3_GetString(myFrame, ID3FN_OWNER);
          size_t nDataSize = myFrame->Field(ID3FN_DATA).Size();
          std::cout << sOwner << ", " << nDataSize
               << " bytes" << std::endl;
          delete [] sOwner;
          break;
        }
        case ID3FID_PLAYCOUNTER:
        {
          size_t nCounter = myFrame->Field(ID3FN_COUNTER).Get();
          std::cout << nCounter << std::endl;
          break;
        }
        case ID3FID_POPULARIMETER:
        {
          char *sEmail = ID3_GetString(myFrame, ID3FN_EMAIL);
          size_t
            nCounter = myFrame->Field(ID3FN_COUNTER).Get(),
            nRating = myFrame->Field(ID3FN_RATING).Get();
          std::cout << sEmail << ", counter="
               << nCounter << " rating=" << nRating;
          delete [] sEmail;
          break;
        }
        case ID3FID_CRYPTOREG:
        case ID3FID_GROUPINGREG:
        {
          char *sOwner = ID3_GetString(myFrame, ID3FN_OWNER);
          size_t
            nSymbol = myFrame->Field(ID3FN_ID).Get(),
            nDataSize = myFrame->Field(ID3FN_DATA).Size();
          std::cout << "(" << nSymbol << "): " << sOwner
               << ", " << nDataSize << " bytes";
          break;
        }
        case ID3FID_AUDIOCRYPTO:
        case ID3FID_EQUALIZATION:
        case ID3FID_EVENTTIMING:
        case ID3FID_CDID:
        case ID3FID_MPEGLOOKUP:
        case ID3FID_OWNERSHIP:
        case ID3FID_PRIVATE:
        case ID3FID_POSITIONSYNC:
        case ID3FID_BUFFERSIZE:
        case ID3FID_VOLUMEADJ:
        case ID3FID_REVERB:
        case ID3FID_SYNCEDLYRICS:
        case ID3FID_SYNCEDTEMPO:
        case ID3FID_METACRYPTO:
        {
          std::cout << " (unimplemented)" << std::endl;
          break;
        }
        default:
        {
          std::cout << " frame" << std::endl;
          break;
        }
      }
    }
  }
  if(firstLine)
    return 1;

  return 0;
}

int PrintID3v1Tag(char *sFileName)
// code from id3
{
  struct id3 {
    char tag[3];
    char title[30];
    char artist[30];
    char album[30];
    char year[4];
    /* With ID3 v1.0, the comment is 30 chars long */
    /* With ID3 v1.1, if comment[28] == 0 then comment[29] == tracknum */
    char comment[30];
    unsigned char genre;
  } id3v1tag;
  FILE *fp;

  fp = fopen(sFileName, "r"); /* read only */

  if (fp == NULL) { /* file didn't open */
    fprintf(stderr, "fopen: %s: ", sFileName);
    perror("id3v2");
    return -1;
  }
  if (fseek(fp, -128, SEEK_END) < 0) {
    /* problem rewinding */
  } else { /* we rewound successfully */
    if (fread(&id3v1tag, 128, 1, fp) != 1) {
      /* read error */
      fprintf(stderr, "fread: %s: ", sFileName);
      perror("");
    }
  }

  fclose(fp);

    /* This simple detection code has a 1 in 16777216
     * chance of misrecognizing or deleting the last 128
     * bytes of your mp3 if it isn't tagged. ID3 ain't
     * world peace, live with it.
     */


  if (!strncmp(id3v1tag.tag, "TAG", 3))
  {
    std::cout << "id3v1 tag info for " << sFileName << ":" << std::endl;
    printf("Title  : %-30.30s  Artist: %-30.30s\n",
            id3v1tag.title, id3v1tag.artist);
    printf("Album  : %-30.30s  Year: %-4.4s, Genre: %s (%d)\n",
            id3v1tag.album, id3v1tag.year,
            (id3v1tag.genre < GetGenreCount())
            ? GetGenreFromNum(id3v1tag.genre) :
            "Unknown", id3v1tag.genre);
    if (!id3v1tag.comment[28])
      printf("Comment: %-28.28s    Track: %d\n",
             id3v1tag.comment, id3v1tag.comment[29]);
    else
      printf("Comment: %-30.30s\n", id3v1tag.comment);
  }
  else
  {
    return 1;
  }
  return 0;
}

void ListTag(int argc, char *argv[], int optind, int rfc822)
{
  int ret;
  for (size_t nIndex = optind; nIndex < argc; nIndex++)
  {
    bool tags = false;
    ID3_Tag myTag;

    if (!rfc822)
    {
      ret = PrintID3v1Tag(argv[nIndex]);
      if (ret == -1)
      {
        continue;
      }
      else if(ret == 0)
      {
        tags = true;
      }
    }
    myTag.Link(argv[nIndex], ID3TT_ID3V2);
    if(!PrintInformation(argv[nIndex],myTag,rfc822))
      tags = true;
    if(!tags)
      std::cout << argv[nIndex] << ": No ID3 tag" << std::endl;
  }

  return;
}

