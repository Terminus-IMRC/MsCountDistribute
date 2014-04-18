#!/bin/sh
if test -z "$1"; then
	echo invalid argument >&2
	echo "usage: $0 [X]" >&2
	exit 1
fi

X=$1

RESULT=result.txt

echo "#!/usr/bin/env gnuplot"
echo "set terminal pngcairo mono size 1024,768 font \"Courier Bold\""
echo "set output \"result.png\""

rm -f result.png

cat <<END
set title "[MsCountDistribute]"
set xlabel "#elem"
set ylabel "count"
set xrange [1:$((X*X))]
set xtics 1
set yrange [0:]
set grid
END

echo "plot \\"
for f in $(seq 1 $((X*X))); do
	echo -n "\"result.txt\" using 1:$((f+1)) title \"$f\" with linespoints"
	if test $f -ne $((X*X)); then
		echo ", \\"
	else
		echo
	fi
done
