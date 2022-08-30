for ((i=1;;i++)) do
	echo $i
	./gen $i > in
	diff -w <(./A < in) <(./to_hack < in) || break
done
