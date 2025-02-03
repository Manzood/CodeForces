for ((i=1;;i++)) do
	echo $i
	./gen $i > in
	diff -w <(./D < in) <(./o3 < in) || break
done
