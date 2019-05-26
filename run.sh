#!/bin/sh -e

PS=$(find . -type f -name "*.c" | grep -v "template.c" | sed 's/.c//g' | tr -d './' | sort)

>a.txt
echo a.txt > .gitignore

for p in $PS
do
	make -s "$p"
	echo "$p" >> .gitignore
	t=$(awk -v p="$p" 'NR==p {print $1}' t.txt)
	got=$(./$p $t)
	want=$(awk -v p="$p" 'NR==p {print $2}' t.txt)
	if [ $got -eq $want ]
	then
		./$p $(sed "${p}q;d" ./q.txt) >> a.txt
	else
		echo "$p($t)\t$got\t$want"
		echo $got >> a.txt
	fi
done

echo OK
exit
