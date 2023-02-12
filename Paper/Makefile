all: draft.pdf some

draft.pdf: draft.tex bibliography.bib
	pdflatex draft.tex
	biber draft
	pdflatex draft.tex
	pdflatex draft.tex

some:
	@echo "------------------DONE------------------"

clean:
	rm draft.pdf
	rm draft.log
	rm draft.aux
	rm draft.bbl
	rm draft.blg
	rm draft.bcf
	rm draft.run.xml
