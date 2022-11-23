for linee in $(cat assignments.txt)
do 
echo $linee
fgrep texcl $linee
done
