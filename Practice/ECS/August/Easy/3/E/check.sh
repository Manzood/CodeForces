for ((i=1;;i++)) do
	echo $i
	./gen $i > in
	(./E < in) || break
done
