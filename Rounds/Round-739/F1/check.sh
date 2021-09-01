for ((i=1;;i++)) do
	echo $i
	./gen $i > in
	diff -w <(./F1 < in) <(./correct < in) || break
done
