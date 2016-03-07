# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
canonical mode
o0 [OUTPUT] = (~o1)
	>>Expanded: 
o1 [OUTPUT] =  (p0)||(i0)
	>>Expanded: 
i0 [INPUT] 
i1 [INPUT] 
i2 [INPUT] 
p0 [WIRE] =  (i1)&(~(i2))
	>>Expanded: 

EOF
pass;
