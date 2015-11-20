#!/bin/sh
ls -al|awk 'BEGIN{printf"0directory:\n2files:\n4total:\n5\t";system("du -shc|sed -e 1d")}NR<=3{next}/^d/{printf"1\t"}/^-/{printf"3\t"}/^[d-]/{$9;c=sprintf("du -sh %s",$9);system(c)}'|sort -k1h -k2hr|sed -e"s/^.//"
