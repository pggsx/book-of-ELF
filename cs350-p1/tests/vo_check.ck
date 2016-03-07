# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
Running in verbose mode
Running in numeric mode
Output will be in octal format
Opening file "../small.data"
File contains 6 bytes of data
110 145 154 154 157 012 
EOF
pass;
