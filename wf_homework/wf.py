import os
import sys
import re
import argparse

def found_file(file_path):
	file_name = open(file_path, "r", encoding="utf-8")
	file_txt = file_name.read()
	spce = re.compile(u'!@$#%&*,.，.?;:')
	file_txt = re.sub(spce,'',file_txt)
	file_txt = file_txt.lower()
	return file_txt.split()
def put_num(word_list,f = True):
	d = {}
	for list in word_list:
		d[list] = d.get(list,0)+1
	d_list = sorted(d.items(), key=lambda x: x[1], reverse=True)
	print("Total",len(d_list),"words")
	for i in range(min(len(d_list),10)):
		print("{0:<9}{1:>5}".format(d_list[i][0], d_list[i][1]))
		if (f == False):
			print("----")
	return None
def d_file(file_path):
	if (os.path.isdir(file_path) == True):
		return os.listdir(file_path)
	elif os.path.isfile(file_path) == True:
		return [file_path]
	return None
def word_list(file_path):
	d_file_list = d_file(file_path)
	if os.path.isfile(file_path):
		for file in d_file_list:
			f1 = found_file(file)
			put_num(f1)
	for file in d_file_list:
		print(file.split('.')[0])
		put_num(found_file(file_path + '\\' + file), False)
	return None
def function_four(file_txt):
	spce = re.compile(u'!@$#%&*,.，.?;:')
	file_txt = re.sub(spce, '', file_txt)
	file_txt = file_txt.lower()
	file_txt =file_txt.split()
	put_num(file_txt)
	return  None
if __name__ == '__main__':
	parser = argparse.ArgumentParser()
	parser.add_argument("file_path", nargs='?')
	parser.add_argument('-s', nargs='?')
	a= parser.parse_args()
	if ((a.s == None) and (a.file_path == None)):
		r = sys.stdin.read()  # redirect
		function_four(r)
		pass
	elif ((a.s == None) and (a.file_path != None)):
		word_list(a.file_path)
		pass
	elif ((a.s != None) and (a.file_path == None)):
		word_list(a.s)
		pass
	pass









