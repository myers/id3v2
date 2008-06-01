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

#ifndef __GENRE_H__
#include "genre.h"
#endif

#ifdef SORT_RUNTIME
#include <stdlib.h>
#endif  // SORT_RUNTIME
#include <string.h>


char *genre_table[] = {"Blues",
                       "Classic Rock",
                       "Country",
                       "Dance",
                       "Disco",
                       "Funk",
                       "Grunge",
                       "Hip-Hop",
                       "Jazz",
                       "Metal",
                       "New Age",
                       "Oldies",
                       "Other",
                       "Pop",
                       "R&B",
                       "Rap",
                       "Reggae",
                       "Rock",
                       "Techno",
                       "Industrial",
                       "Alternative",
                       "Ska",
                       "Death Metal",
                       "Pranks",
                       "Soundtrack",
                       "Euro-Techno",
                       "Ambient",
                       "Trip-Hop",
                       "Vocal",
                       "Jazz+Funk",
                       "Fusion",
                       "Trance",
                       "Classical",
                       "Instrumental",
                       "Acid",
                       "House",
                       "Game",
                       "Sound Clip",
                       "Gospel",
                       "Noise",
                       "Alt. Rock",
                       "Bass",
                       "Soul",
                       "Punk",
                       "Space",
                       "Meditative",
                       "Instrum. Pop",
                       "Instrum. Rock",
                       "Ethnic",
                       "Gothic",
                       "Darkwave",
                       "Techno-Indust.",
                       "Electronic",
                       "Pop-Folk",
                       "Eurodance",
                       "Dream",
                       "Southern Rock",
                       "Comedy",
                       "Cult",
                       "Gangsta",
                       "Top 40",
                       "Christian Rap",
                       "Pop/Funk",
                       "Jungle",
                       "Native American",
                       "Cabaret",
                       "New Wave",
                       "Psychadelic",
                       "Rave",
                       "Showtunes",
                       "Trailer",
                       "Lo-Fi",
                       "Tribal",
                       "Acid Punk",
                       "Acid Jazz",
                       "Polka",
                       "Retro",
                       "Musical",
                       "Rock & Roll",
                       "Hard Rock",
                       "Folk",
                       "Folk/Rock",
                       "National Folk",
                       "Swing",
                       "Fusion",
                       "Bebob",
                       "Latin",
                       "Revival",
                       "Celtic",
                       "Bluegrass",
                       "Avantgarde",
                       "Gothic Rock",
                       "Progress. Rock",
                       "Psychadel. Rock",
                       "Symphonic Rock",
                       "Slow Rock",
                       "Big Band",
                       "Chorus",
                       "Easy Listening",
                       "Acoustic",
                       "Humour",
                       "Speech",
                       "Chanson",
                       "Opera",
                       "Chamber Music",
                       "Sonata",
                       "Symphony",
                       "Booty Bass",
                       "Primus",
                       "Porn Groove",
                       "Satire",
 /* The following were added 1999 26 Apr by Ben Gertzfield <che@debian.org> 
  * as per the list at http://mp3.musichall.cz/id3master/faq.htm but with a 
  * few spell-checks confirmed by running 'strings' on the in_mp3.dll file 
  * from winamp 2.10 (sorry :)
  */
		       "Slow Jam",
		       "Club",
		       "Tango",
		       "Samba",
		       "Folklore",
		       "Ballad",
		       "Power Ballad",
		       "Rhythmic Soul",
		       "Freestyle",
		       "Duet",
		       "Punk Rock",
		       "Drum Solo",
		       "A Capella",
		       "Euro-House",
		       "Dance Hall",
		       "Goa",
		       "Drum & Bass",
		       "Club-House",
		       "Hardcore",
		       "Terror",
		       "Indie",
		       "BritPop",
		       "Negerpunk",
		       "Polsk Punk",
		       "Beat",
		       "Christian Gangsta Rap",	/* DJ JC in da house */
		       "Heavy Metal",
		       "Black Metal",
		       "Crossover",
		       "Contemporary Christian",
		       "Christian Rock",
				/* winamp 1.91 genres */
		       "Merengue",
		       "Salsa",
		       "Thrash Metal",
				/* winamp 1.92 genres */
		       "Anime",
		       "Jpop",
		       "Synthpop",
                       };

const int genre_count = sizeof(genre_table) / sizeof(char*);

#ifdef SORT_RUNTIME
int genre_map[genre_count];
#else
int genre_map[genre_count] =
    { 123, 34, 74, 73, 99, 40, 20, 26, 145, 90, 116, 41, 135, 85, 96, 138, 89,
      0, 107, 132, 65, 88, 104, 102, 97, 136, 61, 141, 1, 32, 112, 128, 57,
      140, 2, 139, 58, 3, 125, 50, 22, 4, 55, 127, 122, 120, 98, 52, 48, 124,
      25, 54, 80, 81, 115, 119, 5, 30, 84, 36, 59, 126, 38, 49, 91, 6, 79, 129,
      137, 7, 35, 100, 131, 19, 46, 47, 33, 8, 29, 146, 63, 86, 71, 45, 142, 9,
      77, 82, 64, 133, 10, 66, 39, 11, 103, 12, 75, 134, 13, 53, 62, 109, 117,
      23, 108, 92, 93, 67, 43, 121, 14, 15, 68, 16, 76, 87, 118, 17, 78, 143,
      114, 110, 69, 21, 111, 95, 105, 42, 37, 24, 56, 44, 101, 83, 94, 106,
      147, 113, 18, 51, 130, 144, 60, 70, 31, 72, 27, 28 } ;
#endif  // SORT_RUNTIME

int GetGenreCount()
{
    return genre_count;
}

const char *GetGenreFromNum(int genre_id)
{
    if ((genre_id >= 0) && (genre_id < GetGenreCount()))
        return genre_table[genre_id];
    else
        return "Unknown";
}

int GetNumFromGenre(const char *genre)
{
    int a=0;
    int b=GetGenreCount()-1;
    int i;

    while(a <= b) {
        const int i = (a+b)/2;
        const int genre_id = genre_map[i];
        const int cmp = strcmp(GetGenreFromNum(genre_id), genre);

        if (cmp == 0)
            return genre_id;
        else if (cmp < 0)
            a = i+1;
        else
            b = i-1;
    }

    return 255;
}

#ifdef SORT_RUNTIME
int CompareGenres(const void *a, const void *b)
{
    int g1, g2;
    g1 = *((int*)a);
    g2 = *((int*)b);

    return strcmp(GetGenreFromNum(g1), GetGenreFromNum(g2));
}

void InitGenres()
{
    int i;
    for (i=0; i<GetGenreCount(); ++i)
        genre_map[i] = i;

    qsort(genre_map, GetGenreCount(), sizeof(int), &CompareGenres);
}
#endif  // SORT_RUNTIME
