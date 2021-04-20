env = Environment()

Export('env')

subdirs = ['Core']
objs = []

for subdir in subdirs:
	o = SConscript(subdir + '/SConscript')
	objs.append(o)

env.Program('mogue', objs)