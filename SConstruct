env = Environment()

is_vs = ARGUMENTS.get('vs', 0)

build_dir = './build'

env.Append(CPPPATH=["C:\\Users\\finnm\\Desktop\\CSCWork\\MogueEngine\\Mogue\\","C:\\Users\\finnm\\Desktop\\CSCWork\\MogueEngine\\Mogue\\src", 'C:\\Users\\finnm\\Desktop\\CSCWork\\Libraries\\SDL\\include\\'])
env.Append(LIBPATH=['C:\\Users\\finnm\\Desktop\\CSCWork\\Libraries\\SDL\\lib\\'])
env.Append(LIBS=['SDL2', 'SDL2main', 'SDL2_image'])


Export('env')

subdirs = ['src\\Core','src\\Test', 'Libs']
objs = []

VariantDir(build_dir, 'src', duplicate=0)

for subdir in subdirs:
	print("\nReading from: " + '.\\%s\\SConscript' % subdir)
	o = env.SConscript('.\\%s\\SConscript' % subdir)
	env.Install(build_dir, o)
	objs.extend(o)

#for obj in objs:
#	if obj == None:
#		objs.remove(obj)

main = env.Object('src\\main.cpp')
objs.extend(main)

prog = NULL

print("\nFinal objects: " + str(objs) + "\n")
if len(objs) > 0:
	prog = env.Program("Mogue", objs)
else:
	print("No files found!")

def check_dirs_and_scan(directory, array):
	folder = os.walk(directory)
	
	return array
	

if is_vs:
	walk = os.walk('.')
	src = []
	for dirs, root, file in walk:
		for d in dirs:
			os.walk(d)
		for f in file:
			files.
	env.MSVSProject()