from os import walk
import os.path

readme = open('./Todo.md', 'w+')
readme.write('# TODOs\n\n')

for (dirpath, dirnames, filenames) in walk('..\\src\\'):
	for filename in filenames:
		print(dirpath + '\\' + filename)
		file = open(dirpath + '\\' + filename)
		line = file.readline()
		lineNumber = 1
		
		todosInFile = ''
		
		while line != '':
			search = line.find('@TODO')
			if (search != -1):
				todosInFile = todosInFile + '\nLine ' + str(lineNumber)
			line = file.readline()
			lineNumber = lineNumber + 1
		
		if (len(todosInFile) > 0):
			readme.write('## ' + dirpath[7:] + '\\' + filename + '\n' + todosInFile + '\n\n')
		file.close()
readme.close()