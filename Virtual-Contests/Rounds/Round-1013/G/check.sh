for ((i=1;;i++)) do
	echo $i
	./gen $i > in
	diff -w <(./G < in) <(./brute < in) || break
done
