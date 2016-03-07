# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
Running in verbose mode
Running in numeric mode
Output will be in decimal format
Opening file "../small.data"
File contains 6 bytes of data
072 101 108 108 111 010 
EOF
pass;
