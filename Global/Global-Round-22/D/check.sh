for ((i=1;;i++)) do
	echo $i
	./gen $i > in
	./D < in > out || break
done
