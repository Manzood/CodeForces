for ((i=1;;i++)) do
	echo $i
	./gen $i > in
	diff -w <(./D < in) <(./Dslow < in) || break
done
