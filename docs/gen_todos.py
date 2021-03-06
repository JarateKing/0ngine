from os import walk
import os.path

readme = open('./Todo.md', 'w+')
readme.write('# TODOs\n\n')

for (dirpath, dirnames, filenames) in walk('..\\src\\'):
	for (filename) in filenames:
		file = open(dirpath + '\\' + filename)
		line = file.readline()
		lineNumber = 1
		
		todosInFile = ''
		
		while (line != ''):
			search = line.find('@TODO')
			if (search != -1):
				linePrefix = line[:search]
				todosInFile += '\n[Line ' + str(lineNumber) + ']('
				todosInFile += 'https://github.com/JarateKing/0ngine/blob/master/src/' + dirpath[7:].replace('\\','/') + '/' + filename + '#L' + str(lineNumber) + ')\n'
				todosInFile += '```\n'
				while (line != '' and line.startswith(linePrefix)):
					todosInFile += line[search:]
					line = file.readline()
					lineNumber += 1
				todosInFile += '```\n'
			else:
				line = file.readline()
				lineNumber += 1
		
		if (len(todosInFile) > 0):
			readme.write('## ' + dirpath[7:] + '\\' + filename + '\n' + todosInFile + '\n\n')
		file.close()
readme.close()