# rgxlist
Creates a list of all filenames that contain a string.

Usage - Technical: rgxlist [1] (2) > file

arg [1] : Regex string to search each filename within a directory for. Each filename that is found to contain it is added to a list. Each filename is terminated by a newline character '\n' which is essentially just the return key character.

arg [2] : Search directory. Defaults to the local directory and is optional to use.

">"     : Used to write the output, which will just be lines of filenames in the console otherwise, to a text file. You can use ">>" instead to append filenames instead of overwrite them.

file    : File that is written to.

Usage - General:

Useful in the same manner as extlist(https://github.com/KaptainBflakes/extlist) but made to deal with highly formatted filenames, not just file extensions.
Can feed all my list-fed commands.
