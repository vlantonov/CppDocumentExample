# CppDocumentExample
C++ code documentation example

## Setup Doxygen
* Startup command
```bash
doxygen -g ./doc/Doxyfile
```
## Useful Doygen settings

### General
* Title of the project: `PROJECT_NAME = "..."`
* Optional one line description of the project: `PROJECT_BRIEF = "..."`
* Disable LaTeX output: `GENERATE_LATEX = NO`
* Directory to put the HTML docs `OUTPUT_DIRECTORY = ./html/`
* Make a main page out of a markdown: `USE_MDFILE_AS_MAINPAGE = "..."`
* Project logo file: `PROJECT_LOGO = "..."`
* Match functions declarations and definitions whose arguments contain STL classes: `BUILTIN_STL_SUPPORT = YES`
* Exclude documentation from external libraries: `EXCLUDE = "..."`

### Scope related
* Show public members of class: `EXTRACT_ALL = YES`
* Show private members of class: `EXTRACT_PRIVATE = YES`
* Show private virtual members of class: `EXTRACT_PRIV_VIRTUAL = YES`
* Show static members of class: `EXTRACT_STATIC = YES`
* Show all memebers of internal scope: `EXTRACT_PACKAGE = YES`
* Show members of anonymous namespace: `EXTRACT_ANON_NSPACES = YES`

### Entrance points
* Add all the header and source file extensions used: `FILE_PATTERNS = *.cpp *.h *.hpp`
* Files and/or directories that contain documented source files: `INPUT = ./src ./include`
* Search subdirectories for input files: `RECURSIVE = YES`
* Generate list from all `/** @todo */ `: `GENERATE_TODOLIST = YES`
* Generate list from all `/** @test */` : `GENERATE_TESTLIST = YES`

### Diagram generators
* Dot tool ( [Graphviz](https://graphviz.org/) ) available: `HAVE_DOT = YES`
* Use UML notation for class diagrams: `UML_LOOK = YES`
* Show all members in UML class: `UML_LIMIT_NUM_FIELDS = 0`
* Generate a call dependency graph for every global function or class method: `CALL_GRAPH = YES`
* Generate a caller dependency graph for every global function or class method: `CALLER_GRAPH = YES`
* Show relationship for templates in graphs: `TEMPLATE_RELATIONS = YES`
* Hide inheritance and usage relations if the target is undocumented or is not a class: `HIDE_UNDOC_RELATIONS = NO`
* Number of threads to use for DOT: `DOT_NUM_THREADS = 4`

### Source browsing
* Show all functions that reference current function: `REFERENCED_BY_RELATION = YES`
* Show all functions referenced by current function: `REFERENCES_RELATION = YES`
* Include functions body to the generated HTML's: `INLINE_SOURCES = YES`
* Specify files/folders with example code: `EXAMPLE_PATH = "..."`

## Doxygen C++ examples
* [How to configure Doxygen for C++ code](https://codeyarns.com/tech/2014-06-18-how-to-configure-doxygen-for-c-code.html#gsc.tab=0)
* [Creating a visualization of a C++ project with doxygen](http://web.evolbio.mpg.de/~boettcher//other/2016/creating_source_graph.html)
* [Learn how to use doxygen](http://www.whatimade.today/learn-how-to-use-doxygen/)
* [CPP / C++ Notes - Doxygen - Documentation Generator](https://caiorss.github.io/C-Cpp-Notes/Doxygen-documentation.html)

## Command Pattern References
* [refactoring.guru:Command](https://refactoring.guru/design-patterns/command/)
* [Command Design Pattern](https://sourcemaking.com/design_patterns/command)

## Technical References
* [The Copy-and-Swap Idiom](https://www.modernescpp.com/index.php/the-copy-and-swap-idiom/)
* [What std::exchange does, and how to remember it](https://www.fluentcpp.com/2020/09/18/what-stdexchange-does-and-how-to-remember-it/)
* [std::exchange Patterns: Fast, Safe, Expressive, and Probably Underused](https://www.fluentcpp.com/2020/09/25/stdexchange-patterns-fast-safe-expressive-and-probably-underused/)

## Example Document pages
* <https://github.com/nullromo/doxygen-example>
* <https://gitlab.com/pages/doxygen>
