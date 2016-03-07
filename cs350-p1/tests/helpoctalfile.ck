# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
Usage: hexdumper [-v] filename                                                                                         
hexdumper [-v] -d filename                                                                                             
hexdumper [-v] -o filename                                                                                             
hexdumper [-v] -m [-b bldg | -a area | -q bldg:bldg] filename                                                         
-v            Run the program in verbose mode, printing extra output                                                   
-d            Print the input data as decimal format                                                                   
-o            Print the input data as octal format                                                                     
-m            Switch to map mode and execute a query of the campus                                                     
-b bldg       Query the map about a particular building                                                                
-a area       Query the map about a particular area of campus                                                          
-q bldg:bldg  Query the map about the distance between two buildings                                                   
-h            Print this help message and quit   
EOF
pass;
