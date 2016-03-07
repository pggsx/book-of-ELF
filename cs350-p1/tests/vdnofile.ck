# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
Running in verbose mode
Running in numeric mode
ERROR User must select either octal or decimal format
Exiting Now..
EOF
pass;
