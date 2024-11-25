for ((i=1;;i++)) do
	echo $i
	./gen $i > in
	diff -w <(./B2 < in) <(./B < in) || break
done
