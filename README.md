# ft_ls -- list directory contents

## SYNOPSIS
     ft_ls [-AFGRUSTacdfgloprtu1] [file ...]

## DESCRIPTION
     For each operand that names a file of a type other than directory, ls displays its name as well as any requested, associated information.  For each operand that names a file of type
     directory, ls displays the names of files contained within that directory, as well as any requested, associated information.

     If no operands are given, the contents of the current directory are displayed.  If more than one operand is given, non-directory operands are displayed first; directory and non-
     directory operands are sorted separately and in lexicographical order.

     The following options are available:
     
     -1      (The numeric digit ``one''.)  Force output to be one entry per line.  This is the default when output is not to a terminal.

     -A      List all entries except for . and ..  Always set for the super-user.

     -a      Include directory entries whose names begin with a dot (.).

     -d      Directories are listed as plain files (not searched recursively).

     -F      Display a slash (`/') immediately after each pathname that is a directory, an asterisk (`*') after each that is executable, an at sign (`@') after each symbolic link, an
             equals sign (`=') after each socket, a percent sign (`%') after each whiteout, and a vertical bar (`|') after each that is a FIFO.

     -f      Output is not sorted.  This option turns on the -a option.

     -G      Enable colorized output.  This option is equivalent to defining CLICOLOR in the environment.  (See below.)

     -g      This option is only available for compatibility with POSIX; it is used to display the group name in the long (-l) format output (the owner name is suppressed).

     -l      (The lowercase letter ``ell''.)  List in long format.  (See below.)  If the output is to a terminal, a total sum for all the file sizes is output on a line before the long
             listing.

     -o      List in long format, but omit the group id.

     -p      Write a slash (`/') after each filename if that file is a directory.

     -R      Recursively list subdirectories encountered.

     -r      Reverse the order of the sort to get reverse lexicographical order or the oldest entries first (or largest files last, if combined with sort by size

     -S      Sort files by size
     
     -s      Display the number of file system blocks actually used by each file, in units of 512 bytes, where partial units are rounded up to the next integer value.  If the output is to
             a terminal, a total sum for all the file sizes is output on a line before the listing.  The environment variable BLOCKSIZE overrides the unit size of 512 bytes.

     -T      When used with the -l (lowercase letter ``ell'') option, display complete time information for the file, including month, day, hour, minute, second, and year.

     -t      Sort by time modified (most recently modified first) before sorting the operands by lexicographical order.

     -u      Use time of last access, instead of last modification of the file for sorting (-t) or long printing (-l).

     -U      Use time of file creation, instead of last modification for sorting (-t) or long output (-l).

### The Long Format
     If the -l option is given, the following information is displayed for each file: file mode, number of links, owner name, group name, number of bytes in the file, abbreviated month,
     day-of-month file was last modified, hour file last modified, minute file last modified, and the pathname.  In addition, for each directory whose contents are displayed, the total
     number of 512-byte blocks used by the files in the directory is displayed on a line by itself, immediately before the information for the files in the directory.  If the file or
     directory has extended attributes, the permissions field printed by the -l option is followed by a '@' character.  Otherwise, if the file or directory has extended security informa-
     tion (such as an access control list), the permissions field printed by the -l option is followed by a '+' character.

     If the modification time of the file is more than 6 months in the past or future, then the year of the last modification is displayed in place of the hour and minute fields.

     If the owner or group names are not a known user or group name, or the -n option is given, the numeric ID's are displayed.

     If the file is a character special or block special file, the major and minor device numbers for the file are displayed in the size field.  If the file is a symbolic link, the path-
     name of the linked-to file is preceded by ``->''.

     The file mode printed under the -l option consists of the entry type, owner permissions, and group permissions.  The entry type character describes the type of file, as follows:

           b     Block special file.
           c     Character special file.
           d     Directory.
           l     Symbolic link.
           s     Socket link.
           p     FIFO.
           -     Regular file.

     The next three fields are three characters each: owner permissions, group permissions, and other permissions.  Each field has three character positions:

           1.   If r, the file is readable; if -, it is not readable.

           2.   If w, the file is writable; if -, it is not writable.

           3.   The first of the following that applies:

                      S     If in the owner permissions, the file is not executable and set-user-ID mode is set.  If in the group permissions, the file is not executable and set-group-ID
                            mode is set.

                      s     If in the owner permissions, the file is executable and set-user-ID mode is set.  If in the group permissions, the file is executable and setgroup-ID mode is
                            set.

                      x     The file is executable or the directory is searchable.

                      -     The file is neither readable, writable, executable, nor set-user-ID nor set-group-ID mode, nor sticky.  (See below.)

                These next two apply only to the third character in the last group (other permissions).

                      T     The sticky bit is set (mode 1000), but not execute or search permission.  (See chmod(1) or sticky(8).)

                      t     The sticky bit is set (mode 1000), and is searchable or executable.  (See chmod(1) or sticky(8).)

## EXAMPLES
     The following is how to do an ls listing sorted by increasing size

           ./ft_ls -lrS

## DIAGNOSTICS
     The ft_ls utility exits 0 on success, and >0 if an error occurs.
