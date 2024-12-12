# Regla para generar el ejecutable bin/testTableEntry
bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -std=c++11 -o bin/testTableEntry testTableEntry.cpp

# Regla para generar el ejecutable bin/testHashTable
bin/testHashTable: testHashTable.cpp TableEntry.h Dict.h HashTable.h
	mkdir -p bin
	g++ -std=c++11 -o bin/testHashTable testHashTable.cpp

# Regla para generar el ejecutable bin/testBSTree
bin/testBSTree: testBSTree.cpp BSTree.h BSNode.h
	mkdir -p bin
	g++ -std=c++11 -o bin/testBSTree testBSTree.cpp

# Regla para generar el ejecutable bin/testBSTreeDict
bin/testBSTreeDict: testBSTreeDict.cpp Dict.h BSTreeDict.h BSNode.h TableEntry.h
	mkdir -p bin
	g++ -std=c++11 -o bin/testBSTreeDict testBSTreeDict.cpp

# Regla para limpiar los archivos generados
clean:
	rm -rf *.o *.gch bin






