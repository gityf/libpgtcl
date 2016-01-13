#
# playpen entry to mess with data types
#
# $Id: demo.tcl,v 1.1 2004/11/22 21:36:08 karl Exp $
#

package require Pgtcl

source install-types.tcl

proc doit {} {
    set conn [pg_connect www]
    fetch_types $conn

    puts "here are the fields and data types in pg_tables (or whatever)..."
    puts [table_types $conn pg_tables]
}

if !$tcl_interactive doit
