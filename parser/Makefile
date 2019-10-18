NAMESPACE=Zlang

PARSER_CLASS=ZlangParser
PARSER_HEADER=$(PARSER_CLASS).yy.hpp
PARSER_SOURCE=$(PARSER_CLASS).yy.cpp
PARSER_LOCATIONS=location.yy.hpp

SCANNER_CLASS=ZlangScanner
SCANNER_HEADER=$(SCANNER_CLASS).yy.hpp
SCANNER_SOURCE=$(SCANNER_CLASS).yy.cpp

BISON=/usr/local/opt/bison/bin/bison
BISON_FLAGS= --debug --verbose

REFLEX=/usr/local/bin/reflex
REFLEX_FLAGS= --debug

.PHONY: all parser scanner clean marker

all: parser scanner
parser: $(PARSER_HEADER) $(PARSER_SOURCE)
scanner: $(SCANNER_HEADER) $(SCANNER_SOURCE)

$(PARSER_HEADER) $(PARSER_SOURCE): zlang.y
	$(BISON) $(BISON_FLAGS) --output=$(PARSER_SOURCE) --defines=$(PARSER_HEADER) --locations -Dapi.location.file='"$(PARSER_LOCATIONS)"' -Dapi.namespace={$(NAMESPACE)} -Dapi.parser.class={$(PARSER_CLASS)} $<

$(SCANNER_HEADER) $(SCANNER_SOURCE): zlang.l
	$(REFLEX) $(REFLEX_FLAGS) --bison-complete --bison-cc-namespace=$(NAMESPACE) --bison-cc-parser=$(PARSER_CLASS) --bison-locations --namespace=$(NAMESPACE) --lexer=$(SCANNER_CLASS) --outfile=$(SCANNER_SOURCE) --header-file=$(SCANNER_HEADER) $<

marker:
	touch marker.make

clean:
	rm -rf *.yy.*
