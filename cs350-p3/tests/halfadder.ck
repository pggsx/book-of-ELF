# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
canonical mode
o0 [OUTPUT] =  (a)^(b)	>>Expanded: 
o1 [OUTPUT] =  (a)^(b)	>>Expanded: 
a [INPUT] 
b [INPUT] 
EOF
pass;
