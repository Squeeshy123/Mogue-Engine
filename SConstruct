env = Environment()

env.Append(CPPPATH=[".", 'C:\\Users\\finnm\\Desktop\\CSCWork\\Libraries\\SDL\\include'])
env.Append(LIBPATH=['C:\\Users\\finnm\\Desktop\\CSCWork\\Libraries\\SDL\\lib'])

Export('env')

subdirs = ['Core','Test']
objs = []

main = env.Object('main.cpp')
objs.append(main)

for subdir in subdirs:
	print(subdir + '\\SConscript')
	o = env.SConscript('%s\\SConscript' % subdir)
	objs.append(o)

for obj in objs:
	if obj == None:
		objs.remove(obj)

print(str(objs) + "\n")
if len(objs) > 0:
	env.Program("Mogue", objs)
else:
	print("No files found!")