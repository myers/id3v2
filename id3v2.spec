Summary: An MP3 technical info viewer and ID3 tag editor
Name: id3v2
Version: 0.1.6
Release: 1
Copyright: GPL
Group: Utilities/file
Packager: Pavel Polischouk <pavelp@geocities.com>
Source: http://download.sourceforge.net/%{name}/%{name}-%{version}.tar.gz
Patch:  %name-%version.newlib.patch
BuildRoot: /var/tmp/id3v2
Requires: id3lib
URL: http://id3v2.sourceforge.net/
Prefix: /usr

%description
I wrote this because id3v1 are seriously deficient in what kind of 
info can be in them and the length of info that can be in them. 
id3v2 tags are much better but there isn't a tool to edit them in Linux. 
This is a tool to fill that space.
In case you didn't know id3 tags can be found on mp3 files, they can 
store infomation about what band recorded the song, the song name, 
etc. id3v2 adds all kinds of neat stuff and you can find out more about 
it at the id3v2 page

%prep
%setup
%patch -p 1

%build
make

%install
install -d $RPM_BUILD_ROOT%{prefix}/bin/
install -m 755 -s id3v2 $RPM_BUILD_ROOT%{prefix}/bin/

%post

%postun

%clean
rm -rf ${RPM_BUILD_ROOT}

%files
%defattr(-,root,root)
%{prefix}/bin
%doc README COPYING INSTALL

%changelog
* Mon Nov 12 2001 Pavel Polischouk <pavelp@geocities.com>
- Initial release of spec
- Patch created for id3lib 3.8.0pre2 support
