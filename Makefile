F = MedianOfTwoSortedArray
all:
	javac $(F).java; java $(F)
run:
	java $(F)
clean:
	rm -rf *.class
up:
	scp *.java csehao@ix.cs.uoregon.edu:~/public_html/uploads/java/
