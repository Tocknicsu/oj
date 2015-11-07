#!/bin/sh
ls -l|awk 'BEGIN{printf"0 directory:\n2 files:\n4 total:\n5 \t";system("du -shc|sed -e 1d");}/^d/{printf"1 \t"}/^-/{printf"3 \t"}/^[d-]/{$9;cmd=sprintf("du -sh ./%s",$9);system(cmd)}'|sort -k1h -k2hr |sed -e "s/^[0-9] //"
