#!/bin/sh
ls -Al|awk 'BEGIN{printf"0 directory:\n2 file:\n4 total:\n5 \t";system("du -shc|sed -e 1d")}/^d/{printf"1 "}/^-/{printf"3 "}/^[d-]/{$9;c=sprintf("du -sh %s",$9);system(c)}'|sort -k1h -k2hr|awk '/^[024]/{printf"%s\n",$2}/^[135]/{printf"\t%s\t%s\n",$2,$3}'
