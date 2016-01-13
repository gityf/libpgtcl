#
# program to insert the sampledata.txt data set into pgtest_people
#  in one single transaction
#
# $Id: import_sampledata_onetransaction.tcl,v 1.2 2005/06/22 17:31:12 schwarzkopf Exp $
#

package require Pgtcl

if {[file exists conninfo.tcl]} {
    source conninfo.tcl
}

proc doit {} {
    set fp [open sampledata.txt]

    if {[info exists ::conninfo]} {
        set conn [pg_connect -connlist [array get ::conninfo]]
    } else {
        set conn [pg_connect -conninfo ""]
    }

    set statement "begin; "
    while {[gets $fp line] >= 0} {
	append statement "insert into pgtest_people values ([pg_quote [lindex $line 0]], [pg_quote [lindex $line 1]], [pg_quote [lindex $line 2]], [pg_quote [lindex $line 3]], [pg_quote [lindex $line 4]], [pg_quote [lindex $line 5]]); "
    }

    append statement "end;"

    set result [pg_exec $conn $statement]
    if {[pg_result $result -status] != "PGRES_COMMAND_OK"} {
	puts "[pg_result $result -error] executing '$statement'"
    }
    pg_result $result -clear
}

if !$tcl_interactive doit

