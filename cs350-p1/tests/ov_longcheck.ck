# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
Running in verbose mode
Running in numeric mode
Output will be in octal format
Opening file "../long.data"
File contains 47 bytes of data
001 002 003 004 005 006 007 010 011 012 013 014 015 016 017 020 021 022 023 024 025 026 
027 030 031 032 033 034 035 036 037 040 041 042 043 044 045 046 047 050 051 052 053 054 
055 056 057 
EOF
pass;
