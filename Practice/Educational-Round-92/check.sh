for ((i=1;;i++)) do
	echo $i
	./gen $i > in
    python3 correct.py < in > expected
	diff -w <(./b < in) expected || break
done

