# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
Running in numeric mode                                                                                                │
Output will be in hexidecimal format                                                                                   │
ERROR Invalid File: Bad address
EOF
pass;
