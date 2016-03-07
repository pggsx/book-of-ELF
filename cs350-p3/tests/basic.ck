# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
canonical mode
eq [OUTPUT] = 	>>Expanded: 
i0 [INPUT] 
p0 [WIRE] =  (i0)||(i0)

	>>Expanded: 

EOF
pass;
