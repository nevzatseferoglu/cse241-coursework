JFLAGS = -g
JC = javac
.SUFFIXES: .java .class

	
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	Driver.java

default: classes

run: classes
	java Driver

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class