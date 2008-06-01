#include <cstdio>
#include <iostream>
#include <id3/tag.h>
#include <cstdlib>

void DeleteTag(int argc, char *argv[], int optind, int whichTags)
{

    FILE * fp;
    
    for (size_t nIndex = optind; nIndex < argc; nIndex++)
    {
      /* cludgy to check if we have the proper perms */
      fp = fopen(argv[nIndex], "r+");
      if (fp == NULL) { /* file didn't open */
        fprintf(stderr, "fopen: %s: ", argv[nIndex]);
        perror("id3v2");
        continue;
      }
      fclose(fp);

      ID3_Tag myTag;

      std::cout << "Stripping id3 tag in \"";
      std::cout << argv[nIndex] << "\"...";

      myTag.Clear();
      myTag.Link(argv[nIndex], ID3TT_ALL);

      luint nTags;
      switch(whichTags) 
      {
        case 1: 
          nTags = myTag.Strip(ID3TT_ID3V1);
          std::cout << "id3v1 ";
          break;
        case 2:
          nTags = myTag.Strip(ID3TT_ID3V2);
          std::cout << "id3v2 ";
          break; 
        case 0:
        default:
          nTags = myTag.Strip(ID3TT_ID3);
          std::cout << "id3v1 and v2 ";
      }

      std::cout << "stripped." << std::endl;
    }

  return;
}


void ConvertTag(int argc, char *argv[], int optind)
{
    for (size_t nIndex = optind; nIndex < argc; nIndex++)
    {
      ID3_Tag myTag;

      std::cout << "Converting id3v1 tag to id3v2 in ";
      std::cout << argv[nIndex] << "...";

      myTag.Clear();
      myTag.Link(argv[nIndex], ID3TT_ALL);

      luint nTags;

      nTags = myTag.Update(ID3TT_ID3V2);
      std::cout << " converted ";
      std::cout << std::endl;
    }

  return;
}
