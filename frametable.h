/* id3v2 frame table
 * frametable.h - struct with info on all id3v2 frames
 * Copyright (C) 2000 Myers Carpenter (icepick@sourceforge.net)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,
 * USA.
 */

#ifndef __FRAMETABLE_H__
#define __FRAMETABLE_H__

#include <id3/globals.h>

struct frameTbl {
  char *frameName;
  enum ID3_FrameID frameID;
  char *frameLongName;
}; 

static struct frameTbl frameTable[] = {
  { "AENC", ID3FID_AUDIOCRYPTO,  	    "Audio encryption" },
  { "APIC", ID3FID_PICTURE,	 			    "Attached picture" },
  { "COMM", ID3FID_COMMENT,	 			    "Comments" },
  { "COMR", ID3FID_COMMERCIAL,	 	    "Commercial frame" },
  { "ENCR", ID3FID_CRYPTOREG,	 		    "Encryption method registration" },
  { "EQUA", ID3FID_EQUALIZATION, 	    "Equalization" },
	{ "ETCO", ID3FID_EVENTTIMING, 	    "Event timing codes" },
	{ "GEOB", ID3FID_GENERALOBJECT,	    "General encapsulated object" },
	{ "GRID", ID3FID_GROUPINGREG,       "Group identification registration" },
	{ "IPLS", ID3FID_INVOLVEDPEOPLE,    "Involved people list" },
	{ "LINK", ID3FID_LINKEDINFO,        "Linked information" },
	{ "MCDI", ID3FID_CDID,              "Music CD identifier" },
	{ "MLLT", ID3FID_MPEGLOOKUP,        "MPEG location lookup table" },
	{ "OWNE", ID3FID_OWNERSHIP,         "Ownership frame" },
	{ "PRIV", ID3FID_PRIVATE,           "Private frame" },
	{ "PCNT", ID3FID_PLAYCOUNTER,       "Play counter" },
	{ "POPM", ID3FID_POPULARIMETER,     "Popularimeter" },
	{ "POSS", ID3FID_POSITIONSYNC,      "Position synchronisation frame" },
	{ "RBUF", ID3FID_BUFFERSIZE,        "Recommended buffer size" },
	{ "RVAD", ID3FID_VOLUMEADJ,         "Relative volume adjustment" },
	{ "RVRB", ID3FID_REVERB,            "Reverb" },
	{ "SYLT", ID3FID_SYNCEDLYRICS,      "Synchronized lyric/text" },
	{ "SYTC", ID3FID_SYNCEDTEMPO,       "Synchronized tempo codes" },
	{ "TALB", ID3FID_ALBUM,             "Album/Movie/Show title" },
	{ "TBPM", ID3FID_BPM,               "BPM (beats per minute)" },
	{ "TCOM", ID3FID_COMPOSER,          "Composer" },
	{ "TCON", ID3FID_CONTENTTYPE,       "Content type" },
	{ "TCOP", ID3FID_COPYRIGHT,         "Copyright message" },
	{ "TDAT", ID3FID_DATE,              "Date" },
	{ "TDLY", ID3FID_PLAYLISTDELAY,     "Playlist delay" },
	{ "TENC", ID3FID_ENCODEDBY,         "Encoded by" },
	{ "TEXT", ID3FID_LYRICIST,          "Lyricist/Text writer" },
	{ "TFLT", ID3FID_FILETYPE,          "File type" },
	{ "TIME", ID3FID_TIME,              "Time" },
	{ "TIT1", ID3FID_CONTENTGROUP,      "Content group description" },
	{ "TIT2", ID3FID_TITLE,             "Title/songname/content description" },
	{ "TIT3", ID3FID_SUBTITLE,          "Subtitle/Description refinement" },
	{ "TKEY", ID3FID_INITIALKEY,        "Initial key" },
	{ "TLAN", ID3FID_LANGUAGE,          "Language(s)" },
	{ "TLEN", ID3FID_SONGLEN,           "Length" },
	{ "TMED", ID3FID_MEDIATYPE,         "Media type" },
	{ "TOAL", ID3FID_ORIGALBUM,         "Original album/movie/show title" },
	{ "TOFN", ID3FID_ORIGFILENAME,      "Original filename" },
	{ "TOLY", ID3FID_ORIGLYRICIST,      "Original lyricist(s)/text writer(s)" },
	{ "TOPE", ID3FID_ORIGARTIST,        "Original artist(s)/performer(s)" },
	{ "TORY", ID3FID_ORIGYEAR,          "Original release year" },
	{ "TOWN", ID3FID_FILEOWNER,         "File owner/licensee" },
	{ "TPE1", ID3FID_LEADARTIST,        "Lead performer(s)/Soloist(s)" },
	{ "TPE2", ID3FID_BAND,              "Band/orchestra/accompaniment" },
	{ "TPE3", ID3FID_CONDUCTOR,         "Conductor/performer refinement" },
	{ "TPE4", ID3FID_MIXARTIST,         "Interpreted, remixed, or otherwise modified by" },
	{ "TPOS", ID3FID_PARTINSET,         "Part of a set" },
	{ "TPUB", ID3FID_PUBLISHER,         "Publisher" },
	{ "TRCK", ID3FID_TRACKNUM,          "Track number/Position in set" },
	{ "TRDA", ID3FID_RECORDINGDATES,    "Recording dates" }, 
	{ "TRSN", ID3FID_NETRADIOSTATION,   "Internet radio station name" },
	{ "TRSO", ID3FID_NETRADIOOWNER,     "Internet radio station owner" },
	{ "TSIZ", ID3FID_SIZE,              "Size" },
	{ "TSRC", ID3FID_ISRC,              "ISRC (international standard recording code)" },
	{ "TSSE", ID3FID_ENCODERSETTINGS,   "Software/Hardware and settings used for encoding" },
  { "TXXX", ID3FID_USERTEXT,          "User defined text information" },
  { "TYER", ID3FID_YEAR,              "Year" },
  { "UFID", ID3FID_UNIQUEFILEID,      "Unique file identifier" },
  { "USER", ID3FID_TERMSOFUSE,        "Terms of use" },
  { "USLT", ID3FID_UNSYNCEDLYRICS,    "Unsynchronized lyric/text transcription" },
  { "WCOM", ID3FID_WWWCOMMERCIALINFO, "Commercial information" },
  { "WCOP", ID3FID_WWWCOPYRIGHT,      "Copyright/Legal infromation" },
  { "WOAF", ID3FID_WWWAUDIOFILE,      "Official audio file webpage" },
  { "WOAR", ID3FID_WWWARTIST,         "Official artist/performer webpage" },
  { "WOAS", ID3FID_WWWAUDIOSOURCE,    "Official audio source webpage" },
  { "WORS", ID3FID_WWWRADIOPAGE,      "Official internet radio station homepage" },
  { "WPAY", ID3FID_WWWPAYMENT,        "Payment" },
  { "WPUB", ID3FID_WWWPUBLISHER,      "Official publisher webpage" },
  { "WXXX", ID3FID_WWWUSER,           "User defined URL link" },
  { "    ", ID3FID_METACRYPTO,        "Encrypted meta frame" },
  { "????", ID3FID_NOFRAME,           "Error" }
};

int frameTableCount = 75;


#endif /* __FRAMETABLE_H__ */
