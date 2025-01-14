for ((i=1;;i++)) do
	echo $i
	./gen $i > in
    ./C < in > out1
    ./C_backup2 < in > out2
    ./compare < out1 > out3
    ./compare < out2 > out4
	diff -w out3 out4 || break
done
