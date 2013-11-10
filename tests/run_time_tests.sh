#!/bin/sh

BINFILE=../codigo/bin/time
TESTINDIR=./testfiles

echo "\nIniciando tests de tiempos\n"
	echo "\tBiseccion f\n"
	$BINFILE < $TESTINDIR/timetest_bis_f.in
	
	echo "\tBiseccion e\n"
	$BINFILE < $TESTINDIR/timetest_bis_e.in
	
	echo "\tNewton f\n"
	$BINFILE < $TESTINDIR/timetest_newt_f.in
	
	echo "\tNewton e\n"
	$BINFILE < $TESTINDIR/timetest_newt_e.in
	
	echo "\tSecante f\n"
	$BINFILE < $TESTINDIR/timetest_sec_f.in
	
	echo "\tSecante e\n"
	$BINFILE < $TESTINDIR/timetest_sec_e.in
	
echo "\n Tests de tiempo terminados con exito\n"
