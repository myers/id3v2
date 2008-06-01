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


#include <iostream>
#include <stdlib.h>
#include "genre.cpp"

#ifndef SORT_RUNTIME
int CompareGenres(const void *a, const void *b)
{
    int g1, g2;
    g1 = *((int*)a);
    g2 = *((int*)b);

    return strcmp(GetGenreFromNum(g1), GetGenreFromNum(g2));
}
#endif  // SORT_RUNTIME

void main()
{
    int i;
    for (i=0; i<GetGenreCount(); ++i)
        genre_map[i] = i;

    qsort(genre_map, GetGenreCount(), sizeof(int), &CompareGenres);

    cout << "char *genre_table[] = {" << genre_map[0];
    for (i=1; i<GetGenreCount(); ++i)
        cout << ", " << genre_map[i];
    cout << "};" << std::endl;
}
